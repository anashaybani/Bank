#include "JariAccount.h"

JariAccount::JariAccount() : Account() {}
JariAccount::~JariAccount(){}


void JariAccount::deleteAccount() { this->~JariAccount(); }

void JariAccount::calculateInterest() const {
	cout <<endl<< "No interest! Can issue cheques.";
}

string JariAccount::accountType() const {
	return "Jari";
}
