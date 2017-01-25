#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	private:
		int m_value;
		Node* m_next;
        Node* m_prev;

	public:

		Node();

		void setValue(int val);

		int getValue() const;

		void setNext(Node* prev);

        void setPrev(Node* node);

		Node* getNext() const;

        Node* getPrev() const;
};
#endif
