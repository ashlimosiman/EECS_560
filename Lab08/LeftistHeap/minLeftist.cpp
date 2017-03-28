#include "minLeftist.h"

minLeft::minLeft()
{
     m_size = 0;
     m_root = nullptr;
}

minLeft::~minLeft()
{
     while(!isEmpty())
     {
          deletemin();
     }
}

bool minLeft::isEmpty()
{
     if(m_size == 0)
     {
          return true;
     }
     else
     {
          return false;
     }
}

void minLeft::insert(int value)
{
     //create a new node with the value passed in
     LHNode* newbie = new LHNode();
     newbie->setValue(value);

     m_root = merge(m_root, newbie);// merge the current heap with the new node

     m_size++;//increment size of heap
}

void minLeft::deletemin()
{
     if(isEmpty())//nothing to deletemin
     {
          return;
     }
     else
     {
          //gain scope on the subtrees from alternate objects
          LHNode* leftSub = m_root->getLeft();
          LHNode* rightSub = m_root->getRight();

          delete m_root;//deleting min value

          m_size--;//decrementing size

          if(leftSub == nullptr)//no left subtree
          {
               m_root = rightSub;
          }
          else if(rightSub == nullptr)//no right subTree
          {
               m_root = leftSub;
          }
          else//left subtree and right subtree both exist
          {
               m_root = merge(leftSub, rightSub);//merging subtrees
          }
     }
}

void minLeft::levelorder()
{
     LHNode* value = nullptr;

     std::cout<<"Levelorder: \n";
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }

     middleman.enqueue(m_root);//placing root on queue
     middleman.enqueue(nullptr);//indicates new level

     while(!middleman.isEmpty())
     {
          value = middleman.peekFront();
          middleman.dequeue();//removing front item

          if(value == nullptr)//print a new line
          {
               std::cout<<'\n';

               if(!middleman.isEmpty())//still more nodes to print
               {
                    value = middleman.peekFront();
                    middleman.dequeue();//removing front item
                    middleman.enqueue(nullptr);//indicates end of this level
               }
               else
               {
                    return;
               }
          }

          std::cout<<value->getValue()<<' ';//printing value

          if(value->getLeft() != nullptr)//pushes left child value onto queue if not empty
          {
               middleman.enqueue(value->getLeft());
          }
          if(value->getRight() != nullptr)//pushes right child value onto queue if not empty
          {
               middleman.enqueue(value->getRight());
          }
     }

     std::cout<<'\n';
}

void minLeft::preorder()
{
     std::cout<<"Preorder: ";
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }
     recPre(m_root);
     std::cout<<'\n';
}

void minLeft::recPre(LHNode* curr)
{
     if(curr == nullptr)
     {
          return;//will not print value, snce node is empty
     }
     else
     {
          std::cout<<curr->getValue()<<' ';//print the value
          recPre(curr->getLeft());//go through left subtree
          recPre(curr->getRight());//go through right subtree
     }
}

void minLeft::inorder()
{
     std::cout<<"Inorder: ";
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }
     recIn(m_root);
     std::cout<<'\n';
}

void minLeft::recIn(LHNode* curr)
{
     if(curr == nullptr)//will not print value, snce node is empty
     {
          return;
     }
     else
     {
          recPre(curr->getLeft());//go through left subtree
          std::cout<<curr->getValue()<<' ';//print the value
          recPre(curr->getRight());//go through right subtree
     }
}

LHNode* minLeft::merge(LHNode* first, LHNode* second)
{
     if(first == nullptr)//first is an empty tree
     {
          return second;
     }
     else if(second == nullptr)//second is an empty tree
     {
          return first;
     }
     else//both are populated trees
     {
          //swap trees if necessary
          if(first->getValue() > second->getValue())
          {
               LHNode* holder = second;
               second = first;
               first = holder;
          }

          LHNode* rightSide = merge(first->getRight(), second);//merging right subtree with second tree
          first->setRight(rightSide);//updating new right subtree

          //deal with the rank value
          if((first->getLeft() == nullptr) || (first->getRight() == nullptr))//doesn't have two children
          {
               first->setRank(1);
          }
          else//has both children
          {
               first->setRank((first->getRight()->getRank()) + 1);
          }

          //hold up rules of a leftist tree
          if(first->getLeft() == nullptr)//no left subtree
          {
               first->setLeft(first->getRight());//move right subtree to the left subtree
               first->setRight(nullptr);//now there's no right subtree, since it was moved to the left side
          }
          else//left subtree exists
          {
               if((first->getLeft()->getRank()) < (first->getRight()->getRank()))//breaking rule of leftist tree, so swap em
               {
                    LHNode* holder = first->getRight();
                    first->setRight(first->getLeft());
                    first->setLeft(holder);
               }
          }
     }

     return first;
}
