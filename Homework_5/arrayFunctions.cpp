#include<iostream>
#include<cstring>            //include the cstring library contains various functions for working with C-style strings 

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
    std::cin.get();                                                             // Wait for a single character input


}
// -------------------------FUNCTION TO CONVERT THE INPUT STRING INTO AN ARRAY

void stringToArrayConversion(){


}


// -------------------------FUNCTION TO EVALUATE THE CHARACTER QUANTITIES

void checkCharacterType(){
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