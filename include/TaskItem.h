
#ifndef APP_TASKITEM_H
#define APP_TASKITEM_H


#include <string>
#include <iostream>
#include "Serializable.h"

class TaskItem{
public:
    TaskItem(const std::string &task);
    TaskItem(const std::string &task, bool taskComplete);
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
    std::string taskDetails;
    bool complete = false;
    void copyContent(const TaskItem &other) {
        taskDetails = std::string(other.taskDetails);
        complete = other.complete;
    }

    void moveContent(const TaskItem &other) {
        taskDetails = std::move(other.taskDetails);
        complete = std::move(other.complete);
    }
};
#endif //APP_TASKITEM_H


#ifndef TASK_SERIALIZER_H
#define TASK_SERIALIZER_H

class TaskItemSerializer: Serializable<TaskItem> {
public:
    TaskItem deserialize(std::string stream) override;
    std::string serialize(TaskItem object) override;
};


#endif //TASK_SERIALIZER_H
