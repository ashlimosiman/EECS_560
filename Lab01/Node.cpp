#include "Node.h"

Node::Node()
{
	//defines private variables to their respective 0s
	m_value=0;
	m_next=nullptr;
    m_prev=nullptr;
}

void Node::setValue(int val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value=val;
}

int Node::getValue() const
{
	//returns the Node's value
	return(m_value);
}

void Node::setNext(Node* prev)
{
	//sets the private variable, m_next, to the provided value, prev
	m_next=prev;
}

void Node::setPrev(Node* node)
{
    //sets the private variable, m_prev, to the provided value, node
    m_prev=node;
}

Node* Node::getNext() const
{
	//returns the Node's Next Node it's pointing at
	return(m_next);
}

Node* Node::getPrev() const
{
    //returns the Node's previous node to which it's connected
    return(m_prev);
}
