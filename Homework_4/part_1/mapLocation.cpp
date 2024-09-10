// Part 1: easy.
// Write a C++ program that prompts the user to enter their name and location point (x, y) on a map.

// The program will check whether the point is within the a random sized, map width of 20 and height 20 centered at 0,0 ie a(-10,-10),b(-10,10),c(10,10), d(10,-10).

// Hard requirements

// Use a function to check if the location is valid.
// Use a function to create the random sized map.
// Use if else.
// Have fun with this 
// Soft requirements (optional)

// Use a global variable
// Use logical operators.
// Do not have fun with this (this option will override the hard requirement, and you will be issued a -1 for your enjoyment)
 

#include <cstdlib> // Required for rand()
#include <iostream>
int main() {
  std::cout << rand() % 100 << " "; // Numbers between 0 and 99  // Output a random number between 0 and 99, followed by a space

// std::cout: Standard output stream, used to print to the console.
// rand(): Generates a random integer, often a large number. The actual range of values is system-dependent.
// % 100: This is the modulus operator. It gives the remainder when the random number is divided by 100. 
// This operation ensures the result is between 0 and 99 (inclusive).
// << " ": This inserts a space after the random number, separating it from other output.
  return 0;
}


