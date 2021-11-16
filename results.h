#ifndef RESULTS_H
#define RESULTS_H
#include<iostream>
#include <QDialog>
#include<list>
#include"hotels.h"
#include<QListWidgetItem>
using namespace std;
namespace Ui {
class results;
}

class results : public QDialog
{
    Q_OBJECT

public:
    explicit results(QWidget *parent = nullptr);
    struct HotelInfo{
        QString HotelName,Description;

    };
    void go();
    ~results();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::results *ui;
    hotels *hotel;

};

#endif // RESULTS_H
