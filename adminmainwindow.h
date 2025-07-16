#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QWidget>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    ~AdminMainWindow();

private:
    Ui::AdminMainWindow *ui;

    void handleProceed();
    void on_closeButton_clicked();
};

#endif // ADMINMAINWINDOW_H
