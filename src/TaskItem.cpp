

#include "TaskItem.h"
#include "AppConfig.h"
#include <regex>
#include <iostream>
#include <HelperFunctions.h>

TaskItem::TaskItem(const std::string &taskDetails) : taskDetails(taskDetails) {}

TaskItem::TaskItem(const std::string &task, bool taskComplete): taskDetails(task), complete(taskComplete) {

}

std::string TaskItem::getTask() {
    return std::string(taskDetails);
}

void TaskItem::toggleComplete() {
    this->complete = (complete == true) ? false : true;
}

bool TaskItem::isComplete() {
    return complete;
}

std::string TaskItem::taskDisplayText(uint width) {
    return HelperFunctions::addSurroundPad(' ', width, 2, getTask());
}

std::string TaskItem::taskCompletedText(uint width) {
    if (isComplete()) {
        return HelperFunctions::addSurroundPad(' ', width, 1, "[x]");
    } else {
        return HelperFunctions::addSurroundPad(' ', width, 1, "[ ]");
    }
}

TaskItem TaskItemSerializer::deserialize(std::string stream) {
    std::vector<std::string> out = HelperFunctions::stringSplit(stream, DELIMITER);
    if (out.size() == 2) {
        TaskItem taskItem(
                out.at(0),
                std::string("c").compare(out.at(1)) == 0
        );
        return taskItem;
    }
    return TaskItem(stream);
}

std::string TaskItemSerializer::serialize(TaskItem object) {
    std::string serialStr = object.getTask() + DELIMITER + (object.isComplete() ? "c" : "n");
    return serialStr;
}
