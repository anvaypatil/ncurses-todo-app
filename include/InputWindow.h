
#ifndef APP_INPUTWINDOW_H
#define APP_INPUTWINDOW_H


#include <memory>
#include <functional>
#include <map>
#include "Dimension.h"
#include "Window.h"
#include "TextContent.h"

class InputWindow {
public:
    InputWindow(Dimension dimension, const std::string windowName);
    void setInputString(std::string str);
    std::string getInputString();
    void putPromptAt(Position position);
    void addInputControl(int controlChar, std::string description, std::string controlText);
    std::shared_ptr<Window> &getWindow();
    int getPromptControl();
    void onChangeHandler(void (*handler)(std::string));
    void displayPromptMenu() const;
private:
    std::string windowName = "";
    std::string inputString = "";
    std::shared_ptr<Window> inputWindow;
    // lambda to hold the handler so to trigger when we input is changed
    std::function<void(std::string)> changeHandler;
    void inputPrompt(Position position);
    std::map<int, std::pair<std::string, std::string>> controls;
    std::pair<uint, uint> maxLengths = std::pair(0, 0);
};

class ControlItems {
public:
private:
    std::vector<std::string> controlList;
};

class ControlItem {
private:
    std::string control;
};

#endif //APP_INPUTWINDOW_H
