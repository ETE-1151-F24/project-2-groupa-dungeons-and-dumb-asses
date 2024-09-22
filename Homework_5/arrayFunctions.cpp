#include "arrayConversionHeader.h"
#include <limits>  // For std::numeric_limits

// Define global variables here
std::string userInputString = "";  // Define the userInputString
char* characterStorageArray = nullptr;  // Global definition of the character array
int punctuationCount = 0;
int vowelsCount = 0;
int consonantsCount = 0;
int numericDigitsCount = 0;
int spacesOrTabsCount = 0;
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
// The `printStrobingText` function creates a strobing effect by changing the text color for each character in sequence.
//  The strobing lasts for a specified duration, and the colors are applied using ANSI escape codes.
// ANSI escape codes allow for changing the text color on the terminal.
// The chrono library is used to measure time, allowing the strobing effect to continue for the desired duration.
// This effect is achieved using a loop that prints each character of the string with a strobing color applied, 
// along with a small delay to create a smooth transition between colors.
// More descriptive variable names like `currentCharacterIndex` and `textPosition` have been used to clarify 
// the purpose of each loop and variable for readability.





// -------------------------FUNCTION FOR PROGRAM GREETING
void wordSaladGreeting(){
   std::cout << std::endl << "Welcome to WORDSALAD TOSSER, where things get... mixed up in all the right ways." << std::endl;
   std::cout << "Brace yourself... it's about to get messy...." << std::endl << std::endl;

}
//----------------------------------------------------------------------------------------------------


// -------------------------FUNCTION TO PROMPT AND GATHER INPUT STRING

void getArrayInput(){

    std::cout << "Enter a string: it can be whatever you like" << std::endl << std::endl;                     // Prompt the user for input

    std::getline(std::cin, userInputString);                                        //Read the whole line of input into [userInputString]

    std::cout << std::endl << "                                     That's quite the load...." << std::endl << std::endl;

    std::cout << "                            Are you ready to get that Wordsalad tossed?"<< std::endl << std::endl;        
    // Prompt to press any key to continue
    std::cout << "Press ENTER to continue...";

    std::cin.get();

}
//----------------------------------------------------------------------------------------------------



// -------------------------FUNCTION TO CONVERT THE INPUT STRING INTO AN ARRAY

void stringToArrayConversion() {
                                                                                    //Allocate memory for global [characterStorageArray] 
                                                                                    //(make sure don't redeclare it locally)
    characterStorageArray = new char[userInputString.length() + 1];                 // +1 for the null terminator
    
                                                                                    //Copy content[userInputString] to [characterStorageArray]
    std::strcpy(characterStorageArray, userInputString.c_str());                    // Convert std::string to C-style string
}
//----------------------------------------------------------------------------------------------------



// -------------------------FUNCTION TO EVALUATE THE CHARACTER QUANTITIES
//--------------------------ESTABLISh VARIABLES to HOLD COUNT OF EACH CHARACTER TYPE (and are aptly named)
void checkCharacterType(){

    int lengthOfArray = strlen(characterStorageArray);                                      //Calculate the length of the array

//for statement to loop through [characterStorageArray] and determine the type of charachter in the array

  for (int characterNumber = 0;  characterNumber < lengthOfArray; characterNumber++) {// position is the traversal of each individual element in the array
        // Convert the character to lowercase to simplify the comparison
        char indChr = tolower(characterStorageArray[characterNumber]);                      //[indChr] short for individual character
                                                                                            //[tolower] converts to lowercase
         if (std::ispunct(indChr)){                                                         //if the character is a punctuation....
            punctuationCount+=1;                                                            //then it increments the [spacesOrTabsCount]
        }
        else if (std::isalpha(indChr)){                                                     //if the character is alphabetic...
                                                                                            // NESTED if / else statement to Check ...
                                                                                            //if the character is a vowel or a consonant
            
/*NESTED*/  if (indChr == 'a' || indChr == 'e' || indChr == 'i' || indChr == 'o' || indChr == 'u') { //"a", "e", "i", "o", or "u"
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
   std::cout << "                                     ["<< userInputString <<"] was really loaded." << std::endl << std::endl;

 
//---------------having alternates when it finds a zero value for a character type---------   
    if (vowelsCount > 0) {                                     // if>1...plural (s) else singular
     std::cout << "You slipped in " << vowelsCount << " vowel" << (vowelsCount > 1 ? "s." : ".") << std::endl;
    } else {
        std::cout << "No vowels? that's a bit anti-climactic for me." << std::endl;

    }if (consonantsCount > 0) {                                             // if>1...plural (s) else singular
    std::cout << "and filled it with "<< consonantsCount << " consonant" << (consonantsCount > 1 ? "s." : ".") << std::endl;
    } else {
        std::cout << "No consonants? Yea it felt a bit soft." << std::endl;
    
    }if (punctuationCount > 0) {                                               // if>1...plural (s) else singular
    std::cout << "I see you came with " << punctuationCount << " punctuation" << (punctuationCount > 1 ? "s" : "") <<  
    " or special character" << (punctuationCount > 1 ? "s." : ".") << std::endl;
    } else {
        std::cout << "No punctuations? not even a single (_*_)...We expected more excitement." << std::endl;

    }if (spacesOrTabsCount > 0) {                                // if>1...plural (s) else singular
    std::cout << "A total of " << spacesOrTabsCount << " gap" << (spacesOrTabsCount > 1 ? "s" : "") <<  
    " were created with space bar or tab" << std::endl;
    } else {
        std::cout << "No spaces? ... let's loosen things up next time." << std::endl;

    }if (numericDigitsCount > 0) {                                          // if>1...plural (s) else singular
    std::cout << "And, you managed to fit " << numericDigitsCount << " digit" << (numericDigitsCount > 1 ? "s" : "") << 
    " inside.  So adventurous!!" << std::endl;
    } else {
        std::cout << "No digits? We preferer your digits to be a little more heavy handed." << std::endl;



    }
}

// -------------------------FUNCTION TO CLEAN UP MEMORY
void cleanup() {
    delete[] characterStorageArray;                                                 // Free up dynamically allocated memory
    characterStorageArray = nullptr;                                                // Avoid having a dangling pointer
}

// -------------------------FUNCTION TO WAIT FOR USER INPUT TO TERMINATE PROGRAM
void closingMessageExit() {

    // Wait for a key press before exiting
    std::cout << "Press ENTER to pull out of the program...";
    std::cin.get();
}