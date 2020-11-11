//
// Created by ap on 11/11/20.
//

#include <iomanip>
#include "HelperFunctions.h"

std::vector<std::string> HelperFunctions::stringSplit(const std::string &str, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delimiter, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delimiter.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}


std::string HelperFunctions::addRightPad(char pad, uint width, std::string displayString) {
    std::stringstream sstr;
    sstr << std::right << std::setfill(pad) << std::setw(width) << displayString;
    return sstr.str();
}

std::string HelperFunctions::addLeftPad(char pad, uint width, std::string displayString) {
    std::stringstream sstr;
    sstr << std::left << std::setfill(pad) << std::setw(width) << displayString;
    return sstr.str();
}

std::string HelperFunctions::addSurroundPad(char pad, uint width, uint start, std::string displayString) {
    std::stringstream sstr;
    sstr << std::right << std::setfill(pad) << std::setw(start - 1) << ""
         << std::left << std::setfill(pad) << std::setw(width - start) << displayString;
    return sstr.str();
}