#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account{

    public:
        Account(std::string);
        ~Account();
        void setDetails( std::string,std::string, float);
        std::string getAccountNo();
        float getAccountBalance();
        void addToBalance(float);
        void subtractFromBalance(float);

    private:
        std::string accountNo;
        std::string owner;
        std::string name;
        float balance;

};
#endif