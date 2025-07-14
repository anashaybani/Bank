#ifndef ADMINLOGINWINDOW_H
#define ADMINLOGINWINDOW_H

#include <QDialog>

namespace Ui {
class AdminLoginWindow;
}

class AdminLoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLoginWindow(QWidget *parent = nullptr);
    ~AdminLoginWindow();

private:
    Ui::AdminLoginWindow *ui;

    void handleLogin();
};

#endif // ADMINLOGINWINDOW_H
