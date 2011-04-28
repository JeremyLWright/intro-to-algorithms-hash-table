/**
 * @brief Double Hashing Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef DOUBLEHASHTABLE_EEWMT7Q8
#define DOUBLEHASHTABLE_EEWMT7Q8

#include <tr1/memory>
#include "OpenAddress.h"

class DoubleHashTable : public OpenAddress
{
public:
    typedef std::tr1::shared_ptr<DoubleHashTable> Ptr;
    typedef std::tr1::weak_ptr<DoubleHashTable> WeakPtr;
    static DoubleHashTable::Ptr construct();
    virtual ~DoubleHashTable();
    inline int h_prime(int const key) const;
    inline int hash(int const key, int const iteration) const;
private:
    inline int h1(int const key) const;
    inline int h2(int const key) const;
    int mprime;
    DoubleHashTable();
    DoubleHashTable::WeakPtr self;
    
};

#endif /* end of include guard: DOUBLEHASHTABLE_EEWMT7Q8 */
