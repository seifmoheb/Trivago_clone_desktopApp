#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include"string"
#include<iostream>
#include<fstream>
using namespace std;
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/trivago.png");
    ui->image->setPixmap(pix.scaled(500,70,Qt::KeepAspectRatio));}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    username = ui -> user->text();
    password = ui -> pass->text();
    string x = username.toStdString().c_str();
    string z = password.toStdString().c_str();
    ofstream oFile("users.txt", std::ios_base::app);
    if(oFile.is_open()){
    oFile<<"\n"<<x<<"\n"<<z;
    }
    oFile.close();
    QMessageBox::information(this,"Register", "Successfully Registerd");
    hide();
}
