//
//  AdjustCommandDelegate.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#import <AdjustTestLibrary/ATLTestLibrary.h>
#import <iostream>

@interface AdjustCommandDelegateUE : NSObject<AdjustCommandDelegate>

@property (nonatomic) void (*commandExecutorCallback)(std::string className, std::string methodName, std::string jsonParameters);

+ (id)getInstanceWithCommandExecutorCallbackId:(void (*)(std::string className, std::string methodName, std::string jsonParameters))commandExecutorCallbackId;

@end
