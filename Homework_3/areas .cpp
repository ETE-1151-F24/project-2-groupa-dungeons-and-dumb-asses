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


//i need to make [constant expressions] for area for square, rectangles, or circles, cylinders,
//area of a square = side*side
//area of a rectangle = length * width
// area of a circle = pi*(radius^2) = pi*radius*radius
// area of a cylinder = pi*radius*radius*height 
// also need a constant expression for pi


#include <iostream>            // Includes the standard input/output stream library for cout
using namespace std;

constexpr
constexpr
constexpr
constexpr
constexpr





int main() {


cout << "Choose an object to calculate the area of (1-4)" << endl;  
// Outputs a message to the user, prompting them to choose a number between 1 and 4 to select which object’s area they want to calculate.
cout << "1. Area of a square" << endl;
cout << "2. Area of a rectangle" << endl;
cout << "3. Area of a circle" << endl;
    return 0;
}