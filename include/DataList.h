//
// Created by newton on 11/4/20.
//

#ifndef MONITOR_DATALIST_H
#define MONITOR_DATALIST_H

#include <string>
#include <vector>
#include <memory>
#include "Serializable.h"
#include "TaskItem.h"

class DataList {
public:
    DataList();
    ~DataList();
    void addTask(std::string string);
    void addTask(TaskItem item);
    void deleteTask(const size_t index);
    TaskItem &taskAt(size_t position);
    size_t size();
    void clear();
    void setHighlighted(uint index);
    uint getHighlightedIndex();
private:
    std::unique_ptr<std::vector<TaskItem>> items;
    uint highlightedIndex = -1;
};


#endif //MONITOR_DATALIST_H
