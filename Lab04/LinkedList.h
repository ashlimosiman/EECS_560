#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
    private:
        int m_size;

        Node* m_front;

    public:
        LinkedList();

        ~LinkedList();

        int getSize() const;

        bool isEmpty() const;

        bool search(int val) const;

        void addBack(int val);

        void addFront(int val);

        bool removeBack();

        bool removeFront();

        bool removeSelected(int val);

        void printList() const;
};
#endif
