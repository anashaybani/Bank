#include "viewcardswindow.h"
#include "ui_viewcardswindow.h"

#include "showaccountinfo.h"

#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/JariAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/globals.h"

#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>


ViewCardsWindow::ViewCardsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewCardsWindow)
{
    ui->setupUi(this);

    CURRENT_ACCOUNT = nullptr;

    radioGroup = new QButtonGroup(this);

    radioGroup->setExclusive(true);

    ui->cardsTable->clearContents();
    ui->cardsTable->setRowCount(0);
    ui->cardsTable->setColumnCount(4);

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

    connect(ui->closeButton, &QPushButton::clicked, this, &ViewCardsWindow::on_closeButton_clicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &ViewCardsWindow::on_nextButton_clicked);
}

ViewCardsWindow::~ViewCardsWindow()
{
    delete ui;
}


void ViewCardsWindow::on_nextButton_clicked() {
    int selectedId = radioGroup->checkedId();
    if (selectedId == -1) {
        QMessageBox::warning(this, "Error", "Please select a card.");
        return;
    }

     CURRENT_ACCOUNT= CURRENT_COSTUMER->getAccount(selectedId);

    ShowAccountInfo* cardWin = new ShowAccountInfo();
    cardWin->show();
    this->close();
}



void ViewCardsWindow::on_closeButton_clicked()
{
    this->close();
}

