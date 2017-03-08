#include "minThree.h"

minThreeHeap::minThreeHeap()
{
     m_heap = new int[200];
     m_size = 0;
     initHeap();
}

minThreeHeap::~minThreeHeap()
{
     delete[] m_heap;
}

void minThreeHeap::organize()
{
     int child[3];
     int min = 0;
     int temp = 0;
     int pos = 0;

     if(m_size < 2)//zero or 1 elements is already in order
     {
          return;
     }
     else
     {
          for(int x = m_size-1; x >= 0; x--)
          {
               if(!isLeaf(m_heap[x]))
               {
                    child[0] = m_heap[(3*x)+1];
                    child[1] = m_heap[(3*x)+2];
                    child[2] = m_heap[(3*x)+3];
                    min = getmin(child);

                    if(m_heap[x] > min)
                    {
                         temp = m_heap[x];
                         pos = getPos(min);
                         m_heap[x] = min;
                         m_heap[pos] = temp;
                         organize();
                    }
               }
          }
     }
}

void minThreeHeap::initHeap()//add values from file
{
     for(int x = 0; x < 200; x++)
     {
          m_heap[x] = (-1);
     }

     int newVal = 0;
     int pos = 0;
     std::ifstream file;
     file.open("data.txt");
     while(file>>newVal)
     {
          m_heap[pos] = newVal;
          m_size++;
          pos++;
     }

     file.close();

     organize();
}

void minThreeHeap::insert(int value)
{
     m_size++;//increase size
     m_heap[m_size-1] = value;
     organize();
}

bool minThreeHeap::remove(int value)
{
     if(Exists(value))//on the heap
     {
          int pos = 0;

          while(Exists(value))//removes all copies of the value passed in
          {
               pos = getPos(value);//getting position in heap of value

               m_heap[pos] = m_heap[m_size-1];//replace with last element
               m_heap[m_size-1] = (-1);//remove last element
               m_size--;
               organize();

          }
     }
     else//not on the heap
     {
          std::cout<<"Error: " << value << " is not in heap\n";
          return(false);
     }

     return(true);
}

bool minThreeHeap::deletemin()
{
     //root is the minimum value
     m_heap[0] = m_heap[m_size-1];//replace with last element
     m_heap[m_size-1] = (-1);//remove last element
     m_size--;
     organize();

     return(true);
}

bool minThreeHeap::deletemax()
{
     //leaf
     int max = m_heap[0];
     int maxPos = 0;
     for(int x = 0; x < m_size; x++)
     {
          if(m_heap[x] > max)
          {
               max = m_heap[x];
               maxPos = x;
          }
     }
     //remove that value, ignore repeats
     m_heap[maxPos] = m_heap[m_size-1];//replace with last element
     m_heap[m_size-1] = (-1);//remove last element
     m_size--;
     organize();

     return(true);
}

void minThreeHeap::levelorder()
{
     int currPos = 0;
     int dash = 1;

     std::cout<<"Levelorder:\n\n";

     if(m_heap[0] == (-1))
     {
          std::cout<<"Empty\n";
     }
     else
     {
          while(m_heap[currPos] != (-1))
          {
               std::cout<<m_heap[currPos]<<' ';
               if(currPos == 0)//finished 0th level
               {
                    std::cout<<'\n';
               }
               else if(currPos == 3)//finished 1st level
               {
                    dash = 1;
                    std::cout<<'\n';
               }
               else if(currPos <= 12)
               {
                    if(currPos == 12)//finished second level
                    {
                         std::cout<<'\n';
                         dash = 1;
                    }
                    else if(dash <= 2)
                    {
                         dash++;
                    }
                    else
                    {
                         std::cout<<"- ";
                         dash = 1;
                    }

               }
               else if(currPos <= 39)
               {
                    if(currPos == 39)//finished third level
                    {
                         std::cout<<'\n';
                         dash = 1;
                    }
                    else if(dash <= 2)
                    {
                         dash++;
                    }
                    else
                    {
                         std::cout<<"- ";
                         dash = 1;
                    }

               }
               else if(currPos <= 120)
               {
                    if(currPos == 120)//finished fourth level
                    {
                         std::cout<<'\n';
                         dash = 1;
                    }
                    else if(dash <= 2)
                    {
                         dash++;
                    }
                    else
                    {
                         std::cout<<"- ";
                         dash = 1;
                    }

               }
               else if(currPos <= 199)//fifth level
               {
                    if(dash <= 2)
                    {
                         dash++;
                    }
                    else
                    {
                         std::cout<<"- ";
                         dash = 1;
                    }
               }

               currPos++;//next node
          }
     }
}

bool minThreeHeap::Exists(int value)
{
     for(int x = 0; x < m_size; x++)
     {
          if(m_heap[x] == value)
          {
               return(true);//value found
          }
     }
     return(false);//value not found
}

bool minThreeHeap::isLeaf(int value)
{
     int pos = (-1);//postion of element in question

     for(int x = 0; x < m_size; x++)
     {
          if(m_heap[x] == value)
          {
               pos = x;
          }
     }

     //first child's locations
     int child1 = (3*pos) + 1;

     if(m_heap[child1] == (-1))
     {
          return(true);//it's a leaf, since it must have a first child before a second or third child, and first child does not exist
     }
     else
     {
          return(false);//has at least one child
     }
}

int minThreeHeap::getPos(int value)
{
     for(int x = 0; x < m_size; x++)
     {
          if(m_heap[x] == value)
          {
               return(x);//found
          }
     }

     return(-1);//not found
}

int minThreeHeap::getmin(int list[])
{
     int min = list[0];
     for(int x = 1; x < 3; x++)
     {
          if((list[x] < min) && (list[x] != (-1)))
          {
               min = list[x];
          }
     }

     return(min);
}
