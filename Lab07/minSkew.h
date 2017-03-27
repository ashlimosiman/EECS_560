#ifndef MIN_SKEW_H
#define MIN_SKEW_H

class minSkew
{
     private:
          int m_size;
          int* heap;

     public:
          minLeft();
          ~minLeft();
          void initHeap();
          void insert(int value);
          void deletemin();
          void levelorder();
          void preorder();
          void inorder();
};

#endif
