// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#include "UESubsystems.h"
#include "UESubsystemsLog.h"

#define LOCTEXT_NAMESPACE "FUESubsystemsModule"

DEFINE_LOG_CATEGORY(LogUESubsystems);

void FUESubsystemsModule::StartupModule()
{
}

void FUESubsystemsModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUESubsystemsModule, UESubsystems)