#include "postpass.h"
#include "ui_postpass.h"
#include<QFile>
#include<QTextStream>
#include <QMessageBox>
#include<QPixmap>
#include <iostream>
#include <list>
#include "string"
#include <QDebug>
using namespace std;
postpass::postpass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::postpass)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/trivago.png");
    ui->label->setPixmap(pix.scaled(700,50,Qt::KeepAspectRatio));
}
postpass::~postpass()
{
    delete ui;
}
void postpass::on_AddButton_clicked()
{
            data1 = new class data(this);
            data1->show();
}

void postpass::on_ViewButton_clicked()
{
    deledits = new EditDel(this);
    deledits->show();
}
