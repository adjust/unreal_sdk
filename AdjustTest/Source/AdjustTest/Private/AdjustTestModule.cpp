//
//  AdjustTestModule.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#include "AdjustTestModule.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#if WITH_EDITOR
#include "Interfaces/IPluginManager.h"
#endif

#define LOCTEXT_NAMESPACE "FAdjustTestModule"

DEFINE_LOG_CATEGORY(AdjustTestLog);

void FAdjustTestModule::StartupModule()
{
    // this code will execute after your module is loaded into memory
    // the exact timing is specified in the .uplugin file per-module
}

void FAdjustTestModule::ShutdownModule()
{
    // this function may be called during shutdown to clean up your module
    // for modules that support dynamic reloading, we call this function before unloading the module
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FAdjustTestModule, AdjustTest)
