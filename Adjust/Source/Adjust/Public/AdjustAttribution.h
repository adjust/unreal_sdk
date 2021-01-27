//
//  AdjustAttribution.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustAttribution.generated.h"

USTRUCT(BlueprintType)
struct FAdjustAttribution
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TrackerToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TrackerName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Network;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Campaign;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Adgroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Creative;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString ClickLabel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Adid;
};
