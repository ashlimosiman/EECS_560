#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Node
{
     private:
          int first;//vertex Value
          int second;//vertex Value
          int length;//value between vertices
          Node* next;//next edge

     public:
          Node();
          int getFirst() const;
          void setFirst(int value);
          int getSecond() const;
          void setSecond(int value);
          Node* getNext() const;
          void setNext(Node* n);
          int getLength() const;
          void setLength(int value);
};

#endif
