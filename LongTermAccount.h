#pragma once
#include <iostream>
using namespace std;
#include "Account.h"

class LongTermAccount : public Account
{
public:
    LongTermAccount();
    ~LongTermAccount();


    void deleteAccount();

    void calculateInterest() const override;

    string accountType() const override;
};

