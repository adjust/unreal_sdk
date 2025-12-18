//
//  AdjustTest.Build.cs
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

using System.IO;
using UnrealBuildTool;

public class AdjustTest : ModuleRules
{
    public AdjustTest(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateIncludePaths.Add("AdjustTest/Private");

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "Adjust" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.Add("BlueprintGraph");
        }

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicAdditionalFrameworks.Add(
                new Framework("AdjustTestLibrary", "../ThirdParty/IOS/AdjustTestLibrary.framework.zip")
            );
        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(PluginPath, "AdjustTest_UPL_Android.xml"));
            PublicIncludePathModuleNames.Add("Launch");
        }
    }
}
