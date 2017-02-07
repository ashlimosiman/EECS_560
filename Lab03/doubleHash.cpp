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

int doubleHash::hash(int key)
{
    int p = 5;
    int i = 0;
    int hPlus = 5 - (key % 5);
    //check if table contains key
    //int h = ((key % m_size) + (i * hPlus)) % m_size;
    //return if m_table[h] == (-1) && indexFlag[h] == false
    //else keep going until ???
}

void doubleHash::initTable()
{
    for(int x =0; x < m_size; x++)
    {
        m_table[x] = (-1);
        indexFlag[x] = false;
    }
}

void doubleHash::insert(int val)
{
    //get a valid hash index from hash()
    //verify it's legit
    //insert if legit index
    //print error if not
    //increment m_numEntries
}

bool doubleHash::remove(int val)
{
    if(contains(val))
    {
        for(int x = 0; x < m_size; x++)
        {
            if(m_table[x] == val)
            {
                m_table[x] = (-1);
                indexFlag[x] = true;
                return(true);
            }
        }
    }

    std::cout<<val<<" is not in the table.\n";
    return(false);
}

void doubleHash::print()
{
    for(int x = 0; x < m_size; x++)
    {
        std::cout<<x<<": "<<m_table[x]<<" flag = "<<indexFlag[x]<<'\n';
    }
}

bool doubleHash::contains(int key) const
{
    for(int x = 0; x < m_size; x++)
    {
        if(m_table[x] == key)
        {
            return(true);
        }
    }
    return(false);
}
