//
// Created by ap on 10/11/20.
//

#include "TaskItem.h"
#include "AppConfig.h"
#include <regex>
#include <iostream>
#include <HelperFunctions.h>

TaskItem::TaskItem(const std::string &task) : task(task) {}

std::string TaskItem::getTask() {
    return std::string(task);
}

void TaskItem::toggleComplete() {
    complete = !complete;
}

bool TaskItem::isComplete() {
    return complete;
}

TaskItem TaskItemSerializer::deserialize(std::string stream) {
    std::vector<std::string> out = HelperFunctions::stringSplit(stream, DELIMITER);
    if (out.size() == 2) {
        TaskItem taskItem(out.at(0));
        if (out.at(1) == std::to_string('c')) {
            taskItem.toggleComplete();
        }
        return taskItem;
    }
    return TaskItem(stream);
}

std::string TaskItemSerializer::serialize(TaskItem object) {
    std::string serialStr = object.getTask() + DELIMITER + (object.isComplete() ? 'c' : 'n');
    return serialStr;
}
