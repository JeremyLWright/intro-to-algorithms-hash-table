/**
 * @brief Linear Probing Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#include "LinearHashTable.h"
#include <cmath>

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
   store = new list<int>[m];
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
    list<int> t;
    return t;
}

void LinearHashTable::Insert(int const key)
{
}

string LinearHashTable::ToString() const
{
    return "";
}

inline int LinearHashTable::h_prime(int const key) const
{
    return floor(m*fmod(key*A,1));
}

inline int LinearHashTable::hash(int const key, int const iteration) const
{
    return h_prime(key)+1;
}

