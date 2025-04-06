#include "diary.h"
#include<iostream>
#include<sstream>
#include<map>

class User {
    private:
        std::string inst;
        Diary db;
    public:
        // the function to read in the entity and write into the diary
        void parseCommand() {
            std::istringstream is(inst);
            std::string cmd, date;
            is >> cmd >> date;  //使用字符串流截取命令和日期
            if(cmd == "pdadd") addOp(cmd, date);
            else if(cmd == "pdlist") listOp(cmd);
            else if(cmd == "pdshow") showOp(cmd, date);
            else if(cmd == "pdremove") removeOp(cmd, date);
            else std::cout << "Wrong Instruction! Please give the right instruction\n";
        }
        void readIn() {
            std::cout << "-------Diary System (type 'exit' to quit)------\n"; //exit表示结束操作
            while (true) {
                std::cout << "> "; //模仿Linux系统中的命令标识符
                if (!std::getline(std::cin, inst) || inst == "exit") break;
                if (!inst.empty()) parseCommand();
            }
        }

        void writeIn(std::string input, std::string date) {
            db.insertEntity(date, input); //注意insertEntity和writeIn的date和input是反过来的
        }

        void addOp(std::string cmd, std::string date) {
            int beginIndex = inst.find(date) + date.size();
            // 因为find函数只会返回子串在母串中的起始点，所以我们需要加上子串的长度，因为需要省去空格，所以不需要再减一
            std::string input = inst.substr(beginIndex);
            std::string allInput;
            allInput = allInput + input;
            while(std::getline(std::cin, input)) {//while循环遇到输入EOF时会自动终止
                if(input == ".") break;
                allInput += input + "\n";
            }
            writeIn(allInput, date); //将最后统一收集的输入直接存到personal diary中
        }

        void listOp(std::string cmd) {
            if(inst == cmd) {
                db.printContentAll();
                return;
            }
            std::istringstream is(inst);
            std::string begin, end, temp;
            is >> temp >> begin >> end;
            db.printContentList(begin, end);
        }

        void showOp(std::string cmd, std::string date) {
            db.printContentOne(date);
        }

        void removeOp(std::string cmd, std::string date) {
            db.removeEntity(date);
        }
};

int main() {
    User pd;
    pd.readIn();
    return 0;
}