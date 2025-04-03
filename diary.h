#ifndef DIARY_H
#define DIARY_H

#include<iostream>
#include<map>

class Diary {
    private:
        std::map<std::string, std::string> Entity;
    public:
        int Number;
    public:
        int removeEntity(std::string date);
        void insertEntity(std::string date, std::string entity);
        void printContentList(std::string start, std::string end);
        void printContentOne(std::string date);
};

#endif