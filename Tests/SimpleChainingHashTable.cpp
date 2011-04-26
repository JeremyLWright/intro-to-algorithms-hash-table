#include <gtest/gtest.h>
#include <limits.h>
#include "ChainingHashTable.h"

TEST(ChainingHashTable, SimpleInsert)
{
    ChainingHashTable::Ptr ht = ChainingHashTable::construct();
    for(int i = 0; i < 1500; ++i)
    {
        ht->Insert(i);
    }

    for(int i = 0; i < 1500; ++i)
    {
        EXPECT_EQ(i, ht->Search(i));
    }
}

TEST(ChainingHashTable, EmptySearch)
{
    ChainingHashTable::Ptr ht = ChainingHashTable::construct();
    for (int i = 0; i < 200; ++i) {
        EXPECT_EQ(IHashTable::KEY_NOT_FOUND, ht->Search(i));
    }
}
