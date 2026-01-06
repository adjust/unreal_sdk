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
static std::vector<SafeString> pendingTests;
static std::vector<SafeString> pendingTestDirectories;

void UAdjustTest::StartTestSession(const FString& BaseUrl, const FString& ControlUrl, const FString& ClientSdk)
{
    SafeString baseUrlStr = SafeString(TCHAR_TO_UTF8(*BaseUrl));
    
    // determine URL overwrite based on platform
    // input is just IP:port, we add the protocol based on platform
    SafeString urlOverwrite;
#if PLATFORM_IOS
    // iOS always uses http://
    urlOverwrite = "http://" + baseUrlStr;
#elif PLATFORM_ANDROID
    // Android always uses https:// on port 8443
    // extract IP from baseUrlStr and replace port with 8443
    size_t lastColon = baseUrlStr.find_last_of(':');
    SafeString ipOnly = (lastColon != SafeString::npos) ? baseUrlStr.substr(0, lastColon) : baseUrlStr;
    urlOverwrite = SafeString("https://") + ipOnly + SafeString(":8443");
#else
    urlOverwrite = baseUrlStr;
#endif

    SafeString controlUrlStr = SafeString(TCHAR_TO_UTF8(*ControlUrl));
    
    // for Android, control URL should be WebSocket URL (ws://) based on base URL
#if PLATFORM_ANDROID
    // reuse ipOnly from above to build WebSocket URL
    // controlUrl should be ws://IP:1987 (WebSocket port, typically 1987)
    controlUrlStr = SafeString("ws://") + ipOnly + SafeString(":1987");
#endif

    // create command executor
    if (commandExecutor == nullptr) {
        // convert SafeString to std::string for AdjustCommandExecutor (not part of JNI boundary)
        commandExecutor = new AdjustCommandExecutor(std::string(urlOverwrite.c_str()));
    }

    // create command callback function
    auto commandCallback = [](SafeString className, SafeString methodName, SafeString jsonParameters) {
        if (commandExecutor != nullptr) {
            // CRITICAL: Capture SafeString by value and convert to std::string INSIDE AsyncTask on game thread
            // Converting std::string in JNI callback context causes allocator issues
            // SafeString uses SystemAllocator (malloc/free) which is safe to capture
            AsyncTask(ENamedThreads::GameThread, [className, methodName, jsonParameters]() {
                // Command now accepts SafeString directly - no conversion needed!
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
    SafeString clientSdkStr = SafeString(TCHAR_TO_UTF8(*ClientSdk));
    
    if (testLibrary != nullptr) {
        testLibrary->startTestSession(clientSdkStr);
    }
}

void UAdjustTest::AddTest(const FString& TestName)
{
    SafeString testNameStr = SafeString(TCHAR_TO_UTF8(*TestName));
    
    if (testLibrary != nullptr) {
        testLibrary->addTest(testNameStr);
    } else {
        pendingTests.push_back(testNameStr);
    }
}

void UAdjustTest::AddTestDirectory(const FString& TestDirectory)
{
    SafeString testDirectoryStr = SafeString(TCHAR_TO_UTF8(*TestDirectory));
    
    if (testLibrary != nullptr) {
        testLibrary->addTestDirectory(testDirectoryStr);
    } else {
        pendingTestDirectories.push_back(testDirectoryStr);
    }
}

void UAdjustTest::AddInfoToSend(const FString& Key, const FString& Value)
{
    SafeString keyStr = SafeString(TCHAR_TO_UTF8(*Key));
    SafeString valueStr = SafeString(TCHAR_TO_UTF8(*Value));
    TestLib::addInfoToSend(keyStr, valueStr);
}

void UAdjustTest::SendInfoToServer(const FString& BasePath)
{
    SafeString basePathStr = SafeString(TCHAR_TO_UTF8(*BasePath));
    TestLib::sendInfoToServer(basePathStr);
}
