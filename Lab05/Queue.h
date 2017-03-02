#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

#include "OGNode.h"
#include "Node.h"

class Queue
{
	private:
			int m_size;
			OGNode* m_first;
	public:
			Queue();
			~Queue();
			bool isEmpty() const;
			void enqueue(Node* newEntry);
			void dequeue();
			Node* peekFront() const;
};

#endif
