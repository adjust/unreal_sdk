//
//  Adjust.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018 Adjust GmbH. All rights reserved.
//

#include "Adjust.h"
#include "AdjustDelegates.h"
#include "AdjustModule.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Modules/ModuleManager.h"

#if PLATFORM_IOS
#import "IOS/Native/Adjust.h"
#import "IOS/Delegate/AdjustSdkDelegate.h"
#elif PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include <android/log.h>
#endif

UAdjust::UAdjust(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

static void attributionCallbackMethod(FAdjustAttribution Attribution) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnAttributionChangedDelegate.Broadcast(Attribution);
        }
    }
}

static void sessionSuccessCallbackMethod(FAdjustSessionSuccess SessionSuccess) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnSessionSuccessDelegate.Broadcast(SessionSuccess);
        }
    }
}

static void sessionFailureCallbackMethod(FAdjustSessionFailure SessionFailure) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnSessionFailureDelegate.Broadcast(SessionFailure);
        }
    }
}

static void eventSuccessCallbackMethod(FAdjustEventSuccess EventSuccess) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnEventSuccessDelegate.Broadcast(EventSuccess);
        }
    }
}

static void eventFailureCallbackMethod(FAdjustEventFailure EventFailure) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnEventFailureDelegate.Broadcast(EventFailure);
        }
    }
}

static void deferredDeeplinkCallbackMethod(FString Deeplink) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnDeferredDeeplinkDelegate.Broadcast(Deeplink);
        }
    }
}

void UAdjust::Initialize(const FAdjustConfig& Config) {
#if PLATFORM_IOS
    // AppToken (FString).
    CFStringRef cfstrAppToken = FPlatformString::TCHARToCFString(*Config.AppToken);
    NSString *strAppToken = (NSString *)cfstrAppToken;

    // Environment (EAdjustEnvironment).
    EAdjustEnvironment eEnvironment = Config.Environment;
    NSString *environment;
    switch (eEnvironment) {
        case EAdjustEnvironment::Sandbox:
            environment = ADJEnvironmentSandbox;
            break;
        case (EAdjustEnvironment::Production):
            environment = ADJEnvironmentProduction;
            break;
    }

    ADJConfig *adjustConfig = [ADJConfig configWithAppToken:strAppToken environment:environment];
    if (![adjustConfig isValid]) {
        return;
    }

    // Delegate.
    AdjustSdkDelegate *delegate = [[AdjustSdkDelegate alloc] init];
    [delegate setAttributionCallback:attributionCallbackMethod];
    [delegate setSessionSuccessCallback:sessionSuccessCallbackMethod];
    [delegate setSessionFailureCallback:sessionFailureCallbackMethod];
    [delegate setEventSuccessCallback:eventSuccessCallbackMethod];
    [delegate setEventFailureCallback:eventFailureCallbackMethod];
    [delegate setShouldOpenDeferredDeeplink:Config.OpenDeferredDeeplink];
    adjustConfig.delegate = delegate;

    // SDK prefix.
    [adjustConfig setSdkPrefix:@"unreal4.15.0"];

    // LogLevel (EAdjustLogLevel)
    EAdjustLogLevel eLogLevel = Config.LogLevel;
    ADJLogLevel logLevel = ADJLogLevelInfo;
    switch (eLogLevel) {
        case EAdjustLogLevel::Verbose:
            logLevel = ADJLogLevelVerbose;
            break;
        case EAdjustLogLevel::Debug:
            logLevel = ADJLogLevelDebug;
            break;
        case EAdjustLogLevel::Info:
            logLevel = ADJLogLevelInfo;
            break;
        case EAdjustLogLevel::Warn:
            logLevel = ADJLogLevelWarn;
            break;
        case EAdjustLogLevel::Error:
            logLevel = ADJLogLevelError;
            break;
        case EAdjustLogLevel::Assert:
            logLevel = ADJLogLevelAssert;
            break;
        case EAdjustLogLevel::Suppress:
            logLevel = ADJLogLevelSuppress;
            break;
        default:
            logLevel = ADJLogLevelInfo;
            break;
    }
    [adjustConfig setLogLevel:logLevel];

    // UserAgent (FString).
    CFStringRef cfstrUserAgent = FPlatformString::TCHARToCFString(*Config.UserAgent);
    NSString *strUserAgent = (NSString *)cfstrUserAgent;
    if ([strUserAgent length] > 0) {
        [adjustConfig setUserAgent:strUserAgent];
    }

    // DefaultTracker (FString).
    CFStringRef cfstrDefaultTracker = FPlatformString::TCHARToCFString(*Config.DefaultTracker);
    NSString *strDefaultTracker = (NSString *)cfstrDefaultTracker;
    if ([strDefaultTracker length] > 0) {
        [adjustConfig setDefaultTracker:strDefaultTracker];
    }

    // DelayStart (FString).
    CFStringRef cfstrDelayStart = FPlatformString::TCHARToCFString(*Config.DelayStart);
    NSString *strDelayStart = (NSString *)cfstrDelayStart;
    if ([strDelayStart length] > 0) {
        [adjustConfig setDelayStart:[strDelayStart doubleValue]];
    }

    // SecretId (FString).
    // Info1 (FString).
    // Info2 (FString).
    // Info3 (FString).
    // Info4 (FString).
    CFStringRef cfstrSecretId = FPlatformString::TCHARToCFString(*Config.SecretId);
    CFStringRef cfstrInfo1 = FPlatformString::TCHARToCFString(*Config.Info1);
    CFStringRef cfstrInfo2 = FPlatformString::TCHARToCFString(*Config.Info2);
    CFStringRef cfstrInfo3 = FPlatformString::TCHARToCFString(*Config.Info3);
    CFStringRef cfstrInfo4 = FPlatformString::TCHARToCFString(*Config.Info4);
    NSString *strSecretId = (NSString *)cfstrSecretId;
    NSString *strInfo1 = (NSString *)cfstrInfo1;
    NSString *strInfo2 = (NSString *)cfstrInfo2;
    NSString *strInfo3 = (NSString *)cfstrInfo3;
    NSString *strInfo4 = (NSString *)cfstrInfo4;
    if ([strSecretId length] > 0
        && [strInfo1 length] > 0
        && [strInfo2 length] > 0
        && [strInfo3 length] > 0
        && [strInfo4 length] > 0) {
        [adjustConfig setAppSecret:[[NSNumber numberWithLongLong:[strSecretId longLongValue]] unsignedIntegerValue]
                              info1:[[NSNumber numberWithLongLong:[strInfo1 longLongValue]] unsignedIntegerValue]
                             info2:[[NSNumber numberWithLongLong:[strInfo2 longLongValue]] unsignedIntegerValue]
                             info3:[[NSNumber numberWithLongLong:[strInfo3 longLongValue]] unsignedIntegerValue]
                             info4:[[NSNumber numberWithLongLong:[strInfo4 longLongValue]] unsignedIntegerValue]];
    }

    // EventBuffering (bool).
    [adjustConfig setEventBufferingEnabled:Config.EventBuffering];

    // SendInBackground (bool).
    [adjustConfig setSendInBackground:Config.SendInBackground];

    // IsDeviceKnown (bool).
    [adjustConfig setIsDeviceKnown:Config.IsDeviceKnown];

    [Adjust appDidLaunch:adjustConfig];
#elif PLATFORM_ANDROID
    // return AndroidThunkCpp_GetDataString(fsFirst, fsSeconds);
#endif
}

void UAdjust::TrackEvent(const FAdjustEvent& Event) {
#if PLATFORM_IOS
    // EventToken (FString).
    CFStringRef cfstrEventToken = FPlatformString::TCHARToCFString(*Event.EventToken);
    NSString *strEventToken = (NSString *)cfstrEventToken;

    ADJEvent *adjustEvent = [ADJEvent eventWithEventToken:strEventToken];
    if (![adjustEvent isValid]) {
        return;
    }

    // Revenue (float).
    CFStringRef cfstrCurrency = FPlatformString::TCHARToCFString(*Event.Currency);
    NSString *strCurrency = (NSString *)cfstrCurrency;
    [adjustEvent setRevenue:(double)Event.Revenue currency:strCurrency];

    // CallbackParameters (TMap<FString, FString>).
    TMap<FString, FString> callbackParams = Event.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams) {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addCallbackParameter:strKey value:strValue];
    }

    // PartnerParameters (TMap<FString, FString>).
    TMap<FString, FString> partnerParams = Event.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams) {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addPartnerParameter:strKey value:strValue];
    }

    // TransactionId (FString).
    CFStringRef cfstrTransactionId = FPlatformString::TCHARToCFString(*Event.TransactionId);
    NSString *strTransactionId = (NSString *)cfstrTransactionId;
    [adjustEvent setTransactionId:strTransactionId];

    // CallbackId (FString).
    CFStringRef cfstrCallbackId = FPlatformString::TCHARToCFString(*Event.CallbackId);
    NSString *strCallbackId = (NSString *)cfstrCallbackId;
    [adjustEvent setCallbackId:strCallbackId];

    // Track event
    [Adjust trackEvent:adjustEvent];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::SetEnabled(bool Enable) {
#if PLATFORM_IOS
    [Adjust setEnabled:Enable];
#elif PLATFORM_ANDROID

#endif
}

bool UAdjust::IsEnabled() {
#if PLATFORM_IOS
    return [Adjust isEnabled];
#elif PLATFORM_ANDROID

#endif
    return false;
}

void UAdjust::AppWillOpenUrl(const FString& Url) {
#if PLATFORM_IOS
    NSURL *url;
    CFStringRef cfstrUrl = FPlatformString::TCHARToCFString(*Url);
    NSString *strUrl = (NSString *)cfstrUrl;
    if ([NSString instancesRespondToSelector:@selector(stringByAddingPercentEncodingWithAllowedCharacters:)]) {
        url = [NSURL URLWithString:[strUrl stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLFragmentAllowedCharacterSet]]];
    } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        url = [NSURL URLWithString:[strUrl stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    }
#pragma clang diagnostic pop

    [Adjust appWillOpenUrl:url];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::SetPushToken(const FString& PushToken) {
#if PLATFORM_IOS
    CFStringRef cfstrPushToken = FPlatformString::TCHARToCFString(*PushToken);
    NSString *strPushToken = (NSString *)cfstrPushToken;
    [Adjust setPushToken:strPushToken];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::SetOfflineMode(bool Offline) {
#if PLATFORM_IOS
    [Adjust setOfflineMode:Offline];
#elif PLATFORM_ANDROID

#endif
}

FString UAdjust::GetAdid() {
#if PLATFORM_IOS
    FString adid = *FString([Adjust adid]);
    return adid;
#elif PLATFORM_ANDROID

#endif
    return *(new FString());
}

FString UAdjust::GetIdfa() {
#if PLATFORM_IOS
    FString idfa = *FString([Adjust idfa]);
    return idfa;
#elif PLATFORM_ANDROID

#endif
    return *(new FString());
}

FString UAdjust::GetGoogleAdId() {
#if PLATFORM_IOS
    return *(new FString());
#elif PLATFORM_ANDROID

#endif
    return *(new FString());
}

FString UAdjust::GetAmazonAdId() {
#if PLATFORM_IOS
    return *(new FString());
#elif PLATFORM_ANDROID

#endif
    return *(new FString());
}

FAdjustAttribution UAdjust::GetAttribution() {
#if PLATFORM_IOS
    ADJAttribution *attribution = [Adjust attribution];
    if (attribution == nil) {
        FAdjustAttribution ueAttribution;
        return ueAttribution;
    }

    FAdjustAttribution ueAttribution;
    ueAttribution.TrackerToken = *FString(attribution.trackerToken);
    ueAttribution.TrackerName = *FString(attribution.trackerName);
    ueAttribution.Network = *FString(attribution.network);
    ueAttribution.Campaign = *FString(attribution.campaign);
    ueAttribution.Adgroup = *FString(attribution.adgroup);
    ueAttribution.Creative = *FString(attribution.creative);
    ueAttribution.ClickLabel = *FString(attribution.clickLabel);
    ueAttribution.Adid = *FString(attribution.adid);
    return ueAttribution;
#elif PLATFORM_ANDROID

#else
    FAdjustAttribution ueAttribution;
    return ueAttribution;
#endif
}

void UAdjust::AddSessionCallbackParameter(const FString& Key, const FString& Value) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*Value);
    NSString *strValue = (NSString *)cfstrValue;
    [Adjust addSessionCallbackParameter:strKey value:strValue];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::AddSessionPartnerParameter(const FString& Key, const FString& Value) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*Value);
    NSString *strValue = (NSString *)cfstrValue;
    [Adjust addSessionPartnerParameter:strKey value:strValue];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::RemoveSessionCallbackParameter(const FString& Key) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeSessionCallbackParameter:strKey];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::RemoveSessionPartnerParameter(const FString& Key) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeSessionPartnerParameter:strKey];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::ResetSessionCallbackParameters() {
#if PLATFORM_IOS
    [Adjust resetSessionCallbackParameters];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::ResetPartnerCallbackParameters() {
#if PLATFORM_IOS
    [Adjust resetSessionPartnerParameters];
#elif PLATFORM_ANDROID

#endif
}

void UAdjust::GdprForgetMe() {
#if PLATFORM_IOS
    [Adjust gdprForgetMe];
#elif PLATFORM_ANDROID

#endif
}
