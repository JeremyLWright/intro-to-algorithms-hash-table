#!/bin/sh
#Jeremy Wright
# CSE 310 HW #9
# Hash Tables
g++ -O3 -c ChainingHashTable.cpp
g++ -O3 -c DoubleHashTable.cpp
g++ -O3 -c IHashTable.cpp
g++ -O3 -c LinearHashTable.cpp
g++ -O3 -c main.cpp
g++ -O3 -c OpenAddress.cpp
g++ -O3 -c QuadraticHashTable.cpp
g++ *.o -o main
rm -f *.o chain.txt linear.txt double.txt quadratic.txt
