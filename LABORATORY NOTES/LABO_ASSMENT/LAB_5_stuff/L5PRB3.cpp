#include <iostream>
#include <limits>
#include <string> // Enables use of the standard string class for handling text
#include <algorithm> // Required for using std::max

int main() {
    // Top-left block pattern
    int i = 0;
    while (i < 4) {                                                             // Loop for 4 rows
        int j = 0;
        while (j < 4) {                                                             // Loop for 4 columns
            std::cout << "+ ";                              // Print '+'
            ++j;
        }
        std::cout << std::endl;                         // Move to the next line after printing 4 '+'
        ++i;
    }

    std::cout << std::endl;                                     // Blank line between patterns

    // Bottom-right triangle pattern with offset
    i = 1;                                                      // Initialize row counter
    while (i <= 4) {                                            // Loop for incremental rows from 1 to 4
        int j = 0;

        // Add 8 spaces offset
        while (j < 8) {
            std::cout << " ";
            ++j;
        }

        // Print '+' symbols incrementally
        j = 0;
        while (j < i) {
            std::cout << "+ ";
            ++j;
        }
        
        std::cout << std::endl; // Move to the next line
        ++i;
    }

    std::cout << "Press Enter to exit..."; // Prompt user to press Enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Wait for user input (Enter)

    return 0; // End the program
}

