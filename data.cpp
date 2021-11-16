#include "ui_data.h"
#include <map>
#include <iostream>
#include <QDebug>
#include"data.h"
#include<fstream>
#include<QMessageBox>
#include <QFileDialog>
#include<QPixmap>
#include<QHash>
using namespace std;

data::data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::data)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/addimage.png");
    ui->image->setPixmap(pix.scaled(500,70,Qt::KeepAspectRatio));
}

data::~data()
{
    delete ui;
}

void data::on_pushButton_2_clicked()
{
        hinfo.name = ui -> HotelName->text();
        hinfo.country = ui -> Country->text();
        hinfo.Description = ui ->description->text();
       string x = hinfo.name.toStdString().c_str();
       string z = hinfo.country.toStdString().c_str();
       string y = hinfo.Description.toStdString().c_str();
        ofstream oFile ("DataInfo.txt", std::ios_base::app);
        if(oFile.is_open()){
        oFile<<z<<"\n"<<x<<"\n"<<y<<"\n";
        }
        oFile.close();
        QMessageBox::information(this,"Add-Admin", "Successfully added");
        hide();

}
void data::on_pushButton_clicked()
{
    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName;
        fileName = QFileDialog::getOpenFileName(this,
             tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
        QPixmap pix((fileName));
         QFile pixi((fileName));
        ui->image->setPixmap(pix.scaled(500,70,Qt::KeepAspectRatio));
        pixi.open(QIODevice::WriteOnly);
        pix.save(&pixi, "PNG");

}
