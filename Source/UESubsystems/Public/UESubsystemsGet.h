// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "CoreMinimal.h"
#if UE_EDITOR
#include "Editor.h"
#endif //UE_EDITOR

template <class TSubsystemClass>
class UEEngineSubsystemGet
{
public:
	// Returns the engine-level subsystem of type TSubsystemClass.
	static FORCEINLINE TSubsystemClass* Get()
	{ 
		if (IsValid(GEngine))
		{
			return GEngine->GetEngineSubsystem<TSubsystemClass>();
		}
		return nullptr;
	}
};

template <class TSubsystemClass>
class UEEditorSubsystemGet
{
public:
	// Returns the editor-level subsystem of type TSubsystemClass.
	static FORCEINLINE TSubsystemClass* Get()
	{
#if UE_EDITOR
		if (IsValid(GEditor))
		{
			return GEditor->GetEditorSubsystem<TSubsystemClass>();
		}
#endif //UE_EDITOR
		return nullptr;
	}
};

template <class TSubsystemClass>
class UEGameInstanceSubsystemGet
{
public:
	// Returns the subsystem from a UGameInstance.
	static FORCEINLINE TSubsystemClass* Get(const UGameInstance* GameInstance)
	{
		if (IsValid(GameInstance))
		{
			return UGameInstance::GetSubsystem<TSubsystemClass>(GameInstance);
		}
		return nullptr;
	}

	// Gets the subsystem from a UWorld by first getting its GameInstance.
	static FORCEINLINE TSubsystemClass* Get(const UWorld* World)
	{
		if (IsValid(World))
		{
			return Get(World->GetGameInstance());
		}
		return nullptr;
	}

	// Gets the subsystem from any UObject by first getting its UWorld, then its GameInstance.
	static FORCEINLINE TSubsystemClass* Get(const UObject* WorldContextObject)
	{
		if (IsValid(WorldContextObject))
		{
			return Get(WorldContextObject->GetWorld());
		}
		return nullptr;
	}
};

template <class TSubsystemClass>
class UEWorldSubsystemGet
{
public:
	// Returns the world-level subsystem from a UWorld.
	static FORCEINLINE TSubsystemClass* Get(const UWorld* World)
	{
		if (IsValid(World))
		{
			return UWorld::GetSubsystem<TSubsystemClass>(World);
		}
		return nullptr;
	}

	// Resolves the world from any UObject and gets the subsystem.
	static FORCEINLINE TSubsystemClass* Get(const UObject* WorldContextObject)
	{
		if (IsValid(WorldContextObject))
		{
			return Get(WorldContextObject->GetWorld());
		}
		return nullptr;
	}
};

template <class TSubsystemClass>
class UELocalPlayerSubsystemGet
{
public:
	// Returns the subsystem from a ULocalPlayer.
	static FORCEINLINE TSubsystemClass* Get(const ULocalPlayer* LocalPlayer)
	{
		if (IsValid(LocalPlayer))
		{
			return LocalPlayer->GetSubsystem<TSubsystemClass>();
		}
		return nullptr;
	}
};
