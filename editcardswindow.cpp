#include "editcardswindow.h"
#include "ui_editcardswindow.h"


#include <QMessageBox>
#include <QInputDialog>

EditCardsWindow::EditCardsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCardsWindow)
{
    ui->setupUi(this);



    ui->cardsTable->clearContents();
    ui->cardsTable->setRowCount(0);

    if (!CURRENT_COSTUMER || CURRENT_COSTUMER->getAccountCount() == 0) {
        QMessageBox::warning(this, "خطا", "هیچ حسابی برای ویرایش وجود ندارد.");
        return;
    }

    int count = CURRENT_COSTUMER->getAccountCount();
    ui->cardsTable->setRowCount(count);

    for (int i = 0; i < count; ++i) {
        Account* acc = CURRENT_COSTUMER->getAccount(i);
        QTableWidgetItem* typeItem = new QTableWidgetItem(QString::fromStdString(acc->accountType()));
        QTableWidgetItem* cardItem = new QTableWidgetItem(QString::fromStdString(acc->getCardNumber()));
        ui->cardsTable->setItem(i, 0, typeItem);
        ui->cardsTable->setItem(i, 1, cardItem);
    }


}


EditCardsWindow::~EditCardsWindow()
{
    delete ui;
}


void EditCardsWindow::on_editSelectedButton_clicked()
{
    int row = ui->cardsTable->currentRow();

    if (row < 0 || row >= CURRENT_COSTUMER->getAccountCount()) {
        QMessageBox::warning(this, "خطا", "هیچ کارتی انتخاب نشده است!");
        return;
    }

    Account* acc = CURRENT_COSTUMER->getAccount(row);

    bool ok;
    QStringList items;
    items << "ویرایش رمز اول" << "ویرایش رمز دوم";

    QString choice = QInputDialog::getItem(this, "انتخاب عملیات", "چه چیزی را می‌خواهید تغییر دهید؟", items, 0, false, &ok);

    if (ok && !choice.isEmpty()) {
        if (choice == "ویرایش رمز اول") {
            QString newPin = QInputDialog::getText(this, "رمز جدید", "رمز اول جدید را وارد کنید:", QLineEdit::Password, "", &ok);
            if (ok) {
                acc->setPinCode(newPin.toStdString());
                QMessageBox::information(this, "موفق", "رمز اول با موفقیت تغییر کرد.");
            }
        } else if (choice == "ویرایش رمز دوم") {
            QString newPass = QInputDialog::getText(this, "رمز دوم جدید", "رمز دوم جدید را وارد کنید:", QLineEdit::Password, "", &ok);
            if (ok) {
                acc->setStaticSecondPassword(newPass.toStdString());
                QMessageBox::information(this, "موفق", "رمز دوم با موفقیت تغییر کرد.");
            }
        }
    }
}
