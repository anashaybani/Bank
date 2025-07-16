#ifndef EDITCUSTOMERWINDOW_H
#define EDITCUSTOMERWINDOW_H

#include <QDialog>

namespace Ui {
class EditCustomerWindow;
}

class EditCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomerWindow(QWidget *parent = nullptr);
    ~EditCustomerWindow();

private:
    Ui::EditCustomerWindow *ui;

    void on_saveButton_clicked();
    void on_closeButton_clicked();
};

#endif // EDITCUSTOMERWINDOW_H
