//
// Created by newton on 11/9/20.
//

#include <iostream>
#include "TaskManager.h"
#include "WindowManager.h"

void TaskManager::addPromptControls() {
    inputWindow->addInputControl(QUIT_APPLICATION, "Quit Application","[q]");
    inputWindow->addInputControl(INSERT_TASK, "Insert Task","[i]");
    inputWindow->addInputControl(DELETE_TASK, "Delete Task","[d]");
    inputWindow->addInputControl(MOVE_DOWN, "Navigate Down","[Down Arrow]");
    inputWindow->addInputControl(MOVE_UP, "Navigate Up","[Up Arrow]");
    WindowManager::repaintWindows();
}

TaskManager::TaskManager() {
    windowPtr = std::make_shared<Window>(
            Dimension{1, 1, 80, 20},
            std::string("Todo List")
    );
    inputWindow = std::make_shared<InputWindow>(
            Dimension{1, 25, 80, 8},
            "Control Pane"
    );
    dataList = std::make_shared<DataList>();
    WindowManager::registerWindow(windowPtr);
    WindowManager::registerWindow(inputWindow->getWindow());
}

void TaskManager::manageTasks() {
    addPromptControls();
    taskLoop();
}

void TaskManager::taskLoop() {
    std::shared_ptr<std::vector<TextContent>> textList = std::make_shared<std::vector<TextContent>>();
    while (true) {
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
        displayTasks(textList);
        WindowManager::repaintWindows();
    }
}

void TaskManager::displayTasks(std::shared_ptr<std::vector<TextContent>> &textList) {
    for (uint i = 0; i < dataList->size(); i++) {
        char t[80];
        TextContent textItem(windowPtr.get());
        const auto width = windowPtr->getWidth()-2;
        const std::string lmt = " %-" + std::to_string(width) + "s";
        sprintf(t, lmt.c_str(), dataList->taskAt(i).c_str());
        TextContent itemIndex(windowPtr.get());
        itemIndex.withColor(Colors::YELLOW)
                ->atPosition(Position{1, uint(i)})
                ->putPlainText(std::to_string(i+1));
        const auto item = textItem.withColor(Colors::BLUE)
                ->atPosition(Position{3, uint(i)});
        if (dataList->getHighlightedIndex() == i) {
            item->withInvertedText();
        }
        item->putPlainText(t);
        textList->push_back(textItem);
    }
}

void TaskManager::addTask() {
    inputWindow->putPromptAt(Position{0, 0});
    dataList->addTask(inputWindow->getInputString());
    dataList->setHighlighted(0);
}

void TaskManager::moveUp() {
    const uint index = dataList->getHighlightedIndex();
    const uint newIndex = (index == 0) ? dataList->size() - 1 : index - 1;
    dataList->setHighlighted(newIndex);
}

void TaskManager::moveDown() {
    const uint index = dataList->getHighlightedIndex();
    const uint newIndex = (dataList->size() == (index + 1)) ? 0 : index + 1;
    dataList->setHighlighted(newIndex);
}

void TaskManager::deleteTask() {
    if (dataList->size() != 0) {
        const uint index = dataList->getHighlightedIndex();
        dataList->deleteTask(index);
        dataList->setHighlighted((index != 0) ? (index - 1) : 0);
    }
}
