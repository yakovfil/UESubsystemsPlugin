// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "Engine/DeveloperSettings.h"

#include "UESubsystemsSettings.generated.h"


UCLASS(Config=Game, DefaultConfig, DisplayName="SubsystemsSettings")
class UESUBSYSTEMS_API UUESubsystemsSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, config, Category = "Settings", meta=(DisplayName="Subsystems data asset", AllowedClasses = "/Script/UESubsystems.UESubsystemsPrimaryDataAsset"))
	FSoftObjectPath UESubsystemsAsset;
};
