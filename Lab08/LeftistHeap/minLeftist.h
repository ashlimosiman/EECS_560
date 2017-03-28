#ifndef MIN_LEFT_H
#define MIN_LEFT_H

#include <iostream>
#include "LHNode.h"
#include "LHQueue.h"

class minLeft
{
     private:
          int m_size;
          LHNode* m_root;
          LHQueue middleman;
          LHNode* merge(LHNode* first, LHNode* second);
          void recPre(LHNode* curr);
          void recIn(LHNode* curr);

     public:
          minLeft();
          ~minLeft();
          bool isEmpty();
          void insert(int value);
          void deletemin();
          void levelorder();
          void preorder();
          void inorder();
};

#endif
