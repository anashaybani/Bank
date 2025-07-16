#include "loginselectorwindow.h"
#include "ui_loginselectorwindow.h"
#include "customerloginwindow.h"
#include "adminloginwindow.h"

LoginSelectorWindow::LoginSelectorWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginSelectorWindow)
{
    ui->setupUi(this);

    connect(ui->customerButton, &QPushButton::clicked, this, &LoginSelectorWindow::openCustomerLogin);
    connect(ui->adminButton, &QPushButton::clicked, this, &LoginSelectorWindow::openAdminLogin);
}

LoginSelectorWindow::~LoginSelectorWindow()
{
    delete ui;
}

void LoginSelectorWindow::openCustomerLogin()
{
    CustomerLoginWindow *login = new CustomerLoginWindow();
    login->show();
}

void LoginSelectorWindow::openAdminLogin()
{
    AdminLoginWindow *login = new AdminLoginWindow();
    login->show();
}


