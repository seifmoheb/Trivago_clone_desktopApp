#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<list>
#include<QString>
using namespace std;
class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list<QString> *table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(QString x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();
};

#endif // HASH_H
