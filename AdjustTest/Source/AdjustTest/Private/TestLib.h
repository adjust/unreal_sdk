//
//  TestLib.h
//  Adjust SDK
//
//  Created by Uglješa Erceg (@uerceg) on 27th September 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include <string>
#include <cstdlib>
#include "CoreMinimal.h"

// custom allocator that bypasses Unreal's allocator system to prevent FMallocBinned crashes
// when interacting with JNI/JVM memory during stack unwinding
template<typename T>
struct SystemAllocator {
    using value_type = T;
    
    T* allocate(size_t n) { 
        return (T*)std::malloc(n * sizeof(T)); 
    }
    
    void deallocate(T* p, size_t) { 
        std::free(p); 
    }
    
    template<typename U>
    bool operator==(const SystemAllocator<U>&) const { return true; }
    
    template<typename U>
    bool operator!=(const SystemAllocator<U>&) const { return false; }
};

// use SafeString instead of std::string to avoid Unreal allocator conflicts
using SafeString = std::basic_string<char, std::char_traits<char>, SystemAllocator<char>>;

// helper function to safely convert std::string to SafeString
// copies the string data immediately to avoid Unreal allocator validation issues
// by accessing the string's internal buffer only once and copying it immediately
inline SafeString SafeStringFromStdString(const std::string& str) {
    if (str.empty()) {
        return SafeString("");
    }
    size_t len = str.length();
    const char* data = str.c_str();
    // construct SafeString with copied data using SystemAllocator
    SafeString result(data, len);
    return result;
}

// helper function to safely convert SafeString to std::string
// creates std::string from SafeString data, ensuring proper copy
inline std::string StdStringFromSafeString(const SafeString& str) {
    if (str.empty()) {
        return std::string("");
    }
    size_t len = str.size();
    const char* data = str.c_str();
    // construct std::string with copied data
    // this is safe because we're on the game thread when this is called
    std::string result(data, len);
    return result;
}

#if PLATFORM_IOS
class ATLTestLibraryWrapper;
#endif

class TestLib {
private:
    void initTestLibrary(const SafeString& baseUrl, const SafeString& controlUrl, void(*executeCommandCallback)(SafeString className, SafeString methodName, SafeString jsonParameters));

#if PLATFORM_IOS
    ATLTestLibraryWrapper* testLibrary;
#elif PLATFORM_ANDROID
    void* testLibrary; // jobject
#endif

public:
    TestLib(const SafeString& baseUrl, const SafeString& controlUrl, void(*executeCommandCallback)(SafeString className, SafeString methodName, SafeString jsonParameters));
    ~TestLib();

    void addTest(const SafeString& testName);
    void addTestDirectory(const SafeString& testDirectory);
    void startTestSession(const SafeString& clientSdk);
    static void addInfoToSend(const SafeString& key, const SafeString& value);
    static void sendInfoToServer(const SafeString& basePath);
    
#if PLATFORM_ANDROID
    // get static instance to ensure it stays alive
    static TestLib* GetStaticInstance();
#endif
};
