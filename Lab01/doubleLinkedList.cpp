#include "doubleLinkedList.h"

//USE RECURSIVE WITHIN METHODS

doubleLinkedList::doubleLinkedList()
{
    m_size=0;
    m_front=nullptr;
    m_back=nullptr;
}

doubleLinkedList::~doubleLinkedList()
{
    while(!isEmpty())
    {
        removeBack();
    }
}

int doubleLinkedList::getSize() const
{
    return(m_size);
}

bool doubleLinkedList::isEmpty() const
{
    if(m_front == nullptr)
    {
        return (true);
    }
    else
    {
        return(false);
    }
}

bool doubleLinkedList::search(int val) const
{
    //traverse list looking for val
    //return true if found
    //return false if not found
}

void doubleLinkedList::addBack(int val)
{
    //add val to the back of the list
    //increment m_size
}

void douleLinkedList::addfront(int val)
{
    //add val to the front of the list
    //increment m_size
}

bool doubleLinkedList::removeBack()
{
    //remove last node
    //set the current last node to look at nullptr
    //decrement m_size
}

bool doubleLinkedList::removeFront()
{
    //remove first node
    //list should look at the new first node
    //new first node should look at nullptr
    //decrement m_size
}

bool removeselected(int val)
{
    //remove val from the list
    //return true if found and successfully removed
    //return false if not found
    //make sure to reconnect the list halves
    //decrement m_size
}
