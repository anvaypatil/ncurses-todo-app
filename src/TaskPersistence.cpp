//
// Created by newton on 11/10/20.
//

#include <sys/stat.h>
#include <iostream>
#include "TaskItem.h"
#include "AppConfig.h"
#include "TaskPersistence.h"

TaskPersistence::TaskPersistence(std::shared_ptr<DataList> list):dataList(list) {

}

void TaskPersistence::save() {
    // based on https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
    mkdir(saveDirectoryPath.c_str(), S_IRWXG | S_IXOTH |S_IRWXU | S_IROTH);
    std::ofstream todoFile(saveFilePath);
    if (!todoFile.good()){
        std::cout<<""<<std::endl;
        return;
    }
    TaskItemSerializer serializer;
    for (uint i = 0; i < dataList->size() ; ++i) {
        todoFile << serializer.serialize(dataList->taskAt(i)) <<"\n";
    }
    todoFile.close();
}

void TaskPersistence::load() {

}
