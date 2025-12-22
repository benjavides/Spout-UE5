/**
 * Implements the Spout sender flow by copying UE D3D12 textures into shared DX11 textures
 * via D3D11-on-12, coordinating with the sender registry and D3D context.
 */
#include "SpoutSender.h"
#include "SpoutD3DContext.h"
#include "SpoutD3DUtils.h"
#include "SpoutSenderRegistry.h"
#include "SpoutModule.h"

#include "Engine/Engine.h"
#include "RHI.h"
#include "RHIResources.h"
#include "RenderResource.h"
#include "RenderingThread.h"

using Microsoft::WRL::ComPtr;

namespace
{
	struct FSpoutSendSource
	{
		// RHI texture to read from (viewport backbuffer or render target).
		FTextureRHIRef SourceRHI;
		// Render target resource when sending from a UTextureRenderTarget2D.
		FTextureRenderTargetResource* RenderTargetResource = nullptr;
		// Used to restore access state after copy.
		bool bIsViewport = false;
		// True if SourceRHI should be fetched from RenderTargetResource.
		bool bUseRenderTarget = false;
	};

	bool BuildSendSource(ESpoutSendTextureFrom SendTextureFrom, UTextureRenderTarget2D* TextureRenderTarget2D, FSpoutSendSource& OutSource)
	{
		if (SendTextureFrom == ESpoutSendTextureFrom::TextureRenderTarget2D)
		{
			if (!TextureRenderTarget2D)
			{
				return false;
			}

			OutSource.RenderTargetResource = TextureRenderTarget2D->GameThread_GetRenderTargetResource();
			if (!OutSource.RenderTargetResource)
			{
				return false;
			}

			OutSource.bUseRenderTarget = true;
			return true;
		}

		if (SendTextureFrom == ESpoutSendTextureFrom::GameViewport)
		{
			// Only valid when a game viewport exists (e.g., not in commandlets).
			if (GEngine && GEngine->GameViewport && GEngine->GameViewport->Viewport)
			{
				OutSource.SourceRHI = GEngine->GameViewport->Viewport->GetRenderTargetTexture();
			}

			OutSource.bIsViewport = true;
			OutSource.bUseRenderTarget = false;
			return OutSource.SourceRHI.IsValid();
		}

		return false;
	}

	void EnsureSharedSenderTexture(FSpoutSharedSender& Sender, uint32 Width, uint32 Height, DXGI_FORMAT Format, FSpoutD3DContext& Context)
	{
		// Sender state can be accessed on the render thread and by BP calls.
		FScopeLock SenderLock(&Sender.ResourceMutex);
		if (Sender.SharedTexture && Sender.Width == Width && Sender.Height == Height)
		{
			return;
		}

		Sender.SharedTexture.Reset();
		Sender.SharedHandle = nullptr;
		Sender.CachedWrappedResource.Reset();
		Sender.CachedNativeResource = nullptr;
		Sender.Width = Width;
		Sender.Height = Height;

		spoutDirectX* SpoutDX = Context.GetSpoutDirectX();
		if (!SpoutDX)
		{
			return;
		}

		// Spout creates a DX11 shared texture and returns a shared handle.
		const bool bCreated = SpoutDX->CreateSharedDX11Texture(
			Context.GetD3D11Device(),
			Width,
			Height,
			Format,
			Sender.SharedTexture.GetAddressOf(),
			Sender.SharedHandle
		);

		if (bCreated && Sender.SharedTexture && Sender.SharedHandle)
		{
			spoutSenderNames* SenderNames = Context.GetSenderNames();
			if (SenderNames)
			{
				// Register or update this sender in Spout's global registry.
				FScopeLock SpoutLock(&Context.GetSpoutMutex());
				if (!Sender.bRegistered)
				{
					Sender.bRegistered = SenderNames->CreateSender(
						TCHAR_TO_UTF8(*Sender.Name.ToString()),
						Sender.Width,
						Sender.Height,
						Sender.SharedHandle,
						Format
					);
				}
				else
				{
					SenderNames->UpdateSender(
						TCHAR_TO_UTF8(*Sender.Name.ToString()),
						Sender.Width,
						Sender.Height,
						Sender.SharedHandle,
						Format
					);
				}
			}
		}
	}

	ComPtr<ID3D11Texture2D> GetWrappedResource(FSpoutSharedSender& Sender, ID3D12Resource* NativeResource)
	{
		// Cache the wrapped resource per native D3D12 texture to avoid re-wrapping every frame.
		FScopeLock SenderLock(&Sender.ResourceMutex);
		if (Sender.CachedNativeResource != NativeResource || !Sender.CachedWrappedResource)
		{
			Sender.CachedWrappedResource = WrapD3D12Resource(NativeResource, D3D12_RESOURCE_STATE_COPY_SOURCE);
			Sender.CachedNativeResource = NativeResource;
		}

		return Sender.CachedWrappedResource;
	}
}

bool FSpoutSender::Send(FName SpoutName, ESpoutSendTextureFrom SendTextureFrom, UTextureRenderTarget2D* TextureRenderTarget2D)
{
	FSpoutD3DContext& Context = FSpoutD3DContext::Get();
	Context.InitializeIfNeeded();

	if (!Context.IsSpoutAvailable())
	{
		return false;
	}

	FSpoutSendSource SendSource;
	if (!BuildSendSource(SendTextureFrom, TextureRenderTarget2D, SendSource))
	{
		return false;
	}

	// The copy must run on the render thread to safely touch RHI resources.
	ENQUEUE_RENDER_COMMAND(SpoutSenderCmd)(
		[SpoutName, SendSource](FRHICommandListImmediate& RHICmdList)
		{
			FSpoutD3DContext& Context = FSpoutD3DContext::Get();

			// D3D11 immediate context is not thread-safe; guard its usage.
			FScopeLock D3DLock(&Context.GetD3D11ContextMutex());
			if (!Context.GetImmediateContext() || !Context.GetD3D11On12Device())
			{
				return;
			}

			FTextureRHIRef LocalSourceRHI = SendSource.SourceRHI;
			if (SendSource.bUseRenderTarget)
			{
				if (!SendSource.RenderTargetResource)
				{
					return;
				}
				LocalSourceRHI = SendSource.RenderTargetResource->GetRenderTargetTexture();
			}

			if (!LocalSourceRHI.IsValid())
			{
				return;
			}

			// UE D3D12 textures expose their native resource for interop.
			ID3D12Resource* NativeRes = static_cast<ID3D12Resource*>(LocalSourceRHI->GetNativeResource());
			if (!NativeRes)
			{
				return;
			}

			// Transition for copy and flush so the wrapped D3D11 context can see up-to-date data.
			RHICmdList.Transition(FRHITransitionInfo(LocalSourceRHI, ERHIAccess::Unknown, ERHIAccess::CopySrc));
			RHICmdList.ImmediateFlush(EImmediateFlushType::FlushRHIThreadFlushResources);

			D3D12_RESOURCE_DESC Desc = NativeRes->GetDesc();

			// Spout DX11 path expects BGRA8 shared textures.
			const DXGI_FORMAT Format = DXGI_FORMAT_B8G8R8A8_UNORM;
			TSharedPtr<FSpoutSharedSender> Sender = FSpoutSenderRegistry::Get().FindOrAdd(SpoutName, ESpoutType::Sender);
			if (!Sender)
			{
				return;
			}

			EnsureSharedSenderTexture(*Sender, static_cast<uint32>(Desc.Width), static_cast<uint32>(Desc.Height), Format, Context);

			ComPtr<ID3D11Texture2D> SharedTexture;
			{
				FScopeLock SenderLock(&Sender->ResourceMutex);
				SharedTexture = Sender->SharedTexture;
			}

			ComPtr<ID3D11Texture2D> WrappedResource = SharedTexture ? GetWrappedResource(*Sender, NativeRes) : nullptr;
			if (SharedTexture && WrappedResource)
			{
				// Acquire transitions the wrapped resource for D3D11 access.
				FScopedD3D11On12Acquire Acquire(WrappedResource.Get());
				if (Acquire.IsValid())
				{
					// Copy UE's D3D12 texture into the shared DX11 texture.
					Context.GetImmediateContext()->CopyResource(SharedTexture.Get(), WrappedResource.Get());
					Context.GetImmediateContext()->Flush();
				}
			}

			// Restore the source access state after the copy.
			RHICmdList.Transition(FRHITransitionInfo(
				LocalSourceRHI,
				ERHIAccess::CopySrc,
				SendSource.bIsViewport ? ERHIAccess::Present : ERHIAccess::SRVGraphics
			));
		});

	return true;
}

void FSpoutSender::Close(FName SpoutName)
{
	if (FSpoutSenderRegistry::Get().Find(SpoutName))
	{
		FSpoutSenderRegistry::Get().Remove(SpoutName);
		UE_LOG(LogSpoutPlugin, Log, TEXT("Closed Spout Sender: %s"), *SpoutName.ToString());
	}
}
