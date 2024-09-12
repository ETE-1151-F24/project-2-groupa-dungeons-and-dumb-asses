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
 

#include "mapStuff.h"      // Include the header file for map functions
#include <iostream>        // For input/output functionality
#include <cstdlib>         // For rand() function (random number generation)
#include <ctime>           // For time() function to seed random number generator
#include <limits>          // For numeric limits to handle input errors

using namespace std; // Use standard [std] C++ namespace


//THESE ARE GOING TO BE GLOBAL VARIABLES SUCH AS THE MAPSIZE AND THE USER LOCATIONS ENTERED

//i only want to generate the map at the start of the program and not every time there is an error
// map size directions will be half in one direction and half in the other
int mapSizeX; //this is the random number generated for the total x width of the map  =(rand() % 81) + 20
int mapSizeY; // this is the random number generated for the total y width of the map =(rand() % 81) + 20

//LOGICAL OPERATORS WOULD BE IF, ELSE, OR BOOLEANS
//for the input of [locations (X,Y)], 
//i will want error handling messages that say that the input was expecting a number and got a letter or something else

// Global variables for map size and user coordinates (defined here)
int mapSizeX, mapSizeY;       //preliminarily initializing the mapsize variables
double locationX, locationY;  //preliminarily initializing the location variables
string userName;              //preliminarily initializing the [string] [userName]


// Function to randomly generate the size of the map
void generateMap() {
    // Random map size between 20 and 100 for both width (X) and height (Y)
    mapSizeX = (rand() % 81) + 20; // Random width (range: 20 to 100)
    mapSizeY = (rand() % 81) + 20; // Random height (range: 20 to 100)

    // Output the generated map size
    cout << "Randomly generated map size is " << mapSizeX << " (width) by " << mapSizeY << " (height)." << endl;
}





//to establish left and right and top and bottom quadrants i need to find the half way points of each mapSize
    //-(mapSizeX/2) is the left side of the map
    // (mapSizeX/2) is the right ide of the map
    //-(mapSizeX/2) is the bottom side of the map
    // (mapSizeX/2) is the top side of the map

 //   if locationX>0 and locationX<= (mapSizeX/2)....then [horizontal]=right and confirmX=true
//    else....if locationX==0....then [horizontal]=center and confirmx=true
 //   else....if locationX<0 and locationX>= -(mapSizeX/2)....then [horizontal]=left and confirmX=true
//      else....confirmX=false


 //   if locationY>0 and locationY<= (mapSizeY/2)....then [vertical]=top and confirmY=true
//    else....if locationY==0....then [vertical]=center and confirmy=true
 //   else....if locationY<0 and locationY>= -(mapSizeY/2)....then [vertical]=bottom and confirmY=true
//      else....confirmY=false

if confirmX=true and confirmY=true;
  outcome = Success       //initialize outcome variable
else {
  outcome = Failure
  // while the outcome is a failure, return the user to the input prompt after displaying [wrong guess]
}


//if [horizontal]=right && [vertical]=top:        then [quadrant] = quad1
//if [horizontal]=left  && [vertical]=top:        then [quadrant] = quad2
//if [horizontal]=center  && [vertical]=top:      then [quadrant] = topcenter
//if [horizontal]=right && [vertical]=bottom:     then [quadrant] = quad3
//if [horizontal]=left  && [vertical]=bottom:     then [quadrant] = quad4
//if [horizontal]=center  && [vertical]=bottom:   then [quadrant] = bottomcenter
//if [horizontal]=center && [vertical]=center:    then [quadrant] = exactcenter

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
//[+] [ ]


//if [quadrant]= topcenter then display message 
//you are located in the top center of the map
//[ ]+[ ]
//[ ] [ ]

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


