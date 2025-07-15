#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"

AdminLoginWindow::AdminLoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminLoginWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &AdminLoginWindow::handleLogin);

}

AdminLoginWindow::~AdminLoginWindow()
{
    delete ui;
}



#include <QMessageBox>
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Admin.h"

void AdminLoginWindow::handleLogin()
{
    QString card = ui->userLineEdit->text();
    QString pass = ui->passLineEdit->text();

    Admin ana;
    ana.setFirstName("ana");
    ana.setLastName("sh");
    ana.setNationalCode("1");
    ana.setUsername(ana.getNationalCode());
    ana.setPassword("1");
    ADMINS.add(&ana);



    Admin* a1 = ADMINS.search(card.toStdString());
     CURRENT_ADMIN = a1;

    if (a1 && a1->getPassword() == pass.toStdString()) {
        QMessageBox::information(this, "SUCCESS", "Logging in");
        accept();
    } else {
        QMessageBox::warning(this, "ERROR", "Not found");
    }
}

