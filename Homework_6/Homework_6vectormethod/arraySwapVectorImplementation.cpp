// arraySwapVectorImplementation.cpp
#include "arraySwapVectorHeader.h"

//----------------------------------Function to print a C-style array
void printArray(const int* arraySpecified, int sizeOfArray, const std::string& arrayNamedSpecified) {
                                        // [void] indicates that this function does not return any value
                                        // [const int* arr] means that the function accepts a pointer to an integer array.
                                        // [const] ensures that the array elements will not be modified by this function.
                                        // [int sizeOfArray] is the size of the array, which is passed to know how many elements to print.
                                        // [const std::string& arrayName] is name/label of array to print, passed as a constant reference.
                                        // [std::string] is the C++ standard string type. Using [const&] reference avoids unnecessary copying.

    std::cout << arrayNamedSpecified << "[] {"; 
    for (int indexPosition = 0; indexPosition < sizeOfArray; ++indexPosition) {  
                                        // Standard for-loop starts from index 0 and runs until 'indexPosition' is less than 'size'.
                                        // sizeOfArray represents the number of elements in the array.
                                        // The '++indexPosition' increments the value of 'indexPosition' after each iteration of the loop.
    
        std::cout << arraySpecified[indexPosition];  
                                        // 'arraySpecified[indexPosition]' accesses the element at index [indexPosition] of the array [arraySpecified].
                                        // [const int* arraySpecified] is pointer to first element of array, and 'arraySpecified[indexPosition]' is equivalent
                                        // to *(arraySpecified + indexPosition), which fetches the ith element from the pointer 'arraySpecified'.
        if (indexPosition != sizeOfArray - 1) {
            std::cout << ", ";          // Add a comma and space between elements, but not after the last element
        }
    }
    std::cout << "}" << std::endl;      // Close the curly brace and move to the next line
}

//--------------------------------------Function to convert a C-style array to a vector
std::vector<int> arrayToVectorConvert(const int* arraySpecified, int sizeOfArray) {
                                                                // SYNTAX: std::vector<int> vec_data(start_pointer, end_pointer)
                                                                //[arraySpecified] is starting pointer.... 
                                                                //(i.e., the address of the first element)
                                                                // [arraySpecified + sizeOfArray] is the pointer to the end.... 
                                                                //(i.e., just after the last element)
                                                                //sizeOfArray calculates number of elements in the array
    return std::vector<int>(arraySpecified, arraySpecified + sizeOfArray);
}



//--------------------------------------Function to convert a vector back to a C-style array
void vectorToArrayConvert(const std::vector<int>& vecSpecified, int* arraySpecified) {
                                                                            
    std::copy(vecSpecified.begin(), vecSpecified.end(), arraySpecified);    //[std::copy] copies elements from vector back into C-style array
                                                                            // Range [vecSpecified.begin()] to [vecSpecified.end()] defines 
                                                                            //the range to copy
}