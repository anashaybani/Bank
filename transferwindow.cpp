#include "transferwindow.h"
#include "ui_transferwindow.h"
#include <QMessageBox>
#include "../Bank/Bank/globals.h"


TransferWindow::TransferWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransferWindow)
{
    ui->setupUi(this);

    connect(ui->transferButton, &QPushButton::clicked, this, &TransferWindow::on_transferButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &TransferWindow::on_closeButton_clicked);
}

TransferWindow::~TransferWindow()
{
    delete ui;

}

#include <ctime>

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


    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;


    string expDateStr = origin->getExpirationDate();
    int expYear = stoi(expDateStr.substr(0, 4));
    int expMonth = stoi(expDateStr.substr(5, 2));


    if (currentYear > expYear || (currentYear == expYear && currentMonth > expMonth)) {
        ui->statusLabel->setText("Origin card expired!");
        return;
    }

    string today = to_string(currentYear) + "-" + (currentMonth < 10 ? "0" + to_string(currentMonth) : to_string(currentMonth));

    if (date.toStdString() != origin->getExpirationDate()) {
        ui->statusLabel->setText(" wrong Origin card expire ddate!");
        return;
    }

    double totalToday = CardToCardS.getTotalAmountForCardAndDate(originCard.toStdString(), today);

    double total = amount * 1.01;
    CardToCard temp;
    temp.setoriginCardNum(originCard.toStdString()) ;
    temp.setdate(today);

    if (amount > 3000000 || total > origin->getBalance() || totalToday + amount > 6000000) {
        ui->statusLabel->setText("Amount over limit or balance!");
        return;
    }

    if (amount <= 100000) {
        if (password.toStdString() != origin->getStaticSecondPassword()) {
            ui->statusLabel->setText("Incorrect second password!");
            return;
        }
    } else {
        if (origin->getDynamicSecondPassword().empty()) {
            const string dynPass = origin->generateRandomDigits(5);
            origin->setDynamicSecondPassword(dynPass);
            QMessageBox::information(this, "Dynamic Password", QString::fromStdString("Dynamic password: " + dynPass));
            return;
        }

        if (password.toStdString() != origin->getDynamicSecondPassword()) {
            ui->statusLabel->setText("Incorrect dynamic password!");
            origin->setDynamicSecondPassword("");
            return;
        }

        origin->setDynamicSecondPassword("");
    }


    origin->setBalance(origin->getBalance() - total);
    dest->setBalance(dest->getBalance() + amount);


    CardToCard* transaction = new CardToCard();
    transaction->setoriginCardNum(originCard.toStdString());
    transaction->setdestinationCardNum(destCard.toStdString());
    transaction->setdate(today);
    transaction->setamount(amount);
    CardToCardS.add(transaction);


    QMessageBox::information(this, "SUCCESS","Successful transaction. ");
    this->close();
}





void TransferWindow::on_closeButton_clicked()
{
    this->close();
}
