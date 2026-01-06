//
//  AdjustCommandExecutor.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "AdjustCommandExecutor.h"
#include "AdjustTestModule.h"
#include "TestLib.h"
#include "TestConnectionOptions.h"
#include "Command.h"
#include "AdjustDelegates.h"
#include "AdjustTestCommandExecutorDelegates.h"
#if !PLATFORM_IOS || (defined(__cpp_exceptions) && __cpp_exceptions)
#include "json/json.hpp"
#endif
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#endif
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#if PLATFORM_IOS
#include <regex>
#endif

static std::string localBasePath;
static UAdjustDelegates* persistentAdjustDelegates = nullptr;
static UAdjustTestCommandExecutorDelegates* persistentTestDelegates = nullptr;
const std::string AdjustCommandExecutor::TAG = "AdjustCommandExecutor";

AdjustCommandExecutor::AdjustCommandExecutor(const std::string& urlOverwrite) {
    this->urlOverwrite = urlOverwrite;
    this->command = nullptr;
}

void AdjustCommandExecutor::executeCommand(Command *cmd) {
    this->command = cmd;
    if (cmd->methodName == "testOptions") {
        this->testOptions();
    } else if (cmd->methodName == "config") {
        this->config();
    } else if (cmd->methodName == "start") {
        this->start();
    } else if (cmd->methodName == "event") {
        this->event();
    } else if (cmd->methodName == "trackEvent") {
        this->trackEvent();
    } else if (cmd->methodName == "resume") {
        this->resume();
    } else if (cmd->methodName == "pause") {
        this->pause();
    } else if (cmd->methodName == "setEnabled") {
        this->setEnabled();
    } else if (cmd->methodName == "setOfflineMode") {
        this->setOfflineMode();
    } else if (cmd->methodName == "addGlobalCallbackParameter") {
        this->addGlobalCallbackParameter();
    } else if (cmd->methodName == "addGlobalPartnerParameter") {
        this->addGlobalPartnerParameter();
    } else if (cmd->methodName == "removeGlobalCallbackParameter") {
        this->removeGlobalCallbackParameter();
    } else if (cmd->methodName == "removeGlobalPartnerParameter") {
        this->removeGlobalPartnerParameter();
    } else if (cmd->methodName == "removeGlobalCallbackParameters") {
        this->removeGlobalCallbackParameters();
    } else if (cmd->methodName == "removeGlobalPartnerParameters") {
        this->removeGlobalPartnerParameters();
    } else if (cmd->methodName == "setPushToken") {
        this->setPushToken();
    } else if (cmd->methodName == "openDeeplink") {
        this->openDeeplink();
    } else if (cmd->methodName == "gdprForgetMe") {
        this->gdprForgetMe();
    } else if (cmd->methodName == "trackSubscription") {
        this->trackSubscription();
    } else if (cmd->methodName == "thirdPartySharing") {
        this->trackThirdPartySharing();
    } else if (cmd->methodName == "measurementConsent") {
        this->trackMeasurementConsent();
    } else if (cmd->methodName == "trackAdRevenue") {
        this->trackAdRevenue();
    } else if (cmd->methodName == "getLastDeeplink") {
        this->getLastDeeplink();
    } else if (cmd->methodName == "verifyPurchase") {
        this->verifyPurchase();
    } else if (cmd->methodName == "verifyTrack") {
        this->verifyTrack();
    } else if (cmd->methodName == "processDeeplink") {
        this->processDeeplink();
    } else if (cmd->methodName == "attributionGetter") {
        this->attributionGetter();
    } else if (cmd->methodName == "adidGetter") {
        this->adidGetter();
    } else if (cmd->methodName == "adidGetterWithTimeout") {
        this->adidGetterWithTimeout();
    } else if (cmd->methodName == "attributionGetterWithTimeout") {
        this->attributionGetterWithTimeout();
    } else if (cmd->methodName == "idfaGetter") {
        this->idfaGetter();
    } else if (cmd->methodName == "idfvGetter") {
        this->idfvGetter();
    } else if (cmd->methodName == "googleAdIdGetter") {
        this->googleAdIdGetter();
    } else if (cmd->methodName == "amazonAdIdGetter") {
        this->amazonAdIdGetter();
    } else if (cmd->methodName == "sdkVersionGetter") {
        this->sdkVersionGetter();
    } else if (cmd->methodName == "endFirstSessionDelay") {
        this->endFirstSessionDelay();
    } else if (cmd->methodName == "coppaComplianceInDelay") {
        this->coppaComplianceInDelay();
    } else if (cmd->methodName == "playStoreKidsComplianceInDelay") {
        this->playStoreKidsComplianceInDelay();
    } else if (cmd->methodName == "externalDeviceIdInDelay") {
        this->externalDeviceIdInDelay();
    } else if (cmd->methodName == "lastDeeplinkGetter") {
        this->lastDeeplinkGetter();
    }
}

void AdjustCommandExecutor::testOptions() {
    std::map<std::string, std::string> stringTestOptions;
    std::map<std::string, int> intTestOptions;

    if (!this->urlOverwrite.empty()) {
        stringTestOptions["testUrlOverwrite"] = this->urlOverwrite;
    }

    if (this->command->containsParameter(SafeString("basePath"))) {
        std::string basePathStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("basePath")));
        this->basePath = basePathStr;
        localBasePath = basePathStr;
        if (persistentTestDelegates != nullptr) {
            persistentTestDelegates->localBasePath = FString(UTF8_TO_TCHAR(basePathStr.c_str()));
        }
    }
    if (this->command->containsParameter(SafeString("timerInterval"))) {
        intTestOptions["timerIntervalInMilliseconds"] = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("timerInterval"))));
    }
    if (this->command->containsParameter(SafeString("timerStart"))) {
        intTestOptions["timerStartInMilliseconds"] = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("timerStart"))));
    }
    if (this->command->containsParameter(SafeString("sessionInterval"))) {
        intTestOptions["sessionIntervalInMilliseconds"] = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("sessionInterval"))));
    }
    if (this->command->containsParameter(SafeString("subsessionInterval"))) {
        intTestOptions["subsessionIntervalInMilliseconds"] = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("subsessionInterval"))));
    }
    if (this->command->containsParameter(SafeString("attStatus"))) {
        intTestOptions["attStatusInt"] = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("attStatus"))));
    }

    if (this->command->containsParameter(SafeString("idfa"))) {
        stringTestOptions["idfa"] = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("idfa")));
    }

    if (this->command->containsParameter(SafeString("noBackoffWait"))) {
        if (StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("noBackoffWait"))) == "true") {
            intTestOptions["noBackoffWait"] = 1;
        } else {
            intTestOptions["noBackoffWait"] = 0;
        }
    }
    // "false" is default value - AdServices will not be used in test app by default
    intTestOptions["adServicesFrameworkEnabled"] = 0;
    if (this->command->containsParameter(SafeString("adServicesFrameworkEnabled"))) {
        if (StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adServicesFrameworkEnabled"))) == "true") {
            intTestOptions["adServicesFrameworkEnabled"] = 1;
        }
    }

    if (this->command->containsParameter(SafeString("tryInstallReferrer"))) {
        if (StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("tryInstallReferrer"))) == "true") {
            intTestOptions["tryInstallReferrer"] = 1;
        } else {
            intTestOptions["tryInstallReferrer"] = 0;
        }
    }

    if (this->command->containsParameter(SafeString("doNotIgnoreSystemLifecycleBootstrap"))) {
        if (StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("doNotIgnoreSystemLifecycleBootstrap"))) == "true") {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 1;
        } else {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 0;
        }
    }

    bool useTestConnectionOptions = false;

    if (this->command->containsParameter(SafeString("teardown"))) {
        std::vector<SafeString> teardownOptionsSafe = this->command->getParameters(SafeString("teardown"));
        std::vector<std::string> teardownOptions;
        for (const auto& option : teardownOptionsSafe) {
            teardownOptions.push_back(StdStringFromSafeString(option));
        }
        std::vector<std::string>::iterator toIterator = teardownOptions.begin();
        while(toIterator != teardownOptions.end()) {
            std::string teardownOption = (*toIterator);
            if (teardownOption == "resetSdk") {
                intTestOptions["teardown"] = 1;
                if (!this->basePath.empty()) {
                    stringTestOptions["extraPath"] = this->basePath;
                }
                // Android specific
                useTestConnectionOptions = true;
#if PLATFORM_IOS
                // note: Unreal SDK doesn't have teardown method exposed yet
                // this would need to be added if needed
#endif
            }
            if (teardownOption == "deleteState") {
                // Android specific
                intTestOptions["setContext"] = 1;
                // iOS specific
                intTestOptions["deleteState"] = 1;
            }
            if (teardownOption == "resetTest") {
                this->savedEvents.clear();
                this->savedConfigs.clear();
                intTestOptions["timerIntervalInMilliseconds"] = -1;
                intTestOptions["timerStartInMilliseconds"] = -1;
                intTestOptions["sessionIntervalInMilliseconds"] = -1;
                intTestOptions["subsessionIntervalInMilliseconds"] = -1;
                // delegate bindings will be cleared in config() method for each test
            }
            if (teardownOption == "sdk") {
                intTestOptions["teardown"] = 1;
                stringTestOptions.erase("extraPath");
                // Android specific
                intTestOptions["useTestConnectionOptions"] = 0;
            }
            if (teardownOption == "test") {
                this->savedEvents.clear();
                this->savedConfigs.clear();
                this->basePath = "";
                intTestOptions["timerIntervalInMilliseconds"] = -1;
                intTestOptions["timerStartInMilliseconds"] = -1;
                intTestOptions["sessionIntervalInMilliseconds"] = -1;
                intTestOptions["subsessionIntervalInMilliseconds"] = -1;
                // delegate bindings will be cleared in config() method for each test
            }
            toIterator++;
        }
    }

    // Convert maps to Unreal TMap format
    TMap<FString, FString> unrealStringTestOptions;
    for (const auto& pair : stringTestOptions) {
        FString key = FString(UTF8_TO_TCHAR(pair.first.c_str()));
        FString value = FString(UTF8_TO_TCHAR(pair.second.c_str()));
        if (!key.IsEmpty() && !value.IsEmpty()) {
            unrealStringTestOptions.Add(key, value);
        }
    }

    TMap<FString, int32> unrealIntTestOptions;
    for (const auto& pair : intTestOptions) {
        FString key = FString(UTF8_TO_TCHAR(pair.first.c_str()));
        if (!key.IsEmpty()) {
            unrealIntTestOptions.Add(key, pair.second);
        }
    }

    UAdjust::SetTestOptions(unrealStringTestOptions, unrealIntTestOptions);

#if PLATFORM_ANDROID
    if (useTestConnectionOptions == true) {
        TestConnectionOptions::setTestConnectionOptions();
    }
#elif PLATFORM_IOS
#endif
}

void AdjustCommandExecutor::config() {
    int configNumber = 0;
    if (this->command->containsParameter(SafeString("configName"))) {
        std::string configName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("configName")));
        if (!configName.empty()) {
            std::string configNumberStr = configName.substr(configName.length() - 1, 1);
            configNumber = std::stoi(configNumberStr);
        }
    }

    FAdjustConfig* adjustConfig;
    if (this->savedConfigs.count(configNumber) > 0) {
        adjustConfig = &this->savedConfigs[configNumber];
    } else {
        FAdjustConfig newConfig;
        std::string environmentParam = "";
        std::string appToken = "";
        if (this->command->containsParameter(SafeString("environment"))) {
            environmentParam = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("environment")));
        }
        if (this->command->containsParameter(SafeString("appToken"))) {
            appToken = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("appToken")));
        }

        // handle environment parameter
        if (environmentParam == "production") {
            newConfig.Environment = EAdjustEnvironment::Production;
        } else if (environmentParam == "sandbox") {
            newConfig.Environment = EAdjustEnvironment::Sandbox;
        } else {
            // For malformed/invalid environment values, set to an invalid enum value (255 for uint8)
            // this allows the SDK to properly detect and handle the error
            newConfig.Environment = static_cast<EAdjustEnvironment>(255);
        }

        newConfig.AppToken = FString(UTF8_TO_TCHAR(appToken.c_str()));
        newConfig.LogLevel = EAdjustLogLevel::Verbose;
        savedConfigs[configNumber] = newConfig;
        adjustConfig = &this->savedConfigs[configNumber];
    }

    if (this->command->containsParameter(SafeString("logLevel"))) {
        std::string logLevelString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("logLevel")));
        if (logLevelString == "verbose") {
            adjustConfig->LogLevel = EAdjustLogLevel::Verbose;
        } else if (logLevelString == "debug") {
            adjustConfig->LogLevel = EAdjustLogLevel::Debug;
        } else if (logLevelString == "info") {
            adjustConfig->LogLevel = EAdjustLogLevel::Info;
        } else if (logLevelString == "warn") {
            adjustConfig->LogLevel = EAdjustLogLevel::Warn;
        } else if (logLevelString == "error") {
            adjustConfig->LogLevel = EAdjustLogLevel::Error;
        } else if (logLevelString == "assert") {
            adjustConfig->LogLevel = EAdjustLogLevel::Assert;
        } else if (logLevelString == "suppress") {
            adjustConfig->LogLevel = EAdjustLogLevel::Suppress;
        }
    }

    if (this->command->containsParameter(SafeString("checkPasteboard"))) {
        std::string checkPasteboardString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("checkPasteboard")));
        bool checkPasteboard = (checkPasteboardString == "true");
        if (checkPasteboard) {
            adjustConfig->IsLinkMeEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("attConsentWaitingSeconds"))) {
        std::string attConsentWaitingSecondsString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("attConsentWaitingSeconds")));
        adjustConfig->AttConsentWaitingInterval = std::stoi(attConsentWaitingSecondsString);
    }

    if (this->command->containsParameter(SafeString("eventDeduplicationIdsMaxSize"))) {
        std::string eventDeduplicationIdsMaxSizeString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("eventDeduplicationIdsMaxSize")));
        adjustConfig->EventDeduplicationIdsMaxSize = std::stoi(eventDeduplicationIdsMaxSizeString);
    }

    if (this->command->containsParameter(SafeString("coppaCompliant"))) {
        std::string coppaCompliantString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("coppaCompliant")));
        bool coppaCompliant = (coppaCompliantString == "true");
        if (coppaCompliant) {
            adjustConfig->IsCoppaComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("needsCost"))) {
        std::string needsCostString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("needsCost")));
        bool needsCost = (needsCostString == "true");
        if (needsCost) {
            adjustConfig->IsCostDataInAttributionEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("allowIdfaReading"))) {
        std::string allowIdfaReadingString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("allowIdfaReading")));
        bool allowIdfaReading = (allowIdfaReadingString == "true");
        if (!allowIdfaReading) {
            adjustConfig->IsIdfaReadingEnabled = false;
        }
    }

    if (this->command->containsParameter(SafeString("allowAdServicesInfoReading"))) {
        std::string allowAdServicesInfoReadingString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("allowAdServicesInfoReading")));
        bool allowAdServicesInfoReading = (allowAdServicesInfoReadingString == "true");
        if (!allowAdServicesInfoReading) {
            adjustConfig->IsAdServicesEnabled = false;
        }
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter(SafeString("allowAppSetIdReading"))) {
        std::string allowAppSetIdReadingString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("allowAppSetIdReading")));
        bool allowAppSetIdReading = (allowAppSetIdReadingString == "true");
        if (!allowAppSetIdReading) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }

    if (this->command->containsParameter(SafeString("appSetIdReadingEnabled"))) {
        std::string appSetIdReadingEnabledString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("appSetIdReadingEnabled")));
        bool appSetIdReadingEnabled = (appSetIdReadingEnabledString == "true");
        if (!appSetIdReadingEnabled) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }
#endif

    if (this->command->containsParameter(SafeString("allowSkAdNetworkHandling"))) {
        std::string allowSkAdNetworkHandlingString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("allowSkAdNetworkHandling")));
        bool allowSkAdNetworkHandling = (allowSkAdNetworkHandlingString == "true");
        if (allowSkAdNetworkHandling == false) {
            adjustConfig->IsSkanAttributionEnabled = false;
        }
    }

    if (this->command->containsParameter(SafeString("sendInBackground"))) {
        std::string sendInBackgroundString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("sendInBackground")));
        bool sendInBackground = (sendInBackgroundString == "true");
        if (sendInBackground) {
            adjustConfig->IsSendingInBackgroundEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("defaultTracker"))) {
        std::string defaultTracker = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("defaultTracker")));
        adjustConfig->DefaultTracker = FString(UTF8_TO_TCHAR(defaultTracker.c_str()));
    }

    if (this->command->containsParameter(SafeString("externalDeviceId"))) {
        std::string externalDeviceId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("externalDeviceId")));
        adjustConfig->ExternalDeviceId = FString(UTF8_TO_TCHAR(externalDeviceId.c_str()));
    }

    if (this->command->containsParameter(SafeString("playStoreKids"))) {
        std::string playStoreKidsString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("playStoreKids")));
        if (playStoreKidsString == "true") {
            adjustConfig->IsPlayStoreKidsComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("allowAttUsage"))) {
        std::string allowAttUsageString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("allowAttUsage")));
        if (allowAttUsageString == "false") {
            adjustConfig->IsAppTrackingTransparencyUsageEnabled = false;
        }
    }

    if (this->command->containsParameter(SafeString("firstSessionDelayEnabled"))) {
        std::string firstSessionDelayEnabledString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("firstSessionDelayEnabled")));
        if (firstSessionDelayEnabledString == "true") {
            adjustConfig->IsFirstSessionDelayEnabled = true;
        }
    }

    if (this->command->containsParameter(SafeString("storeName"))) {
        std::string storeName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("storeName")));
        adjustConfig->StoreInfo.StoreName = FString(UTF8_TO_TCHAR(storeName.c_str()));
        if (this->command->containsParameter(SafeString("storeAppId"))) {
            std::string storeAppId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("storeAppId")));
            adjustConfig->StoreInfo.StoreAppId = FString(UTF8_TO_TCHAR(storeAppId.c_str()));
        }
    }

    // handle callbacks - register delegates in config() method
    // create or reuse persistent delegate instances
    // (they need to persist to receive broadcasts)
    if (persistentAdjustDelegates == nullptr) {
        persistentAdjustDelegates = NewObject<UAdjustDelegates>(GetTransientPackage());
        persistentAdjustDelegates->AddToRoot();
    }
    
    if (persistentTestDelegates == nullptr) {
        persistentTestDelegates = NewObject<UAdjustTestCommandExecutorDelegates>(GetTransientPackage());
        persistentTestDelegates->AddToRoot();
    }
    
    // clear all delegate bindings first to ensure clean state for each test
    // this prevents callbacks from previous tests from persisting
    persistentAdjustDelegates->OnAttributionChangedDelegate.Clear();
    persistentAdjustDelegates->OnSessionSuccessDelegate.Clear();
    persistentAdjustDelegates->OnSessionFailureDelegate.Clear();
    persistentAdjustDelegates->OnEventSuccessDelegate.Clear();
    persistentAdjustDelegates->OnEventFailureDelegate.Clear();
    persistentAdjustDelegates->OnDeferredDeeplinkDelegate.Clear();
#if PLATFORM_IOS
    persistentAdjustDelegates->OnSkanConversionValueUpdatedDelegate.Clear();
#endif
    
    // update basePath in the delegate
    localBasePath = this->basePath;
    persistentTestDelegates->localBasePath = FString(UTF8_TO_TCHAR(this->basePath.c_str()));
    
    // reset callback activation flags for current test
    persistentTestDelegates->shouldSendAttributionCallback = false;
    persistentTestDelegates->shouldSendSessionSuccessCallback = false;
    persistentTestDelegates->shouldSendSessionFailureCallback = false;
    persistentTestDelegates->shouldSendEventSuccessCallback = false;
    persistentTestDelegates->shouldSendEventFailureCallback = false;
    persistentTestDelegates->shouldSendDeferredDeeplinkCallback = false;
    persistentTestDelegates->shouldSendSkanCallback = false;
    
    // register and activate attribution callback if attributionCallbackSendAll is present
    if (this->command->containsParameter(SafeString("attributionCallbackSendAll"))) {
        persistentTestDelegates->shouldSendAttributionCallback = true;
        persistentAdjustDelegates->OnAttributionChangedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnAttributionChanged);
    }
    
    // register and activate session success callback if sessionCallbackSendSuccess is present
    if (this->command->containsParameter(SafeString("sessionCallbackSendSuccess"))) {
        persistentTestDelegates->shouldSendSessionSuccessCallback = true;
        persistentAdjustDelegates->OnSessionSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionSuccess);
    }
    
    // register and activate session failure callback if sessionCallbackSendFailure is present
    if (this->command->containsParameter(SafeString("sessionCallbackSendFailure"))) {
        persistentTestDelegates->shouldSendSessionFailureCallback = true;
        persistentAdjustDelegates->OnSessionFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionFailure);
    }
    
    // register and activate event success callback if eventCallbackSendSuccess is present
    if (this->command->containsParameter(SafeString("eventCallbackSendSuccess"))) {
        persistentTestDelegates->shouldSendEventSuccessCallback = true;
        persistentAdjustDelegates->OnEventSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventSuccess);
    }
    
    // register and activate event failure callback if eventCallbackSendFailure is present
    if (this->command->containsParameter(SafeString("eventCallbackSendFailure"))) {
        persistentTestDelegates->shouldSendEventFailureCallback = true;
        persistentAdjustDelegates->OnEventFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventFailure);
    }
    
    // register and activate deferred deeplink callback if deferredDeeplinkCallback is present
    if (this->command->containsParameter(SafeString("deferredDeeplinkCallback"))) {
        std::string openDeeplinkString = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("deferredDeeplinkCallback")));
        bool openDeeplink = (openDeeplinkString == "true");
        adjustConfig->IsDeferredDeeplinkOpeningEnabled = openDeeplink;
        persistentTestDelegates->shouldSendDeferredDeeplinkCallback = true;
        persistentAdjustDelegates->OnDeferredDeeplinkDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnDeferredDeeplink);
    }
    
#if PLATFORM_IOS
    // register and activate SKAN callback if skanCallback is present (NOT skanCallbackSendAll)
    if (this->command->containsParameter(SafeString("skanCallback"))) {
        persistentTestDelegates->shouldSendSkanCallback = true;
        persistentAdjustDelegates->OnSkanConversionValueUpdatedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSkanConversionValueUpdated);
    }
#endif
}

void AdjustCommandExecutor::start() {
    config();
    int configNumber = 0;
    if (this->command->containsParameter(SafeString("configName"))) {
        std::string configName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("configName")));
        if (!configName.empty()) {
            std::string configNumberStr = configName.substr(configName.length() - 1, 1);
            configNumber = std::stoi(configNumberStr);
        }
    }

    FAdjustConfig adjustConfig = this->savedConfigs[configNumber];
    UAdjust::InitSdk(adjustConfig);
    this->savedConfigs.erase(0);
}

void AdjustCommandExecutor::event() {
    int eventNumber = 0;
    if (this->command->containsParameter(SafeString("eventName"))) {
        std::string eventName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("eventName")));
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent* adjustEvent;
    if (this->savedEvents.count(eventNumber) > 0) {
        adjustEvent = &this->savedEvents[eventNumber];
    } else {
        std::string eventToken = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("eventToken")));
        FAdjustEvent newEvent;
        newEvent.EventToken = FString(UTF8_TO_TCHAR(eventToken.c_str()));
        savedEvents[eventNumber] = newEvent;
        adjustEvent = &this->savedEvents[eventNumber];
    }

    if (this->command->containsParameter(SafeString("revenue"))) {
        std::vector<SafeString> revenueParamsSafe = this->command->getParameters(SafeString("revenue"));
        std::vector<std::string> revenueParams;
        for (const auto& param : revenueParamsSafe) {
            revenueParams.push_back(StdStringFromSafeString(param));
        }
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustEvent->Revenue = revenue;
            adjustEvent->Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter(SafeString("callbackParams"))) {
        std::vector<SafeString> callbackParamsSafe = this->command->getParameters(SafeString("callbackParams"));
        std::vector<std::string> callbackParams;
        for (const auto& param : callbackParamsSafe) {
            callbackParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustEvent->CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("partnerParams"))) {
        std::vector<SafeString> partnerParamsSafe = this->command->getParameters(SafeString("partnerParams"));
        std::vector<std::string> partnerParams;
        for (const auto& param : partnerParamsSafe) {
            partnerParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustEvent->PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("orderId"))) {
        std::string orderId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("orderId")));
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(orderId.c_str()));
    }

    if (this->command->containsParameter(SafeString("callbackId"))) {
        std::string callbackId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("callbackId")));
        adjustEvent->CallbackId = FString(UTF8_TO_TCHAR(callbackId.c_str()));
    }

    if (this->command->containsParameter(SafeString("transactionId"))) {
        std::string transactionId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionId")));
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    }

    if (this->command->containsParameter(SafeString("productId"))) {
        std::string productId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("productId")));
        adjustEvent->ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    }

    if (this->command->containsParameter(SafeString("deduplicationId"))) {
        std::string deduplicationId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("deduplicationId")));
        adjustEvent->DeduplicationId = FString(UTF8_TO_TCHAR(deduplicationId.c_str()));
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter(SafeString("purchaseToken"))) {
        std::string purchaseToken = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("purchaseToken")));
        adjustEvent->PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));
    }
#endif
}

void AdjustCommandExecutor::trackEvent() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter(SafeString("eventName"))) {
        std::string eventName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("eventName")));
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent adjustEvent = this->savedEvents[eventNumber];
    UAdjust::TrackEvent(adjustEvent);
    this->savedEvents.erase(0);
}

void AdjustCommandExecutor::resume() {
    UAdjust::OnResume();
}

void AdjustCommandExecutor::pause() {
    UAdjust::OnPause();
}

void AdjustCommandExecutor::setEnabled() {
    std::string enabledStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("enabled")));
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::Enable();
    } else {
        UAdjust::Disable();
    }
}

void AdjustCommandExecutor::setOfflineMode() {
    std::string enabledStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("enabled")));
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::SwitchToOfflineMode();
    } else {
        UAdjust::SwitchBackToOnlineMode();
    }
}

void AdjustCommandExecutor::addGlobalCallbackParameter() {
    if (this->command->containsParameter(SafeString("KeyValue"))) {
        std::vector<SafeString> keyValuePairsSafe = this->command->getParameters(SafeString("KeyValue"));
        std::vector<std::string> keyValuePairs;
        for (const auto& param : keyValuePairsSafe) {
            keyValuePairs.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter(SafeString("key")) && this->command->containsParameter(SafeString("value"))) {
        FString key = FString(UTF8_TO_TCHAR(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("key"))).c_str()));
        FString value = FString(UTF8_TO_TCHAR(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("value"))).c_str()));
        UAdjust::AddGlobalCallbackParameter(key, value);
    }
}

void AdjustCommandExecutor::addGlobalPartnerParameter() {
    if (this->command->containsParameter(SafeString("KeyValue"))) {
        std::vector<SafeString> keyValuePairsSafe = this->command->getParameters(SafeString("KeyValue"));
        std::vector<std::string> keyValuePairs;
        for (const auto& param : keyValuePairsSafe) {
            keyValuePairs.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalPartnerParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter(SafeString("key")) && this->command->containsParameter(SafeString("value"))) {
        FString key = FString(UTF8_TO_TCHAR(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("key"))).c_str()));
        FString value = FString(UTF8_TO_TCHAR(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("value"))).c_str()));
        UAdjust::AddGlobalPartnerParameter(key, value);
    }
}

void AdjustCommandExecutor::removeGlobalCallbackParameter() {
    if (this->command->containsParameter(SafeString("key"))) {
        std::vector<SafeString> keysSafe = this->command->getParameters(SafeString("key"));
        std::vector<std::string> keys;
        for (const auto& key : keysSafe) {
            keys.push_back(StdStringFromSafeString(key));
        }
        for (size_t i = 0; i < keys.size(); i++) {
            std::string key = keys[i];
            UAdjust::RemoveGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())));
        }
    }
}

void AdjustCommandExecutor::removeGlobalPartnerParameter() {
    if (this->command->containsParameter(SafeString("key"))) {
        std::vector<SafeString> keysSafe = this->command->getParameters(SafeString("key"));
        std::vector<std::string> keys;
        for (const auto& key : keysSafe) {
            keys.push_back(StdStringFromSafeString(key));
        }
        for (size_t i = 0; i < keys.size(); i++) {
            std::string key = keys[i];
            UAdjust::RemoveGlobalPartnerParameter(FString(UTF8_TO_TCHAR(key.c_str())));
        }
    }
}

void AdjustCommandExecutor::removeGlobalCallbackParameters() {
    UAdjust::RemoveGlobalCallbackParameters();
}

void AdjustCommandExecutor::removeGlobalPartnerParameters() {
    UAdjust::RemoveGlobalPartnerParameters();
}

void AdjustCommandExecutor::setPushToken() {
    std::string token = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("pushToken")));
    UAdjust::SetPushToken(FString(UTF8_TO_TCHAR(token.c_str())));
}

void AdjustCommandExecutor::openDeeplink() {
    std::string deeplink = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("deeplink")));
    std::string referrer = "";
    if (this->command->containsParameter(SafeString("referrer"))) {
        referrer = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("referrer")));
    }
    FAdjustDeeplink adjustDeeplink;
    adjustDeeplink.Deeplink = FString(UTF8_TO_TCHAR(deeplink.c_str()));
    if (!referrer.empty()) {
        adjustDeeplink.Referrer = FString(UTF8_TO_TCHAR(referrer.c_str()));
    }
    UAdjust::ProcessDeeplink(adjustDeeplink);
}

void AdjustCommandExecutor::gdprForgetMe() {
    UAdjust::GdprForgetMe();
}

void AdjustCommandExecutor::trackSubscription() {
#if PLATFORM_IOS
    std::string price = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("revenue")));
    std::string currency = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("currency")));
    std::string transactionId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionId")));
    std::string transactionDate = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionDate")));
    std::string salesRegion = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("salesRegion")));

    FAdjustAppStoreSubscription subscription;
    subscription.Price = std::stod(price);
    subscription.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
    subscription.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    subscription.TransactionDate = FString(UTF8_TO_TCHAR(transactionDate.c_str()));
    subscription.SalesRegion = FString(UTF8_TO_TCHAR(salesRegion.c_str()));

    if (this->command->containsParameter(SafeString("callbackParams"))) {
        std::vector<SafeString> callbackParamsSafe = this->command->getParameters(SafeString("callbackParams"));
        std::vector<std::string> callbackParams;
        for (const auto& param : callbackParamsSafe) {
            callbackParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("partnerParams"))) {
        std::vector<SafeString> partnerParamsSafe = this->command->getParameters(SafeString("partnerParams"));
        std::vector<std::string> partnerParams;
        for (const auto& param : partnerParamsSafe) {
            partnerParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                subscription.PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    UAdjust::TrackAppStoreSubscription(subscription);
#elif PLATFORM_ANDROID
    std::string price = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("revenue")));
    std::string currency = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("currency")));
    std::string sku = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("productId")));
    std::string orderId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionId")));
    std::string signature = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("receipt")));
    std::string purchaseToken = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("purchaseToken")));
    std::string purchaseTime = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionDate")));

    FAdjustPlayStoreSubscription subscription;
    // convert price to micros (multiply by 1,000,000)
    double priceDouble = std::stod(price);
    subscription.Price = (int64)(priceDouble * 1000000);
    subscription.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
    subscription.Sku = FString(UTF8_TO_TCHAR(sku.c_str()));
    subscription.OrderId = FString(UTF8_TO_TCHAR(orderId.c_str()));
    subscription.Signature = FString(UTF8_TO_TCHAR(signature.c_str()));
    subscription.PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));
    subscription.PurchaseTime = std::stoll(purchaseTime);

    if (this->command->containsParameter(SafeString("callbackParams"))) {
        std::vector<SafeString> callbackParamsSafe = this->command->getParameters(SafeString("callbackParams"));
        std::vector<std::string> callbackParams;
        for (const auto& param : callbackParamsSafe) {
            callbackParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("partnerParams"))) {
        std::vector<SafeString> partnerParamsSafe = this->command->getParameters(SafeString("partnerParams"));
        std::vector<std::string> partnerParams;
        for (const auto& param : partnerParamsSafe) {
            partnerParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                subscription.PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    UAdjust::TrackPlayStoreSubscription(subscription);
#endif
}

void AdjustCommandExecutor::trackThirdPartySharing() {
    std::string enabled = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("isEnabled")));
    FAdjustThirdPartySharing thirdPartySharing;
    if (enabled == "true") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Enable;
    } else if (enabled == "false") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Disable;
    } else {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;
    }

    if (this->command->containsParameter(SafeString("granularOptions"))) {
        std::vector<SafeString> granularOptionsSafe = this->command->getParameters(SafeString("granularOptions"));
        std::vector<std::string> granularOptions;
        for (const auto& option : granularOptionsSafe) {
            granularOptions.push_back(StdStringFromSafeString(option));
        }
        for (size_t i = 0; i < granularOptions.size(); i = i + 3) {
            if (i + 2 < granularOptions.size()) {
                std::string partnerName = granularOptions[i];
                std::string key = granularOptions[i + 1];
                std::string value = granularOptions[i + 2];
                if (partnerName.empty() || key.empty() || value.empty()) {
                    continue;
                }
                FAdjustGranularOption granularOption;
                granularOption.GranularOption.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
                thirdPartySharing.GranularOptions.Add(FString(UTF8_TO_TCHAR(partnerName.c_str())), granularOption);
            }
        }
    }

    if (this->command->containsParameter(SafeString("partnerSharingSettings"))) {
        std::vector<SafeString> partnerSharingSettingsSafe = this->command->getParameters(SafeString("partnerSharingSettings"));
        std::vector<std::string> partnerSharingSettings;
        for (const auto& setting : partnerSharingSettingsSafe) {
            partnerSharingSettings.push_back(StdStringFromSafeString(setting));
        }
        for (size_t i = 0; i < partnerSharingSettings.size(); i = i + 3) {
            if (i + 2 < partnerSharingSettings.size()) {
                std::string partnerName = partnerSharingSettings[i];
                std::string key = partnerSharingSettings[i + 1];
                bool value = (partnerSharingSettings[i + 2] == "true");
                if (partnerName.empty() || key.empty()) {
                    continue;
                }
                FAdjustPartnerSharingSetting partnerSetting;
                partnerSetting.PartnerSharingSetting.Add(FString(UTF8_TO_TCHAR(key.c_str())), value);
                thirdPartySharing.PartnerSharingSettings.Add(FString(UTF8_TO_TCHAR(partnerName.c_str())), partnerSetting);
            }
        }
    }

    UAdjust::TrackThirdPartySharing(thirdPartySharing);
}

void AdjustCommandExecutor::trackMeasurementConsent() {
    std::string enabled = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("isEnabled")));
    UAdjust::TrackMeasurementConsent(enabled == "true" ? true : false);
}

void AdjustCommandExecutor::trackAdRevenue() {
    std::string source = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adRevenueSource")));
    FAdjustAdRevenue adjustAdRevenue;
    adjustAdRevenue.Source = FString(UTF8_TO_TCHAR(source.c_str()));

    if (this->command->containsParameter(SafeString("revenue"))) {
        std::vector<SafeString> revenueParamsSafe = this->command->getParameters(SafeString("revenue"));
        std::vector<std::string> revenueParams;
        for (const auto& param : revenueParamsSafe) {
            revenueParams.push_back(StdStringFromSafeString(param));
        }
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustAdRevenue.Revenue = revenue;
            adjustAdRevenue.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter(SafeString("callbackParams"))) {
        std::vector<SafeString> callbackParamsSafe = this->command->getParameters(SafeString("callbackParams"));
        std::vector<std::string> callbackParams;
        for (const auto& param : callbackParamsSafe) {
            callbackParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustAdRevenue.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("partnerParams"))) {
        std::vector<SafeString> partnerParamsSafe = this->command->getParameters(SafeString("partnerParams"));
        std::vector<std::string> partnerParams;
        for (const auto& param : partnerParamsSafe) {
            partnerParams.push_back(StdStringFromSafeString(param));
        }
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustAdRevenue.PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(SafeString("adImpressionsCount"))) {
        int adImpressionsCount = std::stoi(StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adImpressionsCount"))));
        adjustAdRevenue.AdImpressionsCount = adImpressionsCount;
    }

    if (this->command->containsParameter(SafeString("adRevenueNetwork"))) {
        std::string adRevenueNetwork = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adRevenueNetwork")));
        adjustAdRevenue.AdRevenueNetwork = FString(UTF8_TO_TCHAR(adRevenueNetwork.c_str()));
    }

    if (this->command->containsParameter(SafeString("adRevenueUnit"))) {
        std::string adRevenueUnit = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adRevenueUnit")));
        adjustAdRevenue.AdRevenueUnit = FString(UTF8_TO_TCHAR(adRevenueUnit.c_str()));
    }

    if (this->command->containsParameter(SafeString("adRevenuePlacement"))) {
        std::string adRevenuePlacement = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("adRevenuePlacement")));
        adjustAdRevenue.AdRevenuePlacement = FString(UTF8_TO_TCHAR(adRevenuePlacement.c_str()));
    }

    UAdjust::TrackAdRevenue(adjustAdRevenue);
}

void AdjustCommandExecutor::getLastDeeplink() {
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetLastDeeplink([testCallbackId, localExtraPath](const FString& LastDeeplink) {
        FTCHARToUTF8 lastDeeplinkUTF8(*LastDeeplink);
        SafeString lastDeeplinkSafe(lastDeeplinkUTF8.Get(), lastDeeplinkUTF8.Length());
        TestLib::addInfoToSend(SafeString("last_deeplink"), lastDeeplinkSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::verifyPurchase() {
    SafeString localBasePathValue = SafeStringFromStdString(this->basePath);
    
#if PLATFORM_IOS
    std::string productId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("productId")));
    std::string transactionId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("transactionId")));

    FAdjustAppStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAppStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        SafeString verificationStatusSafe(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(SafeString("verification_status"), verificationStatusSafe);
        std::string codeStr = std::to_string(VerificationResult.Code);
        SafeString codeStrSafe = SafeStringFromStdString(codeStr);
        TestLib::addInfoToSend(SafeString("code"), codeStrSafe);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        SafeString messageSafe(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(SafeString("message"), messageSafe);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    std::string productId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("productId")));
    std::string purchaseToken = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("purchaseToken")));

    FAdjustPlayStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyPlayStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        SafeString verificationStatusSafe(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(SafeString("verification_status"), verificationStatusSafe);
        std::string codeStr = std::to_string(VerificationResult.Code);
        SafeString codeStrSafe = SafeStringFromStdString(codeStr);
        TestLib::addInfoToSend(SafeString("code"), codeStrSafe);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        SafeString messageSafe(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(SafeString("message"), messageSafe);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif
}

void AdjustCommandExecutor::verifyTrack() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter(SafeString("eventName"))) {
        std::string eventName = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("eventName")));
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent adjustEvent = this->savedEvents[eventNumber];
    SafeString localBasePathValue = SafeStringFromStdString(this->basePath);

#if PLATFORM_IOS
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAndTrackAppStorePurchase(adjustEvent, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        SafeString verificationStatusSafe(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(SafeString("verification_status"), verificationStatusSafe);
        std::string codeStr = std::to_string(VerificationResult.Code);
        SafeString codeStrSafe = SafeStringFromStdString(codeStr);
        TestLib::addInfoToSend(SafeString("code"), codeStrSafe);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        SafeString messageSafe(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(SafeString("message"), messageSafe);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAndTrackPlayStorePurchase(adjustEvent, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        SafeString verificationStatusSafe(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(SafeString("verification_status"), verificationStatusSafe);
        std::string codeStr = std::to_string(VerificationResult.Code);
        SafeString codeStrSafe = SafeStringFromStdString(codeStr);
        TestLib::addInfoToSend(SafeString("code"), codeStrSafe);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        SafeString messageSafe(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(SafeString("message"), messageSafe);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif

    this->savedEvents.erase(0);
}

void AdjustCommandExecutor::processDeeplink() {
    std::string deeplink = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("deeplink")));
    std::string referrer = "";
    if (this->command->containsParameter(SafeString("referrer"))) {
        referrer = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("referrer")));
    }
    FAdjustDeeplink adjustDeeplink;
    adjustDeeplink.Deeplink = FString(UTF8_TO_TCHAR(deeplink.c_str()));
    if (!referrer.empty()) {
        adjustDeeplink.Referrer = FString(UTF8_TO_TCHAR(referrer.c_str()));
    }
    
    // capture basePath at the time processDeeplink is called
    // this ensures that even if the deeplink is saved and processed later
    // the callback will use the correct basePath for the test that called processDeeplink
    SafeString localBasePathValue = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API - the lambda captures basePath by value
    // so it will use the correct basePath even if called before SDK initialization
    // and processed later after other tests have started
    UAdjust::ProcessAndResolveDeeplink(adjustDeeplink, [localBasePathValue](const FString& ResolvedLink) {
        FTCHARToUTF8 resolvedLinkUTF8(*ResolvedLink);
        SafeString resolvedLinkSafe(resolvedLinkUTF8.Get(), resolvedLinkUTF8.Length());
        TestLib::addInfoToSend(SafeString("resolved_link"), resolvedLinkSafe);
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::attributionGetter() {
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localBasePathValue = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttribution([testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(SafeString("attribution"), SafeString("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(SafeString("attribution"), SafeString("null"));
#endif
        } else {
            FTCHARToUTF8 trackerTokenUTF8(*Attribution.TrackerToken);
            SafeString trackerTokenSafe(trackerTokenUTF8.Get(), trackerTokenUTF8.Length());
            TestLib::addInfoToSend(SafeString("tracker_token"), trackerTokenSafe);
            
            FTCHARToUTF8 trackerNameUTF8(*Attribution.TrackerName);
            SafeString trackerNameSafe(trackerNameUTF8.Get(), trackerNameUTF8.Length());
            TestLib::addInfoToSend(SafeString("tracker_name"), trackerNameSafe);
            
            FTCHARToUTF8 networkUTF8(*Attribution.Network);
            SafeString networkSafe(networkUTF8.Get(), networkUTF8.Length());
            TestLib::addInfoToSend(SafeString("network"), networkSafe);
            
            FTCHARToUTF8 campaignUTF8(*Attribution.Campaign);
            SafeString campaignSafe(campaignUTF8.Get(), campaignUTF8.Length());
            TestLib::addInfoToSend(SafeString("campaign"), campaignSafe);
            
            FTCHARToUTF8 adgroupUTF8(*Attribution.Adgroup);
            SafeString adgroupSafe(adgroupUTF8.Get(), adgroupUTF8.Length());
            TestLib::addInfoToSend(SafeString("adgroup"), adgroupSafe);
            
            FTCHARToUTF8 creativeUTF8(*Attribution.Creative);
            SafeString creativeSafe(creativeUTF8.Get(), creativeUTF8.Length());
            TestLib::addInfoToSend(SafeString("creative"), creativeSafe);
            
            FTCHARToUTF8 clickLabelUTF8(*Attribution.ClickLabel);
            SafeString clickLabelSafe(clickLabelUTF8.Get(), clickLabelUTF8.Length());
            TestLib::addInfoToSend(SafeString("click_label"), clickLabelSafe);
            
            FTCHARToUTF8 costTypeUTF8(*Attribution.CostType);
            SafeString costTypeSafe(costTypeUTF8.Get(), costTypeUTF8.Length());
            TestLib::addInfoToSend(SafeString("cost_type"), costTypeSafe);
            
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            std::string costAmountStr = sstream.str();
            SafeString costAmountSafe = SafeStringFromStdString(costAmountStr);
            TestLib::addInfoToSend(SafeString("cost_amount"), costAmountSafe);
            
            FTCHARToUTF8 costCurrencyUTF8(*Attribution.CostCurrency);
            SafeString costCurrencySafe(costCurrencyUTF8.Get(), costCurrencyUTF8.Length());
            TestLib::addInfoToSend(SafeString("cost_currency"), costCurrencySafe);
#if PLATFORM_ANDROID
            FTCHARToUTF8 fbInstallReferrerUTF8(*Attribution.FbInstallReferrer);
            SafeString fbInstallReferrerSafe(fbInstallReferrerUTF8.Get(), fbInstallReferrerUTF8.Length());
            TestLib::addInfoToSend(SafeString("fb_install_referrer"), fbInstallReferrerSafe);
            
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            SafeString jsonResponseSafe(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            TestLib::addInfoToSend(SafeString("json_response"), jsonResponseSafe);
#elif PLATFORM_IOS
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonStr = std::string(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            SafeString jsonStrSafe = SafeStringFromStdString(jsonStr);
            TestLib::addInfoToSend(SafeString("json_response"), jsonStrSafe);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::adidGetter() {
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdid([testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(SafeString("adid"), SafeString("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(SafeString("adid"), SafeString("null"));
#endif
        } else {
            FTCHARToUTF8 adidUTF8(*Adid);
            SafeString adidSafe(adidUTF8.Get(), adidUTF8.Length());
            TestLib::addInfoToSend(SafeString("adid"), adidSafe);
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::adidGetterWithTimeout() {
    std::string timeoutStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("timeout")));
    int timeout = std::stoi(timeoutStr);
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdidWithTimeout(timeout, [testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(SafeString("adid"), SafeString("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(SafeString("adid"), SafeString("null"));
#endif
        } else {
            FTCHARToUTF8 adidUTF8(*Adid);
            SafeString adidSafe(adidUTF8.Get(), adidUTF8.Length());
            TestLib::addInfoToSend(SafeString("adid"), adidSafe);
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::attributionGetterWithTimeout() {
    std::string timeoutStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("timeout")));
    int timeout = std::stoi(timeoutStr);
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localBasePathValue = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttributionWithTimeout(timeout, [testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(SafeString("attribution"), SafeString("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(SafeString("attribution"), SafeString("null"));
#endif
        } else {
            FTCHARToUTF8 trackerTokenUTF8(*Attribution.TrackerToken);
            SafeString trackerTokenSafe(trackerTokenUTF8.Get(), trackerTokenUTF8.Length());
            TestLib::addInfoToSend(SafeString("tracker_token"), trackerTokenSafe);
            
            FTCHARToUTF8 trackerNameUTF8(*Attribution.TrackerName);
            SafeString trackerNameSafe(trackerNameUTF8.Get(), trackerNameUTF8.Length());
            TestLib::addInfoToSend(SafeString("tracker_name"), trackerNameSafe);
            
            FTCHARToUTF8 networkUTF8(*Attribution.Network);
            SafeString networkSafe(networkUTF8.Get(), networkUTF8.Length());
            TestLib::addInfoToSend(SafeString("network"), networkSafe);
            
            FTCHARToUTF8 campaignUTF8(*Attribution.Campaign);
            SafeString campaignSafe(campaignUTF8.Get(), campaignUTF8.Length());
            TestLib::addInfoToSend(SafeString("campaign"), campaignSafe);
            
            FTCHARToUTF8 adgroupUTF8(*Attribution.Adgroup);
            SafeString adgroupSafe(adgroupUTF8.Get(), adgroupUTF8.Length());
            TestLib::addInfoToSend(SafeString("adgroup"), adgroupSafe);
            
            FTCHARToUTF8 creativeUTF8(*Attribution.Creative);
            SafeString creativeSafe(creativeUTF8.Get(), creativeUTF8.Length());
            TestLib::addInfoToSend(SafeString("creative"), creativeSafe);
            
            FTCHARToUTF8 clickLabelUTF8(*Attribution.ClickLabel);
            SafeString clickLabelSafe(clickLabelUTF8.Get(), clickLabelUTF8.Length());
            TestLib::addInfoToSend(SafeString("click_label"), clickLabelSafe);
            
            FTCHARToUTF8 costTypeUTF8(*Attribution.CostType);
            SafeString costTypeSafe(costTypeUTF8.Get(), costTypeUTF8.Length());
            TestLib::addInfoToSend(SafeString("cost_type"), costTypeSafe);
            
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            std::string costAmountStr = sstream.str();
            SafeString costAmountSafe = SafeStringFromStdString(costAmountStr);
            TestLib::addInfoToSend(SafeString("cost_amount"), costAmountSafe);
            
            FTCHARToUTF8 costCurrencyUTF8(*Attribution.CostCurrency);
            SafeString costCurrencySafe(costCurrencyUTF8.Get(), costCurrencyUTF8.Length());
            TestLib::addInfoToSend(SafeString("cost_currency"), costCurrencySafe);
#if PLATFORM_ANDROID
            FTCHARToUTF8 fbInstallReferrerUTF8(*Attribution.FbInstallReferrer);
            SafeString fbInstallReferrerSafe(fbInstallReferrerUTF8.Get(), fbInstallReferrerUTF8.Length());
            TestLib::addInfoToSend(SafeString("fb_install_referrer"), fbInstallReferrerSafe);
            
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            SafeString jsonResponseSafe(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            TestLib::addInfoToSend(SafeString("json_response"), jsonResponseSafe);
#elif PLATFORM_IOS
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonStr = std::string(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            SafeString jsonStrSafe = SafeStringFromStdString(jsonStr);
            TestLib::addInfoToSend(SafeString("json_response"), jsonStrSafe);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::idfaGetter() {
#if PLATFORM_IOS
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfa([testCallbackId, localExtraPath](const FString& Idfa) {
        FTCHARToUTF8 idfaUTF8(*Idfa);
        SafeString idfaSafe(idfaUTF8.Get(), idfaUTF8.Length());
        TestLib::addInfoToSend(SafeString("idfa"), idfaSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::idfvGetter() {
#if PLATFORM_IOS
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfv([testCallbackId, localExtraPath](const FString& Idfv) {
        FTCHARToUTF8 idfvUTF8(*Idfv);
        SafeString idfvSafe(idfvUTF8.Get(), idfvUTF8.Length());
        TestLib::addInfoToSend(SafeString("idfv"), idfvSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::googleAdIdGetter() {
#if PLATFORM_ANDROID
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetGoogleAdId([testCallbackId, localExtraPath](const FString& GoogleAdId) {
        FTCHARToUTF8 googleAdIdUTF8(*GoogleAdId);
        SafeString googleAdIdSafe(googleAdIdUTF8.Get(), googleAdIdUTF8.Length());
        TestLib::addInfoToSend(SafeString("gps_adid"), googleAdIdSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::amazonAdIdGetter() {
#if PLATFORM_ANDROID
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAmazonAdId([testCallbackId, localExtraPath](const FString& AmazonAdId) {
        FTCHARToUTF8 amazonAdIdUTF8(*AmazonAdId);
        SafeString amazonAdIdSafe(amazonAdIdUTF8.Get(), amazonAdIdUTF8.Length());
        TestLib::addInfoToSend(SafeString("fire_adid"), amazonAdIdSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::sdkVersionGetter() {
    SafeString testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        std::string testCallbackIdStr = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
        testCallbackId = SafeStringFromStdString(testCallbackIdStr);
    }
    SafeString localExtraPath = SafeStringFromStdString(this->basePath);
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetSdkVersion([testCallbackId, localExtraPath](const FString& SdkVersion) {
        FTCHARToUTF8 sdkVersionUTF8(*SdkVersion);
        SafeString sdkVersionSafe(sdkVersionUTF8.Get(), sdkVersionUTF8.Length());
        TestLib::addInfoToSend(SafeString("sdk_version"), sdkVersionSafe);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(SafeString("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::lastDeeplinkGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(SafeString("testCallbackId"))) {
        testCallbackId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("testCallbackId")));
    }
    std::string localExtraPath = this->basePath;
    
    // create new delegate objects for each call to support burst/concurrent callbacks
    // each call gets its own delegate object, so when callback fires, all will receive it
    UAdjustDelegates* delegates = NewObject<UAdjustDelegates>(GetTransientPackage());
    delegates->AddToRoot();
    UAdjustTestCommandExecutorDelegates* testDelegates = NewObject<UAdjustTestCommandExecutorDelegates>(GetTransientPackage());
    testDelegates->AddToRoot();
    testDelegates->testCallbackId = FString(UTF8_TO_TCHAR(testCallbackId.c_str()));
    testDelegates->localExtraPath = FString(UTF8_TO_TCHAR(localExtraPath.c_str()));
    delegates->OnLastDeeplinkGetterDelegate.AddDynamic(testDelegates, &UAdjustTestCommandExecutorDelegates::OnLastDeeplinkReceived);
    
    UAdjust::GetLastDeeplink();
}

void AdjustCommandExecutor::endFirstSessionDelay() {
    UAdjust::EndFirstSessionDelay();
}

void AdjustCommandExecutor::coppaComplianceInDelay() {
    std::string strIsEnabled = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("isEnabled")));
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnableCoppaComplianceInDelay();
    } else {
        UAdjust::DisableCoppaComplianceInDelay();
    }
}

void AdjustCommandExecutor::playStoreKidsComplianceInDelay() {
    std::string strIsEnabled = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("isEnabled")));
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnablePlayStoreKidsComplianceInDelay();
    } else {
        UAdjust::DisablePlayStoreKidsComplianceInDelay();
    }
}

void AdjustCommandExecutor::externalDeviceIdInDelay() {
    std::string externalDeviceId = StdStringFromSafeString(this->command->getFirstParameterValue(SafeString("externalDeviceId")));
    UAdjust::SetExternalDeviceIdInDelay(FString(UTF8_TO_TCHAR(externalDeviceId.c_str())));
}
