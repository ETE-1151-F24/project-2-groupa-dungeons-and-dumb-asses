
#include <iostream>                     // For input/output functionality
#include <cstdlib>                      // For rand() function (random number generation)
#include <ctime>                        // For time() function to seed random number generator
#include <limits>                       // For numeric limits to handle input errors
#include <algorithm> 
#include <iomanip>  

void printMonth(int year, int month, int &startDay) {
    // Determine the number of days in the month
    int monthLength = findMonthLength(year, month);

    // Use a switch statement to print the month name
    switch (month) {
        case 1: std::cout << "  January "; break;
        case 2: std::cout << "  February "; break;
        case 3: std::cout << "  March "; break;
        case 4: std::cout << "  April "; break;
        case 5: std::cout << "  May "; break;
        case 6: std::cout << "  June "; break;
        case 7: std::cout << "  July "; break;
        case 8: std::cout << "  August "; break;
        case 9: std::cout << "  September "; break;
        case 10: std::cout << "  October "; break;
        case 11: std::cout << "  November "; break;
        case 12: std::cout << "  December "; break;
    }

    std::cout << year << "\n";
    std::cout << "  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n";  // Change order of days to start with Monday

    // Adjust startDay so that Monday is day 0, shifting other days accordingly
    startDay = (startDay == 0) ? 6 : startDay - 1;  // Convert Sunday (0) to 6, and shift other days down

    // Print leading spaces for the first week
    for (int i = 0; i < startDay; i++) {
        std::cout << "     ";  // 5 spaces for proper alignment
    }

    // Print each day of the month
    for (int day = 1; day <= monthLength; day++) {
        std::cout << std::setw(5) << day;  // Right-align days with 5-width spacing

        // Check if the current day is the last day of the week (Sunday, which is now day 6)
        if ((startDay + day) % 7 == 0) {
            std::cout << "\n";  // Start a new line after Sunday
        }
    }

    // If the last day of the month doesn't end on a Sunday, add a final newline
    if ((startDay + monthLength) % 7 != 0) {
        std::cout << "\n";
    }

    // Update startDay to the first day of the next month (adjusting back to original Sunday = 0, Monday = 1 system)
    startDay = (startDay + monthLength) % 7;
    startDay = (startDay == 6) ? 0 : startDay + 1;  // Convert Sunday (6) back to 0 for the next month
}
                                                                                // Output the entered year to the user
int main() {

    return 0;                                                                   // Return 0 to indicate successful completion of the program
}