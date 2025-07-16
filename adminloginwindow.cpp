#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"
#include "adminmainwindow.h"



AdminLoginWindow::AdminLoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminLoginWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &AdminLoginWindow::handleLogin);
    connect(ui->closeButton, &QPushButton::clicked, this, &AdminLoginWindow::on_closeButton_clicked);
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
    Admin* ana = new Admin();
    ana->setFirstName("ana");
    ana->setLastName("sh");
    ana->setAge(19);
    ana->setNationalCode("1");
    ana->setUsername("1");
    ana->setPassword("1");
    ADMINS.add(ana);

    QString card = ui->userLineEdit->text();
    QString pass = ui->passLineEdit->text();



    Admin* a1 = ADMINS.search(card.toStdString());
     CURRENT_ADMIN = a1;

    if (a1 && a1->getPassword() == pass.toStdString()) {
        QMessageBox::information(this, "SUCCESS", "Logging in");
        this->close();

        AdminMainWindow* win = new AdminMainWindow( );
        win->show();


    } else {
        QMessageBox::warning(this, "ERROR", "Not found");
    }

}





void AdminLoginWindow::on_closeButton_clicked()
{
    this->close();
}

