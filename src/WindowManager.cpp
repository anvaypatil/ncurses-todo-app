//
// Created by newton on 11/3/20.
//

#include "WindowManager.h"
#include <ncurses.h>
#include <iostream>

void WindowManager::initializeScreen() {
    std::cout << "\033]0;" << "todo" << "\7" << std::flush;
    initscr();
    raw();

    use_default_colors();
    if (has_colors()){
        start_color();
        ColorManager::initializeColors();
    }
    mouseinterval(0);
    keypad(stdscr, true);
    noecho();

    clear();
    refresh();
    curs_set(0);
}

void WindowManager::registerWindow(std::shared_ptr<Window> &window) {
    windows.push_back(window);
}

void WindowManager::repaintWindows() {
 for (auto &win: windows){
     win->draw();
 }
}

void WindowManager::terminateScreen() {
    // all the windows will out of scope since under shared ptr,
    // they will get destructed automatically
    endwin();
    curs_set(1);
}

void WindowManager::repaintWindow(std::shared_ptr<Window> &window) {
    window->draw();
}
