#pragma once

#include "CoreMinimal.h"
#include "MediaCapture.h"
#include "SpoutMediaCapture.generated.h"

class USpoutMediaOutput;
class IDisplayClusterViewportProxy;
class FSceneViewFamily;

UCLASS()
class SPOUTMEDIAIO_API USpoutMediaCapture : public UMediaCapture
{
	GENERATED_BODY()

public:
	void SetMediaOutput(USpoutMediaOutput* InMediaOutput);

protected:
	virtual bool ValidateMediaOutput() const override;
	virtual bool InitializeCapture() override;
	virtual void StopCaptureImpl(bool bAllowPendingFrameToBeProcess) override;
	virtual bool ShouldCaptureRHIResource() const override { return true; }
	virtual bool SupportsAnyThreadCapture() const override { return false; }

	// UE 5.5 GPU capture callback path. nDisplay hits this render-thread variant.
	virtual void OnRHIResourceCaptured_RenderingThread(
		FRHICommandListImmediate& RHICmdList,
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture) override;
	virtual void OnRHIResourceCaptured_RenderingThread(
		FRHICommandListImmediate& RHICmdList,
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FBufferRHIRef InBuffer) override;

	// Keep this override for diagnostics/fallback if capture mode changes.
	virtual void OnRHIResourceCaptured_AnyThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture) override;
	virtual void OnRHIResourceCaptured_AnyThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FBufferRHIRef InBuffer) override;

	virtual void BeforeFrameCaptured_RenderingThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture) override;
	virtual void BeforeFrameCaptured_RenderingThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FBufferRHIRef InBuffer) override;
	virtual void OnFrameCaptured_RenderingThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		void* InBuffer,
		int32 Width,
		int32 Height,
		int32 BytesPerRow) override;
	virtual void OnCustomCapture_RenderingThread(
		FRDGBuilder& GraphBuilder,
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FRDGTextureRef InSourceTexture,
		FRDGTextureRef OutputTexture,
		const FRHICopyTextureInfo& CopyInfo,
		FVector2D CropU,
		FVector2D CropV) override;
	virtual void OnCustomCapture_RenderingThread(
		FRDGBuilder& GraphBuilder,
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FRDGTextureRef InSourceTexture,
		FRDGBufferRef OutputBuffer,
		const FRHICopyTextureInfo& CopyInfo,
		FVector2D CropU,
		FVector2D CropV) override;
	virtual EMediaCaptureResourceType GetCustomOutputResourceType() const override;

private:
	void RegisterDisplayClusterDirectHook();
	void UnregisterDisplayClusterDirectHook();
	void OnDisplayClusterPostRenderViewFamily_RenderThread(
		FRDGBuilder& GraphBuilder,
		const FSceneViewFamily& ViewFamily,
		const IDisplayClusterViewportProxy* ViewportProxy);
	FName ResolveSenderName(const FString& InViewportId) const;

	TWeakObjectPtr<USpoutMediaOutput> CachedOutput;
	FName ResolvedSenderName;
	FString ResolvedNodeId = TEXT("Node_0");
	FString ResolvedViewportId = TEXT("VP_0");
	bool bDirectHookRegistered = false;
};
