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

    void openAddCardPage();
    void openViewCardPage();
    void openEditCardPage();
    void on_closeButton_clicked();


};

#endif // ACCOUNTEDITWINDOW_H
