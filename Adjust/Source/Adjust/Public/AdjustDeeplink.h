//
//  AdjustDeeplink.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 16th January 2025.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustDeeplink.generated.h"

USTRUCT(BlueprintType)
struct FAdjustDeeplink
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Deeplink;
};
