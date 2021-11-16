#include "mainwindow.h"
#include <QApplication>
#include<string>
#include<iostream>
#include <vector>
#include"log.h"
#include<QObject>
#include"postpass.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QMainWindow mw;
    log login;
   if(login.exec()==QDialog::Accepted)
    {
        mw.show(); }
    return a.exec();
}
