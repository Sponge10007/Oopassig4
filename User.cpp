#include "diary.h"
#include<iostream>
#include<map>

class User {
    private:
        std::string inst;
    public:
        // the function to read in the entity and write into the diary
        void readIn() {
            std::getline(std::cin, inst);
            if(inst.find("pdadd")) addOp();
            if(inst.find("pdlist")) listOp();
            if(inst.find("pdshow")) showOp();
            if(inst.find("pdremove")) removeOp();
        }

        void writeIn() {
            
        }

        void addOp() {
            
        }

        void listOp() {

        }

        void showOp() {

        }

        void removeOp() {

        }
};