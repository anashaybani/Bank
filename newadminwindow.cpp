#include "newadminwindow.h"
#include "ui_newadminwindow.h"

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Admin.h"
#include <QMessageBox>

NewAdminWindow::NewAdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewAdminWindow)
{
    ui->setupUi(this);
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

    if (fname.isEmpty() || lname.isEmpty() || pass.isEmpty()) {
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

    QMessageBox::information(this, "SUCCESS", "Customer added ");
    this->accept();
}
