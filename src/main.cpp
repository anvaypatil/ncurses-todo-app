#include <WindowManager.h>
#include <TaskManager.h>
#include <iostream>

using namespace std;

int main() {
    WindowManager::initializeScreen();
    TaskManager taskManager;
    taskManager.manageTasks();
    WindowManager::terminateScreen();
    return 0;
}
