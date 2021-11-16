#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include"postpass.h"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_log_clicked();

private:
    Ui::Admin *ui;
    postpass *welcome;
};


#endif // ADMIN_H
