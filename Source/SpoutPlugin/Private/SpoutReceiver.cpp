/**
 * Implements the Spout receiver flow by opening shared DX11 textures, reading back into
 * CPU memory, and updating UE transient textures via the render thread.
 */
#include "SpoutReceiver.h"
#include "SpoutD3DContext.h"
#include "SpoutSenderRegistry.h"
#include "SpoutTextureUtils.h"
#include "SpoutModule.h"

#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "RHI.h"
#include "RenderingThread.h"

using Microsoft::WRL::ComPtr;

namespace
{
	bool QuerySenderInfo(const FName& SpoutName, unsigned int& OutWidth, unsigned int& OutHeight, HANDLE& OutHandle, unsigned long& OutFormat)
	{
		FSpoutD3DContext& Context = FSpoutD3DContext::Get();
		spoutSenderNames* SenderNames = Context.GetSenderNames();
		if (!SenderNames)
		{
			return false;
		}

		// Spout sender list is shared process-wide; guard with the mutex.
		FScopeLock SpoutLock(&Context.GetSpoutMutex());
		return SenderNames->GetSenderInfo(TCHAR_TO_UTF8(*SpoutName.ToString()), OutWidth, OutHeight, OutHandle, OutFormat);
	}

	bool UpdateSharedReceiverTexture(FSpoutSharedSender& Receiver, unsigned int Width, unsigned int Height, HANDLE SharedHandle, FSpoutD3DContext& Context)
	{
		// Reuse the shared texture while the handle and dimensions are unchanged.
		if (Receiver.Width == Width && Receiver.Height == Height && Receiver.SharedHandle == SharedHandle && Receiver.SharedTexture)
		{
			return true;
		}

		// Open the shared DX11 texture from the external sender's handle.
		ComPtr<ID3D11Texture2D> NewSharedTexture;
		HRESULT hr = Context.GetD3D11Device()->OpenSharedResource(
			SharedHandle,
			IID_PPV_ARGS(NewSharedTexture.GetAddressOf())
		);

		if (FAILED(hr) || !NewSharedTexture)
		{
			UE_LOG(LogSpoutPlugin, Error,
				TEXT("Failed to open shared Spout texture for sender '%s' (hr=0x%08x)"),
				*Receiver.Name.ToString(),
				hr);
			return false;
		}

		FScopeLock ReceiverLock(&Receiver.ResourceMutex);
		Receiver.Width = Width;
		Receiver.Height = Height;
		Receiver.SharedHandle = SharedHandle;
		// SharedTexture is owned by this receiver; the sender owns the underlying resource.
		Receiver.SharedTexture = MoveTemp(NewSharedTexture);
		Receiver.StagingTexture.Reset();

		return true;
	}

	bool GetSharedAndStaging(FSpoutSharedSender& Receiver, FSpoutD3DContext& Context, ComPtr<ID3D11Texture2D>& OutShared, ComPtr<ID3D11Texture2D>& OutStaging, uint32& OutWidth, uint32& OutHeight)
	{
		FScopeLock ReceiverLock(&Receiver.ResourceMutex);
		if (!Receiver.SharedTexture)
		{
			return false;
		}

		OutWidth = Receiver.Width;
		OutHeight = Receiver.Height;
		OutShared = Receiver.SharedTexture;

		// Staging texture is CPU-readable for readback into a UE UTexture2D.
		bool bNeedsResize = false;
		if (!Receiver.StagingTexture)
		{
			bNeedsResize = true;
		}
		else
		{
			D3D11_TEXTURE2D_DESC Desc;
			Receiver.StagingTexture->GetDesc(&Desc);
			if (Desc.Width != Receiver.Width || Desc.Height != Receiver.Height)
			{
				bNeedsResize = true;
			}
		}

		if (bNeedsResize)
		{
			D3D11_TEXTURE2D_DESC Desc;
			Receiver.SharedTexture->GetDesc(&Desc);

			Desc.Usage = D3D11_USAGE_STAGING;
			Desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
			Desc.BindFlags = 0;

			// Staging texture is owned by the receiver and recreated on size changes.
			ComPtr<ID3D11Texture2D> NewStaging;
			HRESULT hr = Context.GetD3D11Device()->CreateTexture2D(&Desc, nullptr, NewStaging.GetAddressOf());
			if (FAILED(hr))
			{
				UE_LOG(LogSpoutPlugin, Error, TEXT("Failed to create staging texture (hr=0x%08x)"), hr);
				return false;
			}

			Receiver.StagingTexture = MoveTemp(NewStaging);
		}

		OutStaging = Receiver.StagingTexture;
		return OutStaging != nullptr;
	}
}

bool FSpoutReceiver::Receive(const FName SpoutName, UMaterialInstanceDynamic*& OutMat, UTexture2D*& OutTexture, UTextureRenderTarget2D* OptionalOutputRenderTarget)
{
	// OptionalOutputRenderTarget is currently unused; kept for future GPU paths.
	static_cast<void>(OptionalOutputRenderTarget);

	FSpoutD3DContext& Context = FSpoutD3DContext::Get();
	Context.InitializeIfNeeded();

	if (!Context.GetSenderNames() || !Context.GetD3D11Device())
	{
		return false;
	}

	unsigned int W = 0;
	unsigned int H = 0;
	HANDLE SharedHandle = nullptr;
	unsigned long Format = 0;
	if (!QuerySenderInfo(SpoutName, W, H, SharedHandle, Format))
	{
		return false;
	}
	static_cast<void>(Format);

	TSharedPtr<FSpoutSharedSender> Receiver = FSpoutSenderRegistry::Get().FindOrAdd(SpoutName, ESpoutType::Receiver);
	if (!Receiver)
	{
		return false;
	}

	if (!UpdateSharedReceiverTexture(*Receiver, W, H, SharedHandle, Context))
	{
		return false;
	}

	// Create/resize the transient texture that UE will sample in materials.
	SpoutTextureUtils::EnsureTransientTexture(OutTexture, static_cast<int32>(W), static_cast<int32>(H), PF_B8G8R8A8);

	if (!OutMat)
	{
		// NOTE: Hard-coded material path assumes project content is staged accordingly.
		UMaterialInterface* BaseMat = LoadObject<UMaterialInterface>(nullptr, TEXT("/SpoutPlugin/Content/Materials/SpoutMaterial.SpoutMaterial"));
		if (!BaseMat)
		{
			BaseMat = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Content/Materials/SpoutMaterial.SpoutMaterial"));
		}
		if (!BaseMat)
		{
			BaseMat = LoadObject<UMaterialInterface>(nullptr, TEXT("/DGS/SpoutMaterial.SpoutMaterial"));
		}
		if (BaseMat)
		{
			OutMat = UMaterialInstanceDynamic::Create(BaseMat, nullptr);
		}
	}

	if (OutMat)
	{
		OutMat->SetTextureParameterValue(FName("SpoutTexture"), OutTexture);
	}

	TRefCountPtr<FRHITexture> CapturedTextureRHI;
	if (OutTexture && OutTexture->GetResource())
	{
		CapturedTextureRHI = OutTexture->GetResource()->GetTexture2DRHI();
	}

	TRefCountPtr<FRHITexture> CapturedRenderTargetRHI;
	if (OptionalOutputRenderTarget)
	{
		if (OptionalOutputRenderTarget->SizeX != static_cast<int32>(W) || OptionalOutputRenderTarget->SizeY != static_cast<int32>(H))
		{
			OptionalOutputRenderTarget->ResizeTarget(static_cast<int32>(W), static_cast<int32>(H));
		}

		if (FTextureRenderTargetResource* RenderTargetResource = OptionalOutputRenderTarget->GameThread_GetRenderTargetResource())
		{
			CapturedRenderTargetRHI = RenderTargetResource->GetRenderTargetTexture();
		}
	}

	// Readback + texture update must run on the render thread.
	ENQUEUE_RENDER_COMMAND(SpoutRecvCmd)(
		[Receiver, CapturedTextureRHI, CapturedRenderTargetRHI](FRHICommandListImmediate& RHICmdList)
		{
			if (!CapturedTextureRHI.IsValid() && !CapturedRenderTargetRHI.IsValid())
			{
				return;
			}

			FSpoutD3DContext& Context = FSpoutD3DContext::Get();
			ComPtr<ID3D11Texture2D> SharedTexture;
			ComPtr<ID3D11Texture2D> StagingTexture;
			uint32 LocalWidth = 0;
			uint32 LocalHeight = 0;

			if (!GetSharedAndStaging(*Receiver, Context, SharedTexture, StagingTexture, LocalWidth, LocalHeight))
			{
				return;
			}

			// D3D11 immediate context use is serialized across sender/receiver paths.
			FScopeLock Lock(&Context.GetD3D11ContextMutex());
			ID3D11DeviceContext* ImmediateContext = Context.GetImmediateContext();
			if (!ImmediateContext || !SharedTexture || !StagingTexture)
			{
				return;
			}

			// Copy into a CPU-readable staging texture.
			ImmediateContext->CopyResource(StagingTexture.Get(), SharedTexture.Get());

			D3D11_MAPPED_SUBRESOURCE Mapped;
			if (SUCCEEDED(ImmediateContext->Map(StagingTexture.Get(), 0, D3D11_MAP_READ, 0, &Mapped)))
			{
				// NOTE: This is a CPU readback + upload each frame; can be expensive for large textures.
				const uint32 DataSize = LocalHeight * Mapped.RowPitch;
				TArray<uint8> Data;
				Data.SetNumUninitialized(DataSize);
				FMemory::Memcpy(Data.GetData(), Mapped.pData, DataSize);
				ImmediateContext->Unmap(StagingTexture.Get(), 0);

				// Update the UE texture with the readback data.
				FUpdateTextureRegion2D UpdateRegion(0, 0, 0, 0, LocalWidth, LocalHeight);
				if (CapturedTextureRHI.IsValid())
				{
					RHIUpdateTexture2D(
						CapturedTextureRHI,
						0,
						UpdateRegion,
						Mapped.RowPitch,
						Data.GetData()
					);
				}

				if (CapturedRenderTargetRHI.IsValid())
				{
					RHIUpdateTexture2D(
						CapturedRenderTargetRHI,
						0,
						UpdateRegion,
						Mapped.RowPitch,
						Data.GetData()
					);
				}
			}
		});

	return true;
}
