//
// Created by ap on 10/11/20.
//

#include "TaskItem.h"
#include "AppConfig.h"
#include <regex>

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
    std::vector<std::string> out(
            std::sregex_token_iterator(stream.begin(), stream.end(), DELIMITER_REGEX, -1),
            std::sregex_token_iterator()
    );
    TaskItem taskItem(out.at(0));
    if(out.at(2)==std::to_string('c')){
        taskItem.toggleComplete();
    }
    return taskItem;
}

std::string TaskItemSerializer::serialize(TaskItem object) {
    std::string serialStr = object.getTask()+DELIMITER+(object.isComplete()?'c':'n');
    return serialStr;
}
