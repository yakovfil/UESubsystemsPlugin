// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#pragma once

#include "UObject/Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Subsystems/WorldSubsystem.h"
#include "Subsystems/LocalPlayerSubsystem.h"

#include "UEBlueprintableSubsystems.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class  UUEBlueprintableSubsystem : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class UESUBSYSTEMS_API IUEBlueprintableSubsystem
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool ShouldCreateSubsystemBP(UObject* Outer) const;

	UFUNCTION(BlueprintNativeEvent)
	void InitializeBP();

	UFUNCTION(BlueprintNativeEvent)
	void DeinitializeBP();

protected:
	bool ShouldCreateSubsystem(const UObject* Self, UObject* Outer) const;
	void Initialize(UObject* Self, FSubsystemCollectionBase& Collection);
	void Deinitialize(UObject* Self);
};

UCLASS(Abstract, Blueprintable)
class UESUBSYSTEMS_API UUEBlueprintableGameInstanceSubsystem : public UGameInstanceSubsystem, public IUEBlueprintableSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	virtual bool ShouldCreateSubsystemBP_Implementation(UObject* Outer) const override;
};

UCLASS(Abstract, Blueprintable)
class UESUBSYSTEMS_API UUEBlueprintableWorldSubsystem : public UWorldSubsystem, public IUEBlueprintableSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (ToolTip = "Only turn it on if you know exactly what you're doing."))
	bool RunWhileEditing = false;

	virtual bool ShouldCreateSubsystemBP_Implementation(UObject* Outer) const override;
};

UCLASS(Abstract, Blueprintable)
class UESUBSYSTEMS_API UUEBlueprintableLocalPlayerSubsystem : public ULocalPlayerSubsystem, public IUEBlueprintableSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	virtual bool ShouldCreateSubsystemBP_Implementation(UObject* Outer) const override;
};
