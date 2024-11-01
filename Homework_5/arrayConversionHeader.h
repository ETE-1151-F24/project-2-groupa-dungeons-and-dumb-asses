#ifndef ARRAYCONVERSIONHEADER_H
#define ARRAYCONVERSIONHEADER_H

//-------------------INCLUDES-------------------------------

#include <iostream>
#include <iomanip>   // [iomanip] allows for formatting of output and alignment
#include <string>
#include <cstring>
#include <thread>

//-------------------Declaring global variables-----------------
extern std::string userInputString; 
// Externally declared array (to be defined in the source file)
extern char* characterStorageArray;  // Declare the array as an external symbol

extern int punctuationCount;
extern int vowelsCount;
extern int consonantsCount;
extern int numericDigitsCount;
extern int spacesOrTabsCount;

//-------------------Preliminary initialization of functions-----------------

// Declare strobing effect function (implementation will be in the .cpp file)
void printStrobingText(const std::string& text, int duration);

void wordSaladGreeting();
void getArrayInput();
void stringToArrayConversion();
void checkCharacterType();
void displayCharTypes();
void cleanup();  // Declaration of cleanup function to free memory
void closingMessageExit();

#endif // End of include guard
