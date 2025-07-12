#include "Account.h"
#include "globals.h"

Account::Account() :
	IDnum(""),
	cardNumber(""),
	accountNumber(""),
	shabaNumber(""),
	cvv2("000"),
	balance(0.0),
	expirationDate("01/30"),
	pinCode("0000"),
	staticSecondPassword(""),
	dynamicSecondPassword("") {}
Account::~Account() {}

string Account::getIDnum() const { return	IDnum; }
string Account::getCardNumber() const { return cardNumber; }
string Account::getAccountNumber() const { return accountNumber; }
string Account::getShabaNumber() const { return shabaNumber; }
string Account::getCVV2() const { return cvv2; }
double Account::getBalance() const { return balance; }
string Account::getExpirationDate() const { return expirationDate; }
string Account::getPinCode() const { return pinCode; }
string Account::getStaticSecondPassword() const { return staticSecondPassword; }
string Account::getDynamicSecondPassword() const { return dynamicSecondPassword; }


void Account::setCardNumber(const string& cardNum) {
	cardNumber = cardNum;
}
void Account::setAccountNumber(const string& accNum){
	accountNumber = accNum; 
}
void Account::setShabaNumber(const string& shaba) {
	shabaNumber = shaba ;
}
void Account::setCVV2(const string& cvv) {
	cvv2 = cvv ;
}
void Account::setBalance(double bal){
	balance = bal;
}
void Account::setExpirationDate(const string& date) {
	expirationDate = date ;
}
void Account::setPinCode(const string& pin) {
	pinCode = pin;
}
void Account::setStaticSecondPassword(const string& spw) {
	staticSecondPassword = spw;
}
void Account::setDynamicSecondPassword(const string& pw) {
	dynamicSecondPassword = pw ;
}



string Account::accountType() const {
	return "Generic Account";
}


void Account::calculateInterest() const {
	cout << endl << "Base Account: No interest! ";
}



void Account::deleteAccount() { this->~Account(); }





string  Account::display() const {
	return cardNumber;
}





string Account::generateRandomDigits(int length) const {
	string result;
	for (int i = 0; i < length; ++i) {
		result += '0' + rand() % 10;
	}
	return result;
}



void Account::setAccount(const string& ID) {
	this->IDnum = ID;
	cardNumber = generateRandomDigits(6) + ID;
	shabaNumber = generateRandomDigits(14) + ID;
	accountNumber = ID.substr(4, 6);
	cvv2 = generateRandomDigits(3);
	pinCode = generateRandomDigits(4);
	staticSecondPassword = generateRandomDigits(6);
	cout << endl << "Enter account balance";
	cin >> balance;
	cout << endl << "Enter account expiration date";
	cin >> expirationDate;
}

void Account::editAccount() {
	cout << endl << "edit : 1.pinCode    2.Second Password  ";
	int num;
	cin >> num;
	if(num == 1){
		cout << endl << "Enter new pinCode :  ";
		cin >> pinCode;
		cout << endl << "pinCode changed !  ";
	}
	else if (num == 2) {
		cout << endl << "Enter new Second Password :  ";
		cin >> staticSecondPassword;
		cout << endl << "Second Password changed !  ";
	}
}

void Account::showAccount() const {
	cout << endl << "		***Account information :***  ";
	cout << endl << "Card Number :  "<< cardNumber;
	cout << endl << "Account Number :  "<< accountNumber;
	cout << endl << "shaba Number :  "<< shabaNumber;
	cout << endl << "cvv2 :  " << cvv2;
	cout << endl << "balance :  " << balance;
	cout << endl << "expiration Date :  " << expirationDate;
	cout << endl << "pinCode :  " << pinCode;
	cout << endl << "Second Password :  " << staticSecondPassword;
}



