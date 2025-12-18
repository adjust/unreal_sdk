//
//  TestLib.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "TestLib.h"
#include "CoreMinimal.h"

#if PLATFORM_ANDROID
#include "Android/AdjustTestJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#elif PLATFORM_IOS
#include "IOS/ATLTestLibraryWrapper.h"
#endif

#if PLATFORM_ANDROID
static void* staticTestLibrary = nullptr;
#elif PLATFORM_IOS
static ATLTestLibraryWrapper* staticTestLibrary = nullptr;
#endif

void TestLib::initTestLibrary(std::string baseUrl, std::string controlUrl, void(*callback)(std::string className, std::string methodName, std::string jsonParameters)) {
#if PLATFORM_ANDROID
    setExecuteTestLibCommandCallbackMethod([callback](FString className, FString methodName, FString jsonParameters) {
        if (callback != nullptr) {
            std::string classNameStr = std::string(TCHAR_TO_UTF8(*className));
            std::string methodNameStr = std::string(TCHAR_TO_UTF8(*methodName));
            std::string jsonParametersStr = std::string(TCHAR_TO_UTF8(*jsonParameters));
            callback(classNameStr, methodNameStr, jsonParametersStr);
        }
    });

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslTestLibrary = FAndroidApplication::FindJavaClass("com/adjust/test/TestLibrary");
    jmethodID jmidInit = Env->GetMethodID(jcslTestLibrary, "<init>", "(Ljava/lang/String;Ljava/lang/String;Landroid/content/Context;Lcom/adjust/test/ICommandJsonListener;)V");
    
    jstring jBaseUrl = Env->NewStringUTF(baseUrl.c_str());
    jstring jControlUrl = Env->NewStringUTF(controlUrl.c_str());
    
    jclass jcslUeTestLibCommandJsonListenerCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeTestLibCommandJsonListenerCallback");
    jmethodID jmidUeTestLibCommandJsonListenerCallbackInit = Env->GetMethodID(jcslUeTestLibCommandJsonListenerCallback, "<init>", "(Lcom/epicgames/unreal/GameActivity;)V");
    jobject jCommListenerCallbackProxy = Env->NewObject(jcslUeTestLibCommandJsonListenerCallback, jmidUeTestLibCommandJsonListenerCallbackInit, FJavaWrapper::GameActivityThis);

    jobject jTestLib = Env->NewObject(jcslTestLibrary, jmidInit, jBaseUrl, jControlUrl, FJavaWrapper::GameActivityThis, jCommListenerCallbackProxy);
    this->testLibrary = Env->NewGlobalRef(jTestLib);
    staticTestLibrary = this->testLibrary;

    Env->DeleteLocalRef(jBaseUrl);
    Env->DeleteLocalRef(jControlUrl);
    Env->DeleteLocalRef(jCommListenerCallbackProxy);
    Env->DeleteLocalRef(jTestLib);
#elif PLATFORM_IOS
    this->testLibrary = new ATLTestLibraryWrapper(baseUrl, controlUrl, callback);
    staticTestLibrary = this->testLibrary;
#endif
}

TestLib::TestLib(std::string baseUrl, std::string controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters)) 
#if PLATFORM_IOS
    : testLibrary(nullptr)
#elif PLATFORM_ANDROID
    : testLibrary(nullptr)
#endif
{
    initTestLibrary(baseUrl, controlUrl, executeCommandCallback);
}

TestLib::~TestLib() {
#if PLATFORM_ANDROID
    if (testLibrary != nullptr) {
        JNIEnv *Env = FAndroidApplication::GetJavaEnv();
        Env->DeleteGlobalRef((jobject)testLibrary);
        testLibrary = nullptr;
    }
#elif PLATFORM_IOS
    if (testLibrary != nullptr) {
        delete testLibrary;
        testLibrary = nullptr;
    }
#endif
}

void TestLib::addTest(std::string testName) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidAddTest = Env->GetMethodID(jcslTestLibrary, "addTest", "(Ljava/lang/String;)V");
    jstring jTestName = Env->NewStringUTF(testName.c_str());
    Env->CallVoidMethod((jobject)testLibrary, jmidAddTest, jTestName);
    Env->DeleteLocalRef(jTestName);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (testLibrary != nullptr) {
        testLibrary->addTest(testName);
    }
#endif
}

void TestLib::addTestDirectory(std::string testDirectory) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidAddTestDir = Env->GetMethodID(jcslTestLibrary, "addTestDirectory", "(Ljava/lang/String;)V");
    jstring jTestDir = Env->NewStringUTF(testDirectory.c_str());
    Env->CallVoidMethod((jobject)testLibrary, jmidAddTestDir, jTestDir);
    Env->DeleteLocalRef(jTestDir);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (testLibrary != nullptr) {
        testLibrary->addTestDirectory(testDirectory);
    }
#endif
}

void TestLib::startTestSession(std::string clientSdk) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidStartTestSession = Env->GetMethodID(jcslTestLibrary, "startTestSession", "(Ljava/lang/String;)V");
    jstring jClientSdk = Env->NewStringUTF(clientSdk.c_str());
    Env->CallVoidMethod((jobject)testLibrary, jmidStartTestSession, jClientSdk);
    Env->DeleteLocalRef(jClientSdk);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (testLibrary != nullptr) {
        testLibrary->startTestSession(clientSdk);
    }
#endif
}

void TestLib::addInfoToSend(std::string key, std::string value) {
#if PLATFORM_ANDROID
    if (staticTestLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)staticTestLibrary);
    if (jcslTestLibrary == nullptr) {
        return;
    }
    jmethodID jmidAddInfoToSend = Env->GetMethodID(jcslTestLibrary, "addInfoToSend", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (jmidAddInfoToSend == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        return;
    }
    jstring jKey = Env->NewStringUTF(key.c_str());
    jstring jValue = Env->NewStringUTF(value.c_str());
    Env->CallVoidMethod((jobject)staticTestLibrary, jmidAddInfoToSend, jKey, jValue);
    Env->DeleteLocalRef(jKey);
    Env->DeleteLocalRef(jValue);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (staticTestLibrary != nullptr) {
        staticTestLibrary->addInfoToSend(key, value);
    }
#endif    
}

void TestLib::sendInfoToServer(std::string basePath) {
#if PLATFORM_ANDROID
    if (staticTestLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)staticTestLibrary);
    if (jcslTestLibrary == nullptr) {
        return;
    }
    jmethodID jmidSendInfoToServer = Env->GetMethodID(jcslTestLibrary, "sendInfoToServer", "(Ljava/lang/String;)V");
    if (jmidSendInfoToServer == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        return;
    }
    jstring jBasePath = Env->NewStringUTF(basePath.c_str());
    Env->CallVoidMethod((jobject)staticTestLibrary, jmidSendInfoToServer, jBasePath);
    Env->DeleteLocalRef(jBasePath);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (staticTestLibrary != nullptr) {
        staticTestLibrary->sendInfoToServer(basePath);
    }
#endif
}
