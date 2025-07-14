#ifndef NEWADMINWINDOW_H
#define NEWADMINWINDOW_H

#include <QDialog>

namespace Ui {
class NewAdminWindow;
}

class NewAdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewAdminWindow(QWidget *parent = nullptr);
    ~NewAdminWindow();

private:
    Ui::NewAdminWindow *ui;

       void on_createButton_clicked();
};

#endif // NEWADMINWINDOW_H
