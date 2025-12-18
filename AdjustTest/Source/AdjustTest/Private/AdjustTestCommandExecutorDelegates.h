//
//  AdjustTestCommandExecutorDelegates.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdjustDelegates.h"
#include "AdjustTestCommandExecutorDelegates.generated.h"

UCLASS()
class ADJUSTTEST_API UAdjustTestCommandExecutorDelegates : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void OnAdidReceived(const FString& Adid);

    UFUNCTION()
    void OnAttributionReceived(const FAdjustAttribution& Attribution);

    UFUNCTION()
    void OnLastDeeplinkReceived(const FString& LastDeeplink);

    UFUNCTION()
    void OnDeeplinkResolved(const FString& ResolvedLink);

    UFUNCTION()
    void OnSdkVersionReceived(const FString& SdkVersion);

    UFUNCTION()
    void OnPurchaseVerificationFinished(const FAdjustPurchaseVerificationResult& VerificationResult);

    UFUNCTION()
    void OnIdfaReceived(const FString& Idfa);

    UFUNCTION()
    void OnIdfvReceived(const FString& Idfv);

    UFUNCTION()
    void OnGoogleAdIdReceived(const FString& GoogleAdId);

    UFUNCTION()
    void OnAmazonAdIdReceived(const FString& AmazonAdId);

    UFUNCTION()
    void OnSkanConversionValueUpdated(const FAdjustSkanConversionDataMap& ConversionData);

    UFUNCTION()
    void OnAttributionChanged(const FAdjustAttribution& Attribution);

    UFUNCTION()
    void OnSessionSuccess(const FAdjustSessionSuccess& SessionSuccess);

    UFUNCTION()
    void OnSessionFailure(const FAdjustSessionFailure& SessionFailure);

    UFUNCTION()
    void OnEventSuccess(const FAdjustEventSuccess& EventSuccess);

    UFUNCTION()
    void OnEventFailure(const FAdjustEventFailure& EventFailure);

    UFUNCTION()
    void OnDeferredDeeplink(const FString& Deeplink);

    // callback data
    FString testCallbackId;
    FString localBasePath;
    FString localExtraPath;
    
    // flags to track which callbacks should be active for current test
    bool shouldSendAttributionCallback = false;
    bool shouldSendSessionSuccessCallback = false;
    bool shouldSendSessionFailureCallback = false;
    bool shouldSendEventSuccessCallback = false;
    bool shouldSendEventFailureCallback = false;
    bool shouldSendDeferredDeeplinkCallback = false;
    bool shouldSendSkanCallback = false;
};
