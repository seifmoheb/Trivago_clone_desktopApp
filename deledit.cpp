#include "deledit.h"
#include "ui_deledit.h"
#include<QPushButton>
#include <QActionEvent>
#include<QWidgetList>
deledit::deledit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deledit),
    m_controller (controller)
{
    Q_ASSERT(controller!=nullptr);
    ui->setupUi(this);

    setupconnections();
}
void deledit::creatEntry()
{
    auto entry = m_controller -> creatEntry();  //function createntry() deh ely mawgoda fe trivago.cpp
    if (entry){// el if deh ba2a 3ashan yt2akd en el entry da5l function el createntry() wel variable ely esmo entry et3aml
      ui->listWidget_2->addItem(entry->name());
      auto listItem =ui->listWidget_2->item(ui->listWidget_2->count()-1);  //mohem min1:33
      m_entryMap.insert(listItem,entry);
    }
}
void deledit::deleteEntry()
{
    auto listItem=ui->listWidget_2->currentItem();
    if (listItem){
        auto entry=m_entryMap.value(listItem);
        if (entry){
            if(m_controller -> deleteEntry(entry)){ //3ashan law fe3lan etmsa7 y3mlo delete mn 3al screen fel satr ely ta7teh.
              m_entryMap.remove(listItem);
                delete listItem;
            }
        }
    }
}

void deledit::editEntry()
{
    auto listItem=ui->listWidget_2->currentItem();
    if (listItem){
        auto entry=m_entryMap.value(listItem);
        if (entry){
        ui->stackedWidget->setCurrentWidget(ui->detailedpage_2); //3ashan ywadeni ll page el tania ely ba edit feha.
        ui->menubar->setEnabled(false);  // 3ashan hy5aly el user my3rfsh y5tar 7aga mn el  menu ely feh el add wl remove wl edit.
      //  ui->nameedit->setText(entry->name());
       // ui->dateEdit->setDate(entry->checksDate());
       // ui->adressedit->setPlainText(entry->adress());
       // ui->phonenumberedit->setPlainText(entry->phoneNumber().join("\n"));//7etet join el zeyada deh 3ashan el data type bta3to QStringlist
       resetEntry();  // code sharing : 3ashan kda kda katbhom fl reset entry ta7t
        }
    }

}

void deledit::saveEntry()
{
    auto listItem=ui->listWidget_2->currentItem();  //nafs el reset w zawedt b3d if el kam entery dol w shelt ba2et el function.
    if (listItem){
        auto entry=m_entryMap.value(listItem);
        if (entry){
        entry->setName (ui->nameedit_2->text());
        entry ->setChecksDate(ui->dateEdit_2->date());
        entry->setAdress(ui->adressedit_2->toPlainText());
        entry->setPhoneNumber(ui->phonenumberedit_2->toPlainText().split("\n"));
        listItem->setText(entry->name()); // da by3ml zay update ll list widget
        discardEntry();
        }
    }

}

void deledit::discardEntry()
{
    ui->stackedWidget->setCurrentWidget(ui->listpage_2);  //hywdandeni ll page el ola
    ui->menubar->setEnabled(true); // w da 3asham e5leni ados 3ala el add w edit wl remove
}

void deledit::resetEntry()
{
    auto listItem=ui->listWidget_2->currentItem();
    if (listItem){
        auto entry=m_entryMap.value(listItem);
        if (entry){
        ui->nameedit_2->setText(entry->name());
        ui->dateEdit_2->setDate(entry->checksDate());
        ui->adressedit_2->setPlainText(entry->adress());
        ui->phonenumberedit_2->setPlainText(entry->phoneNumber().join("\n"));//7etet join el zeyada deh 3ashan el data type bta3to QStringlist
        }
    }
}

void deledit::setupconnections()
{
     // mesh fahem fehom 7aga.
    connect (ui->actionAdd, SIGNAL(triggered (bool)),this,SLOT(creatEntry()));

    connect (ui->actionRemove, &QAction::triggered,this,&deledit::deleteEntry);

    connect (ui->actionEdit, &QAction::triggered,this,&deledit::editEntry);

    connect(ui->buttonBox_2 -> button(QDialogButtonBox::Save),&QPushButton::clicked,
            this, &deledit::saveEntry);  // ely fahmo hna en e7na 3amlna connect maben el save button w el save entery ely fl slot fe el mainwindow.

    connect(ui->buttonBox_2 -> button(QDialogButtonBox::Discard),&QPushButton::clicked,
            this, &deledit::discardEntry);
    connect(ui->buttonBox_2 -> button(QDialogButtonBox::Reset),&QPushButton::clicked,
            this, &deledit::resetEntry);


}
deledit::~deledit()
{
    delete ui;
}

