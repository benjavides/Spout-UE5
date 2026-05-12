/**
 * Declares the sender API that bridges Blueprint requests to the render-thread Spout
 * publishing path implemented in SpoutSender.cpp.
 */
#pragma once

#include "CoreMinimal.h"
#include "RHI.h"
#include "RHICommandList.h"
#include "SpoutBPFunctionLibrary.h"

class SPOUTPLUGIN_API FSpoutSender
{
public:
	// Kicks a render-thread copy from an RHI texture to a shared Spout DX11 texture.
	static bool Send(FName SpoutName, ESpoutSendTextureFrom SendTextureFrom, UTextureRenderTarget2D* TextureRenderTarget2D);
	// Removes a sender from the registry and releases its shared handle.
	static void Close(FName SpoutName);
	// Removes viewport hooks used by the GameViewport sender path.
	static void Shutdown();

	// Must be called on the render thread. Submits SourceRHI to the named Spout sender.
	// bIsViewport controls the RHI access state assumed before and restored after copy.
	static void SendRHIOnRenderThread(FName SpoutName, const FTextureRHIRef& SourceRHI, FRHICommandListImmediate& RHICmdList, bool bIsViewport = false);

	// Initializes the Spout D3D context. Must be called once on the game thread before
	// SendRHIOnRenderThread is used (e.g. from UMediaCapture::InitializeCapture).
	// Returns true if Spout is available after initialization.
	static bool Initialize();
};
