#include "customermainwindow.h"
#include "ui_customermainwindow.h"

CustomerMainWindow::CustomerMainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerMainWindow)
{
    ui->setupUi(this);

    connect(ui->transferButton, &QPushButton::clicked, this, &CustomerMainWindow::openTransferPage);
    connect(ui->viewCardsButton, &QPushButton::clicked, this, &CustomerMainWindow::openViewCardsPage);
    connect(ui->editCardButton, &QPushButton::clicked, this, &CustomerMainWindow::openEditCardPage);

}

CustomerMainWindow::~CustomerMainWindow()
{
    delete ui;
}


#include "TransferWindow.h"
#include "ViewCardsWindow.h"
#include "EditCardsWindow.h"

void CustomerMainWindow::openTransferPage() {
    TransferWindow* transferWin = new TransferWindow(this); // parent قرار می‌دیم برای مدیریت حافظه
    transferWin->exec();
    delete transferWin;
}

void CustomerMainWindow::openViewCardsPage() {
    ViewCardsWindow * viewWin = new ViewCardsWindow(this);
    viewWin->exec();
    delete viewWin;

}

void CustomerMainWindow::openEditCardPage() {
    EditCardsWindow * editWin = new EditCardsWindow(this);
    editWin->exec();
    delete editWin;
}
