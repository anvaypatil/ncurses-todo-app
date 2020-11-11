
#ifndef APP_HELPER_FUNCTIONS_H
#define APP_HELPER_FUNCTIONS_H


#include <string>
#include <vector>

class HelperFunctions {
public:
    static std::vector<std::string> stringSplit(const std::string &str, const std::string &delimiter);
    static std::string addRightPad(char pad, uint width, std::string displayString);
    static std::string addLeftPad(char pad, uint width, std::string displayString);
    static std::string addSurroundPad(char pad, uint width, uint start, std::string displayString);
};


#endif //APP_HELPER_FUNCTIONS_H
