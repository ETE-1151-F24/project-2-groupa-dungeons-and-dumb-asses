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
        
    case 1: {                                                                               //case one is square 
            int side;                                                                       //initializes the variable [side]
            cout << "enter side length of the square:" <<endl;                              //output message prompt for the side
            cin >> side;                                                                    ////stores user input into variable [side]
            cout << "the area of the square is" << squareArea(side) << endl;                //area message followed by the function [squareArea]...
        }                                                                                   //with user specified parameter [side]
    break;

    case 2: {                                                                               //case two is rectangle
            int length,width;                                                               //initializes the variables [length] and [width]
            cout << "enter length of the rectangle:" <<endl;                                //output message prompt for the length
            cin >> length;                                                                  //stores user input into variable [length]
            cout << "enter width of rectangle square:" << endl;                             //output message promptydoo for width
            cin >> width;                                                                   //stores user input into variable [width]
            cout << "the area of the square is" << rectangleArea(length, width) << endl;    //area message followed by function [rectangleArea]...         
                                                                                            //with user specified parameters [length] and [width]
        }
    break;

    case 3: {                                                                               //case three is circle
            double radius;                                                                  //initializes the variable [radius]
            cout << "enter radius of the circle:" <<endl;                                   //output message prompt for the radius
            cin >> radius;                                                                  //stores user input into variable [radius]
            cout << "the area of the circle is" << circleArea(radius) << endl;              //area message followed by function [circleArea]...         
                                                                                            //with user specified parameter [radius]
        }
    break;

    case 4: {                                                                               //case four is cylinder
        double radius, height;                                                              //initializes the variables [radius] and [height]
        cout << "enter radius of cylinder:"  << endl;                                      //output message prompt for the radius
        cin >> radius;                                                                      //stores user input into variable [radius]
        cout << "enter the height of the cylinder:" << endl;                               //output message prompt for the height
        cin >> height;                                                                      //stores user input into variable [height]
        cout << "surface area of the cylinder:" << cylinderArea(radius, height) << endl;   //area message followed by function [cylinderArea]...
    }                                                                                           
    break;
    }
    return 0;

    }
/*
        .-.
       |_:_|
      /(_Y_)\  
     ( \/M\/ )
      ) |-| (
     /  |-|  \
    /   |_|   \
   /    (_)    \
  /'._.-' `-._.'\
 /               \
/__..--'''''--..__\
`"--.._______..--"`

lord vader approves
*/
