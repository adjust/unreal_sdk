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

    FAdjustAttribution ueAttribution;
    ueAttribution.TrackerToken = *FString(attribution.trackerToken);
    ueAttribution.TrackerName = *FString(attribution.trackerName);
    ueAttribution.Network = *FString(attribution.network);
    ueAttribution.Campaign = *FString(attribution.campaign);
    ueAttribution.Adgroup = *FString(attribution.adgroup);
    ueAttribution.Creative = *FString(attribution.creative);
    ueAttribution.ClickLabel = *FString(attribution.clickLabel);
    _attributionCallback(ueAttribution);
}

- (void)adjustEventTrackingSucceeded:(ADJEventSuccess *)eventSuccessResponseData {
    if (_eventSuccessCallback == nil) {
        return;
    }

    FAdjustEventSuccess ueEventSuccess;
    ueEventSuccess.Message = *FString(eventSuccessResponseData.message);
    ueEventSuccess.Timestamp = *FString(eventSuccessResponseData.timestamp);
    ueEventSuccess.Adid = *FString(eventSuccessResponseData.adid);
    ueEventSuccess.EventToken = *FString(eventSuccessResponseData.eventToken);
    ueEventSuccess.CallbackId = *FString(eventSuccessResponseData.callbackId);
    if (eventSuccessResponseData.jsonResponse != nil)
    {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueEventSuccess.JsonResponse = *FString(stringJsonResponse);
    }
    _eventSuccessCallback(ueEventSuccess);
}

- (void)adjustEventTrackingFailed:(ADJEventFailure *)eventFailureResponseData {
    if (_eventFailureCallback == nil) {
        return;
    }

    FAdjustEventFailure ueEventFailure;
    ueEventFailure.Message = *FString(eventFailureResponseData.message);
    ueEventFailure.Timestamp = *FString(eventFailureResponseData.timestamp);
    ueEventFailure.Adid = *FString(eventFailureResponseData.adid);
    ueEventFailure.EventToken = *FString(eventFailureResponseData.eventToken);
    ueEventFailure.CallbackId = *FString(eventFailureResponseData.callbackId);
    ueEventFailure.WillRetry = eventFailureResponseData.willRetry;
    if (eventFailureResponseData.jsonResponse != nil)
    {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueEventFailure.JsonResponse = *FString(stringJsonResponse);
    }
    _eventFailureCallback(ueEventFailure);
}

- (void)adjustSessionTrackingSucceeded:(ADJSessionSuccess *)sessionSuccessResponseData {
    if (_sessionSuccessCallback == nil) {
        return;
    }

    FAdjustSessionSuccess ueSessionSuccess;
    ueSessionSuccess.Message = *FString(sessionSuccessResponseData.message);
    ueSessionSuccess.Timestamp = *FString(sessionSuccessResponseData.timestamp);
    ueSessionSuccess.Adid = *FString(sessionSuccessResponseData.adid);
    if (sessionSuccessResponseData.jsonResponse != nil)
    {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueSessionSuccess.JsonResponse = *FString(stringJsonResponse);
    }
    _sessionSuccessCallback(ueSessionSuccess);
}

- (void)adjustSessionTrackingFailed:(ADJSessionFailure *)sessionFailureResponseData {
    if (_sessionFailureCallback == nil) {
        return;
    }

    FAdjustSessionFailure ueSessionFailure;
    ueSessionFailure.Message = *FString(sessionFailureResponseData.message);
    ueSessionFailure.Timestamp = *FString(sessionFailureResponseData.timestamp);
    ueSessionFailure.Adid = *FString(sessionFailureResponseData.adid);
    ueSessionFailure.WillRetry = sessionFailureResponseData.willRetry;
    if (sessionFailureResponseData.jsonResponse != nil)
    {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueSessionFailure.JsonResponse = *FString(stringJsonResponse);
    }
    _sessionFailureCallback(ueSessionFailure);
}

- (BOOL)adjustDeferredDeeplinkReceived:(NSURL *)deeplink {
    if (_deferredDeeplinkCallback == nil) {
        return YES;
    }

    NSString *url = [deeplink absoluteString];
    FString ueDeeplink = *FString(url);
    _deferredDeeplinkCallback(ueDeeplink);
    return _shouldOpenDeferredDeeplink;
}

@end
