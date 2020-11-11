//
// Created by ap on 10/11/20.
//

#ifndef MONITOR_TASKITEM_H
#define MONITOR_TASKITEM_H


#include <string>
#include <iostream>
#include "Serializable.h"

class TaskItem{
public:
    TaskItem(const std::string &task);
    bool isComplete();
    void toggleComplete();
    std::string getTask();
    std::string taskDisplayText(uint width);
    std::string taskCompletedText(uint width);
    // Copy constructor
    TaskItem(const TaskItem &other) {
        copyContent(other);
    }
    // Copy assignment
    TaskItem &operator=(const TaskItem &other) {
        if (this != &other) {
            copyContent(other);
        }
        return *this;
    }
    // Move assignment
    TaskItem &operator=(TaskItem &&other){
        if (this != &other) {
            moveContent(other);
        }
        return *this;
    }
    // Move Constructor
    TaskItem(TaskItem &&other){
        moveContent(other);
    }
private:
    std::string task;
    bool complete = false;
    void copyContent(const TaskItem &other) {
        task = std::string(other.task);
        complete = other.complete;
    }

    void moveContent(const TaskItem &other) {
        task = std::move(other.task);
        complete = std::move(other.complete);
    }
};
#endif //MONITOR_TASKITEM_H


#ifndef TASK_SERIALIZER_H
#define TASK_SERIALIZER_H

class TaskItemSerializer: Serializable<TaskItem> {
public:
    TaskItem deserialize(std::string stream) override;
    std::string serialize(TaskItem object) override;
};


#endif //TASK_SERIALIZER_H
