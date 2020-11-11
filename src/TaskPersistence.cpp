
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
    if (todoFile.good()){
        TaskItemSerializer serializer;
        for (uint i = 0; i < dataList->size() ; ++i) {
            todoFile << serializer.serialize(dataList->taskAt(i)) <<"\n";
        }
        todoFile.close();
    }
}

void TaskPersistence::load() {
   if(fileExists()){
       std::ifstream todoFile(saveFilePath);
       if (todoFile.good()){
           dataList->clear();
           TaskItemSerializer serializer;
           for (std::string stream = ""; getline(todoFile, stream); ){
               dataList->addTask(serializer.deserialize(stream));
           }
       }
   }
}

// https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
bool TaskPersistence::fileExists() {
    struct stat buffer;
    return (stat (saveFilePath.c_str(), &buffer) == 0);
}
