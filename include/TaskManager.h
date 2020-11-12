
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
    bool checkOutOfBound();
    void displayTasks();
    void initDataListForDisplay();
    void refreshDisplayList();

    std::shared_ptr<Window> windowPtr;
    std::shared_ptr<InputWindow> inputWindow;
    std::shared_ptr<DataList> dataList;
    uint top, bottom;
    std::unique_ptr<TaskPersistence> taskPersistence;
};


#endif //APP_TASK_MANAGER_H
