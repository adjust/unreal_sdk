//
//  Adjust.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdjustEvent.h"
#include "AdjustConfig.h"
#include "AdjustAttribution.h"
#include "AdjustDeeplink.h"
#include "AdjustAdRevenue.h"
#include "AdjustThirdPartySharing.h"
#include "Adjust.generated.h"

UCLASS()
class ADJUST_API UAdjust : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void InitSdk(const FAdjustConfig& Config);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void Enable();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void Disable();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SwitchToOfflineMode();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SwitchBackToOnlineMode();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackEvent(const FAdjustEvent& Event);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackAdRevenue(const FAdjustAdRevenue& AdRevenue);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackThirdPartySharing(const FAdjustThirdPartySharing& ThirdPartySharing);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackMeasurementConsent(bool MeasurementConsent);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void ProcessDeeplink(const FAdjustDeeplink& Deeplink);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void ProcessAndResolveDeeplink(const FAdjustDeeplink& Deeplink);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SetPushToken(const FString& PushToken);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GdprForgetMe();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void AddGlobalCallbackParameter(const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void AddGlobalPartnerParameter(const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalCallbackParameter(const FString& Key);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalPartnerParameter(const FString& Key);

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalCallbackParameters();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalPartnerParameters();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void IsEnabled();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAdid();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAttribution();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetLastDeeplink();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetSdkVersion();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void EndFirstSessionDelay();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void EnableCoppaComplianceInDelay();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void DisableCoppaComplianceInDelay();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SetExternalDeviceIdInDelay(const FString& ExternalDeviceId);

    // ios only

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetIdfa();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetIdfv();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAppTrackingAuthorizationStatus();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RequestAppTrackingAuthorization();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void UpdateSkanConversionValue(int ConversionValue, const FString& CoarseValue, bool lockWindow);

    // android only

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetGoogleAdId();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAmazonAdId();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void EnablePlayStoreKidsComplianceInDelay();

    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void DisablePlayStoreKidsComplianceInDelay();
};
