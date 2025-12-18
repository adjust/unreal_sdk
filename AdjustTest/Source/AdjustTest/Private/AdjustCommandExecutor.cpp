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

AdjustCommandExecutor::AdjustCommandExecutor(std::string urlOverwrite) {
    this->urlOverwrite = urlOverwrite;
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

    if (this->command->containsParameter("basePath")) {
        this->basePath = this->command->getFirstParameterValue("basePath");
        localBasePath = this->basePath;
        if (persistentTestDelegates != nullptr) {
            persistentTestDelegates->localBasePath = FString(UTF8_TO_TCHAR(this->basePath.c_str()));
        }
    }
    if (this->command->containsParameter("timerInterval")) {
        intTestOptions["timerIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue("timerInterval"));
    }
    if (this->command->containsParameter("timerStart")) {
        intTestOptions["timerStartInMilliseconds"] = std::stoi(this->command->getFirstParameterValue("timerStart"));
    }
    if (this->command->containsParameter("sessionInterval")) {
        intTestOptions["sessionIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue("sessionInterval"));
    }
    if (this->command->containsParameter("subsessionInterval")) {
        intTestOptions["subsessionIntervalInMilliseconds"] = std::stoi(this->command->getFirstParameterValue("subsessionInterval"));
    }
    if (this->command->containsParameter("attStatus")) {
        intTestOptions["attStatusInt"] = std::stoi(this->command->getFirstParameterValue("attStatus"));
    }

    if (this->command->containsParameter("idfa")) {
        stringTestOptions["idfa"] = this->command->getFirstParameterValue("idfa");
    }

    if (this->command->containsParameter("noBackoffWait")) {
        if (this->command->getFirstParameterValue("noBackoffWait") == "true") {
            intTestOptions["noBackoffWait"] = 1;
        } else {
            intTestOptions["noBackoffWait"] = 0;
        }
    }
    // "false" is default value - AdServices will not be used in test app by default
    intTestOptions["adServicesFrameworkEnabled"] = 0;
    if (this->command->containsParameter("adServicesFrameworkEnabled")) {
        if (this->command->getFirstParameterValue("adServicesFrameworkEnabled") == "true") {
            intTestOptions["adServicesFrameworkEnabled"] = 1;
        }
    }

    if (this->command->containsParameter("tryInstallReferrer")) {
        if (this->command->getFirstParameterValue("tryInstallReferrer") == "true") {
            intTestOptions["tryInstallReferrer"] = 1;
        } else {
            intTestOptions["tryInstallReferrer"] = 0;
        }
    }

    if (this->command->containsParameter("doNotIgnoreSystemLifecycleBootstrap")) {
        if (this->command->getFirstParameterValue("doNotIgnoreSystemLifecycleBootstrap") == "true") {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 1;
        } else {
            intTestOptions["doNotIgnoreSystemLifecycleBootstrap"] = 0;
        }
    }

    bool useTestConnectionOptions = false;

    if (this->command->containsParameter("teardown")) {
        std::vector<std::string> teardownOptions = this->command->getParameters("teardown");
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
    if (this->command->containsParameter("configName")) {
        std::string configName = this->command->getFirstParameterValue("configName");
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
        if (this->command->containsParameter("environment")) {
            environmentParam = this->command->getFirstParameterValue("environment");
        }
        if (this->command->containsParameter("appToken")) {
            appToken = this->command->getFirstParameterValue("appToken");
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

    if (this->command->containsParameter("logLevel")) {
        std::string logLevelString = this->command->getFirstParameterValue("logLevel");
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

    if (this->command->containsParameter("checkPasteboard")) {
        std::string checkPasteboardString = this->command->getFirstParameterValue("checkPasteboard");
        bool checkPasteboard = (checkPasteboardString == "true");
        if (checkPasteboard) {
            adjustConfig->IsLinkMeEnabled = true;
        }
    }

    if (this->command->containsParameter("attConsentWaitingSeconds")) {
        std::string attConsentWaitingSecondsString = this->command->getFirstParameterValue("attConsentWaitingSeconds");
        adjustConfig->AttConsentWaitingInterval = std::stoi(attConsentWaitingSecondsString);
    }

    if (this->command->containsParameter("eventDeduplicationIdsMaxSize")) {
        std::string eventDeduplicationIdsMaxSizeString = this->command->getFirstParameterValue("eventDeduplicationIdsMaxSize");
        adjustConfig->EventDeduplicationIdsMaxSize = std::stoi(eventDeduplicationIdsMaxSizeString);
    }

    if (this->command->containsParameter("coppaCompliant")) {
        std::string coppaCompliantString = this->command->getFirstParameterValue("coppaCompliant");
        bool coppaCompliant = (coppaCompliantString == "true");
        if (coppaCompliant) {
            adjustConfig->IsCoppaComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter("needsCost")) {
        std::string needsCostString = this->command->getFirstParameterValue("needsCost");
        bool needsCost = (needsCostString == "true");
        if (needsCost) {
            adjustConfig->IsCostDataInAttributionEnabled = true;
        }
    }

    if (this->command->containsParameter("allowIdfaReading")) {
        std::string allowIdfaReadingString = this->command->getFirstParameterValue("allowIdfaReading");
        bool allowIdfaReading = (allowIdfaReadingString == "true");
        if (!allowIdfaReading) {
            adjustConfig->IsIdfaReadingEnabled = false;
        }
    }

    if (this->command->containsParameter("allowAdServicesInfoReading")) {
        std::string allowAdServicesInfoReadingString = this->command->getFirstParameterValue("allowAdServicesInfoReading");
        bool allowAdServicesInfoReading = (allowAdServicesInfoReadingString == "true");
        if (!allowAdServicesInfoReading) {
            adjustConfig->IsAdServicesEnabled = false;
        }
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter("allowAppSetIdReading")) {
        std::string allowAppSetIdReadingString = this->command->getFirstParameterValue("allowAppSetIdReading");
        bool allowAppSetIdReading = (allowAppSetIdReadingString == "true");
        if (!allowAppSetIdReading) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }

    if (this->command->containsParameter("appSetIdReadingEnabled")) {
        std::string appSetIdReadingEnabledString = this->command->getFirstParameterValue("appSetIdReadingEnabled");
        bool appSetIdReadingEnabled = (appSetIdReadingEnabledString == "true");
        if (!appSetIdReadingEnabled) {
            adjustConfig->IsAppSetIdReadingEnabled = false;
        }
    }
#endif

    if (this->command->containsParameter("allowSkAdNetworkHandling")) {
        std::string allowSkAdNetworkHandlingString = this->command->getFirstParameterValue("allowSkAdNetworkHandling");
        bool allowSkAdNetworkHandling = (allowSkAdNetworkHandlingString == "true");
        if (allowSkAdNetworkHandling == false) {
            adjustConfig->IsSkanAttributionEnabled = false;
        }
    }

    if (this->command->containsParameter("sendInBackground")) {
        std::string sendInBackgroundString = this->command->getFirstParameterValue("sendInBackground");
        bool sendInBackground = (sendInBackgroundString == "true");
        if (sendInBackground) {
            adjustConfig->IsSendingInBackgroundEnabled = true;
        }
    }

    if (this->command->containsParameter("defaultTracker")) {
        std::string defaultTracker = this->command->getFirstParameterValue("defaultTracker");
        adjustConfig->DefaultTracker = FString(UTF8_TO_TCHAR(defaultTracker.c_str()));
    }

    if (this->command->containsParameter("externalDeviceId")) {
        std::string externalDeviceId = this->command->getFirstParameterValue("externalDeviceId");
        adjustConfig->ExternalDeviceId = FString(UTF8_TO_TCHAR(externalDeviceId.c_str()));
    }

    if (this->command->containsParameter("playStoreKids")) {
        std::string playStoreKidsString = this->command->getFirstParameterValue("playStoreKids");
        if (playStoreKidsString == "true") {
            adjustConfig->IsPlayStoreKidsComplianceEnabled = true;
        }
    }

    if (this->command->containsParameter("allowAttUsage")) {
        std::string allowAttUsageString = this->command->getFirstParameterValue("allowAttUsage");
        if (allowAttUsageString == "false") {
            adjustConfig->IsAppTrackingTransparencyUsageEnabled = false;
        }
    }

    if (this->command->containsParameter("firstSessionDelayEnabled")) {
        std::string firstSessionDelayEnabledString = this->command->getFirstParameterValue("firstSessionDelayEnabled");
        if (firstSessionDelayEnabledString == "true") {
            adjustConfig->IsFirstSessionDelayEnabled = true;
        }
    }

    if (this->command->containsParameter("storeName")) {
        std::string storeName = this->command->getFirstParameterValue("storeName");
        adjustConfig->StoreInfo.StoreName = FString(UTF8_TO_TCHAR(storeName.c_str()));
        if (this->command->containsParameter("storeAppId")) {
            std::string storeAppId = this->command->getFirstParameterValue("storeAppId");
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
    if (this->command->containsParameter("attributionCallbackSendAll")) {
        persistentTestDelegates->shouldSendAttributionCallback = true;
        persistentAdjustDelegates->OnAttributionChangedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnAttributionChanged);
    }
    
    // register and activate session success callback if sessionCallbackSendSuccess is present
    if (this->command->containsParameter("sessionCallbackSendSuccess")) {
        persistentTestDelegates->shouldSendSessionSuccessCallback = true;
        persistentAdjustDelegates->OnSessionSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionSuccess);
    }
    
    // register and activate session failure callback if sessionCallbackSendFailure is present
    if (this->command->containsParameter("sessionCallbackSendFailure")) {
        persistentTestDelegates->shouldSendSessionFailureCallback = true;
        persistentAdjustDelegates->OnSessionFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSessionFailure);
    }
    
    // register and activate event success callback if eventCallbackSendSuccess is present
    if (this->command->containsParameter("eventCallbackSendSuccess")) {
        persistentTestDelegates->shouldSendEventSuccessCallback = true;
        persistentAdjustDelegates->OnEventSuccessDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventSuccess);
    }
    
    // register and activate event failure callback if eventCallbackSendFailure is present
    if (this->command->containsParameter("eventCallbackSendFailure")) {
        persistentTestDelegates->shouldSendEventFailureCallback = true;
        persistentAdjustDelegates->OnEventFailureDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnEventFailure);
    }
    
    // register and activate deferred deeplink callback if deferredDeeplinkCallback is present
    if (this->command->containsParameter("deferredDeeplinkCallback")) {
        std::string openDeeplinkString = this->command->getFirstParameterValue("deferredDeeplinkCallback");
        bool openDeeplink = (openDeeplinkString == "true");
        adjustConfig->IsDeferredDeeplinkOpeningEnabled = openDeeplink;
        persistentTestDelegates->shouldSendDeferredDeeplinkCallback = true;
        persistentAdjustDelegates->OnDeferredDeeplinkDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnDeferredDeeplink);
    }
    
#if PLATFORM_IOS
    // register and activate SKAN callback if skanCallback is present (NOT skanCallbackSendAll)
    if (this->command->containsParameter("skanCallback")) {
        persistentTestDelegates->shouldSendSkanCallback = true;
        persistentAdjustDelegates->OnSkanConversionValueUpdatedDelegate.AddDynamic(persistentTestDelegates, &UAdjustTestCommandExecutorDelegates::OnSkanConversionValueUpdated);
    }
#endif
}

void AdjustCommandExecutor::start() {
    config();
    int configNumber = 0;
    if (this->command->containsParameter("configName")) {
        std::string configName = this->command->getFirstParameterValue("configName");
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
    if (this->command->containsParameter("eventName")) {
        std::string eventName = this->command->getFirstParameterValue("eventName");
        if (!eventName.empty()) {
            std::string eventNumberStr = eventName.substr(eventName.length() - 1, 1);
            eventNumber = std::stoi(eventNumberStr);
        }
    }

    FAdjustEvent* adjustEvent;
    if (this->savedEvents.count(eventNumber) > 0) {
        adjustEvent = &this->savedEvents[eventNumber];
    } else {
        std::string eventToken = this->command->getFirstParameterValue("eventToken");
        FAdjustEvent newEvent;
        newEvent.EventToken = FString(UTF8_TO_TCHAR(eventToken.c_str()));
        savedEvents[eventNumber] = newEvent;
        adjustEvent = &this->savedEvents[eventNumber];
    }

    if (this->command->containsParameter("revenue")) {
        std::vector<std::string> revenueParams = this->command->getParameters("revenue");
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustEvent->Revenue = revenue;
            adjustEvent->Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter("callbackParams")) {
        std::vector<std::string> callbackParams = this->command->getParameters("callbackParams");
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustEvent->CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("partnerParams")) {
        std::vector<std::string> partnerParams = this->command->getParameters("partnerParams");
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustEvent->PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("orderId")) {
        std::string orderId = this->command->getFirstParameterValue("orderId");
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(orderId.c_str()));
    }

    if (this->command->containsParameter("callbackId")) {
        std::string callbackId = this->command->getFirstParameterValue("callbackId");
        adjustEvent->CallbackId = FString(UTF8_TO_TCHAR(callbackId.c_str()));
    }

    if (this->command->containsParameter("transactionId")) {
        std::string transactionId = this->command->getFirstParameterValue("transactionId");
        adjustEvent->TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    }

    if (this->command->containsParameter("productId")) {
        std::string productId = this->command->getFirstParameterValue("productId");
        adjustEvent->ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    }

    if (this->command->containsParameter("deduplicationId")) {
        std::string deduplicationId = this->command->getFirstParameterValue("deduplicationId");
        adjustEvent->DeduplicationId = FString(UTF8_TO_TCHAR(deduplicationId.c_str()));
    }

#if PLATFORM_ANDROID
    if (this->command->containsParameter("purchaseToken")) {
        std::string purchaseToken = this->command->getFirstParameterValue("purchaseToken");
        adjustEvent->PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));
    }
#endif
}

void AdjustCommandExecutor::trackEvent() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter("eventName")) {
        std::string eventName = this->command->getFirstParameterValue("eventName");
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
    std::string enabledStr = this->command->getFirstParameterValue("enabled");
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::Enable();
    } else {
        UAdjust::Disable();
    }
}

void AdjustCommandExecutor::setOfflineMode() {
    std::string enabledStr = this->command->getFirstParameterValue("enabled");
    bool enabled = (enabledStr == "true");
    if (enabled) {
        UAdjust::SwitchToOfflineMode();
    } else {
        UAdjust::SwitchBackToOnlineMode();
    }
}

void AdjustCommandExecutor::addGlobalCallbackParameter() {
    if (this->command->containsParameter("KeyValue")) {
        std::vector<std::string> keyValuePairs = this->command->getParameters("KeyValue");
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter("key") && this->command->containsParameter("value")) {
        FString key = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue("key").c_str()));
        FString value = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue("value").c_str()));
        UAdjust::AddGlobalCallbackParameter(key, value);
    }
}

void AdjustCommandExecutor::addGlobalPartnerParameter() {
    if (this->command->containsParameter("KeyValue")) {
        std::vector<std::string> keyValuePairs = this->command->getParameters("KeyValue");
        for (size_t i = 0; i < keyValuePairs.size(); i = i + 2) {
            if (i + 1 < keyValuePairs.size()) {
                std::string key = keyValuePairs[i];
                std::string value = keyValuePairs[i + 1];
                UAdjust::AddGlobalPartnerParameter(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    } else if (this->command->containsParameter("key") && this->command->containsParameter("value")) {
        FString key = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue("key").c_str()));
        FString value = FString(UTF8_TO_TCHAR(this->command->getFirstParameterValue("value").c_str()));
        UAdjust::AddGlobalPartnerParameter(key, value);
    }
}

void AdjustCommandExecutor::removeGlobalCallbackParameter() {
    if (this->command->containsParameter("key")) {
        std::vector<std::string> keys = this->command->getParameters("key");
        for (size_t i = 0; i < keys.size(); i++) {
            std::string key = keys[i];
            UAdjust::RemoveGlobalCallbackParameter(FString(UTF8_TO_TCHAR(key.c_str())));
        }
    }
}

void AdjustCommandExecutor::removeGlobalPartnerParameter() {
    if (this->command->containsParameter("key")) {
        std::vector<std::string> keys = this->command->getParameters("key");
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
    std::string token = this->command->getFirstParameterValue("pushToken");
    UAdjust::SetPushToken(FString(UTF8_TO_TCHAR(token.c_str())));
}

void AdjustCommandExecutor::openDeeplink() {
    std::string deeplink = this->command->getFirstParameterValue("deeplink");
    std::string referrer = "";
    if (this->command->containsParameter("referrer")) {
        referrer = this->command->getFirstParameterValue("referrer");
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
    std::string price = this->command->getFirstParameterValue("revenue");
    std::string currency = this->command->getFirstParameterValue("currency");
    std::string transactionId = this->command->getFirstParameterValue("transactionId");
    std::string transactionDate = this->command->getFirstParameterValue("transactionDate");
    std::string salesRegion = this->command->getFirstParameterValue("salesRegion");

    FAdjustAppStoreSubscription subscription;
    subscription.Price = std::stod(price);
    subscription.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
    subscription.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));
    subscription.TransactionDate = FString(UTF8_TO_TCHAR(transactionDate.c_str()));
    subscription.SalesRegion = FString(UTF8_TO_TCHAR(salesRegion.c_str()));

    if (this->command->containsParameter("callbackParams")) {
        std::vector<std::string> callbackParams = this->command->getParameters("callbackParams");
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("partnerParams")) {
        std::vector<std::string> partnerParams = this->command->getParameters("partnerParams");
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
    std::string price = this->command->getFirstParameterValue("revenue");
    std::string currency = this->command->getFirstParameterValue("currency");
    std::string sku = this->command->getFirstParameterValue("productId");
    std::string orderId = this->command->getFirstParameterValue("transactionId");
    std::string signature = this->command->getFirstParameterValue("receipt");
    std::string purchaseToken = this->command->getFirstParameterValue("purchaseToken");
    std::string purchaseTime = this->command->getFirstParameterValue("transactionDate");

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

    if (this->command->containsParameter("callbackParams")) {
        std::vector<std::string> callbackParams = this->command->getParameters("callbackParams");
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                subscription.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("partnerParams")) {
        std::vector<std::string> partnerParams = this->command->getParameters("partnerParams");
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
    std::string enabled = this->command->getFirstParameterValue("isEnabled");
    FAdjustThirdPartySharing thirdPartySharing;
    if (enabled == "true") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Enable;
    } else if (enabled == "false") {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Disable;
    } else {
        thirdPartySharing.Sharing = EAdjustThirdPartySharingState::Current;
    }

    if (this->command->containsParameter("granularOptions")) {
        std::vector<std::string> granularOptions = this->command->getParameters("granularOptions");
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

    if (this->command->containsParameter("partnerSharingSettings")) {
        std::vector<std::string> partnerSharingSettings = this->command->getParameters("partnerSharingSettings");
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
    std::string enabled = this->command->getFirstParameterValue("isEnabled");
    UAdjust::TrackMeasurementConsent(enabled == "true" ? true : false);
}

void AdjustCommandExecutor::trackAdRevenue() {
    std::string source = this->command->getFirstParameterValue("adRevenueSource");
    FAdjustAdRevenue adjustAdRevenue;
    adjustAdRevenue.Source = FString(UTF8_TO_TCHAR(source.c_str()));

    if (this->command->containsParameter("revenue")) {
        std::vector<std::string> revenueParams = this->command->getParameters("revenue");
        if (revenueParams.size() >= 2) {
            std::string currency = revenueParams[0];
            double revenue = std::stod(revenueParams[1]);
            adjustAdRevenue.Revenue = revenue;
            adjustAdRevenue.Currency = FString(UTF8_TO_TCHAR(currency.c_str()));
        }
    }

    if (this->command->containsParameter("callbackParams")) {
        std::vector<std::string> callbackParams = this->command->getParameters("callbackParams");
        for (size_t i = 0; i < callbackParams.size(); i = i + 2) {
            if (i + 1 < callbackParams.size()) {
                std::string key = callbackParams[i];
                std::string value = callbackParams[i + 1];
                adjustAdRevenue.CallbackParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("partnerParams")) {
        std::vector<std::string> partnerParams = this->command->getParameters("partnerParams");
        for (size_t i = 0; i < partnerParams.size(); i = i + 2) {
            if (i + 1 < partnerParams.size()) {
                std::string key = partnerParams[i];
                std::string value = partnerParams[i + 1];
                adjustAdRevenue.PartnerParameters.Add(FString(UTF8_TO_TCHAR(key.c_str())), FString(UTF8_TO_TCHAR(value.c_str())));
            }
        }
    }

    if (this->command->containsParameter("adImpressionsCount")) {
        int adImpressionsCount = std::stoi(this->command->getFirstParameterValue("adImpressionsCount"));
        adjustAdRevenue.AdImpressionsCount = adImpressionsCount;
    }

    if (this->command->containsParameter("adRevenueNetwork")) {
        std::string adRevenueNetwork = this->command->getFirstParameterValue("adRevenueNetwork");
        adjustAdRevenue.AdRevenueNetwork = FString(UTF8_TO_TCHAR(adRevenueNetwork.c_str()));
    }

    if (this->command->containsParameter("adRevenueUnit")) {
        std::string adRevenueUnit = this->command->getFirstParameterValue("adRevenueUnit");
        adjustAdRevenue.AdRevenueUnit = FString(UTF8_TO_TCHAR(adRevenueUnit.c_str()));
    }

    if (this->command->containsParameter("adRevenuePlacement")) {
        std::string adRevenuePlacement = this->command->getFirstParameterValue("adRevenuePlacement");
        adjustAdRevenue.AdRevenuePlacement = FString(UTF8_TO_TCHAR(adRevenuePlacement.c_str()));
    }

    UAdjust::TrackAdRevenue(adjustAdRevenue);
}

void AdjustCommandExecutor::getLastDeeplink() {
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetLastDeeplink([testCallbackId, localExtraPath](const FString& LastDeeplink) {
        TestLib::addInfoToSend("last_deeplink", std::string(TCHAR_TO_UTF8(*LastDeeplink)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::verifyPurchase() {
    std::string localBasePathValue = this->basePath;
    
#if PLATFORM_IOS
    std::string productId = this->command->getFirstParameterValue("productId");
    std::string transactionId = this->command->getFirstParameterValue("transactionId");

    FAdjustAppStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.TransactionId = FString(UTF8_TO_TCHAR(transactionId.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAppStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        TestLib::addInfoToSend("verification_status", std::string(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
        TestLib::addInfoToSend("code", std::to_string(VerificationResult.Code));
        TestLib::addInfoToSend("message", std::string(TCHAR_TO_UTF8(*VerificationResult.Message)));
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    std::string productId = this->command->getFirstParameterValue("productId");
    std::string purchaseToken = this->command->getFirstParameterValue("purchaseToken");

    FAdjustPlayStorePurchase purchase;
    purchase.ProductId = FString(UTF8_TO_TCHAR(productId.c_str()));
    purchase.PurchaseToken = FString(UTF8_TO_TCHAR(purchaseToken.c_str()));

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyPlayStorePurchase(purchase, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        TestLib::addInfoToSend("verification_status", std::string(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
        TestLib::addInfoToSend("code", std::to_string(VerificationResult.Code));
        TestLib::addInfoToSend("message", std::string(TCHAR_TO_UTF8(*VerificationResult.Message)));
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif
}

void AdjustCommandExecutor::verifyTrack() {
    event();
    int eventNumber = 0;
    if (this->command->containsParameter("eventName")) {
        std::string eventName = this->command->getFirstParameterValue("eventName");
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
        TestLib::addInfoToSend("verification_status", std::string(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
        TestLib::addInfoToSend("code", std::to_string(VerificationResult.Code));
        TestLib::addInfoToSend("message", std::string(TCHAR_TO_UTF8(*VerificationResult.Message)));
        TestLib::sendInfoToServer(localBasePathValue);
    });
#elif PLATFORM_ANDROID
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::VerifyAndTrackPlayStorePurchase(adjustEvent, [localBasePathValue](const FAdjustPurchaseVerificationResult& VerificationResult) {
        TestLib::addInfoToSend("verification_status", std::string(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
        TestLib::addInfoToSend("code", std::to_string(VerificationResult.Code));
        TestLib::addInfoToSend("message", std::string(TCHAR_TO_UTF8(*VerificationResult.Message)));
        TestLib::sendInfoToServer(localBasePathValue);
    });
#endif

    this->savedEvents.erase(0);
}

void AdjustCommandExecutor::processDeeplink() {
    std::string deeplink = this->command->getFirstParameterValue("deeplink");
    std::string referrer = "";
    if (this->command->containsParameter("referrer")) {
        referrer = this->command->getFirstParameterValue("referrer");
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
        TestLib::addInfoToSend("resolved_link", std::string(TCHAR_TO_UTF8(*ResolvedLink)));
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::attributionGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localBasePathValue = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttribution([testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend("attribution", "nil");
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend("attribution", "null");
#endif
        } else {
            TestLib::addInfoToSend("tracker_token", std::string(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
            TestLib::addInfoToSend("tracker_name", std::string(TCHAR_TO_UTF8(*Attribution.TrackerName)));
            TestLib::addInfoToSend("network", std::string(TCHAR_TO_UTF8(*Attribution.Network)));
            TestLib::addInfoToSend("campaign", std::string(TCHAR_TO_UTF8(*Attribution.Campaign)));
            TestLib::addInfoToSend("adgroup", std::string(TCHAR_TO_UTF8(*Attribution.Adgroup)));
            TestLib::addInfoToSend("creative", std::string(TCHAR_TO_UTF8(*Attribution.Creative)));
            TestLib::addInfoToSend("click_label", std::string(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
            TestLib::addInfoToSend("cost_type", std::string(TCHAR_TO_UTF8(*Attribution.CostType)));
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            TestLib::addInfoToSend("cost_amount", sstream.str());
            TestLib::addInfoToSend("cost_currency", std::string(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
            TestLib::addInfoToSend("fb_install_referrer", std::string(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
            TestLib::addInfoToSend("json_response", std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
#elif PLATFORM_IOS
            std::string jsonStr = std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse));
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            TestLib::addInfoToSend("json_response", jsonStr);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::adidGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdid([testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend("adid", "nil");
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend("adid", "null");
#endif
        } else {
            TestLib::addInfoToSend("adid", std::string(TCHAR_TO_UTF8(*Adid)));
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::adidGetterWithTimeout() {
    std::string timeoutStr = this->command->getFirstParameterValue("timeout");
    int timeout = std::stoi(timeoutStr);
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAdidWithTimeout(timeout, [testCallbackId, localExtraPath](const FString& Adid) {
        if (Adid.IsEmpty()) {
#if PLATFORM_IOS
            TestLib::addInfoToSend("adid", "nil");
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend("adid", "null");
#endif
        } else {
            TestLib::addInfoToSend("adid", std::string(TCHAR_TO_UTF8(*Adid)));
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::attributionGetterWithTimeout() {
    std::string timeoutStr = this->command->getFirstParameterValue("timeout");
    int timeout = std::stoi(timeoutStr);
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localBasePathValue = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAttributionWithTimeout(timeout, [testCallbackId, localBasePathValue](const FAdjustAttribution& Attribution) {
        bool isEmpty = Attribution.TrackerToken.IsEmpty() && 
                       Attribution.TrackerName.IsEmpty() && 
                       Attribution.Network.IsEmpty();
        
        if (isEmpty) {
#if PLATFORM_IOS
            TestLib::addInfoToSend("attribution", "nil");
#elif PLATFORM_ANDROID
            TestLib::addInfoToSend("attribution", "null");
#endif
        } else {
            TestLib::addInfoToSend("tracker_token", std::string(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
            TestLib::addInfoToSend("tracker_name", std::string(TCHAR_TO_UTF8(*Attribution.TrackerName)));
            TestLib::addInfoToSend("network", std::string(TCHAR_TO_UTF8(*Attribution.Network)));
            TestLib::addInfoToSend("campaign", std::string(TCHAR_TO_UTF8(*Attribution.Campaign)));
            TestLib::addInfoToSend("adgroup", std::string(TCHAR_TO_UTF8(*Attribution.Adgroup)));
            TestLib::addInfoToSend("creative", std::string(TCHAR_TO_UTF8(*Attribution.Creative)));
            TestLib::addInfoToSend("click_label", std::string(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
            TestLib::addInfoToSend("cost_type", std::string(TCHAR_TO_UTF8(*Attribution.CostType)));
            std::ostringstream sstream;
            sstream << Attribution.CostAmount;
            TestLib::addInfoToSend("cost_amount", sstream.str());
            TestLib::addInfoToSend("cost_currency", std::string(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
            TestLib::addInfoToSend("fb_install_referrer", std::string(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
            TestLib::addInfoToSend("json_response", std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
#elif PLATFORM_IOS
            std::string jsonStr = std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse));
            if (!jsonStr.empty()) {
                std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
                std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
                jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
            }
            TestLib::addInfoToSend("json_response", jsonStr);
#endif
        }
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localBasePathValue);
    });
}

void AdjustCommandExecutor::idfaGetter() {
#if PLATFORM_IOS
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfa([testCallbackId, localExtraPath](const FString& Idfa) {
        TestLib::addInfoToSend("idfa", std::string(TCHAR_TO_UTF8(*Idfa)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::idfvGetter() {
#if PLATFORM_IOS
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetIdfv([testCallbackId, localExtraPath](const FString& Idfv) {
        TestLib::addInfoToSend("idfv", std::string(TCHAR_TO_UTF8(*Idfv)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::googleAdIdGetter() {
#if PLATFORM_ANDROID
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetGoogleAdId([testCallbackId, localExtraPath](const FString& GoogleAdId) {
        TestLib::addInfoToSend("gps_adid", std::string(TCHAR_TO_UTF8(*GoogleAdId)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::amazonAdIdGetter() {
#if PLATFORM_ANDROID
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;

    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetAmazonAdId([testCallbackId, localExtraPath](const FString& AmazonAdId) {
        TestLib::addInfoToSend("fire_adid", std::string(TCHAR_TO_UTF8(*AmazonAdId)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
#endif
}

void AdjustCommandExecutor::sdkVersionGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
    }
    std::string localExtraPath = this->basePath;
    
    // use lambda-based C++ API for proper burst/concurrent callback support
    UAdjust::GetSdkVersion([testCallbackId, localExtraPath](const FString& SdkVersion) {
        TestLib::addInfoToSend("sdk_version", std::string(TCHAR_TO_UTF8(*SdkVersion)));
        if (!testCallbackId.empty()) {
            TestLib::addInfoToSend("test_callback_id", testCallbackId);
        }
        TestLib::sendInfoToServer(localExtraPath);
    });
}

void AdjustCommandExecutor::lastDeeplinkGetter() {
    std::string testCallbackId = "";
    if (this->command->containsParameter("testCallbackId")) {
        testCallbackId = this->command->getFirstParameterValue("testCallbackId");
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
    std::string strIsEnabled = this->command->getFirstParameterValue("isEnabled");
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnableCoppaComplianceInDelay();
    } else {
        UAdjust::DisableCoppaComplianceInDelay();
    }
}

void AdjustCommandExecutor::playStoreKidsComplianceInDelay() {
    std::string strIsEnabled = this->command->getFirstParameterValue("isEnabled");
    bool enabled = (strIsEnabled == "true");
    if (enabled) {
        UAdjust::EnablePlayStoreKidsComplianceInDelay();
    } else {
        UAdjust::DisablePlayStoreKidsComplianceInDelay();
    }
}

void AdjustCommandExecutor::externalDeviceIdInDelay() {
    std::string externalDeviceId = this->command->getFirstParameterValue("externalDeviceId");
    UAdjust::SetExternalDeviceIdInDelay(FString(UTF8_TO_TCHAR(externalDeviceId.c_str())));
}
