#include<iostream>
#include<cstring>            //include the cstring library contains various functions for working with C-style strings 
#include "arrayConversionHeader.h"
#include <limits>  // For std::numeric_limits such as 

// -------------------------FUNCTION FOR DISPLAYING THE STROBING EFFECT OF THE LETTERS AT THE BEGINNING





// -------------------------FUNCTION FOR PROGRAM GREETING
void wordSaladGreeting(){
   std::cout << std::endl << "Welcome to WORDSALAD TOSSER, where things get... mixed up in all the right ways." << std::endl;
   std::cout << "Brace yourself... it’s about to get messy...." << std::endl << std::endl;

}



// -------------------------FUNCTION TO PROMPT AND GATHER INPUT STRING

void getArrayInput(){
std::string userInputString;             // Declare a string variable 's' to hold the user's input
    std::cout << "Enter a string: it can be whatever you like";     // Prompt the user for input

    std::getline(std::cin, userInputString);  // Read the whole line of input into 'userInputString'

    std::cout << "That's quite the load...." << std::endl << std::endl;


    std::cout << "Are you ready to get that Wordsalad tossed?"<< std::endl;    // Prompt to press any key to continue
    std::cout << "Press any key to continue..." << std::endl;
        // Clear the input buffer to ignore any leftover newline characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//  need [#include <limits>]  For std::numeric_limits
    std::cin.get();                                                             // Wait for a single character input


}
// -------------------------FUNCTION TO CONVERT THE INPUT STRING INTO AN ARRAY

void stringToArrayConversion(){

char* characterStorageArray = new char[userInputString.length() + 1];  // +1 for the null terminator
std::strcpy(characterStorageArray, userInputString.c_str());           // Copy std::string to char array


}


// -------------------------FUNCTION TO EVALUATE THE CHARACTER QUANTITIES

void checkCharacterType(){
//-----ESTABLISHING THE VARIABLE THAT WILL HOLD THE COUNT OF EACH CHARACTER TYPE
    int punctuationCount=0;
    int vowelsCount=0;
    int consonantsCount=0;
    int numericDigitsCount=0;
    int spacesOrTabsCount=0;
    int lengthOfArray = strlen(characterStorageArray); // Calculate the length of the input
// here is the for statement to loop through [characterStorageArray] and determine the type of charachter in the array
  for (int position = 0;  position < lengthOfArray; position++) {// position is the traversal of each individual element in the array
        // Convert the character to lowercase to simplify the comparison
        char individualCharCheck = tolower(characterStorageArray[i]);

        // Check if the character is a vowel
        if (individualCharCheck == 'a' || individualCharCheck == 'e' || individualCharCheck == 'i' || individualCharCheck == 'o' || individualCharCheck == 'u') {
            vowelsCount++; // Increment the vowel count
        }  

//std::isspace() //checks whether a character is a whitespace character, including spaces, tabs, newlines, etc
//std::isalpha(): Checks if a character is alphabetic.
//isVowel(): Called within the if block to check if the alphabetic character is a vowel or consonant.
//std::isdigit(): Checks if a character is a numeric digit.
//std::ispunct(): Checks if a character is punctuation or a symbol.
}


// -------------------------FUNCTION TO SHOW THE CHARACTER QUANTITIES

void displayCharTypes(){

}

// -------------------------FUNCTION TO WAIT FOR USER INPUT TO TERMINAT PROGRAM
  void closingMessageExit(){
  std::cout << "Thanks for playing preshuss" << std::endl << std::endl;

      
    std::cout << "\nPress any key to exit..." << std::endl;                                 // Wait for user input before closing 
    std::cin.get();                                                                         // Wait for the user to press any key
  }