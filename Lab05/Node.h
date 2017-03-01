#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	private:
		int m_value;
		Node* l_child;
		Node* r_child;

	public:

		Node();

		void setValue(int val);

		int getValue() const;

		void setLeft(Node* left);

		void setRight(Node* right);

		Node* getLeft() const;

		Node* getRight() const;
};
#endif
