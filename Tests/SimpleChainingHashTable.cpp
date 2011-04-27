#include <gtest/gtest.h>
#include <limits.h>
#include "ChainingHashTable.h"
#include <list>
#include <iostream>
using namespace std;

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

TEST(ChainingHashTable, SampleInput1)
{
    int sample_input_array[] = {47,     26,     12,     4821,   83621, 
                                18936,  299,    9248,   534,    2147000000,
                                3917,   134895, 187462, 9291,   1846,
                                1872,   93,     23,     52,     91,
                                16,     15,     14,     13,     11};

    list<int> sample_input(sample_input_array, sample_input_array + sizeof(sample_input_array) / sizeof(int));
    int search_key = 134895;
    int expected_search_history[] = {0, 23, 134895};

    ChainingHashTable::Ptr ht = ChainingHashTable::construct();

    for(list<int>::const_iterator it = sample_input.begin();
            it != sample_input.end();
            ++it)
    {
        ht->Insert(*it);
    }
    
    list<int> history = ht->Historical_Search(search_key);
    int i = 0;
    for(list<int>::const_iterator itt = history.begin(); i < 3; ++i, ++itt)
    {
        EXPECT_EQ(expected_search_history[i], *itt);   
    }
}
