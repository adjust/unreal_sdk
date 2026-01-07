//
//  AdjustCommandExecutor.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
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

    if (this->command->containsParameter(std::string("basePath"))) {
        std::string basePathStr = this->command->getFirstParameterValue(std::string("basePath"));
        this->basePath = basePathStr;
        localBasePath = basePathStr;
        if (persistentTestDelegates != nullptr) {
            persistentTestDelegates->localBasePath = FString(UTF8_TO_TCHAR(basePathStr.c_str()));
        }
    }
    if (this->command->containsParameter(std::string("timerInterval"))) {
        intTestOptions["timerIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue(std::string("timerInterval")));
    }
    if (this->command->containsParameter(std::string("timerStart"))) {
        intTestOptions["timerStartInMilliseconds"] = std::stoi(this->command->getFirstParameterValue(std::string("timerStart")));
    }
    if (this->command->containsParameter(std::string("sessionInterval"))) {
        intTestOptions["sessionIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue(std::string("sessionInterval")));
    }
    if (this->command->containsParameter(std::string("subsessionInterval"))) {
        intTestOptions["subsessionIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue(std::string("subsessionInterval")));
    }
    if (this->command->containsParameter(std::string("attStatus"))) {
        intTestOptions["attStatusInt"] = std::stoi(this->command->getFirstParameterValue(std::string("attStatus")));
    }

    if (this->command->containsParameter(std::string("idfa"))) {
        stringTestOptions["idfa"] = this->command->getFirstParameterValue(std::string("idfa"));
    }

    if (this->command->containsParameter(std::string("noBackoffWait"))) {
        if (this->command->getFirstParameterValue(std::string("noBackoffWait")) == "true") {
            intTestOptions["noBackoffWait"] = 1;
        } else {
            intTestOptions["noBackoffWait"] = 0;
        }
    }
    // "false" is default value - AdServices will not be used in test app by default
    intTestOptions["adServicesFrameworkEnabled"] = 0;
    if (this->command->containsParameter(std::string("adServicesFrameworkEnabled"))) {
        if (this->command->getFirstParameterValue(std::string("adServicesFrameworkEnabled")) == "true") {
            intTestOptions["adServicesFrameworkEnabled"] = 1;
        }
    }

    if (this->command->containsParameter(std::string("tryInstallReferrer"))) {
        if (this->command->getFirstParameterValue(std::string("tryInstallReferrer")) == "true") {
            intTestOptions["tryInstallReferrer"] = 1;
        } else {
            intTestOptions["tryInstallReferrer"] = 0;
        }
    }

    if (this->command->containsParameter(std::string("doNotIgnoreSystemLifecycleBootstrap"))) {
        if (this->command->getFirstParameterValue(std::string("doNotIgnoreSystemLifecycleBootstrap")) == "true") {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 1;
        } else {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 0;
        }
    }

    bool useTestConnectionOptions = false;

    if (this->command->containsParameter(std::string("teardown"))) {
        std::vector<std::string> teardownOptions = this->command->getParameters(std::string("teardown"));
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
    if (this->command->containsParameter(std::string("configName"))) {
        std::string configName = this->command->getFirstParameterValue(std::string("configName"));
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
        if (this->command->containsParameter(std::string("environment"))) {
            environmentParam = this->command->getFirstParameterValue(std::string("environment"));
        }
        if (this->command->containsParameter(std::string("appToken"))) {
            appToken = this->command->getFirstParameterValue(std::string("appToken"));
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

    if (this->command->containsParameter(std::string("logLevel"))) {
        std::string logLevelString = this->command->getFirstParameterValue(std::string("logLevel"));
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

    if (this->command->containsParameter(std::string("checkPasteboard"))) {
        std::string checkPasteboardString = this->command->getFirstParameterValue(std::string("checkPasteboard"));
        bool checkPasteboard = (checkPasteboardString == "true");
        if (checkPasteboard) {
            adjustConfig->IsLinkMeEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("attConsentWaitingSeconds"))) {
        std::string attConsentWaitingSecondsString = this->command->getFirstParameterValue(std::string("attConsentWaitingSeconds"));
        adjustConfig->AttConsentWaitingInterval = std::stoi(attConsentWaitingSecondsString);
    }

    if (this->command->containsParameter(std::string("eventDeduplicationIdsMaxSize"))) {
        std::string eventDeduplicationIdsMaxSizeString = this->command->getFirstParameterValue(std::string("eventDeduplicationIdsMaxSize"));
        adjustConfig->EventDeduplicationIdsMaxSize = std::stoi(eventDeduplicationIdsMaxSizeString);
    }

    if (this->command->containsParameter(std::string("coppaCompliant"))) {
        std::string coppaCompliantString = this->command->getFirstParameterValue(std::string("coppaCompliant"));
        bool coppaCompliant = (coppaCompliantString == "true");
        if (coppaCompliant) {
            adjustConfig->IsCoppaComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("needsCost"))) {
        std::string needsCostString = this->command->getFirstParameterValue(std::string("needsCost"));
        bool needsCost = (needsCostString == "true");
        if (needsCost) {
            adjustConfig->IsCostDataInAttributionEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("allowIdfaReading"))) {
        std::string allowIdfaReadingString = this->command->getFirstParameterValue(std::string("allowIdfaReading"));
        bool allowIdfaReading = (allowIdfaReadingString == "true");
        if (!allowIdfaReading) {
            adjustConfig->IsIdfaReadingEnabled = false;
        }
    }

    if (this->command->containsParameter(std::string("allowAdServicesInfoReading"))) {
        std::string allowAdServicesInfoReadingString = this->command->getFirstParameterValue(std::string("allowAdServicesInfoReading"));
        bool allowAdServicesInfoReading = (allowAdServicesInfoReadingString == "true");
        if (!allowAdServicesInfoReading) {
            adjustConfig->IsAdServicesEnabled = false;
        }
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter(std::string("allowAppSetIdReading"))) {
        std::string allowAppSetIdReadingString = this->command->getFirstParameterValue(std::string("allowAppSetIdReading"));
        bool allowAppSetIdReading = (allowAppSetIdReadingString == "true");
        if (!allowAppSetIdReading) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }

    if (this->command->containsParameter(std::string("appSetIdReadingEnabled"))) {
        std::string appSetIdReadingEnabledString = this->command->getFirstParameterValue(std::string("appSetIdReadingEnabled"));
        bool appSetIdReadingEnabled = (appSetIdReadingEnabledString == "true");
        if (!appSetIdReadingEnabled) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }
#endif

    if (this->command->containsParameter(std::string("allowSkAdNetworkHandling"))) {
        std::string allowSkAdNetworkHandlingString = this->command->getFirstParameterValue(std::string("allowSkAdNetworkHandling"));
        bool allowSkAdNetworkHandling = (allowSkAdNetworkHandlingString == "true");
        if (allowSkAdNetworkHandling == false) {
            adjustConfig->IsSkanAttributionEnabled = false;
        }
    }

    if (this->command->containsParameter(std::string("sendInBackground"))) {
        std::string sendInBackgroundString = this->command->getFirstParameterValue(std::string("sendInBackground"));
        bool sendInBackground = (sendInBackgroundString == "true");
        if (sendInBackground) {
            adjustConfig->IsSendingInBackgroundEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("defaultTracker"))) {
        std::string defaultTracker = this->command->getFirstParameterValue(std::string("defaultTracker"));
        adjustConfig->DefaultTracker = FString(UTF8_TO_TCHAR(defaultTracker.c_str()));
    }

    if (this->command->containsParameter(std::string("externalDeviceId"))) {
        std::string externalDeviceId = this->command->getFirstParameterValue(std::string("externalDeviceId"));
        adjustConfig->ExternalDeviceId = FString(UTF8_TO_TCHAR(externalDeviceId.c_str()));
    }

    if (this->command->containsParameter(std::string("playStoreKids"))) {
        std::string playStoreKidsString = this->command->getFirstParameterValue(std::string("playStoreKids"));
        if (playStoreKidsString == "true") {
            adjustConfig->IsPlayStoreKidsComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("allowAttUsage"))) {
        std::string allowAttUsageString = this->command->getFirstParameterValue(std::string("allowAttUsage"));
        if (allowAttUsageString == "false") {
            adjustConfig->IsAppTrackingTransparencyUsageEnabled = false;
        }
    }

    if (this->command->containsParameter(std::string("firstSessionDelayEnabled"))) {
        std::string firstSessionDelayEnabledString = this->command->getFirstParameterValue(std::string("firstSessionDelayEnabled"));
        if (firstSessionDelayEnabledString == "true") {
            adjustConfig->IsFirstSessionDelayEnabled = true;
        }
    }

    if (this->command->containsParameter(std::string("storeName"))) {
        std::string storeName = this->command->getFirstParameterValue(std::string("storeName"));
        adjustConfig->StoreInfo.StoreName = FString(UTF8_TO_TCHAR(storeName.c_str()));
        if (this->command->containsParameter(std::string("storeAppId"))) {
            std::string storeAppId = this->command->getFirstParameterValue(std::string("storeAppId"));
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
    if (this->command->containsParameter(std::string("attributionCallbackSendAll"))) {
        persistentTestDelegates->shouldSendAttributionCallback = true;
        persistentAdjustDelegates->OnAttributionChangedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnAttributionChanged);
    }
    
    // register and activate session success callback if sessionCallbackSendSuccess is present
    if (this->command->containsParameter(std::string("sessionCallbackSendSuccess"))) {
        persistentTestDelegates->shouldSendSessionSuccessCallback = true;
        persistentAdjustDelegates->OnSessionSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionSuccess);
    }
    
    // register and activate session failure callback if sessionCallbackSendFailure is present
    if (this->command->containsParameter(std::string("sessionCallbackSendFailure"))) {
        persistentTestDelegates->shouldSendSessionFailureCallback = true;
        persistentAdjustDelegates->OnSessionFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionFailure);
    }
    
    // register and activate event success callback if eventCallbackSendSuccess is present
    if (this->command->containsParameter(std::string("eventCallbackSendSuccess"))) {
        persistentTestDelegates->shouldSendEventSuccessCallback = true;
        persistentAdjustDelegates->OnEventSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventSuccess);
    }
    
    // register and activate event failure callback if eventCallbackSendFailure is present
    if (this->command->containsParameter(std::string("eventCallbackSendFailure"))) {
        persistentTestDelegates->shouldSendEventFailureCallback = true;
        persistentAdjustDelegates->OnEventFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventFailure);
    }
    
    // register and activate deferred deeplink callback if deferredDeeplinkCallback is present
    if (this->command->containsParameter(std::string("deferredDeeplinkCallback"))) {
        std::string openDeeplinkString = this->command->getFirstParameterValue(std::string("deferredDeeplinkCallback"));
        bool openDeeplink = (openDeeplinkString == "true");
        adjustConfig->IsDeferredDeeplinkOpeningEnabled = openDeeplink;
        persistentTestDelegates->shouldSendDeferredDeeplinkCallback = true;
        persistentAdjustDelegates->OnDeferredDeeplinkDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnDeferredDeeplink);
    }
    
#if PLATFORM_IOS
    // register and activate SKAN callback if skanCallback is present (NOT skanCallbackSendAll)
    if (this->command->containsParameter(std::string("skanCallback"))) {
        persistentTestDelegates->shouldSendSkanCallback = true;
        persistentAdjustDelegates->OnSkanConversionValueUpdatedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSkanConversionValueUpdated);
    }
#endif
}

void AdjustCommandExecutor::start() {
    config();
    int configNumber = 0;
    if (this->command->containsParameter(std::string("configName"))) {
        std::string configName = this->command->getFirstParameterValue(std::string("configName"));
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
    if (this->command->containsParameter(std::string("eventName"))) {
        std::string eventName = this->command->getFirstParameterValue(std::string("eventName"));
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent* adjustEvent;
    if (this->savedEvents.count(eventNumber) > 0) {
        adjustEvent = &this->savedEvents[eventNumber];
    } else {
        std::string eventToken = this->command->getFirstParameterValue(std::string("eventToken"));
        FAdjustEvent newEvent;
        newEvent.EventToken = FString(UTF8_TO_TCHAR(eventToken.c_str()));
        savedEvents[eventNumber] = newEvent;
        adjustEvent = &this->savedEvents[eventNumber];
    }

    if (this->command->containsParameter(std::string("revenue"))) {
        std::vector<std::string> revenueParams = this->command->getParameters(std::string("revenue"));
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustEvent->Revenue = revenue;
            adjustEvent->Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter(std::string("callbackParams"))) {
        std::vector<std::string> callbackParams = this->command->getParameters(std::string("callbackParams"));
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustEvent->CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("partnerParams"))) {
        std::vector<std::string> partnerParams = this->command->getParameters(std::string("partnerParams"));
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustEvent->PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("orderId"))) {
        std::string orderId = this->command->getFirstParameterValue(std::string("orderId"));
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(orderId.c_str()));
    }

    if (this->command->containsParameter(std::string("callbackId"))) {
        std::string callbackId = this->command->getFirstParameterValue(std::string("callbackId"));
        adjustEvent->CallbackId = FString(UTF8_TO_TCHAR(callbackId.c_str()));
    }

    if (this->command->containsParameter(std::string("transactionId"))) {
        std::string transactionId = this->command->getFirstParameterValue(std::string("transactionId"));
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    }

    if (this->command->containsParameter(std::string("productId"))) {
        std::string productId = this->command->getFirstParameterValue(std::string("productId"));
        adjustEvent->ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    }

    if (this->command->containsParameter(std::string("deduplicationId"))) {
        std::string deduplicationId = this->command->getFirstParameterValue(std::string("deduplicationId"));
        adjustEvent->DeduplicationId = FString(UTF8_TO_TCHAR(deduplicationId.c_str()));
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter(std::string("purchaseToken"))) {
        std::string purchaseToken = this->command->getFirstParameterValue(std::string("purchaseToken"));
        adjustEvent->PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));
    }
#endif
}

void AdjustCommandExecutor::trackEvent() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter(std::string("eventName"))) {
        std::string eventName = this->command->getFirstParameterValue(std::string("eventName"));
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
    std::string enabledStr = this->command->getFirstParameterValue(std::string("enabled"));
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::Enable();
    } else {
        UAdjust::Disable();
    }
}

void AdjustCommandExecutor::setOfflineMode() {
    std::string enabledStr = this->command->getFirstParameterValue(std::string("enabled"));
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::SwitchToOfflineMode();
    } else {
        UAdjust::SwitchBackToOnlineMode();
    }
}

void AdjustCommandExecutor::addGlobalCallbackParameter() {
    if (this->command->containsParameter(std::string("KeyValue"))) {
        std::vector<std::string> keyValuePairs = this->command->getParameters(std::string("KeyValue"));
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter(std::string("key")) && this->command->containsParameter(std::string("value"))) {
        FString key = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue(std::string("key")).c_str()));
        FString value = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue(std::string("value")).c_str()));
        UAdjust::AddGlobalCallbackParameter(key, value);
    }
}

void AdjustCommandExecutor::addGlobalPartnerParameter() {
    if (this->command->containsParameter(std::string("KeyValue"))) {
        std::vector<std::string> keyValuePairs = this->command->getParameters(std::string("KeyValue"));
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalPartnerParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter(std::string("key")) && this->command->containsParameter(std::string("value"))) {
        FString key = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue(std::string("key")).c_str()));
        FString value = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue(std::string("value")).c_str()));
        UAdjust::AddGlobalPartnerParameter(key, value);
    }
}

void AdjustCommandExecutor::removeGlobalCallbackParameter() {
    if (this->command->containsParameter(std::string("key"))) {
        std::vector<std::string> keys = this->command->getParameters(std::string("key"));
        for (size_t i = 0; i < keys.size(); i++) {
            std::string key = keys[i];
            UAdjust::RemoveGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())));
        }
    }
}

void AdjustCommandExecutor::removeGlobalPartnerParameter() {
    if (this->command->containsParameter(std::string("key"))) {
        std::vector<std::string> keys = this->command->getParameters(std::string("key"));
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
    std::string token = this->command->getFirstParameterValue(std::string("pushToken"));
    UAdjust::SetPushToken(FString(UTF8_TO_TCHAR(token.c_str())));
}

void AdjustCommandExecutor::openDeeplink() {
    std::string deeplink = this->command->getFirstParameterValue(std::string("deeplink"));
    std::string referrer = "";
    if (this->command->containsParameter(std::string("referrer"))) {
        referrer = this->command->getFirstParameterValue(std::string("referrer"));
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
    std::string price = this->command->getFirstParameterValue(std::string("revenue"));
    std::string currency = this->command->getFirstParameterValue(std::string("currency"));
    std::string transactionId = this->command->getFirstParameterValue(std::string("transactionId"));
    std::string transactionDate = this->command->getFirstParameterValue(std::string("transactionDate"));
    std::string salesRegion = this->command->getFirstParameterValue(std::string("salesRegion"));

    FAdjustAppStoreSubscription subscription;
    subscription.Price = std::stod(price);
    subscription.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
    subscription.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    subscription.TransactionDate = FString(UTF8_TO_TCHAR(transactionDate.c_str()));
    subscription.SalesRegion = FString(UTF8_TO_TCHAR(salesRegion.c_str()));

    if (this->command->containsParameter(std::string("callbackParams"))) {
        std::vector<std::string> callbackParams = this->command->getParameters(std::string("callbackParams"));
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("partnerParams"))) {
        std::vector<std::string> partnerParams = this->command->getParameters(std::string("partnerParams"));
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
    std::string price = this->command->getFirstParameterValue(std::string("revenue"));
    std::string currency = this->command->getFirstParameterValue(std::string("currency"));
    std::string sku = this->command->getFirstParameterValue(std::string("productId"));
    std::string orderId = this->command->getFirstParameterValue(std::string("transactionId"));
    std::string signature = this->command->getFirstParameterValue(std::string("receipt"));
    std::string purchaseToken = this->command->getFirstParameterValue(std::string("purchaseToken"));
    std::string purchaseTime = this->command->getFirstParameterValue(std::string("transactionDate"));

    FAdjustPlayStoreSubscription subscription;
    // price should be passed as-is (Android SDK expects the value directly, not multiplied)
    subscription.Price = std::stoll(price);
    subscription.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
    subscription.Sku = FString(UTF8_TO_TCHAR(sku.c_str()));
    subscription.OrderId = FString(UTF8_TO_TCHAR(orderId.c_str()));
    subscription.Signature = FString(UTF8_TO_TCHAR(signature.c_str()));
    subscription.PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));
    subscription.PurchaseTime = std::stoll(purchaseTime);

    if (this->command->containsParameter(std::string("callbackParams"))) {
        std::vector<std::string> callbackParams = this->command->getParameters(std::string("callbackParams"));
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("partnerParams"))) {
        std::vector<std::string> partnerParams = this->command->getParameters(std::string("partnerParams"));
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
    std::string enabled = this->command->getFirstParameterValue(std::string("isEnabled"));
    FAdjustThirdPartySharing thirdPartySharing;
    if (enabled == "true") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Enable;
    } else if (enabled == "false") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Disable;
    } else {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;
    }

    if (this->command->containsParameter(std::string("granularOptions"))) {
        std::vector<std::string> granularOptions = this->command->getParameters(std::string("granularOptions"));
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

    if (this->command->containsParameter(std::string("partnerSharingSettings"))) {
        std::vector<std::string> partnerSharingSettings = this->command->getParameters(std::string("partnerSharingSettings"));
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
    std::string enabled = this->command->getFirstParameterValue(std::string("isEnabled"));
    UAdjust::TrackMeasurementConsent(enabled == "true" ? true : false);
}

void AdjustCommandExecutor::trackAdRevenue() {
    std::string source = this->command->getFirstParameterValue(std::string("adRevenueSource"));
    FAdjustAdRevenue adjustAdRevenue;
    adjustAdRevenue.Source = FString(UTF8_TO_TCHAR(source.c_str()));

    if (this->command->containsParameter(std::string("revenue"))) {
        std::vector<std::string> revenueParams = this->command->getParameters(std::string("revenue"));
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustAdRevenue.Revenue = revenue;
            adjustAdRevenue.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter(std::string("callbackParams"))) {
        std::vector<std::string> callbackParams = this->command->getParameters(std::string("callbackParams"));
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustAdRevenue.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("partnerParams"))) {
        std::vector<std::string> partnerParams = this->command->getParameters(std::string("partnerParams"));
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustAdRevenue.PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter(std::string("adImpressionsCount"))) {
        int adImpressionsCount = std::stoi(this->command->getFirstParameterValue(std::string("adImpressionsCount")));
        adjustAdRevenue.AdImpressionsCount = adImpressionsCount;
    }

    if (this->command->containsParameter(std::string("adRevenueNetwork"))) {
        std::string adRevenueNetwork = this->command->getFirstParameterValue(std::string("adRevenueNetwork"));
        adjustAdRevenue.AdRevenueNetwork = FString(UTF8_TO_TCHAR(adRevenueNetwork.c_str()));
    }

    if (this->command->containsParameter(std::string("adRevenueUnit"))) {
        std::string adRevenueUnit = this->command->getFirstParameterValue(std::string("adRevenueUnit"));
        adjustAdRevenue.AdRevenueUnit = FString(UTF8_TO_TCHAR(adRevenueUnit.c_str()));
    }

    if (this->command->containsParameter(std::string("adRevenuePlacement"))) {
        std::string adRevenuePlacement = this->command->getFirstParameterValue(std::string("adRevenuePlacement"));
        adjustAdRevenue.AdRevenuePlacement = FString(UTF8_TO_TCHAR(adRevenuePlacement.c_str()));
    }

    UAdjust::TrackAdRevenue(adjustAdRevenue);
}

void AdjustCommandExecutor::getLastDeeplink() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetLastDeeplink([testCallbackId, localExtraPath](const FString& LastDeeplink) {
        FTCHARToUTF8 lastDeeplinkUTF8(*LastDeeplink);
        std::string lastDeeplink(lastDeeplinkUTF8.Get(), lastDeeplinkUTF8.Length());
        TestLib::addInfoToSend(std::string("last_deeplink"), lastDeeplink);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::verifyPurchase() {
    std::string localBasePathValue = this->basePath;
    
#if PLATFORM_IOS
    std::string productId = this->command->getFirstParameterValue(std::string("productId"));
    std::string transactionId = this->command->getFirstParameterValue(std::string("transactionId"));

    FAdjustAppStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAppStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        std::string verificationStatus(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(std::string("verification_status"), verificationStatus);
        std::string codeStr = std::to_string(VerificationResult.Code);
        TestLib::addInfoToSend(std::string("code"), codeStr);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        std::string message(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(std::string("message"), message);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    std::string productId = this->command->getFirstParameterValue(std::string("productId"));
    std::string purchaseToken = this->command->getFirstParameterValue(std::string("purchaseToken"));

    FAdjustPlayStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyPlayStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        std::string verificationStatus(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(std::string("verification_status"), verificationStatus);
        std::string codeStr = std::to_string(VerificationResult.Code);
        TestLib::addInfoToSend(std::string("code"), codeStr);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        std::string message(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(std::string("message"), message);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif
}

void AdjustCommandExecutor::verifyTrack() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter(std::string("eventName"))) {
        std::string eventName = this->command->getFirstParameterValue(std::string("eventName"));
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent adjustEvent = this->savedEvents[eventNumber];
    std::string localBasePathValue = this->basePath;

#if PLATFORM_IOS
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAndTrackAppStorePurchase(adjustEvent, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        std::string verificationStatus(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(std::string("verification_status"), verificationStatus);
        std::string codeStr = std::to_string(VerificationResult.Code);
        TestLib::addInfoToSend(std::string("code"), codeStr);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        std::string message(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(std::string("message"), message);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAndTrackPlayStorePurchase(adjustEvent, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        FTCHARToUTF8 verificationStatusUTF8(*VerificationResult.VerificationStatus);
        std::string verificationStatus(verificationStatusUTF8.Get(), verificationStatusUTF8.Length());
        TestLib::addInfoToSend(std::string("verification_status"), verificationStatus);
        std::string codeStr = std::to_string(VerificationResult.Code);
        TestLib::addInfoToSend(std::string("code"), codeStr);
        FTCHARToUTF8 messageUTF8(*VerificationResult.Message);
        std::string message(messageUTF8.Get(), messageUTF8.Length());
        TestLib::addInfoToSend(std::string("message"), message);
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif

    this->savedEvents.erase(0);
}

void AdjustCommandExecutor::processDeeplink() {
    std::string deeplink = this->command->getFirstParameterValue(std::string("deeplink"));
    std::string referrer = "";
    if (this->command->containsParameter(std::string("referrer"))) {
        referrer = this->command->getFirstParameterValue(std::string("referrer"));
    }
    FAdjustDeeplink adjustDeeplink;
    adjustDeeplink.Deeplink = FString(UTF8_TO_TCHAR(deeplink.c_str()));
    if (!referrer.empty()) {
        adjustDeeplink.Referrer = FString(UTF8_TO_TCHAR(referrer.c_str()));
    }
    
    // capture basePath at the time processDeeplink is called
    // this ensures that even if the deeplink is saved and processed later
    // the callback will use the correct basePath for the test that called processDeeplink
    std::string localBasePathValue = this->basePath;
    
    // use lambda-based C++ API - the lambda captures basePath by value
    // so it will use the correct basePath even if called before SDK initialization
    // and processed later after other tests have started
    UAdjust::ProcessAndResolveDeeplink(adjustDeeplink, [localBasePathValue](const FString& ResolvedLink) {
        FTCHARToUTF8 resolvedLinkUTF8(*ResolvedLink);
        std::string resolvedLink(resolvedLinkUTF8.Get(), resolvedLinkUTF8.Length());
        TestLib::addInfoToSend(std::string("resolved_link"), resolvedLink);
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::attributionGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localBasePathValue = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttribution([testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(std::string("attribution"), std::string("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(std::string("attribution"), std::string("null"));
#endif
        } else {
            FTCHARToUTF8 trackerTokenUTF8(*Attribution.TrackerToken);
            std::string trackerToken(trackerTokenUTF8.Get(), trackerTokenUTF8.Length());
            TestLib::addInfoToSend(std::string("tracker_token"), trackerToken);
            
            FTCHARToUTF8 trackerNameUTF8(*Attribution.TrackerName);
            std::string trackerName(trackerNameUTF8.Get(), trackerNameUTF8.Length());
            TestLib::addInfoToSend(std::string("tracker_name"), trackerName);
            
            FTCHARToUTF8 networkUTF8(*Attribution.Network);
            std::string network(networkUTF8.Get(), networkUTF8.Length());
            TestLib::addInfoToSend(std::string("network"), network);
            
            FTCHARToUTF8 campaignUTF8(*Attribution.Campaign);
            std::string campaign(campaignUTF8.Get(), campaignUTF8.Length());
            TestLib::addInfoToSend(std::string("campaign"), campaign);
            
            FTCHARToUTF8 adgroupUTF8(*Attribution.Adgroup);
            std::string adgroup(adgroupUTF8.Get(), adgroupUTF8.Length());
            TestLib::addInfoToSend(std::string("adgroup"), adgroup);
            
            FTCHARToUTF8 creativeUTF8(*Attribution.Creative);
            std::string creative(creativeUTF8.Get(), creativeUTF8.Length());
            TestLib::addInfoToSend(std::string("creative"), creative);
            
            FTCHARToUTF8 clickLabelUTF8(*Attribution.ClickLabel);
            std::string clickLabel(clickLabelUTF8.Get(), clickLabelUTF8.Length());
            TestLib::addInfoToSend(std::string("click_label"), clickLabel);
            
            FTCHARToUTF8 costTypeUTF8(*Attribution.CostType);
            std::string costType(costTypeUTF8.Get(), costTypeUTF8.Length());
            TestLib::addInfoToSend(std::string("cost_type"), costType);
            
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            std::string costAmountStr = sstream.str();
            TestLib::addInfoToSend(std::string("cost_amount"), costAmountStr);
            
            FTCHARToUTF8 costCurrencyUTF8(*Attribution.CostCurrency);
            std::string costCurrency(costCurrencyUTF8.Get(), costCurrencyUTF8.Length());
            TestLib::addInfoToSend(std::string("cost_currency"), costCurrency);
#if PLATFORM_ANDROID
            FTCHARToUTF8 fbInstallReferrerUTF8(*Attribution.FbInstallReferrer);
            std::string fbInstallReferrer(fbInstallReferrerUTF8.Get(), fbInstallReferrerUTF8.Length());
            TestLib::addInfoToSend(std::string("fb_install_referrer"), fbInstallReferrer);
            
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonResponse(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            TestLib::addInfoToSend(std::string("json_response"), jsonResponse);
#elif PLATFORM_IOS
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonStr = std::string(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            TestLib::addInfoToSend(std::string("json_response"), jsonStr);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::adidGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdid([testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(std::string("adid"), std::string("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(std::string("adid"), std::string("null"));
#endif
        } else {
            FTCHARToUTF8 adidUTF8(*Adid);
            std::string adid(adidUTF8.Get(), adidUTF8.Length());
            TestLib::addInfoToSend(std::string("adid"), adid);
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::adidGetterWithTimeout() {
    std::string timeoutStr = this->command->getFirstParameterValue(std::string("timeout"));
    int timeout = std::stoi(timeoutStr);
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdidWithTimeout(timeout, [testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(std::string("adid"), std::string("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(std::string("adid"), std::string("null"));
#endif
        } else {
            FTCHARToUTF8 adidUTF8(*Adid);
            std::string adid(adidUTF8.Get(), adidUTF8.Length());
            TestLib::addInfoToSend(std::string("adid"), adid);
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::attributionGetterWithTimeout() {
    std::string timeoutStr = this->command->getFirstParameterValue(std::string("timeout"));
    int timeout = std::stoi(timeoutStr);
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localBasePathValue = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttributionWithTimeout(timeout, [testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend(std::string("attribution"), std::string("nil"));
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend(std::string("attribution"), std::string("null"));
#endif
        } else {
            FTCHARToUTF8 trackerTokenUTF8(*Attribution.TrackerToken);
            std::string trackerToken(trackerTokenUTF8.Get(), trackerTokenUTF8.Length());
            TestLib::addInfoToSend(std::string("tracker_token"), trackerToken);
            
            FTCHARToUTF8 trackerNameUTF8(*Attribution.TrackerName);
            std::string trackerName(trackerNameUTF8.Get(), trackerNameUTF8.Length());
            TestLib::addInfoToSend(std::string("tracker_name"), trackerName);
            
            FTCHARToUTF8 networkUTF8(*Attribution.Network);
            std::string network(networkUTF8.Get(), networkUTF8.Length());
            TestLib::addInfoToSend(std::string("network"), network);
            
            FTCHARToUTF8 campaignUTF8(*Attribution.Campaign);
            std::string campaign(campaignUTF8.Get(), campaignUTF8.Length());
            TestLib::addInfoToSend(std::string("campaign"), campaign);
            
            FTCHARToUTF8 adgroupUTF8(*Attribution.Adgroup);
            std::string adgroup(adgroupUTF8.Get(), adgroupUTF8.Length());
            TestLib::addInfoToSend(std::string("adgroup"), adgroup);
            
            FTCHARToUTF8 creativeUTF8(*Attribution.Creative);
            std::string creative(creativeUTF8.Get(), creativeUTF8.Length());
            TestLib::addInfoToSend(std::string("creative"), creative);
            
            FTCHARToUTF8 clickLabelUTF8(*Attribution.ClickLabel);
            std::string clickLabel(clickLabelUTF8.Get(), clickLabelUTF8.Length());
            TestLib::addInfoToSend(std::string("click_label"), clickLabel);
            
            FTCHARToUTF8 costTypeUTF8(*Attribution.CostType);
            std::string costType(costTypeUTF8.Get(), costTypeUTF8.Length());
            TestLib::addInfoToSend(std::string("cost_type"), costType);
            
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            std::string costAmountStr = sstream.str();
            TestLib::addInfoToSend(std::string("cost_amount"), costAmountStr);
            
            FTCHARToUTF8 costCurrencyUTF8(*Attribution.CostCurrency);
            std::string costCurrency(costCurrencyUTF8.Get(), costCurrencyUTF8.Length());
            TestLib::addInfoToSend(std::string("cost_currency"), costCurrency);
#if PLATFORM_ANDROID
            FTCHARToUTF8 fbInstallReferrerUTF8(*Attribution.FbInstallReferrer);
            std::string fbInstallReferrer(fbInstallReferrerUTF8.Get(), fbInstallReferrerUTF8.Length());
            TestLib::addInfoToSend(std::string("fb_install_referrer"), fbInstallReferrer);
            
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonResponse(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            TestLib::addInfoToSend(std::string("json_response"), jsonResponse);
#elif PLATFORM_IOS
            FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
            std::string jsonStr = std::string(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            TestLib::addInfoToSend(std::string("json_response"), jsonStr);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::idfaGetter() {
#if PLATFORM_IOS
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfa([testCallbackId, localExtraPath](const FString& Idfa) {
        FTCHARToUTF8 idfaUTF8(*Idfa);
        std::string idfa(idfaUTF8.Get(), idfaUTF8.Length());
        TestLib::addInfoToSend(std::string("idfa"), idfa);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::idfvGetter() {
#if PLATFORM_IOS
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfv([testCallbackId, localExtraPath](const FString& Idfv) {
        FTCHARToUTF8 idfvUTF8(*Idfv);
        std::string idfv(idfvUTF8.Get(), idfvUTF8.Length());
        TestLib::addInfoToSend(std::string("idfv"), idfv);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::googleAdIdGetter() {
#if PLATFORM_ANDROID
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetGoogleAdId([testCallbackId, localExtraPath](const FString& GoogleAdId) {
        FTCHARToUTF8 googleAdIdUTF8(*GoogleAdId);
        std::string googleAdId(googleAdIdUTF8.Get(), googleAdIdUTF8.Length());
        TestLib::addInfoToSend(std::string("gps_adid"), googleAdId);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::amazonAdIdGetter() {
#if PLATFORM_ANDROID
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAmazonAdId([testCallbackId, localExtraPath](const FString& AmazonAdId) {
        if (AmazonAdId.IsEmpty()) {
            TestLib::addInfoToSend(std::string("fire_adid"), std::string("null"));
        } else {
            FTCHARToUTF8 amazonAdIdUTF8(*AmazonAdId);
            std::string amazonAdId(amazonAdIdUTF8.Get(), amazonAdIdUTF8.Length());
            TestLib::addInfoToSend(std::string("fire_adid"), amazonAdId);
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::sdkVersionGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        std::string testCallbackIdStr = this->command->getFirstParameterValue(std::string("testCallbackId"));
        testCallbackId = testCallbackIdStr;
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetSdkVersion([testCallbackId, localExtraPath](const FString& SdkVersion) {
        FTCHARToUTF8 sdkVersionUTF8(*SdkVersion);
        std::string sdkVersion(sdkVersionUTF8.Get(), sdkVersionUTF8.Length());
        TestLib::addInfoToSend(std::string("sdk_version"), sdkVersion);
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend(std::string("test_callback_id"), testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::lastDeeplinkGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter(std::string("testCallbackId"))) {
        testCallbackId = this->command->getFirstParameterValue(std::string("testCallbackId"));
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
    std::string strIsEnabled = this->command->getFirstParameterValue(std::string("isEnabled"));
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnableCoppaComplianceInDelay();
    } else {
        UAdjust::DisableCoppaComplianceInDelay();
    }
}

void AdjustCommandExecutor::playStoreKidsComplianceInDelay() {
    std::string strIsEnabled = this->command->getFirstParameterValue(std::string("isEnabled"));
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnablePlayStoreKidsComplianceInDelay();
    } else {
        UAdjust::DisablePlayStoreKidsComplianceInDelay();
    }
}

void AdjustCommandExecutor::externalDeviceIdInDelay() {
    std::string externalDeviceId = this->command->getFirstParameterValue(std::string("externalDeviceId"));
    UAdjust::SetExternalDeviceIdInDelay(FString(UTF8_TO_TCHAR(externalDeviceId.c_str())));
}
