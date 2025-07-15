#include "showadminwindow.h"
#include "ui_showadminwindow.h"

ShowAdminWindow::ShowAdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowAdminWindow)
{
    ui->setupUi(this);

    fillUserFields();

    connect(ui->closeButton, &QPushButton::clicked, this, &ShowAdminWindow::on_closeButton_clicked);

}

ShowAdminWindow::~ShowAdminWindow()
{
    delete ui;
}




#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Admin.h"

void ShowAdminWindow::fillUserFields()
{
    ui->firstNameLabel->setText(QString::fromStdString(SECOND_ADMIN->getFirstName()));
    ui->lastNameLabel->setText(QString::fromStdString(SECOND_ADMIN->getLastName()));
    ui->nationalCodeLabel->setText(QString::fromStdString(SECOND_ADMIN->getNationalCode()));
    ui->ageLabel->setText(QString::number(SECOND_ADMIN->getAge()));
    ui->usernameLabel->setText(QString::fromStdString(SECOND_ADMIN->getUsername()));
    ui->passwordLabel->setText(QString::fromStdString(SECOND_ADMIN->getPassword()));

}


void ShowAdminWindow::on_closeButton_clicked()
{
    this->close();
}
