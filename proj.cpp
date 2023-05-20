#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.h"
// run code with g++ proj.cpp Account.cpp Person.cpp
// then ./a.out


//main menu
void menu(){
    std::cout<<"\n-------Menu-------\n"<<std::endl;
    std::cout<<"1. Create Account"<<std::endl;
    std::cout<<"2. Check Balance"<<std::endl;
    std::cout<<"3. Make a deposit"<<std::endl;
    std::cout<<"4. Transfer Funds Between Accounts"<<std::endl;
    std::cout<<"\nSelection: ";

}
//Generate random Bank Account Number
std::string randomId(){
    //Generate random account number
    int id = rand() % 100000 + 1;
    char randLetter1 = toupper('a' + rand()%26 );
    std::string s = std::to_string(id);
    char randLetter2 = toupper('a' + rand()%26 );
    char randLetter3 = toupper('a' + rand()%26 );
    std::string bankId = randLetter1 + s + randLetter2 + randLetter3;
    return bankId;
}
//display account balance of all accounts
void checkBalance(Person *me){
    std::cout<< "\nAccount Balance is"<<std::endl;
    me->printAccounts();
}

//make a deposit
void deposit(Person *me){

    if(me->getNumAccounts() < 1){
        std::cout<< "You must have at least 1 account to make a deposit!\nBack to MAIN MENU." << std::endl;
    } else{
        bool found = false;
        std::string accNo;

        std::cout<< "\nAccounts"<<std::endl;
        me->printAccounts();

        //loop till account number found
        while(!found){
            std::cout<< "\nType the account number:"<<std::endl;
            std::cin >> accNo ;
        (me->accountExists(accNo) == true )? (found = true) : (std::cout<<"Account Does NOT exist"<<std::endl); 
        }

        float amount;
        std::cout<< "\nEnter Amount to deposit:  $";
        std::cin >> amount;
        me->deposit(accNo,amount);
    }



}
//make transfer between accounts
void transfer(Person *me){
    //make sure atleast 2 accounts exist
    if(me->getNumAccounts() <= 1){
        std::cout<< "You must have at least two accounts to transfer between!\nBack to MAIN MENU." << std::endl;
    } else{
        std::string from, to;
        bool verified = false;
        checkBalance(me);


        //loop account number entry until gotten right
        while (!verified){
            std::cout<<"Enter account to transfer FROM"<<std::endl;
            std::cin >> from;
            (me->accountExists(from) == true )? verified = true: std::cout<<"Wrong Account Number Entered!"<<std::endl;
        }

        verified = false;

        //loop account number entry until gotten right
        while (!verified){
            std::cout<<"Enter account to transfer TO"<<std::endl;
            std::cin >> to;
            (me->accountExists(to) == true )? verified = true: std::cout<<"Wrong Account Number Entered!"<<std::endl;
        }

        me->transfer(from, to);
    }
}

//create a new account
void createAccount(Person *me){
        int option;
        std::string accType;
        std::string myName = me->getName();
        while(true){
            std::cout<<"Enter account type: \n(1) for Chequing \nor \n(2) for Savings"<<std::endl;
            std::cin>> option ;
            if (option == 1){
                accType = "Chequing";
                break;
            }else if (option == 2){
                accType = "Savings";
                break;
            }
        }
        me->setAccount(myName,accType,randomId(),0.00);
        
}

int main(){
    srand(time(0));

    std::string myName;
    std::cout << "Please enter your name"<<std::endl;
    std::cin>> myName ;
    std::system("clear");


    Person *p1 = new Person(myName);
    
    int selection;
    bool state = true;
    std::cout <<"\nHello "<<p1->getName() <<"!!! \nWelcome to Standard Bank.\nThe Greenest Bank in the world.\n"<<std::endl;


    while (state == true){
        std::cout<<"Select an option by typing the Number then hit ENTER."<<std::endl;
        menu();
        std::cin>> selection ;
        //switch case main menu
        switch(selection){
            case 1: 
                if (p1->getNumAccounts() == 3 ){
                    std::cout<< "\nSorry :( \nYou have reached the MAXIMUM # of accounts"<<std::endl;
                }else{
                    createAccount(p1);

                }
                break;
            case 2: 
                checkBalance(p1);
 
                break;
            case 3: 
                deposit(p1);
                break;
            case 4: 
                transfer(p1);
                break;


        }
        std::string str;
        std::cout<<"Would you like to exit program? Y or N."<<std::endl;
        std::cin >> str;
        std::system("clear");

        if (str == "Y" || str == "y" || str == "yes" || str == "Yes"){
            std::cout <<"\nGoodbye "<<p1->getName() <<" and Thank you for using Standard Bank.\n"<<std::endl;
            state = false;

        }

    }

    return 0;
}


