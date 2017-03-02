#include "OGNode.h"

OGNode::OGNode()
{
	//defines private variables to their respective 0s
	m_value=nullptr;
	m_next=nullptr;
}

void OGNode::setValue(Node* val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value = val;
}

Node* OGNode::getValue() const
{
	//returns the OGNode's value
	return(m_value);
}

void OGNode::setNext(OGNode* next)
{
	//sets the private variable, l_child, to the provided value, left
	m_next=next;
}

OGNode* OGNode::getNext() const
{
	//returns the OGNode's left child OGNode it's pointing at
	return(m_next);
}
