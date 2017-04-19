#include "BinomQueue.h"

BinomQueue::BinomQueue()
{
     m_root = nullptr;
     size = 0;
     carry = nullptr;

     initQueues();
}

BinomQueue::~BinomQueue()
{
     while(m_root != nullptr)//nodes are still in the Binomial Queue
     {
          deletemin();
     }
}

void BinomQueue::initQueues()
{
     for(int x = 0; x < 64; x++)
     {
          A[x] = nullptr;
          B[x] = nullptr;
     }
}

void BinomQueue::insert(int key)
{
     //create new node with key passed in
     Node* temp = new Node();
     temp->setKey(key);
     temp->setLeft(temp);

     B[0] = temp;//start it in B's binomial queue
     merge();//merge with rest of queue
     size++;//increase size by one

     unlink();
     relink();
     reviseRoot();
     reviseOrder();
}

void BinomQueue::deletemin()
{
     if(m_root == nullptr)//empty queue
     {
          return;
     }
     //getting min node and its index
     Node* minVal = m_root;
     int pos = m_root->getOrder();

     for(int x = 0; x < 64; x++)
     {
          if(A[x] != nullptr)//populated
          {
               if(A[x]->getKey() < minVal->getKey())//need to update minVal
               {
                    pos = x;
                    minVal = A[x];
               }
          }
     }

     Node* child = minVal->getFirst();//gets the first child, so scope isn't lost on tree
     unlink();

     //remove the minimum Node
     delete minVal;
     minVal = nullptr;
     size--;//decrease size by one

     if(child != nullptr)//NOT barren
     {
          int num = 0;
          while(child-> getRight() != nullptr)
          {
               B[num] = child;
               child = child->getLeft();
          }
          unlinkB();
          relinkB();

          merge();
     }
     unlink();
     relink();
     reviseRoot();
     reviseOrder();
}

void BinomQueue::merge()
{
     /*
          *   for loop/Switch-case: 8 cases
          *    Table on note sheet
          carryBA
          000       nothing
          001       nothing
          010       A[i] = B[i]; B[i] = nullptr;
          011       carry = join(A[i], B[i]); A[i] = nullptr; B[i] = nullptr;
          100       A[i] = carry; carry = nullptr;
          101       carry = join(A[i], carry); A[i] = nullptr;
          110       carry = join(B[i], carry); B[i] = nullptr;
          111       carry = join(B[i], carry); B[i] = nullptr;
     */

     for(int x = 0; x < 64; x++)
     {
          if((A[x] == nullptr) && (B[x] == nullptr) && (carry == nullptr))//000
          {
               //do nothing
          }
          else if((A[x] != nullptr) && (B[x] == nullptr) && (carry == nullptr))//001
          {
               //do nothing
          }
          else if((A[x] == nullptr) && (B[x] != nullptr) && (carry == nullptr))//010
          {
               A[x] = B[x];
               B[x] = nullptr;
          }
          else if((A[x] != nullptr) && (B[x] != nullptr) && (carry == nullptr))//011
          {
               carry = join(A[x], B[x]);
               A[x] = nullptr;
               B[x] = nullptr;
          }
          else if((A[x] == nullptr) && (B[x] == nullptr) && (carry != nullptr))//100
          {
               A[x] = carry;
               carry = nullptr;
          }
          else if((A[x] != nullptr) && (B[x] == nullptr) && (carry != nullptr))//101
          {
               carry = join(A[x], carry);
               A[x] = nullptr;
          }
          else if((A[x] == nullptr) && (B[x] != nullptr) && (carry != nullptr))//110
          {
               carry = join(B[x], carry);
               B[x] = nullptr;
          }
          else if((A[x] != nullptr) && (B[x] != nullptr) && (carry != nullptr))//111
          {
               carry = join(B[x], carry);
               B[x] = nullptr;
          }
     }
}

Node* BinomQueue::join(Node* a, Node* b)
{
       Node* newLeft = nullptr;
       Node* newRight = nullptr;

       if(a->getKey() > b->getKey())
       {
            return(join(b, a));
       }

       //seperate b from siblings
       newLeft = b->getLeft();
       newRight = b->getRight();
       b->setLeft(nullptr);
       b->setRight(nullptr);

       if(newLeft != nullptr)
       {
            a->setLeft(newLeft);
       }
       if(newRight != nullptr)
       {
            a->setRight(newRight);
            newRight->setLeft(a);
       }

       if(a->getFirst() == nullptr)
       {
            a->setFirst(b);
            b->setLeft(b);
       }
       else
       {
            Node* lastLeaf = a->getFirst()->getLeft();

            b->setLeft(lastLeaf);
            lastLeaf->setRight(b);

            a->getFirst()->setLeft(b);
       }

       return(a);
}

void BinomQueue::levelorder()
{
     /*
          Print:
          level order:
          10
          ---
          1
          5
          ---
          2
          7 9 3
          16 8 4
          6
     */
     Node* temp = nullptr;

     std::cout<<"Levelorder: \n";
     if(m_root == nullptr)//no nodes
     {
          std::cout<<"Empty\n";
     }
     else//populated
     {
          temp = m_root;
          std::cout<<"Not working\n";

     }
}

void BinomQueue::unlink()
{
     //unlinks the trees, not all the nodes
     for(int x = 0; x < 64; x++)//going through the whole queue
     {
          Node* temp = A[x];
          if(temp != nullptr)//not an empty tree
          {
               //unlinking
               temp->setLeft(temp);
               temp->setRight(nullptr);
          }
     }
}

void BinomQueue::unlinkB()
{
     //unlinks the trees, not all the nodes
     for(int x = 0; x < 64; x++)//going through the whole queue
     {
          Node* temp = B[x];
          if(temp != nullptr)//not an empty tree
          {
               //unlinking
               temp->setLeft(temp);
               temp->setRight(nullptr);
          }
     }
}

void BinomQueue::reviseOrder()
{
     for(int x = 0; x < 64; x++)
     {
          recReviseOrder(A[x]);
     }
}
void BinomQueue::recReviseOrder(Node* node)
{
     int ord = 0;
     Node* temp = node;
     while(temp != nullptr)
     {
          temp->setOrder(ord);
          recReviseOrder(temp->getFirst());
          temp = temp->getRight();
          ord++;
     }
}

void BinomQueue::reviseRoot()
{
     int x = 0;
     while(A[x] == nullptr)//find the first tree in queue
     {
          x++;
     }

     m_root = A[x];//set as main root of queue
}

void BinomQueue::relink()
{
     reviseRoot();//set up m_root first

     int pos = m_root->getOrder();//las root node seen
     for(int x = ((m_root->getOrder()) + 1); x < 64; x++)
     {
          if(A[x] != nullptr)
          {
               //connecting siblings
               A[pos]->setRight(A[x]);
               A[x]->setLeft(A[pos]);
               pos = x;//update last root node seen
          }
     }

     //connect left of m_root to last root
     m_root->setLeft(A[pos]);

     //set last root's right to nullptr
     A[pos]->setRight(nullptr);
}

void BinomQueue::relinkB()
{
     int first = (-1);
     int last = (-1);
     int prev = (-1);
     for(int x = 0; x < 64; x++)
     {
          if(B[x] != nullptr)
          {
               if(first < 0)//first root node found already
               {
                    first = x;
               }

               prev = last;
               last = x;//last root node found

               if(prev != (-1))
               {
                    B[prev]->setRight(B[last]);
                    B[last]->setLeft(B[prev]);
               }
          }
     }

     B[first]->setLeft(B[last]);
     B[last]->setRight(nullptr);
}
