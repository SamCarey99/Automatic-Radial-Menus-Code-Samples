// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class RadialMenu : ModuleRules
{
	public RadialMenu(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"});
		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //Requried Radial Menu dependency
        PrivateDependencyModuleNames.AddRange(new string[]  { "AutomaticRadialMenus" });
		PrivateIncludePathModuleNames.AddRange(new string[] { "AutomaticRadialMenus" });
        PublicDependencyModuleNames.AddRange(new string[]   {"SlateCore" });
    }
}
