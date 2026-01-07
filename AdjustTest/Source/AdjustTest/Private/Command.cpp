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

Command::Command(std::string className, std::string methodName, std::string parametersJson) {
    this->className = className;
    this->methodName = methodName;

    // reason for changing [null] to []: https://github.com/nlohmann/json/issues/1163
    replace(parametersJson, std::string("[null]"), std::string("[\"\"]"));
    replace(parametersJson, std::string("[null,"), std::string("[\"\","));
    replace(parametersJson, std::string("null"), std::string("\"\""));
    replace(parametersJson, std::string("null,"), std::string("\"\","));
    
    std::map<std::string, std::vector<std::string>> parsedParams = json::parse(parametersJson);

    // store parsed params directly
    for (const auto& pair : parsedParams) {
        this->parameters[pair.first] = pair.second;
    }
}

// https://stackoverflow.com/a/15372760/1498352
void Command::replace(std::string &s, const std::string &search, const std::string &replace) {
    typedef std::string::size_type size_type;
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

std::vector<std::string> Command::getParameters(std::string parameterKey) {
    std::vector<std::string> parameterValues = this->parameters[parameterKey];
    if (parameterValues.size() == 0) {
        return std::vector<std::string>();
    }
    return parameterValues;
}

std::string Command::getFirstParameterValue(std::string parameterKey) {
    std::vector<std::string> parameterValues = this->parameters[parameterKey];
    if (parameterValues.size() == 0) {
        return std::string("");
    }
    return parameterValues[0];
}

bool Command::containsParameter(std::string parameterKey) {
    return this->parameters.count(parameterKey) > 0;
}
