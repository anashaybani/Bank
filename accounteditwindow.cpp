#include "accounteditwindow.h"
#include "ui_accounteditwindow.h"
#include "AddCardWindow.h"

#include "EditCardsWindow.h"
#include "ViewCardsWindow.h"

AccountEditWindow::AccountEditWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountEditWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountEditWindow::openAddCardPage);
    connect(ui->editCardButton, &QPushButton::clicked, this, &AccountEditWindow::openEditCardPage);
    connect(ui->viewCardsButton, &QPushButton::clicked, this, &AccountEditWindow::openViewCardPage);
    connect(ui->closeButton, &QPushButton::clicked, this, &AccountEditWindow::on_closeButton_clicked);
}

AccountEditWindow::~AccountEditWindow()
{
    delete ui;
}

#include "../Bank/Bank/globals.h"
#include <QMessageBox>

void AccountEditWindow::openAddCardPage() {

    if(CURRENT_COSTUMER->getAccountCount() >= 5){
        QMessageBox::warning(this, "ERROR", "Five existing cards!");
        return;
    }
    else{
        AddCardWindow* addCardWin = new AddCardWindow(); // parent قرار می‌دیم برای مدیریت حافظه
        addCardWin->exec();
        delete addCardWin;
    }
}



void AccountEditWindow::openEditCardPage() {
    EditCardsWindow * editWin = new EditCardsWindow();
    editWin->exec();
    delete editWin;
}


void AccountEditWindow::openViewCardPage() {
    ViewCardsWindow * viewWin = new ViewCardsWindow();
    viewWin->exec();
    delete viewWin;

}


void AccountEditWindow::on_closeButton_clicked()
{
    this->close();
}
