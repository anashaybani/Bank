#include "customerloginwindow.h"
#include "ui_customerloginwindow.h"
#include "customermainwindow.h"

#include <QMessageBox>
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Costumer.h"


CustomerLoginWindow::CustomerLoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerLoginWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &CustomerLoginWindow::handleLogin);

}

CustomerLoginWindow::~CustomerLoginWindow()
{
    delete ui;
}


void CustomerLoginWindow::handleLogin()
{
    QString username = ui->userLineEdit->text();
    QString password = ui->passLineEdit->text();

    Costumer* c = COSTUMERS.search(username.toStdString());
    CURRENT_COSTUMER = c;

    if (c && c->getPassword() == password.toStdString()) {
        QMessageBox::information(this, "موفق", "ورود موفقیت‌آمیز بود");
        CustomerMainWindow* mainWin = new CustomerMainWindow;
        mainWin->show();
        this->close();

    } else {
        QMessageBox::warning(this, "خطا", "اطلاعات اشتباه است");
    }
}
