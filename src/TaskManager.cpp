//
// Created by newton on 11/9/20.
//

#include <iostream>
#include "TaskManager.h"
#include "WindowManager.h"

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
    inputWindow->addInputControl(COMPLETED, "Mark as Complete", "[Space Bar]");
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
    for (uint i = top; i < bottom; i++) {
        TextContent taskItem(windowPtr.get());
        std::string text = getFormattedText(dataList->taskAt(i));
        TextContent itemIndex(windowPtr.get());
        // colorize index;
        const auto index = itemIndex.atPosition(Position{1, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            index->withColor(Colors::MAGENTA)->withInvertedText();
        } else {
            index->withColor(Colors::WHITE);
        }
        // colorize text;
        index->putPlainText(std::to_string(i + 1));
        const auto item = taskItem.withColor(Colors::BLUE)
                ->atPosition(Position{3, uint(i - top)});
        if (dataList->getHighlightedIndex() == i) {
            item->withInvertedText();
        }
        item->putPlainText(text);
    }
}

std::string TaskManager::getFormattedText(TaskItem task) {
    char text[80];
    const auto width = windowPtr->getWidth() - 8;
    const std::string lmt = " %-" + std::to_string(width) + "s";
    sprintf(text, lmt.c_str(), task.getTask().c_str());
    return std::string(text);
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
