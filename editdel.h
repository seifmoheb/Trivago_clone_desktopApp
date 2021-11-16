#ifndef EDITDEL_H
#define EDITDEL_H

#include <QDialog>
#include<QListWidgetItem>
#include<iostream>
#include<fstream>
#include"string"
#include<QHash>
#include<queue>
#include<QList>
using namespace std;
namespace Ui {
class EditDel;
}

class EditDel : public QDialog
{
    Q_OBJECT

public:
    explicit EditDel(QWidget *parent = nullptr);
    ~EditDel();
    struct info{
        QString name,desc,country;

    }put1;



private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::EditDel *ui;
QHash<QString,QList< info>>s;
QHash<QString,QList< info>>::iterator it= s.begin();

};

#endif // EDITDEL_H
