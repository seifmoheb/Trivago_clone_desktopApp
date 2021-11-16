#include "trivagcontroller.h"

TrivagController::TrivagController(Trivago *trivago,QObject *parent)
    : QObject(parent),
    m_trivago (trivago)
{
    Q_ASSERT (trivago != nullptr);  //3ashan net2kd dayman en el member variable is iniallized ely howa m_trivago fel header.
}

TrivagoEntry *TrivagController::creatEntry()
{
    auto result =m_trivago ->creatEntry();
    if (result != nullptr) { //m3nha enna succeful a new entry fe3lan fe el 5atwa ely ba3dha.
    result -> setName("New entry...");
    }

    return result;

}

bool TrivagController::deleteEntry(TrivagoEntry *entry)
{
    return  m_trivago ->deleteEntry(entry);
}
