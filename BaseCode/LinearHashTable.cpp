/**
 * @brief Linear Probing Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#include "LinearHashTable.h"
#include <cmath>
#include <sstream>
#include <cassert>

using std::endl;
using std::stringstream;

LinearHashTable::Ptr LinearHashTable::construct()
{
    LinearHashTable::Ptr c(new LinearHashTable());
    c->self = c;
    return c;
}

LinearHashTable::LinearHashTable():
    m(32),
    A(0.618)
{
   store = new int[m];
   for(int i=0; i < m; ++i)
   {
       store[i] = KEY_NOT_FOUND;
   }
}

LinearHashTable::~LinearHashTable()
{
    delete [] store;
}

int LinearHashTable::Search(int const key) const
{
    return 0;
}

list<int> LinearHashTable::Historical_Search(int const key) const
{
    list<int> search_history;
    for(int i = 0; i < m; ++i)
    {
        int idx = hash(key, i);
        search_history.push_back(idx);
        if(store[idx] == key)
            return search_history;
    }
    return search_history;
}

void LinearHashTable::Insert(int const key)
{   
    for(int i = 0; i < m ; ++i)
    {
        int idx = hash(key, i);
        assert(idx < m);
        if(store[idx] == KEY_NOT_FOUND)
        {
            store[idx] = key;
            return;
        }

    }
    return;
}

string LinearHashTable::ToString() const
{
    stringstream table_dump;
    for(int i = 0; i < m; ++i)
    {
        table_dump << i << '\t' << store[i] << endl;
    }
    table_dump << -1 << endl;
    return table_dump.str();
}

inline int LinearHashTable::h_prime(int const key) const
{
    return floor(m*fmod(key*A,1));
}

inline int LinearHashTable::hash(int const key, int const iteration) const
{
    return ((h_prime(key)+iteration)%m);
}

