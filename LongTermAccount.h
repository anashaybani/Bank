#pragma once
#include <iostream>
using namespace std;
#include "Account.h"

class LongTermAccount : public Account
{
public:
    LongTermAccount();
    ~LongTermAccount();


    void deleteAccount()override;

    void calculateInterest() const override;

    string accountType() const override;
};

