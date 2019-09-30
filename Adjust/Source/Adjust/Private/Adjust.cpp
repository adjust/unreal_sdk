//
//  Adjust.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2019 Adjust GmbH. All rights reserved.
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
#include "Android/AdjustJNI.h"
#endif

UAdjust::UAdjust(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

static void adjustAttributionCallback(FAdjustAttribution Attribution) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnAttributionChangedDelegate.Broadcast(Attribution);
        }
    }
}

static void adjustSessionSuccessCallback(FAdjustSessionSuccess SessionSuccess) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnSessionSuccessDelegate.Broadcast(SessionSuccess);
        }
    }
}

static void adjustSessionFailureCallback(FAdjustSessionFailure SessionFailure) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnSessionFailureDelegate.Broadcast(SessionFailure);
        }
    }
}

static void adjustEventSuccessCallback(FAdjustEventSuccess EventSuccess) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnEventSuccessDelegate.Broadcast(EventSuccess);
        }
    }
}

static void adjustEventFailureCallback(FAdjustEventFailure EventFailure) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnEventFailureDelegate.Broadcast(EventFailure);
        }
    }
}

static void adjustDeferredDeeplinkCallback(FString Deeplink) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnDeferredDeeplinkDelegate.Broadcast(Deeplink);
        }
    }
}

static void adjustGoogleAdvertisingIdCallback(FString GoogleAdId) {
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr) {
        if (Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill())) {
            Itr->OnGoogleAdvertisingIdDelegate.Broadcast(GoogleAdId);
        }
    }
}

void UAdjust::Initialize(const FAdjustConfig& Config) {
#if PLATFORM_IOS
    // App token.
    CFStringRef cfstrAppToken = FPlatformString::TCHARToCFString(*Config.AppToken);
    NSString *strAppToken = (NSString *)cfstrAppToken;

    // Environment.
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

    // Log level.
    EAdjustLogLevel eLogLevel = Config.LogLevel;
    ADJLogLevel logLevel = ADJLogLevelInfo;
    bool allowSuppressLevel = false;
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
            allowSuppressLevel = true;
            break;
        default:
            logLevel = ADJLogLevelInfo;
            break;
    }

    ADJConfig *adjustConfig = [ADJConfig configWithAppToken:strAppToken environment:environment allowSuppressLogLevel:allowSuppressLevel];
    if (![adjustConfig isValid]) {
        return;
    }

    // SDK prefix.
    [adjustConfig setSdkPrefix:@"unreal4.17.1"];

    // Log level.
    [adjustConfig setLogLevel:logLevel];

    // Adjust Delegate.
    AdjustSdkDelegate *delegate = [[AdjustSdkDelegate alloc] init];
    [delegate setAttributionCallback:adjustAttributionCallback];
    [delegate setSessionSuccessCallback:adjustSessionSuccessCallback];
    [delegate setSessionFailureCallback:adjustSessionFailureCallback];
    [delegate setEventSuccessCallback:adjustEventSuccessCallback];
    [delegate setEventFailureCallback:adjustEventFailureCallback];
    [delegate setShouldOpenDeferredDeeplink:Config.OpenDeferredDeeplink];
    adjustConfig.delegate = delegate;

    // User agent.
    CFStringRef cfstrUserAgent = FPlatformString::TCHARToCFString(*Config.UserAgent);
    NSString *strUserAgent = (NSString *)cfstrUserAgent;
    if ([strUserAgent length] > 0) {
        [adjustConfig setUserAgent:strUserAgent];
    }

    // Default tracker.
    CFStringRef cfstrDefaultTracker = FPlatformString::TCHARToCFString(*Config.DefaultTracker);
    NSString *strDefaultTracker = (NSString *)cfstrDefaultTracker;
    if ([strDefaultTracker length] > 0) {
        [adjustConfig setDefaultTracker:strDefaultTracker];
    }

    // Delay start.
    CFStringRef cfstrDelayStart = FPlatformString::TCHARToCFString(*Config.DelayStart);
    NSString *strDelayStart = (NSString *)cfstrDelayStart;
    if ([strDelayStart length] > 0) {
        [adjustConfig setDelayStart:[strDelayStart doubleValue]];
    }

    // App secret.
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

    // Event buffering.
    [adjustConfig setEventBufferingEnabled:Config.EventBuffering];

    // Send in background.
    [adjustConfig setSendInBackground:Config.SendInBackground];

    // Is device known.
    [adjustConfig setIsDeviceKnown:Config.IsDeviceKnown];

    // Start SDK.
    [Adjust appDidLaunch:adjustConfig];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // App token.
    jstring jAppToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.AppToken));

    // Environment.
    jstring jEnvironment;
    EAdjustEnvironment eEnvironment = Config.Environment;
    switch (eEnvironment) {
        case EAdjustEnvironment::Sandbox:
            jEnvironment = Env->NewStringUTF("sandbox");
            break;
        case (EAdjustEnvironment::Production):
            jEnvironment = Env->NewStringUTF("production");
            break;
    }

    // Log level.
    const char* cLogLevel;
    bool allowSuppressLevel = false;
    EAdjustLogLevel eLogLevel = Config.LogLevel;
    switch (eLogLevel) {
        case EAdjustLogLevel::Verbose:
            cLogLevel = "VERBOSE";
            break;
        case EAdjustLogLevel::Debug:
            cLogLevel = "DEBUG";
            break;
        case EAdjustLogLevel::Info:
            cLogLevel = "INFO";
            break;
        case EAdjustLogLevel::Warn:
            cLogLevel = "WARN";
            break;
        case EAdjustLogLevel::Error:
            cLogLevel = "ERROR";
            break;
        case EAdjustLogLevel::Assert:
            cLogLevel = "ASSERT";
            break;
        case EAdjustLogLevel::Suppress:
            cLogLevel = "SUPRESS";
            allowSuppressLevel = true;
            break;
        default:
            cLogLevel = "INFO";
            break;
    }

    // Create config object.
    jclass jcslAdjustConfig = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustConfig");
    jmethodID jmidAdjustConfigInit = Env->GetMethodID(jcslAdjustConfig, "<init>", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Z)V");
    jobject joAdjustConfig = Env->NewObject(jcslAdjustConfig, jmidAdjustConfigInit, FJavaWrapper::GameActivityThis, jAppToken, jEnvironment, allowSuppressLevel);
    Env->DeleteLocalRef(jAppToken);
    Env->DeleteLocalRef(jEnvironment);

    // SDK prefix.
    const char* cstrSdkPrefix = "unreal4.17.1";
    jstring jSdkPrefix = Env->NewStringUTF(cstrSdkPrefix);
    jmethodID jmidAdjustConfigSetSdkPrefix = Env->GetMethodID(jcslAdjustConfig, "setSdkPrefix", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSdkPrefix, jSdkPrefix);
    Env->DeleteLocalRef(jSdkPrefix);

    // Log level.
    jclass jclsLogLevel = FAndroidApplication::FindJavaClass("com/adjust/sdk/LogLevel");
    jfieldID jfidValue = Env->GetStaticFieldID(jclsLogLevel, cLogLevel, "Lcom/adjust/sdk/LogLevel;");
    jobject joLogLevel = Env->GetStaticObjectField(jclsLogLevel, jfidValue);
    jmethodID jmidAdjustConfigSetLogLevel = Env->GetMethodID(jcslAdjustConfig, "setLogLevel", "(Lcom/adjust/sdk/LogLevel;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetLogLevel, joLogLevel);
    Env->DeleteLocalRef(joLogLevel);

    // Attribution callback.
    setAttributionCallbackMethod(adjustAttributionCallback);
    jclass jcslUeAttributionCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeAttributionCallback");
    jmethodID jmidAdjustConfigSetAttributionCallback = Env->GetMethodID(jcslAdjustConfig, "setOnAttributionChangedListener", "(Lcom/adjust/sdk/OnAttributionChangedListener;)V");
    jmethodID jmidUeAttributionCallbackInit = Env->GetMethodID(jcslUeAttributionCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joAttributionCallbackProxy = Env->NewObject(jcslUeAttributionCallback, jmidUeAttributionCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetAttributionCallback, joAttributionCallbackProxy);
    Env->DeleteLocalRef(joAttributionCallbackProxy);

    // Session success callback.
    setSessionSuccessCallbackMethod(adjustSessionSuccessCallback);
    jclass jcslUeSessionSuccessCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeSessionSuccessCallback");
    jmethodID jmidAdjustConfigSetSessionSuccessCallback = Env->GetMethodID(jcslAdjustConfig, "setOnSessionTrackingSucceededListener", "(Lcom/adjust/sdk/OnSessionTrackingSucceededListener;)V");
    jmethodID jmidUeSessionSuccessCallbackInit = Env->GetMethodID(jcslUeSessionSuccessCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joSessionSuccessCallbackProxy = Env->NewObject(jcslUeSessionSuccessCallback, jmidUeSessionSuccessCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSessionSuccessCallback, joSessionSuccessCallbackProxy);
    Env->DeleteLocalRef(joSessionSuccessCallbackProxy);

    // Session failure callback.
    setSessionFailureCallbackMethod(adjustSessionFailureCallback);
    jclass jcslUeSessionFailureCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeSessionFailureCallback");
    jmethodID jmidAdjustConfigSetSessionFailureCallback = Env->GetMethodID(jcslAdjustConfig, "setOnSessionTrackingFailedListener", "(Lcom/adjust/sdk/OnSessionTrackingFailedListener;)V");
    jmethodID jmidUeSessionFailureCallbackInit = Env->GetMethodID(jcslUeSessionFailureCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joSessionFailureCallbackProxy = Env->NewObject(jcslUeSessionFailureCallback, jmidUeSessionFailureCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSessionFailureCallback, joSessionFailureCallbackProxy);
    Env->DeleteLocalRef(joSessionFailureCallbackProxy);

    // Event success callback.
    setEventSuccessCallbackMethod(adjustEventSuccessCallback);
    jclass jcslUeEventSuccessCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeEventSuccessCallback");
    jmethodID jmidAdjustConfigSetEventSuccessCallback = Env->GetMethodID(jcslAdjustConfig, "setOnEventTrackingSucceededListener", "(Lcom/adjust/sdk/OnEventTrackingSucceededListener;)V");
    jmethodID jmidUeEventSuccessCallbackInit = Env->GetMethodID(jcslUeEventSuccessCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joEventSuccessCallbackProxy = Env->NewObject(jcslUeEventSuccessCallback, jmidUeEventSuccessCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventSuccessCallback, joEventSuccessCallbackProxy);
    Env->DeleteLocalRef(joEventSuccessCallbackProxy);

    // Event failure callback.
    setEventFailureCallbackMethod(adjustEventFailureCallback);
    jclass jcslUeEventFailureCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeEventFailureCallback");
    jmethodID jmidAdjustConfigSetEventFailureCallback = Env->GetMethodID(jcslAdjustConfig, "setOnEventTrackingFailedListener", "(Lcom/adjust/sdk/OnEventTrackingFailedListener;)V");
    jmethodID jmidUeEventFailureCallbackInit = Env->GetMethodID(jcslUeEventFailureCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joEventFailureCallbackProxy = Env->NewObject(jcslUeEventFailureCallback, jmidUeEventFailureCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventFailureCallback, joEventFailureCallbackProxy);
    Env->DeleteLocalRef(joEventFailureCallbackProxy);

    // Deferred deep link callback.
    setDeferredDeeplinkCallbackMethod(adjustDeferredDeeplinkCallback);
    jclass jcslUeDeferredDeeplinkCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeDeferredDeeplinkCallback");
    jmethodID jmidAdjustConfigSetDeferredDeeplinkCallback = Env->GetMethodID(jcslAdjustConfig, "setOnDeeplinkResponseListener", "(Lcom/adjust/sdk/OnDeeplinkResponseListener;)V");
    jmethodID jmidUeDeferredDeeplinkCallbackInit = Env->GetMethodID(jcslUeDeferredDeeplinkCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Z)V");
    jobject joDeferredDeeplinkCallbackProxy = Env->NewObject(jcslUeDeferredDeeplinkCallback, jmidUeDeferredDeeplinkCallbackInit, FJavaWrapper::GameActivityThis, Config.OpenDeferredDeeplink);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetDeferredDeeplinkCallback, joDeferredDeeplinkCallbackProxy);
    Env->DeleteLocalRef(joDeferredDeeplinkCallbackProxy);

    // User agent.
    jstring jUserAgent = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.UserAgent));
    jmethodID jmidAdjustConfigSetUserAgent = Env->GetMethodID(jcslAdjustConfig, "setUserAgent", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetUserAgent, jUserAgent);
    Env->DeleteLocalRef(jUserAgent);

    // Default tracker.
    jstring jDefaultTracker = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.DefaultTracker));
    jmethodID jmidAdjustConfigSetDefaultTracker = Env->GetMethodID(jcslAdjustConfig, "setDefaultTracker", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetDefaultTracker, jDefaultTracker);
    Env->DeleteLocalRef(jDefaultTracker);

    // Delay start.
    float fDelayStart = FCString::Atof(*Config.DelayStart);
    jmethodID jmidAdjustConfigSetDelayStart = Env->GetMethodID(jcslAdjustConfig, "setDelayStart", "(D)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetDelayStart, (double)fDelayStart);

    // App secret.
    uint64 secretId = FCString::Strtoui64(*Config.SecretId, NULL, 10);
    uint64 info1 = FCString::Strtoui64(*Config.Info1, NULL, 10);
    uint64 info2 = FCString::Strtoui64(*Config.Info2, NULL, 10);
    uint64 info3 = FCString::Strtoui64(*Config.Info3, NULL, 10);
    uint64 info4 = FCString::Strtoui64(*Config.Info4, NULL, 10);
    if (secretId > 0 && info1 > 0 && info2 > 0 && info3 > 0 && info4 > 0) {
        jmethodID jmidAdjustConfigSetAppSecret = Env->GetMethodID(jcslAdjustConfig, "setAppSecret", "(JJJJJ)V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetAppSecret, secretId, info1, info2, info3, info4);
    }

    // Event buffering.
    jmethodID jmidAdjustConfigSetEventBufferingEnabled = Env->GetMethodID(jcslAdjustConfig, "setEventBufferingEnabled", "(Ljava/lang/Boolean;)V");
    jclass jclsBoolean = Env->FindClass("java/lang/Boolean");
    jmethodID jmidValueOf = Env->GetStaticMethodID(jclsBoolean, "valueOf", "(Z)Ljava/lang/Boolean;");
    jobject joIsEnabled = Env->CallStaticObjectMethod(jclsBoolean, jmidValueOf, Config.EventBuffering);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventBufferingEnabled, joIsEnabled);
    Env->DeleteLocalRef(joIsEnabled);

    // Send in background.
    jmethodID jmidAdjustConfigSetSendInBackground = Env->GetMethodID(jcslAdjustConfig, "setSendInBackground", "(Z)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSendInBackground, Config.SendInBackground);

    // Is device known.
    jmethodID jmidAdjustConfigSetIsDeviceKnown = Env->GetMethodID(jcslAdjustConfig, "setDeviceKnown", "(Z)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetIsDeviceKnown, Config.IsDeviceKnown);

    // Start SDK.
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustOnCreate = Env->GetStaticMethodID(jcslAdjust, "onCreate", "(Lcom/adjust/sdk/AdjustConfig;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustOnCreate, joAdjustConfig);
    jmethodID jmidAdjustOnResume = Env->GetStaticMethodID(jcslAdjust, "onResume", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustOnResume);
    Env->DeleteLocalRef(joAdjustConfig);
#endif
}

void UAdjust::TrackEvent(const FAdjustEvent& Event) {
#if PLATFORM_IOS
    // Event token.
    CFStringRef cfstrEventToken = FPlatformString::TCHARToCFString(*Event.EventToken);
    NSString *strEventToken = (NSString *)cfstrEventToken;

    ADJEvent *adjustEvent = [ADJEvent eventWithEventToken:strEventToken];
    if (![adjustEvent isValid]) {
        return;
    }

    // Revenue.
    CFStringRef cfstrCurrency = FPlatformString::TCHARToCFString(*Event.Currency);
    NSString *strCurrency = (NSString *)cfstrCurrency;
    [adjustEvent setRevenue:(double)Event.Revenue currency:strCurrency];

    // Callback parameters.
    TMap<FString, FString> callbackParams = Event.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams) {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addCallbackParameter:strKey value:strValue];
    }

    // Partner parameters.
    TMap<FString, FString> partnerParams = Event.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams) {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addPartnerParameter:strKey value:strValue];
    }

    // Transaction ID.
    CFStringRef cfstrTransactionId = FPlatformString::TCHARToCFString(*Event.TransactionId);
    NSString *strTransactionId = (NSString *)cfstrTransactionId;
    [adjustEvent setTransactionId:strTransactionId];

    // Callback ID.
    CFStringRef cfstrCallbackId = FPlatformString::TCHARToCFString(*Event.CallbackId);
    NSString *strCallbackId = (NSString *)cfstrCallbackId;
    [adjustEvent setCallbackId:strCallbackId];

    // Track event.
    [Adjust trackEvent:adjustEvent];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // Event token.
    jstring jEventToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.EventToken));

    // Create Event object.
    jclass jcslAdjustEvent = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustEvent");
    jmethodID jmidAdjustEventInit = Env->GetMethodID(jcslAdjustEvent, "<init>", "(Ljava/lang/String;)V");
    jobject joAdjustEvent = Env->NewObject(jcslAdjustEvent, jmidAdjustEventInit, jEventToken);
    Env->DeleteLocalRef(jEventToken);

    // Revenue.
    jstring jCurrency = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.Currency));
    jmethodID jmidAdjustEventSetRevenue = Env->GetMethodID(jcslAdjustEvent, "setRevenue", "(DLjava/lang/String;)V");
    Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetRevenue, (double)Event.Revenue, jCurrency);
    Env->DeleteLocalRef(jCurrency);

    // Callback parameters.
    jmethodID jmidAdjustEventAddCallbackParameter = Env->GetMethodID(jcslAdjustEvent, "addCallbackParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> callbackParams = Event.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams) {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventAddCallbackParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // Partner parameters.
    jmethodID jmidAdjustEventAddPartnerParameter = Env->GetMethodID(jcslAdjustEvent, "addPartnerParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> partnerParams = Event.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams) {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventAddPartnerParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // Order ID.
    jstring jTransactionId = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.TransactionId));
    jmethodID jmidAdjustEventSetOrderId = Env->GetMethodID(jcslAdjustEvent, "setOrderId", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetOrderId, jTransactionId);
    Env->DeleteLocalRef(jTransactionId);

    // Callback ID.
    jstring jCallbackId = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.CallbackId));
    jmethodID jmidAdjustEventSetCallbackId = Env->GetMethodID(jcslAdjustEvent, "setCallbackId", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetCallbackId, jCallbackId);
    Env->DeleteLocalRef(jCallbackId);

    // Track event.
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackEvent = Env->GetStaticMethodID(jcslAdjust, "trackEvent", "(Lcom/adjust/sdk/AdjustEvent;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackEvent, joAdjustEvent);
    Env->DeleteLocalRef(joAdjustEvent);
#endif
}

void UAdjust::SetEnabled(bool Enable) {
#if PLATFORM_IOS
    [Adjust setEnabled:Enable];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSetEnabled = Env->GetStaticMethodID(jcslAdjust, "setEnabled", "(Z)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSetEnabled, Enable);
#endif
}

bool UAdjust::IsEnabled() {
#if PLATFORM_IOS
    return [Adjust isEnabled];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustIsEnabled = Env->GetStaticMethodID(jcslAdjust, "isEnabled", "()Z");
    jboolean jIsEnabled = Env->CallStaticBooleanMethod(jcslAdjust, jmidAdjustIsEnabled);
    return jIsEnabled;
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
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslUri = Env->FindClass("android/net/Uri");
    jmethodID jmidUriParse = Env->GetStaticMethodID(jcslUri, "parse", "(Ljava/lang/String;)Landroid/net/Uri;");
    jstring jUrl = Env->NewStringUTF(TCHAR_TO_UTF8(*Url));
    jobject joUri = Env->CallStaticObjectMethod(jcslUri, jmidUriParse, jUrl);

    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustAppWillOpenUrl = Env->GetStaticMethodID(jcslAdjust, "appWillOpenUrl", "(Landroid/net/Uri;Landroid/content/Context;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustAppWillOpenUrl, joUri, FJavaWrapper::GameActivityThis);
    Env->DeleteLocalRef(jUrl);
    Env->DeleteLocalRef(joUri);
#endif
}

void UAdjust::SetPushToken(const FString& PushToken) {
#if PLATFORM_IOS
    CFStringRef cfstrPushToken = FPlatformString::TCHARToCFString(*PushToken);
    NSString *strPushToken = (NSString *)cfstrPushToken;
    [Adjust setPushToken:strPushToken];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSetPushToken = Env->GetStaticMethodID(jcslAdjust, "setPushToken", "(Ljava/lang/String;Landroid/content/Context;)V");
    jstring jPushToken = Env->NewStringUTF(TCHAR_TO_UTF8(*PushToken));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSetPushToken, jPushToken, FJavaWrapper::GameActivityThis);
    Env->DeleteLocalRef(jPushToken);
#endif
}

void UAdjust::SetOfflineMode(bool Offline) {
#if PLATFORM_IOS
    [Adjust setOfflineMode:Offline];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSetOfflineMode = Env->GetStaticMethodID(jcslAdjust, "setOfflineMode", "(Z)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSetOfflineMode, Offline);
#endif
}

FString UAdjust::GetAdid() {
#if PLATFORM_IOS
    FString adid = *FString([Adjust adid]);
    return adid;
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAdid = Env->GetStaticMethodID(jcslAdjust, "getAdid", "()Ljava/lang/String;");
    jstring jAdid = (jstring)Env->CallStaticObjectMethod(jcslAdjust, jmidAdjustGetAdid);

    FString Adid = FString(UTF8_TO_TCHAR(""));
    if (NULL != jAdid) {
        const char* adidCStr = Env->GetStringUTFChars(jAdid, NULL);
        Adid = FString(UTF8_TO_TCHAR(adidCStr));
        Env->ReleaseStringUTFChars(jAdid, adidCStr);
    }

    Env->DeleteLocalRef(jAdid);
    return Adid;
#else
    FString Adid = FString(UTF8_TO_TCHAR(""));
    return Adid;
#endif
}

FString UAdjust::GetIdfa() {
#if PLATFORM_IOS
    FString Idfa = *FString([Adjust idfa]);
    return Idfa;
#else
    FString Idfa = FString(UTF8_TO_TCHAR(""));
    return Idfa;
#endif
}

void UAdjust::GetGoogleAdId() {
#if PLATFORM_ANDROID
    setGoogleAdvertisingIdCallbackMethod(adjustGoogleAdvertisingIdCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetGoogleAdvertisingId = Env->GetStaticMethodID(jcslAdjust, "getGoogleAdId", "(Landroid/content/Context;Lcom/adjust/sdk/OnDeviceIdsRead;)V");
    jclass jcslUeGoogleAdvertisingIdCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$AdjustUeGoogleAdvertisingIdCallback");
    jmethodID jmidUeGoogleAdvertisingIdCallbackInit = Env->GetMethodID(jcslUeGoogleAdvertisingIdCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joGoogleAdvertisingIdCallbackProxy = Env->NewObject(jcslUeGoogleAdvertisingIdCallback, jmidUeGoogleAdvertisingIdCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetGoogleAdvertisingId, FJavaWrapper::GameActivityThis, joGoogleAdvertisingIdCallbackProxy);
    Env->DeleteLocalRef(joGoogleAdvertisingIdCallbackProxy);
#endif
}

FString UAdjust::GetAmazonAdId() {
#if PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAmazonAdId = Env->GetStaticMethodID(jcslAdjust, "getAmazonAdId", "(Landroid/content/Context;)Ljava/lang/String;");
    jstring jAmazonAdId = (jstring)Env->CallStaticObjectMethod(jcslAdjust, jmidAdjustGetAmazonAdId, FJavaWrapper::GameActivityThis);

    FString AmazonAdId = FString(UTF8_TO_TCHAR(""));
    if (NULL != jAmazonAdId) {
        const char* amazonAdIdCStr = Env->GetStringUTFChars(jAmazonAdId, NULL);
        AmazonAdId = FString(UTF8_TO_TCHAR(amazonAdIdCStr));
        Env->ReleaseStringUTFChars(jAmazonAdId, amazonAdIdCStr);
    }

    Env->DeleteLocalRef(jAmazonAdId);
    return AmazonAdId;
#else
    FString AmazonAdId = FString(UTF8_TO_TCHAR(""));
    return AmazonAdId;
#endif
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
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAttribution = Env->GetStaticMethodID(jcslAdjust, "getAttribution", "()Lcom/adjust/sdk/AdjustAttribution;");
    jobject joAttribution = Env->CallStaticObjectMethod(jcslAdjust, jmidAdjustGetAttribution);
    if (Env->IsSameObject(joAttribution, NULL)) {
        FAdjustAttribution ueAttribution;
        return ueAttribution;
    }

    FString trackerToken;
    FString trackerName;
    FString network;
    FString campaign;
    FString adgroup;
    FString creative;
    FString clickLabel;
    FString adid;

    jclass clsAdjustAttribution = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustAttribution");
    jfieldID fTrackerTokenID = Env->GetFieldID(clsAdjustAttribution, "trackerToken", "Ljava/lang/String;");
    jfieldID fTrackerNameID = Env->GetFieldID(clsAdjustAttribution, "trackerName", "Ljava/lang/String;");
    jfieldID fNetworkID = Env->GetFieldID(clsAdjustAttribution, "network", "Ljava/lang/String;");
    jfieldID fCampaignID = Env->GetFieldID(clsAdjustAttribution, "campaign", "Ljava/lang/String;");
    jfieldID fAdgroupID = Env->GetFieldID(clsAdjustAttribution, "adgroup", "Ljava/lang/String;");
    jfieldID fCreativeID = Env->GetFieldID(clsAdjustAttribution, "creative", "Ljava/lang/String;");
    jfieldID fClickLabelID = Env->GetFieldID(clsAdjustAttribution, "clickLabel", "Ljava/lang/String;");
    jfieldID fAdidID = Env->GetFieldID(clsAdjustAttribution, "adid", "Ljava/lang/String;");
    jstring jTrackerToken = (jstring)Env->GetObjectField(joAttribution, fTrackerTokenID);
    jstring jTrackerName = (jstring)Env->GetObjectField(joAttribution, fTrackerNameID);
    jstring jNetwork = (jstring)Env->GetObjectField(joAttribution, fNetworkID);
    jstring jCampaign = (jstring)Env->GetObjectField(joAttribution, fCampaignID);
    jstring jAdgroup = (jstring)Env->GetObjectField(joAttribution, fAdgroupID);
    jstring jCreative = (jstring)Env->GetObjectField(joAttribution, fCreativeID);
    jstring jClickLabel = (jstring)Env->GetObjectField(joAttribution, fClickLabelID);
    jstring jAdid = (jstring)Env->GetObjectField(joAttribution, fAdidID);

    if (NULL != jTrackerToken) {
        const char *trackerTokenCStr = Env->GetStringUTFChars(jTrackerToken, NULL);
        trackerToken = FString(UTF8_TO_TCHAR(trackerTokenCStr));
        Env->ReleaseStringUTFChars(jTrackerToken, trackerTokenCStr);
        Env->DeleteLocalRef(jTrackerToken);
    } else {
        trackerToken = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jTrackerName) {
        const char *trackerNameCStr = Env->GetStringUTFChars(jTrackerName, NULL);
        trackerName = FString(UTF8_TO_TCHAR(trackerNameCStr));
        Env->ReleaseStringUTFChars(jTrackerName, trackerNameCStr);
        Env->DeleteLocalRef(jTrackerName);
    } else {
        trackerName = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jNetwork) {
        const char *networkCStr = Env->GetStringUTFChars(jNetwork, NULL);
        network = FString(UTF8_TO_TCHAR(networkCStr));
        Env->ReleaseStringUTFChars(jNetwork, networkCStr);
        Env->DeleteLocalRef(jNetwork);
    } else {
        network = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jCampaign) {
        const char *campaignCStr = Env->GetStringUTFChars(jCampaign, NULL);
        campaign = FString(UTF8_TO_TCHAR(campaignCStr));
        Env->ReleaseStringUTFChars(jCampaign, campaignCStr);
        Env->DeleteLocalRef(jCampaign);
    } else {
        campaign = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jAdgroup) {
        const char *adgroupCStr = Env->GetStringUTFChars(jAdgroup, NULL);
        adgroup = FString(UTF8_TO_TCHAR(adgroupCStr));
        Env->ReleaseStringUTFChars(jAdgroup, adgroupCStr);
        Env->DeleteLocalRef(jAdgroup);
    } else {
        adgroup = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jCreative) {
        const char *creativeCStr = Env->GetStringUTFChars(jCreative, NULL);
        creative = FString(UTF8_TO_TCHAR(creativeCStr));
        Env->ReleaseStringUTFChars(jCreative, creativeCStr);
        Env->DeleteLocalRef(jCreative);
    } else {
        creative = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jClickLabel) {
        const char *clickLabelCStr = Env->GetStringUTFChars(jClickLabel, NULL);
        clickLabel = FString(UTF8_TO_TCHAR(clickLabelCStr));
        Env->ReleaseStringUTFChars(jClickLabel, clickLabelCStr);
        Env->DeleteLocalRef(jClickLabel);
    } else {
        clickLabel = FString(UTF8_TO_TCHAR(""));
    }

    if (NULL != jAdid) {
        const char *adidCStr = Env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        Env->ReleaseStringUTFChars(jAdid, adidCStr);
        Env->DeleteLocalRef(jAdid);
    } else {
        adid = FString(UTF8_TO_TCHAR(""));
    }

    FAdjustAttribution ueAttribution;
    ueAttribution.TrackerToken = trackerToken;
    ueAttribution.TrackerName = trackerName;
    ueAttribution.Network = network;
    ueAttribution.Campaign = campaign;
    ueAttribution.Adgroup = adgroup;
    ueAttribution.Creative = creative;
    ueAttribution.ClickLabel = clickLabel;
    ueAttribution.Adid = adid;

    Env->DeleteLocalRef(joAttribution);
    return ueAttribution;
#else
    FAdjustAttribution ueAttribution;
    return ueAttribution;
#endif
}

FString UAdjust::GetSdkVersion() {
#if PLATFORM_IOS
    FString Separator = FString(UTF8_TO_TCHAR("@"));
    FString SdkPrefix = FString(UTF8_TO_TCHAR("unreal4.17.1"));
    FString SdkVersion = *FString([Adjust sdkVersion]);
    FString FinalVersion = SdkPrefix + Separator + SdkVersion;
    return FinalVersion;
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetSdkVersion = Env->GetStaticMethodID(jcslAdjust, "getSdkVersion", "()Ljava/lang/String;");
    jstring jSdkVersion = (jstring)Env->CallStaticObjectMethod(jcslAdjust, jmidAdjustGetSdkVersion);

    FString SdkVersion = FString(UTF8_TO_TCHAR(""));
    if (NULL != jSdkVersion) {
        const char* sdkVersionCStr = Env->GetStringUTFChars(jSdkVersion, NULL);
        SdkVersion = FString(UTF8_TO_TCHAR(sdkVersionCStr));
        Env->ReleaseStringUTFChars(jSdkVersion, sdkVersionCStr);
    }
    Env->DeleteLocalRef(jSdkVersion);

    FString Separator = FString(UTF8_TO_TCHAR("@"));
    FString SdkPrefix = FString(UTF8_TO_TCHAR("unreal4.17.1"));
    FString FinalVersion = SdkPrefix + Separator + SdkVersion;
    return FinalVersion;
#else
    FString FinalVersion = FString(UTF8_TO_TCHAR(""));
    return FinalVersion;
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
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustAddSessionCallbackParameter = Env->GetStaticMethodID(jcslAdjust, "addSessionCallbackParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*Value));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustAddSessionCallbackParameter, jKey, jValue);
    Env->DeleteLocalRef(jKey);
    Env->DeleteLocalRef(jValue);
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
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustAddSessionPartnerParameter = Env->GetStaticMethodID(jcslAdjust, "addSessionPartnerParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*Value));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustAddSessionPartnerParameter, jKey, jValue);
    Env->DeleteLocalRef(jKey);
    Env->DeleteLocalRef(jValue);
#endif
}

void UAdjust::RemoveSessionCallbackParameter(const FString& Key) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeSessionCallbackParameter:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveSessionCallbackParameter = Env->GetStaticMethodID(jcslAdjust, "removeSessionCallbackParameter", "(Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveSessionCallbackParameter, jKey);
    Env->DeleteLocalRef(jKey);
#endif
}

void UAdjust::RemoveSessionPartnerParameter(const FString& Key) {
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeSessionPartnerParameter:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveSessionPartnerParameter = Env->GetStaticMethodID(jcslAdjust, "removeSessionPartnerParameter", "(Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveSessionPartnerParameter, jKey);
    Env->DeleteLocalRef(jKey);
#endif
}

void UAdjust::ResetSessionCallbackParameters() {
#if PLATFORM_IOS
    [Adjust resetSessionCallbackParameters];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustResetSessionCallbackParameters = Env->GetStaticMethodID(jcslAdjust, "resetSessionCallbackParameters", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustResetSessionCallbackParameters);
#endif
}

void UAdjust::ResetSessionPartnerParameters() {
#if PLATFORM_IOS
    [Adjust resetSessionPartnerParameters];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustResetSessionPartnerParameters = Env->GetStaticMethodID(jcslAdjust, "resetSessionPartnerParameters", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustResetSessionPartnerParameters);
#endif
}

void UAdjust::SendFirstPackages() {
#if PLATFORM_IOS
    [Adjust sendFirstPackages];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSendFirstPackages = Env->GetStaticMethodID(jcslAdjust, "sendFirstPackages", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSendFirstPackages);
#endif
}

void UAdjust::GdprForgetMe() {
#if PLATFORM_IOS
    [Adjust gdprForgetMe];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGdprForgetMe = Env->GetStaticMethodID(jcslAdjust, "gdprForgetMe", "(Landroid/content/Context;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGdprForgetMe, FJavaWrapper::GameActivityThis);
#endif
}

void UAdjust::TrackAdRevenue(const FString& Source, const FString& Payload) {
#if PLATFORM_IOS
    CFStringRef cfstrSource = FPlatformString::TCHARToCFString(*Source);
    NSString *strSource = (NSString *)cfstrSource;
    CFStringRef cfstrPayload = FPlatformString::TCHARToCFString(*Payload);
    NSString *strPayload = (NSString *)cfstrPayload;
    NSData *dataPayload = [strPayload dataUsingEncoding:NSUTF8StringEncoding];
    [Adjust trackAdRevenue:strSource payload:dataPayload];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackAdRevenue = Env->GetStaticMethodID(jcslAdjust, "trackAdRevenue", "(Ljava/lang/String;Lorg/json/JSONObject;)V");
    jstring jSource = Env->NewStringUTF(TCHAR_TO_UTF8(*Source));
    jstring jPayload = Env->NewStringUTF(TCHAR_TO_UTF8(*Payload));

    jclass jcslJsonObject = FAndroidApplication::FindJavaClass("org/json/JSONObject");
    jmethodID jmidJsonObjectInit = Env->GetMethodID(jcslJsonObject, "<init>", "(Ljava/lang/String;)V");
    jobject joJsonPayload = Env->NewObject(jcslJsonObject, jmidJsonObjectInit, jPayload);

    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackAdRevenue, jSource, joJsonPayload);
    Env->DeleteLocalRef(jSource);
    Env->DeleteLocalRef(jPayload);
#endif
}
