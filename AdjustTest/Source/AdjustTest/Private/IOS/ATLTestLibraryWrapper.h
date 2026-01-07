//
//  ATLTestLibraryWrapper.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 18th December 2025.
//  Copyright © 2025-Present Adjust GmbH. All rights reserved.
//

#pragma once

class ATLTestLibraryWrapper {
private:
    void* testLibrary;

public:
    ATLTestLibraryWrapper() {}
    ATLTestLibraryWrapper(std::string baseUrl, std::string controlUrl, void(*executeCommandCallback)(std::string className, std::string methodName, std::string jsonParameters));
    ~ATLTestLibraryWrapper();

    void addTest(std::string testName);
    void addTestDirectory(std::string testDirectory);
    void startTestSession(std::string clientSdk);
    void addInfoToSend(std::string key, std::string value);
    void sendInfoToServer(std::string basePath);
};
