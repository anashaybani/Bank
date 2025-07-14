#include "customereditwindow.h"
#include "ui_customereditwindow.h"

CustomerEditWindow::CustomerEditWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerEditWindow)
{
    ui->setupUi(this);


    connect(ui->editButton, &QPushButton::clicked, this, &CustomerEditWindow::openEditCustomerPage);
    connect(ui->viewButton, &QPushButton::clicked, this, &CustomerEditWindow::openViewCustomerPage);

}

CustomerEditWindow::~CustomerEditWindow()
{
    delete ui;
}

#include "ViewCustomerWindow.h"
#include "EditCustomerWindow.h"
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/Admin.h"
#include "../Bank/Bank/Costumer.h"
#include <QMessageBox>


void CustomerEditWindow::openViewCustomerPage(){
    ViewCustomerWindow * viewWin = new ViewCustomerWindow(this);
    viewWin->exec();
    delete viewWin;
}

void CustomerEditWindow::openEditCustomerPage(){
    EditCustomerWindow * editWin = new EditCustomerWindow(this);
    editWin->exec();
    delete editWin;
}

void CustomerEditWindow::on_deleteButton_clicked()
{

    CURRENT_COSTUMER->delete_all_Accounts();

    COSTUMERS.remove(CURRENT_COSTUMER->getNationalCode());

    QMessageBox::information(this, "DELETED", "Customer removed ! ");

    this->close();
}

