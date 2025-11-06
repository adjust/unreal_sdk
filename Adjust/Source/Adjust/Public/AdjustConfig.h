//
//  AdjustConfig.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustStoreInfo.h"
#include "AdjustConfig.generated.h"

UENUM(BlueprintType)
enum class EAdjustEnvironment : uint8
{
    Sandbox = 0,
    Production = 1
};

UENUM(BlueprintType)
enum class EAdjustLogLevel : uint8
{
    Verbose = 0,
    Debug = 1,
    Info = 2,
    Warn = 3,
    Error = 4,
    Assert = 5,
    Suppress = 6
};

USTRUCT(BlueprintType)
struct FAdjustConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString AppToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    EAdjustEnvironment Environment = EAdjustEnvironment::Sandbox;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    EAdjustLogLevel LogLevel = EAdjustLogLevel::Verbose;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString DefaultTracker;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString ExternalDeviceId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsSendingInBackgroundEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsDeferredDeeplinkOpeningEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsCoppaComplianceEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsDeviceIdsReadingOnceEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsCostDataInAttributionEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsFirstSessionDelayEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FAdjustStoreInfo StoreInfo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int EventDeduplicationIdsMaxSize = -1;

    // ios only

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsIdfaReadingEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsIdfvReadingEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsLinkMeEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsSkanAttributionEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsAdServicesEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    int AttConsentWaitingInterval = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsAppTrackingTransparencyUsageEnabled = true;

    // android only

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    bool IsPlayStoreKidsComplianceEnabled = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString FbAppId;
};
