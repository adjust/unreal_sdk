//
//  TestConnectionOptions.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 14th September 2021.
//  Copyright © 2021-Present Adjust GmbH. All rights reserved.
//

#include "TestConnectionOptions.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#elif PLATFORM_IOS
// iOS doesn't need test connection options
#endif

void TestConnectionOptions::setTestConnectionOptions() {
#if PLATFORM_ANDROID
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }

    jclass jcslTestConnectionOptions = FAndroidApplication::FindJavaClass("com/adjust/test_options/TestConnectionOptions");
    if (jcslTestConnectionOptions == nullptr) {
        return;
    }

    jmethodID jmidSetTestConnectionOptions = Env->GetStaticMethodID(jcslTestConnectionOptions, "setTestConnectionOptions", "()V");
    if (jmidSetTestConnectionOptions == nullptr) {
        Env->DeleteLocalRef(jcslTestConnectionOptions);
        return;
    }

    Env->CallStaticVoidMethod(jcslTestConnectionOptions, jmidSetTestConnectionOptions);
    Env->DeleteLocalRef(jcslTestConnectionOptions);
#elif PLATFORM_IOS
    // iOS doesn't need test connection options
#endif
}
