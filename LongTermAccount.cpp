#include "LongTermAccount.h"

LongTermAccount::LongTermAccount() : Account() {}
LongTermAccount::~LongTermAccount(){}


void LongTermAccount::deleteAccount() { this->~LongTermAccount(); }


void LongTermAccount::calculateInterest() const {
    cout << endl << "Long-term interest applied: 18%  ";}


string LongTermAccount::accountType() const {
    return "LongTerm";}