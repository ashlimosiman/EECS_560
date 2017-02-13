#ifndef QUADRATIC_HASH_H
#define QUADRATIC_HASH_H

#include <iostream>

class quadHash
{
    private:
        int m_size;
        int m_numEntries;
        int* m_table;
        bool* indexFlag;
        int hash(int key, int check);

    public:
        quadHash();
        quadHash(int size);
        ~quadHash();
        void initTable();
        void insert(int val);
        bool remove(int val);
        void print() const;
        bool contains(int key) const;
};
#endif
