
//Part 2.
//Using the same 2 arrays create a function that will search the arrays and output the numbers that are the same.*/

#include <cstddef> // For size_t

void findStuffInCommon(const int* data, const int* data1, size_t sizeOfDataArray, size_t sizeOfData1Array);
    std::cout << "Here are the things that are in common ";
    bool similarities = false;
    for (size_t dataElem = 0; dataElem < sizeOfDataArray; ++dataElem) {                         // Loop through first array
        for (size_t data1_Elem = 0; data1_Elem < sizeOfData1Array; ++data1_Elem) {                    // Compare each element with second array
            if (data[dataElem] == data1[data1_Elem]) {                              // If elements match
                std::cout << data[dataElem] << " ";                        // Print the common element
                similarities = true;                                // Mark that a common element was found
                break;                                              // Avoid printing the same element multiple times
            }
        }
    }