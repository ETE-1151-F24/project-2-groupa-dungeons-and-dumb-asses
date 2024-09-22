#ifndef ARRAYCONVERSIONHEADER_H
#define ARRAYCONVERSIONHEADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <thread>

// Global variable declarations
extern char* characterStorageArray;  // Declare the array as an external symbol

extern int punctuationCount;
extern int vowelsCount;
extern int consonantsCount;
extern int numericDigitsCount;
extern int spacesOrTabsCount;

// Function declarations
void printStrobingText(const std::string& text, int duration);
void wordSaladGreeting();
void getArrayInput();
void stringToArrayConversion();
void checkCharacterType();
void displayCharTypes();
void cleanup();  // Declaration of cleanup function to free memory
void closingMessageExit();

#endif
