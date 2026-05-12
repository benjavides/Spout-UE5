#include "SpoutMediaCapture.h"
#include "SpoutMediaOutput.h"
#include "SpoutSender.h"
#include "IDisplayCluster.h"
#include "IDisplayClusterCallbacks.h"
#include "Cluster/IDisplayClusterClusterManager.h"
#include "Render/Viewport/IDisplayClusterViewportProxy.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"

void USpoutMediaCapture::SetMediaOutput(USpoutMediaOutput* InMediaOutput)
{
	CachedOutput = InMediaOutput;
}

bool USpoutMediaCapture::ValidateMediaOutput() const
{
	return CachedOutput.IsValid();
}

bool USpoutMediaCapture::InitializeCapture()
{
	if (!CachedOutput.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("SpoutMediaCapture: InitializeCapture failed - no media output"));
		return false;
	}
	const bool bSpoutReady = FSpoutSender::Initialize();
	ResolvedViewportId = CachedOutput->ViewportId;
	if (IDisplayCluster::Get().GetClusterMgr())
	{
		const FString NodeId = IDisplayCluster::Get().GetClusterMgr()->GetNodeId();
		if (!NodeId.IsEmpty())
		{
			ResolvedNodeId = NodeId;
		}
	}
	ResolvedSenderName = ResolveSenderName(ResolvedViewportId);
	RegisterDisplayClusterDirectHook();
	UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: InitializeCapture - SpoutReady=%d SenderName=%s NodeId=%s ViewportId=%s DesiredSize=%dx%d DesiredPixelFormat=%d"),
		bSpoutReady, *ResolvedSenderName.ToString(), *ResolvedNodeId, *ResolvedViewportId, GetDesiredSize().X, GetDesiredSize().Y, static_cast<int32>(GetDesiredPixelFormat()));
	return true;
}

void USpoutMediaCapture::StopCaptureImpl(bool bAllowPendingFrameToBeProcess)
{
	UnregisterDisplayClusterDirectHook();
	UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: StopCapture for sender '%s'"), *ResolvedSenderName.ToString());
	FSpoutSender::Close(ResolvedSenderName);
}

void USpoutMediaCapture::OnRHIResourceCaptured_RenderingThread(
	FRHICommandListImmediate& RHICmdList,
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FTextureRHIRef InTexture)
{
	// Log once to confirm the render-thread callback is active.
	static bool bLogged = false;
	if (!bLogged)
	{
		bLogged = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: OnRHIResourceCaptured_RenderingThread fired - Texture=%s Valid=%d"),
			InTexture.IsValid() ? *InTexture->GetName().ToString() : TEXT("null"),
			InTexture.IsValid());
	}

	if (!InTexture.IsValid())
	{
		return;
	}
	FSpoutSender::SendRHIOnRenderThread(ResolvedSenderName, InTexture, RHICmdList, false);
}

void USpoutMediaCapture::OnRHIResourceCaptured_RenderingThread(
	FRHICommandListImmediate& RHICmdList,
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FBufferRHIRef InBuffer)
{
	static bool bLoggedRTBuffer = false;
	if (!bLoggedRTBuffer)
	{
		bLoggedRTBuffer = true;
		UE_LOG(LogTemp, Warning, TEXT("SpoutMediaCapture: OnRHIResourceCaptured_RenderingThread(Buffer) fired - buffer capture path is not supported for Spout sender"));
	}
}

void USpoutMediaCapture::OnRHIResourceCaptured_AnyThread(
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FTextureRHIRef InTexture)
{
	// Diagnostic-only in UE 5.5 path; keeps visibility if capture thread policy changes.
	static bool bLoggedAnyThread = false;
	if (!bLoggedAnyThread)
	{
		bLoggedAnyThread = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: OnRHIResourceCaptured_AnyThread fired - Texture=%s Valid=%d"),
			InTexture.IsValid() ? *InTexture->GetName().ToString() : TEXT("null"),
			InTexture.IsValid());
	}

	if (!InTexture.IsValid())
	{
		return;
	}

	FRHICommandListImmediate& RHICmdList = FRHICommandListExecutor::GetImmediateCommandList();
	FSpoutSender::SendRHIOnRenderThread(ResolvedSenderName, InTexture, RHICmdList, false);
}

void USpoutMediaCapture::OnRHIResourceCaptured_AnyThread(
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FBufferRHIRef InBuffer)
{
	static bool bLoggedAnyBuffer = false;
	if (!bLoggedAnyBuffer)
	{
		bLoggedAnyBuffer = true;
		UE_LOG(LogTemp, Warning, TEXT("SpoutMediaCapture: OnRHIResourceCaptured_AnyThread(Buffer) fired - buffer capture path is not supported for Spout sender"));
	}
}

void USpoutMediaCapture::BeforeFrameCaptured_RenderingThread(
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FTextureRHIRef InTexture)
{
	static bool bLoggedBeforeTexture = false;
	if (!bLoggedBeforeTexture)
	{
		bLoggedBeforeTexture = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: BeforeFrameCaptured_RenderingThread(Texture) fired"));
	}
}

void USpoutMediaCapture::BeforeFrameCaptured_RenderingThread(
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FBufferRHIRef InBuffer)
{
	static bool bLoggedBeforeBuffer = false;
	if (!bLoggedBeforeBuffer)
	{
		bLoggedBeforeBuffer = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: BeforeFrameCaptured_RenderingThread(Buffer) fired"));
	}
}

void USpoutMediaCapture::OnFrameCaptured_RenderingThread(
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	void* InBuffer,
	int32 Width,
	int32 Height,
	int32 BytesPerRow)
{
	static bool bLoggedCPU = false;
	if (!bLoggedCPU)
	{
		bLoggedCPU = true;
		UE_LOG(LogTemp, Warning, TEXT("SpoutMediaCapture: OnFrameCaptured_RenderingThread(CPU) fired - capture is on CPU readback path (%dx%d, stride=%d)"), Width, Height, BytesPerRow);
	}
}

void USpoutMediaCapture::OnCustomCapture_RenderingThread(
	FRDGBuilder& GraphBuilder,
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FRDGTextureRef InSourceTexture,
	FRDGTextureRef OutputTexture,
	const FRHICopyTextureInfo& CopyInfo,
	FVector2D CropU,
	FVector2D CropV)
{
	if (!InSourceTexture || !OutputTexture)
	{
		return;
	}

	static bool bLoggedCustom = false;
	if (!bLoggedCustom)
	{
		bLoggedCustom = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: OnCustomCapture_RenderingThread fired"));
	}

	// Keep MediaCapture pipeline valid by copying source into output.
	AddCopyTexturePass(GraphBuilder, InSourceTexture, OutputTexture, CopyInfo);

	FRDGTextureRef OutputTextureRef = OutputTexture;
	const FName SenderName = ResolvedSenderName;
	GraphBuilder.AddPass(
		RDG_EVENT_NAME("SpoutMediaCaptureSend"),
		ERDGPassFlags::None,
		[OutputTextureRef, SenderName](FRHICommandListImmediate& RHICmdList)
		{
			FTextureRHIRef OutputTextureRHI = OutputTextureRef->GetRHI();
			if (OutputTextureRHI.IsValid())
			{
				FSpoutSender::SendRHIOnRenderThread(SenderName, OutputTextureRHI, RHICmdList, false);
			}
		});
}

void USpoutMediaCapture::OnCustomCapture_RenderingThread(
	FRDGBuilder& GraphBuilder,
	const FCaptureBaseData& InBaseData,
	TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
	FRDGTextureRef InSourceTexture,
	FRDGBufferRef OutputBuffer,
	const FRHICopyTextureInfo& CopyInfo,
	FVector2D CropU,
	FVector2D CropV)
{
	static bool bLoggedCustomBuffer = false;
	if (!bLoggedCustomBuffer)
	{
		bLoggedCustomBuffer = true;
		UE_LOG(LogTemp, Warning, TEXT("SpoutMediaCapture: OnCustomCapture_RenderingThread(Buffer) fired - forcing texture output is required for Spout"));
	}
}

EMediaCaptureResourceType USpoutMediaCapture::GetCustomOutputResourceType() const
{
	return EMediaCaptureResourceType::Texture;
}

void USpoutMediaCapture::RegisterDisplayClusterDirectHook()
{
	if (bDirectHookRegistered)
	{
		return;
	}

	IDisplayCluster::Get().GetCallbacks().OnDisplayClusterPostRenderViewFamily_RenderThread().AddUObject(
		this, &USpoutMediaCapture::OnDisplayClusterPostRenderViewFamily_RenderThread);
	bDirectHookRegistered = true;
	UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: Direct nDisplay hook registered for viewport '%s'"), *ResolvedViewportId);
}

void USpoutMediaCapture::UnregisterDisplayClusterDirectHook()
{
	if (!bDirectHookRegistered)
	{
		return;
	}

	IDisplayCluster::Get().GetCallbacks().OnDisplayClusterPostRenderViewFamily_RenderThread().RemoveAll(this);
	bDirectHookRegistered = false;
	UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: Direct nDisplay hook unregistered"));
}

void USpoutMediaCapture::OnDisplayClusterPostRenderViewFamily_RenderThread(
	FRDGBuilder& GraphBuilder,
	const FSceneViewFamily& ViewFamily,
	const IDisplayClusterViewportProxy* ViewportProxy)
{
	if (!ViewportProxy || ResolvedViewportId.IsEmpty())
	{
		return;
	}

	if (!ViewportProxy->GetId().Equals(ResolvedViewportId, ESearchCase::IgnoreCase))
	{
		return;
	}

	TArray<FRHITexture*> Textures;
	TArray<FIntRect> Regions;
	if (!ViewportProxy->GetResourcesWithRects_RenderThread(EDisplayClusterViewportResourceType::InternalRenderTargetResource, Textures, Regions))
	{
		return;
	}

	if (Textures.Num() == 0 || !Textures[0])
	{
		return;
	}

	FRDGTextureRef SrcTextureRef = RegisterExternalTexture(GraphBuilder, Textures[0], TEXT("SpoutDirectNDisplayViewportTex"));
	if (!SrcTextureRef)
	{
		return;
	}

	static bool bLoggedDirectHookFrame = false;
	if (!bLoggedDirectHookFrame)
	{
		bLoggedDirectHookFrame = true;
		UE_LOG(LogTemp, Log, TEXT("SpoutMediaCapture: Direct nDisplay frame callback fired for viewport '%s'"), *ResolvedViewportId);
	}

	const FName SenderName = ResolveSenderName(ViewportProxy->GetId());
	FRDGTextureRef CapturedTexture = SrcTextureRef;
	GraphBuilder.AddPass(
		RDG_EVENT_NAME("SpoutDirectNDisplaySend"),
		ERDGPassFlags::None,
		[SenderName, CapturedTexture](FRHICommandListImmediate& RHICmdList)
		{
			FTextureRHIRef TextureRHI = CapturedTexture->GetRHI();
			if (TextureRHI.IsValid())
			{
				FSpoutSender::SendRHIOnRenderThread(SenderName, TextureRHI, RHICmdList, false);
			}
		});
}

FName USpoutMediaCapture::ResolveSenderName(const FString& InViewportId) const
{
	if (!CachedOutput.IsValid())
	{
		return NAME_None;
	}
	const FString ResolvedName = CachedOutput->BuildResolvedSpoutName(ResolvedNodeId, InViewportId);
	return FName(*ResolvedName);
}
