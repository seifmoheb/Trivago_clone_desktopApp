#include "hotels.h"
#include "ui_hotels.h"

hotels::hotels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotels)
{
    ui->setupUi(this);
}

hotels::~hotels()
{
    delete ui;
}
