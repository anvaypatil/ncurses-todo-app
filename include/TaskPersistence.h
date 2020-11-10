//
// Created by newton on 11/10/20.
//

#ifndef MONITOR_TASK_PERSISTENCE_H
#define MONITOR_TASK_PERSISTENCE_H


#include <memory>
#include "DataList.h"

class TaskPersistence {
public:
    TaskPersistence(std::shared_ptr<DataList> dataList);
    void save();
    void load();
private:
    std::shared_ptr<DataList> dataList;
};


#endif //MONITOR_TASK_PERSISTENCE_H
