#include "Admin.h"
#include "globals.h"


Admin::Admin() : User() { this->setUser(); }

Admin::~Admin() {}



void Admin::findCostumer() {
	cout << endl << "Enter costumer ID : ";
	string ID;
	cin >> ID;
	Costumer* dest = COSTUMERS.search(ID);
	if (!dest) {
		cout << "\nCostumer not found!";
		cout << endl << "**	1.add new Costumer		0.Exit     **";
		int choice;
		cin >> choice;
		if (1 == choice) {
			Costumer c;
			COSTUMERS.add(&c);
			cout << endl << " Costumer	 added . ";
			return;
		}
		else { return; }
	}
	else {
		int choice;
		cout << endl << "**		1.Card		2.Costumer 	** ";
		cin >> choice;
		if (1 == choice) {
			int cho;
			cout << endl << "**		1.edit		2.remove	3. add     ** ";
			cin >> cho;
			if(cho == 1){
				dest->editAccounts();
				return;
			}
			else if (cho == 2) {
				dest->deleteAccounts();
				return;
			}
			else if (cho == 3) {
				dest->addAccount();
				return;
			}
			else{return;}
			
		}
		else if (2 == choice) {
			int cho;
			cout << endl << "**		1.edit		2.remove	 ** ";
			cin >> cho;
			if (cho == 1) {
				dest->editUser();
				return;
			}
			else if (cho == 2) {
				dest->delete_all_Accounts();
				COSTUMERS.remove(dest->getNationalCode());
				cout << endl << " Costumer	 removed . ";
				return;
			}
			else{ return; }
		}
		else { return; }
	}
}



void Admin::findAdmin() {
    cout << endl << "Enter admin ID : ";
    string ID;
    cin >> ID;
    	Admin* dest = ADMINS.search(ID);
	if (!dest) {
		cout << "\nAdmin card not found!";
		cout << endl << "**	1.add new Admin		0.Exit     **";
		int choice;
		cin >> choice;
		if (1 == choice) { 
			Admin a;
			ADMINS.add(&a);
			cout << endl << " Admin	 added . ";
			return;
		}
		else { return; }
	}
	else {
		int choice = 0;
		cout << endl << "**		1.edit		2.remove	** ";
		cin >> choice;
		if (1 == choice) {
			dest->editUser();
			return;
		}
		else if (2 == choice) {
			ADMINS.remove(dest->getNationalCode());
			cout << endl << " Admin	 removed . ";
			return;
		}
		else { return; }
	}

}