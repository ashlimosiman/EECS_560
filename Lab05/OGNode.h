#ifndef OGNODE_H
#define OGNODE_H

#include <iostream>

#include "Node.h"

class OGNode
{
	private:
		Node* m_value;
		OGNode* m_next;

	public:

		OGNode();

		void setValue(Node* val);

		Node* getValue() const;

		void setNext(OGNode* next);

		OGNode* getNext() const;
};
#endif
