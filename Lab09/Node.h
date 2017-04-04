#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Node
{
     private:
          int m_order;
          int m_key;
          Node* left;
          Node* right;
          Node* first;

     public:
          Node();
          int getKey() const;
          void setKey(int key);
          Node* getLeft() const;
          void setLeft(Node* n);
          Node* getRight() const;
          void setRight(Node* n);
          Node* getFirst() const;
          void setFirst(Node* n);
          int getOrder() const;
          void setOrder(int order);
};

#endif
