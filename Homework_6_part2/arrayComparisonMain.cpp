
//Part 2.
//Using the same 2 arrays create a function that will search the arrays and output the numbers that are the same.*/
#include <iostream>
#include <cstddef> // For size_t


void findStuffInCommon(const int* data, const int* data1, size_t sizeOfDataArray, size_t sizeOfData1_Array){
    std::cout << "Here are the similarities ";
    bool similarities = false;
    for (size_t dataElem = 0; dataElem < sizeOfDataArray; ++dataElem) {                         // Loop through first array
        for (size_t data1_Elem = 0; data1_Elem < sizeOfData1_Array; ++data1_Elem) {             // Compare each element with second array
            if (data[dataElem] == data1[data1_Elem]) {                                          // If matching elements are found
                std::cout << data[dataElem] << " ";                                             // Print whatever th [similarities] are
                similarities = true;                                                            // Mark that a common element was found
                break;                                                                          // Avoid printing the same element multiple times
            }
        }
    }
        if (!similarities) {
        std::cout << "I didnt find squat in her chief!";                                                                    // If no common elements found
    }
    std::cout << std::endl;
}
int main(){
int data[] {1,3,6,7,9};
int data1[] {5,3,3,11};


    size_t sizeOfDataArray = sizeof(data) / sizeof(data[0]);           //used to determine the size of the arrays    
    size_t sizeOfData1_Array = sizeof(data1) / sizeof(data1[0]);       //to be used in a for loop to print

//printing the arrays
std::cout << "Array data[]: {";
for (size_t datA = 0; datA < sizeOfDataArray; ++datA) {                 
    std::cout << data[datA];
    std::cout << "}" << std::endl;
}

std::cout << "Array data1[]: {";
for (size_t dat1 = 0; dat1 < sizeOfDataArray; ++dat1) {
    std::cout << data1[dat1];
    std::cout << "}" << std::endl;
findStuffInCommon( data,  data1, sizeOfDataArray, sizeOfData1_Array)
}
}