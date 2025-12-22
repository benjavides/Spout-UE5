/**
 * Declares the shared sender/receiver registry and state objects that track Spout handles,
 * textures, and cached wrappers across the plugin.
 */
#pragma once

#include "CoreMinimal.h"
#include "SpoutBPFunctionLibrary.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <d3d11.h>
#include <wrl/client.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

class FSpoutSharedSender
{
public:
	FSpoutSharedSender(FName InName, ESpoutType InType);
	~FSpoutSharedSender();

	// Releases shared handles and unregisters sender names when applicable.
	void ReleaseResources();

	// Spout sender/receiver identifier (shared across the registry).
	FName Name;
	uint32 Width = 0;
	uint32 Height = 0;
	// Distinguishes sender vs receiver ownership semantics.
	ESpoutType Type = ESpoutType::Sender;
	bool bRegistered = false;

	// Shared DX11 texture exposed to other Spout clients (senders only).
	Microsoft::WRL::ComPtr<ID3D11Texture2D> SharedTexture;
	HANDLE SharedHandle = nullptr;

	// CPU-readable staging texture for receiver readback.
	Microsoft::WRL::ComPtr<ID3D11Texture2D> StagingTexture;
	// Optional intermediate texture for sender-side gamma correction.
	Microsoft::WRL::ComPtr<ID3D11Texture2D> GammaTexture;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> GammaRTV;

	// Cached D3D11 wrapper for a D3D12 resource (sender path).
	Microsoft::WRL::ComPtr<ID3D11Texture2D> CachedWrappedResource;
	void* CachedNativeResource = nullptr;

	// Protects SharedTexture/handle updates across game and render threads.
	FCriticalSection ResourceMutex;
};

class FSpoutSenderRegistry
{
public:
	// Global registry of sender/receiver shared state.
	static FSpoutSenderRegistry& Get();

	// Finds an existing entry or creates a new one for the given name.
	TSharedPtr<FSpoutSharedSender> FindOrAdd(const FName& Name, ESpoutType Type);
	TSharedPtr<FSpoutSharedSender> Find(const FName& Name);
	void Remove(const FName& Name);
	void Clear();

private:
	TMap<FName, TSharedPtr<FSpoutSharedSender>> Senders;
	// Protects registry mutations across threads.
	FCriticalSection Mutex;
};
