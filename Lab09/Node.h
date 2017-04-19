#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Node
{
     private:
          int m_order;//which binomial it is i.e. B0, B1, B2,...
          int m_key;//value
          Node* left;//left sibling, will wrap around at the end nodes
          Node* right;//right sibling
          Node* first;//just the first child

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
