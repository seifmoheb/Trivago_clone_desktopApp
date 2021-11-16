#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include"register.h"
#include"postpass.h"
namespace Ui {
class log;
}

class log : public QDialog
{
    Q_OBJECT

public:
    explicit log(QWidget *parent = nullptr);
    QString username,password;

    ~log();

private slots:
    void write();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::log *ui;
    Register *redirect;
    postpass *welcome;
};

#endif // LOG_H
