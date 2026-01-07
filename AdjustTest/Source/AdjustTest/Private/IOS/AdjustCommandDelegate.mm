//
//  AdjustCommandDelegate.mm
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#import <objc/runtime.h>
#import "AdjustCommandDelegate.h"

@implementation AdjustCommandDelegateUE

+ (id)getInstanceWithCommandExecutorCallbackId:(void (*)(std::string className, std::string methodName, std::string jsonParameters))commandExecutorCallbackId {
    static dispatch_once_t onceToken;
    static AdjustCommandDelegateUE *defaultInstance = nil;

    dispatch_once(&onceToken, ^{
        defaultInstance = [[AdjustCommandDelegateUE alloc] init];
        [defaultInstance setCommandExecutorCallback:commandExecutorCallbackId];
    });

    return defaultInstance;
}

- (id)init {
    self = [super init];
    if (nil == self) {
        return nil;
    }
    return self;
}

- (void)executeCommand:(NSString *)className
            methodName:(NSString *)methodName
        jsonParameters:(NSString *)jsonParameters {
    if (nil == _commandExecutorCallback) {
        return;
    }

    std::string strClassName = std::string([className UTF8String]);
    std::string strMethodName = std::string([methodName UTF8String]);
    std::string strJsonParameters = std::string([jsonParameters UTF8String]);
    _commandExecutorCallback(strClassName, strMethodName, strJsonParameters);
}

@end
