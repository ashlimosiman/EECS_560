#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

#include "OGNode.h"
#include "Node.h"

template <typename T>
class Queue
{
	private:
			int m_size;
			OGNode<T>* m_first;
	public:
			Queue();
			~Queue();
			bool isEmpty() const;
			void enqueue(const T& newEntry);
			void dequeue();
			T peekFront() const;
			void printQueue() const;
};

#endif
