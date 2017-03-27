#ifndef MIN_LEFT_H
#define MIN_LEFT_H

class minLeft
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
