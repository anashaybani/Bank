#pragma once
#include "User.h"
#include "JariAccount.h"
#include "GharzolHasanehAccount.h"
#include "LongTermAccount.h"

class Costumer : public User
{		
private:
	int accountCount = 0;
	Account* accounts[5];

public:
	Costumer();
	~Costumer();


	void setAccountCount(int number);
	int getAccountCount() const;

	void setAccount( Account* account);
	Account* getAccount(int index) const;



	void addAccount();
	void editAccounts();
	void deleteAccounts();
	void showAccounts() const;

};

