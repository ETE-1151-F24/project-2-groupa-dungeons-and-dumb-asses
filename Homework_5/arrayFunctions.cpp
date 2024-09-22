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

char* characterStorageArray = new char[userInputString.length() + 1];                   // +1 for the null terminator
std::strcpy(characterStorageArray, userInputString.c_str());                            // Copy std::string to char array

//-----------i pulled this from stack overflow and had to look up what it does
// additional_comments.cpp holds the explaination to clarify
}


// -------------------------FUNCTION TO EVALUATE THE CHARACTER QUANTITIES

void checkCharacterType(){
//-----ESTABLISHING THE VARIABLES THAT WILL HOLD THE COUNT OF EACH CHARACTER TYPE (and are aptly named)
    int punctuationCount=0;                                             
    int vowelsCount=0;
    int consonantsCount=0;
    int numericDigitsCount=0;
    int spacesOrTabsCount=0;
    int lengthOfArray = strlen(characterStorageArray);                                      //Calculate the length of the array

// here is the for statement to loop through [characterStorageArray] and determine the type of charachter in the array

  for (int characterNumber = 0;  characterNumber < lengthOfArray; characterNumber++) {// position is the traversal of each individual element in the array
        // Convert the character to lowercase to simplify the comparison
        char indChr = tolower(characterStorageArray[characterNumber]);                      //[indChr] short for individual character

         if (std::ispunct(indChr)){                                                         //if the character is a punctuation....
            punctuationCount+=1;                                                            //then it increments the [spacesOrTabsCount]
        }
        else if (std::isalpha(indChr)){                                                     //if the character is alphabetic...
                                                                                            // Nested if else statement to Check ...
                                                                                            //if the character is a vowel or a consonant
            
            if (indChr == 'a' || indChr == 'e' || indChr == 'i' || indChr == 'o' || indChr == 'u') { //"a", "e", "i", "o", or "u"
                vowelsCount++;                                                              // Increment the vowel count
        }   else {                                                                          //if character is alphabetic but not a vowel....
                consonantsCount+=1;                                                         //then it increments the [consonantsCount]
             }
        }

        else if (std::isspace(indChr)/* condition */) {                                //if character is a space, 
            spacesOrTabsCount+=1; }                                                         //then it increments the [spacesOrTabsCount]

        else if (std::isdigit(indChr)/* condition */) {                                //if character is a numeric digit... then it increments the []        
            numericDigitsCount+=1;                                                          //then it increments the [numericDigitsCount]
        }

//std::isspace() //checks whether a character is a whitespace character, including spaces, tabs, newlines, etc
//std::isalpha(): Checks if a character is alphabetic.
//std::isdigit(): Checks if a character is a numeric digit.
//std::ispunct(): Checks if a character is punctuation or a symbol.
}
}

// -------------------------FUNCTION TO SHOW THE CHARACTER QUANTITIES

void displayCharTypes(){

    std::cout << "We hope you enjoyed having your vowels tossed" << std::endl;
    std::cout << "Here are all your character counts, nice and tidy... just the way you like it." << std::endl << std::endl;
    std::cout << userInputString <<" was loaded with goodies." << std::endl;
    
    std::cout <<"Your input came with " << vowelsCount << " vowels." << std::endl;
    std::cout <<"You filled it "<< consonantsCount << "consonants." << std::endl;
    std::cout <<"You finished with " << punctuationCount << "punctuations or special characters." << std::endl;
    std::cout <<"What a spread. A total of " << spacesOrTabsCount << "gaps were created with space bar or tab" << std::endl;
    std::cout <<"You managed to fit " << numericDigitsCount <<" digits inside.  So adventurous!!" << std::endl;
    std::cout << "" << std::endl;
}

// -------------------------FUNCTION TO WAIT FOR USER INPUT TO TERMINAT PROGRAM
  void closingMessageExit(){
  std::cout << "This was a fun challenge to face down." << std::endl; 
  std::cout << "Class is up!" << std::endl;

      
    std::cout << "\nPress any key to exit..." << std::endl;                                 // Wait for user input before closing 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     //need [#include <limits>]  For std::numeric_limits    
    std::cin.get();                                                                         // Wait for the user to press any key
  }