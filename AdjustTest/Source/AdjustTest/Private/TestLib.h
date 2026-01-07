//
//  TestLib.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include <string>
#include "CoreMinimal.h"

#if PLATFORM_IOS
class ATLTestLibraryWrapper;
#endif

class TestLib {
private:
    void initTestLibrary(const std::string& baseUrl, const std::string& controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters));

#if PLATFORM_IOS
    ATLTestLibraryWrapper* testLibrary;
#elif PLATFORM_ANDROID
    void* testLibrary; // jobject
#endif

public:
    TestLib(const std::string& baseUrl, const std::string& controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters));
    ~TestLib();

    void addTest(const std::string& testName);
    void addTestDirectory(const std::string& testDirectory);
    void startTestSession(const std::string& clientSdk);
    static void addInfoToSend(const std::string& key, const std::string& value);
    static void sendInfoToServer(const std::string& basePath);
    
#if PLATFORM_ANDROID
    // get static instance to ensure it stays alive
    static TestLib* GetStaticInstance();
#endif
};
