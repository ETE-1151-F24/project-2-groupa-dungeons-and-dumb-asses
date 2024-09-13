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


// ------------------------GLOBAL VARIABLES AND STRINGS FOR MAPSIZE, LOCATION AND NAME INITIALIZATIONS---------------------
//NOTE: i only want to generate the map at the start of the program and not every time there is an error
//NOTE:  map size directions will be half in one direction and half in the other

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
bool isValidLocation(double locationX, double locationY) {
    int halfX = mapSizeX / 2; //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    return (locationX >= -halfX && locationX <= halfX) && (locationY >= -halfY && locationY <= halfY);
} // this boolean wiLL either return a true or false value if both of the conditions meet or fail




//---------------------------------QUADRANT DETERMINING FUNCTION--------------------------------------------------------------------------------
void determineQuadrant(double locationX, double locationY) {                      //determining the quadrant location on the map based on [locationX] and [loactionY]
    int halfX = mapSizeX / 2;                   //this is setting a halfwaypoint in either direction of the origin(0,0) based on the mapsize
    int halfY = mapSizeY / 2;
    
//----------checking X location                 //FINDING [locationX] within SPECIFIC bounds of the [halfx] measurements
    if (locationX > 0 && locationX <= halfX) {  
        horizontal = "right";                  //assign [right] if positive x
    } else if (locationX == 0) {
        horizontal = "center";                 //assign [center] if x == 0
    } else {
        horizontal = "left";                   //assign [left] if negative x
    }
//----------checking Y location                 //FINDING [locationY] within SPECIFIC bounds of the [halfy] measurements
    if (locationY > 0 && locationY <= halfY) {  
        vertical = "top";                      //assign [top] if positive y
    } else if (locationY == 0) {
        vertical = "center";                   //assign [center] if y == 0
    } else{
      vertical = "bottom";                     //assign [bottom] if negative y
    }
}


//---------------------------------QUADRANT IMAGING FUNCTION---------------------------------------------
// this is used to make a generic visual of the location of the coordinate
 
void quadImaging() {                                                          //INITIALIZING THE QUADRANT IMAGING FUNCTION
std::string quad;

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

  } else if (horizontal == "left" && vertical == "bottom") {   
      quad = "3rd Quadrant";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "[+] [ ]" << std::endl;                           //visual output of quadrant

  } else if (horizontal == "right" && vertical == "bottom") {   
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
void printStatement(std::string quad) {
    std::cout << "Coordinate (" << locationX <<", " << locationY <<") is located in the " << quad << " of the map." << std::endl;
}



//---------------------------------GETTING AN INPUT LOCATION FUNCTION (UNTIL VALID)-------------------------------------------------------------------------
// Function to get valid numeric input from the user and handle errors
double getNumberInput(std::string prompt) {                                        //and intitializing a [string] called [prompt]
  
  double number;                                                              // Declare variable to store input as [double] called [number]
   
    while (true) {                                                            //while loop                                           

      std::cout << prompt;                                                    //Display prompt, for each occurence "enter coordinate"
    
      std::cin >> number;                                                     //Get input and attempt to store in [number]

      if (std::cin.fail()) {                                                  //Check if input failed (i.e.,user didnt enter valid number)
              
        std::cout << "Invalid input. Please enter a valid number no letters." << std::endl;        //error message indicating input invalid   
        
        std::cin.clear();                                     // Clear error flag on input stream [std::cin], from non-num value entered    
        
        std::cin.ignore(1000, '\n');                          // Ignore remaining input in stream up to 1000 characters or until the next newline
                                                              // helps remove any invalid input that might still be in the buffer
                                                              //(1000 characters should be more than enough)        
        } else {
            return number;                                    // Valid input received, return it
        }
    }
}

