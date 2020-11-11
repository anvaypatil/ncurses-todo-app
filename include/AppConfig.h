//
// Created by newton on 11/8/20.
//

#ifndef MONITOR_CONFIG
#define MONITOR_CONFIG

#include <ncurses.h>
#include <regex>
#include <sys/stat.h>
#include <fstream>
#include <stdlib.h>
enum Interrupts {
    QUIT_APPLICATION = 'q',
    INSERT_TASK = 'i',
    DELETE_TASK = 'd',
    MOVE_UP = KEY_UP,
    MOVE_DOWN = KEY_DOWN,
    TOGGLE_TASK_COMPLETE = ' ',
    DEFAULT = '`'
};

const std::string DELIMITER = "$%$%$";
const std::regex DELIMITER_REGEX ("\\" + DELIMITER+"\\g");
const std::string saveDirectory= ".todolist";
const std::string fileName="todolist.txt";
const std::string saveDirectoryPath =
        std::string(getenv("HOME"))+"/"+saveDirectory;

const std::string saveFilePath = saveDirectoryPath+"/"+fileName;

#endif //MONITOR_CONFIG
