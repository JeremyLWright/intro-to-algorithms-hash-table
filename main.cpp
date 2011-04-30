/**
 * @brief Main Entry Point for the Hash Table Applicaiton
 *
 * @par
 * Copyright Jeremy Wright (c) 2011
 * Creative Commons Attribution-ShareAlike 3.0 Unported License.
 */

#include "DoubleHashTable.h"
#include "LinearHashTable.h"
#include "QuadraticHashTable.h"
#include "ChainingHashTable.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

int main(int argc, const char *argv[])
{
    DoubleHashTable::Ptr double_table = DoubleHashTable::construct();
    LinearHashTable::Ptr linear_table = LinearHashTable::construct();
    QuadraticHashTable::Ptr quad_table = QuadraticHashTable::construct();
    ChainingHashTable::Ptr chain_table = ChainingHashTable::construct();

    ifstream fin(argv[1]);
    ofstream fchain_out("chain.txt");
    ofstream fdouble_out("double.txt");
    ofstream flinear_out("linear.txt");
    ofstream fquad_out("quadratic.txt");

    int input_count;
    fin >> input_count;
    int temp_value;
    while(input_count--)
    {
        fin >> temp_value;
        double_table->Insert(temp_value);
        linear_table->Insert(temp_value);
        quad_table->Insert(temp_value);
        chain_table->Insert(temp_value);
    }
    //Read the Search Key
    int search_key;
    fin >> search_key;

    fchain_out << chain_table->ToString();
    fdouble_out << double_table->ToString();
    flinear_out << linear_table->ToString();
    fquad_out << quad_table->ToString();
 
    list<int> chain_history = chain_table->Historical_Search(search_key);
    for(list<int>::const_iterator itt = chain_history.begin(); itt != chain_history.end(); ++itt)
    {
        fchain_out << *itt << " ";   
    }

    
    list<int> double_history = double_table->Historical_Search(search_key);
    for(list<int>::const_iterator itt = double_history.begin(); itt != double_history.end(); ++itt)
    {
        fdouble_out << *itt << " ";   
    }

    list<int> linear_history = linear_table->Historical_Search(search_key);
    for(list<int>::const_iterator itt = linear_history.begin(); itt != linear_history.end(); ++itt)
    {
        flinear_out << *itt << " ";   
    }

    list<int> quad_history = quad_table->Historical_Search(search_key);
    for(list<int>::const_iterator itt = quad_history.begin(); itt != quad_history.end(); ++itt)
    {
        fquad_out << *itt << " ";   
    }

    return 0;
}
