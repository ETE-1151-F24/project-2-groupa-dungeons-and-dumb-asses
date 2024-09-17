#include "calendar.h"
#include <limits>                       // For numeric limits to handle input errors
#include <iostream>                     // For input/output functionality


//----------------FUNCTION IMPLEMENTATIONS START HERE----------
                                                                                // This file implements the declared functions in calendar.h



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

    //you will also know what day of the week january starts on
    //and from there you will be able to find what day each month starts on
    //then you output the formatting using [setw] syntax
std::cout << "--"<<month<<"--" << std::endl;


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
int getMonth() {                                                                                        //want function guide month choices
     int month;                                                                                         // Declare variable to store the input month

    while (true) {
                                                                                                        // Display the options for months
        std::cout << "Choose a month by entering the corresponding number:\n";
        std::cout << "[ 1: Jan], [ 2: Feb], [ 3: Mar], [ 4: Apr], [ 5: May], [ 6: Jun]\n";
        std::cout << "[ 7: Jul], [ 8: Aug], [ 9: Sep], [10: Oct], [11: Nov], [12: Dec]\n";
         
        std::cout << "Choose a month (1-12): ";                                                           // Prompt the user for a month
        std::cin >> month;
                                                                                                    //USING ERROR HANDLING FROM MAP PROGRAM
        if (std::cin.fail()) {                                                                          // Check if input is valid
            std::cout << "I'm sorry I didn't quite get that" << std::endl;
            std::cout << " Please make your input a 'VALID' NUMBER." << std::endl;
            std::cin.clear();                                                                           // Clear error flag on input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                         // Clear any remaining input in stream
        } else if(month < 1 || month > 12){
            std::cout << "*facepalm*  please choose a 'VALID' NUMBER (1-12).," << std::endl;
    
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
        totalDays += isLeapYear(y) ? 366 : 365;             //uses the is leapyear function to check for extra days
    }
    // Year 1900 starts on a Monday, so offset by totalDays % 7
    return totalDays % 7; // Returns the start day offset for the given year
}
