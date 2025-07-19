#include "customermainwindow.h"
#include "ui_customermainwindow.h"

#include <QMessageBox>

CustomerMainWindow::CustomerMainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerMainWindow)
{
    ui->setupUi(this);

    connect(ui->transferButton, &QPushButton::clicked, this, &CustomerMainWindow::openTransferPage);
    connect(ui->viewCardsButton, &QPushButton::clicked, this, &CustomerMainWindow::openViewCardsPage);
    connect(ui->editCardButton, &QPushButton::clicked, this, &CustomerMainWindow::openEditCardPage);
    connect(ui->closeButton, &QPushButton::clicked, this, &CustomerMainWindow::on_closeButton_clicked);

}

CustomerMainWindow::~CustomerMainWindow()
{
    delete ui;
}


#include "TransferWindow.h"
#include "ViewCardsWindow.h"
#include "EditCardsWindow.h"

void CustomerMainWindow::openTransferPage() {
    TransferWindow* transferWin = new TransferWindow();
    transferWin->exec();
    delete transferWin;
}

void CustomerMainWindow::openViewCardsPage() {
    if(CURRENT_COSTUMER->getAccountCount() == 0){
        QMessageBox::warning(this, "ERROR", "No Accpunt!");
        return;
    }
    else{
        ViewCardsWindow * viewWin = new ViewCardsWindow();
        viewWin->exec();
        delete viewWin;


    }
}

void CustomerMainWindow::openEditCardPage() {  
    if(CURRENT_COSTUMER->getAccountCount() == 0){
        QMessageBox::warning(this, "ERROR", "No Accpunt!");
        return;
    }
    else{
        EditCardsWindow * editWin = new EditCardsWindow();
        editWin->exec();
        delete editWin;

    }
}



void CustomerMainWindow::on_closeButton_clicked()
{
    this->close();
}
