//
//  AdjustCommandExecutor.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include <map>
#include <string>
#include <vector>
#include "Command.h"
#include "../Public/AdjustTest.h"
#include "Adjust.h"
#include "AdjustEvent.h"
#include "AdjustConfig.h"
#include "AdjustAttribution.h"
#include "AdjustAppStoreSubscription.h"
#include "AdjustPlayStoreSubscription.h"
#include "AdjustEventFailure.h"
#include "AdjustEventSuccess.h"
#include "AdjustSessionSuccess.h"
#include "AdjustSessionFailure.h"
#include "AdjustThirdPartySharing.h"
#include "AdjustAdRevenue.h"
#include "AdjustAppStorePurchase.h"
#include "AdjustPlayStorePurchase.h"
#include "AdjustDeeplink.h"
#include "AdjustPurchaseVerificationResult.h"
#include "AdjustStoreInfo.h"
#include "TestLib.h"
#include "AdjustTestCommandExecutorDelegates.h"

class AdjustCommandExecutor {
private:
    std::string urlOverwrite;
    std::string basePath;
    std::map<int8_t, FAdjustEvent> savedEvents;
    std::map<int8_t, FAdjustConfig> savedConfigs;
    Command *command;

    void testOptions();
    void config();
    void start();
    void event();
    void trackEvent();
    void pause();
    void resume();
    void setEnabled();
    void setOfflineMode();
    void addGlobalCallbackParameter();
    void addGlobalPartnerParameter();
    void removeGlobalCallbackParameter();
    void removeGlobalPartnerParameter();
    void removeGlobalCallbackParameters();
    void removeGlobalPartnerParameters();
    void setPushToken();
    void openDeeplink();
    void gdprForgetMe();
    void trackSubscription();
    void trackThirdPartySharing();
    void trackMeasurementConsent();
    void trackAdRevenue();
    void getLastDeeplink();
    void verifyPurchase();
    void verifyTrack();
    void processDeeplink();
    void attributionGetter();
    void adidGetter();
    void adidGetterWithTimeout();
    void attributionGetterWithTimeout();
    void idfaGetter();
    void idfvGetter();
    void googleAdIdGetter();
    void amazonAdIdGetter();
    void sdkVersionGetter();
    void lastDeeplinkGetter();
    void endFirstSessionDelay();
    void coppaComplianceInDelay();
    void playStoreKidsComplianceInDelay();
    void externalDeviceIdInDelay();
public:
    static const std::string TAG;
    AdjustCommandExecutor(const std::string& urlOverwrite);
    void executeCommand(Command *command);
};
