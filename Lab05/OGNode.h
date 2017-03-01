#ifndef OGNODE_H
#define OGNODE_H

#include <iostream>

#include "Node.h"

template <typename T>
class OGNode
{
	private:
		int m_value;
		OGNode<T>* m_next;

	public:

		OGNode();

		void setValue(T val);

		T getValue() const;

		void setNext(OGNode<T>* next);

		OGNode<T>* getNext() const;
};
#endif
