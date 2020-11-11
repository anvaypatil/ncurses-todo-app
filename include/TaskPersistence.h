
#ifndef APP_TASK_PERSISTENCE_H
#define APP_TASK_PERSISTENCE_H


#include <memory>
#include "DataList.h"

class TaskPersistence {
public:
    TaskPersistence(std::shared_ptr<DataList> dataList);
    void save();
    void load();
private:
    bool fileExists();
    std::shared_ptr<DataList> dataList;
};


#endif //APP_TASK_PERSISTENCE_H
