//
//  AdjustTest.Build.cs
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
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
            
            // add JAR files to AndroidJavaLibs so they get copied to the build
            string LibsPath = Path.Combine(ModuleDirectory, "Private", "libs");
            string[] JarFiles = {
                "adjust-test-options.jar",
                "adjust-test-library.jar",
                "gson-2.8.6.jar",
                "Java-WebSocket-1.4.0.jar",
                "slf4j-api-1.7.30.jar",
                "slf4j-simple-1.7.30.jar"
            };
            foreach (string JarFile in JarFiles)
            {
                string JarPath = Path.Combine(LibsPath, JarFile);
                if (File.Exists(JarPath))
                {
                    AdditionalPropertiesForReceipt.Add("AndroidJavaLibs", JarPath);
                }
            }
            
            PublicIncludePathModuleNames.Add("Launch");
        }
    }
}
