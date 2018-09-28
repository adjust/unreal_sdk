//
//  AdjustSessionFailure.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 28th September 2018.
//  Copyright © 2018 Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustSessionFailure.generated.h"

USTRUCT(BlueprintType)
struct FAdjustSessionFailure
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Message;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Timestamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Adid;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString JsonResponse;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool WillRetry;
};
