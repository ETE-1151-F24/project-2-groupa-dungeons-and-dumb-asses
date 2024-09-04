#include "conversionStuff.h"  // Includes the functions that i declared in conversionStuff.h
#include <iostream>            // Includes the standard input/output stream library for cout
#include <bitset>              // Includes the bitset library for handling binary representation of numbers   ***thank you stack overflow***
using namespace std;

//here is where i have my functions stored as far as what each one will do
//i had to use syntax pulled from stackoverflow in order to perform the operations because i didnt know what the correct syntax was

//here is the code for the function [charToBinary]
void charToBinary(char c) {
    // [bitset<8>] creates a bitset of 8 bits, representing the char [c]
    bitset<8> binary(c);  //  then convert the char [c] to an 8-bit [binary] number
    cout << binary << endl;  // then it outputs the binary  to the console
}

//here is the code for the function [numToBinary]
void numToBinary(int n) {
    //[bitset<32>] creates a bitset of 32 bits, representing the integer [n]
    bitset<32> binary(n);  // and then Converts the integer [n] to a 32-bit [binary] number
    cout << binary << endl;  // then it outputs the binary
}

//here is the code for the function [floaterToBinary]
void floaterToBinary(float f) {
    // Handle float conversion
    // This is just a placeholder; floats are more complex to handle
    // as their binary representation involves IEEE 754 encoding
    // You might need a more sophisticated approach for accurate conversion
    union {
        float input;
        int output;
    } data;
    data.input = f;
    std::bitset<32> binary(data.output);
    std::cout << binary << std::endl;
}