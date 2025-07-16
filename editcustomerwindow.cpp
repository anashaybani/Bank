#include "editcustomerwindow.h"
#include "ui_editcustomerwindow.h"
#include <QString>

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/User.h"
#include "../Bank/Bank/Costumer.h"

EditCustomerWindow::EditCustomerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCustomerWindow)
{
    ui->setupUi(this);

    ui->firstNameEdit->setPlaceholderText(QString::fromStdString(CURRENT_COSTUMER->getFirstName()));
    ui->lastNameEdit->setPlaceholderText(QString::fromStdString(CURRENT_COSTUMER->getLastName()));
    ui->passwordEdit->setPlaceholderText(QString::fromStdString(CURRENT_COSTUMER->getPassword()));
    connect(ui->closeButton, &QPushButton::clicked, this, &EditCustomerWindow::on_closeButton_clicked);
}

EditCustomerWindow::~EditCustomerWindow()
{
    delete ui;
}


void EditCustomerWindow::on_saveButton_clicked()
{
    QString f = ui->firstNameEdit->text();
    QString l = ui->lastNameEdit->text();
    QString p = ui->passwordEdit->text();

    if (!f.isEmpty())
        CURRENT_COSTUMER->setFirstName(f.toStdString());

    if (!l.isEmpty())
        CURRENT_COSTUMER->setLastName(l.toStdString());

    if (!p.isEmpty())
        CURRENT_COSTUMER->setPassword(p.toStdString());


}


void EditCustomerWindow::on_closeButton_clicked()
{
    this->close();
}
