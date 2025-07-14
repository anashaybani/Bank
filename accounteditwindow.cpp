#include "accounteditwindow.h"
#include "ui_accounteditwindow.h"

AccountEditWindow::AccountEditWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountEditWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &AccountEditWindow::openAddCardPage);
    connect(ui->deleteButton, &QPushButton::clicked, this, &AccountEditWindow::openDeleteCardPage);
    connect(ui->editCardButton, &QPushButton::clicked, this, &AccountEditWindow::openEditCardPage);
    connect(ui->viewCardsButton, &QPushButton::clicked, this, &AccountEditWindow::openViewCardPage);
}

AccountEditWindow::~AccountEditWindow()
{
    delete ui;
}



//#include "AddCardWindow.h"
//#include "DeleteCardWindow.h"
#include "EditCardsWindow.h"
#include "ViewCardsWindow.h"

void AccountEditWindow::openAddCardPage() {
    AddCardWindow* addCardWin = new AddCardWindow(this); // parent قرار می‌دیم برای مدیریت حافظه
    addCardWin->exec(); // اجرا به صورت مودال (مثل dialog)
    delete addCardWin; // بعد از بستن پاک میشه
}

void AccountEditWindow::openDeleteCardPage() {
    DeleteCardWindow * deleteCardWin = new DeleteCardWindow(this);
    deleteCardWin->exec();
    delete deleteCardWin;

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
