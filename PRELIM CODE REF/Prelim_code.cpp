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