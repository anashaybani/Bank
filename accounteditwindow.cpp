#include "accounteditwindow.h"
#include "ui_accounteditwindow.h"
//#include "AddCardWindow.h"

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
}

AccountEditWindow::~AccountEditWindow()
{
    delete ui;
}





void AccountEditWindow::openAddCardPage() {
    AddCardWindow* addCardWin = new AddCardWindow(this); // parent قرار می‌دیم برای مدیریت حافظه
    addCardWin->exec();
    delete addCardWin;
}



void AccountEditWindow::openEditCardPage() {
    EditCardsWindow * editWin = new EditCardsWindow(this);
    editWin->exec();
    delete editWin;
}


void AccountEditWindow::openViewCardPage() {
    ViewCardsWindow * viewWin = new ViewCardsWindow(this);
    viewWin->exec();
    delete viewWin;

}
