#ifndef MIN_SKEW_H
#define MIN_SKEW_H

#include <iostream>
#include "SHNode.h"
#include "SHQueue.h"

class minSkew
{
     private:
          int m_size;
          SHNode* m_root;
          SHQueue middleman;
          SHNode* merge(SHNode* first, SHNode* second);
          void recPre(SHNode* curr);
          void recIn(SHNode* curr);

     public:
          minSkew();
          ~minSkew();
          bool isEmpty();
          void insert(int value);
          void deletemin();
          void levelorder();
          void preorder();
          void inorder();
};

#endif
