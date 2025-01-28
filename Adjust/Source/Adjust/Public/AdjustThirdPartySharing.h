//
//  AdjustThirdPartySharing.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 17th January 2025.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "AdjustThirdPartySharing.generated.h"

UENUM(BlueprintType)
enum class EAdjustThirdPartySharingState : uint8
{
    Enable = 0   UMETA(DisplayName = "Enable"),
    Disable = 1  UMETA(DisplayName = "Disable"),
    Current = 2  UMETA(DisplayName = "Current")
};

USTRUCT(BlueprintType)
struct FAdjustGranularOption
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> GranularOption;
};

USTRUCT(BlueprintType)
struct FAdjustPartnerSharingSetting
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, bool> PartnerSharingSetting;
};

USTRUCT(BlueprintType)
struct FAdjustThirdPartySharing
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    EAdjustThirdPartySharingState Sharing = EAdjustThirdPartySharingState::Current;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FAdjustGranularOption> GranularOptions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FAdjustPartnerSharingSetting> PartnerSharingSettings;
};