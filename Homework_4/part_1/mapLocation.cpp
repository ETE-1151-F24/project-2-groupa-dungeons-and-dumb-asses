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
 

#include "mapStuff.h"         // Include the header file for map functions
#include <iostream>           // For input/output functionality
#include <cstdlib>            // For rand() function (random number generation)
#include <ctime>              // For time() function to seed random number generator
#include <limits>             // For numeric limits to handle input errors

using namespace std;          // Use standard [std] C++ namespace




// ------------------------Global variables for map size and user coordinates (defined here)
//i only want to generate the map at the start of the program and not every time there is an error
// map size directions will be half in one direction and half in the other


int mapSizeX, mapSizeY;       //preliminarily initializing the mapsize variables
                              //this is the random number generated for the total x width of the map  =(rand() % 81) + 20
double locationX, locationY;  //preliminarily initializing the location variables 
                              // this is the random number generated for the total y width of the map =(rand() % 81) + 20
string userName;              //preliminarily initializing the [string] [userName]
int quadrant;

// Function to randomly generate the size of the map
void generateMap() {                        // Random map size between 20 and 100 for both width (X) and height (Y)
    mapSizeX = (rand() % 81) + 20;          // Random width (range: 20 to 100)
    mapSizeY = (rand() % 81) + 20;          // Random height (range: 20 to 100)
}





//to establish left and right and top and bottom quadrants i need to find the half way points of each mapSize
    //-(mapSizeX/2) is the left side of the map [-halfx]
    // (mapSizeX/2) is the right ide of the map [halfx]
    //-(mapSizey/2) is the bottom side of the map [-halfy]
    // (mapSizey/2) is the top side of the map  [halfy]
    string horizontal;
    string vertical;
    bool confirmX;
    bool confirmY;
// Function to validate if the user's coordinates are within the map boundaries
// Updated: Now uses global variables locationX and locationY directly
//--------------------------------------------------------------------------------------------------
bool isValidLocation() {
    int halfX = mapSizeX / 2; //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    return (locationX >= -halfX && locationX <= halfX) && (locationY >= -halfY && locationY <= halfY);
} // this boolean with either return a true or false value if both of the conditions meet or fail
//-----------------------------------------------------------------------------------------------------------------
void determineQuadrant() {   //determining the quadrant location on the map based on [locationX] and [loactionY]
    int halfX = mapSizeX / 2; //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    string horizontal, vertical;
    string quad;
//----------checking x location
    if (locationX > 0 && locationX <= halfX) {  //if the [locationX] is within the bounds of the [halfx] measurements
        horizontal == "right";
    } else if (locationX == 0) {
        horizontal == "center";
    } else {
        horizontal == "left";
    }
//----------checking y location
    if (locationY > 0 && locationY <= halfY) {  //if the [locationY] is within the bounds of the [halfy] measurements
        vertical == "top";
    } else if (locationY == 0) {
        vertical == "center";
    } else{
      vertical == "bottom";
    }
//now checking for
if (horizontal == "right" && vertical == "top"){      
quad = "Quadrant 1";
cout << "you are located in" << quad << endl;
cout << "[ ] [+]" << endl<<"[ ] [ ]" << endl;

} else if(horizontal =="left" && vertical == "top"){      
  quad = "Quadrant 2";
cout << "" << endl;//you are located in Quadrant 2 
cout << "" << endl;//[+] [ ]
cout << "" << endl;//[ ] [ ]
} else if (horizontal="center" && vertical="top"){      
  quad = "topcenter";
//if [quadrant]= topcenter then display message 
cout << "" << endl;//you are located in the top center of the map
cout << "" << endl;//[ ]+[ ]
cout << "" << endl;//[ ] [ ]
} else if (horizontal="right" && vertical="bottom"){   
  quad = "quad3";
//if [quadrant]= quad3 then display message 
cout << "" << endl;//you are located in Quadrant 3 
cout << "" << endl;//[ ] [ ]
cout << "" << endl;//[+] [ ]
} else if (horizontal="left" && vertical="bottom"){   
  quad = "quad4";
//if [quadrant]= quad4 then display message 
cout << "" << endl;//you are located in Quadrant 4 
cout << "" << endl;//[ ] [ ]
cout << "" << endl;//[ ] [+]
} else if (horizontal="center" && vertical="bottom"){   
  quad = "bottomcenter";
//if [quadrant]= bottomcenter then display message 
cout << "" << endl;//you are located in the bottom center of the map 
cout << "" << endl;//[ ] [ ]
cout << "" << endl;//[ ]+[ ]
} else if (horizontal="center" && vertical="center"){   
  quad = "exactcenter";
  //if [quadrant]= exactcenter then display message 
//you are located in the bottom center of the map 
//[ ] [ ]
//   +
//[ ] [ ]
}
//if [quadrant] is in quad1 then display message 
//you are located in Quadrant 1 
//[ ] [+]
//[ ] [ ]

//if [quadrant]= quad2 then display message 
//you are located in Quadrant 2 
//[+] [ ]
//[ ] [ ]

//if [quadrant]= quad3 then display message 
//you are located in Quadrant 3 
//[ ] [ ]
//[+] [ ]

//if [quadrant]= quad4 then display message 
//you are located in Quadrant 4 
//[ ] [ ]
//[ ] [+]




//if [quadrant]= bottomcenter then display message 
//you are located in the bottom center of the map 
//[ ] [ ]
//[ ]+[ ]

//if [quadrant]= exactcenter then display message 
//you are located in the bottom center of the map 
//[ ] [ ]
//   +
//[ ] [ ]

int main() {
 std::cout << rand() % 100 << " "; // Output a random number between 0 and 99, followed by a space
// [rand()]: Generates a random integer, often a large number. The actual range of values is system-dependent.
// [% 100]: This is the modulus operator. It gives the remainder when the random number is divided by 100. 
// This operation ensures the result is between 0 and 99 (inclusive).
// << " ": This inserts a space after the random number, separating it from other output.


/*this is where the code to randomly choose the size of the map from a range of 10 to 100 */

//USER NAME ENTRY CODE
cout << "Please enter your name." << endl;
cout << "We swears we will 'keep it secret, keep it safe' *Gollum* *Gollum*" << endl;
cin >> userName ;
cout << "Thank you "<< userName <<"for participating in this adventure" << endl;
cout << "Where would you like to be on the map?" << endl;

//[COORDINATE FUNCTION] 
      cout << "Enter an x coordinate: ";
      cin >> locationX;
      cout << "Enter a y coordinate:";
      cin >> locationY;



//THIS IS THE SECTION FOR THE FAILURE MESSAGE
// if the x and/OR y location dont fit anywhere on the random map then display the messages
// "Filthy hobbitses, trixie and false!!! (apparently this location does not exist on the map i had in mind)
// "MAYBE TRY A SMALLER NUMBER"
/*output statement to try again*/


//THEN GO TO SPECIFIED [COORDINATE FUNCTION] FOR ENTERING THE VALUES I WILL NEED SOME FORM OF A [WHILE] LOOP


/*choice of output results*/
      //variable [outcome] =
                  //success; then display message "you have chosen wisely"
                  //failure; while the [outcome] is failure, 

                  //if a value entered for either of the numbers is too big, put a message that says, maybe try a smaller location with either x or y








  return 0;
}


