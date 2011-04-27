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

}


TEST(ChainingHashTable, SampleInput1)
{
    int sample_input_array[] = {47,     26,     12,     4821,   83621, 
                                18936,  299,    9248,   534,    2147000000,
                                3917,   134895, 187462, 9291,   1846,
                                1872,   93,     23,     52,     91,
                                16,     15,     14,     13,     11};

    int search_key = 134895;
    int expected_search_history[] = {0, 23, 134895};

    list<int> sample_input(sample_input_array, sample_input_array + sizeof(sample_input_array) / sizeof(int));

    Verify_Sample_Data(sample_input, search_key, expected_search_history,3);
}


TEST(ChainingHashTable, SampleInput2)
{
    int sample_input_array[] = {1055625865, 1827521410, 1977619123,
        1650412955, 1937168335, 1955138489, 2092492158, 1567160789, 329568782, 70971576, 299752405, 373677453, 1583791118, 738544302, 1882326005, 57417584, 1659105294, 900128927, 1484464552, 397005233, 1347156295, 188169811, 802112425, 716616484, 2029486611, 1353697904, 172080037, 101461306, 715437487, 1313503011, 1502035504};

    int search_key = 101461306;
    int expected_search_history[] = {3, 101461306};

    list<int> sample_input(sample_input_array, sample_input_array + sizeof(sample_input_array) / sizeof(int));

    Verify_Sample_Data(sample_input, search_key, expected_search_history,2);
}

TEST(ChainingHashTable, SampleInput3)
{
    int sample_input_array[] = {
        2107360220, 297908229, 1081543086, 433401115, 882843345, 687824101, 525742027, 10064633, 83736013, 1097825820, 313753780, 729637484, 602079651, 721523951, 1058056381, 1618499637, 1135935939, 943020467, 395312291, 749298670, 1732953728, 759295658, 1899141334, 394378916, 1729907105, 973336498, 705231947, 1715785415, 346724033, 845245135, 1141098044 }; 
    int search_key = 55;
    int expected_search_history[] = {9, 1729907105, 394378916, 1097825820, 2107360220};

    list<int> sample_input(sample_input_array, sample_input_array + sizeof(sample_input_array) / sizeof(int));

    Verify_Sample_Data(sample_input, search_key, expected_search_history,5);
}
TEST(ChainingHashTable, SampleInput4)
{
    int sample_input_array[] = {1102495079, 608669128, 483235457, 666540954, 262433323, 1437908804, 626778993, 538320464, 679721428, 963653492, 1066232694, 1639741378, 319109394, 853207567, 824532356, 947339931, 1682146868, 497677459, 1501629550, 592576867, 806002235, 896690086, 1651811344, 1540748886, 1939629358, 2120329102, 142486651, 632509040, 1440774507, 707347534, 258372102, 395785938};

    int search_key = 395785938;
    int expected_search_history[] = {6, 395785938 };

    list<int> sample_input(sample_input_array, sample_input_array + sizeof(sample_input_array) / sizeof(int));

    Verify_Sample_Data(sample_input, search_key, expected_search_history,2);
}


