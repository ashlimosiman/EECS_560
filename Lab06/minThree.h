#ifndef MIN_THREE_H
#define MIN_THREE_H

#include <iostream>
#include <fstream>
#include <cmath>

class minThreeHeap
{
     private:
          int* m_heap;
          int m_size;
          void organize();

     public:
          minThreeHeap();
          ~minThreeHeap();
          void initHeap();
          void insert(int value);
          bool remove(int value);
          bool deletemin();
          bool deletemax();
          void levelorder();
          bool Exists(int value);
          bool isLeaf(int value);
          int getPos(int value);
          int getmin(int list[]);
};

#endif
