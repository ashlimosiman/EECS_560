#include "minMaxHeap.h"

minMaxHeap::minMaxHeap()
{
     m_heap = new int[200];
     m_size = 0;
}
minMaxHeap::~minMaxHeap()
{
     delete[] m_heap;
}
void minMaxHeap::insert(int value)
{
     m_size++;
     m_heap[m_size] = value;
     bubbleUp(m_size);
}
bool minMaxHeap::deletemin()
{

}
bool minMaxHeap::deletemax()
{

}
void minMaxHeap::levelorder()
{

}
void minMaxHeap::organize()
{

}
void minMaxHeap::initHeap()
{
     for(int x = 0; x < 200; x++)
     {
          m_heap[x] = (-1);
     }
}
bool minMaxHeap::Exists(int value)
{
     for(int x = 1; x <= m_size; x++)
     {
          if(m_heap[x] == value)
          {
               return(true);//found it
          }
     }
     return(false);//didn't find it
}

void minMaxHeap::trickleDown(int pos)
{

}

void minMaxHeap::trickleDownMin(int pos)
{

}

void minMaxHeap::trickleDownMax(int pos)
{

}

void minMaxHeap::bubbleUp(int pos)
{

}

void minMaxHeap::bubbleUpMin(int pos)
{

}

void minMaxHeap::bubbleUpMax(int pos)
{

}

bool minMaxHeap::isMinLevel(int index)
{
     double pos = index;
     int result = int (floor(log2(pos)));

     if(result % 2)
     {
          return(true);//even levels are min levels
     }
     else
     {
          return(false);//odd kevels are max levels
     }

}
