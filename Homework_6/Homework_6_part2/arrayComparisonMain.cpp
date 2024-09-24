//arrayComparisonMain.cpp
//Part 2.
//Using the same 2 arrays create a function that will search the arrays and output the numbers that are the same.*/
#include <iostream>
#include <cstddef> // For size_t
#include "arrayCompHeader.h"
#include "arrayCompImplement.cpp"

int main(){
int data[] {1,3,6,7,9};
int data1[] {5,3,3,11};


    size_t sizeOfDataArray = sizeof(data) / sizeof(data[0]);           //used to determine the size of the arrays    
    size_t sizeOfData1_Array = sizeof(data1) / sizeof(data1[0]);       //to be used in a for loop to print

 printoutArrays(data, data1, sizeOfDataArray, sizeOfData1_Array);
//printing the arrays

findStuffInCommon( data,  data1, sizeOfDataArray, sizeOfData1_Array);

    std::cout << "press enter to exit" << std::endl;                            //prompt to get a user to press a key
    std::cin.get();
return 0;
}


