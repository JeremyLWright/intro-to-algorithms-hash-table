/**
 * @brief Hash Table Interface Definition
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef IHASHTABLE_40F5FBPD
#define IHASHTABLE_40F5FBPD

#include <tr1/memory>

class IHashTable
{
public:
    virtual ~IHashTable(){};
    enum { KEY_NOT_FOUND = -1};
    virtual int Search(int const key) const = 0;
    virtual void Insert(int const key) = 0;
};


#endif /* end of include guard: IHASHTABLE_40F5FBPD */
