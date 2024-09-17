#ifndef CALENDAR_H // Include guard to prevent multiple definitions
#define CALENDAR_H
#include <iostream>
#include <iomanip>   // [iomanip] allows for formatting of output and alignment
#include <string>
//GLOBAL VARIABLE DECLARATIONS
int year;
int month;

//FUNCTION DECLARATIONS AND INITIALIZATIONS
void printMonth(int year, int month, int &startDay);        //initializes the Function to print a specific month
                                                            // Takes in year, month, and a reference to the start day of the week
int getYear(int year);

bool isLeapYear(int year);                                  //initializes [isLeapYear] function logic check for leapyear

int findMonthLength(int year, int month);                   //initalizes the [findMonthLength] function to show how many days are in a month
                                                            //which is calculated by knowing the year and month
int getMonth();                                             //gets month based on user input
int calculateStartDay();                                    //initializes the startday function, that will decide based on the day of the week the month starts on






#endif // End of include guard