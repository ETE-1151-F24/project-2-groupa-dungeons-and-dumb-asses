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

//int the header file [areaStuff.h] i am specifying the constants that will have the functions attatched to them
using namespace std;

int main() {

//i need to initialize a variable to store the user input
int option;                                     // this code initialzes a variable to store the user input as [option] and an integer

cout << "Choose an object to calculate the area of (1-4)" << endl;  
                                                // Outputs a message to the user, prompting number between 1 and 4 for which area
cout << "1. Area of a square" << endl;          //this is the output message for square option
cout << "2. Area of a rectangle" << endl;       //this is the output message for rectangle option
cout << "3. Area of a circle" << endl;          //this is the output message for circle option
cout << "4. Area of a cylinder" << endl;        //this is the output message for cylinder option
cin >> option;                                  // this is the code for waiting for the user input and then stores it to [option]

switch (option){                                //initializes [switch] operator to check which [case] is chosen/referenced from [option]
                                                //for each case, it will perform the following operations
                                                // which is declare my parameter variable(s), prompt input for them, store the input...
                                                // use stored inputs to run case specific functions  
        
        case 1: {
            int side;


        }
        break;

        case 2: {
            int length,width;
             


        }
        break;

        case 3: {
            double radius
             


        }
        break;

        case 4: {
            double radius, height,
            cout << "Enter the radius of the cylinder: ";  
            cin >> radius;  
            cout << "enter cylinder height"
            cin >> height;  
            cout << "Total surface area of the cylinder: " << cylinderArea(radius, height) << std::endl;  // Call the function
            break; 


        }
        break;








return 0;
}