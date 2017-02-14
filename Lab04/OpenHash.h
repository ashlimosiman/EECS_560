#ifndef OPEN_HASH_H
#define OPEN_HASH_H

#include <iostream>
#include "LinkedList.h"

class OpenHash
{
     private:
          int m_size;
          int m_numEntries;
          LinkedList* m_table;
          int hash(int key);

     public:
          OpenHash();
          OpenHash(int size);
          ~OpenHash();
          void insert(int val);
          bool remove(int val);
          void print() const;
          bool find(int key) const;
};
#endif
