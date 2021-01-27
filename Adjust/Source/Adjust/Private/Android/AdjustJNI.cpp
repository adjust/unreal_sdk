//
//  AdjustJNI.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 4th October 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#import "AdjustJNI.h"

#if PLATFORM_ANDROID
JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeAttributionCallback_attributionChanged(JNIEnv *env, jobject obj, jobject attributionObject)
{
    if (env->IsSameObject(attributionObject, NULL))
    {
        return;
    }

    FString trackerToken;
    FString trackerName;
    FString network;
    FString campaign;
    FString adgroup;
    FString creative;
    FString clickLabel;
    FString adid;

    jclass clsAdjustAttribution = env->FindClass("com/adjust/sdk/AdjustAttribution");
    jfieldID jfidTrackerTokenID = env->GetFieldID(clsAdjustAttribution, "trackerToken", "Ljava/lang/String;");
    jfieldID jfidTrackerNameID = env->GetFieldID(clsAdjustAttribution, "trackerName", "Ljava/lang/String;");
    jfieldID jfidNetworkID = env->GetFieldID(clsAdjustAttribution, "network", "Ljava/lang/String;");
    jfieldID jfidCampaignID = env->GetFieldID(clsAdjustAttribution, "campaign", "Ljava/lang/String;");
    jfieldID jfidAdgroupID = env->GetFieldID(clsAdjustAttribution, "adgroup", "Ljava/lang/String;");
    jfieldID jfidCreativeID = env->GetFieldID(clsAdjustAttribution, "creative", "Ljava/lang/String;");
    jfieldID jfidClickLabelID = env->GetFieldID(clsAdjustAttribution, "clickLabel", "Ljava/lang/String;");
    jfieldID jfidAdidID = env->GetFieldID(clsAdjustAttribution, "adid", "Ljava/lang/String;");
    jstring jTrackerToken = (jstring)env->GetObjectField(attributionObject, jfidTrackerTokenID);
    jstring jTrackerName = (jstring)env->GetObjectField(attributionObject, jfidTrackerNameID);
    jstring jNetwork = (jstring)env->GetObjectField(attributionObject, jfidNetworkID);
    jstring jCampaign = (jstring)env->GetObjectField(attributionObject, jfidCampaignID);
    jstring jAdgroup = (jstring)env->GetObjectField(attributionObject, jfidAdgroupID);
    jstring jCreative = (jstring)env->GetObjectField(attributionObject, jfidCreativeID);
    jstring jClickLabel = (jstring)env->GetObjectField(attributionObject, jfidClickLabelID);
    jstring jAdid = (jstring)env->GetObjectField(attributionObject, jfidAdidID);

    if (!env->IsSameObject(jTrackerToken, NULL))
    {
        const char *trackerTokenCStr = env->GetStringUTFChars(jTrackerToken, NULL);
        trackerToken = FString(UTF8_TO_TCHAR(trackerTokenCStr));
        env->ReleaseStringUTFChars(jTrackerToken, trackerTokenCStr);
        env->DeleteLocalRef(jTrackerToken);
    }
    else
    {
        trackerToken = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jTrackerName, NULL))
    {
        const char *trackerNameCStr = env->GetStringUTFChars(jTrackerName, NULL);
        trackerName = FString(UTF8_TO_TCHAR(trackerNameCStr));
        env->ReleaseStringUTFChars(jTrackerName, trackerNameCStr);
        env->DeleteLocalRef(jTrackerName);
    }
    else
    {
        trackerName = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jNetwork, NULL))
    {
        const char *networkCStr = env->GetStringUTFChars(jNetwork, NULL);
        network = FString(UTF8_TO_TCHAR(networkCStr));
        env->ReleaseStringUTFChars(jNetwork, networkCStr);
        env->DeleteLocalRef(jNetwork);
    }
    else
    {
        network = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jCampaign, NULL))
    {
        const char *campaignCStr = env->GetStringUTFChars(jCampaign, NULL);
        campaign = FString(UTF8_TO_TCHAR(campaignCStr));
        env->ReleaseStringUTFChars(jCampaign, campaignCStr);
        env->DeleteLocalRef(jCampaign);
    }
    else
    {
        campaign = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdgroup, NULL)) {
        const char *adgroupCStr = env->GetStringUTFChars(jAdgroup, NULL);
        adgroup = FString(UTF8_TO_TCHAR(adgroupCStr));
        env->ReleaseStringUTFChars(jAdgroup, adgroupCStr);
        env->DeleteLocalRef(jAdgroup);
    }
    else
    {
        adgroup = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jCreative, NULL))
    {
        const char *creativeCStr = env->GetStringUTFChars(jCreative, NULL);
        creative = FString(UTF8_TO_TCHAR(creativeCStr));
        env->ReleaseStringUTFChars(jCreative, creativeCStr);
        env->DeleteLocalRef(jCreative);
    }
    else
    {
        creative = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jClickLabel, NULL))
    {
        const char *clickLabelCStr = env->GetStringUTFChars(jClickLabel, NULL);
        clickLabel = FString(UTF8_TO_TCHAR(clickLabelCStr));
        env->ReleaseStringUTFChars(jClickLabel, clickLabelCStr);
        env->DeleteLocalRef(jClickLabel);
    }
    else
    {
        clickLabel = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdid, NULL))
    {
        const char *adidCStr = env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        env->ReleaseStringUTFChars(jAdid, adidCStr);
        env->DeleteLocalRef(jAdid);
    }
    else
    {
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
    attributionCallbackMethod(ueAttribution);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeSessionSuccessCallback_sessionSuccess(JNIEnv *env, jobject obj, jobject sessionSuccessObject)
{
    if (env->IsSameObject(sessionSuccessObject, NULL))
    {
        return;
    }

    FString message;
    FString timestamp;
    FString adid;
    FString eventToken;
    FString jsonResponse;

    jclass clsAdjustSessionSuccess = env->FindClass("com/adjust/sdk/AdjustSessionSuccess");
    jfieldID jfidMessageID = env->GetFieldID(clsAdjustSessionSuccess, "message", "Ljava/lang/String;");
    jfieldID jfidTimestampID = env->GetFieldID(clsAdjustSessionSuccess, "timestamp", "Ljava/lang/String;");
    jfieldID jfidAdidID = env->GetFieldID(clsAdjustSessionSuccess, "adid", "Ljava/lang/String;");
    jfieldID jfidJsonResponseID = env->GetFieldID(clsAdjustSessionSuccess, "jsonResponse", "Lorg/json/JSONObject;");
    jstring jMessage = (jstring)env->GetObjectField(sessionSuccessObject, jfidMessageID);
    jstring jTimestamp = (jstring)env->GetObjectField(sessionSuccessObject, jfidTimestampID);
    jstring jAdid = (jstring)env->GetObjectField(sessionSuccessObject, jfidAdidID);
    jobject joJsonResponse = (jobject)env->GetObjectField(sessionSuccessObject, jfidJsonResponseID);
    jstring jJsonResponse;

    if (!env->IsSameObject(jMessage, NULL))
    {
        const char *messageCStr = env->GetStringUTFChars(jMessage, NULL);
        message = FString(UTF8_TO_TCHAR(messageCStr));
        env->ReleaseStringUTFChars(jMessage, messageCStr);
        env->DeleteLocalRef(jMessage);
    }
    else
    {
        message = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jTimestamp, NULL))
    {
        const char *timestampCStr = env->GetStringUTFChars(jTimestamp, NULL);
        timestamp = FString(UTF8_TO_TCHAR(timestampCStr));
        env->ReleaseStringUTFChars(jTimestamp, timestampCStr);
        env->DeleteLocalRef(jTimestamp);
    }
    else
    {
        timestamp = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdid, NULL))
    {
        const char *adidCStr = env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        env->ReleaseStringUTFChars(jAdid, adidCStr);
        env->DeleteLocalRef(jAdid);
    }
    else
    {
        adid = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(joJsonResponse, NULL))
    {
        jclass jcJsonObject = env->FindClass("org/json/JSONObject");
        jmethodID jToStringID = env->GetMethodID(jcJsonObject, "toString", "()Ljava/lang/String;");
        jJsonResponse = (jstring)env->CallObjectMethod(joJsonResponse, jToStringID);

        if (!env->IsSameObject(jJsonResponse, NULL))
        {
            const char *jsonResponseCStr = env->GetStringUTFChars(jJsonResponse, NULL);
            jsonResponse = FString(UTF8_TO_TCHAR(jsonResponseCStr));
            env->ReleaseStringUTFChars(jJsonResponse, jsonResponseCStr);
            env->DeleteLocalRef(jJsonResponse);
        }
        else
        {
            jsonResponse = FString(UTF8_TO_TCHAR(""));
        }
    }

    FAdjustSessionSuccess ueSessionSuccess;
    ueSessionSuccess.Message = message;
    ueSessionSuccess.Timestamp = timestamp;
    ueSessionSuccess.Adid = adid;
    ueSessionSuccess.JsonResponse = jsonResponse;
    sessionSuccessCallbackMethod(ueSessionSuccess);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeSessionFailureCallback_sessionFailure(JNIEnv *env, jobject obj, jobject sessionFailureObject)
{
    if (env->IsSameObject(sessionFailureObject, NULL))
    {
        return;
    }

    FString message;
    FString timestamp;
    FString adid;
    FString jsonResponse;
    bool willRetry;

    jclass clsAdjustSessionFailure = env->FindClass("com/adjust/sdk/AdjustSessionFailure");
    jfieldID jfidMessageID = env->GetFieldID(clsAdjustSessionFailure, "message", "Ljava/lang/String;");
    jfieldID jfidTimestampID = env->GetFieldID(clsAdjustSessionFailure, "timestamp", "Ljava/lang/String;");
    jfieldID jfidAdidID = env->GetFieldID(clsAdjustSessionFailure, "adid", "Ljava/lang/String;");
    jfieldID jfidWillRetryID = env->GetFieldID(clsAdjustSessionFailure, "willRetry", "Z");
    jfieldID jfidJsonResponseID = env->GetFieldID(clsAdjustSessionFailure, "jsonResponse", "Lorg/json/JSONObject;");
    jstring jMessage = (jstring)env->GetObjectField(sessionFailureObject, jfidMessageID);
    jstring jTimestamp = (jstring)env->GetObjectField(sessionFailureObject, jfidTimestampID);
    jstring jAdid = (jstring)env->GetObjectField(sessionFailureObject, jfidAdidID);
    jboolean joWillRetry = env->GetBooleanField(sessionFailureObject, jfidWillRetryID);
    jobject joJsonResponse = env->GetObjectField(sessionFailureObject, jfidJsonResponseID);
    jstring jJsonResponse;

    if (!env->IsSameObject(jMessage, NULL))
    {
        const char *messageCStr = env->GetStringUTFChars(jMessage, NULL);
        message = FString(UTF8_TO_TCHAR(messageCStr));
        env->ReleaseStringUTFChars(jMessage, messageCStr);
        env->DeleteLocalRef(jMessage);
    }
    else
    {
        message = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jTimestamp, NULL))
    {
        const char *timestampCStr = env->GetStringUTFChars(jTimestamp, NULL);
        timestamp = FString(UTF8_TO_TCHAR(timestampCStr));
        env->ReleaseStringUTFChars(jTimestamp, timestampCStr);
        env->DeleteLocalRef(jTimestamp);
    }
    else
    {
        timestamp = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdid, NULL))
    {
        const char *adidCStr = env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        env->ReleaseStringUTFChars(jAdid, adidCStr);
        env->DeleteLocalRef(jAdid);
    }
    else
    {
        adid = FString(UTF8_TO_TCHAR(""));
    }

    willRetry = JNI_TRUE == joWillRetry;

    if (!env->IsSameObject(joJsonResponse, NULL))
    {
        jclass jcJsonObject = env->FindClass("org/json/JSONObject");
        jmethodID jToStringID = env->GetMethodID(jcJsonObject, "toString", "()Ljava/lang/String;");
        jJsonResponse = (jstring)env->CallObjectMethod(joJsonResponse, jToStringID);

        if (!env->IsSameObject(jJsonResponse, NULL))
        {
            const char *jsonResponseCStr = env->GetStringUTFChars(jJsonResponse, NULL);
            jsonResponse = FString(UTF8_TO_TCHAR(jsonResponseCStr));
            env->ReleaseStringUTFChars(jJsonResponse, jsonResponseCStr);
            env->DeleteLocalRef(jJsonResponse);
        }
        else
        {
            jsonResponse = FString(UTF8_TO_TCHAR(""));
        }
    }

    FAdjustSessionFailure ueSessionFailure;
    ueSessionFailure.Message = message;
    ueSessionFailure.Timestamp = timestamp;
    ueSessionFailure.Adid = adid;
    ueSessionFailure.WillRetry = willRetry;
    ueSessionFailure.JsonResponse = jsonResponse;
    sessionFailureCallbackMethod(ueSessionFailure);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeEventSuccessCallback_eventSuccess(JNIEnv *env, jobject obj, jobject eventSuccessObject)
{
    if (env->IsSameObject(eventSuccessObject, NULL))
    {
        return;
    }

    FString message;
    FString timestamp;
    FString adid;
    FString eventToken;
    FString callbackId;
    FString jsonResponse;

    jclass clsAdjustEventSuccess = env->FindClass("com/adjust/sdk/AdjustEventSuccess");
    jfieldID jfidMessageID = env->GetFieldID(clsAdjustEventSuccess, "message", "Ljava/lang/String;");
    jfieldID jfidTimestampID = env->GetFieldID(clsAdjustEventSuccess, "timestamp", "Ljava/lang/String;");
    jfieldID jfidAdidID = env->GetFieldID(clsAdjustEventSuccess, "adid", "Ljava/lang/String;");
    jfieldID jfidEventTokenID = env->GetFieldID(clsAdjustEventSuccess, "eventToken", "Ljava/lang/String;");
    jfieldID jfidCallbackIdID = env->GetFieldID(clsAdjustEventSuccess, "callbackId", "Ljava/lang/String;");
    jfieldID jfidJsonResponseID = env->GetFieldID(clsAdjustEventSuccess, "jsonResponse", "Lorg/json/JSONObject;");
    jstring jMessage = (jstring)env->GetObjectField(eventSuccessObject, jfidMessageID);
    jstring jTimestamp = (jstring)env->GetObjectField(eventSuccessObject, jfidTimestampID);
    jstring jAdid = (jstring)env->GetObjectField(eventSuccessObject, jfidAdidID);
    jstring jEventToken = (jstring)env->GetObjectField(eventSuccessObject, jfidEventTokenID);
    jstring jCallbackId = (jstring)env->GetObjectField(eventSuccessObject, jfidCallbackIdID);
    jobject joJsonResponse = (jobject)env->GetObjectField(eventSuccessObject, jfidJsonResponseID);
    jstring jJsonResponse;

    if (!env->IsSameObject(jMessage, NULL))
    {
        const char *messageCStr = env->GetStringUTFChars(jMessage, NULL);
        message = FString(UTF8_TO_TCHAR(messageCStr));
        env->ReleaseStringUTFChars(jMessage, messageCStr);
        env->DeleteLocalRef(jMessage);
    }
    else
    {
        message = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jTimestamp, NULL))
    {
        const char *timestampCStr = env->GetStringUTFChars(jTimestamp, NULL);
        timestamp = FString(UTF8_TO_TCHAR(timestampCStr));
        env->ReleaseStringUTFChars(jTimestamp, timestampCStr);
        env->DeleteLocalRef(jTimestamp);
    }
    else
    {
        timestamp = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdid, NULL))
    {
        const char *adidCStr = env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        env->ReleaseStringUTFChars(jAdid, adidCStr);
        env->DeleteLocalRef(jAdid);
    }
    else
    {
        adid = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jEventToken, NULL))
    {
        const char *eventTokenCStr = env->GetStringUTFChars(jEventToken, NULL);
        eventToken = FString(UTF8_TO_TCHAR(eventTokenCStr));
        env->ReleaseStringUTFChars(jEventToken, eventTokenCStr);
        env->DeleteLocalRef(jEventToken);
    }
    else
    {
        eventToken = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jCallbackId, NULL))
    {
        const char *callbackIdCStr = env->GetStringUTFChars(jCallbackId, NULL);
        callbackId = FString(UTF8_TO_TCHAR(callbackIdCStr));
        env->ReleaseStringUTFChars(jCallbackId, callbackIdCStr);
        env->DeleteLocalRef(jCallbackId);
    }
    else
    {
        callbackId = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(joJsonResponse, NULL))
    {
        jclass jcJsonObject = env->FindClass("org/json/JSONObject");
        jmethodID jToStringID = env->GetMethodID(jcJsonObject, "toString", "()Ljava/lang/String;");
        jJsonResponse = (jstring)env->CallObjectMethod(joJsonResponse, jToStringID);

        if (!env->IsSameObject(jJsonResponse, NULL))
        {
            const char *jsonResponseCStr = env->GetStringUTFChars(jJsonResponse, NULL);
            jsonResponse = FString(UTF8_TO_TCHAR(jsonResponseCStr));
            env->ReleaseStringUTFChars(jJsonResponse, jsonResponseCStr);
            env->DeleteLocalRef(jJsonResponse);
        }
        else
        {
            jsonResponse = FString(UTF8_TO_TCHAR(""));
        }
    }

    FAdjustEventSuccess ueEventSuccess;
    ueEventSuccess.Message = message;
    ueEventSuccess.Timestamp = timestamp;
    ueEventSuccess.Adid = adid;
    ueEventSuccess.EventToken = eventToken;
    ueEventSuccess.CallbackId = callbackId;
    ueEventSuccess.JsonResponse = jsonResponse;
    eventSuccessCallbackMethod(ueEventSuccess);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeEventFailureCallback_eventFailure(JNIEnv *env, jobject obj, jobject eventFailureObject)
{
    if (env->IsSameObject(eventFailureObject, NULL))
    {
        return;
    }

    FString message;
    FString timestamp;
    FString adid;
    FString eventToken;
    FString callbackId;
    FString jsonResponse;
    bool willRetry;

    jclass clsAdjustEventFailure = env->FindClass("com/adjust/sdk/AdjustEventFailure");
    jfieldID jfidMessageID = env->GetFieldID(clsAdjustEventFailure, "message", "Ljava/lang/String;");
    jfieldID jfidTimestampID = env->GetFieldID(clsAdjustEventFailure, "timestamp", "Ljava/lang/String;");
    jfieldID jfidAdidID = env->GetFieldID(clsAdjustEventFailure, "adid", "Ljava/lang/String;");
    jfieldID jfidEventTokenID = env->GetFieldID(clsAdjustEventFailure, "eventToken", "Ljava/lang/String;");
    jfieldID jfidCallbackIdID = env->GetFieldID(clsAdjustEventFailure, "callbackId", "Ljava/lang/String;");
    jfieldID jfidWillRetryID = env->GetFieldID(clsAdjustEventFailure, "willRetry", "Z");
    jfieldID jfidJsonResponseID = env->GetFieldID(clsAdjustEventFailure, "jsonResponse", "Lorg/json/JSONObject;");
    jstring jMessage = (jstring)env->GetObjectField(eventFailureObject, jfidMessageID);
    jstring jTimestamp = (jstring)env->GetObjectField(eventFailureObject, jfidTimestampID);
    jstring jAdid = (jstring)env->GetObjectField(eventFailureObject, jfidAdidID);
    jstring jEventToken = (jstring)env->GetObjectField(eventFailureObject, jfidEventTokenID);
    jstring jCallbackId = (jstring)env->GetObjectField(eventFailureObject, jfidCallbackIdID);
    jboolean joWillRetry = env->GetBooleanField(eventFailureObject, jfidWillRetryID);
    jobject joJsonResponse = env->GetObjectField(eventFailureObject, jfidJsonResponseID);
    jstring jJsonResponse;

    if (!env->IsSameObject(jMessage, NULL))
    {
        const char *messageCStr = env->GetStringUTFChars(jMessage, NULL);
        message = FString(UTF8_TO_TCHAR(messageCStr));
        env->ReleaseStringUTFChars(jMessage, messageCStr);
        env->DeleteLocalRef(jMessage);
    }
    else
    {
        message = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jTimestamp, NULL))
    {
        const char *timestampCStr = env->GetStringUTFChars(jTimestamp, NULL);
        timestamp = FString(UTF8_TO_TCHAR(timestampCStr));
        env->ReleaseStringUTFChars(jTimestamp, timestampCStr);
        env->DeleteLocalRef(jTimestamp);
    }
    else
    {
        timestamp = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jAdid, NULL))
    {
        const char *adidCStr = env->GetStringUTFChars(jAdid, NULL);
        adid = FString(UTF8_TO_TCHAR(adidCStr));
        env->ReleaseStringUTFChars(jAdid, adidCStr);
        env->DeleteLocalRef(jAdid);
    }
    else
    {
        adid = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jEventToken, NULL)) {
        const char *eventTokenCStr = env->GetStringUTFChars(jEventToken, NULL);
        eventToken = FString(UTF8_TO_TCHAR(eventTokenCStr));
        env->ReleaseStringUTFChars(jEventToken, eventTokenCStr);
        env->DeleteLocalRef(jEventToken);
    }
    else
    {
        eventToken = FString(UTF8_TO_TCHAR(""));
    }

    if (!env->IsSameObject(jCallbackId, NULL))
    {
        const char *callbackIdCStr = env->GetStringUTFChars(jCallbackId, NULL);
        callbackId = FString(UTF8_TO_TCHAR(callbackIdCStr));
        env->ReleaseStringUTFChars(jCallbackId, callbackIdCStr);
        env->DeleteLocalRef(jCallbackId);
    }
    else
    {
        callbackId = FString(UTF8_TO_TCHAR(""));
    }

    willRetry = JNI_TRUE == joWillRetry;

    if (!env->IsSameObject(joJsonResponse, NULL))
    {
        jclass jcJsonObject = env->FindClass("org/json/JSONObject");
        jmethodID jToStringID = env->GetMethodID(jcJsonObject, "toString", "()Ljava/lang/String;");
        jJsonResponse = (jstring)env->CallObjectMethod(joJsonResponse, jToStringID);

        if (!env->IsSameObject(jJsonResponse, NULL))
        {
            const char *jsonResponseCStr = env->GetStringUTFChars(jJsonResponse, NULL);
            jsonResponse = FString(UTF8_TO_TCHAR(jsonResponseCStr));
            env->ReleaseStringUTFChars(jJsonResponse, jsonResponseCStr);
            env->DeleteLocalRef(jJsonResponse);
        }
        else
        {
            jsonResponse = FString(UTF8_TO_TCHAR(""));
        }
    }

    FAdjustEventFailure ueEventFailure;
    ueEventFailure.Message = message;
    ueEventFailure.Timestamp = timestamp;
    ueEventFailure.Adid = adid;
    ueEventFailure.EventToken = eventToken;
    ueEventFailure.CallbackId = callbackId;
    ueEventFailure.WillRetry = willRetry;
    ueEventFailure.JsonResponse = jsonResponse;
    eventFailureCallbackMethod(ueEventFailure);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeDeferredDeeplinkCallback_deferredDeeplinkReceived(JNIEnv *env, jobject obj, jstring jDeeplink)
{
    if (env->IsSameObject(jDeeplink, NULL))
    {
        return;
    }

    const char *deeplinkCStr = env->GetStringUTFChars(jDeeplink, NULL);
    FString deeplink = FString(UTF8_TO_TCHAR(deeplinkCStr));
    deferredDeeplinkCallbackMethod(deeplink);
    env->ReleaseStringUTFChars(jDeeplink, deeplinkCStr);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024AdjustUeGoogleAdvertisingIdCallback_googleAdvertisingIdRead(JNIEnv *env, jobject obj, jstring jGoogleAdId)
{
    if (env->IsSameObject(jGoogleAdId, NULL))
    {
        return;
    }

    const char *googleAdIdCStr = env->GetStringUTFChars(jGoogleAdId, NULL);
    FString googleAdId = FString(UTF8_TO_TCHAR(googleAdIdCStr));
    googleAdvertisingIdCallbackMethod(googleAdId);
    env->ReleaseStringUTFChars(jGoogleAdId, googleAdIdCStr);    
}

void setAttributionCallbackMethod(void (*callbackMethod)(FAdjustAttribution Attribution))
{
    if (NULL == attributionCallbackMethod)
    {
        attributionCallbackMethod = callbackMethod;
    }
}

void setSessionSuccessCallbackMethod(void (*callbackMethod)(FAdjustSessionSuccess SessionSuccess))
{
    if (NULL == sessionSuccessCallbackMethod)
    {
        sessionSuccessCallbackMethod = callbackMethod;
    }
}

void setSessionFailureCallbackMethod(void (*callbackMethod)(FAdjustSessionFailure SessionFailure))
{
    if (NULL == sessionFailureCallbackMethod)
    {
        sessionFailureCallbackMethod = callbackMethod;
    }
}

void setEventSuccessCallbackMethod(void (*callbackMethod)(FAdjustEventSuccess EventSuccess))
{
    if (NULL == eventSuccessCallbackMethod)
    {
        eventSuccessCallbackMethod = callbackMethod;
    }
}

void setEventFailureCallbackMethod(void (*callbackMethod)(FAdjustEventFailure EventFailure))
{
    if (NULL == eventFailureCallbackMethod)
    {
        eventFailureCallbackMethod = callbackMethod;
    }
}

void setDeferredDeeplinkCallbackMethod(void (*callbackMethod)(FString Deeplink))
{
    if (NULL == deferredDeeplinkCallbackMethod)
    {
        deferredDeeplinkCallbackMethod = callbackMethod;
    }
}

void setGoogleAdvertisingIdCallbackMethod(void (*callbackMethod)(FString GoogleAdId))
{
    if (NULL == googleAdvertisingIdCallbackMethod)
    {
        googleAdvertisingIdCallbackMethod = callbackMethod;
    }
}
#endif
