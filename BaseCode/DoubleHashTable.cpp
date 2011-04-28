/**
 * @brief Double Hashing Implementation file
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#include "DoubleHashTable.h"
#include <cmath>

DoubleHashTable::Ptr DoubleHashTable::construct()
{
    DoubleHashTable::Ptr c(new DoubleHashTable());
    c->self = c;
    return c;
}

DoubleHashTable::DoubleHashTable():
    OpenAddress(31),
    mprime(30)
{
}

DoubleHashTable::~DoubleHashTable()
{
}

inline int DoubleHashTable::h_prime(int const key) const
{
    return 0;
}

inline int DoubleHashTable::hash(int const key, int const iteration) const
{
    return ((h1(key) + iteration*h2(key))%m);
}

inline int DoubleHashTable::h1(int const key) const
{
    return (key % m);
}

inline int DoubleHashTable::h2(int const key) const
{
    return (1+key%mprime);
}

