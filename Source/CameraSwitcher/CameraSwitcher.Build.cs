// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CameraSwitcher : ModuleRules
{
	public CameraSwitcher(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"EnhancedInput", 
			"InputCore",
			"UMG"
		});

		PrivateIncludePaths.AddRange(new string[] { "CameraSwitcher" });
		//PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
