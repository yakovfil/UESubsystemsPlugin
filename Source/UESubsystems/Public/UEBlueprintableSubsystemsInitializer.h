// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Subsystems/WorldSubsystem.h"
#include "Subsystems/LocalPlayerSubsystem.h"

#include "UESubsystemsPrimaryDataAsset.h"
#include "UESubsystemsSettings.h"

#if UE_EDITOR
#include "Editor.h"
#endif //UE_EDITOR

#include "UEBlueprintableSubsystemsInitializer.generated.h"

template <typename T>
void BlueprintableSubsystemInitialize(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	const UUESubsystemsSettings* settings = GetDefault<UUESubsystemsSettings>();
	if (settings != nullptr)
	{
		UUESubsystemsPrimaryDataAsset* DataAsset = Cast<UUESubsystemsPrimaryDataAsset>(settings->UESubsystemsAsset.TryLoad());
		if (DataAsset != nullptr)
		{
			const bool IsServer = IsValid(GameInstance) ? GameInstance->IsDedicatedServerInstance() : false;
			auto& SubsystemDescriptions = DataAsset->GetDescriptions<T>();
			for (auto& SubsystemDescription : SubsystemDescriptions)
			{
				if (IsServer && SubsystemDescription.SubsystemsMode == EUESubsystemsMode::ESM_ClientOnly)
				{
					continue;
				}
				if (SubsystemDescription.SubsystemsClass != nullptr)
				{
					Collection.InitializeDependency(SubsystemDescription.SubsystemsClass);
				}
			}
		}
	}
}

UCLASS()
class UBlueprintableGameInstanceSubsystemInitializer : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};

UCLASS()
class UBlueprintableWorldSubsystemInitializer : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};

UCLASS()
class UBlueprintableLocalPlayerSubsystemInitializer : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
};
