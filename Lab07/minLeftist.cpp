#include "minLeftist.h"

minLeft::minLeft()
{
     m_size = 0;
     heap = new int[200];

     initHeap();
}

minLeft::~minLeft()
{
     delete[] heap;
}

void minLeft::initHeap()
{
     for(int x = 0; x <200; x++)
     {
          heap[x] = (-1);
     }
}

void minLeft::insert(int value)
{

}

void minLeft::deletemin()
{

}

void minLeft::levelorder()
{

}

void minLeft::preorder()
{

}

void minLeft::inorder()
{
     
}
