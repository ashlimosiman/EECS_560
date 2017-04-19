#include "Node.h"

Node::Node()
{
     first = 0;
     second = 0;
     next = nullptr;
     length = 0;
}

int Node::getFirst() const
{
     return(first);
}

void Node::setFirst(int value)
{
     first = value;
}

int Node::getSecond() const
{
     return(second);
}

void Node::setSecond(int value)
{
     second = value;
}

Node* Node::getNext() const
{
     return(next);
}

void Node::setNext(Node* n)
{
     next = n;
}

int Node::getLength() const
{
     return(length);
}

void Node::setLength(int value)
{
     length = value;
}
