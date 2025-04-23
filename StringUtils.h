#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#pragma once
class StringUtils
{
public:
    static std::string trim(const std::string& str) {
        auto start = str.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        auto end = str.find_last_not_of(" \t\n\r");
        return str.substr(start, end - start + 1);
    }

    static std::string removeHashTag(const std::string& str) {
        std::string result = trim(str);
        if (!result.empty() && result[0] == '#') {
            result.erase(0, 1);
        }
        return trim(result);
    }

    static std::string toLower(const std::string& str) {
        std::string lowerStr;
        for (char c : str) {
            lowerStr += tolower(c);
        }
        return lowerStr;
    }

    static std::vector<std::string> splitString(const std::string& input, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(input);
        while (std::getline(tokenStream, token, delimiter)) {
            token = trim(token);
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }
};