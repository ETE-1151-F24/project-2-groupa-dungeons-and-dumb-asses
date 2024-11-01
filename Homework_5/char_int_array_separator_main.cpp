#include "arrayConversionHeader.h"  // Include the correct header file
#include "arrayFunctions.cpp"
#include <limits>  // For std::numeric_limits

int main() {
    printStrobingText("WORDSALAD TOSSER", 5);  // Display strobing title
    wordSaladGreeting();  
    getArrayInput();  

    stringToArrayConversion();  
    checkCharacterType(); 
    displayCharTypes();  
      
    std::cout << std::endl << "We hope you enjoyed having your vowels tossed" << std::endl << std::endl;

    cleanup();  // Free memory for the dynamically allocated array
    closingMessageExit();  // Exit message 
   

    return 0;
}
