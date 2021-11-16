#ifndef TRIVAGCONTROLLER_H
#define TRIVAGCONTROLLER_H
#include "trivago.h"
#include <QObject>

class TrivagController : public QObject
{
    Q_OBJECT
public:
    explicit TrivagController(Trivago *trivago,QObject *parent = nullptr);
    TrivagoEntry *creatEntry();
    bool deleteEntry (TrivagoEntry *entry);

signals:

public slots:

private:
    Trivago *m_trivago;
};

#endif // TRIVAGCONTROLLER_H
