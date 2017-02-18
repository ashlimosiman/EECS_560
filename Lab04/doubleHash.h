#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include <iostream>

class doubleHash
{
    private:
        int numChecks;
        int m_size;
        int m_numEntries;
        int* m_table;
        bool* indexFlag;
        int m_initIndex;
        bool m_initExists;
        int hash(int key, int check);

    public:
        doubleHash();
        doubleHash(int size, int checks);
        ~doubleHash();
        void initTable();
        void insert(int val);
        bool remove(int val);
        void print() const;
        bool contains(int key) const;
};

#endif
