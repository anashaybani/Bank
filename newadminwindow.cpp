#include "newadminwindow.h"
#include "ui_newadminwindow.h"

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Admin.h"
#include <QMessageBox>
#include "adminoptionswindow.h"

NewAdminWindow::NewAdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewAdminWindow)
{
    ui->setupUi(this);

     connect(ui->createButton, &QPushButton::clicked, this, &NewAdminWindow::on_createButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &NewAdminWindow::on_closeButton_clicked);
}

NewAdminWindow::~NewAdminWindow()
{
    delete ui;
}


void NewAdminWindow::on_createButton_clicked()
{
    QString fname = ui->firstNameEdit->text();
    QString lname = ui->lastNameEdit->text();
    int age = ui->ageEdit->text().toInt();
    QString ID = ui->nationalCodeEdit->text();
    QString pass = ui->passwordEdit->text();

    if (fname.isEmpty() || lname.isEmpty() || pass.isEmpty()|| ID.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "Empty field ! ");
        return;
    }

    Admin* newC = new Admin;
    newC->setFirstName(fname.toStdString());
    newC->setLastName(lname.toStdString());
    newC->setAge(age);
    newC->setPassword(pass.toStdString());
    newC->setNationalCode(ID.toStdString());
    newC->setUsername(ID.toStdString());

    ADMINS.add(newC);
    SECOND_ADMIN = newC;

    QMessageBox::information(this, "SUCCESS", "Customer added ");
    AdminOptionsWindow* options = new AdminOptionsWindow();
    options->show();
    this->close();
}



void NewAdminWindow::on_closeButton_clicked()
{
    this->close();
}
