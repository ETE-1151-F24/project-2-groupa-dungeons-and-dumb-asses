/* assignment promptPart 1:
Given the following arrays swap the data. 
int data[] {1,3,6,7,9};

int data1[] {5,3,3,11};



************************************************************** 
You may not use a tmp value.
IE You may not do the following

 int temp[5];

    //Move data from data1 into temp
    for (size_t i{ 0 }; i < std::size(data); ++i) {
        temp[i] = data1[i];
    }

    //Move data from data to data1
    for (size_t i{ 0 }; i < std::size(data); ++i) {
        data1[i] = data[i];
    }

    //Move data data to data
    for (size_t i{}; i < std::size(temp); ++i) {
        data[i] = temp[i];
    }
**************************************************************************
since i cant use temporary variables i will have to use pointers

Part 2.
Using the same 2 arrays create a function that will search the arrays and output the numbers that are the same.*/

#include <iostream>
#include <algorithm> // for std::swap
#include <iterator>  // for std::size

int main() {
    int data[] {1, 3, 6, 7, 9};    // First array with 5 elements
    int data1[] {5, 3, 3, 11};     // Second array with 4 elements




