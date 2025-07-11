#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Account.h"

class User
{
private:
    string firstName;
    string lastName;
    string nationalCode;
    int age;
    string username;
    string password;

public:
    User();
    virtual~User();


    string getFirstName() const;
    string getLastName() const;
    string getNationalCode() const;
    int getAge() const;
    string getUsername() const;
    string getPassword() const;

    void setFirstName(const string& fName);
    void setLastName(const string& lName);
    void setNationalCode(const string& ID);
    void setAge(const int& ag);
    void setUsername(const string& uName);
    void setPassword(const string& pass);


    void setUser();
};

