// Copyright 2026 Yakov. Placed under the MIT license.
// Unreal Engine Blueprintable Subsystems and Subsystems Getter
using UnrealBuildTool;

public class UESubsystems : ModuleRules
{
	public UESubsystems(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp20;

        PublicDependencyModuleNames.AddRange( new string[] { "Core", } );

		PrivateDependencyModuleNames.AddRange( new string[] { "CoreUObject", "Engine", "DeveloperSettings", } );
	}
}
