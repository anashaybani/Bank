#ifndef CUSTOMERMAINWINDOW_H
#define CUSTOMERMAINWINDOW_H

#include <QWidget>

namespace Ui {
class CustomerMainWindow;
}

class CustomerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerMainWindow(QWidget *parent = nullptr);
    ~CustomerMainWindow();

private:
    Ui::CustomerMainWindow *ui;

    void openTransferPage();
    void openViewCardsPage();
    void openEditCardPage();
    void on_closeButton_clicked();
};

#endif // CUSTOMERMAINWINDOW_H
