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
#include "arraySwapImplementation.cpp"
#include <iostream>


int main() {
    // Initialize two arrays with different sizes
    int data[] = {1, 3, 6, 7, 9};                                           // Array [data] with 5 elements
    int data1[] = {5, 3, 3, 11};                                            // Array [data1] with 4 elements

                                                                            // Determine the sizes of the array element counts
    size_t sizeData = sizeof(data) / sizeof(data[0]);                       //[data] array initialized as a [size_t] datatype named [sizeData]
    size_t sizeData1 = sizeof(data1) / sizeof(data1[0]);                    //[data1] array initialized as a [size_t] datatype named [SizeData1]

    std::cout << "Before the swap" << std::endl;
    printArray(data, sizeData, "data[]");                                   //use print array function to print data before swap
    printArray(data1, sizeData1, "data1[]");                                //use print array function to print data1 before swap
 
    swapArrays(data, data1, sizeData, sizeData1);                           // perform swapping function of the elements

    std::cout << "After the swap" << std::endl;
    printArray(data, sizeData, "data[]");                                   //use print array function to print data after swap
    printArray(data1, sizeData1, "data1[]");                                //use print array function to print data1 after swap

    std::cout << "}" << std::endl;

    std::cout << "press enter to exit" << std::endl;                            //prompt to get a user to press a key
    std::cin.get();
    return 0;
}
