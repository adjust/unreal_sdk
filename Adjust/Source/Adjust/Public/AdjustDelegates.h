//
//  AdjustDelegates.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AdjustAttribution.h"
#include "AdjustSessionSuccess.h"
#include "AdjustSessionFailure.h"
#include "AdjustEventSuccess.h"
#include "AdjustEventFailure.h"
#include "AdjustDelegates.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedDelegate, const FAdjustAttribution&, Attribution);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionSuccessDelegate, const FAdjustSessionSuccess&, SessionSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionFailureDelegate, const FAdjustSessionFailure&, SessionFailure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSuccessDelegate, const FAdjustEventSuccess&, EventSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventFailureDelegate, const FAdjustEventFailure&, EventFailure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeferredDeeplinkDelegate, const FString&, Deeplink);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoogleAdvertisingIdDelegate, const FString&, GoogleAdId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusDelegate, const int, AuthorizationStatus);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAttributionChangedNonDynamicDelegate, const FAdjustAttribution&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSessionSuccessNonDynamicDelegate, const FAdjustSessionSuccess&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSessionFailureNonDynamicDelegate, const FAdjustSessionFailure&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEventSuccessNonDynamicDelegate, const FAdjustEventSuccess&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEventFailureNonDynamicDelegate, const FAdjustEventFailure&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnDeferredDeeplinkNonDynamicDelegate, const FString&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnGoogleAdvertisingIdNonDynamicDelegate, const FString&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusNonDynamicDelegate, const int);

UCLASS(ClassGroup = (Adjust), meta = (BlueprintSpawnableComponent))
class ADJUST_API UAdjustDelegates : public USceneComponent
{
	GENERATED_BODY()
	
public:
	UAdjustDelegates(const FObjectInitializer& ObjectInitializer);

    // dynamic delegates
	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnAttributionChangedDelegate OnAttributionChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnSessionSuccessDelegate OnSessionSuccessDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnSessionFailureDelegate OnSessionFailureDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnEventSuccessDelegate OnEventSuccessDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnEventFailureDelegate OnEventFailureDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnDeferredDeeplinkDelegate OnDeferredDeeplinkDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnGoogleAdvertisingIdDelegate OnGoogleAdvertisingIdDelegate;

	UPROPERTY(BlueprintAssignable, Category = Adjust)
	FOnAuthorizationStatusDelegate OnAuthorizationStatusDelegate;

    // non dynamic delegates
    FOnAttributionChangedNonDynamicDelegate OnAttributionChangedNonDynamicDelegate;

    FOnSessionSuccessNonDynamicDelegate OnSessionSuccessNonDynamicDelegate;

    FOnSessionFailureNonDynamicDelegate OnSessionFailureNonDynamicDelegate;

    FOnEventSuccessNonDynamicDelegate OnEventSuccessNonDynamicDelegate;

    FOnEventFailureNonDynamicDelegate OnEventFailureNonDynamicDelegate;

    FOnDeferredDeeplinkNonDynamicDelegate OnDeferredDeeplinkNonDynamicDelegate;

    FOnGoogleAdvertisingIdNonDynamicDelegate OnGoogleAdvertisingIdNonDynamicDelegate;

    FOnAuthorizationStatusNonDynamicDelegate OnAuthorizationStatusNonDynamicDelegate;
};
