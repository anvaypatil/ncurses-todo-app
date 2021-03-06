
#ifndef APP_DATA_LIST_H
#define APP_DATA_LIST_H

#include <string>
#include <vector>
#include <memory>
#include "Serializable.h"
#include "TaskItem.h"

class DataList {
public:
    DataList();
    ~DataList();
    void addTask(std::string &string);
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


#endif //APP_DATA_LIST_H
