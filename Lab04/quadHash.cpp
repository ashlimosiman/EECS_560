#include "quadHash.h"

quadHash::quadHash()
{
     numChecks = 1;
    m_size = 1;
    m_numEntries = 0;
    m_initIndex = (-1);
    m_initExists = false;
    m_table = new int[m_size];
    indexFlag = new bool[m_size];

    initTable();
}

quadHash::quadHash(int size, int checks)
{
     numChecks = checks;
    m_size = size;
    m_numEntries = 0;
    m_initIndex = (-1);
    m_initExists = false;
    m_table = new int[m_size];
    indexFlag = new bool[m_size];

    initTable();
}

quadHash::~quadHash()
{
    delete[] m_table;
    delete[] indexFlag;
}

int quadHash::hash(int key, int check)
{
    int i = check;
    int index = 0;
    int h = ((key % m_size) + (i * i)) % m_size;//producing hash index

    if(i >= numChecks)//checked numChecks times
    {
         return(-2);
    }
    else if(m_table[h] == (-1))//spot available
    {
         index = h;
         /*if(indexFlag[h] == false)//been empty since the dawn of time
         {
              index = h;
         }
         else//emptied by deletion
         {
              if(m_initExists == true)
              {
                   i++;
                   index = hash(key, i);
                   if(index == (-2))//legit index was not found
                   {
                        index = m_initIndex;
                        m_initExists = false;
                   }
              }
              else
              {
                   m_initIndex = h;
                   m_initExists = true;
                   i++;
                   index = hash(key, i);
                   if(index == (-2))//legit index was not found
                   {
                        index = m_initIndex;
                        m_initExists = false;
                   }
              }
         }*/
    }
    else//spot is not available
    {
         i++;
         index = hash(key, i);
    }

    return(index);
}

void quadHash::initTable()
{
    for(int x =0; x < m_size; x++)//setting intial values for hash table to (-1) and flag table to "false"
    {
        m_table[x] = (-1);
        indexFlag[x] = false;
    }
}

void quadHash::insert(int val)
{
     int index = hash(val, 0);//getting hash index for the value

     if(contains(val))//invalid hash index, so it returns
     {
          //std::cout<<val<<" is already in the table.\n";
          return;
     }
     else if(index == (-2))
     {
          std::cout<<"Error: could not place "<<val<<".\n";
          return;
     }
     else//valid hash index, so places value in that index
     {
          m_table[index] = val;
          m_numEntries++;
     }
}

bool quadHash::remove(int val)
{
    if(contains(val))//checking val exists in the hash table
    {
        for(int x = 0; x < m_size; x++)//traversing through the table
        {
            if(m_table[x] == val)//found the value
            {
                m_table[x] = (-1);//change value at the hash index to (-1)
                indexFlag[x] = true;//change value at flag index to "true", so to show a value was deleted at this index
                return(true);//return true since a value was "removed"
            }
        }
    }

    std::cout<<val<<" is not in the table.\n";//value was not removed, so prints error
    return(false);//value was not removed so returns false
}

void quadHash::print() const
{
    for(int x = 0; x < m_size; x++)//traversing through both tables and printing hash values and flag values
    {
        std::cout<<x<<": "<<m_table[x]<<" flag = ";
        if(indexFlag[x] == 0)
        {
             std::cout<<"FALSE\n";
        }
        else
        {
             std::cout<<"TRUE\n";
        }
    }
}

bool quadHash::contains(int key) const
{
    for(int x = 0; x < m_size; x++)//traversing through hash table
    {
        if(m_table[x] == key)//checking if the key in already in the table
        {
            return(true);//value is already in the hash table
        }
    }
    return(false);//value is not in the hash table
}
