#include "admin.h"
#include "ui_admin.h"
#include<QMessageBox>
#include <QDebug>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_log_clicked()
{
    QString username = ui ->lineEdit_username->text();
    QString password = ui -> lineEdit_password->text();
    if(username == "teameldamar" && password == "number1")
    {
        QMessageBox::information(this,"Sign in", "Username and Password is correct");
        hide();
        welcome = new postpass(this);
        welcome->show();

    }
    else{
        QMessageBox::warning(this,"Sign in", "Username or Password is incorrect");

    }
}
