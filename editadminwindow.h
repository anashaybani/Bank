#ifndef EDITADMINWINDOW_H
#define EDITADMINWINDOW_H

#include <QDialog>

namespace Ui {
class EditAdminWindow;
}

class EditAdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditAdminWindow(QWidget *parent = nullptr);
    ~EditAdminWindow();

private:
    Ui::EditAdminWindow *ui;

    void on_saveButton_clicked();
    void on_closeButton_clicked();
};

#endif // EDITADMINWINDOW_H
