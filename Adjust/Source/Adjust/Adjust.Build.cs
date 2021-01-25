//
//  Adjust.Build.cs
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2019 Adjust GmbH. All rights reserved.
//

using System.IO;
using UnrealBuildTool;

public class Adjust : ModuleRules {
    public Adjust(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {});
        PrivateIncludePaths.AddRange(new string[] { "Adjust/Private" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Projects" });
        PrivateDependencyModuleNames.AddRange(new string[] {});
        DynamicallyLoadedModuleNames.AddRange(new string[] {});

        if (Target.Platform == UnrealTargetPlatform.IOS) {
            bool bHasAdjust = false;
            string AdjustNFLDir = "";
            try {
                AdjustNFLDir = System.IO.Path.Combine(ModuleDirectory, "../ThirdParty/IOS");
                bHasAdjust = System.IO.Directory.Exists(AdjustNFLDir);
            } catch (System.Exception) {}

            if (bHasAdjust) {
                string Err = string.Format("Adjust SDK found in {0}", AdjustNFLDir);
                System.Console.WriteLine(Err);
                PublicAdditionalLibraries.Add(Path.Combine(AdjustNFLDir, "AdjustSdk.a"));
                PublicWeakFrameworks.AddRange(new string[] { "AppTrackingTransparency" });
                PublicFrameworks.AddRange(new string[] { "AdSupport", "iAd", "CoreTelephony", "StoreKit", "AdServices" });
                PublicLibraryPaths.Add(AdjustNFLDir);
                PublicDefinitions.Add("WITH_ADJUST=1");
                PublicDefinitions.Add("UE4_ADJUST_VER=4.20.0");
                PrivateIncludePaths.Add("Adjust/Private/IOS");
                PublicAdditionalLibraries.Add("z");
                PublicAdditionalLibraries.Add("sqlite3");
            } else {
                string Err = string.Format("Adjust SDK not found in {0}", AdjustNFLDir);
                System.Console.WriteLine(Err);
                PublicDefinitions.Add("WITH_ADJUST=0");
            }
        } else if (Target.Platform == UnrealTargetPlatform.Android) {
            bool bHasAdjust = false;
            string AdjustNFLDir = "";
            try {
                AdjustNFLDir = System.IO.Path.Combine(ModuleDirectory, "../ThirdParty/Android");
                bHasAdjust = System.IO.Directory.Exists(AdjustNFLDir);
            } catch (System.Exception) {}

            PublicIncludePathModuleNames.Add("Launch");

            if (bHasAdjust) {
                string Err = string.Format("Adjust SDK found in {0}", AdjustNFLDir);
                System.Console.WriteLine(Err);
                PublicLibraryPaths.Add(AdjustNFLDir);
                PublicDefinitions.Add("WITH_ADJUST=1");
                PublicDefinitions.Add("UE4_ADJUST_VER=4.20.0");

                PrivateDependencyModuleNames.AddRange(new string[] { "Launch", });

                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "Adjust_UPL_Android.xml"));
            } else {
                string Err = string.Format("Adjust SDK not found in {0}", AdjustNFLDir);
                System.Console.WriteLine(Err);
                PublicDefinitions.Add("WITH_ADJUST=0");
            }
        } else {
            PublicDefinitions.Add("WITH_ADJUST=0");
        }
    }
}
