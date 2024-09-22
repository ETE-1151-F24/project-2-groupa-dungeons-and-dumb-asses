#ifndef ARRAYCONVERSIONHEADER_H //CALENDAR_H // Include guard to prevent multiple definitions
#define ARRAYCONVERSIONHEADER_H

//-------------------INCLUDES-------------------------------

#include <iostream>
#include <iomanip>   // [iomanip] allows for formatting of output and alignment
#include <string>
#include <cstring>

//-------------------Declaring global variables-----------------
std::string userInputString; 
// Externally declared array (to be defined in the source file)
extern char* characterStorageArray;  // This declaration tells the compiler the array exists
    int punctuationCount;                                             
    int vowelsCount;
    int consonantsCount;
    int numericDigitsCount;
    int spacesOrTabsCount;




//-------------------Preliminary initialize of functions-----------------
void wordSaladGreeting();
void getArrayInput();
void stringToArrayConversion();
void checkCharacterType();
void displayCharTypes();
void closingMessageExit();




#endif // End of include guard