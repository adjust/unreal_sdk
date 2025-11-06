//
//  Adjust.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "Adjust.h"
#include "AdjustDelegates.h"
#include "AdjustModule.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Modules/ModuleManager.h"

#if PLATFORM_IOS
#import "IOS/Native/Adjust.h"
#import "IOS/Native/ADJEvent.h"
#import "IOS/Native/ADJThirdPartySharing.h"
#import "IOS/Native/ADJConfig.h"
#import "IOS/Native/ADJLogger.h"
#import "IOS/Native/ADJAttribution.h"
#import "IOS/Native/ADJAppStoreSubscription.h"
#import "IOS/Native/ADJEventSuccess.h"
#import "IOS/Native/ADJEventFailure.h"
#import "IOS/Native/ADJSessionSuccess.h"
#import "IOS/Native/ADJSessionFailure.h"
#import "IOS/Native/ADJAdRevenue.h"
#import "IOS/Native/ADJLinkResolution.h"
#import "IOS/Native/ADJAppStorePurchase.h"
#import "IOS/Native/ADJStoreInfo.h"
#import "IOS/Native/ADJPurchaseVerificationResult.h"
#import "IOS/Native/ADJDeeplink.h"
#import "IOS/Delegate/AdjustSdkDelegate.h"
#elif PLATFORM_ANDROID
#include "Android/AdjustJNI.h"
#endif

UAdjust::UAdjust(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

static void adjustAttributionCallback(FAdjustAttribution Attribution)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAttributionChangedDelegate.Broadcast(Attribution);
    }
}

static void adjustSessionSuccessCallback(FAdjustSessionSuccess SessionSuccess)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnSessionSuccessDelegate.Broadcast(SessionSuccess);
    }
}

static void adjustSessionFailureCallback(FAdjustSessionFailure SessionFailure)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnSessionFailureDelegate.Broadcast(SessionFailure);
    }
}

static void adjustEventSuccessCallback(FAdjustEventSuccess EventSuccess)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnEventSuccessDelegate.Broadcast(EventSuccess);
    }
}

static void adjustEventFailureCallback(FAdjustEventFailure EventFailure)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnEventFailureDelegate.Broadcast(EventFailure);
    }
}

static void adjustDeferredDeeplinkCallback(FString Deeplink)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnDeferredDeeplinkDelegate.Broadcast(Deeplink);
    }
}

static void adjustIsEnabledCallback(bool isEnabled)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnIsEnabledDelegate.Broadcast(isEnabled);
    }
}

static void adjustAdidGetterCallback(FString Adid)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAdidGetterDelegate.Broadcast(Adid);
    }
}

static void adjustAttributionGetterCallback(FAdjustAttribution Attribution)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAttributionGetterDelegate.Broadcast(Attribution);
    }
}

static void adjustLastDeeplinkGetterCallback(FString LastDeeplink)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnLastDeeplinkGetterDelegate.Broadcast(LastDeeplink);
    }
}

static void adjustAuthorizationStatusCallback(int AuthorizationStatus)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAuthorizationStatusGetterDelegate.Broadcast(AuthorizationStatus);
    }
}

static void adjustDeeplinkResolutionCallback(FString ResolvedLink)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnDeeplinkResolutionDelegate.Broadcast(ResolvedLink);
    }
}

static void adjustSdkVersionGetterCallback(FString SdkVersion)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnSdkVersionGetterDelegate.Broadcast(SdkVersion);
    }
}

static void adjustIdfaGetterCallback(FString Idfa)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnIdfaGetterDelegate.Broadcast(Idfa);
    }
}

static void adjustIdfvGetterCallback(FString Idfv)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnIdfvGetterDelegate.Broadcast(Idfv);
    }
}

static void adjustAuthorizationStatusGetterCallback(int AuthorizationStatus)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAuthorizationStatusGetterDelegate.Broadcast(AuthorizationStatus);
    }
}

static void adjustRequestAppAuthorizationStatusCallback(int AuthorizationStatus)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnRequestTrackingAuthorizationDelegate.Broadcast(AuthorizationStatus);
    }
}

static void adjustUpdateSkanConversionValueCallback(FString Error)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnUpdateSkanConversionValueDelegate.Broadcast(Error);
    }
}

static void adjustGoogleAdIdGetterCallback(FString GoogleAdId)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnGoogleAdIdGetterDelegate.Broadcast(GoogleAdId);
    }
}

static void adjustAmazonAdIdGetterCallback(FString AmazonAdId)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnAmazonAdIdGetterDelegate.Broadcast(AmazonAdId);
    }
}

static void adjustPurchaseVerificationCallback(FAdjustPurchaseVerificationResult VerificationResult)
{
    for (TObjectIterator<UAdjustDelegates> Itr; Itr; ++Itr)
    {
        Itr->OnPurchaseVerificationFinishedDelegate.Broadcast(VerificationResult);
    }
}

void UAdjust::InitSdk(const FAdjustConfig& Config)
{
#if PLATFORM_IOS
    // app token
    CFStringRef cfstrAppToken = FPlatformString::TCHARToCFString(*Config.AppToken);
    NSString *strAppToken = (NSString *)cfstrAppToken;

    // environment
    EAdjustEnvironment eEnvironment = Config.Environment;
    NSString *environment;
    switch (eEnvironment)
    {
        case EAdjustEnvironment::Sandbox:
            environment = ADJEnvironmentSandbox;
            break;
        case (EAdjustEnvironment::Production):
            environment = ADJEnvironmentProduction;
            break;
    }

    // log level
    EAdjustLogLevel eLogLevel = Config.LogLevel;
    ADJLogLevel logLevel = ADJLogLevelInfo;
    bool allowSuppressLevel = false;
    switch (eLogLevel)
    {
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

    ADJConfig *adjustConfig = [[ADJConfig alloc] initWithAppToken:strAppToken
                                                      environment:environment
                                                 suppressLogLevel:allowSuppressLevel];

    // SDK prefix
    [adjustConfig setSdkPrefix:@"unreal5.4.0"];

    // log level
    [adjustConfig setLogLevel:logLevel];

    // user callbacks
    AdjustSdkDelegate *delegate = [[AdjustSdkDelegate alloc] init];
    [delegate setAttributionCallback:adjustAttributionCallback];
    [delegate setSessionSuccessCallback:adjustSessionSuccessCallback];
    [delegate setSessionFailureCallback:adjustSessionFailureCallback];
    [delegate setEventSuccessCallback:adjustEventSuccessCallback];
    [delegate setEventFailureCallback:adjustEventFailureCallback];
    [delegate setDeferredDeeplinkCallback:adjustDeferredDeeplinkCallback];
    [delegate setShouldOpenDeferredDeeplink:Config.IsDeferredDeeplinkOpeningEnabled];
    adjustConfig.delegate = delegate;

    // default tracker
    if (!Config.DefaultTracker.IsEmpty())
    {
        CFStringRef cfstrDefaultTracker = FPlatformString::TCHARToCFString(*Config.DefaultTracker);
        NSString *strDefaultTracker = (NSString *)cfstrDefaultTracker;
        [adjustConfig setDefaultTracker:strDefaultTracker];
    }

    // external device ID
    if (!Config.ExternalDeviceId.IsEmpty())
    {
        CFStringRef cfstrExternalDeviceId = FPlatformString::TCHARToCFString(*Config.ExternalDeviceId);
        NSString *strExternalDeviceId = (NSString *)cfstrExternalDeviceId;
        [adjustConfig setExternalDeviceId:strExternalDeviceId];
    }

    // send in background
    if (Config.IsSendingInBackgroundEnabled == true) {
        [adjustConfig enableSendingInBackground];
    }

    // COPPA compliance
    if (Config.IsCoppaComplianceEnabled == true) {
        [adjustConfig enableCoppaCompliance];
    }

    // read device info just once
    if (Config.IsDeviceIdsReadingOnceEnabled == true) {
        [adjustConfig enableDeviceIdsReadingOnce];
    }

    // cost data in attribution
    if (Config.IsCostDataInAttributionEnabled == true) {
        [adjustConfig enableCostDataInAttribution];
    }

    // disable IDFA reading
    if (Config.IsIdfaReadingEnabled == false) {
        [adjustConfig disableIdfaReading];
    }

    // disable IDFV reading
    if (Config.IsIdfvReadingEnabled == false) {
        [adjustConfig disableIdfvReading];
    }

    // LinkMe
    if (Config.IsLinkMeEnabled == true) {
        [adjustConfig enableLinkMe];
    }

    // SKAN attribution
    if (Config.IsSkanAttributionEnabled == false)
    {
        [adjustConfig disableSkanAttribution];
    }

    // AdServices.framework handling (Apple Search Ads)
    if (Config.IsAdServicesEnabled == false)
    {
        [adjustConfig disableAdServices];
    }

    // ATT consent waiting interval
    if (Config.AttConsentWaitingInterval > 0) {
        [adjustConfig setAttConsentWaitingInterval:Config.AttConsentWaitingInterval];
    }

    // disable App Tracking Transparency usage
    if (Config.IsAppTrackingTransparencyUsageEnabled == false) {
        [adjustConfig disableAppTrackingTransparencyUsage];
    }

    // first session delay
    if (Config.IsFirstSessionDelayEnabled == true) {
        [adjustConfig enableFirstSessionDelay];
    }

    // store info
    if (!Config.StoreInfo.StoreName.IsEmpty()) {
        CFStringRef cfstrStoreName = FPlatformString::TCHARToCFString(*(Config.StoreInfo.StoreName));
        NSString *strStoreName = (NSString *)cfstrStoreName;
        ADJStoreInfo *storeInfo = [[ADJStoreInfo alloc] initWithStoreName:strStoreName];
        if (storeInfo != nil && !Config.StoreInfo.StoreAppId.IsEmpty()) {
            CFStringRef cfstrStoreAppId = FPlatformString::TCHARToCFString(*(Config.StoreInfo.StoreAppId));
            NSString *strStoreAppId = (NSString *)cfstrStoreAppId;
            storeInfo.storeAppId = strStoreAppId;
        }
        [adjustConfig setStoreInfo:storeInfo];
    }

    // event deduplication IDs max size
    if (Config.EventDeduplicationIdsMaxSize >= 0) {
        adjustConfig.eventDeduplicationIdsMaxSize = Config.EventDeduplicationIdsMaxSize;
    }

    // start SDK
    [Adjust initSdk:adjustConfig];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // app token
    jstring jAppToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.AppToken));

    // environment
    jstring jEnvironment;
    EAdjustEnvironment eEnvironment = Config.Environment;
    switch (eEnvironment)
    {
        case EAdjustEnvironment::Sandbox:
            jEnvironment = Env->NewStringUTF("sandbox");
            break;
        case (EAdjustEnvironment::Production):
            jEnvironment = Env->NewStringUTF("production");
            break;
    }

    // log level
    const char* cLogLevel;
    bool allowSuppressLevel = false;
    EAdjustLogLevel eLogLevel = Config.LogLevel;
    switch (eLogLevel)
    {
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
            cLogLevel = "SUPPRESS";
            allowSuppressLevel = true;
            break;
        default:
            cLogLevel = "INFO";
            break;
    }

    // create config object
    jclass jcslAdjustConfig = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustConfig");
    jmethodID jmidAdjustConfigInit = Env->GetMethodID(jcslAdjustConfig, "<init>", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Z)V");
    jobject joAdjustConfig = Env->NewObject(jcslAdjustConfig, jmidAdjustConfigInit, FJavaWrapper::GameActivityThis, jAppToken, jEnvironment, allowSuppressLevel);
    Env->DeleteLocalRef(jAppToken);
    Env->DeleteLocalRef(jEnvironment);

    // SDK prefix
    const char* cstrSdkPrefix = "unreal5.4.0";
    jstring jSdkPrefix = Env->NewStringUTF(cstrSdkPrefix);
    jmethodID jmidAdjustConfigSetSdkPrefix = Env->GetMethodID(jcslAdjustConfig, "setSdkPrefix", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSdkPrefix, jSdkPrefix);
    Env->DeleteLocalRef(jSdkPrefix);

    // log level
    jclass jclsLogLevel = FAndroidApplication::FindJavaClass("com/adjust/sdk/LogLevel");
    jfieldID jfidValue = Env->GetStaticFieldID(jclsLogLevel, cLogLevel, "Lcom/adjust/sdk/LogLevel;");
    jobject joLogLevel = Env->GetStaticObjectField(jclsLogLevel, jfidValue);
    jmethodID jmidAdjustConfigSetLogLevel = Env->GetMethodID(jcslAdjustConfig, "setLogLevel", "(Lcom/adjust/sdk/LogLevel;)V");
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetLogLevel, joLogLevel);
    Env->DeleteLocalRef(joLogLevel);

    // attribution callback
    setAttributionCallbackMethod(adjustAttributionCallback);
    jclass jcslUeAttributionCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeAttributionCallback");
    jmethodID jmidAdjustConfigSetAttributionCallback = Env->GetMethodID(jcslAdjustConfig, "setOnAttributionChangedListener", "(Lcom/adjust/sdk/OnAttributionChangedListener;)V");
    jmethodID jmidUeAttributionCallbackInit = Env->GetMethodID(jcslUeAttributionCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joAttributionCallbackProxy = Env->NewObject(jcslUeAttributionCallback, jmidUeAttributionCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetAttributionCallback, joAttributionCallbackProxy);
    Env->DeleteLocalRef(joAttributionCallbackProxy);

    // session success callback
    setSessionSuccessCallbackMethod(adjustSessionSuccessCallback);
    jclass jcslUeSessionSuccessCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeSessionSuccessCallback");
    jmethodID jmidAdjustConfigSetSessionSuccessCallback = Env->GetMethodID(jcslAdjustConfig, "setOnSessionTrackingSucceededListener", "(Lcom/adjust/sdk/OnSessionTrackingSucceededListener;)V");
    jmethodID jmidUeSessionSuccessCallbackInit = Env->GetMethodID(jcslUeSessionSuccessCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joSessionSuccessCallbackProxy = Env->NewObject(jcslUeSessionSuccessCallback, jmidUeSessionSuccessCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSessionSuccessCallback, joSessionSuccessCallbackProxy);
    Env->DeleteLocalRef(joSessionSuccessCallbackProxy);

    // session failure callback
    setSessionFailureCallbackMethod(adjustSessionFailureCallback);
    jclass jcslUeSessionFailureCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeSessionFailureCallback");
    jmethodID jmidAdjustConfigSetSessionFailureCallback = Env->GetMethodID(jcslAdjustConfig, "setOnSessionTrackingFailedListener", "(Lcom/adjust/sdk/OnSessionTrackingFailedListener;)V");
    jmethodID jmidUeSessionFailureCallbackInit = Env->GetMethodID(jcslUeSessionFailureCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joSessionFailureCallbackProxy = Env->NewObject(jcslUeSessionFailureCallback, jmidUeSessionFailureCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSessionFailureCallback, joSessionFailureCallbackProxy);
    Env->DeleteLocalRef(joSessionFailureCallbackProxy);

    // event success callback
    setEventSuccessCallbackMethod(adjustEventSuccessCallback);
    jclass jcslUeEventSuccessCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeEventSuccessCallback");
    jmethodID jmidAdjustConfigSetEventSuccessCallback = Env->GetMethodID(jcslAdjustConfig, "setOnEventTrackingSucceededListener", "(Lcom/adjust/sdk/OnEventTrackingSucceededListener;)V");
    jmethodID jmidUeEventSuccessCallbackInit = Env->GetMethodID(jcslUeEventSuccessCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joEventSuccessCallbackProxy = Env->NewObject(jcslUeEventSuccessCallback, jmidUeEventSuccessCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventSuccessCallback, joEventSuccessCallbackProxy);
    Env->DeleteLocalRef(joEventSuccessCallbackProxy);

    // event failure callback
    setEventFailureCallbackMethod(adjustEventFailureCallback);
    jclass jcslUeEventFailureCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeEventFailureCallback");
    jmethodID jmidAdjustConfigSetEventFailureCallback = Env->GetMethodID(jcslAdjustConfig, "setOnEventTrackingFailedListener", "(Lcom/adjust/sdk/OnEventTrackingFailedListener;)V");
    jmethodID jmidUeEventFailureCallbackInit = Env->GetMethodID(jcslUeEventFailureCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joEventFailureCallbackProxy = Env->NewObject(jcslUeEventFailureCallback, jmidUeEventFailureCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventFailureCallback, joEventFailureCallbackProxy);
    Env->DeleteLocalRef(joEventFailureCallbackProxy);

    // deferred deep link callback
    setDeferredDeeplinkCallbackMethod(adjustDeferredDeeplinkCallback);
    jclass jcslUeDeferredDeeplinkCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeDeferredDeeplinkCallback");
    jmethodID jmidAdjustConfigSetDeferredDeeplinkCallback = Env->GetMethodID(jcslAdjustConfig, "setOnDeferredDeeplinkResponseListener", "(Lcom/adjust/sdk/OnDeferredDeeplinkResponseListener;)V");
    jmethodID jmidUeDeferredDeeplinkCallbackInit = Env->GetMethodID(jcslUeDeferredDeeplinkCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;Z)V");
    jobject joDeferredDeeplinkCallbackProxy = Env->NewObject(jcslUeDeferredDeeplinkCallback, jmidUeDeferredDeeplinkCallbackInit, FJavaWrapper::GameActivityThis, Config.IsDeferredDeeplinkOpeningEnabled);
    Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetDeferredDeeplinkCallback, joDeferredDeeplinkCallbackProxy);
    Env->DeleteLocalRef(joDeferredDeeplinkCallbackProxy);

    // default tracker
    if (!Config.DefaultTracker.IsEmpty())
    {
        jstring jDefaultTracker = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.DefaultTracker));
        jmethodID jmidAdjustConfigSetDefaultTracker = Env->GetMethodID(jcslAdjustConfig, "setDefaultTracker", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetDefaultTracker, jDefaultTracker);
        Env->DeleteLocalRef(jDefaultTracker);
    }

    // external device ID
    if (!Config.ExternalDeviceId.IsEmpty())
    {
        jstring jExternalDeviceId = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.ExternalDeviceId));
        jmethodID jmidAdjustConfigSetExternalDeviceId = Env->GetMethodID(jcslAdjustConfig, "setExternalDeviceId", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetExternalDeviceId, jExternalDeviceId);
        Env->DeleteLocalRef(jExternalDeviceId);
    }

    // FB app ID
    if (!Config.FbAppId.IsEmpty())
    {
        jstring jFbAppId = Env->NewStringUTF(TCHAR_TO_UTF8(*Config.FbAppId));
        jmethodID jmidAdjustConfigSetFbAppId = Env->GetMethodID(jcslAdjustConfig, "setFbAppId", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetFbAppId, jFbAppId);
        Env->DeleteLocalRef(jFbAppId);
    }

    // COPPA compliance
    if (Config.IsCoppaComplianceEnabled == true) {
        jmethodID jmidAdjustConfigEnableCoppa = Env->GetMethodID(jcslAdjustConfig, "enableCoppaCompliance", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigEnableCoppa);
    }

    // Play Store Kids compliance
    if (Config.IsPlayStoreKidsComplianceEnabled == true) {
        jmethodID jmidAdjustConfigEnablePlayStoreKids = Env->GetMethodID(jcslAdjustConfig, "enablePlayStoreKidsCompliance", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigEnablePlayStoreKids);
    }

    // send in background
    if (Config.IsSendingInBackgroundEnabled == true) {
        jmethodID jmidAdjustConfigSetSendInBackground = Env->GetMethodID(jcslAdjustConfig, "enableSendingInBackground", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetSendInBackground);
    }

    // read device info just once
    if (Config.IsDeviceIdsReadingOnceEnabled == true) {
        jmethodID jmidAdjustConfigReadDeviceIdsOnce = Env->GetMethodID(jcslAdjustConfig, "enableDeviceIdsReadingOnce", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigReadDeviceIdsOnce);
    }

    // cost data in attribution
    if (Config.IsCostDataInAttributionEnabled == true) {
        jmethodID jmidAdjustConfigCostDataInAttribution = Env->GetMethodID(jcslAdjustConfig, "enableCostDataInAttribution", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigCostDataInAttribution);
    }

    // first session delay
    if (Config.IsFirstSessionDelayEnabled == true) {
        jmethodID jmidAdjustConfigEnableFirstSessionDelay = Env->GetMethodID(jcslAdjustConfig, "enableFirstSessionDelay", "()V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigEnableFirstSessionDelay);
    }

    // store info
    if (!Config.StoreInfo.StoreName.IsEmpty()) {
        jclass jcslAdjustStoreInfo = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustStoreInfo");
        jmethodID jmidAdjustStoreInfoInit = Env->GetMethodID(jcslAdjustStoreInfo, "<init>", "(Ljava/lang/String;)V");
        jstring jstrStoreName = Env->NewStringUTF(TCHAR_TO_UTF8(*(Config.StoreInfo.StoreName)));
        jobject joAdjustStoreInfo = Env->NewObject(jcslAdjustStoreInfo, jmidAdjustStoreInfoInit, jstrStoreName);
        Env->DeleteLocalRef(jstrStoreName);
        
        if (joAdjustStoreInfo != nullptr && !Config.StoreInfo.StoreAppId.IsEmpty()) {
            jstring jstrStoreAppId = Env->NewStringUTF(TCHAR_TO_UTF8(*(Config.StoreInfo.StoreAppId)));
            jmethodID jmidAdjustStoreInfoSetStoreAppId = Env->GetMethodID(jcslAdjustStoreInfo, "setStoreAppId", "(Ljava/lang/String;)V");
            Env->CallVoidMethod(joAdjustStoreInfo, jmidAdjustStoreInfoSetStoreAppId, jstrStoreAppId);
            Env->DeleteLocalRef(jstrStoreAppId);
        }
        
        if (joAdjustStoreInfo != nullptr) {
            jmethodID jmidAdjustConfigSetStoreInfo = Env->GetMethodID(jcslAdjustConfig, "setStoreInfo", "(Lcom/adjust/sdk/AdjustStoreInfo;)V");
            Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetStoreInfo, joAdjustStoreInfo);
            Env->DeleteLocalRef(joAdjustStoreInfo);
        }
    }

    // event deduplication IDs max size
    if (Config.EventDeduplicationIdsMaxSize >= 0) {
        jclass clsInteger = Env->FindClass("java/lang/Integer");
        jmethodID midInit = Env->GetMethodID(clsInteger, "<init>", "(I)V");
        jobject jEventDeduplicationIdsMaxSize = Env->NewObject(clsInteger, midInit, Config.EventDeduplicationIdsMaxSize);
        jmethodID jmidAdjustConfigSetEventDeduplicationIdsMaxSize = Env->GetMethodID(jcslAdjustConfig, "setEventDeduplicationIdsMaxSize", "(Ljava/lang/Integer;)V");
        Env->CallVoidMethod(joAdjustConfig, jmidAdjustConfigSetEventDeduplicationIdsMaxSize, jEventDeduplicationIdsMaxSize);
        Env->DeleteLocalRef(jEventDeduplicationIdsMaxSize);
    }

    // start SDK
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustInitSdk = Env->GetStaticMethodID(jcslAdjust, "initSdk", "(Lcom/adjust/sdk/AdjustConfig;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustInitSdk, joAdjustConfig);
    Env->DeleteLocalRef(joAdjustConfig);
#endif
}

void UAdjust::TrackEvent(const FAdjustEvent& Event)
{
#if PLATFORM_IOS
    // event token
    CFStringRef cfstrEventToken = FPlatformString::TCHARToCFString(*Event.EventToken);
    NSString *strEventToken = (NSString *)cfstrEventToken;

    ADJEvent *adjustEvent = [[ADJEvent alloc] initWithEventToken:strEventToken];

    // revenue & currency
    if (Event.Revenue > 0.0 || !Event.Currency.IsEmpty())
    {
        NSString *strCurrency = nil;
        if (!Event.Currency.IsEmpty())
        {
            CFStringRef cfstrCurrency = FPlatformString::TCHARToCFString(*Event.Currency);
            strCurrency = (NSString *)cfstrCurrency;
        }
        [adjustEvent setRevenue:(double)Event.Revenue currency:strCurrency];
    }

    // callback parameters
    TMap<FString, FString> callbackParams = Event.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams)
    {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addCallbackParameter:strKey value:strValue];
    }

    // partner parameters
    TMap<FString, FString> partnerParams = Event.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams)
    {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustEvent addPartnerParameter:strKey value:strValue];
    }

    // deduplication ID
    if (!Event.DeduplicationId.IsEmpty())
    {
        CFStringRef cfstrDeduplicationId = FPlatformString::TCHARToCFString(*Event.DeduplicationId);
        NSString *strDeduplicationId = (NSString *)cfstrDeduplicationId;
        [adjustEvent setDeduplicationId:strDeduplicationId];
    }

    // callback ID
    if (!Event.CallbackId.IsEmpty())
    {
        CFStringRef cfstrCallbackId = FPlatformString::TCHARToCFString(*Event.CallbackId);
        NSString *strCallbackId = (NSString *)cfstrCallbackId;
        [adjustEvent setCallbackId:strCallbackId];
    }

    // transaction ID
    if (!Event.TransactionId.IsEmpty())
    {
        CFStringRef cfstrTransactionId = FPlatformString::TCHARToCFString(*Event.TransactionId);
        NSString *strTransactionId = (NSString *)cfstrTransactionId;
        [adjustEvent setTransactionId:strTransactionId];
    }

    // product ID
    if (!Event.ProductId.IsEmpty())
    {
        CFStringRef cfstrProductId = FPlatformString::TCHARToCFString(*Event.ProductId);
        NSString *strProductId = (NSString *)cfstrProductId;
        [adjustEvent setProductId:strProductId];
    }

    // track event
    [Adjust trackEvent:adjustEvent];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // event token
    jstring jEventToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.EventToken));

    // create event object
    jclass jcslAdjustEvent = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustEvent");
    jmethodID jmidAdjustEventInit = Env->GetMethodID(jcslAdjustEvent, "<init>", "(Ljava/lang/String;)V");
    jobject joAdjustEvent = Env->NewObject(jcslAdjustEvent, jmidAdjustEventInit, jEventToken);
    Env->DeleteLocalRef(jEventToken);

    // revenue & currency
    if (Event.Revenue > 0.0 || !Event.Currency.IsEmpty())
    {
        jstring jCurrency = nullptr;
        if (!Event.Currency.IsEmpty())
        {
            jCurrency = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.Currency));
        }
        jmethodID jmidAdjustEventSetRevenue = Env->GetMethodID(jcslAdjustEvent, "setRevenue", "(DLjava/lang/String;)V");
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetRevenue, (double)Event.Revenue, jCurrency);
        if (jCurrency != nullptr)
        {
            Env->DeleteLocalRef(jCurrency);
        }
    }

    // deduplication ID
    if (!Event.DeduplicationId.IsEmpty())
    {
        jstring jDeduplicationId = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.DeduplicationId));
        jmethodID jmidAdjustEventSetDeduplicationId = Env->GetMethodID(jcslAdjustEvent, "setDeduplicationId", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetDeduplicationId, jDeduplicationId);
        Env->DeleteLocalRef(jDeduplicationId);
    }

    // callback ID
    if (!Event.CallbackId.IsEmpty())
    {
        jstring jCallbackId = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.CallbackId));
        jmethodID jmidAdjustEventSetCallbackId = Env->GetMethodID(jcslAdjustEvent, "setCallbackId", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetCallbackId, jCallbackId);
        Env->DeleteLocalRef(jCallbackId);
    }

    // product ID
    if (!Event.ProductId.IsEmpty())
    {
        jstring jProductId = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.ProductId));
        jmethodID jmidAdjustEventSetProductId = Env->GetMethodID(jcslAdjustEvent, "setProductId", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetProductId, jProductId);
        Env->DeleteLocalRef(jProductId);
    }

    // purchase token (Android only)
    if (!Event.PurchaseToken.IsEmpty())
    {
        jstring jPurchaseToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Event.PurchaseToken));
        jmethodID jmidAdjustEventSetPurchaseToken = Env->GetMethodID(jcslAdjustEvent, "setPurchaseToken", "(Ljava/lang/String;)V");
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventSetPurchaseToken, jPurchaseToken);
        Env->DeleteLocalRef(jPurchaseToken);
    }

    // callback parameters
    jmethodID jmidAdjustEventAddCallbackParameter = Env->GetMethodID(jcslAdjustEvent, "addCallbackParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> callbackParams = Event.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams)
    {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventAddCallbackParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // partner parameters
    jmethodID jmidAdjustEventAddPartnerParameter = Env->GetMethodID(jcslAdjustEvent, "addPartnerParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> partnerParams = Event.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams)
    {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustEvent, jmidAdjustEventAddPartnerParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // track event
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackEvent = Env->GetStaticMethodID(jcslAdjust, "trackEvent", "(Lcom/adjust/sdk/AdjustEvent;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackEvent, joAdjustEvent);
    Env->DeleteLocalRef(joAdjustEvent);
#endif
}

void UAdjust::Enable()
{
#if PLATFORM_IOS
    [Adjust enable];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustEnable = Env->GetStaticMethodID(jcslAdjust, "enable", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustEnable);
#endif
}

void UAdjust::Disable()
{
#if PLATFORM_IOS
    [Adjust disable];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustDisable = Env->GetStaticMethodID(jcslAdjust, "disable", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustDisable);
#endif
}

void UAdjust::ProcessDeeplink(const FAdjustDeeplink& Deeplink)
{
#if PLATFORM_IOS
    CFStringRef cfstrUrl = FPlatformString::TCHARToCFString(*(Deeplink.Deeplink));
    NSString *strUrl = (NSString *)cfstrUrl;
    NSURL *url = [NSURL URLWithString:strUrl];
    ADJDeeplink *deepLink = [[ADJDeeplink alloc] initWithDeeplink:url];
    
    // set referrer if provided
    if (!Deeplink.Referrer.IsEmpty())
    {
        CFStringRef cfstrReferrer = FPlatformString::TCHARToCFString(*(Deeplink.Referrer));
        NSString *strReferrer = (NSString *)cfstrReferrer;
        NSURL *referrerUrl = [NSURL URLWithString:strReferrer];
        if (referrerUrl != nil)
        {
            [deepLink setReferrer:referrerUrl];
        }
    }
    
    [Adjust processDeeplink:deepLink];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // create Uri from string
    jclass jcslUri = Env->FindClass("android/net/Uri");
    jmethodID jmidUriParse = Env->GetStaticMethodID(jcslUri, "parse", "(Ljava/lang/String;)Landroid/net/Uri;");
    jstring jstrUrl = Env->NewStringUTF(TCHAR_TO_UTF8(*(Deeplink.Deeplink)));
    jobject joUri = Env->CallStaticObjectMethod(jcslUri, jmidUriParse, jstrUrl);

    // create deep link object
    jclass jcslAdjustDeeplink = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustDeeplink");
    jmethodID jmidAdjustDeeplinkInit = Env->GetMethodID(jcslAdjustDeeplink, "<init>", "(Landroid/net/Uri;)V");
    jobject joAdjustDeeplink = Env->NewObject(jcslAdjustDeeplink, jmidAdjustDeeplinkInit, joUri);
    Env->DeleteLocalRef(joUri);

    // set referrer if provided
    if (!Deeplink.Referrer.IsEmpty())
    {
        jstring jstrReferrer = Env->NewStringUTF(TCHAR_TO_UTF8(*(Deeplink.Referrer)));
        jobject joReferrerUri = Env->CallStaticObjectMethod(jcslUri, jmidUriParse, jstrReferrer);
        if (joReferrerUri != nullptr)
        {
            jmethodID jmidAdjustDeeplinkSetReferrer = Env->GetMethodID(jcslAdjustDeeplink, "setReferrer", "(Landroid/net/Uri;)V");
            Env->CallVoidMethod(joAdjustDeeplink, jmidAdjustDeeplinkSetReferrer, joReferrerUri);
            Env->DeleteLocalRef(joReferrerUri);
        }
        Env->DeleteLocalRef(jstrReferrer);
    }

    // process deep link
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustProcessDeeplink = Env->GetStaticMethodID(jcslAdjust, "processDeeplink", "(Lcom/adjust/sdk/AdjustDeeplink;Landroid/content/Context;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustProcessDeeplink, joAdjustDeeplink, FJavaWrapper::GameActivityThis);
    Env->DeleteLocalRef(joAdjustDeeplink);
#endif
}

void UAdjust::ProcessAndResolveDeeplink(const FAdjustDeeplink& Deeplink)
{
#if PLATFORM_IOS
    CFStringRef cfstrUrl = FPlatformString::TCHARToCFString(*(Deeplink.Deeplink));
    NSString *strUrl = (NSString *)cfstrUrl;
    NSURL *url = [NSURL URLWithString:strUrl];
    ADJDeeplink *deepLink = [[ADJDeeplink alloc] initWithDeeplink:url];
    
    // set referrer if provided
    if (!Deeplink.Referrer.IsEmpty())
    {
        CFStringRef cfstrReferrer = FPlatformString::TCHARToCFString(*(Deeplink.Referrer));
        NSString *strReferrer = (NSString *)cfstrReferrer;
        NSURL *referrerUrl = [NSURL URLWithString:strReferrer];
        if (referrerUrl != nil)
        {
            [deepLink setReferrer:referrerUrl];
        }
    }
    
    [Adjust processAndResolveDeeplink:deepLink
                withCompletionHandler:^(NSString * _Nullable resolvedLink) {
        FString fsResolvedLink;
        if (resolvedLink != nil)
        {
            fsResolvedLink = FString(UTF8_TO_TCHAR([resolvedLink UTF8String]));
        }
        AsyncTask(ENamedThreads::GameThread, [fsResolvedLink]() {
            adjustDeeplinkResolutionCallback(fsResolvedLink);
        });
    }];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // create Uri from string
    jclass jcslUri = Env->FindClass("android/net/Uri");
    jmethodID jmidUriParse = Env->GetStaticMethodID(jcslUri, "parse", "(Ljava/lang/String;)Landroid/net/Uri;");
    jstring jstrUrl = Env->NewStringUTF(TCHAR_TO_UTF8(*(Deeplink.Deeplink)));
    jobject joUri = Env->CallStaticObjectMethod(jcslUri, jmidUriParse, jstrUrl);

    // create deep link object
    jclass jcslAdjustDeeplink = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustDeeplink");
    jmethodID jmidAdjustDeeplinkInit = Env->GetMethodID(jcslAdjustDeeplink, "<init>", "(Landroid/net/Uri;)V");
    jobject joAdjustDeeplink = Env->NewObject(jcslAdjustDeeplink, jmidAdjustDeeplinkInit, joUri);
    Env->DeleteLocalRef(joUri);

    // set referrer if provided
    if (!Deeplink.Referrer.IsEmpty())
    {
        jstring jstrReferrer = Env->NewStringUTF(TCHAR_TO_UTF8(*(Deeplink.Referrer)));
        jobject joReferrerUri = Env->CallStaticObjectMethod(jcslUri, jmidUriParse, jstrReferrer);
        if (joReferrerUri != nullptr)
        {
            jmethodID jmidAdjustDeeplinkSetReferrer = Env->GetMethodID(jcslAdjustDeeplink, "setReferrer", "(Landroid/net/Uri;)V");
            Env->CallVoidMethod(joAdjustDeeplink, jmidAdjustDeeplinkSetReferrer, joReferrerUri);
            Env->DeleteLocalRef(joReferrerUri);
        }
        Env->DeleteLocalRef(jstrReferrer);
    }

    setDeeplinkResolutionCallback(adjustDeeplinkResolutionCallback);
    jclass jcslUeDeeplinkResolvedCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeDeeplinkResolvedCallback");
    jmethodID jmidUeDeeplinkResolvedCallbackInit = Env->GetMethodID(jcslUeDeeplinkResolvedCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joDeeplinkResolvedCallbackProxy = Env->NewObject(jcslUeDeeplinkResolvedCallback, jmidUeDeeplinkResolvedCallbackInit, FJavaWrapper::GameActivityThis);

    // process deep link
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustProcessAndResolveDeeplink = Env->GetStaticMethodID(jcslAdjust, "processAndResolveDeeplink", "(Lcom/adjust/sdk/AdjustDeeplink;Landroid/content/Context;Lcom/adjust/sdk/OnDeeplinkResolvedListener;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustProcessAndResolveDeeplink, joAdjustDeeplink, FJavaWrapper::GameActivityThis, joDeeplinkResolvedCallbackProxy);
    Env->DeleteLocalRef(joAdjustDeeplink);
    Env->DeleteLocalRef(joDeeplinkResolvedCallbackProxy);
#endif
}

void UAdjust::SetPushToken(const FString& PushToken)
{
#if PLATFORM_IOS
    CFStringRef cfstrPushToken = FPlatformString::TCHARToCFString(*PushToken);
    NSString *strPushToken = (NSString *)cfstrPushToken;
    [Adjust setPushTokenAsString:strPushToken];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSetPushToken = Env->GetStaticMethodID(jcslAdjust, "setPushToken", "(Ljava/lang/String;Landroid/content/Context;)V");
    jstring jPushToken = Env->NewStringUTF(TCHAR_TO_UTF8(*PushToken));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSetPushToken, jPushToken, FJavaWrapper::GameActivityThis);
    Env->DeleteLocalRef(jPushToken);
#endif
}

void UAdjust::TrackMeasurementConsent(bool MeasurementConsent)
{
#if PLATFORM_IOS
    [Adjust trackMeasurementConsent:MeasurementConsent];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackMeasurementConsent = Env->GetStaticMethodID(jcslAdjust, "trackMeasurementConsent", "(Z)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackMeasurementConsent, MeasurementConsent);
#endif
}

void UAdjust::SwitchToOfflineMode()
{
#if PLATFORM_IOS
    [Adjust switchToOfflineMode];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSwitchToOfflineMode = Env->GetStaticMethodID(jcslAdjust, "switchToOfflineMode", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSwitchToOfflineMode);
#endif
}

void UAdjust::SwitchBackToOnlineMode()
{
#if PLATFORM_IOS
    [Adjust switchBackToOnlineMode];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSwitchBackToOnlineMode = Env->GetStaticMethodID(jcslAdjust, "switchBackToOnlineMode", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSwitchBackToOnlineMode);
#endif
}

void UAdjust::GetIdfa()
{
#if PLATFORM_IOS
    [Adjust idfaWithCompletionHandler:^(NSString * _Nullable idfa) {
        FString fsIdfa = FString(UTF8_TO_TCHAR([idfa UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [fsIdfa]() {
            adjustIdfaGetterCallback(fsIdfa);
        });
    }];
#endif
}

void UAdjust::GetIdfv()
{
#if PLATFORM_IOS
    [Adjust idfvWithCompletionHandler:^(NSString * _Nullable idfv) {
        FString fsIdfv = FString(UTF8_TO_TCHAR([idfv UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [fsIdfv]() {
            adjustIdfvGetterCallback(fsIdfv);
        });
    }];
#endif
}

void UAdjust::GetGoogleAdId()
{
#if PLATFORM_ANDROID
    setGoogleAdIdGetterCallbackMethod(adjustGoogleAdIdGetterCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetGoogleAdvertisingId = Env->GetStaticMethodID(jcslAdjust, "getGoogleAdId", "(Landroid/content/Context;Lcom/adjust/sdk/OnGoogleAdIdReadListener;)V");
    jclass jcslUeGoogleAdvertisingIdCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeGoogleAdIdGetterCallback");
    jmethodID jmidUeGoogleAdvertisingIdCallbackInit = Env->GetMethodID(jcslUeGoogleAdvertisingIdCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joGoogleAdvertisingIdCallbackProxy = Env->NewObject(jcslUeGoogleAdvertisingIdCallback, jmidUeGoogleAdvertisingIdCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetGoogleAdvertisingId, FJavaWrapper::GameActivityThis, joGoogleAdvertisingIdCallbackProxy);
    Env->DeleteLocalRef(joGoogleAdvertisingIdCallbackProxy);
#endif
}

void UAdjust::GetAmazonAdId()
{
#if PLATFORM_ANDROID
    setAmazonAdIdGetterCallbackMethod(adjustAmazonAdIdGetterCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAmazonAdvertisingId = Env->GetStaticMethodID(jcslAdjust, "getAmazonAdId", "(Landroid/content/Context;Lcom/adjust/sdk/OnAmazonAdIdReadListener;)V");
    jclass jcslUeAmazonAdvertisingIdCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeAmazonAdIdGetterCallback");
    jmethodID jmidUeAmazonAdvertisingIdCallbackInit = Env->GetMethodID(jcslUeAmazonAdvertisingIdCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joAmazonAdvertisingIdCallbackProxy = Env->NewObject(jcslUeAmazonAdvertisingIdCallback, jmidUeAmazonAdvertisingIdCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetAmazonAdvertisingId, FJavaWrapper::GameActivityThis, joAmazonAdvertisingIdCallbackProxy);
    Env->DeleteLocalRef(joAmazonAdvertisingIdCallbackProxy);
#endif
}

void UAdjust::EnablePlayStoreKidsComplianceInDelay()
{
#if PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustEnablePlayStoreKidsComplianceInDelay = Env->GetStaticMethodID(jcslAdjust, "enablePlayStoreKidsComplianceInDelay", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustEnablePlayStoreKidsComplianceInDelay);
#endif
}

void UAdjust::DisablePlayStoreKidsComplianceInDelay()
{
#if PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustDisablePlayStoreKidsComplianceInDelay = Env->GetStaticMethodID(jcslAdjust, "disablePlayStoreKidsComplianceInDelay", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustDisablePlayStoreKidsComplianceInDelay);
#endif
}

void UAdjust::GetAdid()
{
#if PLATFORM_ANDROID
    setAdidGetterCallbackMethod(adjustAdidGetterCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAdidId = Env->GetStaticMethodID(jcslAdjust, "getAdid", "(Lcom/adjust/sdk/OnAdidReadListener;)V");
    jclass jcslUeAdidGetterCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeAdidGetterCallback");
    jmethodID jmidUeAdidGetterCallbackInit = Env->GetMethodID(jcslUeAdidGetterCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joAdidGetterCallbackProxy = Env->NewObject(jcslUeAdidGetterCallback, jmidUeAdidGetterCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetAdidId, joAdidGetterCallbackProxy);
    Env->DeleteLocalRef(joAdidGetterCallbackProxy);
#elif PLATFORM_IOS
    [Adjust adidWithCompletionHandler:^(NSString * _Nullable adid) {
        FString fsAdid = FString(UTF8_TO_TCHAR([adid UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [fsAdid]() {
            adjustAdidGetterCallback(fsAdid);
        });
    }];
#endif
}

void UAdjust::IsEnabled()
{
#if PLATFORM_ANDROID
    setIsEnabledCallbackMethod(adjustIsEnabledCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustIsEnabled = Env->GetStaticMethodID(jcslAdjust, "isEnabled", "(Landroid/content/Context;Lcom/adjust/sdk/OnIsEnabledListener;)V");
    jclass jcslUeIsEnabledCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeIsEnabledCallback");
    jmethodID jmidUeIsEnabledCallbackInit = Env->GetMethodID(jcslUeIsEnabledCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joIsEnabledCallbackProxy = Env->NewObject(jcslUeIsEnabledCallback, jmidUeIsEnabledCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustIsEnabled, FJavaWrapper::GameActivityThis, joIsEnabledCallbackProxy);
    Env->DeleteLocalRef(joIsEnabledCallbackProxy);
#elif PLATFORM_IOS
    [Adjust isEnabledWithCompletionHandler:^(BOOL isEnabled) {
        bool bIsEnabled = (bool)isEnabled;
        AsyncTask(ENamedThreads::GameThread, [bIsEnabled]() {
            adjustIsEnabledCallback(bIsEnabled);
        });
    }];
#endif
}

void UAdjust::GetAttribution()
{
#if PLATFORM_ANDROID
    setAttributionGetterCallbackMethod(adjustAttributionGetterCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetAttributionId = Env->GetStaticMethodID(jcslAdjust, "getAttribution", "(Lcom/adjust/sdk/OnAttributionReadListener;)V");
    jclass jcslUeAttributionGetterCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeAttributionGetterCallback");
    jmethodID jmidUeAttributionGetterCallbackInit = Env->GetMethodID(jcslUeAttributionGetterCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joAttributionGetterCallbackProxy = Env->NewObject(jcslUeAttributionGetterCallback, jmidUeAttributionGetterCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetAttributionId, joAttributionGetterCallbackProxy);
    Env->DeleteLocalRef(joAttributionGetterCallbackProxy);
#elif PLATFORM_IOS
    [Adjust attributionWithCompletionHandler:^(ADJAttribution * _Nullable attribution) {
        if (attribution == nil) {
            return;
        }

        FAdjustAttribution ueAttribution;
        ueAttribution.TrackerToken = *FString(attribution.trackerToken);
        ueAttribution.TrackerName = *FString(attribution.trackerName);
        ueAttribution.Network = *FString(attribution.network);
        ueAttribution.Campaign = *FString(attribution.campaign);
        ueAttribution.Adgroup = *FString(attribution.adgroup);
        ueAttribution.Creative = *FString(attribution.creative);
        ueAttribution.ClickLabel = *FString(attribution.clickLabel);
        
        FString fsJsonResponse;
        if (attribution.jsonResponse != nil) {
            NSError *error = nil;
            NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:attribution.jsonResponse options:0 error:&error];
            if (dataJsonResponse != nil && error == nil) {
                NSString *stringJsonResponse = [[NSString alloc] initWithData:dataJsonResponse encoding:NSUTF8StringEncoding];
                if (stringJsonResponse != nil) {
                    fsJsonResponse = *FString(stringJsonResponse);
                }
            }
        }
        ueAttribution.JsonResponse = fsJsonResponse;
        
        AsyncTask(ENamedThreads::GameThread, [ueAttribution]() {
            adjustAttributionGetterCallback(ueAttribution);
        });
    }];
#endif
}

void UAdjust::GetLastDeeplink()
{
#if PLATFORM_IOS
    [Adjust lastDeeplinkWithCompletionHandler:^(NSURL * _Nullable lastDeeplink) {
        FString fsLastDeeplink;
        if (lastDeeplink != nil)
        {
            fsLastDeeplink = FString(UTF8_TO_TCHAR([[lastDeeplink absoluteString] UTF8String]));
        }
        AsyncTask(ENamedThreads::GameThread, [fsLastDeeplink]() {
            adjustLastDeeplinkGetterCallback(fsLastDeeplink);
        });
    }];
#elif PLATFORM_ANDROID
    setLastDeeplinkGetterCallbackMethod(adjustLastDeeplinkGetterCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetLastDeeplink = Env->GetStaticMethodID(jcslAdjust, "getLastDeeplink", "(Landroid/content/Context;Lcom/adjust/sdk/OnLastDeeplinkReadListener;)V");
    jclass jcslUeLastDeeplinkGetterCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeLastDeeplinkGetterCallback");
    jmethodID jmidUeLastDeeplinkGetterCallbackInit = Env->GetMethodID(jcslUeLastDeeplinkGetterCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joLastDeeplinkGetterCallbackProxy = Env->NewObject(jcslUeLastDeeplinkGetterCallback, jmidUeLastDeeplinkGetterCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetLastDeeplink, FJavaWrapper::GameActivityThis, joLastDeeplinkGetterCallbackProxy);
    Env->DeleteLocalRef(joLastDeeplinkGetterCallbackProxy);
#endif
}

void UAdjust::GetSdkVersion()
{
#if PLATFORM_IOS
    FString Separator = FString(UTF8_TO_TCHAR("@"));
    FString SdkPrefix = FString(UTF8_TO_TCHAR("unreal5.4.0"));
    [Adjust sdkVersionWithCompletionHandler:^(NSString * _Nullable sdkVersion) {
        FString fsSdkVersion = SdkPrefix + Separator + FString(UTF8_TO_TCHAR([sdkVersion UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [fsSdkVersion]() {
            adjustSdkVersionGetterCallback(fsSdkVersion);
        });
    }];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    setSdkVersionGetterCallbackMethod(adjustSdkVersionGetterCallback);
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGetSdkVersionId = Env->GetStaticMethodID(jcslAdjust, "getSdkVersion", "(Lcom/adjust/sdk/OnSdkVersionReadListener;)V");
    jclass jcslUeSdkVersionGetterCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeSdkVersionGetterCallback");
    jmethodID jmidUeSdkVersionGetterCallbackInit = Env->GetMethodID(jcslUeSdkVersionGetterCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;Ljava/lang/String;)V");
    // TODO: temp hack, parametrize this
    jstring jSdkPrefix = Env->NewStringUTF("unreal5.4.0");
    jobject joSdkVersionGetterCallbackProxy = Env->NewObject(jcslUeSdkVersionGetterCallback, jmidUeSdkVersionGetterCallbackInit, FJavaWrapper::GameActivityThis, jSdkPrefix);
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGetSdkVersionId, joSdkVersionGetterCallbackProxy);
    Env->DeleteLocalRef(joSdkVersionGetterCallbackProxy);
    Env->DeleteLocalRef(jSdkPrefix);
#endif
}

void UAdjust::EndFirstSessionDelay()
{
#if PLATFORM_IOS
    [Adjust endFirstSessionDelay];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustEndFirstSessionDelay = Env->GetStaticMethodID(jcslAdjust, "endFirstSessionDelay", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustEndFirstSessionDelay);
#endif
}

void UAdjust::EnableCoppaComplianceInDelay()
{
#if PLATFORM_IOS
    [Adjust enableCoppaComplianceInDelay];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustEnableCoppaComplianceInDelay = Env->GetStaticMethodID(jcslAdjust, "enableCoppaComplianceInDelay", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustEnableCoppaComplianceInDelay);
#endif
}

void UAdjust::DisableCoppaComplianceInDelay()
{
#if PLATFORM_IOS
    [Adjust disableCoppaComplianceInDelay];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustDisableCoppaComplianceInDelay = Env->GetStaticMethodID(jcslAdjust, "disableCoppaComplianceInDelay", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustDisableCoppaComplianceInDelay);
#endif
}

void UAdjust::SetExternalDeviceIdInDelay(const FString& ExternalDeviceId)
{
#if PLATFORM_IOS
    CFStringRef cfstrExternalDeviceId = FPlatformString::TCHARToCFString(*ExternalDeviceId);
    NSString *strExternalDeviceId = (NSString *)cfstrExternalDeviceId;
    [Adjust setExternalDeviceIdInDelay:strExternalDeviceId];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustSetExternalDeviceIdInDelay = Env->GetStaticMethodID(jcslAdjust, "setExternalDeviceIdInDelay", "(Ljava/lang/String;)V");
    jstring jExternalDeviceId = Env->NewStringUTF(TCHAR_TO_UTF8(*ExternalDeviceId));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustSetExternalDeviceIdInDelay, jExternalDeviceId);
    Env->DeleteLocalRef(jExternalDeviceId);
#endif
}

void UAdjust::AddGlobalCallbackParameter(const FString& Key, const FString& Value)
{
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*Value);
    NSString *strValue = (NSString *)cfstrValue;
    [Adjust addGlobalCallbackParameter:strValue forKey:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustAddGlobalCallbackParameter = Env->GetStaticMethodID(jcslAdjust, "addGlobalCallbackParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*Value));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustAddGlobalCallbackParameter, jKey, jValue);
    Env->DeleteLocalRef(jKey);
    Env->DeleteLocalRef(jValue);
#endif
}

void UAdjust::AddGlobalPartnerParameter(const FString& Key, const FString& Value)
{
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*Value);
    NSString *strValue = (NSString *)cfstrValue;
    [Adjust addGlobalPartnerParameter:strValue forKey:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustAddGlobalPartnerParameter = Env->GetStaticMethodID(jcslAdjust, "addGlobalPartnerParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*Value));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustAddGlobalPartnerParameter, jKey, jValue);
    Env->DeleteLocalRef(jKey);
    Env->DeleteLocalRef(jValue);
#endif
}

void UAdjust::RemoveGlobalCallbackParameter(const FString& Key)
{
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeGlobalCallbackParameterForKey:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveGlobalCallbackParameter = Env->GetStaticMethodID(jcslAdjust, "removeGlobalCallbackParameter", "(Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveGlobalCallbackParameter, jKey);
    Env->DeleteLocalRef(jKey);
#endif
}

void UAdjust::RemoveGlobalPartnerParameter(const FString& Key)
{
#if PLATFORM_IOS
    CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*Key);
    NSString *strKey = (NSString *)cfstrKey;
    [Adjust removeGlobalPartnerParameterForKey:strKey];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveGlobalPartnerParameter = Env->GetStaticMethodID(jcslAdjust, "removeGlobalPartnerParameter", "(Ljava/lang/String;)V");
    jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveGlobalPartnerParameter, jKey);
    Env->DeleteLocalRef(jKey);
#endif
}

void UAdjust::RemoveGlobalCallbackParameters()
{
#if PLATFORM_IOS
    [Adjust removeGlobalCallbackParameters];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveGlobalCallbackParameters = Env->GetStaticMethodID(jcslAdjust, "removeGlobalCallbackParameters", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveGlobalCallbackParameters);
#endif
}

void UAdjust::RemoveGlobalPartnerParameters()
{
#if PLATFORM_IOS
    [Adjust removeGlobalPartnerParameters];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustRemoveGlobalPartnerParameters = Env->GetStaticMethodID(jcslAdjust, "removeGlobalPartnerParameters", "()V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustRemoveGlobalPartnerParameters);
#endif
}

void UAdjust::GdprForgetMe()
{
#if PLATFORM_IOS
    [Adjust gdprForgetMe];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustGdprForgetMe = Env->GetStaticMethodID(jcslAdjust, "gdprForgetMe", "(Landroid/content/Context;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustGdprForgetMe, FJavaWrapper::GameActivityThis);
#endif
}

void UAdjust::TrackAdRevenue(const FAdjustAdRevenue& AdRevenue)
{
#if PLATFORM_IOS
    // source
    CFStringRef cfstrSource = FPlatformString::TCHARToCFString(*AdRevenue.Source);
    NSString *strSource = (NSString *)cfstrSource;

    ADJAdRevenue *adjustAdRevenue = [[ADJAdRevenue alloc] initWithSource:strSource];

    // revenue & currency
    CFStringRef cfstrCurrency = FPlatformString::TCHARToCFString(*AdRevenue.Currency);
    NSString *strCurrency = (NSString *)cfstrCurrency;
    [adjustAdRevenue setRevenue:(double)AdRevenue.Revenue currency:strCurrency];

    // ad impressions count
    if (AdRevenue.AdImpressionsCount > 0) {
        [adjustAdRevenue setAdImpressionsCount:AdRevenue.AdImpressionsCount];
    }

    // ad revenue network
    CFStringRef cfstrAdRevenueNetwork = FPlatformString::TCHARToCFString(*AdRevenue.AdRevenueNetwork);
    NSString *strAdRevenueNetwork = (NSString *)cfstrAdRevenueNetwork;
    [adjustAdRevenue setAdRevenueNetwork:strAdRevenueNetwork];

    // ad revenue unit
    CFStringRef cfstrAdRevenueUnit = FPlatformString::TCHARToCFString(*AdRevenue.AdRevenueUnit);
    NSString *strAdRevenueUnit = (NSString *)cfstrAdRevenueUnit;
    [adjustAdRevenue setAdRevenueUnit:strAdRevenueUnit];

    // ad revenue placement
    CFStringRef cfstrAdRevenuePlacement = FPlatformString::TCHARToCFString(*AdRevenue.AdRevenuePlacement);
    NSString *strAdRevenuePlacement = (NSString *)cfstrAdRevenuePlacement;
    [adjustAdRevenue setAdRevenuePlacement:strAdRevenuePlacement];

    // callback parameters
    TMap<FString, FString> callbackParams = AdRevenue.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams)
    {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustAdRevenue addCallbackParameter:strKey value:strValue];
    }

    // partner parameters
    TMap<FString, FString> partnerParams = AdRevenue.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams)
    {
        CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*pair.Key);
        NSString *strKey = (NSString *)cfstrKey;
        CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*pair.Value);
        NSString *strValue = (NSString *)cfstrValue;
        [adjustAdRevenue addPartnerParameter:strKey value:strValue];
    }

    // track ad revenue
    [Adjust trackAdRevenue:adjustAdRevenue];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // source
    jstring jSource = Env->NewStringUTF(TCHAR_TO_UTF8(*AdRevenue.Source));

    // create ad revenue object
    jclass jcslAdjustAdRevenue = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustAdRevenue");
    jmethodID jmidAdjustAdRevenueInit = Env->GetMethodID(jcslAdjustAdRevenue, "<init>", "(Ljava/lang/String;)V");
    jobject joAdjustAdRevenue = Env->NewObject(jcslAdjustAdRevenue, jmidAdjustAdRevenueInit, jSource);
    Env->DeleteLocalRef(jSource);

    // revenue & currency
    jclass clsDouble = Env->FindClass("java/lang/Double");
    jmethodID midInit = Env->GetMethodID(clsDouble, "<init>", "(D)V");
    jobject jRevenue = Env->NewObject(clsDouble, midInit, AdRevenue.Revenue);
    jstring jCurrency = Env->NewStringUTF(TCHAR_TO_UTF8(*AdRevenue.Currency));
    jmethodID jmidAdjustAdRevenueSetRevenue = Env->GetMethodID(jcslAdjustAdRevenue, "setRevenue", "(Ljava/lang/Double;Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueSetRevenue, jRevenue, jCurrency);
    Env->DeleteLocalRef(jRevenue);
    Env->DeleteLocalRef(jCurrency);

    // ad impressions count
    jclass clsInteger = Env->FindClass("java/lang/Integer");
    midInit = Env->GetMethodID(clsInteger, "<init>", "(I)V");
    jobject jAdImpressionsCount = Env->NewObject(clsInteger, midInit, AdRevenue.AdImpressionsCount);
    jmethodID jmidAdjustAdRevenueSetAdImpressionsCount = Env->GetMethodID(jcslAdjustAdRevenue, "setAdImpressionsCount", "(Ljava/lang/Integer;)V");
    Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueSetAdImpressionsCount, jAdImpressionsCount);
    Env->DeleteLocalRef(jAdImpressionsCount);

    // ad revenue network
    jstring jAdRevenueNetwork = Env->NewStringUTF(TCHAR_TO_UTF8(*AdRevenue.AdRevenueNetwork));
    jmethodID jmidAdjustAdRevenueSetAdRevenueNetwork = Env->GetMethodID(jcslAdjustAdRevenue, "setAdRevenueNetwork", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueSetAdRevenueNetwork, jAdRevenueNetwork);
    Env->DeleteLocalRef(jAdRevenueNetwork);

    // ad revenue unit
    jstring jAdRevenueUnit = Env->NewStringUTF(TCHAR_TO_UTF8(*AdRevenue.AdRevenueUnit));
    jmethodID jmidAdjustAdRevenueSetAdRevenueUnit = Env->GetMethodID(jcslAdjustAdRevenue, "setAdRevenueUnit", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueSetAdRevenueUnit, jAdRevenueUnit);
    Env->DeleteLocalRef(jAdRevenueUnit);

    // ad revenue placement
    jstring jAdRevenuePlacement = Env->NewStringUTF(TCHAR_TO_UTF8(*AdRevenue.AdRevenuePlacement));
    jmethodID jmidAdjustAdRevenueSetAdRevenuePlacement = Env->GetMethodID(jcslAdjustAdRevenue, "setAdRevenuePlacement", "(Ljava/lang/String;)V");
    Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueSetAdRevenuePlacement, jAdRevenuePlacement);
    Env->DeleteLocalRef(jAdRevenuePlacement);

    // callback parameters
    jmethodID jmidAdjustAdRevenueAddCallbackParameter = Env->GetMethodID(jcslAdjustAdRevenue, "addCallbackParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> callbackParams = AdRevenue.CallbackParameters;
    for (TPair<FString, FString> pair : callbackParams)
    {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueAddCallbackParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // partner parameters
    jmethodID jmidAdjustAdRevenueAddPartnerParameter = Env->GetMethodID(jcslAdjustAdRevenue, "addPartnerParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    TMap<FString, FString> partnerParams = AdRevenue.PartnerParameters;
    for (TPair<FString, FString> pair : partnerParams)
    {
        jstring jKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
        jstring jValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
        Env->CallVoidMethod(joAdjustAdRevenue, jmidAdjustAdRevenueAddPartnerParameter, jKey, jValue);
        Env->DeleteLocalRef(jKey);
        Env->DeleteLocalRef(jValue);
    }

    // track ad revenue
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackAdRevenue = Env->GetStaticMethodID(jcslAdjust, "trackAdRevenue", "(Lcom/adjust/sdk/AdjustAdRevenue;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackAdRevenue, joAdjustAdRevenue);
    Env->DeleteLocalRef(joAdjustAdRevenue);
#endif
}

void UAdjust::TrackThirdPartySharing(const FAdjustThirdPartySharing& ThirdPartySharing)
{
#if PLATFORM_IOS
    // sharing
    EAdjustThirdPartySharingState eSharing = ThirdPartySharing.Sharing;
    NSNumber *sharing = nil;
    switch (eSharing)
    {
        case EAdjustThirdPartySharingState::Enable:
            sharing = @YES;
            break;
        case EAdjustThirdPartySharingState::Disable:
            sharing = @NO;
            break;
    }

    ADJThirdPartySharing *adjustThirdPartySharing = [[ADJThirdPartySharing alloc] initWithIsEnabled:sharing];

    // granular options
    const TMap<FString, FAdjustGranularOption>& GranularOptions = ThirdPartySharing.GranularOptions;
    for (const TPair<FString, FAdjustGranularOption>& GranularOptionPair : GranularOptions)
    {
        CFStringRef cfstrPartner = FPlatformString::TCHARToCFString(*GranularOptionPair.Key);
        NSString *strPartner = (NSString *)cfstrPartner;

        const TMap<FString, FString>& GranularOptionMap = GranularOptionPair.Value.GranularOption;
        for (const TPair<FString, FString>& OptionPair : GranularOptionMap)
        {
            CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*OptionPair.Key);
            NSString *strKey = (NSString *)cfstrKey;

            CFStringRef cfstrValue = FPlatformString::TCHARToCFString(*OptionPair.Value);
            NSString *strValue = (NSString *)cfstrValue;

            [adjustThirdPartySharing addGranularOption:strPartner
                                                   key:strKey
                                                 value:strValue];
        }
    }

    // partner sharing settings
    const TMap<FString, FAdjustPartnerSharingSetting>& PartnerSharingSettings = ThirdPartySharing.PartnerSharingSettings;
    for (const TPair<FString, FAdjustPartnerSharingSetting>& PartnerSettingPair : PartnerSharingSettings)
    {
        CFStringRef cfstrPartner = FPlatformString::TCHARToCFString(*PartnerSettingPair.Key);
        NSString *strPartner = (NSString*) cfstrPartner;

        const TMap<FString, bool>& PartnerSettingMap = PartnerSettingPair.Value.PartnerSharingSetting; // Now TMap<FString, bool>
        for (const TPair<FString, bool>& SettingPair : PartnerSettingMap)
        {
            CFStringRef cfstrKey = FPlatformString::TCHARToCFString(*SettingPair.Key);
            NSString *strKey = (NSString*) cfstrKey;

            [adjustThirdPartySharing addPartnerSharingSetting:strPartner
                                                          key:strKey
                                                        value:SettingPair.Value];
        }
    }

    // track third party sharing
    [Adjust trackThirdPartySharing:adjustThirdPartySharing];
#elif PLATFORM_ANDROID
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();

    // sharing
    jclass jclsBoolean = Env->FindClass("java/lang/Boolean");
    jmethodID jmidValueOf = Env->GetStaticMethodID(jclsBoolean, "valueOf", "(Z)Ljava/lang/Boolean;");
    jobject jIsEnabled = nullptr;
    EAdjustThirdPartySharingState eSharing = ThirdPartySharing.Sharing;
    switch (eSharing)
    {
        case EAdjustThirdPartySharingState::Enable:
            jIsEnabled = Env->CallStaticObjectMethod(jclsBoolean, jmidValueOf, true);
            break;
        case EAdjustThirdPartySharingState::Disable:
            jIsEnabled = Env->CallStaticObjectMethod(jclsBoolean, jmidValueOf, false);
            break;
    }

    // create third party sharing object
    jclass jcslAdjustThirdPartySharing = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustThirdPartySharing");
    jmethodID jmidInit = Env->GetMethodID(jcslAdjustThirdPartySharing, "<init>", "(Ljava/lang/Boolean;)V");
    jobject joAdjustThirdPartySharing = Env->NewObject(jcslAdjustThirdPartySharing, jmidInit, jIsEnabled);
    Env->DeleteLocalRef(jIsEnabled);

    // granular options
    jmethodID jmidAddGranularOption = Env->GetMethodID(jcslAdjustThirdPartySharing, "addGranularOption", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    const TMap<FString, FAdjustGranularOption>& GranularOptions = ThirdPartySharing.GranularOptions;
    for (const TPair<FString, FAdjustGranularOption>& GranularOptionPair : GranularOptions)
    {
        jstring jstrPartnerName = Env->NewStringUTF(TCHAR_TO_UTF8(*GranularOptionPair.Key));
        const TMap<FString, FString>& GranularOptionMap = GranularOptionPair.Value.GranularOption;
        for (const TPair<FString, FString>& OptionPair : GranularOptionMap)
        {
            jstring jstrKey = Env->NewStringUTF(TCHAR_TO_UTF8(*OptionPair.Key));
            jstring jstrValue = Env->NewStringUTF(TCHAR_TO_UTF8(*OptionPair.Value));
            Env->CallVoidMethod(
                joAdjustThirdPartySharing,
                jmidAddGranularOption,
                jstrPartnerName,
                jstrKey,
                jstrValue);
            Env->DeleteLocalRef(jstrKey);
            Env->DeleteLocalRef(jstrValue);
        }
        Env->DeleteLocalRef(jstrPartnerName);
    }

    // partner sharing settings
    jmethodID jmidAddPartnerSharingSetting = Env->GetMethodID(jcslAdjustThirdPartySharing, "addPartnerSharingSetting", "(Ljava/lang/String;Ljava/lang/String;Z)V");
    const TMap<FString, FAdjustPartnerSharingSetting>& PartnerSharingSettings = ThirdPartySharing.PartnerSharingSettings;
    for (const TPair<FString, FAdjustPartnerSharingSetting>& PartnerSettingPair : PartnerSharingSettings)
    {
        jstring jstrPartnerName = Env->NewStringUTF(TCHAR_TO_UTF8(*PartnerSettingPair.Key));
        const TMap<FString, bool>& PartnerSettingMap = PartnerSettingPair.Value.PartnerSharingSetting; // Now TMap<FString, bool>
        for (const TPair<FString, bool>& SettingPair : PartnerSettingMap)
        {
            jstring jstrKey = Env->NewStringUTF(TCHAR_TO_UTF8(*SettingPair.Key));
            Env->CallVoidMethod(
                joAdjustThirdPartySharing,
                jmidAddPartnerSharingSetting,
                jstrPartnerName,
                jstrKey,
                SettingPair.Value);
            Env->DeleteLocalRef(jstrKey);
        }
        Env->DeleteLocalRef(jstrPartnerName);
    }

    // track third party sharing
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jmethodID jmidAdjustTrackThirdPartySharing = Env->GetStaticMethodID(jcslAdjust, "trackThirdPartySharing", "(Lcom/adjust/sdk/AdjustThirdPartySharing;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustTrackThirdPartySharing, joAdjustThirdPartySharing);
    Env->DeleteLocalRef(joAdjustThirdPartySharing);
#endif
}

void UAdjust::RequestAppTrackingAuthorization()
{
#if PLATFORM_IOS
    [Adjust requestAppTrackingAuthorizationWithCompletionHandler:^(NSUInteger status) {
        int nStatus = (int)status;
        AsyncTask(ENamedThreads::GameThread, [nStatus]() {
            adjustRequestAppAuthorizationStatusCallback(nStatus);
        });
    }];
#endif
}

void UAdjust::GetAppTrackingAuthorizationStatus()
{
#if PLATFORM_IOS
    int status = [Adjust appTrackingAuthorizationStatus];
    adjustAuthorizationStatusGetterCallback((int)status);
#endif
}

void UAdjust::UpdateSkanConversionValue(int ConversionValue, const FString& CoarseValue, bool lockWindow)
{
#if PLATFORM_IOS
    CFStringRef cfstrCoarseValue = FPlatformString::TCHARToCFString(*CoarseValue);
    NSString *strCoarseValue = (NSString *)cfstrCoarseValue;
    [Adjust updateSkanConversionValue:ConversionValue
                          coarseValue:strCoarseValue
                           lockWindow:[NSNumber numberWithBool:lockWindow]
                withCompletionHandler:^(NSError * _Nullable error) {
        FString fsError = FString(UTF8_TO_TCHAR([[error localizedDescription] UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [fsError]() {
            adjustUpdateSkanConversionValueCallback(fsError);
        });
    }];
#endif
}

void UAdjust::VerifyAppStorePurchase(const FAdjustAppStorePurchase& Purchase)
{
#if PLATFORM_IOS
    CFStringRef cfstrTransactionId = FPlatformString::TCHARToCFString(*Purchase.TransactionId);
    NSString *strTransactionId = (NSString *)cfstrTransactionId;
    CFStringRef cfstrProductId = FPlatformString::TCHARToCFString(*Purchase.ProductId);
    NSString *strProductId = (NSString *)cfstrProductId;
    
    ADJAppStorePurchase *purchase = [[ADJAppStorePurchase alloc] initWithTransactionId:strTransactionId productId:strProductId];
    [Adjust verifyAppStorePurchase:purchase withCompletionHandler:^(ADJPurchaseVerificationResult * _Nonnull result) {
        FAdjustPurchaseVerificationResult ueResult;
        ueResult.VerificationStatus = FString(UTF8_TO_TCHAR([result.verificationStatus UTF8String]));
        ueResult.Code = result.code;
        ueResult.Message = FString(UTF8_TO_TCHAR([result.message UTF8String]));
        AsyncTask(ENamedThreads::GameThread, [ueResult]() {
            adjustPurchaseVerificationCallback(ueResult);
        });
    }];
#endif
}

void UAdjust::VerifyPlayStorePurchase(const FAdjustPlayStorePurchase& Purchase)
{
#if PLATFORM_ANDROID
    setPurchaseVerificationCallbackMethod(adjustPurchaseVerificationCallback);
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslAdjust = FAndroidApplication::FindJavaClass("com/adjust/sdk/Adjust");
    jclass jcslAdjustPlayStorePurchase = FAndroidApplication::FindJavaClass("com/adjust/sdk/AdjustPlayStorePurchase");
    jmethodID jmidAdjustPlayStorePurchaseInit = Env->GetMethodID(jcslAdjustPlayStorePurchase, "<init>", "(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jProductId = Env->NewStringUTF(TCHAR_TO_UTF8(*Purchase.ProductId));
    jstring jPurchaseToken = Env->NewStringUTF(TCHAR_TO_UTF8(*Purchase.PurchaseToken));
    jobject joPurchase = Env->NewObject(jcslAdjustPlayStorePurchase, jmidAdjustPlayStorePurchaseInit, jProductId, jPurchaseToken);
    jclass jcslUePurchaseVerificationCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUePurchaseVerificationCallback");
    jmethodID jmidUePurchaseVerificationCallbackInit = Env->GetMethodID(jcslUePurchaseVerificationCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject joPurchaseVerificationCallbackProxy = Env->NewObject(jcslUePurchaseVerificationCallback, jmidUePurchaseVerificationCallbackInit, FJavaWrapper::GameActivityThis);
    jmethodID jmidAdjustVerifyPlayStorePurchase = Env->GetStaticMethodID(jcslAdjust, "verifyPlayStorePurchase", "(Lcom/adjust/sdk/AdjustPlayStorePurchase;Lcom/adjust/sdk/OnPurchaseVerificationFinishedListener;)V");
    Env->CallStaticVoidMethod(jcslAdjust, jmidAdjustVerifyPlayStorePurchase, joPurchase, joPurchaseVerificationCallbackProxy);
    Env->DeleteLocalRef(joPurchase);
    Env->DeleteLocalRef(joPurchaseVerificationCallbackProxy);
    Env->DeleteLocalRef(jProductId);
    Env->DeleteLocalRef(jPurchaseToken);
#endif
}
