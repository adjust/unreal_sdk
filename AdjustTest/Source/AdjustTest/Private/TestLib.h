//
//  TestLib.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include <string>

#if PLATFORM_IOS
class ATLTestLibraryWrapper;
#endif

class TestLib {
private:
    void initTestLibrary(std::string baseUrl, std::string controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters));

#if PLATFORM_IOS
    ATLTestLibraryWrapper* testLibrary;
#elif PLATFORM_ANDROID
    void* testLibrary; // jobject
#endif

public:
    TestLib(std::string baseUrl, std::string controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters));
    ~TestLib();

    void addTest(std::string testName);
    void addTestDirectory(std::string testDirectory);
    void startTestSession(std::string clientSdk);
    static void addInfoToSend(std::string key, std::string value);
    static void sendInfoToServer(std::string basePath);
};
