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
 

#include "mapStuff.h"                   // Include the header file for map functions
#include <iostream>                     // For input/output functionality
#include <cstdlib>                      // For rand() function (random number generation)
#include <ctime>                        // For time() function to seed random number generator
#include <limits>                       // For numeric limits to handle input errors

using namespace std;                    // Use standard [std] C++ namespace




// ------------------------GLOBAL VARIABLES AND STRINGS FOR MAPSIZE, LOCATION AND NAME INITIALIZATIONS---------------------
//NOTE: i only want to generate the map at the start of the program and not every time there is an error
//NOTE:  map size directions will be half in one direction and half in the other


int mapSizeX, mapSizeY;             //preliminarily initializing the mapsize variables
                                    //this is the random number generated for the total x width of the map  =(rand() % 81) + 20

double locationX, locationY;        //preliminarily initializing the location variables 

string userName;                    //preliminarily initializing the [string]s [userName] [quad] [horizontal] [vertical]
string quad;                 
string horizontal;
string vertical;

//-------------------------------RANDOM MAP GENERATOR FUNCTION----------------------------------------------------------------
// Function to randomly generate the size of the map
void generateMap() {                              // Random map size between 10 and 100 for both width (X) and height (Y)
    mapSizeX = (rand() % 91) + 10;                // Random width (range: 10 to 100)
    mapSizeY = (rand() % 91) + 10;                // Random height (range: 10 to 100)
}
//to establish left and right and top and bottom quadrants i need to find the half way points of each mapSize
    //-(mapSizeX/2) is the left side of the map [-halfX]
    // (mapSizeX/2) is the right ide of the map [halfX]
    //-(mapSizeY/2) is the bottom side of the map [-halfY]
    // (mapSizeY/2) is the top side of the map  [halfY]............SEE BELOW


//---------------------------------LOCATION VALIDITY CHECKING FUNCTION-----------------------------------------------------------------
// Function to validate if the user's coordinates are within the map boundaries
// Updated: Now uses global variables locationX and locationY directly
bool isValidLocation() {
    int halfX = mapSizeX / 2; //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    return (locationX >= -halfX && locationX <= halfX) && (locationY >= -halfY && locationY <= halfY);
} // this boolean wiLL either return a true or false value if both of the conditions meet or fail


//---------------------------------FINAL PRINT STATEMENT FUNCTION---------------------------------
// initializing a print statement so to use less typing later
void printStatement(string quad) {
    cout << "Coordinate (" << locationX <<", " << locationY <<") is located in the " << quad << " of the map." << endl;
}


//---------------------------------QUADRANT DETERMINING FUNCTION--------------------------------------------------------------------------------
void determineQuadrant() {                      //determining the quadrant location on the map based on [locationX] and [loactionY]
    int halfX = mapSizeX / 2;                   //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    string horizontal, vertical;
    string quad;
    
//----------checking X location
    if (locationX > 0 && locationX <= halfX) {  //FINDING [locationX] within SPECIFIC bounds of the [halfx] measurements
        horizontal == "right";
    } else if (locationX == 0) {
        horizontal == "center";
    } else {
        horizontal == "left";
    }
//----------checking Y location
    if (locationY > 0 && locationY <= halfY) {  //FINDING [locationY] within SPECIFIC bounds of the [halfy] measurements
        vertical == "top";
    } else if (locationY == 0) {
        vertical == "center";
    } else{
      vertical == "bottom";
    }
}




//---------------------------------QUADRANT IMAGING FUNCTION---------------------------------------------
void quadImaging() {                                                          //INITIALIZING THE QUADRANT IMAGING FUNCTION
string quad;                                                                  //initializing the string [quad] for the function

  if (horizontal == "right" && vertical == "top") {      
    quad = "1st Quadrant";                                                    // if the above conditions are met then the quadrant is this
    printStatement(quad);  
    cout << "[ ] [+]" << endl << "[ ] [ ]" << endl;                           //visual output of quadrant

  } else if(horizontal == "left" && vertical == "top") {      
    quad = "2nd Quadrant";                                                    // if the above conditions are met then the quadrant is this
    printStatement(quad); 
    cout << "[+] [ ]" << endl << "[ ] [ ]" << endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "top") {      
    quad = "Top Center";
    printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    cout << "[ ]+[ ]" << endl << "[ ] [ ]" << endl;                           //visual output of quadrant

  } else if (horizontal == "right" && vertical == "bottom") {   
    quad = "3rd Quadrant";
    printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    cout << "[ ] [ ]" << endl << "[+] [ ]" << endl;                           //visual output of quadrant

  } else if (horizontal == "left" && vertical == "bottom") {   
    quad = "4th Quadrant";
    printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    cout << "[ ] [ ]" << endl << "[ ] [+]" << endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "bottom") {   
    quad = "Bottom Center";
    printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    cout << "[ ] [ ]" << endl << "[ ]+[ ]" << endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "center") {   
    quad = "Exact Center";
    printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    cout << "[ ] [ ]" << endl << "   +" << endl << "[ ] [ ]" << endl;         //visual output of quadrant
  }
}

//---------------------------------GETTING AN INPUT LOCATION FUNCTION---------------------------------------------------------------------------------
// Function to get valid numeric input from the user and handle errors
double getNumberInput(string prompt) {
  
    double number;  // Declare variable [number] of type double that will store the user's input

    // Start an infinite loop to continuously prompt the user until valid input is received
    while (true) {
        // Output the prompt message to the console (e.g., "Enter a number: ")
        cout << prompt;




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


