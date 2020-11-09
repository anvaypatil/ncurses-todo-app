//
// Created by newton on 11/4/20.
//

#include "DataList.h"

TaskItem::TaskItem(const std::string &task) : task(task) {}

std::string TaskItem::getTask() {
    return std::string(task);
}

DataList::DataList() {
    items = std::make_unique<std::vector<TaskItem>>();
}

DataList::~DataList() {

}

void DataList::addTask(std::string string) {
    items->insert(items->begin()+highlightedIndex, TaskItem{std::string(string)});
    this->highlightedIndex = items->size() - 1;
}

void DataList::deleteTask(const size_t index) {
    items->erase(items->begin() + index);
}

size_t DataList::size() {
    return items->size();
}

std::string DataList::taskAt(size_t position) {
    auto taskItem = items->at(position);
    return taskItem.getTask();
}

void DataList::setHighlighted(uint index) {
    if (index < items->size()) {
        this->highlightedIndex = index;
    }
}

uint DataList::getHighlightedIndex() {
    return highlightedIndex;
}
