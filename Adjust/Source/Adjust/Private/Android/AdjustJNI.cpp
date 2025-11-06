//
//  AdjustJNI.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 4th October 2018.
//  Copyright © 2018-2021 Adjust GmbH. All rights reserved.
//

#include "AdjustJNI.h"

#if PLATFORM_ANDROID
JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAttributionCallback_attributionChanged(
    JNIEnv* env, jobject obj, jobject attributionObject)
{
    // Ensure the attributionObject is not null
    if (attributionObject == nullptr)
    {
        return;
    }

    // Get the AdjustAttribution class
    jclass attributionClass = env->GetObjectClass(attributionObject);
    if (attributionClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(attributionClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(attributionObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Helper function to get double fields
    auto getDoubleField = [&](const char* fieldName) -> double {
        jfieldID fieldId = env->GetFieldID(attributionClass, fieldName, "Ljava/lang/Double;");
        if (fieldId == nullptr)
        {
            return 0.0;
        }
        jobject doubleObj = env->GetObjectField(attributionObject, fieldId);
        if (doubleObj == nullptr)
        {
            return 0.0;
        }
        jclass doubleClass = env->GetObjectClass(doubleObj);
        jmethodID doubleValueMethod = env->GetMethodID(doubleClass, "doubleValue", "()D");
        double value = env->CallDoubleMethod(doubleObj, doubleValueMethod);
        env->DeleteLocalRef(doubleObj);
        env->DeleteLocalRef(doubleClass);
        return value;
    };

    // Extract all fields
    FString trackerToken = getStringField("trackerToken");
    FString trackerName = getStringField("trackerName");
    FString network = getStringField("network");
    FString campaign = getStringField("campaign");
    FString adgroup = getStringField("adgroup");
    FString creative = getStringField("creative");
    FString clickLabel = getStringField("clickLabel");
    FString costType = getStringField("costType");
    double costAmount = getDoubleField("costAmount");
    FString costCurrency = getStringField("costCurrency");
    FString fbInstallReferrer = getStringField("fbInstallReferrer");
    FString fsJsonResponse = getStringField("jsonResponse");

    AsyncTask(ENamedThreads::GameThread, [
        trackerToken,
        trackerName,
        network,
        campaign,
        adgroup,
        creative,
        clickLabel,
        costType,
        costAmount,
        costCurrency,
        fbInstallReferrer,
        fsJsonResponse]()
    {
        FAdjustAttribution ueAttribution;
        ueAttribution.TrackerToken = trackerToken;
        ueAttribution.TrackerName = trackerName;
        ueAttribution.Network = network;
        ueAttribution.Campaign = campaign;
        ueAttribution.Adgroup = adgroup;
        ueAttribution.Creative = creative;
        ueAttribution.ClickLabel = clickLabel;
        ueAttribution.CostType = costType;
        ueAttribution.CostAmount = costAmount;
        ueAttribution.CostCurrency = costCurrency;
        ueAttribution.FbInstallReferrer = fbInstallReferrer;
        ueAttribution.JsonResponse = fsJsonResponse;
        attributionCallbackMethod(ueAttribution);
    });

    // Clean up local references
    env->DeleteLocalRef(attributionClass);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSessionSuccessCallback_sessionSuccess(
    JNIEnv* env, jobject obj, jobject sessionSuccessObject)
{
    // Ensure the sessionSuccessObject is not null
    if (sessionSuccessObject == nullptr)
    {
        return;
    }

    // Get the AdjustSessionSuccess class
    jclass sessionSuccessClass = env->GetObjectClass(sessionSuccessObject);
    if (sessionSuccessClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(sessionSuccessClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(sessionSuccessObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Extract fields
    FString message = getStringField("message");
    FString timestamp = getStringField("timestamp");
    FString adid = getStringField("adid");

    // Extract jsonResponse field
    jfieldID jsonResponseFieldId = env->GetFieldID(sessionSuccessClass, "jsonResponse", "Lorg/json/JSONObject;");
    FString jsonResponseString;
    if (jsonResponseFieldId != nullptr)
    {
        jobject jsonResponseObject = env->GetObjectField(sessionSuccessObject, jsonResponseFieldId);
        if (jsonResponseObject != nullptr)
        {
            jclass jsonObjectClass = env->GetObjectClass(jsonResponseObject);
            jmethodID toStringMethodId = env->GetMethodID(jsonObjectClass, "toString", "()Ljava/lang/String;");
            if (toStringMethodId != nullptr)
            {
                jstring jsonString = (jstring)env->CallObjectMethod(jsonResponseObject, toStringMethodId);
                if (jsonString != nullptr)
                {
                    const char* cStr = env->GetStringUTFChars(jsonString, nullptr);
                    jsonResponseString = FString(UTF8_TO_TCHAR(cStr));
                    env->ReleaseStringUTFChars(jsonString, cStr);
                    env->DeleteLocalRef(jsonString);
                }
            }
            env->DeleteLocalRef(jsonObjectClass);
            env->DeleteLocalRef(jsonResponseObject);
        }
    }

    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, jsonResponseString]()
    {
        FAdjustSessionSuccess ueSessionSuccess;
        ueSessionSuccess.Message = message;
        ueSessionSuccess.Timestamp = timestamp;
        ueSessionSuccess.Adid = adid;
        ueSessionSuccess.JsonResponse = jsonResponseString;
        sessionSuccessCallbackMethod(ueSessionSuccess);
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSessionFailureCallback_sessionFailure(
    JNIEnv* env, jobject obj, jobject sessionFailureObject)
{
    // Ensure the sessionFailureObject is not null
    if (sessionFailureObject == nullptr)
    {
        return;
    }

    // Get the AdjustSessionFailure class
    jclass sessionFailureClass = env->GetObjectClass(sessionFailureObject);
    if (sessionFailureClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(sessionFailureClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(sessionFailureObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Extract fields
    FString message = getStringField("message");
    FString timestamp = getStringField("timestamp");
    FString adid = getStringField("adid");

    // Extract willRetry field
    jfieldID willRetryFieldId = env->GetFieldID(sessionFailureClass, "willRetry", "Z");
    bool willRetry = false;
    if (willRetryFieldId != nullptr)
    {
        willRetry = env->GetBooleanField(sessionFailureObject, willRetryFieldId);
    }

    // Extract jsonResponse field
    jfieldID jsonResponseFieldId = env->GetFieldID(sessionFailureClass, "jsonResponse", "Lorg/json/JSONObject;");
    FString jsonResponseString;
    if (jsonResponseFieldId != nullptr)
    {
        jobject jsonResponseObject = env->GetObjectField(sessionFailureObject, jsonResponseFieldId);
        if (jsonResponseObject != nullptr)
        {
            jclass jsonObjectClass = env->GetObjectClass(jsonResponseObject);
            jmethodID toStringMethodId = env->GetMethodID(jsonObjectClass, "toString", "()Ljava/lang/String;");
            if (toStringMethodId != nullptr)
            {
                jstring jsonString = (jstring)env->CallObjectMethod(jsonResponseObject, toStringMethodId);
                if (jsonString != nullptr)
                {
                    const char* cStr = env->GetStringUTFChars(jsonString, nullptr);
                    jsonResponseString = FString(UTF8_TO_TCHAR(cStr));
                    env->ReleaseStringUTFChars(jsonString, cStr);
                    env->DeleteLocalRef(jsonString);
                }
            }
            env->DeleteLocalRef(jsonObjectClass);
            env->DeleteLocalRef(jsonResponseObject);
        }
    }

    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, willRetry, jsonResponseString]()
    {
        FAdjustSessionFailure ueSessionFailure;
        ueSessionFailure.Message = message;
        ueSessionFailure.Timestamp = timestamp;
        ueSessionFailure.Adid = adid;
        ueSessionFailure.WillRetry = willRetry;
        ueSessionFailure.JsonResponse = jsonResponseString;
        sessionFailureCallbackMethod(ueSessionFailure);
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeEventSuccessCallback_eventSuccess(
    JNIEnv* env, jobject obj, jobject eventSuccessObject)
{
    // Ensure the eventSuccessObject is not null
    if (eventSuccessObject == nullptr)
    {
        return;
    }

    // Get the AdjustEventSuccess class
    jclass eventSuccessClass = env->GetObjectClass(eventSuccessObject);
    if (eventSuccessClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(eventSuccessClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(eventSuccessObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Extract fields
    FString eventToken = getStringField("eventToken");
    FString message = getStringField("message");
    FString adid = getStringField("adid");
    FString timestamp = getStringField("timestamp");
    FString callbackId = getStringField("callbackId");

    // Extract jsonResponse field
    jfieldID jsonResponseFieldId = env->GetFieldID(eventSuccessClass, "jsonResponse", "Lorg/json/JSONObject;");
    FString jsonResponseString;
    if (jsonResponseFieldId != nullptr)
    {
        jobject jsonResponseObject = env->GetObjectField(eventSuccessObject, jsonResponseFieldId);
        if (jsonResponseObject != nullptr)
        {
            jclass jsonObjectClass = env->GetObjectClass(jsonResponseObject);
            jmethodID toStringMethodId = env->GetMethodID(jsonObjectClass, "toString", "()Ljava/lang/String;");
            if (toStringMethodId != nullptr)
            {
                jstring jsonString = (jstring)env->CallObjectMethod(jsonResponseObject, toStringMethodId);
                if (jsonString != nullptr)
                {
                    const char* cStr = env->GetStringUTFChars(jsonString, nullptr);
                    jsonResponseString = FString(UTF8_TO_TCHAR(cStr));
                    env->ReleaseStringUTFChars(jsonString, cStr);
                    env->DeleteLocalRef(jsonString);
                }
            }
            env->DeleteLocalRef(jsonObjectClass);
            env->DeleteLocalRef(jsonResponseObject);
        }
    }

    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, eventToken, callbackId, jsonResponseString]()
    {
        FAdjustEventSuccess ueEventSuccess;
        ueEventSuccess.EventToken = eventToken;
        ueEventSuccess.Message = message;
        ueEventSuccess.Adid = adid;
        ueEventSuccess.Timestamp = timestamp;
        ueEventSuccess.CallbackId = callbackId;
        ueEventSuccess.JsonResponse = jsonResponseString;
        eventSuccessCallbackMethod(ueEventSuccess);
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeEventFailureCallback_eventFailure(
    JNIEnv* env, jobject obj, jobject eventFailureObject)
{
    // Ensure the eventFailureObject is not null
    if (eventFailureObject == nullptr)
    {
        return;
    }

    // Get the AdjustEventFailure class
    jclass eventFailureClass = env->GetObjectClass(eventFailureObject);
    if (eventFailureClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(eventFailureClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(eventFailureObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Extract fields
    FString eventToken = getStringField("eventToken");
    FString message = getStringField("message");
    FString adid = getStringField("adid");
    FString timestamp = getStringField("timestamp");
    FString callbackId = getStringField("callbackId");

    // Extract willRetry field
    jfieldID willRetryFieldId = env->GetFieldID(eventFailureClass, "willRetry", "Z");
    bool willRetry = false;
    if (willRetryFieldId != nullptr)
    {
        willRetry = env->GetBooleanField(eventFailureObject, willRetryFieldId);
    }

    // Extract jsonResponse field
    jfieldID jsonResponseFieldId = env->GetFieldID(eventFailureClass, "jsonResponse", "Lorg/json/JSONObject;");
    FString jsonResponseString;
    if (jsonResponseFieldId != nullptr)
    {
        jobject jsonResponseObject = env->GetObjectField(eventFailureObject, jsonResponseFieldId);
        if (jsonResponseObject != nullptr)
        {
            jclass jsonObjectClass = env->GetObjectClass(jsonResponseObject);
            jmethodID toStringMethodId = env->GetMethodID(jsonObjectClass, "toString", "()Ljava/lang/String;");
            if (toStringMethodId != nullptr)
            {
                jstring jsonString = (jstring)env->CallObjectMethod(jsonResponseObject, toStringMethodId);
                if (jsonString != nullptr)
                {
                    const char* cStr = env->GetStringUTFChars(jsonString, nullptr);
                    jsonResponseString = FString(UTF8_TO_TCHAR(cStr));
                    env->ReleaseStringUTFChars(jsonString, cStr);
                    env->DeleteLocalRef(jsonString);
                }
            }
            env->DeleteLocalRef(jsonObjectClass);
            env->DeleteLocalRef(jsonResponseObject);
        }
    }

    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, eventToken, callbackId, willRetry, jsonResponseString]()
    {
        FAdjustEventFailure ueEventFailure;
        ueEventFailure.EventToken = eventToken;
        ueEventFailure.Message = message;
        ueEventFailure.Adid = adid;
        ueEventFailure.Timestamp = timestamp;
        ueEventFailure.CallbackId = callbackId;
        ueEventFailure.JsonResponse = jsonResponseString;
        ueEventFailure.WillRetry = willRetry;
        eventFailureCallbackMethod(ueEventFailure);
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeDeferredDeeplinkCallback_deferredDeeplinkReceived(
    JNIEnv *env, jobject obj, jstring jDeeplink)
{
    // Check if the jDeeplink is null
    if (jDeeplink == nullptr)
    {
        return;
    }

    // Convert the jDeeplink to FString
    const char* cDeeplink = env->GetStringUTFChars(jDeeplink, nullptr);
    FString deferredDeeplink = FString(UTF8_TO_TCHAR(cDeeplink));
    env->ReleaseStringUTFChars(jDeeplink, cDeeplink);

    AsyncTask(ENamedThreads::GameThread, [deferredDeeplink]()
    {
        if (deferredDeeplinkCallbackMethod != nullptr)
        {
            deferredDeeplinkCallbackMethod(deferredDeeplink);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeIsEnabledCallback_isEnabledRead(
    JNIEnv *env, jobject obj, jboolean jIsEnabled)
{
    AsyncTask(ENamedThreads::GameThread, [jIsEnabled]()
    {
        if (isEnabledCallbackMethod != nullptr)
        {
            isEnabledCallbackMethod(jIsEnabled);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAdidGetterCallback_adidRead(
    JNIEnv *env, jobject obj, jstring jAdid)
{
    if (jAdid == nullptr)
    {
        return;
    }

    const char* cAdid = env->GetStringUTFChars(jAdid, nullptr);
    FString adid = FString(UTF8_TO_TCHAR(cAdid));
    env->ReleaseStringUTFChars(jAdid, cAdid);

    AsyncTask(ENamedThreads::GameThread, [adid]()
    {
        if (adidGetterCallbackMethod != nullptr)
        {
            adidGetterCallbackMethod(adid);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeSdkVersionGetterCallback_sdkVersionRead(
    JNIEnv *env, jobject obj, jstring jSdkVersion)
{
    if (jSdkVersion == nullptr)
    {
        return;
    }

    const char* cSdkVersion = env->GetStringUTFChars(jSdkVersion, nullptr);
    FString sdkVersion = FString(UTF8_TO_TCHAR(cSdkVersion));
    env->ReleaseStringUTFChars(jSdkVersion, cSdkVersion);

    AsyncTask(ENamedThreads::GameThread, [sdkVersion]()
    {
        if (sdkVersionGetterCallbackMethod != nullptr)
        {
            sdkVersionGetterCallbackMethod(sdkVersion);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAttributionGetterCallback_attributionRead(
    JNIEnv* env, jobject obj, jobject attributionObject)
{
    // Ensure the attributionObject is not null
    if (attributionObject == nullptr)
    {
        return;
    }

    // Get the AdjustAttribution class
    jclass attributionClass = env->GetObjectClass(attributionObject);
    if (attributionClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jfieldID fieldId = env->GetFieldID(attributionClass, fieldName, "Ljava/lang/String;");
        if (fieldId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->GetObjectField(attributionObject, fieldId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Helper function to get double fields
    auto getDoubleField = [&](const char* fieldName) -> double {
        jfieldID fieldId = env->GetFieldID(attributionClass, fieldName, "Ljava/lang/Double;");
        if (fieldId == nullptr)
        {
            return 0.0;
        }
        jobject doubleObj = env->GetObjectField(attributionObject, fieldId);
        if (doubleObj == nullptr)
        {
            return 0.0;
        }
        jclass doubleClass = env->GetObjectClass(doubleObj);
        jmethodID doubleValueMethod = env->GetMethodID(doubleClass, "doubleValue", "()D");
        double value = env->CallDoubleMethod(doubleObj, doubleValueMethod);
        env->DeleteLocalRef(doubleObj);
        env->DeleteLocalRef(doubleClass);
        return value;
    };

    // Extract all fields
    FString trackerToken = getStringField("trackerToken");
    FString trackerName = getStringField("trackerName");
    FString network = getStringField("network");
    FString campaign = getStringField("campaign");
    FString adgroup = getStringField("adgroup");
    FString creative = getStringField("creative");
    FString clickLabel = getStringField("clickLabel");
    FString costType = getStringField("costType");
    double costAmount = getDoubleField("costAmount");
    FString costCurrency = getStringField("costCurrency");
    FString fbInstallReferrer = getStringField("fbInstallReferrer");
    FString fsJsonResponse = getStringField("jsonResponse");

    AsyncTask(ENamedThreads::GameThread, [
        trackerToken,
        trackerName,
        network,
        campaign,
        adgroup,
        creative,
        clickLabel,
        costType,
        costAmount,
        costCurrency,
        fbInstallReferrer,
        fsJsonResponse]()
    {
        if (attributionGetterCallbackMethod != nullptr)
        {
            FAdjustAttribution ueAttribution;
            ueAttribution.TrackerToken = trackerToken;
            ueAttribution.TrackerName = trackerName;
            ueAttribution.Network = network;
            ueAttribution.Campaign = campaign;
            ueAttribution.Adgroup = adgroup;
            ueAttribution.Creative = creative;
            ueAttribution.ClickLabel = clickLabel;
            ueAttribution.CostType = costType;
            ueAttribution.CostAmount = costAmount;
            ueAttribution.CostCurrency = costCurrency;
            ueAttribution.FbInstallReferrer = fbInstallReferrer;
            ueAttribution.JsonResponse = fsJsonResponse;
            attributionGetterCallbackMethod(ueAttribution);
        }
    });

    // Clean up local references
    env->DeleteLocalRef(attributionClass);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeDeeplinkResolvedCallback_deeplinkResolved(
    JNIEnv *env, jobject obj, jstring jResolvedLink)
{
    if (jResolvedLink == nullptr)
    {
        return;
    }

    const char* cResolvedDeeplink = env->GetStringUTFChars(jResolvedLink, nullptr);
    FString resolvedDeeplink = FString(UTF8_TO_TCHAR(cResolvedDeeplink));
    env->ReleaseStringUTFChars(jResolvedLink, cResolvedDeeplink);

    AsyncTask(ENamedThreads::GameThread, [resolvedDeeplink]()
    {
        if (deeplinkResolutionCallbackMethod != nullptr)
        {
            deeplinkResolutionCallbackMethod(resolvedDeeplink);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeLastDeeplinkGetterCallback_lastDeeplinkRead(
    JNIEnv *env, jobject obj, jstring jLastDeeplink)
{
    if (jLastDeeplink == nullptr)
    {
        return;
    }

    const char* cLastDeeplink = env->GetStringUTFChars(jLastDeeplink, nullptr);
    FString lastDeeplink = FString(UTF8_TO_TCHAR(cLastDeeplink));
    env->ReleaseStringUTFChars(jLastDeeplink, cLastDeeplink);

    AsyncTask(ENamedThreads::GameThread, [lastDeeplink]()
    {
        if (lastDeeplinkGetterCallbackMethod != nullptr)
        {
            lastDeeplinkGetterCallbackMethod(lastDeeplink);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeGoogleAdIdGetterCallback_googleAdIdRead(
    JNIEnv *env, jobject obj, jstring jGoogleAdId)
{
    if (jGoogleAdId == nullptr)
    {
        return;
    }

    const char* cGoogleAdId = env->GetStringUTFChars(jGoogleAdId, nullptr);
    FString googleAdId = FString(UTF8_TO_TCHAR(cGoogleAdId));
    env->ReleaseStringUTFChars(jGoogleAdId, cGoogleAdId);

    AsyncTask(ENamedThreads::GameThread, [googleAdId]()
    {
        if (googleAdIdGetterCallbackMethod != nullptr)
        {
            googleAdIdGetterCallbackMethod(googleAdId);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeAmazonAdIdGetterCallback_amazonAdIdRead(
    JNIEnv *env, jobject obj, jstring jAmazonAdId)
{
    if (jAmazonAdId == nullptr)
    {
        return;
    }

    const char* cAmazonAdId = env->GetStringUTFChars(jAmazonAdId, nullptr);
    FString amazonAdId = FString(UTF8_TO_TCHAR(cAmazonAdId));
    env->ReleaseStringUTFChars(jAmazonAdId, cAmazonAdId);

    AsyncTask(ENamedThreads::GameThread, [amazonAdId]()
    {
        if (amazonAdIdGetterCallbackMethod != nullptr)
        {
            amazonAdIdGetterCallbackMethod(amazonAdId);
        }
    });
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUePurchaseVerificationCallback_verificationFinished(
    JNIEnv *env, jobject obj, jobject verificationResultObject)
{
    if (verificationResultObject == nullptr)
    {
        return;
    }

    jclass verificationResultClass = env->GetObjectClass(verificationResultObject);
    if (verificationResultClass == nullptr)
    {
        return;
    }

    // Helper function to get string fields
    auto getStringField = [&](const char* fieldName) -> FString {
        jmethodID methodId = env->GetMethodID(verificationResultClass, fieldName, "()Ljava/lang/String;");
        if (methodId == nullptr)
        {
            return FString();
        }
        jstring jStr = (jstring)env->CallObjectMethod(verificationResultObject, methodId);
        if (jStr == nullptr)
        {
            return FString();
        }
        const char* cStr = env->GetStringUTFChars(jStr, nullptr);
        FString result = FString(UTF8_TO_TCHAR(cStr));
        env->ReleaseStringUTFChars(jStr, cStr);
        env->DeleteLocalRef(jStr);
        return result;
    };

    // Helper function to get int fields
    auto getIntField = [&](const char* fieldName) -> int {
        jmethodID methodId = env->GetMethodID(verificationResultClass, fieldName, "()I");
        if (methodId == nullptr)
        {
            return 0;
        }
        return env->CallIntMethod(verificationResultObject, methodId);
    };

    FString verificationStatus = getStringField("getVerificationStatus");
    int code = getIntField("getCode");
    FString message = getStringField("getMessage");

    env->DeleteLocalRef(verificationResultClass);

    AsyncTask(ENamedThreads::GameThread, [verificationStatus, code, message]()
    {
        if (purchaseVerificationCallbackMethod != nullptr)
        {
            FAdjustPurchaseVerificationResult ueResult;
            ueResult.VerificationStatus = verificationStatus;
            ueResult.Code = code;
            ueResult.Message = message;
            purchaseVerificationCallbackMethod(ueResult);
        }
    });
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

void setIsEnabledCallbackMethod(void (*callbackMethod)(bool IsEnabled))
{
    isEnabledCallbackMethod = callbackMethod;
}

void setAdidGetterCallbackMethod(void (*callbackMethod)(FString Adid))
{
    adidGetterCallbackMethod = callbackMethod;
}

void setAttributionGetterCallbackMethod(void (*callbackMethod)(FAdjustAttribution Attribution))
{
    attributionGetterCallbackMethod = callbackMethod;
}

void setSdkVersionGetterCallbackMethod(void (*callbackMethod)(FString SdkVersion))
{
    sdkVersionGetterCallbackMethod = callbackMethod;
}

void setDeeplinkResolutionCallback(void (*callbackMethod)(FString ResolvedLink))
{
    deeplinkResolutionCallbackMethod = callbackMethod;
}

void setLinkResolutionCallback(void (*callbackMethod)(FString ResolvedLink))
{
    linkResolutionCallbackMethod = callbackMethod;
}

void setLastDeeplinkGetterCallbackMethod(void (*callbackMethod)(FString LastDeeplink))
{
    lastDeeplinkGetterCallbackMethod = callbackMethod;
}

void setGoogleAdIdGetterCallbackMethod(void (*callbackMethod)(FString GoogleAdId))
{
    googleAdIdGetterCallbackMethod = callbackMethod;
}

void setAmazonAdIdGetterCallbackMethod(void (*callbackMethod)(FString AmazonAdId))
{
    amazonAdIdGetterCallbackMethod = callbackMethod;
}

void setPurchaseVerificationCallbackMethod(void (*callbackMethod)(FAdjustPurchaseVerificationResult VerificationResult))
{
    purchaseVerificationCallbackMethod = callbackMethod;
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeLinkResolutionCallback_resolvedLinkCallback(
    JNIEnv *env, jobject obj, jstring resolvedLink)
{
    FString fsResolvedLink;
    if (resolvedLink != nullptr)
    {
        const char *utfString = env->GetStringUTFChars(resolvedLink, nullptr);
        if (utfString != nullptr)
        {
            fsResolvedLink = FString(UTF8_TO_TCHAR(utfString));
            env->ReleaseStringUTFChars(resolvedLink, utfString);
        }
    }

    AsyncTask(ENamedThreads::GameThread, [fsResolvedLink]()
    {
        if (linkResolutionCallbackMethod != nullptr)
        {
            linkResolutionCallbackMethod(fsResolvedLink);
        }
    });
}

#endif
