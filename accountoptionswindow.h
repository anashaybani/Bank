#ifndef ACCOUNTOPTIONSWINDOW_H
#define ACCOUNTOPTIONSWINDOW_H

#include <QWidget>

namespace Ui {
class AccountOptionsWindow;
}

class AccountOptionsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AccountOptionsWindow(QWidget *parent = nullptr);
    ~AccountOptionsWindow();

private:
    Ui::AccountOptionsWindow *ui;

    void on_saveButton_clicked();
    void on_closeButton_clicked();
};

#endif // ACCOUNTOPTIONSWINDOW_H
