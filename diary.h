#ifndef DIARY_H
#define DIARY_H

#include<iostream>
#include<map>

typedef std::map<std::string, std::string> Index; //方便起见，重定义字符到字符的map类型

class Diary {
    private:
        Index Entity;
    public:
        int Number;
    public:
        int removeEntity(std::string date);
        void insertEntity(std::string date, std::string entity);
        void printContentList(std::string start, std::string end);
        void printContentOne(std::string date);
};

#endif