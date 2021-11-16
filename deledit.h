#ifndef DELEDIT_H
#define DELEDIT_H
#include "trivagcontroller.h"
#include <QHash>
#include <QMainWindow>
#include<QListWidgetItem>
namespace Ui {
class deledit;
}

class deledit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deledit(QWidget *parent = nullptr);
    ~deledit();
public slots:
    void  creatEntry();
    void  deleteEntry();
    void  editEntry();
    void saveEntry();
    void discardEntry();
    void resetEntry();
private slots:

private:
    Ui::deledit *ui;
    TrivagController *m_controller;
    TrivagController *controller;
    QHash<QListWidgetItem*,class TrivagoEntry*>m_entryMap;
    void setupconnections ();
};

#endif // DELEDIT_H
