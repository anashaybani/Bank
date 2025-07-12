#include "CardToCard.h"
#include "globals.h"


CardToCard::CardToCard() : 
	amount(0.0),
	originCardNum(""),
	destinationCardNum(""),
	date("")
 {}


CardToCard::~CardToCard(){}


string CardToCard::display() const { return originCardNum + date; }


double CardToCard::getAmount()const { return amount; }


void CardToCard::setCardToCard(){
	cout << endl << "Enter origin card number : ";
	string cNum;
	cin >> cNum;
	Account* origin = ACCOUNTS.search(cNum);
	if (!origin) {
		cout << "\norigin card not found!";
		return;
	}
	else{
		string cvv2;
		cout << endl << "Enter origin cvv2 : ";
		cin >> cvv2;
		if(origin->getCVV2() == cvv2 ){
			string destination;
			cout << "\nEnter destination card number: ";
			cin >> destination;

			Account* dest = ACCOUNTS.search(destination);
			if (!dest) {
				cout << "\nDestination card not found!";
				return;
			}
			else {
				User* Pdest = USERS.search(dest->getIDnum());
				cout << "\nReceiver: " << Pdest->getFirstName() << " " << Pdest->getLastName();

				cout << "\nEnter today's date (YYYYMMDD): "; 
				cin >> date;
				if (date > origin->getExpirationDate()) {
					cout << "\nYour card has expired!";
					return;
				}
				else {
					cout << "\nEnter amount: ";
					cin >> amount;
					double total = amount * 1.01;
					CardToCard* recent = CardToCardS.search(this->display());
					if (amount > 3000000 || total > origin->getBalance() || recent->getAmount() + amount > 6000000) {
						cout << "\nAmount exceeds limit or insufficient funds!!";
						return;
					}
					string pass;
					if (amount <= 100000) {
						cout << "\nEnter static second password: ";
						cin >> pass;

						if (pass != origin->getStaticSecondPassword()) {
							cout << "\nWrong password!";
							return;
						}
					}
					else {
						string DSP = origin->generateRandomDigits(6);
						origin->setDynamicSecondPassword(DSP);
						cout << "\nYour dynamic password: " << DSP;

						cout << "\nEnter dynamic password: ";
						cin >> pass;

						if (pass != DSP) {
							cout << "\nWrong dynamic password!";
							return;
						}
					}
					origin->setBalance(origin->getBalance() - total);
					dest->setBalance(dest->getBalance() + amount);

					cout << "\nTransfer successful!";

			
				}

			}
		}
		else{
			cout << "\nwrong cvv2 !";
			return;
		}
	
	}

}

