#ifndef CONVERSIONSTUFF_H       //if my [conversionStuff.h] isnt already defined...
#define CONVERSIONSTUFF_H       //then define [CONVERSIONSTUFF_H] with the following code lines as seen below

// Create a program that takes and input and converts it to binary 
// Program should be able to return correct binary value of Chars, int and floats
// +1 point for creating a function
// Here is a helpful web page
// function for character

//   ##example##
// int addNumbers( int first_param, int second_param){
//     int result = first_param + second_param;
//     return result;
// }       

void charToBinary(char c);      //preliminarily declaring a function called [charToBinary] and expecting a character [char] variable [c]
void numToBinary(int n);        //preliminarily declaring a function called [numToBinary] and expecting a integer [int] variable [n]
void floaterToBinary(float f);  //preliminarily declaring a function called [floaterToBinary] and expecting a float [float] variable [f]

//this is the statement to end the definition of the [conversionStuff.h]
#endif // CONVERSIONSTUFF_H