#include "SHQueue.h"

SHQueue::SHQueue()
{
	//sets private member variables to their respective zeros
	m_size=0;
	m_first=nullptr;
}

SHQueue::~SHQueue()
{
	while(!(isEmpty()))//removes SQNodes until the Queue is empty
	{
		dequeue();
	}
}

bool SHQueue::isEmpty() const
{
	if(m_first == nullptr)//determined empty if the pointer equals nullptr
	{
		return(true);
	}
	else//determined not empty if the pointer is looking at a SQNode
	{
		return(false);
	}
}

void SHQueue::enqueue(SHNode* newEntry)
{
	if(isEmpty())//makes a new SQNode with the given value if the Queue is empty
	{
		m_first = new SQNode();
		m_first->setValue(newEntry);
		m_size++;//increases size
	}
	else//runs through the Queue and adds a new SQNode at the end with the given value
	{
		SQNode* temp=m_first;
		SQNode* nextNode=new SQNode();
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

void SHQueue::dequeue()
{
	if(isEmpty())//queue is empty
	{

	}
	else//removing the first SQNode and making the second SQNode as the first SQNode
	{
		SQNode* temp=m_first;

		m_first=m_first->getNext();

		delete temp;
		temp=nullptr;
		m_size--;//decreasing the size
	}
}

SHNode* SHQueue::peekFront() const
{
	if(isEmpty())//queue is empty
	{
		return(nullptr);
	}
	else//returning the value within the first SQNode
	{
		return(m_first->getValue());
	}
}
