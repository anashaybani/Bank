#ifndef ADMINOPTIONSWINDOW_H
#define ADMINOPTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class AdminOptionsWindow;
}

class AdminOptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminOptionsWindow(QWidget *parent = nullptr);
    ~AdminOptionsWindow();

private:
    Ui::AdminOptionsWindow *ui;

    void on_editButton_clicked();
    void on_showButton_clicked();
    void on_deleteButton_clicked();
};

#endif // ADMINOPTIONSWINDOW_H
