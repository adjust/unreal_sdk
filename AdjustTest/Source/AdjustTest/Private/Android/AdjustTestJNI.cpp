//
//  AdjustTestJNI.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "AdjustTestJNI.h"

#if PLATFORM_ANDROID

#include "Android/AndroidApplication.h"
#include "Async/Async.h"

static void (*executeTestLibCommandCallbackMethod)(FString className, FString methodName, FString jsonParameters) = nullptr;

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeTestLibCommandJsonListenerCallback_commandJsonReceived(
    JNIEnv *env, jobject obj, jstring jClassName, jstring jMethodName, jstring jJsonParameters)
{
    if (jClassName == nullptr || jMethodName == nullptr || jJsonParameters == nullptr)
    {
        return;
    }

    const char* cClassName = env->GetStringUTFChars(jClassName, nullptr);
    const char* cMethodName = env->GetStringUTFChars(jMethodName, nullptr);
    const char* cJsonParameters = env->GetStringUTFChars(jJsonParameters, nullptr);
    
    FString className = FString(UTF8_TO_TCHAR(cClassName));
    FString methodName = FString(UTF8_TO_TCHAR(cMethodName));
    FString jsonParameters = FString(UTF8_TO_TCHAR(cJsonParameters));
    
    env->ReleaseStringUTFChars(jClassName, cClassName);
    env->ReleaseStringUTFChars(jMethodName, cMethodName);
    env->ReleaseStringUTFChars(jJsonParameters, cJsonParameters);

    // execute on game thread
    AsyncTask(ENamedThreads::GameThread, [className, methodName, jsonParameters]()
    {
        if (executeTestLibCommandCallbackMethod != nullptr)
        {
            executeTestLibCommandCallbackMethod(className, methodName, jsonParameters);
        }
    });
}

void setExecuteTestLibCommandCallbackMethod(void (*callbackMethod)(FString className, FString methodName, FString jsonParameters))
{
    executeTestLibCommandCallbackMethod = callbackMethod;
}

#endif
