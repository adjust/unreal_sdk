//
//  AdjustDelegates.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2019 Adjust GmbH. All rights reserved.
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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuthorizationStatusDelegate, const FString&, AuthorizationStatus);

UCLASS(ClassGroup = (Adjust), meta = (BlueprintSpawnableComponent))
class ADJUST_API UAdjustDelegates : public USceneComponent
{
	GENERATED_BODY()
	
public:
	UAdjustDelegates(const FObjectInitializer& ObjectInitializer);

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
};
