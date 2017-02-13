#include "doubleHash.h"

doubleHash::doubleHash()
{
    m_size = 1;
    m_numEntries = 0;
    indexFlag = new bool[m_size];
    m_table = new int[m_size];
}

doubleHash::doubleHash(int size)
{
    m_size = size;
    m_numEntries = 0;
    indexFlag = new bool[m_size];
    m_table = new int[m_size];
}

doublehash::~doubleHash()
{
    delete[] m_table;
    delete[] m_indexFlag;
}

int doubleHash::hash(int key, int check)
{
    int p = 5;
    int i = check;
    int hPlus = 5 - (key % 5);

    if(contains(key))//it's in the table
    {
         std::cout<<key<<" is already in the table.\n";
         return(-1);
    }
    else if(i >= m_size)//after m_size checks, could not place value
    {
         std::cout<<"Error: could not place value.\n";
         return(-1);
    }
    else//finding hash value
    {

         //HOW TO GET BACK TO INITIAL "TRUE" AVAILABLE SPOT

         int index = 0;
         int h = ((key % m_size) + (i * hPlus)) % m_size;//producing hash index
         if(m_table[h] == (-1))//check if space is available
         {
             if(indexFlag[h] == true)//check if it has had a value before
             {
                  index = hash(key, i++);//see if there is an available space without deletion
             }
             else
             {
                  return(h);
             }
         }
         else//space isn't available
         {
              index = hash(key, i++);
         }
    }
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
    if(index == (-1))//hash() returned (-1) and printed error, so returns
    {
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

void doubleHash::print()
{
    for(int x = 0; x < m_size; x++)//traversing through the tables and printing values and flag values
    {
        std::cout<<x<<": "<<m_table[x]<<" flag = "<<indexFlag[x]<<'\n';
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
