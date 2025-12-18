//
//  AdjustCommandDelegate.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#import <AdjustTestLibrary/ATLTestLibrary.h>
#import <iostream>

@interface AdjustCommandDelegateUE : NSObject<AdjustCommandDelegate>

@property (nonatomic) void (*commandExecutorCallback)(std::string className, std::string methodName, std::string jsonParameters);

+ (id)getInstanceWithCommandExecutorCallbackId:(void (*)(std::string className, std::string methodName, std::string jsonParameters))commandExecutorCallbackId;

@end
