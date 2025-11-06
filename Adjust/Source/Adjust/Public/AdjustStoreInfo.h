//
//  AdjustStoreInfo.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustStoreInfo.generated.h"

USTRUCT(BlueprintType)
struct FAdjustStoreInfo
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString StoreName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString StoreAppId;
};

