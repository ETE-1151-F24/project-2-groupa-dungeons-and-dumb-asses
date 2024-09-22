#ifndef ARRAYCONVERSIONHEADER_H //CALENDAR_H // Include guard to prevent multiple definitions
#define ARRAYCONVERSIONHEADER_H

//-------------------INCLUDES-------------------------------

#include <iostream>
#include <iomanip>   // [iomanip] allows for formatting of output and alignment
#include <string>
#include <cstring>
#include <thread>    
//#include <thread>:
                    // This directive includes the C++ Standard Library's thread header, 
                    // which provides functionality for multithreading. It allows you to create, 
                    // manage, and control multiple threads of execution in your program.
                    // this library to utilizes function [std::this_thread::sleep_for], 
                    // which is responsible for making the current thread sleep 
                    // (pause execution) for a specified amount of time. 

//#include <chrono>    
                    // For timing /*#include <chrono>:
                    // This directive includes the C++ Standard Library's chrono header, 
                    // which provides a set of utilities for measuring time. 
                    // It defines types for dealing with clocks, durations, and time points.


//-------------------Declaring global variables-----------------
std::string userInputString; 
// Externally declared array (to be defined in the source file)
extern char* characterStorageArray;  // This declaration tells the compiler the array exists

int punctuationCount = 0;
int vowelsCount = 0;
int consonantsCount = 0;
int numericDigitsCount = 0;
int spacesOrTabsCount = 0;


//-------------------Preliminary initialize of functions-----------------
void wordSaladGreeting();
void getArrayInput();
void stringToArrayConversion();
void checkCharacterType();
void displayCharTypes();
void closingMessageExit();

// Declare strobing effect function (implementation will be in the .cpp file)
//------------------- [  "arbirtaty words"  ] , [how long it strobes]
void printStrobingText(const std::string& text, int duration);


#endif // End of include guard