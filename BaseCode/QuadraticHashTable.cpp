/**
 * @brief Quadtratic Probing implementation
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#include "QuadraticHashTable.h"
#include <cmath>

QuadraticHashTable::Ptr QuadraticHashTable::construct()
{
    QuadraticHashTable::Ptr c(new QuadraticHashTable());
    c->self = c;
    return c;
}

QuadraticHashTable::QuadraticHashTable():
    OpenAddress(32),
    A(0.618),
    c1(0.5),
    c2(0.5)
{
}

QuadraticHashTable::~QuadraticHashTable()
{
}

inline int QuadraticHashTable::h_prime(int const key) const
{
    return floor(m*fmod(key*A, 1));
}

inline int QuadraticHashTable:: hash(int const key, int const iteration) const
{
    return ((int)(h_prime(key)+c1*iteration+c2*pow(iteration, 2))%m);
}


