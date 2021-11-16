#include "trivago.h"

Trivago::Trivago(QObject *parent) : QObject(parent)
{

}

Trivago::Entries Trivago::entries() const
{
    return m_entries;
}

TrivagoEntry *Trivago::creatEntry()
{
    auto result =new TrivagoEntry (this);
    if(result !=nullptr){

        m_entries.append( result );
        emit entryAdded(result);
    }
    return result;
}

bool Trivago::deleteEntry(TrivagoEntry *entry)
{
    if (m_entries.contains(entry)){
        emit entryRmoved(entry);
        m_entries.removeOne(entry);
        delete entry;
        return true;
    }
    return false;
}
