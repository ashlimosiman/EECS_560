#ifndef BINOMQUEUE_H
#define BINOMQUEUE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Node.h"

class BinomQueue
{
     private:
          Node* A[64];
          Node* B[64];
          Node* carry;
          int size;
          Node* m_root;

     public:
          BinomQueue();
          ~BinomQueue();
          void initQueues();
          void insert(int key);
          void deletemin();
          void merge();
          Node* join(Node* a, Node* b);
          void levelorder();
          void unlink();
          void unlinkB();
          void reviseOrder();
          void recReviseOrder(Node* node);
          void reviseRoot();
          void relink();
          void relinkB();
};

#endif
