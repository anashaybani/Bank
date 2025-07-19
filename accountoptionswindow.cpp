#include "accountoptionswindow.h"
#include "ui_accountoptionswindow.h"


#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/Costumer.h"
#include <QMessageBox>

AccountOptionsWindow::AccountOptionsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountOptionsWindow)
{
    ui->setupUi(this);


    ui->pinCodeEdit->setPlaceholderText(QString::fromStdString(CURRENT_ACCOUNT->getPinCode()));
    ui->secondPasswordEdit->setPlaceholderText(QString::fromStdString(CURRENT_ACCOUNT->getStaticSecondPassword()));
    ui->balanceEdit->setPlaceholderText(QString::number(CURRENT_ACCOUNT->getBalance()));

    connect(ui->closeButton, &QPushButton::clicked, this, &AccountOptionsWindow::on_closeButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &AccountOptionsWindow::on_saveButton_clicked);

}

AccountOptionsWindow::~AccountOptionsWindow()
{
    delete ui;
}


void AccountOptionsWindow::on_saveButton_clicked()
{
    QString f = ui->pinCodeEdit->text();
    QString l = ui->secondPasswordEdit->text();
    QString p = ui->balanceEdit->text();


    if(CURRENT_ADMIN == nullptr)
        QMessageBox::information(this, "WORNNING", "Do not have access to balance");

    if (!f.isEmpty())
        CURRENT_ACCOUNT->setPinCode(f.toStdString());

    if (!l.isEmpty())
        CURRENT_ACCOUNT->setStaticSecondPassword(l.toStdString());

    if (!p.isEmpty() && CURRENT_ADMIN != nullptr)
        CURRENT_ACCOUNT->setBalance(p.toDouble());


    this->close();
}


void AccountOptionsWindow::on_closeButton_clicked()
{
    this->close();
}
