#include "GharzolHasanehAccount.h"

GharzolHasanehAccount::GharzolHasanehAccount() : Account() {}
GharzolHasanehAccount::~GharzolHasanehAccount(){}


void GharzolHasanehAccount::deleteAccount() { this->~GharzolHasanehAccount(); }

void GharzolHasanehAccount::calculateInterest() const {
	cout <<endl<< "No interest! Eligible for prize draw.";
}

string GharzolHasanehAccount::accountType() const {
	return "GharzolHasaneh";
}
