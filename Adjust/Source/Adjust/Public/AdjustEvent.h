//
//  AdjustEvent.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustEvent.generated.h"

USTRUCT(BlueprintType)
struct FAdjustEvent
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString EventToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    double Revenue = 0.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DeduplicationId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString CallbackId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};
