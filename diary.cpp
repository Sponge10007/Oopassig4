#include "diary.h"
#include<map>
#include<iostream>

void Diary::insertEntity(std::string date, std::string entity) {
    //map可以通过直接赋值法来新增元素
    Entity[date] = entity;
}

int Diary::removeEntity(std::string date) {
    //首先判断是否存在该天的日记
    if(!Entity.count(date)) {
        std::cout << "There is no diary in that day\n";
        return -1;
    }
    int Temp = Entity.erase(date);
    //erase函数会返回根据key删除元素的个数
    if(!Temp) {
        std::cout << "Error exits in remove operation\n";
        return -1;
    } //如果删除了0个元素，说明没删除，删除操作失败了
    std::cout << "Remove success!\n";
    return 0;
}

void Diary::printContentList(std::string start, std::string end) {
    // 用迭代器来迭代map中的元素
    for(Index::iterator iter = Entity.begin(); iter != Entity.end(); iter++) {
        if(iter->first < start) continue;
        if(iter->first > end) break; // 因为map容器中会根据key的顺序来排列元素，所以我们可以顺序查找
        std::cout << "----" << iter->first << ":\n" << iter->second << "\n";
    }
}

void Diary::printContentOne(std::string date) {
    if(!Entity.count(date)) {
        std::cout << "There is no diary in that day\n";
        return;
    }
    std::cout << "----" << date << ":\n" << Entity[date] << "\n";
}

void Diary::printContentAll() {
    for(Index::iterator iter = Entity.begin(); iter != Entity.end(); iter++) {
        std::cout << "----" << iter->first << ":\n" << iter->second << "\n";
    }
}