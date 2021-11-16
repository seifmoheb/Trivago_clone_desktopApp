#include "hash.h"
#include<QString>
#include<math.h>
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<QString>[BUCKET];
}

void Hash::insertItem(QString key)
{
    string key2 = key.toStdString().c_str();
   /*/ int index = hashFunction(key.QString::toUtf8()); /*/
    //table[index].push_back(key);
}
