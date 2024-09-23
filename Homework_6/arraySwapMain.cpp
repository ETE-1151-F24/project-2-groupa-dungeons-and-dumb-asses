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
#include <vector>
#include <algorithm>  // For std::copy

int main() {
    // Initialize two arrays with different sizes
    int data[] = {1, 3, 6, 7, 9};                                           // Array [data] with 5 elements
    int data1[] = {5, 3, 3, 11};                                            // Array [data1] with 4 elements

                                                                            // Determine the sizes of the array element counts
    size_t sizeData = sizeof(data) / sizeof(data[0]);                       //[data] array initialized as a [size_t] datatype named [sizeData]
    size_t sizeData1 = sizeof(data1) / sizeof(data1[0]);                    //[data1] array initialized as a [size_t] datatype named [SizeData1]


 
    // Find the minimum size of the two arrays
    size_t minSize = (sizeData < sizeData1) ? sizeData : sizeData1;

   // Perform element-wise swapping using XOR via pointers
    for (size_t i = 0; i < minSize; ++i) {
        int* ptrData = &data[i];                                            // Pointer to current element in [data]
        int* ptrData1 = &data1[i];                                          // Pointer to current element in [data1]

                                                                            // XOR swap using pointers which are 
                                                                            //***per wikipedia*** "an algorithm that uses the exclusive 
                                                                            //or bitwise operation to swap the values 
                                                                            //of two variables without using the temporary variable 
                                                                            //which is normally required."
        *ptrData ^= *ptrData1;       // First XOR operation
        *ptrData1 ^= *ptrData;       // Second XOR operation
        *ptrData ^= *ptrData1;       // Third XOR operation, swap complete

            }

    
    std::cout << "data: ";                                                   // Output the [data] array after swapping
    for (size_t i = 0; i < sizeData; ++i) {
        std::cout << data[i] << " ";                                         // Print each element in the 'data' array
    }
    std::cout << std::endl;
   
    std::cout << "data1: ";                                                  // Output the [data1] array after swapping
    for (size_t i = 0; i < sizeData1; ++i) {
        std::cout << data1[i] << " ";                                        // Print each element in the 'data1' array
    }
    std::cout << std::endl;

    return 0;
}
