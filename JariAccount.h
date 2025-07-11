#pragma once
#include <iostream>
using namespace std;
#include "Account.h"

class JariAccount : public Account
{
public:
    JariAccount();
    ~JariAccount();


    void deleteAccount()override;

    void calculateInterest() const override;

    string accountType() const override;

};

