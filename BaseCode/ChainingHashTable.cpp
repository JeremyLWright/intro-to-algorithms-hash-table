#include "ChainingHashTable.h"


ChainingHashTable::Ptr ChainingHashTable::construct()
{
    ChainingHashTable::Ptr c(new ChainingHashTable());
    c->self = c;
    return c;
}

ChainingHashTable::ChainingHashTable():
    m(23)
{
    store = new list<int>[m];
}

ChainingHashTable::~ChainingHashTable()
{
    delete [] store;
}

int ChainingHashTable::Search(int const key) const
{
    int idx = hash(key);
    if(!store[idx].empty())
    {
        //Get an interator to the list element
        for(list<int>::const_iterator it = store[idx].begin();
                it != store[idx].end();
                ++it)
        {
            if(*it == key)
                return *it;
        }
    }
    
    return KEY_NOT_FOUND;
}

void ChainingHashTable::Insert(int const key)
{
    int idx = hash(key);
    store[idx].push_front(key);
}

inline int ChainingHashTable::hash(int const key) const
{
    return key % m;
}
