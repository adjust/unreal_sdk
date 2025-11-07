//
//  AdjustModule.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "AdjustModule.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#if WITH_EDITOR
#include "Interfaces/IPluginManager.h"
#endif

#define LOCTEXT_NAMESPACE "FAdjustModule"

DEFINE_LOG_CATEGORY(AdjustLog);

void FAdjustModule::StartupModule()
{
    // this code will execute after your module is loaded into memory
    // the exact timing is specified in the .uplugin file per-module
}

void FAdjustModule::ShutdownModule()
{
    // this function may be called during shutdown to clean up your module
    // for modules that support dynamic reloading, we call this function before unloading the module
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FAdjustModule, Adjust)
