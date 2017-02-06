#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	private:
		int m_value;
		Node* m_next;

	public:

		Node();

		void setValue(int val);

		int getValue() const;

		void setNext(Node* prev);

		Node* getNext() const;
};
#endif
