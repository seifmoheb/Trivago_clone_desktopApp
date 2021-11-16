#include "trivagoentry.h"

TrivagoEntry::TrivagoEntry(QObject *parent) : QObject(parent)
{

}

QString TrivagoEntry::name() const
{
    return m_name;
}

void TrivagoEntry::setName(const QString &name)
{
    if(m_name != name){
    m_name = name;
    emit nameChanged(); //notifications bta3t el signals
    }
}

QString TrivagoEntry::adress() const
{
    return m_adress;
}

void TrivagoEntry::setAdress(const QString &adress)
{
    if (m_adress != adress){
    m_adress = adress;
    emit adressChanged();
    }
}

QDate TrivagoEntry::checksDate() const
{
    return m_checksDate;
}

void TrivagoEntry::setChecksDate(const QDate &checksDate)
{
    if (m_checksDate !=checksDate){
    m_checksDate = checksDate;
    emit checksDateChanged();
    }
}

QStringList TrivagoEntry::phoneNumber() const
{
    return m_phoneNumber;
}

void TrivagoEntry::setPhoneNumber(const QStringList &phoneNumber)
{
    if(m_phoneNumber!=phoneNumber){
    m_phoneNumber = phoneNumber;
    emit phoneNumberChanged();
    }
}
TrivagoEntry ::~ TrivagoEntry()
{

}
