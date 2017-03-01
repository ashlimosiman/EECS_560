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
          Queue<Node*> lvlList;

          /*RECURSIVE METHODS*/
          Node* recInsert(int value, Node* currNode);//done
          void recPre(Node* currNode);//done
          void recIn(Node* currNode);//done
          void recLevel(Node* currNode);//processing
          int findMin(Node* node);//done
          int findMax(Node* node);//done
          bool recRemove(int value);//"Mind bottling"

     public:
          BST();//done
          ~BST();//done
          void insert(int value);//done
          bool remove(int value);//mulling over
          bool search(int value, Node* currNode);//done
          bool deletemin();//done
          bool deletemax();//done
          void preorder();//done
          void inorder();//done
          void levelorder();//done
};
#endif
