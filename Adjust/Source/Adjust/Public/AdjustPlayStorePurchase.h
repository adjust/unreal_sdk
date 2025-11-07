//
//  AdjustPlayStorePurchase.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 6th November 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustPlayStorePurchase.generated.h"

USTRUCT(BlueprintType)
struct FAdjustPlayStorePurchase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString ProductId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString PurchaseToken;
};

