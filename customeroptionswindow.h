#ifndef CUSTOMEROPTIONSWINDOW_H
#define CUSTOMEROPTIONSWINDOW_H

#include <QWidget>

namespace Ui {
class CustomerOptionsWindow;
}

class CustomerOptionsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerOptionsWindow( QWidget *parent = nullptr);

    ~CustomerOptionsWindow();

private:
    Ui::CustomerOptionsWindow *ui;
    void handleCustomer();
    void handleCard();
    void on_closeButton_clicked();
};

#endif // CUSTOMEROPTIONSWINDOW_H
