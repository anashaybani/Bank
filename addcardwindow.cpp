#include "addcardwindow.h"
#include "ui_addcardwindow.h"

#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/JariAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/globals.h"
#include "showaccountinfo.h"
#include <QMessageBox>


AddCardWindow::AddCardWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCardWindow)
{
    ui->setupUi(this);


    connect(ui->addCardButton, &QPushButton::clicked, this, &AddCardWindow::on_addCardButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &AddCardWindow::on_closeButton_clicked);


}

AddCardWindow::~AddCardWindow()
{
    delete ui;
}



void AddCardWindow::on_addCardButton_clicked()
{

    Account* newAccount = nullptr;

    int selectedType = ui->accountTypeCombo->currentIndex();

    if (selectedType == 0)
        newAccount = new GharzolHasanehAccount();
    else if (selectedType == 1)
        newAccount = new LongTermAccount();
    else if (selectedType == 2)
        newAccount = new JariAccount();
    else {
        QMessageBox::warning(this, "ERROR", "Chise a type.");
        return;
    }

    newAccount->setAccount(CURRENT_COSTUMER->getNationalCode(), CURRENT_COSTUMER->getAccountCount() );
    CURRENT_COSTUMER->setAccount(newAccount);
    ACCOUNTS.add(newAccount);
    CURRENT_ACCOUNT = newAccount;

    ShowAccountInfo* win = new ShowAccountInfo( );
    win->show();
    this->close();
    //QMessageBox::information(this, "SUCCESS", "New account added.");
}




void AddCardWindow::on_closeButton_clicked()
{
    this->close();
}

