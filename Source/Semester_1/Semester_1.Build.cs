// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Semester_1 : ModuleRules
{
	public Semester_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
