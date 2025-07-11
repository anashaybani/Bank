#include "User.h"


User::User() :
	firstName(""),
	lastName(""),
	nationalCode(""),
	age(1),
	username(""),
	password("") {}
 User::~User(){}


string User::getFirstName() const { return firstName; }
string User::getLastName() const{ return lastName; }
string User::getNationalCode() const{ return nationalCode; }
int User::getAge() const{ return age; }
string User::getUsername() const{ return username; }
string User::getPassword() const{ return password; }

void User::setFirstName(const string& fName){ firstName = fName; }
void User::setLastName(const string& lName){ lastName = lName; }
void User::setNationalCode(const string& ID){ nationalCode = ID; }
void User::setAge(const int & ag){ age = ag; }
void User::setUsername(const string& uName){ username = uName; }
void User::setPassword(const string& pass){ password = pass; }


string User::display() const {
	return nationalCode;
}



void User::setUser(){

	cout << endl << "Enter first name  : ";
	getline(cin, this->firstName);
	cout << endl << "Enter last name  : ";
	getline(cin, this->lastName);
	cout << endl << "Enter national Code  : ";
	cin >> nationalCode;
	cout << endl << "Enter age  : ";
	cin >> age;
	username = nationalCode;
	cout << endl << "Enter password  : ";
	cin >> password;

}




void User::editUser(){
	int co;
	cout << endl << "edit :  1.first name    2.last name    3.password    0.Exit";
	cin >> co;
	if(co == 1){
		cout << endl << "Enter first name  : ";
		getline(cin, this->firstName);
	}
	else if(co == 2){
		cout << endl << "Enter last name  : ";
		getline(cin, this->lastName);
	}
	else if (co == 3) {
		cout << endl << "Enter password  : ";
		cin >> password;
	}
	else{
		return;
	}

}
