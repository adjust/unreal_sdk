//
//  AdjustAppStorePurchase.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 6th November 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustAppStorePurchase.generated.h"

USTRUCT(BlueprintType)
struct FAdjustAppStorePurchase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TransactionId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString ProductId;
};

