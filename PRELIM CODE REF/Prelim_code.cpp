//DONT EVER TY TO COMPILE THIS...IT IS JUST FOR VISUAL REFERENCE
// cout << "" << endl;       this is the syntax for an output statement with text

// ANYTIME DEALING WITH PI YOU SHOULD CHOOSE TO DECLARE AS A DOUBLE

//-------------------------------------THIS IS YOUR STARTING JUMP OFF POINT FOR CODING------------------------------
#include<iostream>
using namespace std;                //this makes it the [std::] naming scheme so i dont have to type it over and over

int main() {

        return 0;                   //returns the value of 0 if the program completes correctly                   
}

//--------------------------------putting stuff in and out via prompt------------------------------------------------------------------------------
#include<iostream>
using namespace std;                //this makes it the [std::] naming scheme so i dont have to type it over and over
int x;                              // initializes a variable called [x] for later use

int main() {
    cout << "enter two values";  	//this is a prompt statement and goes before cin
	cin>>x>>y;		                //tells the computer to hold for input for [x] and [y] put a space between 
                                    //each and can only have one stream operator at a time

                                    //To make a comment you use //  or for a multiline comment you use 

z = x + y;                          //all operations are stored on the right side of the variable and [=]
                                    // (make sure to add spaces between things to increase legibility)
cout << ” Result is = ” << z;       //references the variable [z] address    ["Result is"] statement is optional


                // !!!!!!! pay close attention to the quote marks...[”] Result is = [”] curly quote create and unrecognized error token
                // !!!!!!! the correct quotes to use are ["] Result is = ["]  **** notice they are straight quotes

                return 0;                   //returns the value of 0 if the program completes correctly                   
}
//---------------------------------------------IF STATEMENTS-------------------------------------------------
if (/*boolean/comparison*/){
    /*perform this command*/;
} else{
    /*perform this command instead*/
}

//--------------------------------------------SETTING FIXED PRECISION FLOATS-----------------------------
int main() {
    float num = 3.14159265;

    // Set the precision to 3 decimal places
    cout << fixed << setprecision(3);            //output with [setprecision] to [(2)] [fixed] decimal places
    cout << "Number with 3 decimal places: " << num << endl;

    // Set the precision to 5 decimal places
    cout << fixed << setprecision(5);
    cout << "Number with 5 decimal places: " << num << endl;






//------------------------------------------------USING IOMANIP-------------------
#include <iostream>  // Standard library for input/output operations
#include <iomanip>   // Library for input/output formatting manipulations ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

int main() {
    // 1. Using std::setw(n): Sets the width of the next input/output field to 'n' characters
    std::cout << "Using std::setw(10) to set field width:\n";
    
    // std::setw(10) ensures that the following output will be 10 characters wide.
    // "Hello" is 5 characters, so the remaining 5 will be padded with spaces.
    std::cout << std::setw(10) << "Hello" << std::endl; // Output: "     Hello" (5 spaces before "Hello")
    
    // 2. Using std::setprecision(n): Sets the precision for floating-point numbers.
    double pi = 3.1415926535;  // Pi with high precision
    std::cout << "\nUsing std::setprecision(2) to limit floating-point precision:\n";
    
    // std::fixed forces the number to be printed in fixed-point notation (normal decimal form).
    // std::setprecision(2) means two digits after the decimal point will be shown.
    std::cout << std::fixed << std::setprecision(2) << pi << std::endl;  // Output: "3.14"
    
    // 3. Using std::fixed and std::scientific:
    double largeNumber = 123456.789;
    std::cout << "\nUsing std::scientific for scientific notation:\n";
    
    // std::scientific formats the output in scientific notation (exponential form).
    std::cout << std::scientific << largeNumber << std::endl;  // Output: "1.234568e+05"
    
    // std::fixed is used to switch back to fixed-point notation (normal decimal form).
    std::cout << std::fixed << largeNumber << std::endl;  // Output: "123456.789000"
    
    // 4. Using std::left and std::right:
    std::cout << "\nUsing std::left and std::right to control alignment:\n";
    
    // std::left aligns the text to the left side within the specified width.
    // std::setw(10) sets the field width to 10 characters.
    std::cout << std::left << std::setw(10) << "Left" << std::endl;  // Output: "Left      "
    
    // std::right aligns the text to the right side within the specified width.
    std::cout << std::right << std::setw(10) << "Right" << std::endl;  // Output: "     Right"
    
    // 5. Using std::setfill(char): Fills the extra space with a specified character
    std::cout << "\nUsing std::setfill('*') to fill with characters:\n";
    
    // std::setfill('*') changes the fill character from the default (space) to '*'.
    // The output will be padded with '*' characters if the value is shorter than the specified width.
    std::cout << std::setw(10) << std::setfill('*') << 123 << std::endl;  // Output: "*******123"
    
    // 6. Using std::showpoint: Forces the display of the decimal point and trailing zeros
    double simpleNumber = 12.0;  // A number with no decimal places shown by default
    std::cout << "\nUsing std::showpoint to force display of the decimal point:\n";
    
    // std::showpoint ensures that even if the number is an integer, the decimal point and trailing zeros are displayed.
    std::cout << std::showpoint << simpleNumber << std::endl;  // Output: "12.000000"

    return 0;  // Return 0 to indicate successful program completion
}

//                                  EXPANDING THE UNDERSTANDING OF IOMANIP SYNTAX
/*
1. std::setw(n): Sets the width of the next input/output field to 'n' characters.
   If the output is shorter than 'n', the remaining space will be padded with spaces (or a specified character).
   Example:
       std::cout << std::setw(10) << "Hello" << std::endl;
   Output:
       "     Hello" (5 spaces before "Hello")

2. std::setprecision(n): Sets the precision for floating-point numbers.
   When used with std::fixed, it controls how many digits are displayed after the decimal point.
   Example:
       double pi = 3.1415926535;
       std::cout << std::fixed << std::setprecision(2) << pi << std::endl;
   Output:
       "3.14"

3. std::fixed and std::scientific: These manipulators control how floating-point numbers are formatted.
   - std::fixed displays the number in normal decimal notation.
   - std::scientific displays the number in scientific notation (exponential form).
   Example (std::scientific):
       double largeNumber = 123456.789;
       std::cout << std::scientific << largeNumber << std::endl;
   Output:
       "1.234568e+05"
   
   Example (std::fixed):
       std::cout << std::fixed << largeNumber << std::endl;
   Output:
       "123456.789000"

4. std::left and std::right: Control the alignment of output within a specified width.
   - std::left aligns the output to the left within the field width.
   - std::right aligns the output to the right within the field width.
   Example (std::left):
       std::cout << std::left << std::setw(10) << "Left" << std::endl;
   Output:
       "Left      " (6 spaces after "Left")

   Example (std::right):
       std::cout << std::right << std::setw(10) << "Right" << std::endl;
   Output:
       "     Right" (5 spaces before "Right")

5. std::setfill(char): Sets the character used to fill the remaining space when the output is shorter than the specified width.
   By default, the fill character is a space, but you can use any character (e.g., '*').
   Example:
       std::cout << std::setw(10) << std::setfill('*') << 123 << std::endl;
   Output:
       "*******123" (7 '*' characters before "123")

6. std::showpoint: Forces the display of the decimal point and trailing zeros, even for integer values or numbers that don't have a fractional part.
   Example:
       double simpleNumber = 12.0;
       std::cout << std::showpoint << simpleNumber << std::endl;
   Output:
       "12.000000"
*/




//--------------------------------------------------------HEADER FILE CONTENTS---------------------------------
#ifndef HEADER_FILE_NAME_H   // This is called an "include guard". It ensures the file is included only once to avoid redefinition errors.
#define HEADER_FILE_NAME_H   // This is the second part of the include guard. 'HEADER_FILE_NAME_H' should be replaced with a unique name (usually uppercase with underscores).

// Includes - these are standard libraries or custom headers that your code might rely on.
#include <iostream>  // Includes the Input/Output Stream library for operations like std::cout (output) and std::cin (input).
#include <string>    // Includes the string class from the C++ Standard Library, allowing the use of the std::string type for handling text.

// Function declarations - here we declare functions that will later be defined in a corresponding .cpp (source) file.
// These declarations let the compiler know about the function's return type, name, and parameters, but the function's body will be implemented elsewhere.
void FunctionName1();  // Declares a function named 'FunctionName1'. 
                      // 'void' means this function doesn't return any value.
                      // There are no parameters in this function.

int FunctionName2(int param);  // Declares a function named 'FunctionName2' that returns an integer ('int').
                               // 'param' is a parameter passed into the function. It's of type 'int', which means it's an integer.
                               // When the function is called, it will take one integer as input, represented here by 'param'.
                               // You can replace 'param' with a more descriptive name (e.g., 'number', 'value') to clarify what this input represents.
                               // For example: int FunctionName2(int number); 

// Template declaration
// 'typename T' tells the compiler this function is a template and that 'T' can represent any data type.
// 'T' can be an int, double, string, or any type the user provides when the function is called.
template<typename T>
T FunctionName1(T param) {   
    // This function takes one parameter of type 'T' (which could be int, double, string, etc.)
    // and returns a value of the same type 'T'.
    
    // In a real implementation, this function could perform operations on 'param'.
    // For example, it could return 'param' multiplied by 2, or perform any other operation depending on 'T'.
    
    return param;  // Here, we simply return 'param' as-is, but you can customize this logic.
}

// Template function with two parameters
// This demonstrates how a function can work with two generic parameters, and the return type is also generic.
template<typename T, typename U>
T FunctionName2(T param1, U param2) {
    // This function takes two parameters, 'param1' of type T and 'param2' of type U.
    // It performs some operation (yet to be defined) and returns a value of type T.
    
    // For example, if param1 is int and param2 is double, the function could still work and return an int.
    
    // In real use, this function could do something like param1 + param2 (depending on types).
    // You'll need to ensure that operations make sense for the types involved.
    
    return param1;  // Example: returning the first parameter.
}

// End of the include guard: closes the guard, ensuring the header is only included once in the compilation.
#endif // HEADER_FILE_NAME_H

//------------------------------------------------------------------------------------------------------------

//------------------------------------------------USING A RANDOM NUMBER GENERATOR-------------------
std::cout << rand() % 100 << " "; // Output a random number between 0 and 99 (INCLUSIVE), followed by a space

// [std::cout]: Standard output stream, used to print to the console.
// [rand()]: Generates a random integer, often a large number. The actual range of values is system-dependent.
// [% 100]: This is the modulus operator. It gives the remainder when the random number is divided by 100. 
// This operation ensures the result is between 0 and 99 (inclusive).
// << " ": This inserts a space after the random number, separating it from other output.

//IMPLEMENTING A SHIFT IN THE RANGES
std::cout << (rand() % 38) + 6 << " "; // Output a random number between 6 and 43, followed by a space

// [rand()] % 38: Generates a random number between 0 and 37 (because 43 - 6 + 1 = 38).
// [+ 6]: Shifts the range from 0-37 to 6-43.


//-------------------------------GET NUMBER VALIDATION------------------------------

// Function to get valid numeric input from the user and handle errors
double getNumberInput(string prompt) {
    
    // Declare a variable to store the user input as a double
    double number;

    // Infinite loop to keep asking for input until a valid number is entered
    while (true) {

        // Output the prompt message to the user
        cout << prompt;
        
        // Get input from the user and attempt to store it in the 'number' variable
        cin >> number;

        // Check if the input failed (i.e., the user did not enter a valid number)
        if (cin.fail()) {

            // Clear the error flag on the input stream (cin)
            cin.clear();

            // Ignore any remaining input in the stream until the end of the line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Inform the user that the input was invalid
            cout << "Error: Expected a number but received invalid input." << endl;
        
        } else {

            // Ignore any remaining input in the stream (if any) to avoid issues with subsequent input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Return the valid number to the caller (this also exits the loop)
            return number;
        }
    }
}
            // 'cin.ignore()' is a function used to ignore characters in the input stream (cin).
            // It's useful when you want to skip invalid or extra characters left in the input buffer
            // after taking input, especially after using 'cin >>'.
            
            // 'numeric_limits<streamsize>::max()' is a way to specify how many characters should be ignored.
            // Let's break it down:
            //
            // 1. 'numeric_limits' is a template class that provides information about the properties of
            //    fundamental numeric types (like int, double, etc.). In this case, it's applied to 'streamsize',
            //    the type used for representing the size of the input/output stream.
            //
            // 2. '<streamsize>' specifies that we are retrieving the limits (such as max value) for the 'streamsize' type.
            //
            // 3. '::max()' returns the maximum value that a 'streamsize' variable can hold. In this context,
            //    it means we are telling 'cin.ignore()' to ignore up to the maximum possible number of characters in the input stream.
            
            // The second argument, '\n', specifies the delimiter. It means the function will stop ignoring characters 
            // once it encounters a newline ('\n'), or after the maximum number of characters (given by 'numeric_limits<streamsize>::max()') 
            // is ignored. Essentially, it ignores everything until the end of the current input line.
            
            // Practical use: This line clears any leftover characters from the input buffer, preventing
            // unexpected behavior when reading further input. It's commonly used after input validation
            // to ensure no invalid characters (like extra letters or spaces) remain in the input stream.

//-------------------------------press any key to exit/continue
 void exitFunctionWait(){
  std::cout << std::endl << "Press any key to exit..." << std::endl;  
    std::cin.ignore(); // Ignore the leftover newline character from the previous input
std::cin.get();    // Wait for user input to pause       

//or you can do this     
    // Prompt the user to press any key to continue
    std::cout << "Are you ready to get that Wordsalad tossed? Press any key to continue..." << std::endl;

    // Clear the input buffer to ignore any leftover newline characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Wait for the user to press a key
    std::cin.get();  // Wait for a single character input
 }



 //--------------------------------------------------------------------
 #include <thread> // For sleep_for
// #include <thread>:

// This directive includes the C++ Standard Library's thread header, which provides functionality for multithreading. It allows you to create, manage, and control multiple threads of execution in your program.
// In your particular case, you're using this library to utilize the function std::this_thread::sleep_for, which is responsible for making the current thread sleep (pause execution) for a specified amount of time.
// Key Classes/Functions in <thread>:

// std::thread: A class representing an independent thread of execution.
// std::this_thread::sleep_for: Pauses the calling thread for a specified duration.
// std::this_thread::sleep_until: Pauses the calling thread until a certain point in time.
// In your program, you are particularly interested in std::this_thread::sleep_for, which allows you to pause your program for a certain amount of time.

#include <chrono> // For timing
// #include <chrono>:
// This directive includes the C++ Standard Library's chrono header, which provides a set of utilities for measuring time. It defines types for dealing with clocks, durations, and time points.
// chrono is essential for timing-related operations in modern C++ programs, allowing you to represent durations (like seconds, milliseconds) and time points (like a specific time of day or an exact point in time).
// Key Types/Classes in <chrono>:
// std::chrono::duration: Represents a span of time (like "5 seconds" or "10 milliseconds"). It is template-based, meaning you can create durations of any time unit.
// std::chrono::time_point: Represents a specific point in time, relative to a clock (e.g., "now").
// std::chrono::steady_clock: A clock that is guaranteed to never jump forward or backward. It’s often used for measuring intervals of time.
// std::chrono::system_clock: A clock based on the system time, representing wall-clock time.
// std::chrono::high_resolution_clock: Provides the highest available resolution clock (typically used for benchmarking or fine time measurements).


//---------------------------------------------

// -------------------PRINT STROBING TEXT FUNCTION-------------------
// Function to print text with a strobing color effect
//---------------------[  "arbirtaty words"  ],[how long it strobes]
void printStrobingText(const std::string &text, int duration) {  //
    // ---------------------ANSI COLOR CODES-------------------------
    // Array of ANSI escape codes representing different text colors.
    const std::string colors[] = {
        "\033[31m", // Red color code
        "\033[32m", // Green color code
        "\033[33m", // Yellow color code
        "\033[34m", // Blue color code
        "\033[35m", // Magenta color code
        "\033[36m", // Cyan color code
        "\033[37m"  // White color code
    };

    // -----------------------COLOR COUNT---------------------------
    // Calculate the number of colors available in the colors array
    const int colorCount = sizeof(colors) / sizeof(colors[0]);

    // Variable to track the current color index for the strobe effect
    int currentColorIndex = 0;

    // ---------------------TIME START POINT-------------------------
    // Mark the current time as the starting point of the strobing effect
    auto startTime = std::chrono::steady_clock::now();

    // -------------------LOOP FOR STROBING EFFECT-------------------
    // Infinite loop to continuously display the strobing effect until the specified duration is reached
    while (true) {
        // -------------------CHECK TIME ELAPSED----------------------
        // Get the current time and calculate how many seconds have passed since the start
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

        // If the elapsed time has reached or exceeded the duration, break out of the loop
        if (elapsedTime >= duration) {
            break; // Stop the strobing effect after the duration
        }

        // ------------------STROBING CHARACTERS----------------------
        // Iterate over each character in the string
        for (size_t currentCharacterIndex = 0; currentCharacterIndex < text.length(); ++currentCharacterIndex) {
            // "\r" moves the cursor back to the start of the line without advancing to the next line
            std::cout << "\r"; 

            // ------------------PRINTING EACH LETTER------------------
            // Iterate over the text and apply the strobing effect to the current character
            for (size_t textPosition = 0; textPosition < text.length(); ++textPosition) {
                if (textPosition == currentCharacterIndex) {
                    // When the current character is being printed, apply the current strobing color
                    std::cout << colors[currentColorIndex % colorCount] << text[textPosition];
                } else {
                    // Reset the color and print the rest of the text normally
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
//-------------------------------calling the function in the main will be like......
printStrobingText("Hello World", 5);
// ----------------------KEY CONCEPT BREAKDOWN-----------------------
// The `printStrobingText` function creates a strobing effect by changing the text color for each character 
// in sequence. The strobing lasts for a specified duration, and the colors are applied using ANSI escape codes.
// ANSI escape codes allow for changing the text color on the terminal.
// The chrono library is used to measure time, allowing the strobing effect to continue for the desired duration.
// This effect is achieved using a loop that prints each character of the string with a strobing color applied, 
// along with a small delay to create a smooth transition between colors.
// More descriptive variable names like `currentCharacterIndex` and `textPosition` have been used to clarify 
// the purpose of each loop and variable for readability.
