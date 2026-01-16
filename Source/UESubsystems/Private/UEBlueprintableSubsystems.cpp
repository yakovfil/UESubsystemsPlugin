// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#include "UEBlueprintableSubsystems.h"

void IUEBlueprintableSubsystem::Initialize(UObject* Self, FSubsystemCollectionBase& Collection)
{
	Execute_InitializeBP(Self);
}

bool IUEBlueprintableSubsystem::ShouldCreateSubsystem(const UObject* Self, UObject* Outer) const
{
	TArray<UClass*> ChildClasses;
	GetDerivedClasses(Self->GetClass(), ChildClasses, false);

	if (ChildClasses.Num() > 0)
	{
		// Only create an instance if there is no override implementation defined elsewhere
		return false;
	}

	return Execute_ShouldCreateSubsystemBP(Self, Outer);
}

void IUEBlueprintableSubsystem::Deinitialize(UObject* Self)
{
	Execute_DeinitializeBP(Self);
}

UUEBlueprintableSubsystem::UUEBlueprintableSubsystem(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UUEBlueprintableGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	IUEBlueprintableSubsystem::Initialize(this, Collection);
}

bool UUEBlueprintableGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return IUEBlueprintableSubsystem::ShouldCreateSubsystem(this, Outer);
}

void UUEBlueprintableGameInstanceSubsystem::Deinitialize()
{
	IUEBlueprintableSubsystem::Deinitialize(this);
	Super::Deinitialize();
}

bool UUEBlueprintableGameInstanceSubsystem::ShouldCreateSubsystemBP_Implementation(UObject* Outer) const
{
	return true;
}

void UUEBlueprintableWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	IUEBlueprintableSubsystem::Initialize(this, Collection);
}

bool UUEBlueprintableWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return IUEBlueprintableSubsystem::ShouldCreateSubsystem(this, Outer);
}

void UUEBlueprintableWorldSubsystem::Deinitialize()
{
	IUEBlueprintableSubsystem::Deinitialize(this);
	Super::Deinitialize();
}

bool UUEBlueprintableWorldSubsystem::ShouldCreateSubsystemBP_Implementation(UObject* Outer) const
{
	if (UWorld* World = Cast<UWorld>(Outer))
	{
		const auto WorldType = World->WorldType;
		if ((WorldType != EWorldType::Editor) && (WorldType != EWorldType::EditorPreview) && (WorldType != EWorldType::Inactive))
		{
			return true;
		}
		return RunWhileEditing;
	}
	return false;
}

void UUEBlueprintableLocalPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	IUEBlueprintableSubsystem::Initialize(this, Collection);
}

bool UUEBlueprintableLocalPlayerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return IUEBlueprintableSubsystem::ShouldCreateSubsystem(this, Outer);
}

void UUEBlueprintableLocalPlayerSubsystem::Deinitialize()
{
	IUEBlueprintableSubsystem::Deinitialize(this);
	Super::Deinitialize();
}

bool UUEBlueprintableLocalPlayerSubsystem::ShouldCreateSubsystemBP_Implementation(UObject* Outer) const
{
	return true;
}


