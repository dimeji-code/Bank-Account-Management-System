#include <iostream>
#include <vector>
#include "Account.h"

Account::Account(std::string user){
    owner = user;
}
Account::~Account(){

}
void Account::setDetails( std::string accountName,std::string accountNum, float balance){
    accountNo = accountNum;
    name = accountName;
    this->balance = balance;

}

std::string Account::getAccountNo(){

    return accountNo;
}


float Account::getAccountBalance(){

    return balance;
}
void Account::addToBalance(float bal){
    this->balance += bal;
}
void Account::subtractFromBalance(float bal){
    this->balance -= bal;
}