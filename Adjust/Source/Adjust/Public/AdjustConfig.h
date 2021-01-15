//
//  AdjustConfig.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2019 Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustConfig.generated.h"

UENUM(Blueprintable)
enum class EAdjustEnvironment : uint8
{
	Zero = 0,
    Sandbox = 1,
    Production = 2
};

UENUM(Blueprintable)
enum class EAdjustLogLevel : uint8
{
	Zero = 0,
    Verbose = 1,
    Debug = 2,
    Info = 3,
    Warn = 4,
    Error = 5,
    Assert = 6,
    Suppress = 7
};

USTRUCT(Blueprintable, BlueprintType)
struct FAdjustConfig
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AppToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    EAdjustEnvironment Environment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    EAdjustLogLevel LogLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString UserAgent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DefaultTracker;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DelayStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString SecretId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Info1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Info2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Info3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Info4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool EventBuffering = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool SendInBackground = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsDeviceKnown = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool OpenDeferredDeeplink = true;
};
