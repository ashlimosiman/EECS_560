#include "Node.h"

Node::Node()
{
	//defines private variables to their respective 0s
	m_value=0;
	l_child=nullptr;
	r_child=nullptr;
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

void Node::setLeft(Node* left)
{
	//sets the private variable, l_child, to the provided value, left
	l_child=left;
}

void Node::setRight(Node* right)
{
	//sets the private variable, r_child, to the provided value, right
	r_child=right;
}

Node* Node::getLeft() const
{
	//returns the Node's left child Node it's pointing at
	return(l_child);
}

Node* Node::getRight() const
{
	//returns the Node's right child Node it's pointing at
	return(r_child);
}
