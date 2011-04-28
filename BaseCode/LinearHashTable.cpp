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
    OpenAddress(32),
    m(32),
    A(0.618)
{
}

LinearHashTable::~LinearHashTable()
{
}

inline int LinearHashTable::h_prime(int const key) const
{
    return floor(m*fmod(key*A,1));
}

inline int LinearHashTable::hash(int const key, int const iteration) const
{
    return ((h_prime(key)+iteration)%m);
}

