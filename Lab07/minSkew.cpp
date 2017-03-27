#include "minSkew.h"

minSkew::minSkew()
{
     m_size = 0;
     heap = new heap[200];

     initHeap();
}

minSkew::~minSkew()
{
     delete[] heap;
}

void minSkew::initHeap()
{
     for(int x = 0; x < 200; x++)
     {
          heap[x] = (-1);
     }
}

void minSkew::insert(int value)
{

}

void minSkew::deletemin()
{

}

void minSkew::preorder()
{

}

void minSkew::inorder()
{

}

void minSkew::levelorder()
{

}
