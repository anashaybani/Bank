#include "customeroptionswindow.h"
#include "ui_customeroptionswindow.h"

CustomerOptionsWindow::CustomerOptionsWindow( QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerOptionsWindow)
{
    ui->setupUi(this);

    connect(ui->customerButton, &QPushButton::clicked, this, &CustomerOptionsWindow::handleCustomer);
    connect(ui->cardButton, &QPushButton::clicked, this, &CustomerOptionsWindow::handleCard);
    connect(ui->closeButton, &QPushButton::clicked, this, &CustomerOptionsWindow::on_closeButton_clicked);
}

CustomerOptionsWindow::~CustomerOptionsWindow()
{
    delete ui;
}



#include "customereditwindow.h"
#include "accounteditwindow.h"
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Costumer.h"



void CustomerOptionsWindow::handleCustomer() {
    CustomerEditWindow* win = new CustomerEditWindow( );
    win->show();
}

void CustomerOptionsWindow::handleCard() {
    AccountEditWindow* win = new AccountEditWindow( );
    win->show();
}


void CustomerOptionsWindow::on_closeButton_clicked()
{
    this->close();
}
