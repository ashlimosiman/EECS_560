#ifndef SQNode_H
#define SQNode_H

#include <iostream>

#include "SHNode.h"

class SQNode
{
	private:
		SHNode* m_value;
		SQNode* m_next;

	public:

		SQNode();

		void setValue(SHNode* val);

		SHNode* getValue() const;

		void setNext(SQNode* next);

		SQNode* getNext() const;
};
#endif
