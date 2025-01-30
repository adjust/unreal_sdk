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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Source;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    double Revenue = 0.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int AdImpressionsCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenueNetwork;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenueUnit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AdRevenuePlacement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};
