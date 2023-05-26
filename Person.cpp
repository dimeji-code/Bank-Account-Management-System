#include <iostream>
#include <vector>
#include "Person.h"

Person::Person(std::string personName){
    setName(personName);
}

Person::~Person(){
    std::cout << "\nDe-allocate Person Data" << std::endl;
    std::cout << "De-allocate Memory\n" << std::endl;
}

void Person::setName(std::string personName){
    name = personName;
}

int Person::getNumAccounts(){
    return numAccounts;
}

void Person::setAccount(std::string personName,std::string acctName,std::string acctNum,float bal){
    Account *a = new Account(personName);
    a->setDetails(acctName, acctNum, bal);

    accounts[numAccounts] = a;
    numAccounts++;
}

std::string Person::getName(){
    
    return this->name;
}

Account* ( Person::getAccounts()){
    return *accounts;
}

void Person::printAccounts(){
    std::cout<<"You can have a maximum of 3 Accounts.\n"<<std::endl;
    for(int i=0; i<  (sizeof(accounts)/sizeof(*accounts))  ;i++){
        if( this->accounts[i] == NULL){
            std::cout <<"Account "<< i+1 << " -> is NULL"<<std::endl;
        }else{
            std::cout <<"Account "<< i+1 << " -> "<< this->accounts[i]->getAccountNo()<<std::endl;
            std::cout <<"\tBalance is $"<< this->accounts[i]->getAccountBalance()<< "\n"<<std::endl;
        }

    }
}

bool Person::accountExists(std::string account){

    for(int i=0; i<  (sizeof(accounts)/sizeof(*accounts))  ;i++){
         if( this->accounts[i] == NULL){
            // do nothing
        }
        else if( this->accounts[i]->getAccountNo() == account){
            std::cout <<"Account Exists"<<std::endl;
            return true;
        }

    }
    return false;
}

void Person::deposit(std::string account,float dep ){
    Account *curr;
    for(int i=0; i<  (sizeof(accounts)/sizeof(*accounts))  ;i++){
         if( this->accounts[i] == NULL){
            // do nothing
        }
        else if( this->accounts[i]->getAccountNo() == account){
            std::cout <<"Account Exists"<<std::endl;
            curr = this->accounts[i];
            std::cout << this->accounts[i] << std::endl;
            std::cout << curr << std::endl;
            curr->addToBalance(dep);
            break;
        }

    }
}

void Person::transfer(std::string from,std::string to){

    Account *first;
    Account *second;

    for(int i=0; i<  (sizeof(accounts)/sizeof(*accounts))  ;i++){
         if( this->accounts[i] == NULL){
            // do nothing
        }
        else if( this->accounts[i]->getAccountNo() == from){
            first = this->accounts[i];
        }
        else if( this->accounts[i]->getAccountNo() == to){
            second = this->accounts[i];
        }
    }
    float amt;
    std::cout<<"How much would you like to transfer to acct #"<< to <<std::endl;
    std::cin>> amt ;
    //check if account has enough funds for transfer
    if (amt <= first->getAccountBalance()){
        first->subtractFromBalance(amt);
        second->addToBalance(amt);
    }else{
        std::cout<<"Insufficient Funds For Transfer From "<< first->getAccountNo() <<std::endl;
        std::cout<<"Account# "<< first->getAccountNo() << " has $"<<first->getAccountBalance()<<"\n" <<std::endl;
    }


}