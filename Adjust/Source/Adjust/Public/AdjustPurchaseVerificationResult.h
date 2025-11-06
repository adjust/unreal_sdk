//
//  AdjustPurchaseVerificationResult.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustPurchaseVerificationResult.generated.h"

USTRUCT(BlueprintType)
struct FAdjustPurchaseVerificationResult
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString VerificationStatus;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    int Code = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString Message;
};

