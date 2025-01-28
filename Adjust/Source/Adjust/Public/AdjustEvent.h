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
    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString EventToken;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    float Revenue;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DeduplicationId;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString CallbackId;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    // tested [ios, android]
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;

    FAdjustEvent() : Revenue(0.0f) {}
};
