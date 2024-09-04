//preliminary declaration of comment notation, when i make comments, i am puttin [] around named objects
// i am doing this convention to help that stand out in my comments better


#include "conversionStuff.h"  // Includes the functions that i declared in conversionStuff.h
#include<iostream>
#include<string>               //this is the statement to include the string library for using the [string] syntax
#include<cctype>                // this code includes a library to help with the [isalpha] input check
using namespace std; //this makes it the [std::] naming scheme so i dont have to type it over and over

void charToBinary(char c); //initializes the [charToBinary] function and references variable [c]
void numToBinary(int n);  //initializes the number to binary function and references variable [n]
void floaterToBinary(float f);  //initializes the floater to binary function and references variable [f]

int main() {
    //this section of code might be best suited as an intro function
    string inputToConvert; // this is intitializing a string to store an input in a variable named [inputToConvert]
    cout << "Input something to convert to binary" << endl; // this is the output prompt message at the beginning of the program
    cin >> inputToConvert;                                  //this will read the user input into the string [inputToConvert]

    //this is where i am checking to see what kind of input it is that i am working with

    //if thing is character then convert char to binary
            //this code should call the function from [conversionStuff.h]
    if (inputToConvert.length() == 1 && isalpha(inputToConvert[0])){
        charToBinary(inputToConvert[0]);       //[.length() is checking to see what the length of [inputToConvert] is and == 1 asks if it is one
    }                                            //&& is the notation for and when combining operational conditions
                                            //[isalpha] is the check to see if the inpur
                                            //line 24 calls up the [charToBinary] function and initializes it with the value at position [0] of [inputToConvert] 
                                        
    // if thing is float, then convert float to binary
            //this code should call the function from [conversionStuff.h]
    else if (inputToConvert.find('.' ) != string::npos){    //[.find] searches the input number for a [.]  If not found, it returns string::npos, which means no match.  (https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/)
        float f = stof(inputToConvert);                     //this is making a float varible [f] that is assigned with the string stored as a float value [stof]...(string to float) for the [inputToConvert]
        floaterToBinary(f);                                 // this calls up the [floaterToBinary] function and runs it based on variable [f]
    //if the input i make isnt a charachter or float, then look at it as an integer
    }

    //if thing is integer then convert int to binary
            //this code should call the function from [conversionStuff.h]
    else {
        int n = stoi(inputToConvert); //this takes the string [inputToConvert] and stores it as an integer variable [n] using [stoi] (store to integer) 
        numToBinary(n);  //this initializes my function [numToBinary] with the integer value stored in the assignment variable [n]
    }

    return 0;    //returns the value of 0 if the program completes correctly                   
}
// there was some mention fo possibly putting error handling into the program but i am not sure what to do with it.