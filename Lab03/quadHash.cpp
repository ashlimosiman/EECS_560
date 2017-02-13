#include "quadHash.h"

quadHash::quadHash()
{
    m_size = 1;
    m_numEntries = 0;
    m_table = new int[m_size];
    indexFlag = new bool[m_size];
}

quadHash::quadHash(int size)
{
    m_size = size;
    m_numEntries = 0;
    m_table = new int[m_size];
    indexFlag = new bool[m_size];
}

quadHash::~quadhash()
{
    delete[] m_table;
    delete[] indexFlag;
}

int quadHash::hash(int key, int check)
{
    int i = check;

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
         int h = ((key % m_size) + (i * i)) % m_size;//producing hash index
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

     if(index == (-1))//invalid hash index, so it returns
     {
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
        std::cout<<x<<": "<<m_table[x]<<" flag = "<<indexFlag[x]<<'\n';
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
