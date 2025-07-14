#ifndef CUSTOMEROPTIONSWINDOW_H
#define CUSTOMEROPTIONSWINDOW_H
#include "../Bank/Bank/Costumer.h"
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
};

#endif // CUSTOMEROPTIONSWINDOW_H
