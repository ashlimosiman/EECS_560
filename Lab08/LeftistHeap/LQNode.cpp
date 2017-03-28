#include "LQNode.h"

LQNode::LQNode()
{
	//defines private variables to their respective 0s
	m_value=nullptr;
	m_next=nullptr;
}

void LQNode::setValue(LHNode* val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value = val;
}

LHNode* LQNode::getValue() const
{
	//returns the LQNode's value
	return(m_value);
}

void LQNode::setNext(LQNode* next)
{
	//sets the private variable, m_next, to the provided value, next
	m_next=next;
}

LQNode* LQNode::getNext() const
{
	//returns the LQNode's next node
	return(m_next);
}
