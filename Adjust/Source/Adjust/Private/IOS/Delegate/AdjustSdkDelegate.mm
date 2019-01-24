//
//  AdjustSdkDelegate.mm
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-2019 Adjust GmbH. All rights reserved.
//

#import "AdjustSdkDelegate.h"

@implementation AdjustSdkDelegate

- (void)adjustAttributionChanged:(ADJAttribution *)attribution {
    FAdjustAttribution ueAttribution;
    ueAttribution.TrackerToken = *FString(attribution.trackerToken);
    ueAttribution.TrackerName = *FString(attribution.trackerName);
    ueAttribution.Network = *FString(attribution.network);
    ueAttribution.Campaign = *FString(attribution.campaign);
    ueAttribution.Adgroup = *FString(attribution.adgroup);
    ueAttribution.Creative = *FString(attribution.creative);
    ueAttribution.ClickLabel = *FString(attribution.clickLabel);
    ueAttribution.Adid = *FString(attribution.adid);
    _attributionCallback(ueAttribution);
}

- (void)adjustEventTrackingSucceeded:(ADJEventSuccess *)eventSuccessResponseData {
    FAdjustEventSuccess ueEventSuccess;
    ueEventSuccess.Message = *FString(eventSuccessResponseData.message);
    ueEventSuccess.Timestamp = *FString(eventSuccessResponseData.timeStamp);
    ueEventSuccess.Adid = *FString(eventSuccessResponseData.adid);
    ueEventSuccess.EventToken = *FString(eventSuccessResponseData.eventToken);
    ueEventSuccess.CallbackId = *FString(eventSuccessResponseData.callbackId);
    if (eventSuccessResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueEventSuccess.JsonResponse = *FString(stringJsonResponse);
    }
    _eventSuccessCallback(ueEventSuccess);
}

- (void)adjustEventTrackingFailed:(ADJEventFailure *)eventFailureResponseData {
    FAdjustEventFailure ueEventFailure;
    ueEventFailure.Message = *FString(eventFailureResponseData.message);
    ueEventFailure.Timestamp = *FString(eventFailureResponseData.timeStamp);
    ueEventFailure.Adid = *FString(eventFailureResponseData.adid);
    ueEventFailure.EventToken = *FString(eventFailureResponseData.eventToken);
    ueEventFailure.CallbackId = *FString(eventFailureResponseData.callbackId);
    ueEventFailure.WillRetry = eventFailureResponseData.willRetry;
    if (eventFailureResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:eventFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueEventFailure.JsonResponse = *FString(stringJsonResponse);
    }
    _eventFailureCallback(ueEventFailure);
}

- (void)adjustSessionTrackingSucceeded:(ADJSessionSuccess *)sessionSuccessResponseData {
    FAdjustSessionSuccess ueSessionSuccess;
    ueSessionSuccess.Message = *FString(sessionSuccessResponseData.message);
    ueSessionSuccess.Timestamp = *FString(sessionSuccessResponseData.timeStamp);
    ueSessionSuccess.Adid = *FString(sessionSuccessResponseData.adid);
    if (sessionSuccessResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionSuccessResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueSessionSuccess.JsonResponse = *FString(stringJsonResponse);
    }
    _sessionSuccessCallback(ueSessionSuccess);
}

- (void)adjustSessionTrackingFailed:(ADJSessionFailure *)sessionFailureResponseData {
    FAdjustSessionFailure ueSessionFailure;
    ueSessionFailure.Message = *FString(sessionFailureResponseData.message);
    ueSessionFailure.Timestamp = *FString(sessionFailureResponseData.timeStamp);
    ueSessionFailure.Adid = *FString(sessionFailureResponseData.adid);
    ueSessionFailure.WillRetry = sessionFailureResponseData.willRetry;
    if (sessionFailureResponseData.jsonResponse != nil) {
        NSData *dataJsonResponse = [NSJSONSerialization dataWithJSONObject:sessionFailureResponseData.jsonResponse options:0 error:nil];
        NSString *stringJsonResponse = [[NSString alloc] initWithBytes:[dataJsonResponse bytes]
                                                                length:[dataJsonResponse length]
                                                              encoding:NSUTF8StringEncoding];
        ueSessionFailure.JsonResponse = *FString(stringJsonResponse);
    }
    _sessionFailureCallback(ueSessionFailure);
}

- (BOOL)adjustDeeplinkResponse:(NSURL *)deeplink {
    NSString *url = [deeplink absoluteString];
    FString ueDeeplink = *FString(url);
    _deferredDeeplinkCallback(ueDeeplink);
    return _shouldOpenDeferredDeeplink;
}

@end
