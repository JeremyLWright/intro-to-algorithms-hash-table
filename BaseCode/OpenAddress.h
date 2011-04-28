/**
 * @brief Abstract class for the open addressing technique
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef OPENADDRESS_ASIW0OCG
#define OPENADDRESS_ASIW0OCG

#include <tr1/memory>
#include "IHashTable.h"
#include <list>

using std::list;
using std::string;

class OpenAddress : public IHashTable
{
public:
    virtual ~OpenAddress();
    virtual int Search(int const key) const;
    virtual list<int> Historical_Search(int const key) const;
    virtual void Insert(int const key);
    virtual string ToString() const;
    virtual int h_prime(int const key) const = 0;
    virtual int hash(int const key, int const iteration) const = 0;
protected:
    int* store;
    int const m;
    OpenAddress();
    OpenAddress(int const table_size);
    
};

#endif /* end of include guard: OPENADDRESS_ASIW0OCG */
