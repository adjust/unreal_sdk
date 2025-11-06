//
//  AdjustDelegates.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AdjustAttribution.h"
#include "AdjustSessionSuccess.h"
#include "AdjustSessionFailure.h"
#include "AdjustEventSuccess.h"
#include "AdjustEventFailure.h"
#include "AdjustPurchaseVerificationResult.h"
#include "AdjustDelegates.generated.h"

// subscription multiplatform delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedDelegate, const FAdjustAttribution&, Attribution);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionSuccessDelegate, const FAdjustSessionSuccess&, SessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionFailureDelegate, const FAdjustSessionFailure&, SessionFailure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSuccessDelegate, const FAdjustEventSuccess&, EventSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventFailureDelegate, const FAdjustEventFailure&, EventFailure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeferredDeeplinkDelegate, const FString&, Deeplink);
// subscription ios delegates

// one-time multiplatform delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsEnabledDelegate, const bool, IsEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAdidGetterDelegate, const FString&, Adid);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionGetterDelegate, const FAdjustAttribution&, Attribution);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLastDeeplinkGetterDelegate, const FString&, LastDeeplink);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeeplinkResolutionDelegate, const FString&, ResolvedLink);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSdkVersionGetterDelegate, const FString&, SdkVersion);
// one-time ios delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIdfaGetterDelegate, const FString&, Idfa);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIdfvGetterDelegate, const FString&, Idfv);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusGetterDelegate, const int, AuthorizationStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestTrackingAuthorizationDelegate, const int, AuthorizationStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateSkanConversionValueDelegate, const FString&, Error);
// one-time android delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoogleAdIdGetterDelegate, const FString&, GoogleAdId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmazonAdIdGetterDelegate, const FString&, AmazonAdId);
// purchase verification delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPurchaseVerificationFinishedDelegate, const FAdjustPurchaseVerificationResult&, VerificationResult);


UCLASS(Blueprintable)
class ADJUST_API UAdjustDelegates : public UObject
{
    GENERATED_BODY()
    
public:
    UAdjustDelegates();

    // subscription multiplatform delegates

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnAttributionChangedDelegate OnAttributionChangedDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnSessionSuccessDelegate OnSessionSuccessDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnSessionFailureDelegate OnSessionFailureDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnEventSuccessDelegate OnEventSuccessDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnEventFailureDelegate OnEventFailureDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnDeferredDeeplinkDelegate OnDeferredDeeplinkDelegate;

    // one-time multiplatform delegates

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnIsEnabledDelegate OnIsEnabledDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnAdidGetterDelegate OnAdidGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnAttributionGetterDelegate OnAttributionGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnLastDeeplinkGetterDelegate OnLastDeeplinkGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnDeeplinkResolutionDelegate OnDeeplinkResolutionDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnSdkVersionGetterDelegate OnSdkVersionGetterDelegate;

    // one-time ios delegates

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnIdfaGetterDelegate OnIdfaGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnIdfvGetterDelegate OnIdfvGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnAuthorizationStatusGetterDelegate OnAuthorizationStatusGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnRequestTrackingAuthorizationDelegate OnRequestTrackingAuthorizationDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnUpdateSkanConversionValueDelegate OnUpdateSkanConversionValueDelegate;

    // one-time android delegates

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnGoogleAdIdGetterDelegate OnGoogleAdIdGetterDelegate;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnAmazonAdIdGetterDelegate OnAmazonAdIdGetterDelegate;

    // purchase verification delegates

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = Adjust)
    FOnPurchaseVerificationFinishedDelegate OnPurchaseVerificationFinishedDelegate;
};
