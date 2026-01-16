// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "CoreMinimal.h"

class FUESubsystemsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
