#include <gtest/gtest.h>
#include <limits.h>
#include <iostream>
#include "DoubleHashTable.h"
#include "Sample_Input_Data.h"

using namespace std;

void Verify_Sample_Data_Double(list<int> sample_input, int search_key, int expected_search_history[], int expected_history_size)
{
    DoubleHashTable::Ptr ht = DoubleHashTable::construct();
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




TEST(DoubleProbingHashTable, Sample1)
{
    int search_key = search_keys[0];
    int expected_search_history[] = { 14, 30};
    
    Verify_Sample_Data_Double(sample_input_1, search_key, expected_search_history, 2);
       
}
TEST(DoubleProbingHashTable, Sample2)
{
    int search_key = search_keys[1];
    int expected_search_history[] = {11, 28, 14, 0 ,17, 3} ;
    Verify_Sample_Data_Double(sample_input_2, search_key, expected_search_history, 6);
}  

TEST(DoubleProbingHashTable, Sample3)
{
    int search_key = search_keys[2];
    int expected_search_history[] = {24 ,19 ,14 ,9 ,4
        ,30 ,25 ,20 ,15 ,10
            ,5 ,0 ,26 ,21 ,16
            ,11 ,6 ,1 ,27 ,22
            ,17 ,12 ,7 ,2 ,28
            ,23 ,18 ,13 ,8 ,3 
            ,29, -1};
    
    Verify_Sample_Data_Double(sample_input_3, search_key, expected_search_history, 32);
}       
TEST(DoubleProbingHashTable, Sample4)
{
    int search_key = search_keys[3];
    int expected_search_history[] = {10 ,29 ,17 ,5 ,24
        ,12 ,0 ,19 ,7 ,26
            ,14 ,2 ,21 ,9 ,28 
            ,16 ,4 ,23 ,11 ,30 
            ,18 ,6 ,25 ,13, 1
            ,20 ,8 ,27 ,15 ,3 
            ,22, -1};
    
    Verify_Sample_Data_Double(sample_input_4, search_key, expected_search_history, 32);
}      
TEST(DoubleProbingHashTable, Sample5)
{
    int search_key = search_keys[4];
    int expected_search_history[] = {5, 9, 13, 17, 21,
                                    25, 29, 2, 6, 10,
                                    14, 18, 22, 26, 30,
                                    3, 7, 11, 15, 19,
                                    23, 27, 0, 4, 8,
                                    12, 16, 20, 24, 28,
                                    1, -1}; 
    Verify_Sample_Data_Double(sample_input_5, search_key, expected_search_history, 32);
       
}
