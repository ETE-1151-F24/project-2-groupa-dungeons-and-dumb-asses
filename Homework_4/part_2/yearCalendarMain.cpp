// Part 2: hard.
// Write a program that prompts the user for a year(like 1900 or 2450) then print the year calendar. This program is slightly challenging and may take you a while to get right. 

// You will need to read up on how to use iomanip to format your output.

// Use Case
// Use for 
// Use if

// January = 31;
// February 29 / 28 Check for Leap years
// March = 31
// April= 30
// May= 31
// June = 30;
// July  = 31;
// August= 31;
// September = 30;
// October = 31;
// November = 30;
// December  = 31;

// Example Output

// Enter a year  :  2024

// Calendar for 2024
// --January 2024 --
//  Mon     Tue     Wed     Thu     Fri     Sat     Sun
//  1       2       3       4       5       6       7
//  8       9       10      11      12      13      14
//  15      16      17      18      19      20      21
//  22      23      24      25      26      27      28
//  29      30      31

//mon5spaceTue5spaceWed5spaceThu5space


//preliminary thinking
//find out if the year is a leap year
// if the year is a leap year, then february has 29 days
//JAN / FEB / MAR / APR / MAY / JUN / JUL / AUG / SEP / OCT / NOV / DEC /
//31    28    31    30    31    30    31    31    30    31    30    31
//WANT TO KNOW WHAT DAY OF THE WEEK THE MONTH STARTS ON
//TEMPLATE SHOULD BE //  Mon     Tue     Wed     Thu     Fri     Sat     Sun

//USING CODE FROM STACK OVERFLOW I FOUND

// A C++ Program to Implement a Calendar
// of an year
#include<bits/stdc++.h>
#include "calendarCalcFunctions.cpp"
using namespace std;
 
int main() {
                                                                                    // Get user input for year and month
    int year = getYear();
    int month = getMonth();                                                                                
    int startWeekDay = calculateStartDay(year);                                     // Calculate the start day of the year

                                                                                    
    printMonth(year, month, startWeekDay);                                          // Print the requested month

  std::cout << std::endl << "Press any key to exit..." << std::endl;  
    std::cin.ignore(); // Ignore the leftover newline character from the previous input
std::cin.get();    // Wait for user input to pause                                                                    // Wait for the user to press any key

    return 0;
}