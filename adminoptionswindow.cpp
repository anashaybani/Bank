#include "adminoptionswindow.h"
#include "ui_adminoptionswindow.h"
#include "editadminwindow.h"
#include "showadminwindow.h"

AdminOptionsWindow::AdminOptionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminOptionsWindow)
{
    ui->setupUi(this);
}

AdminOptionsWindow::~AdminOptionsWindow()
{
    delete ui;
}


#include "../Bank/Bank/globals.h"
#include <QMessageBox>


void AdminOptionsWindow::on_editButton_clicked()
{
    EditAdminWindow* editWin = new EditAdminWindow( this);
    editWin->show();
    this->close();
}

void AdminOptionsWindow::on_showButton_clicked()
{
    ShowAdminWindow* infoWin = new ShowAdminWindow( this);
    infoWin->show();
    this->close();
}

void AdminOptionsWindow::on_deleteButton_clicked()
{
    ADMINS.remove(SECOND_ADMIN->getNationalCode());
    QMessageBox::information(this, "DELETED", "Customer removed ! ");

    this->close();
}
