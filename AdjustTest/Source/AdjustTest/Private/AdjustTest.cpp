//
//  AdjustTest.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "AdjustTest.h"
#include "AdjustTestModule.h"
#include "TestLib.h"
#include "AdjustCommandExecutor.h"
#include "Command.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Modules/ModuleManager.h"
#include "HAL/Platform.h"
#include "HAL/MemoryBase.h"
#include "Async/Async.h"
#include <vector>
#include <cstdlib>
#include <cstring>

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

UAdjustTest::UAdjustTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

static TestLib* testLibrary = nullptr;
static AdjustCommandExecutor* commandExecutor = nullptr;
static std::vector<std::string> pendingTests;
static std::vector<std::string> pendingTestDirectories;

void UAdjustTest::StartTestSession(const FString& BaseUrl, const FString& ControlUrl, const FString& ClientSdk)
{
    std::string baseUrlStr = std::string(TCHAR_TO_UTF8(*BaseUrl));
    
    // determine URL overwrite based on platform
    // input is just IP:port, we add the protocol based on platform
    std::string urlOverwrite;
#if PLATFORM_IOS
    // iOS always uses http://
    urlOverwrite = "http://" + baseUrlStr;
#elif PLATFORM_ANDROID
    // Android always uses https:// on port 8443
    // extract IP from baseUrlStr and replace port with 8443
    size_t lastColon = baseUrlStr.find_last_of(':');
    std::string ipOnly = (lastColon != std::string::npos) ? baseUrlStr.substr(0, lastColon) : baseUrlStr;
    urlOverwrite = std::string("https://") + ipOnly + std::string(":8443");
#else
    urlOverwrite = baseUrlStr;
#endif

    std::string controlUrlStr = std::string(TCHAR_TO_UTF8(*ControlUrl));
    
    // for Android, control URL should be WebSocket URL (ws://) based on base URL
#if PLATFORM_ANDROID
    // reuse ipOnly from above to build WebSocket URL
    // controlUrl should be ws://IP:1987 (WebSocket port, typically 1987)
    controlUrlStr = std::string("ws://") + ipOnly + std::string(":1987");
#endif

    // create command executor
    if (commandExecutor == nullptr) {
        commandExecutor = new AdjustCommandExecutor(urlOverwrite);
    }

    // create command callback function
    auto commandCallback = [](std::string className, std::string methodName, std::string jsonParameters) {
        if (commandExecutor != nullptr) {
            AsyncTask(ENamedThreads::GameThread, [className, methodName, jsonParameters]() {
                Command* command = new Command(className, methodName, jsonParameters);
                if (commandExecutor != nullptr) {
                    commandExecutor->executeCommand(command);
                    delete command;
                } else {
                    delete command;
                }
            });
        }
    };

    // create test library
    if (testLibrary == nullptr) {
        // pass urlOverwrite (with protocol) to TestLib, not baseUrlStr (without protocol)
        testLibrary = new TestLib(urlOverwrite, controlUrlStr, commandCallback);
        
        // add any pending tests that were added before the library was created
        for (const auto& testName : pendingTests) {
            testLibrary->addTest(testName);
        }
        pendingTests.clear();
        
        for (const auto& testDir : pendingTestDirectories) {
            testLibrary->addTestDirectory(testDir);
        }
        pendingTestDirectories.clear();
    }

    // start test session
    std::string clientSdkStr = std::string(TCHAR_TO_UTF8(*ClientSdk));
    
    if (testLibrary != nullptr) {
        testLibrary->startTestSession(clientSdkStr);
    }
}

void UAdjustTest::AddTest(const FString& TestName)
{
    std::string testNameStr = std::string(TCHAR_TO_UTF8(*TestName));
    
    if (testLibrary != nullptr) {
        testLibrary->addTest(testNameStr);
    } else {
        pendingTests.push_back(testNameStr);
    }
}

void UAdjustTest::AddTestDirectory(const FString& TestDirectory)
{
    std::string testDirectoryStr = std::string(TCHAR_TO_UTF8(*TestDirectory));
    
    if (testLibrary != nullptr) {
        testLibrary->addTestDirectory(testDirectoryStr);
    } else {
        pendingTestDirectories.push_back(testDirectoryStr);
    }
}

void UAdjustTest::AddInfoToSend(const FString& Key, const FString& Value)
{
    std::string keyStr = std::string(TCHAR_TO_UTF8(*Key));
    std::string valueStr = std::string(TCHAR_TO_UTF8(*Value));
    TestLib::addInfoToSend(keyStr, valueStr);
}

void UAdjustTest::SendInfoToServer(const FString& BasePath)
{
    std::string basePathStr = std::string(TCHAR_TO_UTF8(*BasePath));
    TestLib::sendInfoToServer(basePathStr);
}
