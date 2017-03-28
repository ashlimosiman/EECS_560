#ifndef SH_QUEUE_H
#define SH_QUEUE_H

#include <iostream>
#include <string>

#include "SQNode.h"
#include "SHNode.h"

class SHQueue
{
	private:
			int m_size;
			SQNode* m_first;
	public:
			SHQueue();
			~SHQueue();
			bool isEmpty() const;
			void enqueue(SHNode* newEntry);
			void dequeue();
			SHNode* peekFront() const;
};

#endif
