//
//  AdjustSdkDelegate.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Native/Adjust.h"
#import "../Native/ADJConfig.h"
#import "../../../Public/AdjustAttribution.h"
#import "../../../Public/AdjustSessionSuccess.h"
#import "../../../Public/AdjustSessionFailure.h"
#import "../../../Public/AdjustEventSuccess.h"
#import "../../../Public/AdjustEventFailure.h"
#import "../../../Public/AdjustSkanConversionDataMap.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdjustSdkDelegate : NSObject <AdjustDelegate>

@property (nonatomic) void (*attributionCallback)(FAdjustAttribution attribution);
@property (nonatomic) void (*sessionSuccessCallback)(FAdjustSessionSuccess sessionSuccess);
@property (nonatomic) void (*sessionFailureCallback)(FAdjustSessionFailure sessionFailure);
@property (nonatomic) void (*eventSuccessCallback)(FAdjustEventSuccess eventSuccess);
@property (nonatomic) void (*eventFailureCallback)(FAdjustEventFailure eventFailure);
@property (nonatomic) void (*deferredDeeplinkCallback)(FString deeplink);
@property (nonatomic) void (*skanConversionValueUpdatedCallback)(FAdjustSkanConversionDataMap conversionData);
@property (assign) BOOL shouldOpenDeferredDeeplink;

@end

NS_ASSUME_NONNULL_END
