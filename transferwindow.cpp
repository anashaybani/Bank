#include "transferwindow.h"
#include "ui_transferwindow.h"
#include <QMessageBox>
#include "../Bank/Bank/globals.h"


TransferWindow::TransferWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransferWindow)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &TransferWindow::on_closeButton_clicked);
}

TransferWindow::~TransferWindow()
{
    delete ui;

}


void TransferWindow::on_transferButton_clicked()
{
    QString originCard = ui->originCardEdit->text();
    QString cvv2 = ui->cvv2Edit->text();
    QString destCard = ui->destCardEdit->text();
    QString date = ui->dateEdit->text();
    double amount = ui->amountEdit->text().toDouble();
    QString password = ui->passwordEdit->text();

    Account* origin = ACCOUNTS.search(originCard.toStdString());
    if (!origin) {
        ui->statusLabel->setText("Orgin card not found!");
        return;
    }

    if (origin->getCVV2() != cvv2.toStdString()) {
        ui->statusLabel->setText("Incorrect CVV2 !");
        return;
    }

    Account* dest = ACCOUNTS.search(destCard.toStdString());
    if (!dest) {
        ui->statusLabel->setText("Destination card not found!");
        return;
    }

    if (date.toStdString() > origin->getExpirationDate()) {
        ui->statusLabel->setText("orgin card expired !");
        return;
    }

    double total = amount * 1.01;
    CardToCard temp;
    temp.setoriginCardNum(originCard.toStdString()) ;
    temp.setdate(date.toStdString());

    CardToCard* recent = CardToCardS.search(temp.display());
    if (amount > 3000000 || total > origin->getBalance() || (recent && recent->getAmount() + amount > 6000000)) {
        ui->statusLabel->setText("Amount over limit or balance!");
        return;
    }

    if (amount <= 100000) {
        if (password.toStdString() != origin->getStaticSecondPassword()) {
            ui->statusLabel->setText("Incorrect password!");
            return;
        }
    } else {
        std::string dynPass = origin->generateRandomDigits(6);
        origin->setDynamicSecondPassword(dynPass);
        QMessageBox::information(this, "Dynamic", QString::fromStdString("Dynamic password: " + dynPass));
        if (password.toStdString() != dynPass) {
            ui->statusLabel->setText("Incorrect password!");
            return;
        }
    }

    origin->setBalance(origin->getBalance() - total);
    dest->setBalance(dest->getBalance() + amount);


    CardToCard* transaction = new CardToCard();
    transaction->setoriginCardNum(originCard.toStdString());
    transaction->setdate(date.toStdString());


    transaction->setamount(amount);
    CardToCardS.add(transaction);


    ui->statusLabel->setText("Successful transaction.");
}





void TransferWindow::on_closeButton_clicked()
{
    this->close();
}
