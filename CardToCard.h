#pragma once
#include "Account.h"

class CardToCard
{private:
	double amount;
	string originCardNum;
	string destinationCardNum;
	string date;

public:
	CardToCard();
	~CardToCard();


	string display()const ;
	double getAmount()const ;


	void setCardToCard();

};

