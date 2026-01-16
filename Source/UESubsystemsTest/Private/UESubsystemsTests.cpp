// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
#include "UESubsystemsTests.h"
#include "Misc/AutomationTest.h"
#include "UESubsystemsSettings.h"
#include "UESubsystemsPrimaryDataAsset.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUESubsystemsTestSettings, "UESubsystems.Settings", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FUESubsystemsTestSettings::RunTest(const FString& Parameters)
{
	const UUESubsystemsSettings* UESubsystemsSettings = GetDefault<UUESubsystemsSettings>();
	TestNotNull("UUESubsystemsSettings exists", UESubsystemsSettings);
	if (IsValid(UESubsystemsSettings))
	{
		auto* UESubsystemsAsset = UESubsystemsSettings->UESubsystemsAsset.TryLoad();
		TestNotNull("UESubsystemsAsset exists", UESubsystemsAsset);

		UUESubsystemsPrimaryDataAsset* UESubsystemsPrimaryDataAsset = Cast<UUESubsystemsPrimaryDataAsset>(UESubsystemsAsset);
		TestNotNull("UUESubsystemsPrimaryDataAsset exists", UESubsystemsPrimaryDataAsset);
	}

	return true;
}
