#include "showaccountinfo.h"
#include "ui_showaccountinfo.h"

#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/JariAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/globals.h"



ShowAccountInfo::ShowAccountInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowAccountInfo)
{
    ui->setupUi(this);

     //ui->cardInfoBox->setReadOnly(true);
    {
    QString info;
    info += "Account Type: " + QString::fromStdString(CURRENT_ACCOUNT->accountType()) + "\n";
    info += "Card Number: " + QString::fromStdString(CURRENT_ACCOUNT->getCardNumber()) + "\n";
    info += "Account Number: " + QString::fromStdString(CURRENT_ACCOUNT->getAccountNumber()) + "\n";
    info += "Shaba Number: " + QString::fromStdString(CURRENT_ACCOUNT->getShabaNumber()) + "\n";
    info += "Pin Code: " + QString::fromStdString(CURRENT_ACCOUNT->getPinCode()) + "\n";
    info += "Second Password : " + QString::fromStdString(CURRENT_ACCOUNT->getStaticSecondPassword()) + "\n";
    info += "CVV2: " + QString::fromStdString(CURRENT_ACCOUNT->getCVV2()) + "\n";
    info += "Expiration Date: " + QString::fromStdString(CURRENT_ACCOUNT->getExpirationDate()) + "\n";
    info += "Balance: " + QString::number(CURRENT_ACCOUNT->getBalance()) + "\n";


    ui->cardInfoBox->setPlainText(info);
    }
    connect(ui->closeButton, &QPushButton::clicked, this, &ShowAccountInfo::on_closeButton_clicked);
}

ShowAccountInfo::~ShowAccountInfo()
{
    delete ui;
}



void ShowAccountInfo::on_closeButton_clicked()
{
    this->close();
}
