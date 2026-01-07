//
//  ATLTestLibraryWrapper.mm
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#include "ATLTestLibraryWrapper.h"
#include "AdjustCommandDelegate.h"
#include <AdjustTestLibrary/ATLTestLibrary.h>
#include <string>

@interface ATLTestLibraryWrapperObjC : NSObject

@property (nonatomic, strong) ATLTestLibrary *testLibrary;

@end

@implementation ATLTestLibraryWrapperObjC
@end

ATLTestLibraryWrapper::ATLTestLibraryWrapper(std::string baseUrl, std::string controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters)) {
	AdjustCommandDelegateUE *adjustCommandDelegate =
    [AdjustCommandDelegateUE getInstanceWithCommandExecutorCallbackId:executeCommandCallback];
	ATLTestLibrary *atlTestLib =
    [ATLTestLibrary testLibraryWithBaseUrl:[NSString stringWithUTF8String:baseUrl.c_str()]
                             andControlUrl:[NSString stringWithUTF8String:controlUrl.c_str()]
                        andCommandDelegate:adjustCommandDelegate];

	ATLTestLibraryWrapperObjC *testLibWrapper = [[ATLTestLibraryWrapperObjC alloc] init];
	testLibWrapper.testLibrary = atlTestLib;
	testLibrary = (void *)testLibWrapper;
}

ATLTestLibraryWrapper::~ATLTestLibraryWrapper() {
	if (testLibrary != nullptr) {
		CFBridgingRelease(testLibrary);
		testLibrary = nullptr;
	}
}

void ATLTestLibraryWrapper::addTest(std::string testName) {
	ATLTestLibraryWrapperObjC *testLibWrapper = (__bridge ATLTestLibraryWrapperObjC *)testLibrary;
	if (testLibWrapper != nil && testLibWrapper.testLibrary != nil) {
		[testLibWrapper.testLibrary addTest:[NSString stringWithUTF8String:testName.c_str()]];
	}
}

void ATLTestLibraryWrapper::addTestDirectory(std::string testDirectory) {
	ATLTestLibraryWrapperObjC *testLibWrapper = (__bridge ATLTestLibraryWrapperObjC *)testLibrary;
	[testLibWrapper.testLibrary addTestDirectory:[NSString stringWithUTF8String:testDirectory.c_str()]];
}

void ATLTestLibraryWrapper::startTestSession(std::string clientSdk) {
    ATLTestLibraryWrapperObjC *testLibWrapper = (__bridge ATLTestLibraryWrapperObjC *)testLibrary;
    NSString *clientSdkString = [NSString stringWithUTF8String:clientSdk.c_str()];
    [testLibWrapper.testLibrary startTestSession:clientSdkString];
}

void ATLTestLibraryWrapper::addInfoToSend(std::string key, std::string value) {
	ATLTestLibraryWrapperObjC *testLibWrapper = (__bridge ATLTestLibraryWrapperObjC *)testLibrary;
	if (testLibWrapper != nil && testLibWrapper.testLibrary != nil) {
		NSString *keyString = [NSString stringWithUTF8String:key.c_str()];
		NSString *valueString = [NSString stringWithUTF8String:value.c_str()];
		[testLibWrapper.testLibrary addInfoToSend:keyString value:valueString];
	}
}

void ATLTestLibraryWrapper::sendInfoToServer(std::string basePath) {
	ATLTestLibraryWrapperObjC *testLibWrapper = (__bridge ATLTestLibraryWrapperObjC *)testLibrary;
	if (testLibWrapper != nil && testLibWrapper.testLibrary != nil) {
		NSString *basePathString = [NSString stringWithUTF8String:basePath.c_str()];
		[testLibWrapper.testLibrary sendInfoToServer:basePathString];
	}
}
