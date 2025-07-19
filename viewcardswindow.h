#ifndef VIEWCARDSWINDOW_H
#define VIEWCARDSWINDOW_H

#include "../Bank/Bank/Costumer.h"
#include "../Bank/Bank/Account.h"
#include "../Bank/Bank/globals.h"
#include "../Bank/Bank/GharzolHasanehAccount.h"
#include "../Bank/Bank/LongTermAccount.h"
#include "../Bank/Bank/JariAccount.h"

#include <QButtonGroup>
#include <QDialog>

namespace Ui {
class ViewCardsWindow;
}

class ViewCardsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCardsWindow(QWidget *parent = nullptr);
    ~ViewCardsWindow();

private:
    Ui::ViewCardsWindow *ui;
    QButtonGroup* radioGroup;
    void on_nextButton_clicked();
    void on_closeButton_clicked();
};

#endif // VIEWCARDSWINDOW_H
