#ifndef BST_H
#define BST_H

#include <iostream>

#include "Node.h"
#include "Queue.h"

class BST
{
     private:
          Node* m_root;
          int m_size;
          Queue lvlList;

          /*RECURSIVE METHODS*/
          void recInsert(int value, Node* currNode);
          void recPre(Node* currNode);
          void recIn(Node* currNode);
          int findMin(Node* node);
          int findMax(Node* node);
          bool recRemove(Node* temp, int value);

     public:
          BST();
          ~BST();
          bool insert(int value);
          bool remove(int value);
          bool search(int value, Node* currNode);
          bool deletemin();
          bool deletemax();
          void preorder();
          void inorder();
          void levelorder();
          int getMin();
          int getMax();
};
#endif
