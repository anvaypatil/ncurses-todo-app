//
// Created by newton on 11/4/20.
//

#include "DataList.h"


DataList::DataList() {
    items = std::make_unique<std::vector<TaskItem>>();
}

DataList::~DataList() {

}

void DataList::addTask(std::string string) {
    items->push_back(std::string(string));
}

TaskItem DataList::taskAt(size_t position) {
    return items->at(position);
}

void DataList::deleteTask(const size_t index) {
    items->erase(items->begin() + index);
}

size_t DataList::size() {
    return items->size();
}

void DataList::setHighlighted(uint index) {
    if (index < items->size()) {
        this->highlightedIndex = index;
    }
}

uint DataList::getHighlightedIndex() {
    return highlightedIndex;
}

void DataList::clear() {
    items->clear();
}
