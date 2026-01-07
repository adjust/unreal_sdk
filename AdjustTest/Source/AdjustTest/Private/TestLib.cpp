//
//  TestLib.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#include "TestLib.h"
#include "CoreMinimal.h"
#include <cstdlib>
#include <cstring>

#if PLATFORM_ANDROID
#include "Android/AdjustTestJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#elif PLATFORM_IOS
#include "IOS/ATLTestLibraryWrapper.h"
#endif

#if PLATFORM_ANDROID
static void* staticTestLibrary = nullptr; // Java object global reference
static TestLib* staticTestLibInstance = nullptr; // C++ TestLib instance to keep alive
static void(*staticTestLibCallback)(std::string className, std::string methodName, std::string jsonParameters) = nullptr;

// wrapper function that can be used as a function pointer
static void TestLibCommandCallbackWrapper(FString className, FString methodName, FString jsonParameters)
{
    if (staticTestLibCallback != nullptr) {
        FTCHARToUTF8 classNameUTF8(*className);
        std::string classNameStr(classNameUTF8.Get(), classNameUTF8.Length());
        
        FTCHARToUTF8 methodNameUTF8(*methodName);
        std::string methodNameStr(methodNameUTF8.Get(), methodNameUTF8.Length());
        
        FTCHARToUTF8 jsonParametersUTF8(*jsonParameters);
        std::string jsonParametersStr(jsonParametersUTF8.Get(), jsonParametersUTF8.Length());
        
        staticTestLibCallback(classNameStr, methodNameStr, jsonParametersStr);
    }
}
#elif PLATFORM_IOS
static ATLTestLibraryWrapper* staticTestLibrary = nullptr;
#endif

void TestLib::initTestLibrary(const std::string& baseUrl, const std::string& controlUrl, void(*callback)(std::string className, std::string methodName, std::string jsonParameters)) {
#if PLATFORM_ANDROID
    staticTestLibCallback = callback;
    setExecuteTestLibCommandCallbackMethod(TestLibCommandCallbackWrapper);

    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    
    jclass jcslTestLibrary = FAndroidApplication::FindJavaClass("com/adjust/test/TestLibrary");
    if (jcslTestLibrary == nullptr) {
        return;
    }
    
    // current test-library source has constructor signature: (String, String, Context, ICommandJsonListener)
    jmethodID jmidInit = Env->GetMethodID(jcslTestLibrary, "<init>", "(Ljava/lang/String;Ljava/lang/String;Landroid/content/Context;Lcom/adjust/test/ICommandJsonListener;)V");
    
    if (jmidInit == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        this->testLibrary = nullptr;
        staticTestLibrary = nullptr;
        return;
    }
    
    jstring jBaseUrl = Env->NewStringUTF(baseUrl.c_str());
    jstring jControlUrl = Env->NewStringUTF(controlUrl.c_str());
    
    jclass jcslUeTestLibCommandJsonListenerCallback = FAndroidApplication::FindJavaClass("com/epicgames/unreal/GameActivity$AdjustUeTestLibCommandJsonListenerCallback");
    if (jcslUeTestLibCommandJsonListenerCallback == nullptr) {
        Env->DeleteLocalRef(jBaseUrl);
        Env->DeleteLocalRef(jControlUrl);
        Env->DeleteLocalRef(jcslTestLibrary);
        this->testLibrary = nullptr;
        staticTestLibrary = nullptr;
        return;
    }
    
    jmethodID jmidUeTestLibCommandJsonListenerCallbackInit = Env->GetMethodID(jcslUeTestLibCommandJsonListenerCallback, "<init>", "()V");
    if (jmidUeTestLibCommandJsonListenerCallbackInit == nullptr) {
        Env->DeleteLocalRef(jBaseUrl);
        Env->DeleteLocalRef(jControlUrl);
        Env->DeleteLocalRef(jcslUeTestLibCommandJsonListenerCallback);
        Env->DeleteLocalRef(jcslTestLibrary);
        this->testLibrary = nullptr;
        staticTestLibrary = nullptr;
        return;
    }
    
    jobject jCommListenerCallbackProxy = Env->NewObject(jcslUeTestLibCommandJsonListenerCallback, jmidUeTestLibCommandJsonListenerCallbackInit);
    if (jCommListenerCallbackProxy == nullptr) {
        Env->DeleteLocalRef(jBaseUrl);
        Env->DeleteLocalRef(jControlUrl);
        Env->DeleteLocalRef(jcslUeTestLibCommandJsonListenerCallback);
        Env->DeleteLocalRef(jcslTestLibrary);
        this->testLibrary = nullptr;
        staticTestLibrary = nullptr;
        return;
    }

    jobject jTestLib = Env->NewObject(jcslTestLibrary, jmidInit, jBaseUrl, jControlUrl, FJavaWrapper::GameActivityThis, jCommListenerCallbackProxy);
    
    if (jTestLib == nullptr) {
        Env->DeleteLocalRef(jBaseUrl);
        Env->DeleteLocalRef(jControlUrl);
        Env->DeleteLocalRef(jCommListenerCallbackProxy);
        Env->DeleteLocalRef(jcslUeTestLibCommandJsonListenerCallback);
        Env->DeleteLocalRef(jcslTestLibrary);
        this->testLibrary = nullptr;
        staticTestLibrary = nullptr;
        return;
    }
    
    this->testLibrary = Env->NewGlobalRef(jTestLib);
    staticTestLibrary = this->testLibrary;

    Env->DeleteLocalRef(jBaseUrl);
    Env->DeleteLocalRef(jControlUrl);
    Env->DeleteLocalRef(jCommListenerCallbackProxy);
    Env->DeleteLocalRef(jTestLib);
    Env->DeleteLocalRef(jcslUeTestLibCommandJsonListenerCallback);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    this->testLibrary = new ATLTestLibraryWrapper(baseUrl, controlUrl, callback);
    staticTestLibrary = this->testLibrary;
#endif
}

TestLib::TestLib(const std::string& baseUrl, const std::string& controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters)) 
#if PLATFORM_IOS
    : testLibrary(nullptr)
#elif PLATFORM_ANDROID
    : testLibrary(nullptr)
#endif
{
    initTestLibrary(baseUrl, controlUrl, executeCommandCallback);
    
#if PLATFORM_ANDROID
    // keep C++ instance alive in static variable to prevent destruction
    staticTestLibInstance = this;
#endif
}

TestLib::~TestLib() {
#if PLATFORM_ANDROID
    // if this is the static instance, prevent destruction by not cleaning up
    // keep both Java object and C++ instance alive
    if (this == staticTestLibInstance) {
        return;
    }
    
    if (testLibrary != nullptr) {
        // check if this is the static reference BEFORE clearing it
        // keep staticTestLibrary alive to prevent GC of the Java object
        bool isStaticReference = (testLibrary == staticTestLibrary);
        
        JNIEnv *Env = FAndroidApplication::GetJavaEnv();
        if (Env != nullptr) {
            // only delete global ref if this was the static reference AND we're clearing it
            // otherwise keep it alive to prevent GC
            if (isStaticReference) {
                // clear static reference AFTER we've checked it
                staticTestLibrary = nullptr;
                Env->DeleteGlobalRef((jobject)testLibrary);
            }
        }
        testLibrary = nullptr;
    }
#elif PLATFORM_IOS
    if (testLibrary != nullptr) {
        delete testLibrary;
        testLibrary = nullptr;
    }
#endif
}

void TestLib::addTest(const std::string& testName) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidAddTest = Env->GetMethodID(jcslTestLibrary, "addTest", "(Ljava/lang/String;)V");
    if (jmidAddTest == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        return;
    }
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

void TestLib::addTestDirectory(const std::string& testDirectory) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidAddTestDir = Env->GetMethodID(jcslTestLibrary, "addTestDirectory", "(Ljava/lang/String;)V");
    if (jmidAddTestDir == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        return;
    }
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

void TestLib::startTestSession(const std::string& clientSdk) {
#if PLATFORM_ANDROID
    if (testLibrary == nullptr) {
        return;
    }
    JNIEnv *Env = FAndroidApplication::GetJavaEnv();
    if (Env == nullptr) {
        return;
    }
    jclass jcslTestLibrary = Env->GetObjectClass((jobject)testLibrary);
    jmethodID jmidStartTestSession = Env->GetMethodID(jcslTestLibrary, "startTestSession", "(Ljava/lang/String;)V");
    if (jmidStartTestSession == nullptr) {
        Env->DeleteLocalRef(jcslTestLibrary);
        return;
    }
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

void TestLib::addInfoToSend(const std::string& key, const std::string& value) {
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
    const char* keyCStr = key.c_str();
    jstring jKey = Env->NewStringUTF(keyCStr);
    const char* valueCStr = value.c_str();
    jstring jValue = Env->NewStringUTF(valueCStr);
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

void TestLib::sendInfoToServer(const std::string& basePath) {
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
    const char* basePathCStr = basePath.c_str();
    jstring jBasePath = Env->NewStringUTF(basePathCStr);
    Env->CallVoidMethod((jobject)staticTestLibrary, jmidSendInfoToServer, jBasePath);
    Env->DeleteLocalRef(jBasePath);
    Env->DeleteLocalRef(jcslTestLibrary);
#elif PLATFORM_IOS
    if (staticTestLibrary != nullptr) {
        staticTestLibrary->sendInfoToServer(basePath);
    }
#endif
}

#if PLATFORM_ANDROID
TestLib* TestLib::GetStaticInstance() {
    return staticTestLibInstance;
}
#endif
