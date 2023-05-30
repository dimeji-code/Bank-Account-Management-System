#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.h"
// run code with g++ proj.cpp Account.cpp Person.cpp
// then ./a.out
//or ./a.out < test.txt
//test colors specified with ANSI color codes

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
// void deposit(Person *me){
//     if(me->getNumAccounts() < 1){
//         std::cout<< "You must have at least 1 account to make a deposit!\nBack to MAIN MENU." << std::endl;
//     } else{
//         bool found = false;
//         std::string accNo;
//         std::cout<< "\nAccounts"<<std::endl;
//         me->printAccounts();
//         //loop till account number found
//         while(!found){
//             std::cout<< "\nType the account number:"<<std::endl;
//             std::cin >> accNo ;
//         (me->accountExists(accNo) == true )? (found = true) : (std::cout<<"Account Does NOT exist"<<std::endl); 
//         }
//         float amount;
//         std::cout<< "\nEnter Amount to deposit:  $";
//         std::cin >> amount;
//         me->deposit(accNo,amount);
//     }
// }

void deposit(Person *me){

    if(me->getNumAccounts() < 1){
        std::cout<< "You must have at least 1 account to make a deposit!\nBack to MAIN MENU." << std::endl;
    } else{
        bool found = false;
        int accNo;

        std::cout<< "\nAccounts"<<std::endl;
        me->printAccounts();

        //loop till account number found
        while(!found){
            std::cout<< "\nSelect the account [ 1 - 3 ]:"<<std::endl;
            std::cin >> accNo ;
            //make sure input is of the correct type
            while (!std::cin.good())
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<< "\nSelect the account [ 1 - 3 ]:"<<std::endl;
                std::cin >> accNo ;

            }  

            //make sure that the input meets the possible requirements
            (accNo <= me->getNumAccounts() )? (found = true) : (std::cout<<"Account Does NOT exist"<<std::endl); 
        }
        Account* x = me->getAccount(accNo-1);

        float amount;
        std::cout<< "\nEnter Amount to deposit:  $";
        std::cin >> amount;
        //deposit the amount in the account
        me->deposit(x->getAccountNo(),amount);
    }
}

// make transfer between accounts
// void transfer(Person *me){
//     //make sure atleast 2 accounts exist
//     if(me->getNumAccounts() <= 1){
//         std::cout<< "You must have at least two accounts to transfer between!\nBack to MAIN MENU." << std::endl;
//     } else{
//         std::string from, to;
//         bool verified = false;
//         checkBalance(me);
//         //loop account number entry until gotten right
//         while (!verified){
//             std::cout<<"Enter account to transfer FROM"<<std::endl;
//             std::cin >> from;
//             (me->accountExists(from) == true )? verified = true: std::cout<<"Wrong Account Number Entered!"<<std::endl;
//         }
//         verified = false;
//         //loop account number entry until gotten right
//         while (!verified){
//             std::cout<<"Enter account to transfer TO"<<std::endl;
//             std::cin >> to;
//             (me->accountExists(to) == true )? verified = true: std::cout<<"Wrong Account Number Entered!"<<std::endl;
//         }
//         me->transfer(from, to);
//     }
// }

// make transfer between accounts
void transfer(Person *me){
    //make sure atleast 2 accounts exist
    if(me->getNumAccounts() <= 1){
        std::cout<< "You must have at least two accounts to transfer between!\nBack to MAIN MENU." << std::endl;
    } else{
        int from, to;
        bool verified = false;
        checkBalance(me);
        //loop account number entry until gotten right
        while (!verified){
            std::cout<<"Enter account (1, 2 or 3) to transfer FROM"<<std::endl;
            std::cin >> from;
            while (!std::cin.good())
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<< "Enter account (1, 2 or 3) to transfer FROM"<<std::endl;
                std::cin >> from ;
            }  
            (from <= me->getNumAccounts() && from > 0  )? (verified = true) : (std::cout<<"Account Does NOT exist"<<std::endl); 
        }
        verified = false;
        //loop account number entry until gotten right
        while (!verified){
            std::cout<<"Enter account (1, 2 or 3) to transfer TO"<<std::endl;
            std::cin >> to;
            while (!std::cin.good())
            {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<< "Enter account (1, 2 or 3) to transfer TO"<<std::endl;
                std::cin >> to ;
            }  
            (to <= me->getNumAccounts() && to > 0 )? (verified = true) : (std::cout<<"Account Does NOT exist"<<std::endl); 
        }
        //subtract 1 from value to get index
        Account *b = me->getAccount(from-1);
        Account *c = me->getAccount(to-1);

        std::string fromNo, toNo;
        fromNo = b->getAccountNo();
        toNo = c->getAccountNo();

        me->transfer(fromNo, toNo);
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

void testInt(int actual, int expected,std::string testName){
    std::cout<< testName <<std::endl;       
    std::cout<<"\tActual Value: "<< actual<< "\n\tExpected Value: "<< expected<<std::endl;

    if(actual != expected){
        std::cout<< "\e[0;31m" <<"\t --------"<< "\E[0m"<<std::endl;
        std::cout<< "\e[0;31m" <<"\t| Failed |"<< "\E[0m"<<std::endl;
        std::cout<< "\e[0;31m" <<"\t --------"<< "\E[0m"<<std::endl;
    }else{
        std::cout<< "\E[22;32m" <<"\t\t ---------"<< "\E[0m" <<std::endl;
        std::cout<< "\E[22;32m" <<"\t\t| Passed! |"<< "\E[0m" <<std::endl;
        std::cout<< "\E[22;32m" <<"\t\t ---------\n"<< "\E[0m" <<std::endl;
    }
}

void testString(std::string actual, std::string expected,std::string testName){
    std::cout<< testName <<std::endl;       
    std::cout<<"\tActual Value: "<< actual<< "\n\tExpected Value: "<< expected<<std::endl;

    if(actual != expected){
        std::cout<< "\e[0;31m" <<"\t ---------"<< "\E[0m"<<std::endl;
        std::cout<< "\e[0;31m" <<"\t| Failed! |"<< "\E[0m"<<std::endl;
        std::cout<< "\e[0;31m" <<"\t ---------"<< "\E[0m"<<std::endl;
    }else{
        std::cout<< "\E[22;32m" <<"\t\t ---------"<< "\E[0m" <<std::endl;
        std::cout<<"\E[22;32m" <<"\t\t| Passed! |"<< "\E[0m" <<std::endl;
        std::cout<<"\E[22;32m" <<"\t\t ---------\n"<< "\E[0m" <<std::endl;
    }
}

void testFunction(){
    //Generic testing for dynamic allocation and setting accounts
    std::cout << "\e[0;34m" <<" ------"<<std::endl;
    std::cout  <<"| TEST |"<<std::endl;
    std::cout  <<" ------"<< "\E[0m" <<std::endl;

    Person *testPerson = new Person("Tester");
    testString(testPerson->getName(),"Tester","Test 1\nReturn created person name: 'Tester' !");
    testInt(testPerson->getNumAccounts(),0,"Test 2\nReturn the number of Accounts Tester has!");
    
    testPerson->setAccount("Tester","Chequing",randomId(),0.00);
    std::cout<<" --------------------------------------------"<<std::endl;
    std::cout<<"| Just Created a Chequing account for Tester |"<<std::endl;
    std::cout<<" --------------------------------------------\n"<<std::endl;
    testInt(testPerson->getNumAccounts(),1,"Test 3\nReturn the number of Accounts Tester has!");
    
    testPerson->setAccount("Tester","Savings",randomId(),0.00);
    std::cout<<" -------------------------------------------"<<std::endl;
    std::cout<<"| Just Created a Savings account for Tester |"<<std::endl;
    std::cout<<" -------------------------------------------\n"<<std::endl;
    testInt(testPerson->getNumAccounts(),2,"Test 4\nReturn the number of Accounts Tester has!");
    checkBalance(testPerson);

    Account *a = testPerson->getAccount(0);
    testPerson->deposit(a->getAccountNo(),50);
    std::cout<<" ----------------------------"<<std::endl;
    std::cout<<"| Deposit $50 in account (1) |"<<std::endl;
    std::cout<<" ----------------------------\n"<<std::endl;
    testInt(a->getAccountBalance(),50,"Test 5\nReturn an account balance of $50!");
    checkBalance(testPerson);
  
    a = testPerson->getAccount(1);

    std::cout<<" deposit 10 $ to -> "<<a->getAccountNo()<<std::endl;
    testPerson->deposit(a->getAccountNo(),10);
    std::cout<<" ----------------------------"<<std::endl;
    std::cout<<"| Deposit $10 in account (2) |"<<std::endl;
    std::cout<<" ----------------------------\n"<<std::endl;
    testInt(a->getAccountBalance(),10,"Test 6\nReturn an account balance of $10!");

    checkBalance(testPerson);

    std::cout<<"End of Test"<<std::endl;
    delete a;
    delete testPerson;
}

int main(){

    int mode;

    std::cout << "Welcome to Bank Account Simulator.\nPress (1) to run Test or\nPress (2) to run program manually."<<std::endl;
    std::cin>> mode ; 
    // if (std::stoi(mode) == 1) {testFunction();}
    if (mode == 1) {testFunction();}

    else{
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
    }

    return 0;
}


