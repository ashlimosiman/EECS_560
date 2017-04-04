#include "Node.h"

Node::Node()
{
     m_key = 0;
     m_order = 0;
     right = nullptr;
     left = nullptr;
     first = nullptr;
}

int Node::getKey() const
{
     return(m_key);
}

void Node::setKey(int key)
{
     m_key = key;
}

Node* Node::getLeft() const
{
     return(left);
}

void Node::setLeft(Node* n)
{
     left = n;
}

Node* Node::getRight() const
{
     return(right);
}

void Node::setRight(Node* n)
{
     right = n;
}
Node* Node::getFirst() const
{
     return(first);
}

void Node::setFirst(Node* n)
{
     first = n;
}

int Node::getOrder() const
{
     return(m_order);
}

void Node::setOrder(int order)
{
     m_order = order;
}
