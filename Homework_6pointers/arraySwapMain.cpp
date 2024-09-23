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

//----------------------------FUNCTION FOR PRELIMINARY PRINTOUT AND SIZE CALCULATION
//void printBeforePlusCalculation();
std::cout << "Before the swap" << std::endl;                                               
//---------------before swap data array printout
    std::cout << "data[] = { ";

        for (int i = 0; i < 5; i++) {                                       //for each element in the array print it out
        std::cout << data[i] << " ";
        }
    std::cout << "}" << std::endl;

//---------------before swap data1 array printout 
    std::cout << "data1[] = { ";      

        for (int i = 0; i < 4; i++) {                                       //for each element in the array print it out
        std::cout << data1[i] << " ";
        }
    std::cout << "}" << std::endl << std::endl;
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
        *ptrData ^= *ptrData1;         // After this step, [ptrData] holds the result of data[i] XOR data1[i]'.

// Step 2: XOR the new value of 'ptrData' with 'ptrData1' and store the result in 'ptrData1'
        // Syntax: *ptrData1 = *ptrData ^ *ptrData1
        // This means: Take the XOR result currently stored in 'ptrData' and XOR it with the value pointed to by 'ptrData1'.
        // Store the result back in the location pointed to by 'ptrData1'.        
        *ptrData1 ^= *ptrData;       // After this step, 'ptrData1' holds the original value of 'data[i]', effectively swapping the values.

// Step 3: XOR the updated 'ptrData' with the updated 'ptrData1' to finalize the swap
        // Syntax: *ptrData = *ptrData ^ *ptrData1
        // This means: Take the XOR result in 'ptrData' and XOR it with the new value in 'ptrData1'.
        // Store the result back in 'ptrData'.
        *ptrData ^= *ptrData1;       // Third XOR operation, swap complete
 // After this step, [ptrData] holds the original value of 'data1[i]', completing the swap.

        // Summary of the swap:
        // - After these three XOR operations, 'ptrData' (data[i]) holds the original value of 'data1[i]',
        //   and 'ptrData1' (data1[i]) holds the original value of 'data[i]'.
        // - The swap is completed without using any temporary variables.
            }

  std::cout << "After the swap" << std::endl;  
    std::cout << "data [] = { ";                                             // Output the [data] array after swapping
    for (size_t i = 0; i < sizeData; ++i) {
        std::cout << data[i] << " ";                                         // Print each element in the [data] array and add a space
    }
    std::cout << "}" << std::endl;
   
    std::cout << "data1 [] = { ";                                            // Output the [data1] array after swapping
    for (size_t i = 0; i < sizeData1; ++i) {
        std::cout << data1[i] << " ";                                        // Print each element in the [data1] array
    }
    std::cout << "}" << std::endl;
std::cout << "press enter to exit" << std::endl;                            //prompt to get a user to press a key
    std::cin.get();
    return 0;
}
