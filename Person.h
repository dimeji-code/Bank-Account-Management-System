#ifndef PERSON_H
#define PERSON_H
#include "Account.h"

class Person{
    public:
        Person(std::string);
        ~Person();
        void setName(std::string);
        void setAccount(std::string,std::string,std::string,float);
        std::string getName();
        void printAccounts();
        int getNumAccounts();
        bool accountExists(std::string );
        void deposit(std::string,float);
        void transfer(std::string,std::string);
    private:
        int numAccounts;
        std::string name;
        Account *accounts[3];
};

#endif