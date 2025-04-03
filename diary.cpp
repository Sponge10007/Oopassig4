#include "diary.h"
#include<map>
#include<iostream>

void Diary::insertEntity(std::string date, std::string entity) {
    Entity[date] = entity;
}

int Diary::removeEntity(std::string date) {
    if(!Entity.count(date)) {
        std::cout << "There is no diary in that day\n";
        return -1;
    }
    int Temp = Entity.erase(date);
    if(!Temp) {
        std::cout << "Error exits in remove operation\n";
        return -1;
    }
    std::cout << "Remove success!\n";
    return 0;
}

void Diary::printContentList(std::string start, std::string end) {
    auto Temp = Entity.find(start);
    for(const auto)
}