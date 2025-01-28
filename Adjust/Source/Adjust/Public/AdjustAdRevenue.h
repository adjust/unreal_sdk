//
//  AdjustAdRevenue.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 17th January 2025.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustAdRevenue.generated.h"

USTRUCT(BlueprintType)
struct FAdjustAdRevenue
{
    GENERATED_USTRUCT_BODY()

public:
    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Source;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    float Revenue = 0.0f;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int AdImpressionsCount = 0;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenueNetwork;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenueUnit;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenuePlacement;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};
