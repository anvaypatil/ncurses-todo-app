//
// Created by newton on 11/8/20.
//

#ifndef MONITOR_CONFIG
#define MONITOR_CONFIG

#include <ncurses.h>

enum Interrupts {
    QUIT_APPLICATION = 'q',
    INSERT_TASK = 'i',
    DELETE_TASK = 'd',
    MOVE_UP = KEY_UP,
    MOVE_DOWN = KEY_DOWN,
    DEFAULT = '`'
};
#endif //MONITOR_CONFIG
