#include "editcardswindow.h"
#include "ui_editcardswindow.h"


#include <QMessageBox>
#include <QInputDialog>

EditCardsWindow::EditCardsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCardsWindow)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &EditCardsWindow::on_closeButton_clicked);
    

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


EditCardsWindow::~EditCardsWindow()
{
    delete ui;
}


void EditCardsWindow::on_editSelectedButton_clicked()
{
    int row = ui->cardsTable->currentRow();

    if (row < 0 || row >= CURRENT_COSTUMER->getAccountCount()) {
        QMessageBox::warning(this, "ERROR", "No card selected!");
        return;
    }

    Account* acc = CURRENT_COSTUMER->getAccount(row -1);

    bool ok;
    QStringList items;
    items << "pin code" << "second password";

    QString choice = QInputDialog::getItem(this, "SELECT", "chose a field ", items, 0, false, &ok);

    if (ok && !choice.isEmpty()) {
        if (choice == "pin code") {
            QString newPin = QInputDialog::getText(this, "NEW PASS", "Enter new pin code:", QLineEdit::Password, "", &ok);
            if (ok) {
                acc->setPinCode(newPin.toStdString());
                QMessageBox::information(this, "SUCCESS", "Pin code edited.");
            }
        } else if (choice == "second password") {
            QString newPass = QInputDialog::getText(this, "NEW PASS", "Enter new second password:", QLineEdit::Password, "", &ok);
            if (ok) {
                acc->setStaticSecondPassword(newPass.toStdString());
                QMessageBox::information(this, "SUCCESS", "Second password edited.");
            }
        }
    }
}




void EditCardsWindow::on_deleteSelectedButton_clicked()
{
    int row = ui->cardsTable->currentRow();

    if (row < 0 || row >= CURRENT_COSTUMER->getAccountCount()) {
        QMessageBox::warning(this, "ERROR", "No card selected!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "WORNNING", "delete account ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        CURRENT_COSTUMER->deleteAccounts(row - 1);

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

