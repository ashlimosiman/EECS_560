#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class minMaxHeap
{
     private:
          int* m_heap;
          int m_size;

     public:
          minMaxHeap();
          ~minMaxHeap();
          void insert(int value);
          void deletemin();
          void deletemax();
          void levelorder();
          void create();
          void initHeap();
          bool Exists(int value);
          void trickleDown(int pos);
          void trickleDownMin(int pos);
          void trickleDownMax(int pos);
          void bubbleUp(int pos);
          void bubbleUpMin(int pos);
          void bubbleUpMax(int pos);
          bool isMinLevel(int index);
          int getChildIndex(int index, int child);
          int getParentIndex(int index);
          int getGrandchildIndex(int index, int gchild);
          int getGrandparentIndex(int index);
          int getMinOffspringIndex(int index);
          int getMaxOffspringIndex(int index);
};

#endif
