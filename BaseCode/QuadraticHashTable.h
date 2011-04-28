/**
 * @brief Quadratic Probing Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef QUADRATICHASHTABLE_SE73RZ1H
#define QUADRATICHASHTABLE_SE73RZ1H

#include <tr1/memory>
#include "OpenAddress.h"

class QuadraticHashTable : public OpenAddress
{
public:
    typedef std::tr1::shared_ptr<QuadraticHashTable> Ptr;
    typedef std::tr1::weak_ptr<QuadraticHashTable> WeakPtr;
    static QuadraticHashTable::Ptr construct();
    virtual ~QuadraticHashTable();
    inline int h_prime(int const key) const;
    inline int hash(int const key, int const iteration) const;
private:
    QuadraticHashTable();
    QuadraticHashTable::WeakPtr self;
    double const A;
    double const c1;
    double const c2;
};

#endif /* end of include guard: QUADRATICHASHTABLE_SE73RZ1H */
