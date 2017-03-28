#ifndef LH_QUEUE_H
#define LH_QUEUE_H

#include <iostream>
#include <string>

#include "LQNode.h"
#include "LHNode.h"

class LHQueue
{
	private:
			int m_size;
			LQNode* m_first;
	public:
			LHQueue();
			~LHQueue();
			bool isEmpty() const;
			void enqueue(LHNode* newEntry);
			void dequeue();
			LHNode* peekFront() const;
};

#endif
