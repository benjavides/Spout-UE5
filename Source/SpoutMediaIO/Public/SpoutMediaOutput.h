#pragma once

#include "CoreMinimal.h"
#include "MediaOutput.h"
#include "SpoutMediaOutput.generated.h"

UCLASS(BlueprintType)
class SPOUTMEDIAIO_API USpoutMediaOutput : public UMediaOutput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	FString SpoutName = TEXT("SpoutOutput");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	bool bAppendNodeAndViewport = true;

	// Used by direct nDisplay callback fallback path when MediaCapture callbacks are not dispatched.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	FString ViewportId = TEXT("VP_0");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture")
	FIntPoint OutputSize = FIntPoint(1920, 1080);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture")
	TEnumAsByte<EPixelFormat> OutputPixelFormat = EPixelFormat::PF_B8G8R8A8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture")
	bool bInvertAlpha = false;

	virtual bool Validate(FString& OutFailureReason) const override;
	virtual FIntPoint GetRequestedSize() const override;
	virtual EPixelFormat GetRequestedPixelFormat() const override;
	virtual EMediaCaptureConversionOperation GetConversionOperation(EMediaCaptureSourceType InSourceType) const override;
	virtual UMediaCapture* CreateMediaCaptureImpl() override;

	FString BuildResolvedSpoutName(const FString& InNodeId, const FString& InViewportId) const;
};
