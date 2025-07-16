#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"


//#include "customereditwindow.h"
//#include "admineditwindow.h"




AdminMainWindow::AdminMainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);

    connect(ui->proceedButton, &QPushButton::clicked, this, &AdminMainWindow::handleProceed);
    connect(ui->closeButton, &QPushButton::clicked, this, &AdminMainWindow::on_closeButton_clicked);

}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}


#include "../Bank/Bank/globals.h"
#include "customeroptionswindow.h"
#include "newcustomerwindow.h"
#include "adminoptionswindow.h"
#include "newadminwindow.h"
#include <QMessageBox>



void AdminMainWindow::handleProceed() {
    QString userType = ui->userTypeCombo->currentText();
    QString id = ui->idLineEdit->text();

            if (id.isEmpty()) {
                QMessageBox::warning(this, "ERROR", "Enter user ID");
                return;
            }

            if (userType == "Customer") {
                Costumer* c = COSTUMERS.search(id.toStdString());
                if (c) {
                    CURRENT_COSTUMER = c;
                    CustomerOptionsWindow* options = new CustomerOptionsWindow();
                    options->show();
                } else {

                    NewCustomerWindow* newCust = new NewCustomerWindow();
                    newCust->show();
                }
            }
            else if (userType == "Admin") {
                Admin* a = ADMINS.search(id.toStdString());
                if (a) {
                    SECOND_ADMIN = a;

                    AdminOptionsWindow* options = new AdminOptionsWindow();
                    options->show();
                } else {
                    NewAdminWindow* newAdmin = new NewAdminWindow();
                    newAdmin->show();
                }
            }


}



void AdminMainWindow::on_closeButton_clicked()
{
    this->close();
}
