#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include <iostream>

class doubleHash
{
    private:
        int m_size;
        int m_numEntries;
        int* m_table;
        bool* indexFlag;
        int hash(int key, int check);

    public:
        doubleHash();
        doubleHash(int size);
        ~doubleHash();
        void initTable();
        void insert(int val);
        bool remove(int val);
        void print() const;
        bool contains(int key) const;
};

#endif
