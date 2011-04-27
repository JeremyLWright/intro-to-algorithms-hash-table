#include "ChainingHashTable.h"
#include <sstream>
using std::endl;
using std::stringstream;

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

list<int> ChainingHashTable::Historical_Search(int const key) const
{
    int idx = hash(key);
    list<int> search_history;
    search_history.push_back(idx);

    if(!store[idx].empty())
    {
        for(list<int>::const_iterator it = store[idx].begin();
                it != store[idx].end();
                ++it)
        {
            search_history.push_back(*it);
            if(*it == key)
                break;
        }
    }
    return search_history;

}

string ChainingHashTable::ToString() const
{
    stringstream table_dump;
    for(int i = 0; i < m; ++i)
    {
        table_dump << i << '\t';
        for(list<int>::const_iterator it = store[i].begin();
                it != store[i].end();
                ++it)
        {
            table_dump << *it << " ";
        }
        table_dump << endl;
    }
    table_dump << -1 << endl;
    return table_dump.str();

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
