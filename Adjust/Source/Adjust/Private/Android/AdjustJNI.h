//
//  AdjustJNI.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 4th October 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#pragma once

#if PLATFORM_ANDROID

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "../Public/AdjustAttribution.h"
#include "../Public/AdjustEventSuccess.h"
#include "../Public/AdjustEventFailure.h"
#include "../Public/AdjustSessionSuccess.h"
#include "../Public/AdjustSessionFailure.h"

extern "C"
{
    static void (*attributionCallbackMethod)(FAdjustAttribution Attribution);
    static void (*sessionSuccessCallbackMethod)(FAdjustSessionSuccess SessionSuccess);
    static void (*sessionFailureCallbackMethod)(FAdjustSessionFailure SessionFailure);
    static void (*eventSuccessCallbackMethod)(FAdjustEventSuccess EventSuccess);
    static void (*eventFailureCallbackMethod)(FAdjustEventFailure EventFailure);
    static void (*deferredDeeplinkCallbackMethod)(FString Deeplink);
    static void (*isEnabledCallbackMethod)(bool IsEnabled);
    static void (*adidGetterCallbackMethod)(FString Adid);
    static void (*sdkVersionGetterCallbackMethod)(FString Adid);
    static void (*deeplinkResolutionCallbackMethod)(FString ResolvedLink);
    static void (*lastDeeplinkGetterCallbackMethod)(FString LastDeeplink);
    static void (*attributionGetterCallbackMethod)(FAdjustAttribution Attribution);
    static void (*googleAdIdGetterCallbackMethod)(FString GoogleAdId);
    static void (*amazonAdIdGetterCallbackMethod)(FString AmazonAdId);

    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAttributionCallback_attributionChanged(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSessionSuccessCallback_sessionSuccess(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSessionFailureCallback_sessionFailure(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeEventSuccessCallback_eventSuccess(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeEventFailureCallback_eventFailure(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeDeferredDeeplinkCallback_deferredDeeplinkReceived(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeIsEnabledCallback_isEnabledRead(JNIEnv*, jobject, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAdidGetterCallback_adidRead(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAttributionGetterCallback_attributionRead(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSdkVersionGetterCallback_sdkVersionRead(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeDeeplinkResolvedCallback_deeplinkResolved(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeLastDeeplinkGetterCallback_lastDeeplinkRead(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeGoogleAdIdGetterCallback_googleAdIdRead(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAmazonAdIdGetterCallback_amazonAdIdRead(JNIEnv*, jobject, jstring);

    void setAttributionCallbackMethod(void (*callbackMethod)(FAdjustAttribution Attribution));
    void setSessionSuccessCallbackMethod(void (*callbackMethod)(FAdjustSessionSuccess SessionSuccess));
    void setSessionFailureCallbackMethod(void (*callbackMethod)(FAdjustSessionFailure SessionFailure));
    void setEventSuccessCallbackMethod(void (*callbackMethod)(FAdjustEventSuccess EventSuccess));
    void setEventFailureCallbackMethod(void (*callbackMethod)(FAdjustEventFailure EventFailure));
    void setDeferredDeeplinkCallbackMethod(void (*callbackMethod)(FString Deeplink));
    void setIsEnabledCallbackMethod(void (*callbackMethod)(bool IsEnabled));
    void setAdidGetterCallbackMethod(void (*callbackMethod)(FString Adid));
    void setAttributionGetterCallbackMethod(void (*callbackMethod)(FAdjustAttribution Attribution));
    void setSdkVersionGetterCallbackMethod(void (*callbackMethod)(FString SdkVersion));
    void setDeeplinkResolutionCallback(void (*callbackMethod)(FString ResolvedLink));
    void setLastDeeplinkGetterCallbackMethod(void (*callbackMethod)(FString LastDeeplink));
    void setGoogleAdIdGetterCallbackMethod(void (*callbackMethod)(FString GoogleAdId));
    void setAmazonAdIdGetterCallbackMethod(void (*callbackMethod)(FString AmazonAdId));
}

#endif
