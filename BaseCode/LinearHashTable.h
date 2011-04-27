/**
 * @brief Linear Probing Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef LINEARHASHTABLE_EHAIAKL4
#define LINEARHASHTABLE_EHAIAKL4

#include <tr1/memory>
#include "IHashTable.h"
#include <list>

using std::list;
using std::string;

class LinearHashTable : public IHashTable
{
public:
    typedef std::tr1::shared_ptr<LinearHashTable> Ptr;
    typedef std::tr1::weak_ptr<LinearHashTable> WeakPtr;
    static LinearHashTable::Ptr construct();
    virtual ~LinearHashTable();
    virtual int Search(int const key) const;
    virtual list<int> Historical_Search(int const key) const;
    virtual void Insert(int const key);
    virtual string ToString() const;
private:
    LinearHashTable();
    LinearHashTable::WeakPtr self;
    inline int h_prime(int const key) const;
    inline int hash(int const key, int const iteration) const;
    int const m;
    double const A;
    int* store;
    
};

#endif /* end of include guard: LINEARHASHTABLE_EHAIAKL4 */
