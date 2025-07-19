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
    connect(ui->closeButton, &QPushButton::clicked, this, &CustomerLoginWindow::on_closeButton_clicked);

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
        QMessageBox::information(this, "SUCCESS", "logging in");
        CURRENT_ADMIN = nullptr;
        CustomerMainWindow* mainWin = new CustomerMainWindow;
        mainWin->show();


    } else {
        QMessageBox::warning(this, "ERROR", "Not found");
    }
}



void CustomerLoginWindow::on_closeButton_clicked()
{
    this->close();
}
