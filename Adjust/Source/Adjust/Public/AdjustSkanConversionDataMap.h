//
//  AdjustSkanConversionDataMap.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 6th November 2025.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "AdjustSkanConversionDataMap.generated.h"

/**
 * @brief Structure containing SKAdNetwork conversion value update data as a map.
 */
USTRUCT(BlueprintType)
struct ADJUST_API FAdjustSkanConversionDataMap
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> Data;
};

