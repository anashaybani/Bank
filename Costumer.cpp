#include "Costumer.h"


Costumer::Costumer() : User(), accountCount(0) {
    for (int i = 0; i < 5; ++i)
        accounts[i] = nullptr;
    this->setUser();
}

Costumer::~Costumer() {
    for (int i = 0; i < 5; ++i) {
        delete accounts[i];
        accounts[i] = nullptr;
    }
}


void Costumer::setAccountCount(int number) {
    accountCount = number;
}
int Costumer::getAccountCount() const {
    return accountCount;
}
void Costumer::setAccount( Account* account) {
    if (accountCount < 5) {
        accounts[accountCount] = account;
        accountCount++;
    }
}
Account* Costumer::getAccount(int index) const {
    if (index >= 0 && index < 5)
        return accounts[index];
    return nullptr;
}



void Costumer::addAccount(){
    if (accountCount < 5) {
        cout << endl << "**  1.Jari      2.LongTerm      3.GharzolHasaneh  **";
        cout << endl << "chose account type : ";
        int cho =0;
        cin >> cho;
        if(cho == 1){
            JariAccount j;
            accounts[accountCount] = new JariAccount();
            accounts[accountCount]->setAccount(getNationalCode());
            accountCount++;
        }
        else if (cho == 2) {
            accounts[accountCount] = new LongTermAccount();
            accounts[accountCount]->setAccount(getNationalCode());
            accountCount++;
        }
        else if (cho == 3) {
            accounts[accountCount] = new GharzolHasanehAccount();
            accounts[accountCount]->setAccount(getNationalCode());
            accountCount++;
        }
        else{ cout << endl << "wrong imput ! "; }
    }
    else {
        cout << endl << "five accounts ! ";
    }
}


void Costumer::editAccounts(){
    if (accountCount >= 0 && accountCount <= 5) {
        int index = 0;
        while (index < accountCount) {
            cout << endl << index +1;
            cout << "     " << accounts[index]->accountType() << "     " << accounts[index]->getCardNumber();
                index++;
        }
        int num = 0;
        cout << endl << "Enter account num ";
        cin >> num;
        if (num >= 1 && num <= accountCount) {
            accounts[num-1]->editAccount();
        }

    }
    else {
        cout << endl << "no account ! ";
    }
}


void Costumer::deleteAccounts(){
    if (accountCount >= 0 && accountCount <= 5) {
        int index = 0;
        while (index < accountCount) {
            cout << endl << index + 1;
            cout << "     " << accounts[index]->accountType() << "     " << accounts[index]->getCardNumber();
                index++;
        }
        int num = 0;
        cout << endl << "Enter account num ";
        cin >> num;
        if (num >= 1 && num <= accountCount) {
            accounts[num -1 ]->deleteAccount();
            accounts[num-1] = nullptr;
            for (int i = num; i < accountCount; i++) {
                accounts[i - 1] = accounts[i];
            }
            accountCount--;
        }

    }
    else {
        cout << endl << "no account ! ";
    }
}


void Costumer::showAccounts() const{
    if (accountCount >= 0 && accountCount <= 5) {
        int index = 0;
        while( index < accountCount){
            cout <<endl<< accounts[index]->accountType() << "     " << accounts[index]->getCardNumber();
            index++;
        }
    }
    else {
        cout << endl << "no account ! ";
    }
}




