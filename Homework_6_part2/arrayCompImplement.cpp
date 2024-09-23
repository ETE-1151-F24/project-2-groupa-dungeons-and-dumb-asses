//arrayCompImplement.cpp
#include "arrayCompHeader.h"
#include <iostream>

// Function to find common elements
void findStuffInCommon(const int* data, const int* data1, size_t sizeOfDataArray, size_t sizeOfData1_Array) {
    std::cout << "The following value(s) are shared between the arrays: ";
    bool similarities = false;
    
    for (size_t dataElem = 0; dataElem < sizeOfDataArray; ++dataElem) {                         // Loop through first array
        for (size_t data1_Elem = 0; data1_Elem < sizeOfData1_Array; ++data1_Elem) {             // Compare each element with second array
            if (data[dataElem] == data1[data1_Elem]) {                                          // If matching elements are found
                std::cout << data[dataElem] << " ";                                             // Print the common element
                similarities = true;                                                            // Mark that a common element was found
                break;                                                                          //Avoids printing the same element multiple times
            }
        }
    }
    
    if (!similarities) {
        std::cout << "I didn't find anything in common!" << std::endl;                          // Message if no common elements
    }
    std::cout << std::endl;
}

// Function to print the contents of both arrays
void printoutArrays(const int* data, const int* data1, size_t sizeOfDataArray, size_t sizeOfData1_Array) {

    std::cout << "Array data[]: {";                                                             // Print array 1
    for (size_t datA = 0; datA < sizeOfDataArray; ++datA) {                                     // Use sizeOfDataArray for the second array
        std::cout << data[datA];
        if (datA < sizeOfDataArray - 1) std::cout << ", ";                                      // Add commas between elements
    }
    std::cout << "}" << std::endl;


    std::cout << "Array data1[]: {";                                                            // Print array 2
    for (size_t dat1 = 0; dat1 < sizeOfData1_Array; ++dat1) {                                   // Use sizeOfData1_Array for the second array
        std::cout << data1[dat1];
        if (dat1 < sizeOfData1_Array - 1) std::cout << ", ";                                    // Add commas between elements
    }
    std::cout << "}" << std::endl;

}
