//
//  AdjustAttribution.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustAttribution.generated.h"

USTRUCT(BlueprintType)
struct FAdjustAttribution
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString TrackerToken;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString TrackerName;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString Network;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString Campaign;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString Adgroup;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString Creative;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString ClickLabel;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString CostType;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    double CostAmount;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString CostCurrency;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString FbInstallReferrer;

    UPROPERTY(BlueprintReadOnly, Category = "Adjust")
    FString JsonResponse;
};
