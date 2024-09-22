#include<iostream>
#include<cstring>            //include the cstring library contains various functions for working with C-style strings 
#include "arrayConversionHeader.h"
#include <limits>  // For std::numeric_limits such as 

// -------------------------FUNCTION FOR DISPLAYING THE STROBING EFFECT OF THE LETTERS AT THE BEGINNING


void printStrobingText(const std::string& text, int duration) {
    // ---------------------ANSI COLOR CODES-------------------------
    // Array of ANSI escape codes representing different text colors.
    const std::string colors[] = {
        "\033[31m",                                                                 // Red color code
        "\033[32m",                                                                 // Green color code
        "\033[33m",                                                                 // Yellow color code
        "\033[34m",                                                                 // Blue color code
        "\033[35m",                                                                 // Magenta color code
        "\033[36m",                                                                 // Cyan color code
        "\033[37m"                                                                  // White color code
    };

    // -----------------------COLOR COUNT---------------------------
 
    const int colorCount = sizeof(colors) / sizeof(colors[0]);                      //Calculate number colors available in colors array
   
    int currentColorIndex = 0;                                                      //Variable for current color index for strobe effect

    // ---------------------TIME START POINT-------------------------
   
    auto startTime = std::chrono::steady_clock::now();                              //Mark current time as start point of strobe effect

    // -------------------LOOP FOR STROBING EFFECT-------------------
                                                               
    while (true) {                                                                  //loop to display strobe effect until specified duration
        // -------------------CHECK TIME ELAPSED----------------------
        
        auto currentTime = std::chrono::steady_clock::now();                        // Get current time >> calculate seconds passed since start
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

                            
        if (elapsedTime >= duration) {                                              //If elapsed reaches/exceeds duration, break the loop
            break;
        }

        // ------------------STROBING CHARACTERS----------------------
                                                                                    // Iterate over each character in the string
        for (size_t currentCharacterIndex = 0; currentCharacterIndex < text.length(); ++currentCharacterIndex) {
                                                                
            std::cout << "\r";                                                      //"\r" moves cursor to start of line w/o advance next line

            // ------------------PRINTING EACH LETTER------------------
            // Iterate over the text and apply the strobing effect to the current character
            for (size_t textPosition = 0; textPosition < text.length(); ++textPosition) {
                if (textPosition == currentCharacterIndex) {
                    // When current character is being printed, apply current strobe color
                    std::cout << colors[currentColorIndex % colorCount] << text[textPosition];
                } else {
                    // Reset color and print rest of text normally
                    std::cout << "\033[0m" << text[textPosition]; // "\033[0m" resets the terminal color to default
                }
            }

            // --------------------BUFFER FLUSH-------------------------
            // Flush the output buffer to make sure the current state of the text is immediately displayed
            std::cout.flush();

            // --------------------DELAY-------------------------------
            // Introduce a delay between each strobing iteration to make the effect visible
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // ------------------INCREMENT COLOR-----------------------
            // Move to the next color in the color array for the next iteration
            ++currentColorIndex;
        }
    }

    // ---------------------RESET COLOR AT END-----------------------
    // Once the strobing effect is over, reset the terminal color to default and add a newline
    std::cout << "\033[0m\n";
}

// ----------------------KEY CONCEPT BREAKDOWN-----------------------
// The `printStrobingText` function creates a strobing effect by changing the text color for each character 
// in sequence. The strobing lasts for a specified duration, and the colors are applied using ANSI escape codes.
// ANSI escape codes allow for changing the text color on the terminal.
// The chrono library is used to measure time, allowing the strobing effect to continue for the desired duration.
// This effect is achieved using a loop that prints each character of the string with a strobing color applied, 
// along with a small delay to create a smooth transition between colors.
// More descriptive variable names like `currentCharacterIndex` and `textPosition` have been used to clarify 
// the purpose of each loop and variable for readability.





// -------------------------FUNCTION FOR PROGRAM GREETING
void wordSaladGreeting(){
   std::cout << std::endl << "Welcome to WORDSALAD TOSSER, where things get... mixed up in all the right ways." << std::endl;
   std::cout << "Brace yourself... it’s about to get messy...." << std::endl << std::endl;

}



// -------------------------FUNCTION TO PROMPT AND GATHER INPUT STRING

void getArrayInput(){

    std::cout << "Enter a string: it can be whatever you like";                     // Prompt the user for input

    std::getline(std::cin, userInputString);                                        //Read the whole line of input into [userInputString]

    std::cout << "That's quite the load...." << std::endl << std::endl;


    std::cout << "Are you ready to get that Wordsalad tossed?"<< std::endl;         // Prompt to press any key to continue
    std::cout << "Press any key to continue..." << std::endl;
        // Clear the input buffer to ignore any leftover newline characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//  need [#include <limits>]  For std::numeric_limits
    std::cin.get();                                                                 // Wait for a single character input


}
// -------------------------FUNCTION TO CONVERT THE INPUT STRING INTO AN ARRAY

void stringToArrayConversion(){

char* characterStorageArray = new char[userInputString.length() + 1];                // +1 for the null terminator
std::strcpy(characterStorageArray, userInputString.c_str());                     // Copy std::string to char array

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
   std::cout << userInputString <<" was really loaded." << std::endl;

    std::cout << "Here are all your character counts, nice and tidy... just the way you like it." << std::endl << std::endl;
 
//---------------having alternates when it finds a zero value for a character type---------   
    if (vowelsCount > 0) {
    std::cout <<"Your input came with " << vowelsCount << " vowels." << std::endl;
    } else {
        std::cout << "No vowels? So silent... we're a little disappointed." << std::endl;

    }if (consonantsCount > 0) {
    std::cout <<"You filled it "<< consonantsCount << " consonants." << std::endl;
    } else {
        std::cout << "No consonants? It's feeling too soft." << std::endl;
    
    }if (punctuationCount > 0) {
    std::cout <<"You finished with " << punctuationCount << " punctuations or special characters." << std::endl;
    } else {
        std::cout << "No punctuations? We expected more excitement." << std::endl;

    }if (spacesOrTabsCount > 0) {
    std::cout <<"What a spread. A total of " << spacesOrTabsCount << " gaps were created with space bar or tab" << std::endl;
    } else {
        std::cout << "No spaces? It felt pretty tight... let's loosen things up next time." << std::endl;

    }if (numericDigitsCount > 0) {
    std::cout <<"You managed to fit " << numericDigitsCount <<" digits inside.  So adventurous!!" << std::endl;
    } else {
        std::cout << "No digits? Afraid to get numerical? We hoped it was a little more heavy handed." << std::endl;

    std::cout << "" << std::endl;    
    std::cout << "We hope you enjoyed having your vowels tossed" << std::endl;
        std::cout << "\nPress any key to continue..." << std::endl;                                 // Wait for user input before closing 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     //need [#include <limits>]  For std::numeric_limits    
    std::cin.get(); 
    }
}
// -------------------------FUNCTION TO WAIT FOR USER INPUT TO TERMINATE PROGRAM
void closingMessageExit() {
    std::cout << "This was a fun challenge to face down." << std::endl; 
    std::cout << "Class is up!" << std::endl << std::endl;

    std::cout << "\nPress any key to exit..." << std::endl; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    std::cin.get();  // Wait for the user to press any key
}