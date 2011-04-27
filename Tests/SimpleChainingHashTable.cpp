#include <gtest/gtest.h>
#include <limits.h>
#include "ChainingHashTable.h"
#include "Sample_Input_Data.h"
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


void Verify_Sample_Data(list<int> sample_input, int search_key, int expected_search_history[], int expected_history_size)
{
    ChainingHashTable::Ptr ht = ChainingHashTable::construct();
    for(list<int>::const_iterator it = sample_input.begin();
            it != sample_input.end();
            ++it)
    {
        ht->Insert(*it);
    }
    
    list<int> history = ht->Historical_Search(search_key);
    EXPECT_EQ(expected_history_size, history.size()); 
    int i = 0;
    for(list<int>::const_iterator itt = history.begin(); i < expected_history_size; ++i, ++itt)
    {
        EXPECT_EQ(expected_search_history[i], *itt);   
    }
    cout << ht->ToString();
}


TEST(ChainingHashTable, SampleInput1)
{
    int search_key = search_keys[0];
    int expected_search_history[] = {0, 23, 134895};


    Verify_Sample_Data(sample_input_1, search_key, expected_search_history,3);
}


TEST(ChainingHashTable, SampleInput2)
{
    int search_key = search_keys[1];
    int expected_search_history[] = {3, 101461306};


    Verify_Sample_Data(sample_input_2, search_key, expected_search_history,2);
}

TEST(ChainingHashTable, SampleInput3)
{
    int search_key = search_keys[2];
    int expected_search_history[] = {9, 1729907105, 394378916, 1097825820, 2107360220};


    Verify_Sample_Data(sample_input_3, search_key, expected_search_history,5);
}
TEST(ChainingHashTable, SampleInput4)
{
    int search_key = search_keys[3];
    int expected_search_history[] = {6, 395785938 };


    Verify_Sample_Data(sample_input_4, search_key, expected_search_history,2);
}


TEST(ChainingHashTable, SampleInput5)
{
    int search_key = search_keys[4];
    int expected_search_history[] = {22 };


    Verify_Sample_Data(sample_input_5, search_key, expected_search_history,1);
}
