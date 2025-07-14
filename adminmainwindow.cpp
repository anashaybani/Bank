#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

#include "../Bank/Bank/globals.h"
//#include "customereditwindow.h"
//#include "admineditwindow.h"




AdminMainWindow::AdminMainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);

    connect(ui->proceedButton, &QPushButton::clicked, this, &AdminMainWindow::handleProceed);

}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}



#include "customeroptionswindow.h"
#include "newcustomerwindow.h"
#include "adminoptionswindow.h"
#include "newadminwindow.h"
#include <QMessageBox>


void AdminMainWindow::handleProceed() {
    QString userType = ui->userTypeCombo->currentText();
    QString id = ui->idLineEdit->text();

    if (userType == "Customer") {

            if (id.isEmpty()) {
                QMessageBox::warning(this, "ERROR", "Enter user ID");
                return;
            }

            if (userType == "Customer") {
                Costumer* c = COSTUMERS.search(id.toStdString());
                if (c) {
                    // اگر مشتری پیدا شد، برو به پنجره گزینه‌ها (حذف / ویرایش)
                    CustomerOptionsWindow* options = new CustomerOptionsWindow( this);
                    options->show();
                } else {
                    // مشتری پیدا نشد، برو به فرم ساخت مشتری جدید
                    NewCustomerWindow* newCust = new NewCustomerWindow( this);
                    newCust->show();
                }
            }
            else if (userType == "Admin") {
                Admin* a = ADMINS.search(id.toStdString());
                if (a) {
                    AdminOptionsWindow* options = new AdminOptionsWindow( this);
                    options->show();
                } else {
                    NewAdminWindow* newAdmin = new NewAdminWindow( this);
                    newAdmin->show();
                }
            }
        }

}

