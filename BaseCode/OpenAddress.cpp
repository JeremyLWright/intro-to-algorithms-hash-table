/**
 * @brief Implementation for the open addressing abstract class
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include "OpenAddress.h"
#include <cassert>
#include <iostream>
#include <sstream>

using std::stringstream;
using std::endl;
OpenAddress::OpenAddress(int const table_size=32):
    m(table_size)
{
    store = new int[m];
    for(int i = 0; i < m; ++i)
    {
        store[i] = KEY_NOT_FOUND;
    }
}


OpenAddress::~OpenAddress()
{
    delete [] store;
}

int OpenAddress::Search(int const key) const
{
    return 0;
}

list<int> OpenAddress::Historical_Search(int const key) const
{
    list<int> search_history;
    for(int i = 0; i < m; ++i)
    {
        int idx = hash(key, i);
        search_history.push_back(idx);
        if(store[idx] == KEY_NOT_FOUND)
            break;
        else if(store[idx] == key)
            return search_history;
    }
    search_history.push_back(-1);
    return search_history;
}

void OpenAddress::Insert(int const key)
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

string OpenAddress::ToString() const
{
    stringstream table_dump;
    for(int i = 0; i < m; ++i)
    {
        table_dump << i << '\t' << store[i] << endl;
    }
    table_dump << -1 << endl;
    return table_dump.str();
}


