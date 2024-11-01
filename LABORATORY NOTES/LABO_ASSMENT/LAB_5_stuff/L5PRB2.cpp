#include <iostream>
#include <limits>
#include <string> // Enables use of the standard string class for handling text
#include <algorithm> // Required for using std::max

int main() {
                                                                                            // Top-left block pattern with offset
    for (int i = 0; i < 4; ++i) {                                                                   // Loop for 4 rows

        for (int j = 0; j < 4; ++j) {                                                       // Loop for 4 columns
            std::cout << "+ ";                                                              // Print '+'
        }
        std::cout << std::endl;                                                 // Move to the next line after printing 4 '+'
    }

    std::cout << std::endl;                                                     // Blank line between patterns

    // Bottom-right triangle pattern with offset
    for (int i = 1; i <= 4; ++i) {                                                      // Loop for incremental rows from 1 to 4
        for (int j = 0; j < 8; ++j) {                                               // Add 8 spaces offset
            std::cout << " ";
        }
        for (int j = 0; j < i; ++j) {                                           // Loop for printing '+' symbols incrementally
            std::cout << "+ ";                                                  // Print '+'
        }
        std::cout << std::endl;                                                 // Move to the next line
    }

    std::cout << "Press Enter to exit...";                                      // Prompt user to press Enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Wait for user input (Enter)

    return 0; // End the program
}
