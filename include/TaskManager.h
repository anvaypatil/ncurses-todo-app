//
// Created by newton on 11/9/20.
//

#ifndef MONITOR_TASKMANAGER_H
#define MONITOR_TASKMANAGER_H


#include <memory>
#include "Window.h"
#include "InputWindow.h"
#include "DataList.h"

class TaskManager {
public:
    TaskManager();
    void manageTasks();
private:
    void addPromptControls();
    void taskLoop();
    void addTask();
    void deleteTask();
    void moveUp();
    void moveDown();
    std::shared_ptr<Window> windowPtr;
    std::shared_ptr<InputWindow> inputWindow;
    std::shared_ptr<DataList> dataList;
    void displayTasks(std::shared_ptr<std::vector<TextContent>> &textList);
    uint top, bottom;

    bool checkOutOfBound();
};


#endif //MONITOR_TASKMANAGER_H
