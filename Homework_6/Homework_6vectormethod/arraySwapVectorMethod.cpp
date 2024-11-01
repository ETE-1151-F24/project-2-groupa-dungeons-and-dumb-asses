#include "arraySwapVectorImplementation.cpp"

int main() {
    // C-style arrays
    int data[] {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};

    // Get the sizes of the arrays
    int dataSize = sizeof(data) / sizeof(int);
    int data1Size = sizeof(data1) / sizeof(int);

    // Print the arrays before swapping
    std::cout << "PRE_SWAP ARRAYS" << std::endl;
    printArray(data, dataSize, "data");
    printArray(data1, data1Size, "data1");

    // Convert arrays to vectors
    std::vector<int> vec_data = arrayToVectorConvert(data, dataSize);
    std::vector<int> vec_data1 = arrayToVectorConvert(data1, data1Size);

    // Swap the vectors
    std::swap(vec_data, vec_data1);

    // Resize and reassign the swapped vectors back to arrays
    if (vec_data.size() != dataSize) {
        std::cout << "Resizing data to fit swapped elements" << std::endl;
        int* newData = new int[vec_data.size()];
        vectorToArrayConvert(vec_data, newData);  // Convert swapped vector to newData array

        // Print results after swap
        std::cout << "\nPOST_SWAP ARRAYS" << std::endl;
        printArray(newData, vec_data.size(), "data");
        printArray(data1, data1Size, "data1");  // No change to data1

        delete[] newData;  // Clean up dynamically allocated memory
    } else if (vec_data1.size() != data1Size) {
        std::cout << "Resizing data1 to fit swapped elements" << std::endl;
        int* newData1 = new int[vec_data1.size()];
        vectorToArrayConvert(vec_data1, newData1);  // Convert swapped vector to newData1 array

        // Print results after swap
        std::cout << "\nPOST_SWAP ARRAYS" << std::endl;
        printArray(data, dataSize, "data");  // No change to data
        printArray(newData1, vec_data1.size(), "data1");  // Resized data1

        delete[] newData1;  // Clean up dynamically allocated memory
    } else {
        // If sizes are the same, no resizing needed
        vectorToArrayConvert(vec_data, data);
        vectorToArrayConvert(vec_data1, data1);

        // Print results after swap
        std::cout << "\nPOST_SWAP ARRAYS" << std::endl;
        printArray(data, dataSize, "data");
        printArray(data1, data1Size, "data1");
    }

    std::cout << "Press enter to exit" << std::endl;
    std::cin.get();  // Wait for user input to exit

    return 0;
}
