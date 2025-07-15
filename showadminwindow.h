#ifndef SHOWADMINWINDOW_H
#define SHOWADMINWINDOW_H

#include <QDialog>

namespace Ui {
class ShowAdminWindow;
}

class ShowAdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAdminWindow(QWidget *parent = nullptr);
    ~ShowAdminWindow();

private:
    Ui::ShowAdminWindow *ui;

    void fillUserFields();
    void on_closeButton_clicked();
};

#endif // SHOWADMINWINDOW_H
