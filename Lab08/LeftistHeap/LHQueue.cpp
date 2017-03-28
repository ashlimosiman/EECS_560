#include "LHQueue.h"

LHQueue::LHQueue()
{
	//sets private member variables to their respective zeros
	m_size=0;
	m_first=nullptr;
}

LHQueue::~LHQueue()
{
	while(!(isEmpty()))//removes LQNodes until the Queue is empty
	{
		dequeue();
	}
}

bool LHQueue::isEmpty() const
{
	if(m_first == nullptr)//determined empty if the pointer equals nullptr
	{
		return(true);
	}
	else//determined not empty if the pointer is looking at a LQNode
	{
		return(false);
	}
}

void LHQueue::enqueue(LHNode* newEntry)
{
	if(isEmpty())//makes a new LQNode with the given value if the Queue is empty
	{
		m_first = new LQNode();
		m_first->setValue(newEntry);
		m_size++;//increases size
	}
	else//runs through the Queue and adds a new LQNode at the end with the given value
	{
		LQNode* temp=m_first;
		LQNode* nextNode=new LQNode();
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

void LHQueue::dequeue()
{
	if(isEmpty())//queue is empty
	{

	}
	else//removing the first LQNode and making the second LQNode as the first LQNode
	{
		LQNode* temp=m_first;

		m_first=m_first->getNext();

		delete temp;
		temp=nullptr;
		m_size--;//decreasing the size
	}
}

LHNode* LHQueue::peekFront() const
{
	if(isEmpty())//queue is empty
	{
		return(nullptr);
	}
	else//returning the value within the first LQNode
	{
		return(m_first->getValue());
	}
}
