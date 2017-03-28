#include "SQNode.h"

SQNode::SQNode()
{
	//defines private variables to their respective 0s
	m_value=nullptr;
	m_next=nullptr;
}

void SQNode::setValue(SHNode* val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value = val;
}

SHNode* SQNode::getValue() const
{
	//returns the SQNode's value
	return(m_value);
}

void SQNode::setNext(SQNode* next)
{
	//sets the private variable, l_child, to the provided value, left
	m_next=next;
}

SQNode* SQNode::getNext() const
{
	//returns the SQNode's left child SQNode it's pointing at
	return(m_next);
}
