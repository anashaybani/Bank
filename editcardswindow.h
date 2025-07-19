#ifndef EDITCARDSWINDOW_H
#define EDITCARDSWINDOW_H


#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/JariAccount.h"


#include <QButtonGroup>
#include <QDialog>

namespace Ui {
class EditCardsWindow;
}

class EditCardsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditCardsWindow(QWidget *parent = nullptr);
    ~EditCardsWindow();

private:
    Ui::EditCardsWindow *ui;
    QButtonGroup* radioGroup;

    void on_editSelectedButton_clicked();

    void on_deleteSelectedButton_clicked();

    void on_closeButton_clicked();
};

#endif // EDITCARDSWINDOW_H
