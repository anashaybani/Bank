#ifndef CUSTOMERLOGINWINDOW_H
#define CUSTOMERLOGINWINDOW_H

#include <QDialog>

namespace Ui {
class CustomerLoginWindow;
}

class CustomerLoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerLoginWindow(QWidget *parent = nullptr);
    ~CustomerLoginWindow();

private:
    Ui::CustomerLoginWindow *ui;
    void handleLogin();
};

#endif // CUSTOMERLOGINWINDOW_H
