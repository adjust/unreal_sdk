//
//  Adjust.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdjustEvent.h"
#include "AdjustConfig.h"
#include "AdjustAttribution.h"
#include "Adjust.generated.h"

UCLASS()
class ADJUST_API UAdjust : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void Initialize(const FAdjustConfig& Config);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void TrackEvent(const FAdjustEvent& Event);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void SetEnabled(bool Enable);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static bool IsEnabled();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void AppWillOpenUrl(const FString& Url);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void SetPushToken(const FString& PushToken);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void SetOfflineMode(bool Offline);

    // Android only
	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void GetGoogleAdId();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static FString GetAdid();

    // iOS only
	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static FString GetIdfa();

    // iOS only
    UFUNCTION(BlueprintCallable, Category = "Adjust")
    static int GetAppTrackingAuthorizationStatus();

    // Android (Fire OS) only
	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static FString GetAmazonAdId();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static FAdjustAttribution GetAttribution();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static FString GetSdkVersion();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void AddSessionCallbackParameter(const FString& Key, const FString& Value);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void AddSessionPartnerParameter(const FString& Key, const FString& Value);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void RemoveSessionCallbackParameter(const FString& Key);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void RemoveSessionPartnerParameter(const FString& Key);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void ResetSessionCallbackParameters();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void ResetSessionPartnerParameters();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void SendFirstPackages();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void GdprForgetMe();

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void TrackAdRevenue(const FString& Source, const FString& Payload);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void DisableThirdPartySharing();

    // iOS only
	UFUNCTION(BlueprintCallable, Category = "Adjust")
	static void RequestTrackingAuthorizationWithCompletionHandler();
};
