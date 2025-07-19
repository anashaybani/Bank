#include "editcardswindow.h"
#include "ui_editcardswindow.h"
#include "accountoptionswindow.h"

#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/JariAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/globals.h"

#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>
#include <QInputDialog>

EditCardsWindow::EditCardsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCardsWindow)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &EditCardsWindow::on_closeButton_clicked);
    connect(ui->editSelectedButton, &QPushButton::clicked, this, &EditCardsWindow::on_editSelectedButton_clicked);
    connect(ui->deleteSelectedButton, &QPushButton::clicked, this, &EditCardsWindow::on_deleteSelectedButton_clicked);


    CURRENT_ACCOUNT = nullptr;

    radioGroup = new QButtonGroup(this);

    radioGroup->setExclusive(true);

    ui->cardsTable->clearContents();
    ui->cardsTable->setRowCount(0);
    ui->cardsTable->setColumnCount(3);

    if (CURRENT_COSTUMER && CURRENT_COSTUMER->getAccountCount() > 0) {
        int count = CURRENT_COSTUMER->getAccountCount();
        ui->cardsTable->setRowCount(count);

        for (int i = 0; i < count; ++i) {
            Account* acc = CURRENT_COSTUMER->getAccount(i);

            QTableWidgetItem* typeItem = new QTableWidgetItem(QString::fromStdString(acc->accountType()));
            QTableWidgetItem* cardItem = new QTableWidgetItem(QString::fromStdString(acc->getCardNumber()));

            ui->cardsTable->setItem(i, 1, typeItem);
            ui->cardsTable->setItem(i, 2, cardItem);

            QRadioButton* radio = new QRadioButton();
            radioGroup->addButton(radio, i);
            ui->cardsTable->setCellWidget(i, 0, radio);

            connect(radio, &QRadioButton::toggled, this, [=](bool checked){
                if (checked) {
                    CURRENT_ACCOUNT = acc;
                }
            });
        }
    } else {
        ui->cardsTable->setRowCount(1);
        ui->cardsTable->setItem(0, 1, new QTableWidgetItem("No Account"));
    }




}


EditCardsWindow::~EditCardsWindow()
{
    delete ui;
}



void EditCardsWindow::on_editSelectedButton_clicked()
{

    int selectedId = radioGroup->checkedId();
    if (selectedId == -1) {
        QMessageBox::warning(this, "Error", "Please select a card.");
        return;
    }

    CURRENT_ACCOUNT= CURRENT_COSTUMER->getAccount(selectedId);

    AccountOptionsWindow* cardWin = new AccountOptionsWindow();
    cardWin->show();
    this->close();
}




void EditCardsWindow::on_deleteSelectedButton_clicked()
{
    int selectedId = radioGroup->checkedId();
    if (selectedId == -1) {
        QMessageBox::warning(this, "Error", "Please select a card.");
        return;
    }

    else if (CURRENT_ADMIN == nullptr) {
        QMessageBox::warning(this, "Error", "You do not have access.");
        return;
    }

    else{

        CURRENT_ACCOUNT= CURRENT_COSTUMER->getAccount(selectedId);
        CURRENT_COSTUMER->deleteAccounts(selectedId);
        ACCOUNTS.remove(CURRENT_ACCOUNT->getAccountNumber());
        CURRENT_ACCOUNT= nullptr;

        QMessageBox::information(this, "DELETED", "Account deleted.");

        EditCardsWindow* newWindow = new EditCardsWindow(this->parentWidget());
        newWindow->show();
        this->close();
    }

}



void EditCardsWindow::on_closeButton_clicked()
{
    this->close();
}

