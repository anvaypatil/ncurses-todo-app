//
// Created by newton on 10/31/20.
//

#include "Window.h"
#include <memory>
#include <iostream>

Window::Window(Dimension dimension, const std::string windowName) {
    x = dimension.x;
    y = dimension.y;
    width = dimension.width;
    height = dimension.height;
    this->windowName = windowName;
    borderWindow = newwin(height, width, y, x);
    innerWindow = newwin(height - 2, width - 2, y + 1, x + 1);
}

Window::~Window() {
    delwin(borderWindow);
    delwin(innerWindow);
}

WINDOW *Window::getFrameWindow() {
    return innerWindow;
}

void Window::erase() {
    werase(borderWindow);
    werase(innerWindow);
}

void Window::draw() {
    box(borderWindow, 0, 0);
    mvwprintw(borderWindow, 0, 2, std::string("[" + windowName + "]").c_str());
    wrefresh(borderWindow);
    wrefresh(innerWindow);
}

void Window::moveTo(Position position) {
    wmove(innerWindow, position.y, position.x);
}

// Copy Constructor
Window::Window(const Window &other) {
    copyContent(other);
}

//copy assignment
Window &Window::operator=(const Window &other) {
    if (this != &other) {
        copyContent(other);
    }
    return *this;
}
// Move Constructor
Window &Window::operator=(Window &&other) {
    if (this != &other) {
        moveContent(other);
    }
    return *this;
}
// Move Assignment
Window::Window(Window &&other) {
    moveContent(other);
}

void Window::copyContent(const Window &other) {
    windowName = std::string(other.windowName);
    borderWindow = newwin(other.height, other.width, other.y, other.x);
    innerWindow = newwin(other.height - 2, other.width - 2, other.y + 1, other.x + 1);
}

void Window::moveContent(const Window &other) {
    innerWindow = std::move(other.innerWindow);
    borderWindow = std::move(other.borderWindow);
    windowName = std::move(other.windowName);
}

uint Window::getWidth() {
    return this->width;
}

uint Window::getHeight() {
    return this->height;
}

void Window::setWindowName(std::string name) {
    windowName = name;
    mvwprintw(borderWindow, 0, 2, std::string("[" + windowName + "]").c_str());
    refreshDisplay();
}

void Window::refreshDisplay() const {
    wrefresh(innerWindow);
    wrefresh(borderWindow);
}


