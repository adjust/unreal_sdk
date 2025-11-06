//
//  AdjustAppStoreSubscription.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 6th November 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustAppStoreSubscription.generated.h"

USTRUCT(BlueprintType)
struct FAdjustAppStoreSubscription
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int64 Price;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TransactionId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TransactionDate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString SalesRegion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};

