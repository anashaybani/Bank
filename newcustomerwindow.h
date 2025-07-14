#ifndef NEWCUSTOMERWINDOW_H
#define NEWCUSTOMERWINDOW_H

#include <QDialog>

namespace Ui {
class NewCustomerWindow;
}

class NewCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewCustomerWindow(QWidget *parent = nullptr);
    ~NewCustomerWindow();

private:
    Ui::NewCustomerWindow *ui;
    void on_createButton_clicked();
};

#endif // NEWCUSTOMERWINDOW_H
