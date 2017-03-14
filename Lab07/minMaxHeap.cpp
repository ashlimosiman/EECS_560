#include "minMaxHeap.h"

minMaxHeap::minMaxHeap()
{
     m_heap = new int[200];
     m_size = 0;

     initHeap();
     create();
     for(int x=1; x <= m_size; x++)
     {
          std::cout<<m_heap[x]<<' ';
     }
     std::cout<<"\n\n"<<m_size<<"\n\n";
}
minMaxHeap::~minMaxHeap()
{
     delete[] m_heap;
}
void minMaxHeap::insert(int value)
{
     m_size++;
     m_heap[m_size] = value;
     bubbleUp(m_size);
}
void minMaxHeap::deletemin()
{
     //find index of min value
     int min = 1;
     for(int x = 2; x <= m_size; x++)
     {
          if(m_heap[x] < min)//smaller than current value
          {
               min = x;//update min
          }
     }

     //replace min value with last value
     m_heap[min] = m_heap[m_size];
     m_heap[m_size] = (-1);//reset value of last "node"
     m_size--;//decrement size

     trickleDown(min);
}
void minMaxHeap::deletemax()
{
     //find index of max value
     int max = 1;
     for(int x = 2; x <= m_size; x++)
     {
          if(m_heap[x] > m_heap[max])//bigger than current value
          {
               max = x;
          }
     }

     //replace max value with last value
     m_heap[max] = m_heap[m_size];
     m_heap[m_size] = (-1);//reset value of last "node"
     m_size--;

     trickleDown(max);
}
void minMaxHeap::levelorder()
{
     std::cout<<"Levelorder:\n\n";

     if(m_heap[1] == (-1))
     {
          std::cout<<"Empty\n";
     }
     else
     {
          int multiple = 1;//will be exponent of 2, in this case, 2^0
          int printed = 0;

          for(int x = 1; x <= m_size; x++)
          {
               std::cout<<m_heap[x]<<' ';

               if(x == (printed + multiple))//currPos is equivalent to number of elements printed plus multiple
               {
                    std::cout<<'\n';//print next level
                    multiple = multiple*2;
                    printed = x;
               }
          }
     }
     std::cout<<"\n\n";

}
void minMaxHeap::create()
{
     //fills heap initially
     std::ifstream file;
     int value = 0;
     int pos = 1;
     file.open("data.txt");
     while(file>>value)
     {
          m_size++;
          m_heap[pos] = value;
          pos++;
     }
     file.close();

     //bottom up organizing
     for(int x = getParentIndex(m_size); x > 0; x--)
     {
          trickleDown(x);
     }
}
void minMaxHeap::initHeap()
{
     for(int x = 0; x < 200; x++)
     {
          m_heap[x] = (-1);
     }
}
bool minMaxHeap::Exists(int value)
{
     for(int x = 1; x <= m_size; x++)
     {
          if(m_heap[x] == value)
          {
               return(true);//found it
          }
     }
     return(false);//didn't find it
}

void minMaxHeap::trickleDown(int pos)
{
     if(isMinLevel(pos))//on the min level
     {
          trickleDownMin(pos);
     }
     else//on the max level
     {
          trickleDownMax(pos);
     }
}

void minMaxHeap::trickleDownMin(int pos)
{
     int min = getMinOffspringIndex(pos);

     if(pos == getGrandparentIndex(min))//it's a grandchild
     {
          if(m_heap[min] < m_heap[pos])//grandchild is less than grandparent
          {
               //swap values
               int temp = m_heap[pos];
               m_heap[pos] = m_heap[min];
               m_heap[min] = temp;

               int parent = getParentIndex(min);

               if(m_heap[min] > m_heap[parent])//comparing value to the parent, in a max level
               {
                    //swap values
                    temp = m_heap[parent];
                    m_heap[parent] = m_heap[min];
                    m_heap[min] = temp;
               }
               trickleDownMin(min);
          }
     }
     else//it's a child
     {
          if(m_heap[min] < m_heap[pos])//child is smaller than parent
          {
               //swap values
               int temp = m_heap[pos];
               m_heap[pos] = m_heap[min];
               m_heap[min] = temp;
          }
     }
}

void minMaxHeap::trickleDownMax(int pos)
{
     int max = getMaxOffspringIndex(pos);

     if(pos == getGrandparentIndex(max))//it's a grandchild
     {
          if(m_heap[max] > m_heap[pos])//grandchild is greater than grandparent
          {
               //swap values
               int temp = m_heap[pos];
               m_heap[pos] = m_heap[max];
               m_heap[max] = temp;

               int parent = getParentIndex(max);

               if(m_heap[max] < m_heap[parent])//comparing value to the parent, in a min level
               {
                    //swap values
                    temp = m_heap[parent];
                    m_heap[parent] = m_heap[max];
                    m_heap[max] = temp;
               }
               trickleDownMax(max);
          }
     }
     else//it's a child
     {
          if(m_heap[max] > m_heap[pos])//child is greater than parent
          {
               //swap values
               int temp = m_heap[pos];
               m_heap[pos] = m_heap[max];
               m_heap[max] = temp;
          }
     }
}

void minMaxHeap::bubbleUp(int pos)
{
     int parent = getParentIndex(pos);
     if(isMinLevel(pos))
     {
          if((parent > 1) && (m_heap[pos] > m_heap[parent])) //has a parent and is greater than parent's value
          {
               //swap values
               int temp = m_heap[parent];
               m_heap[parent] = m_heap[pos];
               m_heap[pos] = temp;

               bubbleUpMax(parent);
          }
          else
          {
               bubbleUpMin(pos);
          }
     }
     else
     {
          if((parent > 1) && (m_heap[pos] < m_heap[parent])) //has a parent and is greater than parent's value
          {
               //swap values
               int temp = m_heap[parent];
               m_heap[parent] = m_heap[pos];
               m_heap[pos] = temp;

               bubbleUpMin(parent);
          }
          else
          {
               bubbleUpMax(pos);
          }
     }
}

void minMaxHeap::bubbleUpMin(int pos)
{
     int grandparent = getGrandparentIndex(pos);

     if(grandparent > 0)//has a grandparent
     {
          if(m_heap[pos] < m_heap[grandparent])//smaller than grandparent value
          {
               //swap values
               int temp = m_heap[grandparent];
               m_heap[grandparent] = m_heap[pos];
               m_heap[pos] = temp;

               bubbleUpMin(grandparent);
          }
     }
}

void minMaxHeap::bubbleUpMax(int pos)
{
     int grandparent = getGrandparentIndex(pos);

     if(grandparent > 0)//has a grandparent
     {
          if(m_heap[pos] > m_heap[grandparent])//bigger than grandparent value
          {
               //swap values
               int temp = m_heap[grandparent];
               m_heap[grandparent] = m_heap[pos];
               m_heap[pos] = temp;

               bubbleUpMax(grandparent);
          }
     }
}

bool minMaxHeap::isMinLevel(int index)
{
     double pos = index;
     int result = int (floor(log2(pos)));//level of the index

     if(result % 2)
     {
          return(true);//even levels are min levels
     }
     else
     {
          return(false);//odd kevels are max levels
     }

}

int minMaxHeap::getChildIndex(int index, int child)//child must be 0 or 1
{
     //child of i is 2*1+child
     int childPos = (2*index)+child;

     if(childPos > m_size)
     {
          return(-1);//child doesn't exist
     }
     else
     {
          return(childPos);
     }
}

int minMaxHeap::getParentIndex(int index)
{
     if(index == 1)//root
     {
          return(-1);
     }
     else
     {
          return(int (floor(index/2)));
     }
}

int minMaxHeap::getGrandchildIndex(int index, int gchild)//gchild must be 0, 1, 2, or 3
{
     int gchildPos = (4*index)+gchild;
     if(gchildPos < m_size)
     {
          return(-1);//doesn't exist
     }
     else
     {
          return(gchildPos);//found it
     }

}

int minMaxHeap::getGrandparentIndex(int index)
{
     if(index < 4)//root and two children
     {
          return(-1);
     }
     else
     {
          return(int (floor(index/4)));
     }
}

int minMaxHeap::getMinOffspringIndex(int index)
{
     int min = 0;
     int firstChild = getChildIndex(index, 0);
     int secondChild = getChildIndex(index, 0);
     int firstG = getGrandchildIndex(index, 0);
     int secondG = getGrandchildIndex(index, 1);
     int thirdG = getGrandchildIndex(index, 2);
     int fourthG = getGrandchildIndex(index, 3);

     if(firstChild > 0)//checks for child
     {
          min = firstChild;//sets as min value

          if(secondChild > 0)//checks for second child
          {
               if(m_heap[secondChild] < min)//checks if smaller than current min value
               {
                    min = secondChild;//resets min value
               }

               if(firstG > 0)//checks for first grandchild
               {
                    if(m_heap[firstG] < min)//checks if smaller than current min value
                    {
                         min = firstG;//reset min value
                    }

                    if(secondG > 0)//check for second grandchild
                    {
                         if(m_heap[secondG] < min)//checks if smaller than current min value
                         {
                              min = secondG;//resets min value
                         }

                         if(thirdG > 0)//checks for third grandchild
                         {
                              if(m_heap[thirdG] < min)//checks if smaller than current min value
                              {
                                   min = thirdG;//resets min value
                              }

                              if(fourthG > 0)//checks for fourth grandchild
                              {
                                   if(m_heap[fourthG] < min)//checks if smaller than current min value
                                   {
                                        min = fourthG;//resets min value
                                   }
                              }
                         }
                    }
               }
          }
     }

     return(min);//returning index of smallest value
}

int minMaxHeap::getMaxOffspringIndex(int index)
{
     int max = 0;
     int firstChild = getChildIndex(index, 0);
     int secondChild = getChildIndex(index, 0);
     int firstG = getGrandchildIndex(index, 0);
     int secondG = getGrandchildIndex(index, 1);
     int thirdG = getGrandchildIndex(index, 2);
     int fourthG = getGrandchildIndex(index, 3);

     if(firstChild > 0)//checks for child
     {
          max = firstChild;//sets as max value

          if(secondChild > 0)//checks for second child
          {
               if(m_heap[secondChild] > max)//checks if bigger than current min value
               {
                    max = secondChild;//resets max value
               }

               if(firstG > 0)//checks for first grandchild
               {
                    if(m_heap[firstG] > max)//checks if bigger than current min value
                    {
                         max = firstG;//reset max value
                    }

                    if(secondG > 0)//check for second grandchild
                    {
                         if(m_heap[secondG] > max)//checks if bigger than current min value
                         {
                              max = secondG;//resets max value
                         }

                         if(thirdG > 0)//checks for third grandchild
                         {
                              if(m_heap[thirdG] > max)//checks if bigger than current min value
                              {
                                   max = thirdG;//resets max value
                              }

                              if(fourthG > 0)//checks for fourth grandchild
                              {
                                   if(m_heap[fourthG] > max)//checks if bigger than current min value
                                   {
                                        max = fourthG;//resets max value
                                   }
                              }
                         }
                    }
               }
          }
     }

     return(max);//returning index of largest value
}
