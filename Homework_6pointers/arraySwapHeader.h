#ifndef ARRAYSWAPHEADER_H
#define ARRAYSWAPHEADER_H


//-------------------INCLUDES-------------------------------
#include <cstddef> // For size_t


//-------------------Preliminary initialization of functions-----------------

// Function to swap arrays using XOR
void swapArrays(int* data, int* data1, size_t sizeData, size_t sizeData1);

// Function to print an array
void printArray(const int* arr, size_t size, const char* name);

#endif // End of include guard