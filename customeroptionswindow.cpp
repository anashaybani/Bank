#include "customeroptionswindow.h"
#include "ui_customeroptionswindow.h"

CustomerOptionsWindow::CustomerOptionsWindow( QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerOptionsWindow)
{
    ui->setupUi(this);

    connect(ui->customerButton, &QPushButton::clicked, this, &CustomerOptionsWindow::handleCustomer);
    connect(ui->cardButton, &QPushButton::clicked, this, &CustomerOptionsWindow::handleCard);
}

CustomerOptionsWindow::~CustomerOptionsWindow()
{
    delete ui;
}



#include "customereditwindow.h"
#include "accounteditwindow.h"
#include "../Bank/Bank/globals.h"



void CustomerOptionsWindow::handleCustomer() {
    CustomerEditWindow* win = new CustomerEditWindow(customer, this);
    win->show();
}

void CustomerOptionsWindow::handleCard() {
    AccountEditWindow* win = new AccountEditWindow(customer, this);
    win->show();
}

