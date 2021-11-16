#include "log.h"
#include "ui_log.h"
#include<iostream>
#include"fstream"
#include"string"
#include"queue"
#include <QTextStream>
#include <QFile>
#include<QMessageBox>
using namespace std;
log::log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/trivago.png");
    ui->image->setPixmap(pix.scaled(500,70,Qt::KeepAspectRatio));
    Qt::WindowFlags flags = windowFlags();
       Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
       flags = flags & (~closeFlag);
       setWindowFlags(flags);
}

log::~log()
{
    delete ui;
}
void log::write()
{
    QString temp;
     QFile File ("users.txt");
     QTextStream u1(&File);
     File.open(QIODevice::ReadOnly | QIODevice::Append | QFile::Text);
    while(!u1.atEnd())
    {
        temp = u1.readLine();
        if((ui->user->text()==temp.section("",0,0)))
        {

        }
    }
    File.close();
}
void log::on_pushButton_2_clicked()
{
    bool isFound;
    string temp;
    string temp2;
    queue<string>saved;
    ifstream myfile("users.txt");
    if(myfile.is_open())
    {
        while(getline(myfile,temp))
        {
            myfile>>temp2;
            saved.push(temp2);
        }
    }
    if(ui->user->text() == "teameldamar" && ui->pass->text() == "number1")
    {
        QMessageBox::information(this,"Sign in", "Username and Password is correct");
        hide();
        welcome = new postpass(this);
        welcome->show();
    }
    else{
    while(!saved.empty()){
    string t = saved.front();
    QString T = QString::fromLocal8Bit(t.c_str());
    if(T == ui->user->text()){
        saved.pop();
        string t = saved.front();
        QString T = QString::fromLocal8Bit(t.c_str());
        if(T == ui->pass->text()){
            isFound = true;
            QMessageBox::information(this,"Sign in", "Username and Password is correct");
            hide();
            break;
        }
        else{
            isFound = false;
            break;
        }
    }
    else{
        saved.pop();
        saved.pop();
        isFound = false;
    }
    }
    if(isFound == false)
        QMessageBox::warning(this,"Sign in", "Username or Password is incorrect");
    }
     myfile.close();
}
void log::on_commandLinkButton_clicked()
{
   redirect = new Register(this);
   redirect->show();
}
