#pragma once
#include <iostream>
using namespace std;
#include "Account.h"

class GharzolHasanehAccount : public Account
{
public:
    GharzolHasanehAccount();
    ~GharzolHasanehAccount();


    void deleteAccount()override;

    void calculateInterest() const override;

    string accountType() const override;

};

