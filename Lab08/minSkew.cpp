#include "minSkew.h"

minSkew::minSkew()
{
     m_size = 0;
     m_root = nullptr;
}

minSkew::~minSkew()
{
     while(!isEmpty())
     {
          deletemin();
     }
}

bool minSkew::isEmpty()
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

void minSkew::insert(int value)
{
     //create a new node with the value passed in
     SHNode* newbie = new SHNode();
     newbie->setValue(value);

     m_root = merge(m_root, newbie);// merge the current heap with the new node

     m_size++;//increment size of heap
}

void minSkew::deletemin()
{
     if(isEmpty())//nothing to deletemin
     {
          return;
     }
     else
     {
          //gain scope on the subtrees from alternate objects
          SHNode* leftSub = m_root->getLeft();
          SHNode* rightSub = m_root->getRight();

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

void minSkew::levelorder()
{
     SHNode* value = nullptr;

     std::cout<<"Levelorder: ";
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }

     middleman.enqueue(m_root);//placing root on queue

     while(!middleman.isEmpty())
     {
          value = middleman.peekFront();
          middleman.dequeue();//removing front item
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

void minSkew::preorder()
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

void minSkew::recPre(SHNode* curr)
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

void minSkew::inorder()
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

void minSkew::recIn(SHNode* curr)
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

SHNode* minSkew::merge(SHNode* first, SHNode* second)
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
               SHNode* holder = second;
               second = first;
               first = holder;
          }

          SHNode* rightSide = merge(first->getRight(), second);//merging right subtree with second tree
          first->setRight(rightSide);//updating new right subtree

          //skew heaps swap after every merge
          SHNode* holder = first->getRight();
          first->setRight(first->getLeft());
          first->setLeft(holder);
     }

     return first;
}
