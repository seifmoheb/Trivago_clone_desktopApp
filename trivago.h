#ifndef TRIVAGO_H
#define TRIVAGO_H
#include "trivagoentry.h"
#include <QObject>
#include <QList>
class Trivago : public QObject
{
    Q_OBJECT
public:
    typedef QList<TrivagoEntry*> Entries;
    //typedef QHash <TrivagoEntry,TrivagoEntry> Entries;

    explicit Trivago(QObject *parent = nullptr);

    Entries entries() const;

    TrivagoEntry* creatEntry();

    bool deleteEntry (TrivagoEntry *entry);

signals:
    void entryAdded (TrivagoEntry *entry);
    void entryRmoved (TrivagoEntry *entry);

public slots:

private:
    Entries m_entries;
};

#endif // TRIVAGO_H
