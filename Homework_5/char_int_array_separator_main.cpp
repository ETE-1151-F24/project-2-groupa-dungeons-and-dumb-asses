#include "arrayConversionHeader.h"  // Include the correct header file
#include "arrayFunctions.cpp"

int main() {
    printStrobingText("WORDSALAD TOSSER", 5);  // Display strobing title
    wordSaladGreeting();  // Greet the user
    getArrayInput();  // Get user input
    stringToArrayConversion();  // Convert string to char array
    checkCharacterType();  // Check character types in the array
    displayCharTypes();  // Display the counts of different character types
    cleanup();  // Free memory for the dynamically allocated array
    closingMessageExit();  // Wait for user input before exiting

    return 0;




}//---------------------ORIGINAL CONCEPUTALIZATIOn
// i need to declare an array that will first be able to store the input stream

// also have a prompt to say no more that a certain amount of characters
// error message if too many are entered.
// loop it back to entry to try again
//take an input string and split it all into elements of an array
//convert the input string into individual items in the array
// for caracter in wordinput, make the next index of the array that value.  
// then look throught the array and  perform
//initialize [int charCount = 0] variable
//iniotialize [int numericCount = 0] variable
// for item in declared array.....if char then charCount +=1
//                              else if numeric,then numericCount +=1

//while indexPosition is < max lenght of the array keep going with the counting
//  once done output a message
/*  "in [inputString] there are [charCount] letters and [numericCount] numbers "
*/ 

//then have an output message "thank you and have a nice dice my wordsalad tosser"

/*"press any key to exit" message
clear input buffer of stream
wait for user to press any key to exit
*/
