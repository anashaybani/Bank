#include "addcardwindow.h"
#include "ui_addcardwindow.h"


#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/JariAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/globals.h"

#include <QMessageBox>


AddCardWindow::AddCardWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCardWindow)
{
    ui->setupUi(this);

    ui->accountTypeCombo->addItem("Jari");
    ui->accountTypeCombo->addItem("LongTerm ");
    ui->accountTypeCombo->addItem("GharzolHasaneh");
    ui->cardInfoBox->setReadOnly(true);


}

AddCardWindow::~AddCardWindow()
{
    delete ui;
}



void AddCardWindow::on_addCardButton_clicked()
{
    if (CURRENT_COSTUMER->getAccountCount() >= 5) {
         QMessageBox::warning(this, "ERROR", "Five existing cards!");
        return;
    }

    int selectedType = ui->accountTypeCombo->currentIndex();
    Account* newAccount = nullptr;

    if (selectedType == 0)
        newAccount = new JariAccount();
    else if (selectedType == 1)
        newAccount = new LongTermAccount();
    else if (selectedType == 2)
        newAccount = new GharzolHasanehAccount();
    else {
        QMessageBox::warning(this, "ERROR", "Chise a type.");
        return;
    }

    newAccount->setAccount(CURRENT_COSTUMER->getNationalCode());
    CURRENT_COSTUMER->setAccount(newAccount);
    ACCOUNTS.add(newAccount);
    CURRENT_ACCOUNT = newAccount;

    showAccountInfo();
    QMessageBox::information(this, "SUCCESS", "New account added.");
}

void AddCardWindow::showAccountInfo()
{

    QString info;
    info += "Account Type: " + QString::fromStdString(CURRENT_ACCOUNT->accountType()) + "\n";
    info += "Card Number: " + QString::fromStdString(CURRENT_ACCOUNT->getCardNumber()) + "\n";
    info += "Account Number: " + QString::fromStdString(CURRENT_ACCOUNT->getAccountNumber()) + "\n";
    info += "Shaba Number: " + QString::fromStdString(CURRENT_ACCOUNT->getShabaNumber()) + "\n";
    info += "CVV2: " + QString::fromStdString(CURRENT_ACCOUNT->getCVV2()) + "\n";
    info += "Expiration Date: " + QString::fromStdString(CURRENT_ACCOUNT->getExpirationDate()) + "\n";
    info += "Balance: " + QString::number(CURRENT_ACCOUNT->getBalance()) + "\n";


    ui->cardInfoBox->setPlainText(info);
}


