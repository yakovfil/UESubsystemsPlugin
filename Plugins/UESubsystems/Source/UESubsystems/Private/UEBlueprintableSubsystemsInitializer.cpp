// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#include "UEBlueprintableSubsystemsInitializer.h"

#include "UEBlueprintableSubsystems.h"

void UBlueprintableGameInstanceSubsystemInitializer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	BlueprintableSubsystemInitialize<FBlueprintableGameInstanceSubsystemDescription>(GetGameInstance(), Collection);
}

void UBlueprintableGameInstanceSubsystemInitializer::Deinitialize()
{
	Super::Deinitialize();
}

void UBlueprintableWorldSubsystemInitializer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (IsValid(GetWorld()))
	{
		BlueprintableSubsystemInitialize<FBlueprintableWorldSubsystemDescription>(GetWorld()->GetGameInstance(), Collection);
	}
}

void UBlueprintableWorldSubsystemInitializer::Deinitialize()
{
	Super::Deinitialize();
}

void UBlueprintableLocalPlayerSubsystemInitializer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (IsValid(GetWorld()))
	{
		BlueprintableSubsystemInitialize<FBlueprintableLocalPlayerSubsystemDescription>(GetWorld()->GetGameInstance(), Collection);
	}
}

void UBlueprintableLocalPlayerSubsystemInitializer::Deinitialize()
{
	Super::Deinitialize();
}
