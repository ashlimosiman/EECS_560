#include"BST.h"

BST::BST()
{
     m_root = nullptr;
     m_size = 0;
}

BST::~BST()
{
     while(m_root->getLeft() != nullptr)
     {
          deletemin();
     }

     while(m_root->getRight() != nullptr)
     {
          deletemax();
     }

     delete m_root;
}

bool BST::insert(int value)
{
     if(m_root == nullptr)//passed an empty tree
     {
          m_root = new Node();//making a new node to begin the tree
          m_root->setValue(value);//setting the value
     }
     else
     {
          if(search(value, m_root))//finds the value in the tree
          {
               std::cout<<"Value exists in tree\n";
               return(false);
          }

          recInsert(value, m_root);
     }

     return(true);
}

void BST::recInsert(int value, Node*currNode)
{
     if(value < currNode->getValue())//in left subtree
     {
          if(currNode->getLeft() == nullptr)//found a "home"
          {
               Node* newbie = new Node();
               newbie->setValue(value);

               currNode->setLeft(newbie);
          }
          else//keep looking
          {
               recInsert(value, currNode->getLeft());
          }
     }
     else//in right subtree
     {
          if(currNode->getRight() == nullptr)//found a "home"
          {
               Node* newbie = new Node();
               newbie->setValue(value);

               currNode->setRight(newbie);
          }
          else//keep looking
          {
               recInsert(value, currNode->getRight());
          }
     }
}

bool BST::remove(int value)
{
     if(!search(value, m_root))//value not found
     {
          std::cout<<value<<" not found\n";
     }
     else//value exists in tree
     {
          return(recRemove(m_root, value));
     }
     return(false);//value not removed
}

bool BST::recRemove(Node* temp, int value)
{
     /*
     Three cases
          Barren
               just delete it and set pointer to nullptr
          Single Kid
               delete node and replace with sole heir
          Nuclear Fam
               find min value in right subtree
     */
     Node* parent = nullptr;

     while(temp->getValue() != value)
     {
          if(value < temp->getValue())
          {
               parent = temp;
               temp = temp->getLeft();
          }
          else if(value > temp->getValue())
          {
               parent = temp;
               temp = temp->getRight();
          }
          else if(value == temp->getValue())
          {
               break;
          }
     }

     //spinster, or no children
     if((temp->getRight() == nullptr) && (temp->getLeft() == nullptr))
     {
          if(parent->getRight() == temp)
          {
               parent->setRight(nullptr);
          }
          else if(parent->getLeft() == temp)
          {
               parent->setLeft(nullptr);
          }
          delete temp;
          temp = nullptr;
          return(true);
     }

     //sole heir takes over, or has one child
     if(((temp->getRight() != nullptr) && (temp->getLeft() == nullptr)) || ((temp->getRight() == nullptr) && (temp->getLeft() != nullptr)))
     {
          if((temp->getRight() != nullptr) && (temp->getLeft() == nullptr))//right child takes over
          {
               if(parent->getLeft() == temp)
               {
                    parent->setLeft(temp->getRight());
               }
               else if(parent->getRight() == temp)
               {
                    parent->setRight(temp->getRight());
               }
          }
          if((temp->getRight() == nullptr) && (temp->getLeft() != nullptr))//left child takes over
          {
               if(parent->getLeft() == temp)
               {
                    parent->setLeft(temp->getLeft());
               }
               else if(parent->getRight() == temp)
               {
                    parent->setRight(temp->getLeft());
               }
          }
          delete temp;
          temp = nullptr;
          return(true);
     }

     //Nuclear fam, or has two children
     if((temp->getRight() != nullptr) && (temp->getLeft() != nullptr))
     {
          int heir = findMin(temp->getRight());
          temp->setValue(heir);
          recRemove(temp->getRight(), heir);
          return(true);
     }

     return(false);//not removed
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
     if(node->getLeft() == nullptr)//the min value
     {
          min = node->getValue();
     }
     else//not the min value in the tree
     {
          min = findMin(node->getLeft());
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
     if(node->getRight() == nullptr)//man value
     {
          max = node->getValue();
     }
     else//not the max value
     {
          max = findMax(node->getRight());
     }
     return(max);
}

void BST::preorder()
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
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }
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
     Node* value = nullptr;

     std::cout<<"Levelorder: ";
     if(m_root == nullptr)
     {
          std::cout<<"Empty";
          return;
     }

     lvlList.enqueue(m_root);//placing root on queue

     while(!lvlList.isEmpty())
     {
          value = lvlList.peekFront();
          lvlList.dequeue();//removing front item
          std::cout<<value->getValue()<<' ';//printing value

          if(value->getLeft() != nullptr)//pushes left child value onto queue if not empty
          {
               lvlList.enqueue(value->getLeft());
          }
          if(value->getRight() != nullptr)//pushes right child value onto queue if not empty
          {
               lvlList.enqueue(value->getRight());
          }
     }

     std::cout<<'\n';
}

int BST::getMin()
{
     return(findMin(m_root));//returning minimum value in tree
}

int BST::getMax()
{
     return(findMax(m_root));//returning maximum value in tree
}
