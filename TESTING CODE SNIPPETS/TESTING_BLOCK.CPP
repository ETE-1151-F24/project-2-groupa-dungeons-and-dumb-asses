
#include <iostream>                     // For input/output functionality
#include <cstdlib>                      // For rand() function (random number generation)
#include <ctime>                        // For time() function to seed random number generator
#include <limits>                       // For numeric limits to handle input errors
#include <algorithm>   


//--------------------------------------------FUNCTION TO GET USER INPUT FOR YEAR-----------------------------
int getYear() {                                                                              //want function to not accept years before 1900
     int year;                                                                                      // Declare variable to store the input year

    while (true) {
        std::cout << "Enter a year (>= 1900): ";                                                    // Prompt the user for a year
        std::cin >> year;
                                                                                                    //USING ERROR HANDLING FROM MAP PROGRAM
        if (std::cin.fail()) {                                                                      // Check if input is valid
            std::cout << "You may Whisper sweet nothings to me..." << std::endl;
            std::cout << " but Please make your sweet nothings a VALID NUMBER." << std::endl;
            std::cin.clear();                                                                       // Clear error flag on input stream
            std::cin.ignore(1000, '\n');                                                            // Clear any remaining input in the stream
        } else if(year < 1900){
            std::cout << "yeah... THAT'S LIKE A waaay LONG TIME AGO," << std::endl;
            std::cout << "YOU SHOULD JUST START FROM LIKE 1900 AND GOING FORWARD" << std::endl;
        } else {
            return year;
        }
    }
}
                                                                                // Output the entered year to the user
int main() {
    int year = getYear();                                                       // Call [getYear()] to get a valid year and store it in [year]
    std::cout << "You entered year: " << year << std::endl;                     // Output the valid year entered by the user
    return 0;                                                                   // Return 0 to indicate successful completion of the program
}