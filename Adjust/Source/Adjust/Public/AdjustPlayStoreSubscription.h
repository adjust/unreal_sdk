//
//  AdjustPlayStoreSubscription.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 6th November 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustPlayStoreSubscription.generated.h"

USTRUCT(BlueprintType)
struct FAdjustPlayStoreSubscription
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int64 Price;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Sku;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString OrderId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Signature;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString PurchaseToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int64 PurchaseTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};

