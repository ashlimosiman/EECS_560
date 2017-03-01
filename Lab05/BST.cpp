#include"BST.h"

BST::BST()
{
     m_root = nullptr;
     m_size = 0;
}

BST::~BST()
{
     while(m_root != nullptr)
     {
          deletemin();
     }
}

void BST::insert(int value)
{
     if(m_root == nullptr)//passed an empty tree
     {
          m_root = new Node();//making a new node to begin the tree
          m_root->setValue(value);//setting the value
          std::cout<<value<<" placed in tree\n";
     }
     else
     {
          if(search(value, m_root))//finds the value in the tree
          {
               std::cout<<"Value exists in tree\n";
               return;
          }

          Node* temp1 = m_root;
          Node* temp2 = recInsert(value, m_root);//finding "home" for new node
          Node* newbie = new Node();
          newbie->setValue(value);//setting value of the new node

          while(temp1->getValue() != temp2->getValue())//finding adoptive node parent
          {
               if(temp2->getValue() < temp1->getValue())//value belongs in the left subtree
               {
                    temp1 = temp1->getLeft();
               }
               else//value belongs in right subtree
               {
                    temp1 = temp1->getRight();
               }
          }

          if(value < temp1->getValue())//new node is the left child
          {
               temp1->setLeft(newbie);
               std::cout<<value<<" placed in tree\n";
          }
          else//new node is the right child
          {
               temp1->setRight(newbie);
               std::cout<<value<<" placed in tree\n";
          }
     }
}

Node* BST::recInsert(int value, Node*currNode)
{
     Node* temp = currNode;
     if(currNode != nullptr)//node isn't empty
     {
          if(value < temp->getValue())//belongs in left subtree
          {
               if(temp->getLeft() != nullptr)//not an empty spot
               {
                    temp = recInsert(value, temp->getLeft());//keep searching
               }
               else//empty spot
               {
                    return(temp);
               }
          }
          else//belongs in right subtree
          {
               if(temp->getRight() != nullptr)//not an empty spot
               {
                    temp = recInsert(value, temp->getRight());//keep searching
               }
               else//empty spot
               {
                    return(temp);
               }
          }
     }
     return(currNode);//currNode is nullptr
}

bool BST::remove(int value)
{
     if(!search(value, m_root))//value not found
     {
          std::cout<<value<<" not found\n";
     }
     else//value exists in tree
     {
          std::cout<<value<<" removed\n";
          return(recRemove(value));
     }
     return(false);//value not removed
}

bool BST::recRemove(int value)
{
     /*
     Three cases
          Barren
               just delete it and set pointer to nullptr
          Single Kid
               delete node and replace with sole heir
          Atomic Fam
               find min value in right subtree
     */
     return(true);
}

bool BST::search(int value, Node* currNode)
{
     bool found = false;
     if(currNode == nullptr)//current node is empty
     {
          found = false;
     }
     else if(currNode->getValue() == value)//current node holds the value
     {
          found = true;
     }
     else if(value < currNode->getValue())//value is in left subtree
     {
          found = search(value, currNode->getLeft());
     }
     else //value > currNode.getValue() // value in right subtree
     {
          found = search(value, currNode->getRight());
     }
     return(found);
}

bool BST::deletemin()
{
     int banished = findMin(m_root);//getting min value in tree
     return(remove(banished));//removing found value
}

int BST::findMin(Node* node)
{
     int min = 0;
     if(node->getRight() == nullptr)//the min value
     {
          min = node->getValue();
     }
     else//not the min value in the tree
     {
          min = findMin(node->getRight());
     }

     return(min);
}

bool BST::deletemax()
{
     int banished = findMax(m_root);//getting max value in tree
     return(remove(banished));//removing the found value
}

int BST::findMax(Node* node)
{
     int max = 0;
     if(node->getLeft() == nullptr)//man value
     {
          max = node->getValue();
     }
     else//not the max value
     {
          max = findMax(node->getLeft());
     }
     return(max);
}

void BST::preorder()
{
     std::cout<<"Preorder: ";
     recPre(m_root);
     std::cout<<'\n';
}

void BST::recPre(Node* currNode)
{
     if(currNode == nullptr)
     {
          return;//will not print value, snce node is empty
     }
     else
     {
          std::cout<<currNode->getValue()<<' ';//print the value
          recPre(currNode->getLeft());//go through left subtree
          recPre(currNode->getRight());//go through right subtree
     }
}

void BST::inorder()
{
     std::cout<<"Inorder: ";
     recIn(m_root);
     std::cout<<'\n';
}

void BST::recIn(Node* currNode)
{
     if(currNode == nullptr)//will not print value, snce node is empty
     {
          return;
     }
     else
     {
          recPre(currNode->getLeft());//go through left subtree
          std::cout<<currNode->getValue()<<' ';//print the value
          recPre(currNode->getRight());//go through right subtree
     }
}

void BST::levelorder()
{
     std::cout<<"Levelorder: ";
     recLevel(m_root);
     std::cout<<'\n';
}

void BST::recLevel(Node* currNode)
{
     /*
     recursively push all values onto Queue
     then print values while popping off the Queue
     */
     if(currNode == nullptr)
     {
          return;
     }
     else
     {
          /*
          NOT RIGHT, BELIEVE IT'S PREORDER
          lvlList.enqueue(currNode->getValue());
          recLevel(currNode->getLeft());
          recLevel(currNode->getRight());
          */
          /*
          perhaps Queue of Type Node*
          then print node value originally passed in push left and right children (if exist) onto Queue
          call method on next node in the list
          pop off the Queue
          push left and right children (if exist) onto Queue
          and so on until all are printed
          */
     }
}
