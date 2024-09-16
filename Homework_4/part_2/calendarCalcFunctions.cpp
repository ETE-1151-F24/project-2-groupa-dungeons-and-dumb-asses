#include "calendar.h"
#include <limits>                       // For numeric limits to handle input errors
#include <iostream>                     // For input/output functionality


//----------------FUNCTION IMPLEMENTATIONS START HERE----------
                                                                                // This file implements the declared functions in calendar.h



//--------------------------------------------FUNCTION TO CHECK FOR A LEAP YEAR-----------------------------
                                                                                // A leap year occurs if:
                                                                                // 1. The year is divisible by 4. or
                                                                                // 2. The year is divisible by 100 and by 400.
bool isLeapYear(int year) {

}
                                                                                // The leap year logic used to adjust the number of days
                                                                                // in February based on if leap year.
//-------------------------------------------------------------

//-------------------------------------------------------------




//--------------------------------------------FUNCTION TO CHECK DAYS IN THE MONTH-----------------------------
int findMonthLength(int year, int month) {
    //switch operator will go her
    // cases will be 1:JAN  2:FEB  3:MAR   4:APR   5:MAY   6:JUN   7:JUL   8:AUG   9:SEP   10:OCT  11:NOV  12:DEC
    // CASES WITH 31 DAYS       :  1,3,5,7,8,10,12
    // CASES WITH 30 DAYS       :  4,6,9,11
    // FEB WITH 28(29 LEAP YEAR):  2

}



//--------------------------------------------FUNCTION TO PRINT THE DAYS OF THE MONTH-----------------------------
void printMonth(int year, int month, int &startDay) {
    //once the year is known, you will be able to know how many days are in february
    //you will also know what day of the week january starts on
    //and from there you will be able to find what day each month starts on
    //then you output the formatting using [setw] syntax


}






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

//--------------------------------------------FUNCTION TO GET USER INPUT FOR MONTH-----------------------------
int getMonth() {                                                                              //want function to not accept years before 1900
     int month;                                                                                      // Declare variable to store the input year

    while (true) {
        std::cout << "Choose a month";                                                    // Prompt the user for a year
        std::cin >> month;
                                                                                                    //USING ERROR HANDLING FROM MAP PROGRAM
        if (std::cin.fail()) {                                                                      // Check if input is valid
            std::cout << "I'm sorry I didn't quite get that" << std::endl;
            std::cout << " Please make your input a 'VALID' NUMBER." << std::endl;
            std::cin.clear();                                                                       // Clear error flag on input stream
            std::cin.ignore(1000, '\n');                                                            // Clear any remaining input in the stream
        } else if(month < 1 || month > 12){
            std::cout << "*facepalm*  please choose a 'VALID' NUMBER.," << std::endl;
    
        } else {
            return month;
        }
    }
}



//--------------------------------------------FUNCTION TO FIND START DAY OF A MONTH BASED ON THE YEAR-----------------------------
// THE YEAR 1900 BEGAN ON A MONDAY
// ANY YEAR BEFORE 1900, DISPLAY AN ERROR MESSAGE 
//
int calculateStartDay(int year) {
    int totalDays = 0;                                                                       //track total number days from 1900 to entered year
    for (int y = 1900; y < year; y++) {
        // Add 365 days for normal years and 366 for leap years
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    // Year 1900 starts on a Monday, so offset by totalDays % 7
    return totalDays % 7; // Returns the start day offset for the given year
}
