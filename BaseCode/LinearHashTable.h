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
#include "OpenAddress.h"

class LinearHashTable : public OpenAddress
{
public:
    typedef std::tr1::shared_ptr<LinearHashTable> Ptr;
    typedef std::tr1::weak_ptr<LinearHashTable> WeakPtr;
    static LinearHashTable::Ptr construct();
    virtual ~LinearHashTable();
    inline int h_prime(int const key) const;
    inline int hash(int const key, int const iteration) const;
private:
    LinearHashTable();
    LinearHashTable::WeakPtr self;
    double const A;
};

#endif /* end of include guard: LINEARHASHTABLE_EHAIAKL4 */
