// arraySwapVectorHeader.h
#ifndef ARRAYSWAP_H
#define ARRAYSWAP_H
//-------------------INCLUDES-------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//-------------------Declaring global variables-----------------

//-------------------Preliminary initialization of functions-----------------
// Function to print a C-style array
void printArray(const int* arraySpecified, int sizeOfArray, const std::string& arrayNamedSpecified);

// Function to convert a C-style array to a vector
std::vector<int> arrayToVectorConvert(const int* arraySpecified, int sizeOfArray);


// Function to convert a vector back to a C-style array
void vectorToArrayConvert(const std::vector<int>& vecSpecified, int* arraySpecified);

#endif