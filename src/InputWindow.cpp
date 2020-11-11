//
// Created by newton on 11/4/20.
//

#include <iostream>
#include "InputWindow.h"

InputWindow::InputWindow(Dimension dimension, const std::string windowName) {
    this->windowName = std::string(windowName);
    this->inputWindow = std::make_unique<Window>(dimension, std::string(windowName));
}

void InputWindow::setInputString(std::string str) {
    inputString = str;
}

std::string InputWindow::getInputString() {
    return inputString;
}

void InputWindow::onChangeHandler(void (*handler)(std::string)) {
    changeHandler = handler;
}

void InputWindow::putPromptAt(Position position) {
    this->inputPrompt(position);
}

void InputWindow::inputPrompt(Position position) {
    char str[1000] = "";
    int ch;
    bool isStillTyping = true;
    curs_set(2);
    int pos = 0;
    TextContent input(inputWindow.get());
    while (isStillTyping) {
        inputWindow->erase();
        input.atPosition(position)->putPlainText(std::string(str));
        inputWindow->draw();
        ch = getch();
        switch (ch) {
            case '\n':
                isStillTyping = false;
                break;
            case KEY_BACKSPACE:
                if (pos)
                    pos--;
                str[pos] = 0;
                break;
            default:
                str[pos] = (char) ch;
                if (pos < 180)
                    pos++;
                break;
        }
    }
    curs_set(0);
    inputString = std::string(str);
}

std::shared_ptr<Window> &InputWindow::getWindow() {
    return inputWindow;
}

void InputWindow::addInputControl(int controlChar, std::string description, std::string controlText) {
    controls[controlChar] = std::pair(description, controlText);
    if (maxLengths.first < description.length()) {
        maxLengths.first = description.length();
    }
    if (maxLengths.second < controlText.length()) {
        maxLengths.second = controlText.length();
    }
}

int InputWindow::getPromptControl() {
    displayPromptMenu();
    int ch;
    while (true) {
        ch = getch();
        if (controls.find(ch) != controls.end()) {
            if (33 < ch && ch < 126) {
                inputWindow->setWindowName(controls[ch].first);
            }
            break;
        }
    }
    return ch;
}

void InputWindow::displayPromptMenu() const {
    inputWindow->setWindowName(windowName);
    int i = 0;
    char ch[80];
    std::string lmt = "";
    for (auto const&[key, value] : controls) {
        lmt = " %-" + std::to_string(maxLengths.second) + "s";
        sprintf(ch, lmt.c_str(), value.second.c_str());
        TextContent textContent(inputWindow.get());
        textContent.atPosition({0, uint(i++)})
                ->putPlainText(std::string(ch) + "   " + value.first);
    }
    inputWindow->refreshDisplay();
}
