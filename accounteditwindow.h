#ifndef ACCOUNTEDITWINDOW_H
#define ACCOUNTEDITWINDOW_H

#include <QWidget>

namespace Ui {
class AccountEditWindow;
}

class AccountEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AccountEditWindow(QWidget *parent = nullptr);
    ~AccountEditWindow();

private:
    Ui::AccountEditWindow *ui;

    void openDeleteCardPage();
    void openAddCardPage();
    void openViewCardPage();
    void openEditCardPage();


};

#endif // ACCOUNTEDITWINDOW_H
