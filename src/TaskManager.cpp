//
// Created by newton on 11/9/20.
//

#include <iostream>
#include "TaskManager.h"
#include "WindowManager.h"
#include "HelperFunctions.h"

TaskManager::TaskManager() {
    windowPtr = std::make_shared<Window>(
            Dimension{1, 1, 80, 20},
            std::string("Todo List")
    );
    inputWindow = std::make_shared<InputWindow>(
            Dimension{1, 22, 80, 8},
            "Control Pane"
    );
    dataList = std::make_shared<DataList>();
    WindowManager::registerWindow(windowPtr);
    WindowManager::registerWindow(inputWindow->getWindow());
    taskPersistence = std::make_unique<TaskPersistence>(dataList);
}

void TaskManager::addPromptControls() {
    inputWindow->addInputControl(QUIT_APPLICATION, "Quit Application", "[q]");
    inputWindow->addInputControl(INSERT_TASK, "Insert Task", "[i]");
    inputWindow->addInputControl(DELETE_TASK, "Delete Task", "[d]");
    inputWindow->addInputControl(MOVE_DOWN, "Navigate Down", "[Down Arrow]");
    inputWindow->addInputControl(MOVE_UP, "Navigate Up", "[Up Arrow]");
    inputWindow->addInputControl(TOGGLE_TASK_COMPLETE, "Mark as Complete", "[Space Bar]");
    WindowManager::repaintWindows();
}

void TaskManager::manageTasks() {
    taskPersistence->load();
    initDataListForDisplay();
    addPromptControls();
    taskLoop();
}

void TaskManager::initDataListForDisplay() {
    top = 0;
    bottom = (dataList->size() > windowPtr->getHeight() - 2) ? windowPtr->getHeight() - 2 : dataList->size();
    dataList->setHighlighted(0);
}

void TaskManager::taskLoop() {
    while (true) {
        refreshDisplayList();
        int control = inputWindow->getPromptControl();
        if (control == QUIT_APPLICATION) {
            break;
        }
        switch (control) {
            case INSERT_TASK:
                addTask();
                break;
            case MOVE_UP:
                moveUp();
                break;
            case MOVE_DOWN:
                moveDown();
                break;
            case DELETE_TASK:
                deleteTask();
                break;
            case TOGGLE_TASK_COMPLETE:
                toggleCompleteTask();
                break;
            default:
                break;
        }
    }
}

void TaskManager::refreshDisplayList() {
    displayTasks();
    WindowManager::repaintWindows();
}

void TaskManager::displayTasks() {
    windowPtr->setWindowName("Todo's:(" + std::to_string(dataList->size()) + ")");
    uint paneWidth = windowPtr->getWidth();
    for (uint i = top; i < bottom; i++) {
        TextContent taskText(windowPtr.get());
        TaskItem task = dataList->taskAt(i);
        TextContent itemIndex(windowPtr.get());
        // colorize index;
        const auto indexColumn = itemIndex.atPosition(Position{1, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            indexColumn->withColor(Colors::MAGENTA);
        } else {
            indexColumn->withColor(Colors::WHITE);
        }
        const std::string indexText = HelperFunctions::addSurroundPad(' ', 3, 1, std::to_string(i + 1));
        indexColumn->putPlainText(indexText);

        const auto taskColumn = taskText.withColor(Colors::BLUE)
                ->atPosition(Position{3, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            taskColumn->withInvertedText();
        }
        taskColumn->putPlainText(task.taskDisplayText(paneWidth - 8));

        const auto completedColumn = taskText.atPosition(Position{paneWidth - 8, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            if (task.isComplete()) {
                completedColumn->withColor(Colors::RED)->withInvertedText();
            } else {
                completedColumn->withColor(Colors::BLUE)->withInvertedText();
            }
        } else {
            if (task.isComplete()) {
                completedColumn->withColor(Colors::RED);
            } else {
                completedColumn->withColor(Colors::YELLOW);
            }
        }
        completedColumn->putPlainText(task.taskCompletedText(3));

        const auto paddingRight = taskText.withColor(Colors::BLUE)
                ->atPosition(Position{paneWidth - 5, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            paddingRight->withInvertedText();
        }
        paddingRight->putPlainText("  ");
    }
}


void TaskManager::addTask() {
    inputWindow->putPromptAt(Position{0, 0});
    dataList->addTask(inputWindow->getInputString());
    dataList->setHighlighted(dataList->size() - 1);
    if (checkOutOfBound()) {
        bottom = dataList->size();
        top = dataList->size() - (windowPtr->getHeight() - 2);
    } else {
        top = 0;
        bottom = dataList->size();
    }
    taskPersistence->save();
}

bool TaskManager::checkOutOfBound() { return dataList->size() > windowPtr->getHeight() - 2; }

void TaskManager::toggleCompleteTask() {
    if (dataList->size() != 0) {
        const uint index = dataList->getHighlightedIndex();
        dataList->taskAt(index).toggleComplete();
        taskPersistence->save();
    }
}

void TaskManager::moveUp() {
    const uint index = dataList->getHighlightedIndex();
    const uint newIndex = (index == 0) ? 0 : index - 1;
    dataList->setHighlighted(newIndex);
    if (checkOutOfBound() && index == top) {
        top = (top == 0) ? 0 : top - 1;
        bottom = top + windowPtr->getHeight() - 2;
    }
}

void TaskManager::moveDown() {
    const uint index = dataList->getHighlightedIndex();
    const uint newIndex = (dataList->size() == (index + 1)) ? index : index + 1;
    dataList->setHighlighted(newIndex);
    if (checkOutOfBound() && index == (bottom - 1)) {
        bottom = (dataList->size() == (bottom)) ? bottom : bottom + 1;
        top = bottom - (windowPtr->getHeight() - 2);
    }
}

void TaskManager::deleteTask() {
    if (dataList->size() != 0) {
        const uint index = dataList->getHighlightedIndex();
        dataList->deleteTask(index);
        if (dataList->size() != 0) {
            dataList->setHighlighted(index - 1);
        }
        if (checkOutOfBound()) {
            top = 0;
            bottom = windowPtr->getHeight() - 2;
        } else {
            top = 0;
            bottom = (dataList->size() != 0) ? dataList->size() : 0;
        }
    }
    taskPersistence->save();
}
