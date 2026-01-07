//
//  AdjustTestModule.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(AdjustTestLog, Log, All);

class FAdjustTestModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
