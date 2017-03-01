#include "OpenHash.h"

OpenHash::OpenHash()
{
     m_size = 1;
     m_numEntries = 0;
     m_table = new LinkedList[m_size];
}

OpenHash::OpenHash(int size)
{
     m_size = size;
     m_numEntries = 0;
     m_table = new LinkedList[size];
}

OpenHash::~OpenHash()
{
     delete[] m_table;
}

void OpenHash::insert(int val)
{
     int place = hash(val);
     if(m_table[place].search(val))
     {
          //std::cout<<val<<" is already in the table.\n";
     }
     else
     {
          m_table[place].addFront(val);
          m_numEntries++;
     }
}

bool OpenHash::remove(int val)
{
     if(find(val))
     {
          for(int x = 0; x < m_size; x++)
          {
               if(m_table[x].search(val))
               {
                    m_table[x].removeSelected(val);
                    return(true);
               }
          }
     }

     std::cout<<val<<" is not in the table.\n";
     return(false);
}

void OpenHash::print() const
{
     std::cout<<'\n';
     for(int x = 0; x < m_size; x++)
     {
          std::cout<<x<<": ";
          m_table[x].printList();
     }
     std::cout<<'\n';
}

int OpenHash::hash(int key)
{
     return(key % m_size);
}

bool OpenHash::find(int key) const
{
     for(int x = 0; x < m_size; x++)
     {
          if(m_table[x].search(key))
          {
               return(true);
          }
     }
     return(false);
}

void OpenHash::reset()
{
     for(int x = 0; x < m_size; x++)
     {
          while(!(m_table[x].isEmpty()))
          {
               m_table[x].removeFront();
          }
     }
}
