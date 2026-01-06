//
//  AdjustTestCommandExecutorDelegates.cpp
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "AdjustTestCommandExecutorDelegates.h"
#include "TestLib.h"
#include "CoreMinimal.h"
#if !PLATFORM_IOS || (defined(__cpp_exceptions) && __cpp_exceptions)
#include "json/json.hpp"
#endif
#include <sstream>
#include <regex>

void UAdjustTestCommandExecutorDelegates::OnAdidReceived(const FString& Adid)
{
    if (Adid.IsEmpty()) {
#if PLATFORM_IOS
        TestLib::addInfoToSend(std::string("adid"), std::string("nil"));
#elif PLATFORM_ANDROID
        TestLib::addInfoToSend(std::string("adid"), std::string("null"));
#endif
    } else {
        TestLib::addInfoToSend(std::string("adid"), std::string(TCHAR_TO_UTF8(*Adid)));
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnAttributionReceived(const FAdjustAttribution& Attribution)
{
    // check if attribution is empty (timeout case)
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
        TestLib::addInfoToSend(std::string("tracker_token"), std::string(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
        TestLib::addInfoToSend(std::string("tracker_name"), std::string(TCHAR_TO_UTF8(*Attribution.TrackerName)));
        TestLib::addInfoToSend(std::string("network"), std::string(TCHAR_TO_UTF8(*Attribution.Network)));
        TestLib::addInfoToSend(std::string("campaign"), std::string(TCHAR_TO_UTF8(*Attribution.Campaign)));
        TestLib::addInfoToSend(std::string("adgroup"), std::string(TCHAR_TO_UTF8(*Attribution.Adgroup)));
        TestLib::addInfoToSend(std::string("creative"), std::string(TCHAR_TO_UTF8(*Attribution.Creative)));
        TestLib::addInfoToSend(std::string("click_label"), std::string(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
        TestLib::addInfoToSend(std::string("cost_type"), std::string(TCHAR_TO_UTF8(*Attribution.CostType)));
        std::ostringstream sstream;
        sstream << Attribution.CostAmount;
        std::string costAmountStr = sstream.str();
        TestLib::addInfoToSend(std::string("cost_amount"), costAmountStr);
        TestLib::addInfoToSend(std::string("cost_currency"), std::string(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
        TestLib::addInfoToSend(std::string("fb_install_referrer"), std::string(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
        TestLib::addInfoToSend(std::string("json_response"), std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
#elif PLATFORM_IOS
        // remove fb_install_referrer on ios
        FTCHARToUTF8 jsonResponseUTF8(*Attribution.JsonResponse);
        std::string jsonStr = std::string(jsonResponseUTF8.Get(), jsonResponseUTF8.Length());
        if (!jsonStr.empty()) {
            // remove fb_install_referrer using regex (safer for iOS where exceptions may be disabled)
            // pattern matches: "fb_install_referrer":"value" or ,"fb_install_referrer":"value"
            std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
            jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
            // also handle case where it's the first field
            std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
            jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
        }
        TestLib::addInfoToSend(std::string("json_response"), jsonStr);
#endif
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    
    FString basePathToUse = localBasePath;
    if (basePathToUse.IsEmpty()) {
        return;
    }
    
    FTCHARToUTF8 basePathUTF8(*basePathToUse);
    std::string basePathStr = std::string(basePathUTF8.Get(), basePathUTF8.Length());
    TestLib::sendInfoToServer(basePathStr);
}

void UAdjustTestCommandExecutorDelegates::OnLastDeeplinkReceived(const FString& LastDeeplink)
{
    TestLib::addInfoToSend(std::string("last_deeplink"), std::string(TCHAR_TO_UTF8(*LastDeeplink)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnDeeplinkResolved(const FString& ResolvedLink)
{
    TestLib::addInfoToSend(std::string("resolved_link"), std::string(TCHAR_TO_UTF8(*ResolvedLink)));
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localBasePath)));
}

void UAdjustTestCommandExecutorDelegates::OnSdkVersionReceived(const FString& SdkVersion)
{
    TestLib::addInfoToSend(std::string("sdk_version"), std::string(TCHAR_TO_UTF8(*SdkVersion)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnPurchaseVerificationFinished(const FAdjustPurchaseVerificationResult& VerificationResult)
{
    TestLib::addInfoToSend(std::string("verification_status"), std::string(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
    std::string codeStr = std::to_string(VerificationResult.Code);
    TestLib::addInfoToSend(std::string("code"), codeStr);
    TestLib::addInfoToSend(std::string("message"), std::string(TCHAR_TO_UTF8(*VerificationResult.Message)));
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localBasePath)));
}

void UAdjustTestCommandExecutorDelegates::OnIdfaReceived(const FString& Idfa)
{
    TestLib::addInfoToSend(std::string("idfa"), std::string(TCHAR_TO_UTF8(*Idfa)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnIdfvReceived(const FString& Idfv)
{
    TestLib::addInfoToSend(std::string("idfv"), std::string(TCHAR_TO_UTF8(*Idfv)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnGoogleAdIdReceived(const FString& GoogleAdId)
{
    TestLib::addInfoToSend(std::string("gps_adid"), std::string(TCHAR_TO_UTF8(*GoogleAdId)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnAmazonAdIdReceived(const FString& AmazonAdId)
{
    TestLib::addInfoToSend(std::string("fire_adid"), std::string(TCHAR_TO_UTF8(*AmazonAdId)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnSkanConversionValueUpdated(const FAdjustSkanConversionDataMap& ConversionData)
{
    // only send if this callback should be active for current test
    if (!shouldSendSkanCallback) {
        return;
    }
    
    for (const auto& Pair : ConversionData.Data) {
        TestLib::addInfoToSend(std::string(TCHAR_TO_UTF8(*Pair.Key)), std::string(TCHAR_TO_UTF8(*Pair.Value)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnAttributionChanged(const FAdjustAttribution& Attribution)
{
    // only send if this callback should be active for current test
    if (!shouldSendAttributionCallback) {
        return;
    }
    
    // check if attribution is empty (timeout case)
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
        TestLib::addInfoToSend(std::string("tracker_token"), std::string(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
        TestLib::addInfoToSend(std::string("tracker_name"), std::string(TCHAR_TO_UTF8(*Attribution.TrackerName)));
        TestLib::addInfoToSend(std::string("network"), std::string(TCHAR_TO_UTF8(*Attribution.Network)));
        TestLib::addInfoToSend(std::string("campaign"), std::string(TCHAR_TO_UTF8(*Attribution.Campaign)));
        TestLib::addInfoToSend(std::string("adgroup"), std::string(TCHAR_TO_UTF8(*Attribution.Adgroup)));
        TestLib::addInfoToSend(std::string("creative"), std::string(TCHAR_TO_UTF8(*Attribution.Creative)));
        TestLib::addInfoToSend(std::string("click_label"), std::string(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
        TestLib::addInfoToSend(std::string("cost_type"), std::string(TCHAR_TO_UTF8(*Attribution.CostType)));
        std::ostringstream sstream;
        sstream << Attribution.CostAmount;
        std::string costAmountStr = sstream.str();
        TestLib::addInfoToSend(std::string("cost_amount"), costAmountStr);
        TestLib::addInfoToSend(std::string("cost_currency"), std::string(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
        TestLib::addInfoToSend(std::string("fb_install_referrer"), std::string(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
        TestLib::addInfoToSend(std::string("json_response"), std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
#elif PLATFORM_IOS
        std::string jsonStr = std::string(TCHAR_TO_UTF8(*Attribution.JsonResponse));
        if (!jsonStr.empty()) {
            // remove fb_install_referrer using regex (safer for iOS where exceptions may be disabled)
            // pattern matches: "fb_install_referrer":"value" or ,"fb_install_referrer":"value"
            std::regex fbInstallReferrerPattern(R"(,?"fb_install_referrer"\s*:\s*"[^"]*")");
            jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPattern, "");
            // also handle case where it's the first field
            std::regex fbInstallReferrerPatternFirst(R"("fb_install_referrer"\s*:\s*"[^"]*"\s*,)");
            jsonStr = std::regex_replace(jsonStr, fbInstallReferrerPatternFirst, "");
        }
        TestLib::addInfoToSend(std::string("json_response"), jsonStr);
#endif
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(std::string("test_callback_id"), std::string(TCHAR_TO_UTF8(*testCallbackId)));
    }
    
    FString basePathToUse = localBasePath;
    if (basePathToUse.IsEmpty()) {
        return;
    }
    
    FTCHARToUTF8 basePathUTF8(*basePathToUse);
    std::string basePathStr = std::string(basePathUTF8.Get(), basePathUTF8.Length());
    TestLib::sendInfoToServer(basePathStr);
}

void UAdjustTestCommandExecutorDelegates::OnSessionSuccess(const FAdjustSessionSuccess& SessionSuccess)
{
    // only send if this callback should be active for current test
    if (!shouldSendSessionSuccessCallback) {
        return;
    }
    
    TestLib::addInfoToSend(std::string("message"), std::string(TCHAR_TO_UTF8(*SessionSuccess.Message)));
    TestLib::addInfoToSend(std::string("timestamp"), std::string(TCHAR_TO_UTF8(*SessionSuccess.Timestamp)));
    TestLib::addInfoToSend(std::string("adid"), std::string(TCHAR_TO_UTF8(*SessionSuccess.Adid)));
    if (!SessionSuccess.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(std::string("jsonResponse"), std::string(TCHAR_TO_UTF8(*SessionSuccess.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnSessionFailure(const FAdjustSessionFailure& SessionFailure)
{
    // only send if this callback should be active for current test
    if (!shouldSendSessionFailureCallback) {
        return;
    }
    
    TestLib::addInfoToSend(std::string("message"), std::string(TCHAR_TO_UTF8(*SessionFailure.Message)));
    TestLib::addInfoToSend(std::string("timestamp"), std::string(TCHAR_TO_UTF8(*SessionFailure.Timestamp)));
    TestLib::addInfoToSend(std::string("adid"), std::string(TCHAR_TO_UTF8(*SessionFailure.Adid)));
    TestLib::addInfoToSend("willRetry", SessionFailure.WillRetry ? "true" : "false");
    if (!SessionFailure.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(std::string("jsonResponse"), std::string(TCHAR_TO_UTF8(*SessionFailure.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnEventSuccess(const FAdjustEventSuccess& EventSuccess)
{
    // only send if this callback should be active for current test
    if (!shouldSendEventSuccessCallback) {
        return;
    }
    
    TestLib::addInfoToSend(std::string("message"), std::string(TCHAR_TO_UTF8(*EventSuccess.Message)));
    TestLib::addInfoToSend(std::string("timestamp"), std::string(TCHAR_TO_UTF8(*EventSuccess.Timestamp)));
    TestLib::addInfoToSend(std::string("adid"), std::string(TCHAR_TO_UTF8(*EventSuccess.Adid)));
    TestLib::addInfoToSend(std::string("eventToken"), std::string(TCHAR_TO_UTF8(*EventSuccess.EventToken)));
    TestLib::addInfoToSend(std::string("callbackId"), std::string(TCHAR_TO_UTF8(*EventSuccess.CallbackId)));
    if (!EventSuccess.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(std::string("jsonResponse"), std::string(TCHAR_TO_UTF8(*EventSuccess.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnEventFailure(const FAdjustEventFailure& EventFailure)
{
    // only send if this callback should be active for current test
    if (!shouldSendEventFailureCallback) {
        return;
    }
    
    TestLib::addInfoToSend(std::string("message"), std::string(TCHAR_TO_UTF8(*EventFailure.Message)));
    TestLib::addInfoToSend(std::string("timestamp"), std::string(TCHAR_TO_UTF8(*EventFailure.Timestamp)));
    TestLib::addInfoToSend(std::string("adid"), std::string(TCHAR_TO_UTF8(*EventFailure.Adid)));
    TestLib::addInfoToSend(std::string("eventToken"), std::string(TCHAR_TO_UTF8(*EventFailure.EventToken)));
    TestLib::addInfoToSend(std::string("callbackId"), std::string(TCHAR_TO_UTF8(*EventFailure.CallbackId)));
    TestLib::addInfoToSend("willRetry", EventFailure.WillRetry ? "true" : "false");
    if (!EventFailure.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(std::string("jsonResponse"), std::string(TCHAR_TO_UTF8(*EventFailure.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnDeferredDeeplink(const FString& Deeplink)
{
    // only send if this callback should be active for current test
    if (!shouldSendDeferredDeeplinkCallback) {
        return;
    }
    
    TestLib::addInfoToSend(std::string("deeplink"), std::string(TCHAR_TO_UTF8(*Deeplink)));
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(std::string(TCHAR_TO_UTF8(*basePathToUse)));
    }
}
