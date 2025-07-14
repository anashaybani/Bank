#include "transferwindow.h"
#include "ui_transferwindow.h"
#include <QMessageBox>
#include "../Bank/Bank/globals.h"


TransferWindow::TransferWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransferWindow)
{
    ui->setupUi(this);
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
        ui->statusLabel->setText("کارت مبدا پیدا نشد!");
        return;
    }

    if (origin->getCVV2() != cvv2.toStdString()) {
        ui->statusLabel->setText("CVV2 اشتباه است!");
        return;
    }

    Account* dest = ACCOUNTS.search(destCard.toStdString());
    if (!dest) {
        ui->statusLabel->setText("کارت مقصد پیدا نشد!");
        return;
    }

    if (date.toStdString() > origin->getExpirationDate()) {
        ui->statusLabel->setText("کارت منقضی شده!");
        return;
    }

    double total = amount * 1.01;
    CardToCard temp;
    temp.setoriginCardNum(originCard.toStdString()) ;
    temp.setdate(date.toStdString());

    CardToCard* recent = CardToCardS.search(temp.display());
    if (amount > 3000000 || total > origin->getBalance() || (recent && recent->getAmount() + amount > 6000000)) {
        ui->statusLabel->setText("مبلغ بیش از حد مجاز یا موجودی ناکافی!");
        return;
    }

    if (amount <= 100000) {
        if (password.toStdString() != origin->getStaticSecondPassword()) {
            ui->statusLabel->setText("رمز دوم اشتباه است!");
            return;
        }
    } else {
        std::string dynPass = origin->generateRandomDigits(6);
        origin->setDynamicSecondPassword(dynPass);
        QMessageBox::information(this, "رمز پویا", QString::fromStdString("رمز دوم پویا: " + dynPass));
        if (password.toStdString() != dynPass) {
            ui->statusLabel->setText("رمز پویا اشتباه است!");
            return;
        }
    }

    origin->setBalance(origin->getBalance() - total);
    dest->setBalance(dest->getBalance() + amount);

    // ثبت تراکنش در لیست
    CardToCard* transaction = new CardToCard();
    transaction->setoriginCardNum(originCard.toStdString());
    transaction->setdate(date.toStdString());
    // بهتره این مقدارها رو کامل‌تر هم تنظیم کنی
    // مثلاً amount و destinationCardNum:
    transaction->setamount(amount); // اگر نیاز شد، setter بنویس
    // یا اگر خواستی destinationCardNum رو هم ذخیره کنی، باید setter برایش بنویسی
    CardToCardS.add(transaction);


    ui->statusLabel->setText("انتقال با موفقیت انجام شد.");
}
