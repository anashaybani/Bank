#ifndef SHOWACCOUNTINFO_H
#define SHOWACCOUNTINFO_H

#include <QDialog>

namespace Ui {
class ShowAccountInfo;
}

class ShowAccountInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAccountInfo(QWidget *parent = nullptr);
    ~ShowAccountInfo();

private:
    Ui::ShowAccountInfo *ui;

    void on_closeButton_clicked();
};

#endif // SHOWACCOUNTINFO_H
