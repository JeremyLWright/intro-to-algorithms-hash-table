#include <gtest/gtest.h>
#include <limits.h>
#include <iostream>
#include "LinearHashTable.h"
#include "Sample_Input_Data.h"

using namespace std;

void Verify_Sample_Data_Linear(list<int> sample_input, int search_key, int expected_search_history[], int expected_history_size)
{
    LinearHashTable::Ptr ht = LinearHashTable::construct();
    int inserts = 1;
    for(list<int>::const_iterator it = sample_input.begin();
            it != sample_input.end();
            ++it)
    {
        ht->Insert(*it);
        inserts++;
    }

    list<int> history = ht->Historical_Search(search_key);
    EXPECT_EQ(expected_history_size, history.size()); 
    int i = 0;
    for(list<int>::const_iterator itt = history.begin(); i < expected_history_size; ++i, ++itt)
    {
        EXPECT_EQ(expected_search_history[i], *itt);   
    }
   // cout << ht->ToString();
}




TEST(LinearProbingHashTable, Sample1)
{
    int search_key = search_keys[0];
    int expected_search_history[] = { 3, 4};
    
    Verify_Sample_Data_Linear(sample_input_1, search_key, expected_search_history, 2);
       
}
TEST(LinearProbingHashTable, Sample2)
{
    int search_key = search_keys[1];
    int expected_search_history[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    
    Verify_Sample_Data_Linear(sample_input_2, search_key, expected_search_history, 12);
}  

TEST(LinearProbingHashTable, Sample3)
{
    int search_key = search_keys[2];
    int expected_search_history[] = { 31, 0, -1};
    
    Verify_Sample_Data_Linear(sample_input_3, search_key, expected_search_history, 3);
}       
TEST(LinearProbingHashTable, Sample4)
{
    int search_key = search_keys[3];
    int expected_search_history[] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6 ,7 ,8, 9 };
    
    Verify_Sample_Data_Linear(sample_input_4, search_key, expected_search_history, 21);
}      
TEST(LinearProbingHashTable, Sample5)
{
    int search_key = search_keys[4];
    int expected_search_history[] = {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1};
    
    Verify_Sample_Data_Linear(sample_input_5, search_key, expected_search_history, 33);
       
}
