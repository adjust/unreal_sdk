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
    static void (*googleAdvertisingIdCallbackMethod)(FString GoogleAdId);

    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeAttributionCallback_attributionChanged(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeSessionSuccessCallback_sessionSuccess(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeSessionFailureCallback_sessionFailure(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeEventSuccessCallback_eventSuccess(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeEventFailureCallback_eventFailure(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeDeferredDeeplinkCallback_deferredDeeplinkReceived(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeGoogleAdvertisingIdCallback_googleAdvertisingIdRead(JNIEnv*, jobject, jstring);

    void setAttributionCallbackMethod(void (*callbackMethod)(FAdjustAttribution Attribution));
    void setSessionSuccessCallbackMethod(void (*callbackMethod)(FAdjustSessionSuccess SessionSuccess));
    void setSessionFailureCallbackMethod(void (*callbackMethod)(FAdjustSessionFailure SessionFailure));
    void setEventSuccessCallbackMethod(void (*callbackMethod)(FAdjustEventSuccess EventSuccess));
    void setEventFailureCallbackMethod(void (*callbackMethod)(FAdjustEventFailure EventFailure));
    void setDeferredDeeplinkCallbackMethod(void (*callbackMethod)(FString Deeplink));
    void setGoogleAdvertisingIdCallbackMethod(void (*callbackMethod)(FString GoogleAdId));
}

#endif
