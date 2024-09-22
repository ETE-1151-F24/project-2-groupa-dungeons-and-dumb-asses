#include "arrayConversionHeader.h"  // Include the correct header file
#include "arrayFunctions.cpp"

int main() {
    printStrobingText("WORDSALAD TOSSER", 5);  // Display strobing title
    wordSaladGreeting();  
    getArrayInput();  

    stringToArrayConversion();  
    checkCharacterType(); 
    displayCharTypes();  
      
    std::cout << "We hope you enjoyed having your vowels tossed" << std::endl;

    cleanup();  // Free memory for the dynamically allocated array
    closingMessageExit();  // Exit message 
   

    return 0;
}
