#include "OGNode.h"

template <typename T>
OGNode<T>::OGNode()
{
	//defines private variables to their respective 0s
	m_value=0;
	m_next=nullptr;
}

template <typename T>
void OGNode<T>::setValue(T val)
{
	//sets the private variable, m_value, to the provided value, value
	m_value=val;
}

template <typename T>
T OGNode<T>::getValue() const
{
	//returns the OGNode's value
	return(m_value);
}

template <typename T>
void OGNode<T>::setNext(OGNode<T>* next)
{
	//sets the private variable, l_child, to the provided value, left
	m_next=next;
}

template <typename T>
OGNode<T>* OGNode<T>::getNext() const
{
	//returns the OGNode's left child OGNode it's pointing at
	return(m_next);
}
