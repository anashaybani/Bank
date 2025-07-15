#include "editadminwindow.h"
#include "ui_editadminwindow.h"

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/User.h"
#include "../Bank/Bank/Admin.h"

EditAdminWindow::EditAdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditAdminWindow)
{
    ui->setupUi(this);

    ui->firstNameEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getFirstName()));
    ui->lastNameEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getLastName()));
    ui->passwordEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getPassword()));
}

EditAdminWindow::~EditAdminWindow()
{
    delete ui;
}




void EditAdminWindow::on_saveButton_clicked()
{
    QString f = ui->firstNameEdit->text();
    QString l = ui->lastNameEdit->text();
    QString p = ui->passwordEdit->text();

    if (!f.isEmpty())
        SECOND_ADMIN->setFirstName(f.toStdString());

    if (!l.isEmpty())
        SECOND_ADMIN->setLastName(l.toStdString());

    if (!p.isEmpty())
        SECOND_ADMIN->setPassword(p.toStdString());

    this->accept();
}
