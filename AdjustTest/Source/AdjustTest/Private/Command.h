//
//  Command.h
//  Adjust SDK
//
//  Created by Srdjan Tubin (@2beens) on 4th June 2018.
//  Copyright © 2018-Present Adjust GmbH. All rights reserved.
//

#pragma once

#include <map>
#include <string>
#include <vector>
#include "json/json.hpp"
#include "TestLib.h"

class Command {
private:
	void replace(SafeString &s, const SafeString &search, const SafeString &replace);
public:
	SafeString className;
	SafeString methodName;
	std::map<SafeString, std::vector<SafeString>> parameters;

	Command(SafeString className, SafeString methodName, SafeString parametersJson);

	std::vector<SafeString> getParameters(SafeString parameterKey);
	SafeString getFirstParameterValue(SafeString parameterKey);
	bool containsParameter(SafeString parameterKey);
};
