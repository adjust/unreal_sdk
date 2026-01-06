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
        TestLib::addInfoToSend(SafeString("adid"), SafeString("nil"));
#elif PLATFORM_ANDROID
        TestLib::addInfoToSend(SafeString("adid"), SafeString("null"));
#endif
    } else {
        TestLib::addInfoToSend(SafeString("adid"), SafeString(TCHAR_TO_UTF8(*Adid)));
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnAttributionReceived(const FAdjustAttribution& Attribution)
{
    // check if attribution is empty (timeout case)
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
        TestLib::addInfoToSend(SafeString("tracker_token"), SafeString(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
        TestLib::addInfoToSend(SafeString("tracker_name"), SafeString(TCHAR_TO_UTF8(*Attribution.TrackerName)));
        TestLib::addInfoToSend(SafeString("network"), SafeString(TCHAR_TO_UTF8(*Attribution.Network)));
        TestLib::addInfoToSend(SafeString("campaign"), SafeString(TCHAR_TO_UTF8(*Attribution.Campaign)));
        TestLib::addInfoToSend(SafeString("adgroup"), SafeString(TCHAR_TO_UTF8(*Attribution.Adgroup)));
        TestLib::addInfoToSend(SafeString("creative"), SafeString(TCHAR_TO_UTF8(*Attribution.Creative)));
        TestLib::addInfoToSend(SafeString("click_label"), SafeString(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
        TestLib::addInfoToSend(SafeString("cost_type"), SafeString(TCHAR_TO_UTF8(*Attribution.CostType)));
        std::ostringstream sstream;
        sstream << Attribution.CostAmount;
        std::string costAmountStr = sstream.str();
        // convert to SafeString immediately to avoid Unreal allocator validation
        // get size and data, then copy to SafeString using SystemAllocator
        size_t len = costAmountStr.length();
        const char* data = costAmountStr.c_str();
        SafeString costAmountSafe = SafeString(data, len);
        TestLib::addInfoToSend(SafeString("cost_amount"), costAmountSafe);
        TestLib::addInfoToSend(SafeString("cost_currency"), SafeString(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
        TestLib::addInfoToSend(SafeString("fb_install_referrer"), SafeString(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
        TestLib::addInfoToSend(SafeString("json_response"), SafeString(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
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
        SafeString jsonStrSafe = SafeStringFromStdString(jsonStr);
        TestLib::addInfoToSend(SafeString("json_response"), jsonStrSafe);
#endif
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    
    FString basePathToUse = localBasePath;
    if (basePathToUse.IsEmpty()) {
        return;
    }
    
    FTCHARToUTF8 basePathUTF8(*basePathToUse);
    std::string basePathStr = std::string(basePathUTF8.Get(), basePathUTF8.Length());
    SafeString basePathSafe = SafeStringFromStdString(basePathStr);
    TestLib::sendInfoToServer(basePathSafe);
}

void UAdjustTestCommandExecutorDelegates::OnLastDeeplinkReceived(const FString& LastDeeplink)
{
    TestLib::addInfoToSend(SafeString("last_deeplink"), SafeString(TCHAR_TO_UTF8(*LastDeeplink)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnDeeplinkResolved(const FString& ResolvedLink)
{
    TestLib::addInfoToSend(SafeString("resolved_link"), SafeString(TCHAR_TO_UTF8(*ResolvedLink)));
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localBasePath)));
}

void UAdjustTestCommandExecutorDelegates::OnSdkVersionReceived(const FString& SdkVersion)
{
    TestLib::addInfoToSend(SafeString("sdk_version"), SafeString(TCHAR_TO_UTF8(*SdkVersion)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnPurchaseVerificationFinished(const FAdjustPurchaseVerificationResult& VerificationResult)
{
    TestLib::addInfoToSend(SafeString("verification_status"), SafeString(TCHAR_TO_UTF8(*VerificationResult.VerificationStatus)));
    std::string codeStr = std::to_string(VerificationResult.Code);
    SafeString codeStrSafe = SafeStringFromStdString(codeStr);
    TestLib::addInfoToSend(SafeString("code"), codeStrSafe);
    TestLib::addInfoToSend(SafeString("message"), SafeString(TCHAR_TO_UTF8(*VerificationResult.Message)));
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localBasePath)));
}

void UAdjustTestCommandExecutorDelegates::OnIdfaReceived(const FString& Idfa)
{
    TestLib::addInfoToSend(SafeString("idfa"), SafeString(TCHAR_TO_UTF8(*Idfa)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnIdfvReceived(const FString& Idfv)
{
    TestLib::addInfoToSend(SafeString("idfv"), SafeString(TCHAR_TO_UTF8(*Idfv)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnGoogleAdIdReceived(const FString& GoogleAdId)
{
    TestLib::addInfoToSend(SafeString("gps_adid"), SafeString(TCHAR_TO_UTF8(*GoogleAdId)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnAmazonAdIdReceived(const FString& AmazonAdId)
{
    TestLib::addInfoToSend(SafeString("fire_adid"), SafeString(TCHAR_TO_UTF8(*AmazonAdId)));
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*localExtraPath)));
}

void UAdjustTestCommandExecutorDelegates::OnSkanConversionValueUpdated(const FAdjustSkanConversionDataMap& ConversionData)
{
    // only send if this callback should be active for current test
    if (!shouldSendSkanCallback) {
        return;
    }
    
    for (const auto& Pair : ConversionData.Data) {
        TestLib::addInfoToSend(SafeString(TCHAR_TO_UTF8(*Pair.Key)), SafeString(TCHAR_TO_UTF8(*Pair.Value)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
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
        TestLib::addInfoToSend(SafeString("attribution"), SafeString("nil"));
#elif PLATFORM_ANDROID
        TestLib::addInfoToSend(SafeString("attribution"), SafeString("null"));
#endif
    } else {
        TestLib::addInfoToSend(SafeString("tracker_token"), SafeString(TCHAR_TO_UTF8(*Attribution.TrackerToken)));
        TestLib::addInfoToSend(SafeString("tracker_name"), SafeString(TCHAR_TO_UTF8(*Attribution.TrackerName)));
        TestLib::addInfoToSend(SafeString("network"), SafeString(TCHAR_TO_UTF8(*Attribution.Network)));
        TestLib::addInfoToSend(SafeString("campaign"), SafeString(TCHAR_TO_UTF8(*Attribution.Campaign)));
        TestLib::addInfoToSend(SafeString("adgroup"), SafeString(TCHAR_TO_UTF8(*Attribution.Adgroup)));
        TestLib::addInfoToSend(SafeString("creative"), SafeString(TCHAR_TO_UTF8(*Attribution.Creative)));
        TestLib::addInfoToSend(SafeString("click_label"), SafeString(TCHAR_TO_UTF8(*Attribution.ClickLabel)));
        TestLib::addInfoToSend(SafeString("cost_type"), SafeString(TCHAR_TO_UTF8(*Attribution.CostType)));
        std::ostringstream sstream;
        sstream << Attribution.CostAmount;
        std::string costAmountStr = sstream.str();
        // convert to SafeString immediately to avoid Unreal allocator validation
        // get size and data, then copy to SafeString using SystemAllocator
        size_t len = costAmountStr.length();
        const char* data = costAmountStr.c_str();
        SafeString costAmountSafe = SafeString(data, len);
        TestLib::addInfoToSend(SafeString("cost_amount"), costAmountSafe);
        TestLib::addInfoToSend(SafeString("cost_currency"), SafeString(TCHAR_TO_UTF8(*Attribution.CostCurrency)));
#if PLATFORM_ANDROID
        TestLib::addInfoToSend(SafeString("fb_install_referrer"), SafeString(TCHAR_TO_UTF8(*Attribution.FbInstallReferrer)));
        TestLib::addInfoToSend(SafeString("json_response"), SafeString(TCHAR_TO_UTF8(*Attribution.JsonResponse)));
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
        TestLib::addInfoToSend(SafeString("json_response"), SafeStringFromStdString(jsonStr));
#endif
    }
    if (!testCallbackId.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("test_callback_id"), SafeString(TCHAR_TO_UTF8(*testCallbackId)));
    }
    
    FString basePathToUse = localBasePath;
    if (basePathToUse.IsEmpty()) {
        return;
    }
    
    FTCHARToUTF8 basePathUTF8(*basePathToUse);
    std::string basePathStr = std::string(basePathUTF8.Get(), basePathUTF8.Length());
    SafeString basePathSafe = SafeStringFromStdString(basePathStr);
    TestLib::sendInfoToServer(basePathSafe);
}

void UAdjustTestCommandExecutorDelegates::OnSessionSuccess(const FAdjustSessionSuccess& SessionSuccess)
{
    // only send if this callback should be active for current test
    if (!shouldSendSessionSuccessCallback) {
        return;
    }
    
    TestLib::addInfoToSend(SafeString("message"), SafeString(TCHAR_TO_UTF8(*SessionSuccess.Message)));
    TestLib::addInfoToSend(SafeString("timestamp"), SafeString(TCHAR_TO_UTF8(*SessionSuccess.Timestamp)));
    TestLib::addInfoToSend(SafeString("adid"), SafeString(TCHAR_TO_UTF8(*SessionSuccess.Adid)));
    if (!SessionSuccess.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("jsonResponse"), SafeString(TCHAR_TO_UTF8(*SessionSuccess.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnSessionFailure(const FAdjustSessionFailure& SessionFailure)
{
    // only send if this callback should be active for current test
    if (!shouldSendSessionFailureCallback) {
        return;
    }
    
    TestLib::addInfoToSend(SafeString("message"), SafeString(TCHAR_TO_UTF8(*SessionFailure.Message)));
    TestLib::addInfoToSend(SafeString("timestamp"), SafeString(TCHAR_TO_UTF8(*SessionFailure.Timestamp)));
    TestLib::addInfoToSend(SafeString("adid"), SafeString(TCHAR_TO_UTF8(*SessionFailure.Adid)));
    TestLib::addInfoToSend("willRetry", SessionFailure.WillRetry ? "true" : "false");
    if (!SessionFailure.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("jsonResponse"), SafeString(TCHAR_TO_UTF8(*SessionFailure.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnEventSuccess(const FAdjustEventSuccess& EventSuccess)
{
    // only send if this callback should be active for current test
    if (!shouldSendEventSuccessCallback) {
        return;
    }
    
    TestLib::addInfoToSend(SafeString("message"), SafeString(TCHAR_TO_UTF8(*EventSuccess.Message)));
    TestLib::addInfoToSend(SafeString("timestamp"), SafeString(TCHAR_TO_UTF8(*EventSuccess.Timestamp)));
    TestLib::addInfoToSend(SafeString("adid"), SafeString(TCHAR_TO_UTF8(*EventSuccess.Adid)));
    TestLib::addInfoToSend(SafeString("eventToken"), SafeString(TCHAR_TO_UTF8(*EventSuccess.EventToken)));
    TestLib::addInfoToSend(SafeString("callbackId"), SafeString(TCHAR_TO_UTF8(*EventSuccess.CallbackId)));
    if (!EventSuccess.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("jsonResponse"), SafeString(TCHAR_TO_UTF8(*EventSuccess.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnEventFailure(const FAdjustEventFailure& EventFailure)
{
    // only send if this callback should be active for current test
    if (!shouldSendEventFailureCallback) {
        return;
    }
    
    TestLib::addInfoToSend(SafeString("message"), SafeString(TCHAR_TO_UTF8(*EventFailure.Message)));
    TestLib::addInfoToSend(SafeString("timestamp"), SafeString(TCHAR_TO_UTF8(*EventFailure.Timestamp)));
    TestLib::addInfoToSend(SafeString("adid"), SafeString(TCHAR_TO_UTF8(*EventFailure.Adid)));
    TestLib::addInfoToSend(SafeString("eventToken"), SafeString(TCHAR_TO_UTF8(*EventFailure.EventToken)));
    TestLib::addInfoToSend(SafeString("callbackId"), SafeString(TCHAR_TO_UTF8(*EventFailure.CallbackId)));
    TestLib::addInfoToSend("willRetry", EventFailure.WillRetry ? "true" : "false");
    if (!EventFailure.JsonResponse.IsEmpty()) {
        TestLib::addInfoToSend(SafeString("jsonResponse"), SafeString(TCHAR_TO_UTF8(*EventFailure.JsonResponse)));
    }
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
    }
}

void UAdjustTestCommandExecutorDelegates::OnDeferredDeeplink(const FString& Deeplink)
{
    // only send if this callback should be active for current test
    if (!shouldSendDeferredDeeplinkCallback) {
        return;
    }
    
    TestLib::addInfoToSend(SafeString("deeplink"), SafeString(TCHAR_TO_UTF8(*Deeplink)));
    FString basePathToUse = localBasePath;
    if (!basePathToUse.IsEmpty()) {
        TestLib::sendInfoToServer(SafeString(TCHAR_TO_UTF8(*basePathToUse)));
    }
}
