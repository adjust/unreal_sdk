//
//  Command.cpp
//  Adjust SDK
//
//  Created by Srdjan Tubin (@2beens) on 4th June 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#include "Command.h"
#include <iterator>

using json = nlohmann::json;

Command::Command(std::string className, std::string methodName, std::string parametersJson) {
    this->className = className;
    this->methodName = methodName;

    // reason for changing [null] to []: https://github.com/nlohmann/json/issues/1163
    replace(parametersJson, "[null]", "[\"\"]");
    replace(parametersJson, "[null,", "[\"\",");
    replace(parametersJson, "null", "\"\"");
    replace(parametersJson, "null,", "\"\",");
    std::map<std::string, std::vector<std::string>> parsedParams = json::parse(parametersJson);

    this->parameters = parsedParams;
}

// https://stackoverflow.com/a/15372760/1498352
void Command::replace(std::string &s, const std::string &search, const std::string &replace) {
    for (size_t pos = 0; ; pos += replace.length()) {
        // locate the substring to replace
        pos = s.find(search, pos);
        if (pos == std::string::npos) break;
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
        return "";
    }
    return parameterValues[0];
}

bool Command::containsParameter(std::string parameterKey) {
    return this->parameters.count(parameterKey) > 0;
}
