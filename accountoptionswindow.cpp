#include "accountoptionswindow.h"
#include "ui_accountoptionswindow.h"

AccountOptionsWindow::AccountOptionsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountOptionsWindow)
{
    ui->setupUi(this);
}

AccountOptionsWindow::~AccountOptionsWindow()
{
    delete ui;
}
