#ifndef VIEWCUSTOMERWINDOW_H
#define VIEWCUSTOMERWINDOW_H

#include <QDialog>

namespace Ui {
class ViewCustomerWindow;
}

class ViewCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomerWindow(QWidget *parent = nullptr);
    ~ViewCustomerWindow();

private:
    Ui::ViewCustomerWindow *ui;

    void fillUserFields();
    void on_closeButton_clicked();

};

#endif // VIEWCUSTOMERWINDOW_H
