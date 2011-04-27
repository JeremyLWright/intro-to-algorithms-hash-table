/**
 * @brief Chaining Hash Table
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */
#ifndef CHAININGHASHTABLE_HK442CSE
#define CHAININGHASHTABLE_HK442CSE

#include <tr1/memory>
#include "IHashTable.h"
#include <list>

using std::list;
using std::string;
class ChainingHashTable: public IHashTable
{
public:
    typedef std::tr1::shared_ptr<ChainingHashTable> Ptr;
    typedef std::tr1::weak_ptr<ChainingHashTable> WeakPtr;
    static ChainingHashTable::Ptr construct();
    virtual ~ChainingHashTable();
    virtual int Search(int const key) const;
    virtual list<int> Historical_Search(int const key) const;
    virtual void Insert(int const key);
    virtual string ToString() const;
private:
    ChainingHashTable();
    ChainingHashTable::WeakPtr self;
    inline int hash(int const key) const;
    int const m;
    list<int>* store;
    
};

#endif /* end of include guard: CHAININGHASHTABLE_HK442CSE */
