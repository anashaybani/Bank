#ifndef CUSTOMEREDITWINDOW_H
#define CUSTOMEREDITWINDOW_H

#include <QWidget>

namespace Ui {
class CustomerEditWindow;
}

class CustomerEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerEditWindow(QWidget *parent = nullptr);
    ~CustomerEditWindow();

private:
    Ui::CustomerEditWindow *ui;


    void on_deleteButton_clicked();
    void openViewCustomerPage();
    void openEditCustomerPage();
};

#endif // CUSTOMEREDITWINDOW_H
