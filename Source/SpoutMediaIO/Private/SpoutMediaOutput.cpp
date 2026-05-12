#include "SpoutMediaOutput.h"

#include "SpoutMediaCapture.h"

bool USpoutMediaOutput::Validate(FString& OutFailureReason) const
{
	if (SpoutName.IsEmpty())
	{
		OutFailureReason = TEXT("SpoutName cannot be empty.");
		return false;
	}

	return true;
}

FIntPoint USpoutMediaOutput::GetRequestedSize() const
{
	// Let MediaCapture use the source viewport size to avoid hard mismatch with nDisplay viewport dimensions.
	return UMediaOutput::RequestCaptureSourceSize;
}

EPixelFormat USpoutMediaOutput::GetRequestedPixelFormat() const
{
	// nDisplay's RHI immediate capture can fail silently when output format is forced to an
	// incompatible value. Accept source format and let SpoutSender handle DXGI sanitization.
	return EPixelFormat::PF_Unknown;
}

EMediaCaptureConversionOperation USpoutMediaOutput::GetConversionOperation(EMediaCaptureSourceType InSourceType) const
{
	// Force custom conversion path so USpoutMediaCapture::OnCustomCapture_RenderingThread
	// is invoked for each frame in DisplayCluster capture.
	return EMediaCaptureConversionOperation::CUSTOM;
}

UMediaCapture* USpoutMediaOutput::CreateMediaCaptureImpl()
{
	USpoutMediaCapture* Capture = NewObject<USpoutMediaCapture>(this, USpoutMediaCapture::StaticClass());
	Capture->SetMediaOutput(this);
	return Capture;
}

FString USpoutMediaOutput::BuildResolvedSpoutName(const FString& InNodeId, const FString& InViewportId) const
{
	if (!bAppendNodeAndViewport)
	{
		return SpoutName;
	}

	FString Resolved = SpoutName;
	if (!InNodeId.IsEmpty())
	{
		Resolved += TEXT("_") + InNodeId;
	}
	if (!InViewportId.IsEmpty())
	{
		Resolved += TEXT("_") + InViewportId;
	}

	return Resolved;
}
