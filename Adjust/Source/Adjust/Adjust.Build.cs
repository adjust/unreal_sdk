//
//  Adjust.Build.cs
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

using System.IO;
using UnrealBuildTool;

public class Adjust : ModuleRules
{
    public Adjust(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateIncludePaths.Add("Adjust/Private");

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.Add("BlueprintGraph");
        }

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicAdditionalFrameworks.Add(
                new Framework("AdjustSdk", "../ThirdParty/IOS/AdjustSdk.framework.zip")
            );
            string AdjustSigLibPath = Path.Combine(ModuleDirectory, "../ThirdParty/IOS/AdjustSigSdk.a");
            PublicAdditionalLibraries.Add(AdjustSigLibPath);

            PublicWeakFrameworks.AddRange(new string[] {
                "AdSupport",
                "AdServices",
                "StoreKit",
                "AppTrackingTransparency"
            });
        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(PluginPath, "Adjust_UPL_Android.xml"));
            PublicIncludePathModuleNames.Add("Launch");
        }
    }
}
