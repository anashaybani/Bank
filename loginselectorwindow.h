#ifndef LOGINSELECTORWINDOW_H
#define LOGINSELECTORWINDOW_H

#include <QWidget>

namespace Ui {
class LoginSelectorWindow;
}

class LoginSelectorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginSelectorWindow(QWidget *parent = nullptr);
    ~LoginSelectorWindow();

private:
    Ui::LoginSelectorWindow *ui;
    void openCustomerLogin();
    void openAdminLogin();
};

#endif // LOGINSELECTORWINDOW_H
