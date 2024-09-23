#include "arraySwapHeader.h"                                                      // Include the header file for function declarations
#include <iostream>                                                               // Include the iostream library for input/output operations

// -------------------------Function to swap elements between two arrays using XOR
void swapArrays(int* data, int* data1, size_t sizeData, size_t sizeData1) {   
    size_t minSize = (sizeData < sizeData1) ? sizeData : sizeData1;               // Determine minimum size between arrays to avoid out-of-bounds access
    for (size_t i = 0; i < minSize; ++i) {                                        // Iterate through the elements of both arrays up to the minimum size
        int* ptrData = &data[i];                                                  // Create a pointer to the current element of the first array
        int* ptrData1 = &data1[i];                                                // Create a pointer to the current element of the second array
        *ptrData ^= *ptrData1;                                                    // Perform XOR between the two pointed-to values and store the result in the first array
        *ptrData1 ^= *ptrData;                                                    // XOR the new value in the first array with the value in the second array, storing it in the second array
        *ptrData ^= *ptrData1;                                                    // XOR the updated value in the second array with the first array, finalizing the swap
    }
}

// ------------------------------Function to print the elements of an array
void printArray(const int* arr, size_t size, const char* name) {                   // Function definition for printing an array, accepting the array, its size, and a name for the array
    std::cout << name << " = { ";                                                  // Output the name of the array followed by an opening curly brace
    for (size_t i = 0; i < size; ++i) {                                            // Loop through each element of the array
        std::cout << arr[i] << " ";                                                // Print each element followed by a space
    }
    std::cout << "}" << std::endl;                                                 // Print the closing curly brace and move to the next line
}


//------------------ADDITIONAL COMMENTS OF EXPLANATION
// XOR swap using pointers which are 
                                                                            //***per wikipedia*** "an algorithm that uses exclusive 
                                                                            // or bitwise operation XOR to swap the values 
                                                                            //of two variables without using the temporary variable 
        
    // Step-by-step XOR swap without shorthand
    // *** XOR (^) is a bitwise operator that compares the binary representations of two numbers. 
    // It returns a number where the bits are set to 1 where the corresponding bits of the operands are different.
 
// Step 1: XOR the values and store the result in 'ptrData'
        // Syntax: *ptrData = *ptrData ^ *ptrData1
        // This means: Take the value pointed to by 'ptrData' and XOR it with the value pointed to by 'ptrData1'.
        // The result is stored back in the location pointed to by 'ptrData'.                                                                    //which is normally required."
       //[*ptrData ^= *ptrData1;]         // After this step, [ptrData] holds the result of data[i] XOR data1[i]'.

// Step 2: XOR the new value of 'ptrData' with 'ptrData1' and store the result in 'ptrData1'
        // Syntax: *ptrData1 = *ptrData ^ *ptrData1
        // This means: Take the XOR result currently stored in 'ptrData' and XOR it with the value pointed to by 'ptrData1'.
        // Store the result back in the location pointed to by 'ptrData1'.        
        //[*ptrData1 ^= *ptrData;]       // After this step, 'ptrData1' holds the original value of 'data[i]', effectively swapping the values.

// Step 3: XOR the updated 'ptrData' with the updated 'ptrData1' to finalize the swap
        // Syntax: *ptrData = *ptrData ^ *ptrData1
        // This means: Take the XOR result in 'ptrData' and XOR it with the new value in 'ptrData1'.
        // Store the result back in 'ptrData'.
        //[*ptrData ^= *ptrData1;]       // Third XOR operation, swap complete
 // After this step, [ptrData] holds the original value of 'data1[i]', completing the swap.

        // Summary of the swap:
        // - After these three XOR operations, 'ptrData' (data[i]) holds the original value of 'data1[i]',
        //   and 'ptrData1' (data1[i]) holds the original value of 'data[i]'.
        // - The swap is completed without using any temporary variables.
            