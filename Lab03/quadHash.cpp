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

void quadHash::initTable()
{
    for(int x =0; x < m_size; x++)
    {
        m_table[x] = (-1);
        indexFlag[x] = false;
    }
}

int quadHash::hash(int key)
{
    int i = 0;
    //check if table contains key
    //int h = ((key % m_size) + (i * i)) % m_size;
    //return if m_table[h] == (-1) && indexFlag[h] == false
    //else keep going until ???
}

void quadHash::insert(int val)
{
    //get a valid hash index from hash()
    //verify it's legit
    //insert if legit index
    //print error if not
    //increment m_numEntries
}

bool quadHash::remove(int val)
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

void quadHash::print() const
{
    for(int x = 0; x < m_size; x++)
    {
        std::cout<<x<<": "<<m_table[x]<<" flag = "<<indexFlag[x]<<'\n';
    }
}

bool quadHash::contains(int key) const
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
