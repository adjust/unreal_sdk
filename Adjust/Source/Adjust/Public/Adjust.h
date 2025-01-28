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

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void InitSdk(const FAdjustConfig& Config);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void Enable();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void Disable();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SwitchToOfflineMode();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SwitchBackToOnlineMode();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackEvent(const FAdjustEvent& Event);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackAdRevenue(const FAdjustAdRevenue& AdRevenue);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackThirdPartySharing(const FAdjustThirdPartySharing& ThirdPartySharing);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void TrackMeasurementConsent(bool MeasurementConsent);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void ProcessDeeplink(const FAdjustDeeplink& Deeplink);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void ProcessAndResolveDeeplink(const FAdjustDeeplink& Deeplink);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void SetPushToken(const FString& PushToken);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GdprForgetMe();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void AddGlobalCallbackParameter(const FString& Key, const FString& Value);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void AddGlobalPartnerParameter(const FString& Key, const FString& Value);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalCallbackParameter(const FString& Key);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalPartnerParameter(const FString& Key);

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalCallbackParameters();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RemoveGlobalPartnerParameters();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAdid();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAttribution();

    // tested [ios, android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetSdkVersion();

    // ios only

    // tested [ios]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetIdfa();

    // tested [ios]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetIdfv();

    // tested [ios]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAppTrackingAuthorizationStatus();

    // tested [ios]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void RequestAppTrackingAuthorization();

    // tested [ios]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void UpdateSkanConversionValue(int ConversionValue, const FString& CoarseValue, bool lockWindow);

    // android only

    // tested [android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetGoogleAdId();

    // tested [android]
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static void GetAmazonAdId();
};
