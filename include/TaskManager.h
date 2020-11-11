
#ifndef APP_TASK_MANAGER_H
#define APP_TASK_MANAGER_H


#include <memory>
#include "Window.h"
#include "InputWindow.h"
#include "DataList.h"
#include "TaskItem.h"
#include "TaskPersistence.h"

class TaskManager {
public:
    TaskManager();
    void manageTasks();
private:
    void addPromptControls();
    void taskLoop();
    void addTask();
    void deleteTask();
    void toggleCompleteTask();
    void moveUp();
    void moveDown();
    std::shared_ptr<Window> windowPtr;
    std::shared_ptr<InputWindow> inputWindow;
    std::shared_ptr<DataList> dataList;
    void displayTasks();
    uint top, bottom;

    bool checkOutOfBound();
    std::unique_ptr<TaskPersistence> taskPersistence;

    void initDataListForDisplay();

    void refreshDisplayList();
};


#endif //APP_TASK_MANAGER_H
