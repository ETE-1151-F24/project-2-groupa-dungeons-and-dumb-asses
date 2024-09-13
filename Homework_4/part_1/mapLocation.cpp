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


//-------------------------------#INCLUDES----------------------------------------------------------------
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
                                    //this is the random number generated in the map generator function
                                    //for the total x width of the map  =(rand() % 91) + 10

double locationX, locationY;        //preliminarily initializing the location variables 

string userName;                    //preliminarily initializing the [string]s:[userName], [quad], [horizontal] ,[vertical]
string quad;                 
string horizontal;
string vertical;


//-------------------------------RANDOM MAP GENERATOR FUNCTION----------------------------------------------------------------
// Function to randomly generate the size of the map
void generateMap() {                              // Random map size between 10 and 100 for both width (X) and height (Y)
    mapSizeX = (rand() % 91) + 10;                // Random width (range: 10 to 100)
    mapSizeY = (rand() % 91) + 10;                // Random height (range: 10 to 100)
}
//NOTE: to establish left and right and top and bottom quadrants i need to find the half way points of each mapSize
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
// this is used to make a generic visual of the location of the coordinate

void quadImaging() {                                                          //INITIALIZING THE QUADRANT IMAGING FUNCTION
string quad;                                                                  //initializing the string [quad] for the function

  if (horizontal == "right" && vertical == "top") {      
      quad = "1st Quadrant";                                                    // if the above conditions are met then the quadrant is this
        printStatement(quad);  
    std::cout << "[ ] [+]" << std::endl << "[ ] [ ]" << std::endl;                           //visual output of quadrant

  } else if(horizontal == "left" && vertical == "top") {      
      quad = "2nd Quadrant";                                                    // if the above conditions are met then the quadrant is this
        printStatement(quad); 
    std::cout << "[+] [ ]" << std::endl << "[ ] [ ]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "top") {      
      quad = "Top Center";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ]+[ ]" << std::endl << "[ ] [ ]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "right" && vertical == "bottom") {   
      quad = "3rd Quadrant";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "[+] [ ]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "left" && vertical == "bottom") {   
      quad = "4th Quadrant";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "[ ] [+]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "bottom") {   
      quad = "Bottom Center";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "[ ]+[ ]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "center" && vertical == "center") {   
      quad = "Exact Center";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "   +" << std::endl << "[ ] [ ]" << std::endl;         //visual output of quadrant
  }
}



//---------------------------------FINAL PRINT STATEMENT FUNCTION---------------------------------
// initializing a print statement so to use less typing later
void printStatement(string quad) {
    std::cout << "Coordinate (" << locationX <<", " << locationY <<") is located in the " << quad << " of the map." << std::endl;
}



//---------------------------------GETTING AN INPUT LOCATION FUNCTION (UNTIL VALID)-------------------------------------------------------------------------
// Function to get valid numeric input from the user and handle errors
double getNumberInput(string prompt) {                                        //and intitializing a [string] called [prompt]
  
    double number;                                                    // Declare variable to store input as [double] called [number]

    std::cout << prompt;   // Display prompt, in this case for each prompt in get number such as "enter and x coordinate"
    
    // Get input and attempt to store in [number]
    std::cin >> number;

    
    if (std::cin.fail()) {                                   // Check if the input failed (i.e., the user did not enter a valid number)
        
       
      std::cout << "Invalid input. Please enter a valid number." << std::endl;        //error message indicating input invalid
        
        
      std::cin.clear();                                     // Clear error flag on input stream [std::cin], occuring when non-num value is entered

        
        
      std::cin.ignore(1000, '\n');                          // Ignore remaining input in stream up to 1000 characters or until the next newline
                                                            // helps remove any invalid input that might still be in the buffer
                                                            //(1000 characters should be more than enough)
        
      return getNumberInput(prompt);                        // Repeat calling the function to prompt the user again and get a valid input
                                                            // Since function calls itself, it keeps doing  until user enters valid number
    }

    return number; // upon valid input (i.e., no failure in the 'std::cin' stream), return number to caller
}

