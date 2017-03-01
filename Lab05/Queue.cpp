#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
	//sets private member variables to their respective zeros
	m_size=0;
	m_first=nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while(!(isEmpty()))//removes OGNodes until the Queue is empty
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	if(m_first == nullptr)//determined empty if the pointer equals nullptr
	{
		return(true);
	}
	else//determined not empty if the pointer is looking at a OGNode
	{
		return(false);
	}
}

template <typename T>
void Queue<T>::enqueue(const T& newEntry)
{
	if(isEmpty())//makes a new OGNode with the given value if the Queue is empty
	{
		m_first = new OGNode<T>();
		m_first->setValue(newEntry);
		m_size++;//increases size
	}
	else//runs through the Queue and adds a new OGNode at the end with the given value
	{
		OGNode<T>* temp=m_first;
		OGNode<T>* nextNode=new OGNode<T>();
		nextNode->setValue(newEntry);

		while(temp->getNext() != nullptr)
		{
			temp=temp->getNext();
		}
		temp-> setNext(nextNode);
		temp=temp->getNext();
		temp->setNext(nullptr);
		m_size++;//increases size
	}
}

template <typename T>
void Queue<T>::dequeue()
{
	if(isEmpty())//queue is empty
	{
		return;
	}
	else//removing the first OGNode and making the second OGNode as the first OGNode
	{
		OGNode<T>* temp=m_first;

		m_first=m_first->getNext();

		delete temp;
		temp=nullptr;
		m_size--;//decreasing the size
	}
}

template <typename T>
T Queue<T>::peekFront() const
{
	if(isEmpty())//queue is empty
	{
		return;
	}
	else//returning the value within the first OGNode
	{
		return(m_first->getValue());
	}
}

template <typename T>
void Queue<T>::printQueue() const
{
	if(isEmpty())//prints out 'empty' if the Queue is empty
	{
		std::cout<<"empty.";
	}
	else//will print out all OGNodes in the Queue with a double space inbetween from the first OGNode to the last
	{
		OGNode<T>* temp=m_first;
		while(temp != nullptr)
		{
			std::cout<<temp->getValue()<<"  ";
			temp=temp->getNext();
		}
	}
}
