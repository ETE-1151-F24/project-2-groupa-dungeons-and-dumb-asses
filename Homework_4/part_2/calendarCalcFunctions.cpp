#include "calendar.h"
#include <limits>                       // For numeric limits to handle input errors
#include <iostream>                     // For input/output functionality



//--------------------------------------------FUNCTION TO CHECK FOR A LEAP YEAR-----------------------------        
//leap year if either condition is satisfied:                                   //1. The year is multiple of 400.
                                                                                
                                                                                //2. The year is multiple of 4 (year % 4 == 0)...
                                                                                //   and (&&) not multiple of 100 (year % 100 !=0).
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
//----------------------------------------------------------------------------------------------------------




//--------------------------------------------FUNCTION TO CHECK DAYS IN THE MONTH-----------------------------
int findMonthLength(int year, int month) {
    //switch operator will go here
    switch (month) {
    // cases will be 1:JAN  2:FEB  3:MAR   4:APR   5:MAY   6:JUN   7:JUL   8:AUG   9:SEP   10:OCT  11:NOV  12:DEC
    // CASES WITH 31 DAYS       :  1,3,5,7,8,10,12
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31; 
    // CASES WITH 30 DAYS       :  4,6,9,11
        case 4: case 6: case 9: case 11:
            return 30; // Months with 30 days
    // FEB WITH 28(29 LEAP YEAR):  2
        case 2:
            return isLeapYear(year) ? 29 : 28; // February (adjust for leap year) by running leap year check
    }
}
//----------------------------------------------------------------------------------------------------------




//--------------------------------------------FUNCTION TO PRINT THE DAYS OF THE MONTH-----------------------------
void printMonth(int year, int month, int &startDay) {                       //int [&startDay], initializes the variable [startDay] 
                                                                            //and references it so the print function can modify it
    int monthLength = findMonthLength(year, month);

    std::cout << "  " << months[month - 1] << " " << year << std::endl;     // Print the header (month name and year)

    std::cout << year << std::endl;
    std::cout << "  Mon  Tue  Wed  Thu  Fri  Sat  Sun" << std::endl;        // Change order of days to start with Monday

                                                                            //makes sure startDay Monday is day 0, other days adjusted
    startDay = (startDay == 0) ? 6 : startDay - 1;                          // Convert Sunday (0) to 6, and shift other days down

    std::cout << std::setw(startDay * 5) << "";     // Use setw to align the first day properly
                                                    // Explanation: had to look this up on stack overflow and dig to find about what it is doing
                                                    // 2. [std::setw(startDay * 5)]: 
                                                    // [std::setw]  sets the width for the next output.
                                                    //Multiplying startDay by 5 means we leave 5 spaces per day for alignment.
                                                    //Each day in calendar takes up 5 character spaces (a day number plus spacing).
                                                    //if month starts Wednesday (startDay = 2 because index), 
                                                    //it will leave two slots (2 * 5 = 10 spaces) for Monday and Tuesday, 
                                                    //and the first day of month will print under Wednesday.
                                                    //[<< ""] outputs empty string to provide something for std::setw() adjust.
   
    for (int day = 1; day <= monthLength; day++) {              // Print each day of the month (day)
        std::cout << std::setw(5) << day;                       // Right-align days with 5-width spacing
        
        if ((startDay + day) % 7 == 0) {            //Check if current day of week is last day of week (Sunday, which is day 6 by index)
            std::cout << std::endl;                             //Start a new line after Sunday
        }
    }

    if ((startDay + monthLength) % 7 != 0) {                    // If the last day of the month doesn't end on a Sunday, 
        std::cout << std::endl;                                 //add a final newline after last day of the month
    }
}
//----------------------------------------------------------------------------------------------------------





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
//----------------------------------------------------------------------------------------------------------



//--------------------------------------------FUNCTION TO GET USER INPUT FOR MONTH-----------------------------
int getMonth() {                                                                                        // Function to get user input for month
    int month;                                                                                         // Declare variable to store the input month

    while (true) {
        // Display the options for months
        std::cout << "Choose a month by entering the corresponding number:\n";
        std::cout << "[ 1: Jan], [ 2: Feb], [ 3: Mar], [ 4: Apr], [ 5: May], [ 6: Jun]\n";
        std::cout << "[ 7: Jul], [ 8: Aug], [ 9: Sep], [10: Oct], [11: Nov], [12: Dec]\n";
         
        std::cout << "Choose a month (1-12): ";                                                           // Prompt the user for a month
        std::cin >> month;

        // Error handling: Check if input is not a valid number
        if (std::cin.fail()) {  
            std::cout << "I'm sorry, I didn't quite get that." << std::endl;
            std::cout << "Please make your input a 'VALID' NUMBER." << std::endl;
            std::cin.clear();  // Clear error flag on input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear any remaining input
        } else if (month < 1 || month > 12) {  // Check if input is outside valid range (1-12)
            std::cout << "*facepalm* Please choose a 'VALID' NUMBER (1-12)." << std::endl;
        } else {
            return month;  // Return the valid month input
        }
    }
}
//----------------------------------------------------------------------------------------------------------



//--------------------------------------------FUNCTION TO FIND START DAY OF A MONTH BASED ON THE YEAR-----------------------------
// THE YEAR 1900 BEGAN ON A MONDAY
// ANY YEAR BEFORE 1900, DISPLAY AN ERROR MESSAGE 
//
int calculateStartDay(int year) {
    int totalDays = 0;                                                                       //track total number days from 1900 to entered year
    for (int y = 1900; y < year; y++) {
        // Add 365 days for normal years and 366 for leap years
        totalDays += isLeapYear(y) ? 366 : 365;             //uses the is leapyear function to check for extra days
    }
    // Year 1900 starts on a Monday, so offset by totalDays % 7
    return totalDays % 7; // Returns the start day offset for the given year
}
//----------------------------------------------------------------------------------------------------------

