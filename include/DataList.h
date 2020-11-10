//
// Created by newton on 11/4/20.
//

#ifndef MONITOR_DATALIST_H
#define MONITOR_DATALIST_H

#include <string>
#include <vector>
#include <memory>
#include "Serializable.h"

class TaskItem{
public:
    TaskItem(const std::string &task);
    std::string getTask();
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
    void copyContent(const TaskItem &other) {
       task = std::string(other.task);
    }

    void moveContent(const TaskItem &other) {
        task = std::move(other.task);
    }
};

class DataList {
public:
    DataList();
    ~DataList();
    void addTask(std::string string);
    void deleteTask(const size_t index);
    std::string taskAt(size_t position);
    size_t size();
    void setHighlighted(uint index);
    uint getHighlightedIndex();
private:
    std::unique_ptr<std::vector<TaskItem>> items;
    uint highlightedIndex = -1;
};


#endif //MONITOR_DATALIST_H
