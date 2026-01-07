//
//  AdjustTestJNI.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#if PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include <jni.h>

extern "C"
{
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024AdjustUeTestLibCommandJsonListenerCallback_commandJsonReceived(
        JNIEnv *env, jobject obj, jstring jClassName, jstring jMethodName, jstring jJsonParameters);
    
    void setExecuteTestLibCommandCallbackMethod(void (*callbackMethod)(FString className, FString methodName, FString jsonParameters));
}

#endif
