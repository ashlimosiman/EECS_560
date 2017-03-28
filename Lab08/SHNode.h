#ifndef S_H_NODE_H
#define S_H_NODE_H

#include <iostream>

class SHNode
{
     private:
          int element;
          SHNode* m_right;
          SHNode* m_left;

     public:
          SHNode();

          void setValue(int val);

          int getValue() const;

          void setLeft(SHNode* left);

          void setRight(SHNode* right);

          SHNode* getLeft() const;

          SHNode* getRight() const;
     };

#endif
