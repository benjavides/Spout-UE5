/**
 * Declares the Spout plugin module interface and log category used by the runtime implementation.
 */
#pragma once

#include "Modules/ModuleManager.h"

// Global log category for the plugin to keep Spout/D3D diagnostics consistent.
DECLARE_LOG_CATEGORY_EXTERN(LogSpoutPlugin, Log, All);

class FSpoutModule : public IModuleInterface
{
public:
	// Startup/shutdown are called on the game thread by the module manager.
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
