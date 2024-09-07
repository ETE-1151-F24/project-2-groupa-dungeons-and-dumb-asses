/*  Read the 2 following web pages
5.4 — Constant expressions and compile-time optimization – Learn C++ (learncpp.com)Links to an external site.
5.5 — Constexpr variables – Learn C++ (learncpp.com)Links to an external site.
Using what you read incorporate Constant expressions and Constexpr variables in this homework.
 */


/*Starting with your Homework #1 create a program that calculates the area of a circle, square, rectangle and a cylinder depending on the selected input of the user. 

1. Calculate the area of a square.
2. Calculate the area of a rectangle.
3. Calculate the area of a circle.
4. Calculate the area of a cylinder.
Please enter your choice (1-4) 1
Enter hight:1
Enter width:1
Enter length:1
total area:1        */




#include <iostream>            // Includes the standard input/output stream library for cout
#include "areaStuff.h"
using namespace std;
//i need to make [constant expressions] for area for square, rectangles, or circles, cylinders,
//area of a square = side*side
//area of a rectangle = length * width
// area of a circle = pi*(radius^2) = pi*radius*radius which will need to be a double because pi has so many decimal places
// area of a cylinder = pi*radius*radius*height which will need to be a double because pi has so many decimal places
// also need a constant expression for pi which will need to be a double because pi has so many decimal places

constexpr double pi = 3.14159265358979323846;  
// Constexpr ensures the value of pi is computed at compile-time and double allows it to be many decimal places

constexpr int squareArea(int side) {
    // ths Define a [constexpr] function [int squareArea] with the parameter of type [int] named [side]to calculate the area of a square
    return side * side;  // Returns the area of the square (side * side)
}
constexpr
constexpr
constexpr





int main() {

//i need to initialize a variable to store the user input
int option;  // this code initialzes a variable to store the user input as [option] and an integer

cout << "Choose an object to calculate the area of (1-4)" << endl;  
// Outputs a message to the user, prompting them to choose a number between 1 and 4 to select which object’s area they want to calculate.
cout << "1. Area of a square" << endl;      //this is the output message for square option
cout << "2. Area of a rectangle" << endl;   //this is the output message for rectangle option
cout << "3. Area of a circle" << endl;      //this is the output message for circle option
cout << "4. Area of a cylinder" << endl;    //this is the output message for cylinder option
return 0;
}