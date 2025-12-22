/**
 * Wires the module lifecycle to Spout resource startup/shutdown, delegating teardown to
 * the Blueprint function library's global shutdown path.
 */
#include "SpoutModule.h"
#include "SpoutBPFunctionLibrary.h"

DEFINE_LOG_CATEGORY(LogSpoutPlugin);

#define LOCTEXT_NAMESPACE "FSpoutModule"

void FSpoutModule::StartupModule()
{
	// Nothing to initialize eagerly; D3D/Spout resources are created on first use.
	UE_LOG(LogSpoutPlugin, Log, TEXT("Spout Plugin Loaded"));
}

void FSpoutModule::ShutdownModule()
{
	// Ensure all DX/Spout resources are properly released before module teardown.
	USpoutBPFunctionLibrary::GlobalShutdown();
	UE_LOG(LogSpoutPlugin, Log, TEXT("Spout Plugin Unloaded"));
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FSpoutModule, SpoutPlugin)
