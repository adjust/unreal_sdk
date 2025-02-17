//
//  AdjustSdkDelegate.mm
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#import "AdjustSdkDelegate.h"
#import "../Native/ADJAttribution.h"
#import "../Native/ADJEventSuccess.h"
#import "../Native/ADJEventFailure.h"
#import "../Native/ADJSessionSuccess.h"
#import "../Native/ADJSessionFailure.h"

@implementation AdjustSdkDelegate

- (void)adjustAttributionChanged:(ADJAttribution *)attribution {
    if (_attributionCallback == nil) {
        return;
    }

    FString trackerToken = *FString(attribution.trackerToken);
    FString trackerName = *FString(attribution.trackerName);
    FString network = *FString(attribution.network);
    FString campaign = *FString(attribution.campaign);
    FString adgroup = *FString(attribution.adgroup);
    FString creative = *FString(attribution.creative);
    FString clickLabel = *FString(attribution.clickLabel);

    auto callback = _attributionCallback;
    AsyncTask(ENamedThreads::GameThread, [trackerToken, trackerName, network, campaign, adgroup, creative, clickLabel, callback]() {
        FAdjustAttribution ueAttribution;
        ueAttribution.TrackerToken = trackerToken;
        ueAttribution.TrackerName = trackerName;
        ueAttribution.Network = network;
        ueAttribution.Campaign = campaign;
        ueAttribution.Adgroup = adgroup;
        ueAttribution.Creative = creative;
        ueAttribution.ClickLabel = clickLabel;

        if (callback) {
            callback(ueAttribution);
        }
    });
}

- (void)adjustEventTrackingSucceeded:(ADJEventSuccess *)eventSuccessResponseData {
    if (_eventSuccessCallback == nil) {
        return;
    }

    FString message = *FString(eventSuccessResponseData.message);
    FString timestamp = *FString(eventSuccessResponseData.timestamp);
    FString adid = *FString(eventSuccessResponseData.adid);
    FString eventToken = *FString(eventSuccessResponseData.eventToken);
    FString callbackId = *FString(eventSuccessResponseData.callbackId);

    FString jsonResponseString;
    if (eventSuccessResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithData:dataJsonResponse encoding:NSUTF8StringEncoding];
        jsonResponseString = *FString(stringJsonResponse);
    }

    auto callback = _eventSuccessCallback;
    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, eventToken, callbackId, jsonResponseString, callback]() {
        FAdjustEventSuccess ueEventSuccess;
        ueEventSuccess.Message = message;
        ueEventSuccess.Timestamp = timestamp;
        ueEventSuccess.Adid = adid;
        ueEventSuccess.EventToken = eventToken;
        ueEventSuccess.CallbackId = callbackId;
        ueEventSuccess.JsonResponse = jsonResponseString;

        if (callback) {
            callback(ueEventSuccess);
        }
    });
}

- (void)adjustEventTrackingFailed:(ADJEventFailure *)eventFailureResponseData {
    if (_eventFailureCallback == nil) {
        return;
    }

    FString message = *FString(eventFailureResponseData.message);
    FString timestamp = *FString(eventFailureResponseData.timestamp);
    FString adid = *FString(eventFailureResponseData.adid);
    FString eventToken = *FString(eventFailureResponseData.eventToken);
    FString callbackId = *FString(eventFailureResponseData.callbackId);
    bool willRetry = eventFailureResponseData.willRetry;

    FString jsonResponseString;
    if (eventFailureResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithData:dataJsonResponse encoding:NSUTF8StringEncoding];
        jsonResponseString = *FString(stringJsonResponse);
    }

    auto callback = _eventFailureCallback;
    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, eventToken, callbackId, willRetry, jsonResponseString, callback]() {
        FAdjustEventFailure ueEventFailure;
        ueEventFailure.Message = message;
        ueEventFailure.Timestamp = timestamp;
        ueEventFailure.Adid = adid;
        ueEventFailure.EventToken = eventToken;
        ueEventFailure.CallbackId = callbackId;
        ueEventFailure.WillRetry = willRetry;
        ueEventFailure.JsonResponse = jsonResponseString;

        if (callback) {
            callback(ueEventFailure);
        }
    });
}

- (void)adjustSessionTrackingSucceeded:(ADJSessionSuccess *)sessionSuccessResponseData {
    if (_sessionSuccessCallback == nil) {
        return;
    }

    FString message = *FString(sessionSuccessResponseData.message);
    FString timestamp = *FString(sessionSuccessResponseData.timestamp);
    FString adid = *FString(sessionSuccessResponseData.adid);

    FString jsonResponseString;
    if (sessionSuccessResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithData:dataJsonResponse encoding:NSUTF8StringEncoding];
        jsonResponseString = *FString(stringJsonResponse);
    }

    auto callback = _sessionSuccessCallback;
    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, jsonResponseString, callback]() {
        FAdjustSessionSuccess ueSessionSuccess;
        ueSessionSuccess.Message = message;
        ueSessionSuccess.Timestamp = timestamp;
        ueSessionSuccess.Adid = adid;
        ueSessionSuccess.JsonResponse = jsonResponseString;

        if (callback) {
            callback(ueSessionSuccess);
        }
    });
}

- (void)adjustSessionTrackingFailed:(ADJSessionFailure *)sessionFailureResponseData {
    if (_sessionFailureCallback == nil) {
        return;
    }

    FString message = *FString(sessionFailureResponseData.message);
    FString timestamp = *FString(sessionFailureResponseData.timestamp);
    FString adid = *FString(sessionFailureResponseData.adid);
    bool willRetry = sessionFailureResponseData.willRetry;

    FString jsonResponseString;
    if (sessionFailureResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithData:dataJsonResponse encoding:NSUTF8StringEncoding];
        jsonResponseString = *FString(stringJsonResponse);
    }

    auto callback = _sessionFailureCallback;
    AsyncTask(ENamedThreads::GameThread, [message, timestamp, adid, willRetry, jsonResponseString, callback]() {
        FAdjustSessionFailure ueSessionFailure;
        ueSessionFailure.Message = message;
        ueSessionFailure.Timestamp = timestamp;
        ueSessionFailure.Adid = adid;
        ueSessionFailure.WillRetry = willRetry;
        ueSessionFailure.JsonResponse = jsonResponseString;

        if (callback) {
            callback(ueSessionFailure);
        }
    });
}

- (BOOL)adjustDeferredDeeplinkReceived:(NSURL *)deeplink {
    if (_deferredDeeplinkCallback == nil) {
        return YES;
    }

    FString ueDeeplink = *FString([deeplink absoluteString]);

    auto callback = _deferredDeeplinkCallback;    
    AsyncTask(ENamedThreads::GameThread, [ueDeeplink, callback]() {
        if (callback) {
            callback(ueDeeplink);
        }
    });

    return _shouldOpenDeferredDeeplink;
}

@end
