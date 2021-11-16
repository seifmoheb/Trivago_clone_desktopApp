#include "ui_mainwindow.h"
#include<QPixmap>
#include "mainwindow.h"
#include <vector>
#include<fstream>
#include<QString>
#include<QFile>
#include<map>
#include<QDateTime>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/trivago.png");
    ui->label_2->setPixmap(pix.scaled(500,70,Qt::KeepAspectRatio));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
    amn = new Admin(this);
    amn->show();
    /*/Admin amn;
    amn.setModal(true);
    amn.exec();/*/

}



void MainWindow::on_button_clicked()
{

    string x = ui->lineEdit->text().toStdString().c_str();
    ofstream oFile("searchvalue.txt");
    if(oFile.is_open()){
    oFile<<"\n"<<x;
    }
    oFile.close();
    string x2 = ui->line2->text().toStdString().c_str();
    ofstream File("searchvalue2.txt");
    if(File.is_open()){
    File<<"\n"<<x2;
    }
    File.close();
}

void MainWindow::on_pushButton_clicked()
{
    result1 = new results(this);
    result1->show();
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    QDateTime now = QDateTime :: currentDateTime();
    QString timestamp = date.toString(QLatin1String("yyyyMMdd-hhmm"));
    QString filename = QString::fromLatin1("date.txt").arg(timestamp);
    ofstream oFile("date.txt");
    if(oFile.is_open()){
    oFile<<"\n"<<date.day()<<"\n"<<date.month()<<"\n"<<date.year();
    }
    oFile.close();
}

void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    QDateTime now = QDateTime :: currentDateTime();
    QString timestamp = date.toString(QLatin1String("yyyyMMdd-hhmm"));
    QString filename = QString::fromLatin1("date.txt").arg(timestamp);
    ofstream oFile("date2.txt");
    if(oFile.is_open()){
    oFile<<"\n"<<date.day()<<"\n"<<date.month()<<"\n"<<date.year();
    }
    oFile.close();
}
