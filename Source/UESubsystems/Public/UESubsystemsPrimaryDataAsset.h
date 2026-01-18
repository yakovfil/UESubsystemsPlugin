// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UESubsystemsPrimaryDataAsset.generated.h"

UENUM(BlueprintType)
enum class EUESubsystemsMode : uint8
{
	ESM_None				UMETA(hidden),
	ESM_ClientServer		UMETA(DisplayName = "Client and Server"),
	ESM_ClientOnly			UMETA(DisplayName = "Client Only"),
	ESM_ServerOnly			UMETA(DisplayName = "Server Only"),
	ESM_MAX					UMETA(hidden)
};

USTRUCT(BlueprintInternalUseOnly)
struct FBlueprintableGameInstanceSubsystemDescription
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<class UUEBlueprintableGameInstanceSubsystem> SubsystemsClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EUESubsystemsMode SubsystemsMode = EUESubsystemsMode::ESM_ClientServer;
};

USTRUCT(BlueprintInternalUseOnly)
struct FBlueprintableWorldSubsystemDescription
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<class UUEBlueprintableWorldSubsystem> SubsystemsClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EUESubsystemsMode SubsystemsMode = EUESubsystemsMode::ESM_ClientServer;
};

USTRUCT(BlueprintInternalUseOnly)
struct FBlueprintableLocalPlayerSubsystemDescription
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<class UUEBlueprintableLocalPlayerSubsystem> SubsystemsClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EUESubsystemsMode SubsystemsMode = EUESubsystemsMode::ESM_ClientServer;
};

template<typename T>
concept SubsystemDescription =
(std::same_as<T, FBlueprintableGameInstanceSubsystemDescription> ||
	std::same_as<T, FBlueprintableWorldSubsystemDescription> ||
	std::same_as<T, FBlueprintableLocalPlayerSubsystemDescription>);

UCLASS(BlueprintType)
class UESUBSYSTEMS_API UUESubsystemsPrimaryDataAsset :public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FBlueprintableGameInstanceSubsystemDescription> GameInstanceSubsystems;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FBlueprintableWorldSubsystemDescription> WorldSubsystems;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FBlueprintableLocalPlayerSubsystemDescription> LocalPlayerSubsystems;

	template <typename DescriptionStruct>
	constexpr const TArray<DescriptionStruct>& GetDescriptions() const
	{
		static_assert(SubsystemDescription<DescriptionStruct>, "DescriptionStruct no supported");
		if constexpr (std::is_same_v<DescriptionStruct, FBlueprintableGameInstanceSubsystemDescription>)
		{
			return GameInstanceSubsystems;
		}
		if constexpr (std::is_same_v<DescriptionStruct, FBlueprintableWorldSubsystemDescription>)
		{
			return WorldSubsystems;
		}
		if constexpr (std::is_same_v<DescriptionStruct, FBlueprintableLocalPlayerSubsystemDescription>)
		{
			return LocalPlayerSubsystems;
		}
	}

protected:

	static FName AssetName() { return TEXT("UESubsystemsAsset"); }
	virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId(AssetName(), GetFName()); }
};
