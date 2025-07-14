#include "viewcustomerwindow.h"
#include "ui_viewcustomerwindow.h"

ViewCustomerWindow::ViewCustomerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewCustomerWindow)
{
    ui->setupUi(this);

    fillUserFields();

    connect(ui->closeButton, &QPushButton::clicked, this, &ViewCustomerWindow::on_closeButton_clicked);

}

ViewCustomerWindow::~ViewCustomerWindow()
{
    delete ui;
}


#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/User.h"
#include "../Bank/Bank/Costumer.h"

void ViewCustomerWindow::fillUserFields()
{
    ui->firstNameLabel->setText(QString::fromStdString(CURRENT_COSTUMER->getFirstName()));
    ui->lastNameLabel->setText(QString::fromStdString(CURRENT_COSTUMER->getLastName()));
    ui->nationalCodeLabel->setText(QString::fromStdString(CURRENT_COSTUMER->getNationalCode()));
    ui->ageLabel->setText(QString::number(CURRENT_COSTUMER->getAge()));
    ui->usernameLabel->setText(QString::fromStdString(CURRENT_COSTUMER->getUsername()));
    ui->passwordLabel->setText(QString::fromStdString(CURRENT_COSTUMER->getPassword()));
    ui->accountCountLabel->setText(QString::number(CURRENT_COSTUMER->getAccountCount()));

}


void ViewCustomerWindow::on_closeButton_clicked()
{
    this->close();
}
