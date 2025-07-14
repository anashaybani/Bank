#include "viewcardswindow.h"
#include "ui_viewcardswindow.h"


ViewCardsWindow::ViewCardsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewCardsWindow)
{
    ui->setupUi(this);


    // پاک کردن جدول (اگه چیزی داشت)
    ui->cardsTable->clearContents();
    ui->cardsTable->setRowCount(0);

    if (CURRENT_COSTUMER && CURRENT_COSTUMER->getAccountCount() > 0) {
        int count = CURRENT_COSTUMER->getAccountCount();
        ui->cardsTable->setRowCount(count);

        for (int i = 0; i < count; ++i) {
            Account* acc = CURRENT_COSTUMER->getAccount(i);

            QTableWidgetItem* typeItem = new QTableWidgetItem(QString::fromStdString(acc->accountType()));
            QTableWidgetItem* cardItem = new QTableWidgetItem(QString::fromStdString(acc->getCardNumber()));
             QTableWidgetItem* balanceItem = new QTableWidgetItem(QString::number(acc->getBalance()));

            ui->cardsTable->setItem(i, 0, typeItem);
            ui->cardsTable->setItem(i, 1, cardItem);
            ui->cardsTable->setItem(i, 2, balanceItem);
        }
    } else {
        ui->cardsTable->setRowCount(1);
        ui->cardsTable->setItem(0, 0, new QTableWidgetItem("حسابی"));
        ui->cardsTable->setItem(0, 1, new QTableWidgetItem("ندارید"));
        ui->cardsTable->setItem(0, 2, new QTableWidgetItem("ندارید"));
    }

}

ViewCardsWindow::~ViewCardsWindow()
{
    delete ui;
}

void ViewCardsWindow::on_closeButton_clicked()
{
    this->close();
}

