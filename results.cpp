#include "results.h"
#include "ui_results.h"
#include<QListWidget>
#include<iostream>
#include<fstream>
#include"string"
#include<unordered_map>
#include<QHash>
#include<queue>
#include<QList>
#include<QByteArray>
#include<QDebug>
#include<QListWidgetItem>
#include <QItemSelectionModel>
#include<QPixmap>
using namespace std;
int haash(int x);
struct info{
    QString name,desc;
}put;
bool avai();
struct date{
    QString day1="10";
    QString month1="12";
    QString year1="2019";
    QString day2="30";
    QString month2="12";
    QString year2="2019";
}cal;
    results::results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::results)
{
    ui->setupUi(this);
    queue<string>q;
    QHash<QString,QList<info>>s;
    queue<string>search;
    string value;
    ifstream file2("searchvalue.txt");
    file2>>value;
    search.push(value);
    queue<string>search2;
    string value2;
    ifstream file3("searchvalue2.txt");
    file3>>value2;
    search2.push(value2);
    string temp;
    string temp2;
      int count = 0;
       ifstream myfile("DataInfo.txt");
       if(myfile.is_open())
       {
           while(getline(myfile,temp))
           {
               myfile>>temp2;
              q.push(temp2);
               count++;
           }
       }
       myfile.close();
      QList< info>*templist = new QList< info>[25];
while(!q.empty()){
       QString key = q.front().c_str();
       int sum = 0;
       for (int i = 0; i < key.length(); i++)
       {
           int z = key.at(i).toLatin1();
           sum += z;
       }
       q.pop();
        put.name = q.front().c_str();
        int index = haash(sum);
        q.pop();
        put.desc =q.front().c_str();
        q.pop();
        templist[index].push_front(put);
        s[key] = templist[index];
        if(q.size()==1)
            break;
       }
     QString text = QString::fromUtf8(search.front().c_str());
     QString h;
     QListWidgetItem *newItem;
     QString var = "all";

     QStringList List1;
     QString sl = search2.front().c_str();
     List1 = sl.split(',', QString::SkipEmptyParts);
     for(int i = 0; i < s[text].size(); i++){
         QStringList list2;
     list2 = s[text][i].desc.split(',', QString::SkipEmptyParts);

     if(search2.front().c_str()==var){
     newItem = new QListWidgetItem;
     h  = s[text][i].name;
    newItem->setText(h);
    ui->listWidget->insertItem(i, newItem);
    ui->listWidget->selectionMode();
         ui->country->setText(text);
         QPixmap pix(":/img/img/trivago.png");
         ui->image->setPixmap(pix.scaled(90,70,Qt::KeepAspectRatio));
         ui->stars->setText("*****");
}
     else{
         int count = List1.count();
         if(List1.size()<=list2.size()){
 for(int k = 0; k< List1.size(); k++){
    for (int j = 0; j < list2.size(); j++){
     if(list2[j]==List1[k]){
       count--;
       break;
        }
     }
    if(count==0)
    {
        newItem = new QListWidgetItem;
        h  = s[text][i].name;
       newItem->setText(h);
       ui->listWidget->insertItem(i, newItem);
       ui->listWidget->selectionMode();
            ui->country->setText(text);
            QPixmap pix(":/img/img/trivago.png");
            ui->image->setPixmap(pix.scaled(90,70,Qt::KeepAspectRatio));
         ui->stars->setText("*****");
         break;
    }
     }
     }
}
    }
}
int haash(int x)
{
    return (x % 5);
};
results::~results()
{
    delete ui;
}
void results::on_listWidget_itemClicked(QListWidgetItem *item){
    ui->hotel->setText(item->text());
    if(item->text()=="Samiramis"){
    QPixmap pix(":/img/img/samiramis.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("***");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Kempinski"){
    QPixmap pix(":/img/img/hotel2.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    ui->stars->setText("*****");
    }
    if(item->text()=="Hilton"){
    QPixmap pix(":/img/img/hotel3.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Intercontinental"){
    QPixmap pix(":/img/img/hotel4.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("*****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Marriott"){
    QPixmap pix(":/img/img/hotel5.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="GrandHayat"){
    QPixmap pix(":/img/img/hotel6.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="TibaRose"){
    QPixmap pix(":/img/img/hotel7.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("***");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="DusitLakeView"){
    QPixmap pix(":/img/img/hotel8.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("***");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Novitel"){
    QPixmap pix(":/img/img/hotel9.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("*****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Mirage"){
    QPixmap pix(":/img/img/hotel10.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("*****");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="Martinez"){
    QPixmap pix(":/img/img/hotel11.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("***");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
    if(item->text()=="MenaHouse"){
    QPixmap pix(":/img/img/hotel12.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));
    ui->stars->setText("***");
    if(avai() == true)
    {
        ui->av->setText("Available in This Period");
    }
    else if(avai() == false){
        ui->av->setText("Unvailable in This Period");
    }
    }
}
bool avai(){
    queue<string>q2;
    bool available = false;
    string temp3;
    string temp4;
    ifstream date("date.txt");
    if(date.is_open())
    {
        while(getline(date,temp3))
        {
            date>>temp4;
           q2.push(temp4);
        }
    }
    date.close();
    string temp5;
    string temp6;
    ifstream date2("date2.txt");
    if(date2.is_open())
    {
        while(getline(date2,temp5))
        {
           date2>>temp6;
           q2.push(temp6);
        }
    }
    date2.close();
    QString tempo = q2.front().c_str();
    q2.pop();
    if(q2.front().c_str() >= cal.month1)
    {
        if(tempo>=cal.day1){
            q2.pop();
            if(q2.front().c_str() == cal.year1){
                q2.pop();
                QString tempo2 = q2.front().c_str();
                q2.pop();
                if(q2.front().c_str() <= cal.month2)
                {
                    if(tempo2<=cal.day2){
                        q2.pop();
                        if(q2.front().c_str() == cal.year2){
                            q2.pop();
                            available = true;
                        }
                    }
                }
            }
        }
    }
    else
        available = false;
    return available;
}
