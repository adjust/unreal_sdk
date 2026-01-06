//
//  Command.cpp
//  Adjust SDK
//
//  Created by Srdjan Tubin (@2beens) on 4th June 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "Command.h"
#include <iterator>
#include "HAL/PlatformMemory.h"

using json = nlohmann::json;

Command::Command(SafeString className, SafeString methodName, SafeString parametersJson) {
    this->className = className;
    this->methodName = methodName;

    // reason for changing [null] to []: https://github.com/nlohmann/json/issues/1163
    replace(parametersJson, SafeString("[null]"), SafeString("[\"\"]"));
    replace(parametersJson, SafeString("[null,"), SafeString("[\"\","));
    replace(parametersJson, SafeString("null"), SafeString("\"\""));
    replace(parametersJson, SafeString("null,"), SafeString("\"\","));
    
    // convert SafeString to std::string for json::parse (json library uses std::string)
    // CRITICAL: Use FMemory::Malloc to create a temporary buffer to avoid allocator conflicts
    // SafeString::c_str() may point to JVM-allocated memory, so we must copy it immediately
    size_t jsonSize = parametersJson.size();
    char* jsonBuffer = (char*)FMemory::Malloc(jsonSize + 1);
    if (jsonBuffer == nullptr) {
        // If allocation fails, create empty parameters map
        return;
    }
    FMemory::Memcpy(jsonBuffer, parametersJson.c_str(), jsonSize);
    jsonBuffer[jsonSize] = '\0';
    std::string parametersJsonStd(jsonBuffer, jsonSize);
    FMemory::Free(jsonBuffer);
    
    std::map<std::string, std::vector<std::string>> parsedParams = json::parse(parametersJsonStd);

    // convert parsed params to SafeString
    for (const auto& pair : parsedParams) {
        std::vector<SafeString> safeValues;
        for (const auto& value : pair.second) {
            safeValues.push_back(SafeStringFromStdString(value));
        }
        this->parameters[SafeStringFromStdString(pair.first)] = safeValues;
    }
}

// https://stackoverflow.com/a/15372760/1498352
void Command::replace(SafeString &s, const SafeString &search, const SafeString &replace) {
    typedef SafeString::size_type size_type;
    const size_type npos = static_cast<size_type>(-1);
    for (size_type pos = 0; ; pos += replace.length()) {
        // locate the substring to replace
        pos = s.find(search, pos);
        if (pos == npos) break;
        // replace by erasing and inserting
        s.erase(pos, search.length());
        s.insert(pos, replace);
    }
}

std::vector<SafeString> Command::getParameters(SafeString parameterKey) {
    std::vector<SafeString> parameterValues = this->parameters[parameterKey];
    if (parameterValues.size() == 0) {
        return std::vector<SafeString>();
    }
    return parameterValues;
}

SafeString Command::getFirstParameterValue(SafeString parameterKey) {
    std::vector<SafeString> parameterValues = this->parameters[parameterKey];
    if (parameterValues.size() == 0) {
        return SafeString("");
    }
    return parameterValues[0];
}

bool Command::containsParameter(SafeString parameterKey) {
    return this->parameters.count(parameterKey) > 0;
}
