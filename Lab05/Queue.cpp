#include "Queue.h"

Queue::Queue()
{
	//sets private member variables to their respective zeros
	m_size=0;
	m_first=nullptr;
}

Queue::~Queue()
{
	while(!(isEmpty()))//removes OGNodes until the Queue is empty
	{
		dequeue();
	}
}

bool Queue::isEmpty() const
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

void Queue::enqueue(Node* newEntry)
{
	if(isEmpty())//makes a new OGNode with the given value if the Queue is empty
	{
		m_first = new OGNode();
		m_first->setValue(newEntry);
		m_size++;//increases size
	}
	else//runs through the Queue and adds a new OGNode at the end with the given value
	{
		OGNode* temp=m_first;
		OGNode* nextNode=new OGNode();
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

void Queue::dequeue()
{
	if(isEmpty())//queue is empty
	{

	}
	else//removing the first OGNode and making the second OGNode as the first OGNode
	{
		OGNode* temp=m_first;

		m_first=m_first->getNext();

		delete temp;
		temp=nullptr;
		m_size--;//decreasing the size
	}
}

Node* Queue::peekFront() const
{
	if(isEmpty())//queue is empty
	{
		return(nullptr);
	}
	else//returning the value within the first OGNode
	{
		return(m_first->getValue());
	}
}
