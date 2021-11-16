#ifndef TRIVAGOENTRY_H
#define TRIVAGOENTRY_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QStringList>
class TrivagoEntry : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString adress READ adress WRITE setAdress NOTIFY adressChanged)
    Q_PROPERTY(QDate checksDate READ checksDate WRITE setChecksDate NOTIFY checksDateChanged)
    Q_PROPERTY(QStringList phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)

public:
    explicit TrivagoEntry(QObject *parent = nullptr);
    ~TrivagoEntry();

    QString name() const;
    void setName(const QString &name); // hat over write el name ely howa el satr ely fo2eha

    QString adress() const;
    void setAdress(const QString &adress); //hat over write el adress ely nafs el klam


    QDate checksDate() const;
    void setChecksDate(const QDate &checksDate);

    QStringList phoneNumber() const;
    void setPhoneNumber(const QStringList &phoneNumber);

signals:
    void nameChanged();
    void adressChanged ();
    void checksDateChanged();
    void phoneNumberChanged();
public slots:

private:
    QString m_name;
    QString m_adress;
    QDate m_checksDate;
    QStringList m_phoneNumber;
};
#endif // TRIVAGOENTRY_H
