#include "editdel.h"
#include "ui_editdel.h"
#include<QListWidget>
#include<iostream>
#include<fstream>
#include"string"
#include<QHash>
#include<queue>
#include<QList>
#include<QPixmap>
#include<QMessageBox>
using namespace std;

int haaash(int x);
struct info{
    QString name,desc;

}put1;
EditDel::EditDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDel)
{
    ui->setupUi(this);
}
EditDel::~EditDel()
{
    delete ui;
}

void EditDel::on_pushButton_clicked()
{
    QList< info>*templist = new QList< info>[25];
    queue<string>q;

    string value;
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

while(!q.empty()){
       QString key = q.front().c_str();
       int sum = 0;
       for (int i = 0; i < key.length(); i++)
       {
           int z = key.at(i).toLatin1();
           sum += z;
       }
       q.pop();
        put1.name = q.front().c_str();
        int index = haaash(sum);
        s[key]=templist[index];
        q.pop();
        put1.desc =q.front().c_str();
        q.pop();
        templist[index].push_front(put1);
        s[key] = templist[index];
        if(q.size()==1)
            break;
       }
     QString h;
     QListWidgetItem *newItem;
     for(int i = 0; i < s[ui->lineEdit->text()].count(); i++){
      newItem = new QListWidgetItem;
      QString var = ui->lineEdit->text();
      h  = s[var][i].name;
     ui->listWidget->insertItem(i, newItem);
     newItem->setText(h);
     }
}

void EditDel::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->country->setText(ui->lineEdit->text());

    ui->hotel->setText(item->text());

        ui->description->setText(s[ui->lineEdit->text()][ui->listWidget->currentRow()].desc);

    if(item->text()=="Samiramis"){
    QPixmap pix(":/img/img/samiramis.jpg");
    ui->image->setPixmap(pix.scaled(90,70,Qt::KeepAspectRatio));
    }
    if(item->text()=="Kempinski"){
    QPixmap pix(":/img/img/hotel5.jpg");
    ui->image->setPixmap(pix.scaled(90,70,Qt::KeepAspectRatio));
    }
    if(item->text()=="Hilton"){
    QPixmap pix(":/img/img/hotel3.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));

    }
    if(item->text()=="Intercontinental"){
    QPixmap pix(":/img/img/hotel4.jpg");
    ui->image->setPixmap(pix.scaled(90,70,Qt::KeepAspectRatio));
    }
    if(item->text()=="Marriott"){
    QPixmap pix(":/img/img/hotel2.jpg");
    ui->image->setPixmap(pix.scaled(120,80,Qt::KeepAspectRatio));

    }
}
void EditDel::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    ui->description->clear();
    ui->hotel->clear();
    ui->country->clear();
    ui->lineEdit->clear();
}
int haaash(int x)
{
    return (x % 5);
};

void EditDel::on_pushButton_3_clicked()
{
    s[ui->lineEdit->text()].removeAt(ui->listWidget->currentRow());
    it = s.begin();
    ofstream oFile("DataInfo.txt");
    if (oFile.is_open()){
        oFile << "\n";
    while(it != s.end()){

        while (!s[it.key()].empty()){
                        string x = it.key().toStdString().c_str();
                        string z = s[it.key()].front().name.toStdString().c_str();
                        string y = s[it.key()].front().desc.toStdString().c_str();
                        oFile <<x << "\n" << z <<"\n"<< y<<endl;
                        s[it.key()].pop_front();
                    }
                    it++;
    }
}
    QMessageBox::information(this,"Delete", "Successfully Deleted");
    hide();
}

void EditDel::on_pushButton_4_clicked()
{
    s[ui->lineEdit->text()].removeAt(ui->listWidget->currentRow());

   it = s.begin();
   ofstream oFile("DataInfo.txt");
   if (oFile.is_open()){
       oFile << "\n";
   while(it != s.end()){

       while (!s[it.key()].empty()){
                       string x = it.key().toStdString().c_str();
                       string z = s[it.key()].front().name.toStdString().c_str();
                       string y = s[it.key()].front().desc.toStdString().c_str();
                       oFile <<x << "\n" << z <<"\n"<< y<<endl;
                       s[it.key()].pop_front();
                   }
                   it++;
   }
}

}

void EditDel::on_pushButton_5_clicked()
{

    string x = ui->hotel->text().toStdString();
    string y = ui->country->text().toStdString();
    string z = ui->description->text().toStdString();
    ofstream oFile ("DataInfo.txt", std::ios_base::app);
    if(oFile.is_open()){
    oFile<<y<<"\n"<<x<<"\n"<<z<<"\n";
    }
    int sum = 0;
    for (int i = 0; i < ui->lineEdit->text().length(); i++)
    {
        int z = ui->lineEdit->text().at(i).toLatin1();
        sum += z;
    }
    QList< info>*templist1 = new QList< info>[25];
    int index = haaash(sum);
    put1.name = ui->hotel->text();
    put1.country = ui->country->text();
    put1.desc = ui->description->text();
    templist1[index].push_front(put1);
    s[ui->lineEdit->text()] = templist1[index];
    QMessageBox::information(this,"Edit", "Successfully Edited");
    hide();
}
