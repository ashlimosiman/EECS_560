#ifndef LQNODE_H
#define LQNODE_H

#include <iostream>

#include "LHNode.h"

class LQNode
{
	private:
		LHNode* m_value;
		LQNode* m_next;

	public:

		LQNode();

		void setValue(LHNode* val);

		LHNode* getValue() const;

		void setNext(LQNode* next);

		LQNode* getNext() const;
};
#endif
