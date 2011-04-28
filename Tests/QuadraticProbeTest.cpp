#include <gtest/gtest.h>
#include <limits.h>
#include <iostream>
#include "QuadraticHashTable.h"
#include "Sample_Input_Data.h"

using namespace std;

void Verify_Sample_Data_Quad(list<int> sample_input, int search_key, int expected_search_history[], int expected_history_size)
{
    QuadraticHashTable::Ptr ht = QuadraticHashTable::construct();
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




TEST(QuadProbingHashTable, Sample1)
{
    int search_key = search_keys[0];
    int expected_search_history[] = { 3, 4};
    
    Verify_Sample_Data_Quad(sample_input_1, search_key, expected_search_history, 2);
       
}
TEST(QuadProbingHashTable, Sample2)
{
    int search_key = search_keys[1];
    int expected_search_history[] = {3, 4, 6, 9, 13, 18, 24, 31, 7, 16, 26};
    Verify_Sample_Data_Quad(sample_input_2, search_key, expected_search_history, 11);
}  

TEST(QuadProbingHashTable, Sample3)
{
    int search_key = search_keys[2];
    int expected_search_history[] = { 31, 0, -1};
    
    Verify_Sample_Data_Quad(sample_input_3, search_key, expected_search_history, 3);
}       
TEST(QuadProbingHashTable, Sample4)
{
    int search_key = search_keys[3];
    int expected_search_history[] = {21, 22, 24, 27, 31, 4, 10, 17, 25, 2, 12, 23, 3, 16, 30};
    
    Verify_Sample_Data_Quad(sample_input_4, search_key, expected_search_history, 15);
}      
TEST(QuadProbingHashTable, Sample5)
{
    int search_key = search_keys[4];
    int expected_search_history[] = {16, 17, 19, 22, 26, 
                                     31, 5,  12, 20, 29, 
                                     7,  18, 30, 11, 25, 
                                     8,  24, 9,  27, 14, 
                                     2,  23, 13, 4,  28, 
                                     21, 15, 10, 6,  3, 
                                     1, 0, -1}; 
    Verify_Sample_Data_Quad(sample_input_5, search_key, expected_search_history, 33);
       
}
