#include "adminoptionswindow.h"
#include "ui_adminoptionswindow.h"
#include "editadminwindow.h"
#include "showadminwindow.h"

AdminOptionsWindow::AdminOptionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminOptionsWindow)
{
    ui->setupUi(this);


    connect(ui->showButton, &QPushButton::clicked, this, &AdminOptionsWindow::on_showButton_clicked);
    connect(ui->editButton, &QPushButton::clicked, this, &AdminOptionsWindow::on_editButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &AdminOptionsWindow::on_deleteButton_clicked);

    connect(ui->closeButton, &QPushButton::clicked, this, &AdminOptionsWindow::on_closeButton_clicked);
}

AdminOptionsWindow::~AdminOptionsWindow()
{
    delete ui;
}


#include "../Bank/Bank/globals.h"
#include <QMessageBox>


void AdminOptionsWindow::on_editButton_clicked()
{
    EditAdminWindow* editWin = new EditAdminWindow( );
    editWin->show();

}

void AdminOptionsWindow::on_showButton_clicked()
{
    ShowAdminWindow* infoWin = new ShowAdminWindow( );
    infoWin->show();

}

void AdminOptionsWindow::on_deleteButton_clicked()
{
    ADMINS.remove(SECOND_ADMIN->getNationalCode());
    QMessageBox::information(this, "DELETED", "Customer removed ! ");

}


void AdminOptionsWindow::on_closeButton_clicked()
{
    this->close();
}
