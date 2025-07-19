#include "editadminwindow.h"
#include "ui_editadminwindow.h"

#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/User.h"
#include "../Bank/Bank/Admin.h"
#include <QMessageBox>

EditAdminWindow::EditAdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditAdminWindow)
{
    ui->setupUi(this);

    ui->firstNameEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getFirstName()));
    ui->lastNameEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getLastName()));
    ui->passwordEdit->setPlaceholderText(QString::fromStdString(SECOND_ADMIN->getPassword()));
    connect(ui->closeButton, &QPushButton::clicked, this, &EditAdminWindow::on_closeButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &EditAdminWindow::on_saveButton_clicked);
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

    QMessageBox::information(this, "SUCCESS", "saved");
    this->close();
}



void EditAdminWindow::on_closeButton_clicked()
{
    this->close();
}
