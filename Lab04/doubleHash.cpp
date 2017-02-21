#include "doubleHash.h"

doubleHash::doubleHash()
{
     numChecks = 1;
    m_size = 1;
    m_numEntries = 0;
    m_initIndex = (-1);
    m_initExists = false;
    indexFlag = new bool[m_size];
    m_table = new int[m_size];

    initTable();
}

doubleHash::doubleHash(int size, int checks)
{
     numChecks = checks;
    m_size = size;
    m_numEntries = 0;
    m_initIndex = (-1);
    m_initExists = false;
    indexFlag = new bool[m_size];
    m_table = new int[m_size];

    initTable();
}

doubleHash::~doubleHash()
{
    delete[] m_table;
    delete[] indexFlag;
}

int doubleHash::hash(int key, int check)
{
    int p = 5;
    int i = check;
    int index = 0;
    int hPlus = p - (key % p);
    int h = ((key % m_size) + (i * hPlus)) % m_size;//producing hash index

    if(i >= numChecks)//after numChecks checks, could not place value
    {

         return(-2);
    }
    else if(m_table[h] == (-1))
    {
         if(indexFlag[h] == false)//been empty since the dawn of time
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
        }
   }
   else//spot is not available
   {
        i++;
        index = hash(key, i);
   }

   return(index);
}

void doubleHash::initTable()
{
    for(int x =0; x < m_size; x++)//making all values in the table (-1) and the flag table all "False"
    {
        m_table[x] = (-1);
        indexFlag[x] = false;
    }
}

void doubleHash::insert(int val)
{
    int index = hash(val, 0);//getting table index
    if(contains(val))//it's in the table
    {
         std::cout<<val<<" is already in the table.\n";
         return;
    }
    else if(index == (-2))//hash() returned (-2) and printed error, so returns
    {
         std::cout<<"Error: could not place "<<val<<".\n";
         return;
    }
    else//got a valid index number and places value
    {
         m_table[index] = val;
         m_numEntries++;
    }
}

bool doubleHash::remove(int val)
{
    if(contains(val))//checking if the value is in the table
    {
        for(int x = 0; x < m_size; x++)//searching table
        {
            if(m_table[x] == val)//found the value
            {
                m_table[x] = (-1);//change value to (-1)
                indexFlag[x] = true;//change flag for the index to true, so to represent a value was deleted from that index
                return(true);//returning true since a value was "deleted"
            }
        }
    }

    std::cout<<val<<" is not in the table.\n";//contains() returned false and printing error
    return(false);//returning false, since the value was not removed
}

void doubleHash::print() const
{
    for(int x = 0; x < m_size; x++)//traversing through the tables and printing values and flag values
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

bool doubleHash::contains(int key) const
{
    for(int x = 0; x < m_size; x++)//traversing through the hash table
    {
        if(m_table[x] == key)//checking is key is already in the table
        {
            return(true);//key is in the table
        }
    }
    return(false);//key is not in the table
}
