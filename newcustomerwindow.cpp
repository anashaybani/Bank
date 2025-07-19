#include "newcustomerwindow.h"
#include "ui_newcustomerwindow.h"

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Costumer.h"
#include <QMessageBox>
#include "customeroptionswindow.h"

NewCustomerWindow::NewCustomerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewCustomerWindow)
{
    ui->setupUi(this);

    connect(ui->createButton, &QPushButton::clicked, this, &NewCustomerWindow::on_createButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &NewCustomerWindow::on_closeButton_clicked);
}

NewCustomerWindow::~NewCustomerWindow()
{
    delete ui;
}



void NewCustomerWindow::on_createButton_clicked()
{
    QString fname = ui->firstNameEdit->text();
    QString lname = ui->lastNameEdit->text();
    int age = ui->ageEdit->text().toInt();
    QString ID = ui->nationalCodeEdit->text();
    QString pass = ui->passwordEdit->text();

    if (fname.isEmpty() || lname.isEmpty() || pass.isEmpty() || ID.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "Empty field ! ");
        return;
    }

    Costumer* newC = new Costumer;
    newC->setFirstName(fname.toStdString());
    newC->setLastName(lname.toStdString());
    newC->setAge(age);
    newC->setPassword(pass.toStdString());
    newC->setNationalCode(ID.toStdString());
    newC->setUsername(ID.toStdString());

    COSTUMERS.add(newC);
    CURRENT_COSTUMER = newC;

    QMessageBox::information(this, "SUCCESS", "Customer added ");
    CustomerOptionsWindow* options = new CustomerOptionsWindow();
    options->show();
    this->close();
}



void NewCustomerWindow::on_closeButton_clicked()
{
    this->close();
}
