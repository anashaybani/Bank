#pragma once
#include <iostream>
#include <string>
using namespace std;


class Account
{
private:
    string IDnum;
    string cardNumber;
    string accountNumber;
    string shabaNumber;
    string cvv2;
    double balance;
    string expirationDate;
    string pinCode;
    string staticSecondPassword;
    string dynamicSecondPassword;

public:

    Account();
    virtual ~Account();

    string getIDnum() const;
    string getCardNumber() const;
    string getAccountNumber() const;
    string getShabaNumber() const;
    string getCVV2() const;
    double getBalance() const;
    string getExpirationDate() const;
    string getPinCode() const;
    string getStaticSecondPassword() const;
    string getDynamicSecondPassword() const;

    
    void setCardNumber(const string& cardNum);
    void setAccountNumber(const string& accNum);
    void setShabaNumber(const string& shaba);
    void setCVV2(const string& cvv);
    void setBalance(double bal);
    void setExpirationDate(const string& date);
    void setPinCode(const string& pin);
    void setStaticSecondPassword(const string& spw);
    void setDynamicSecondPassword(const string& pw);


    string generateRandomDigits(int length) const;

    string display() const;


    virtual string accountType() const;
    virtual void calculateInterest() const;
    virtual void deleteAccount();


    void setAccount(const string& ID);
    void editAccount();
    void showAccount() const;

};

