#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <QDialog>
#include "postpass.h"
#include <vector>
using namespace std;
namespace Ui {
class data;

}

class data : public QDialog
{
    Q_OBJECT


public:
    explicit data(QWidget *parent = nullptr);
    struct info{
        QString name,country,Description;
    }hinfo;
    void add();
    ~data();
private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::data *ui;

};
#endif
