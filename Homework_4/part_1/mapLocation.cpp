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
#include <algorithm>                    // For std::transform (to convert to lowercase) TO CHECK NAME

// ------------------------GLOBAL VARIABLES AND STRINGS FOR MAPSIZE, LOCATION AND NAME INITIALIZATIONS---------------------
//NOTE: i only want to generate the map at the start of the program and not every time there is an error
//NOTE:  map size directions will be half in one direction and half in the other

//-------------------------------RANDOM MAP GENERATOR FUNCTION----------------------------------------------------------------
// Function to randomly generate the size of the map
void generateMap() {                                                                        // Random map size between 10 and 100 
    mapSizeX = (rand() % 91) + 10;                                                          // Random width (range: 10 to 100)
    mapSizeY = (rand() % 91) + 10;                                                          // Random height (range: 10 to 100)
}
//NOTE: to establish left and right and top and bottom quadrants i need to find the half way points of each mapSize
                                                                                            //-(mapSizeX/2) is the left of map [-halfX]
                                                                                            // (mapSizeX/2) is the right of map [halfX]
                                                                                            //-(mapSizeY/2) is the bottom of map [-halfY]
                                                                                            // (mapSizeY/2) is the top of the map  [halfY]


//--------------------------------- USER NAME ENTRY FUNCTION--------------------
bool nameEntry(){
    std::cout << std::endl << "Please enter your name." << std::endl << std::endl;                       // initial prompt
    
    std::cout << "We swears we will KEEP IT SECRET, KEEP IT SAFE ....*retching*  *gollum*  *gollum*." << std::endl << std::endl; 


    std::getline(std::cin, userName);                                                       // Use std::getline to allow names with spaces

//-------STUPID BUT FUN CONDITION IF THE NAME IS FRODO
    // Convert the input name to lowercase for case-insensitive comparison
      std::string lowerName = userName;
      std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    // Check if the name is "frodo" (any variant)
    if (lowerName == "frodo") {
        std::cout << "*Gollum screams* \"THE PRECIOUS IS MINE!!!!\"" << std::endl;
        std::cout << "\"YOU HAVE DIED... GAME OVER\"" << std::endl << std::endl;
        std::cout << "Press any key to exit..." << std::endl;
        std::cin.get();  // Wait for the user to press a key

        return false;  // Return false to indicate that the program should terminate
    }   


    std::cout << std::endl  <<  "Thank you [" << userName << "] for participating in this adventure!" << std::endl;    //THANKYOU message
      return true;
   }


//---------------------------------COORDINATE intro function--------------------
void coordination() {
  std::cout << std::endl << "Where would you like to be on the map?" << std::endl << std::endl;
  std::cout << std::endl << "The map size I chose is a secret until the end" << std::endl << std::endl;

                                                                                              //Get user X, Y coordinates using input validation
  locationX = getNumberInput("Enter an [X] coordinate: ");                                    //Call getNumberInput with prompt for x coordinate
  locationY = getNumberInput("Enter a [Y] coordinate: ");                                     //Call getNumberInput with prompt for y coordinate
                                                               
  bool validLocation = false;                                                                 // Variable tracks if location valid or not   
    
  while (!validLocation) {                                                                    //Loop until valid location is entered                                                             
                  
    validLocation = isValidLocation(locationX, locationY);                                    //Check if coordinates within the map bounds                                            
                                                                                              //Call isValidLocation to check both valid

    if (!validLocation) {                                                                     //If location invalid, show error message
                                                                          
      std::cout << std::endl << "Filthy hobbitses, trixie and false!!!" << std::endl;         //error message
      std::cout << " (apparently this location does not exist in Middle Earth)" << std::endl; //commentary
      std::cout << "         maybe try some smaller numbers" << std::endl;                    //output statement, try again, Ask for new coordinates

      locationX = getNumberInput("Enter an x coordinate: ");                                  // Get new x coordinate
      locationY = getNumberInput("Enter a y coordinate: ");                                   // Get new y coordinate
      }
  }
}






//---------------------------------LOCATION VALIDITY CHECKING FUNCTION-----------------------------------------------------------------

// Function to validate if the user's coordinates are within the map boundaries
// Updated: Now uses global variables locationX and locationY directly
bool isValidLocation(double locationX, double locationY) {
    float halfX = mapSizeX / 2;                                   //[halfX] or [halfY] is measure of quadrant sizes in either direction
    float halfY = mapSizeY / 2;
    return (locationX >= -halfX && locationX <= halfX) && (locationY >= -halfY && locationY <= halfY);

}                                                           //this boolean either return true/false value if both conditions meet or fail




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
 
void quadImaging() {                                                              //INITIALIZING THE QUADRANT IMAGING FUNCTION
std::string quad;

  if (horizontal == "right" && vertical == "top") {      
      quad = "1st Quadrant";                                                      // if the above conditions are met then the quadrant is this
        printStatement(quad);  
    std::cout << "[ ] [+]" << std::endl << "[ ] [ ]" << std::endl;                           //visual output of quadrant

  } else if(horizontal == "left" && vertical == "top") {      
      quad = "2nd Quadrant";                                                      // if the above conditions are met then the quadrant is this
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
  
  } else if (horizontal == "left" && vertical == "center") {   
      quad = "Left Center";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << " +" << std::endl << "[ ] [ ]" << std::endl;         //visual output of quadrant
  
  } else if (horizontal == "right" && vertical == "center") {   
      quad = "Right Center";
        printStatement(quad);                                                     // if the above conditions are met then the quadrant is this
    std::cout << "[ ] [ ]" << std::endl << "     +" << std::endl << "[ ] [ ]" << std::endl;         //visual output of quadrant
  }
}



//---------------------------------FINAL PRINT STATEMENT FUNCTION---------------------------------
// initializing a print statement so to use less typing later
void printStatement(std::string quad) {
    std::cout << "Coordinate (" << locationX <<", " << locationY <<") is located in the " << quad << " of the map." << std::endl;
}



//---------------------------------GETTING AN INPUT LOCATION FUNCTION (UNTIL VALID)-------------------------------------------------------------------------
// Function to get valid numeric input from the user and handle errors
double getNumberInput(std::string prompt) {                                       //and intitializing a [string] called [prompt]
  
  double number;                                                                  // Declare variable to store input as [double] called [number]
   
    while (true) {                                                                //while loop                                           

      std::cout << prompt;                                                        //Display prompt, for each occurence "enter coordinate"
    
      std::cin >> number;                                                         //Get input and attempt to store in [number]

      if (std::cin.fail()) {                                                      //Check if input failed (i.e.,user didnt enter valid number)
              
        std::cout << "Invalid input. Please enter a valid number no letters." << std::endl;        //error message indicating input invalid   
        
        std::cin.clear();                                     // Clear error flag on input stream [std::cin], from non-num value entered    
        
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining invalid input in the buffer

        } else {
                 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any remaining characters in buffer after valid input
            return number;                                    // Valid input received, return it
        }
    }
}



//---------------------------------REVEALING THE MAP AND QUADRANT SIZE FUNCTION---------------
   void showMapSizes() { // Calculate halfX and halfY here for final statement
    float halfX = mapSizeX / 2.0f;
    float halfY = mapSizeY / 2.0f;

    std::cout << "The map is ("<< mapSizeX << " by "<< mapSizeY << ") B T dubs"<< std::endl;
    std::cout << "Each quadrant is ("<< halfX << " by "<< halfY << ")" << std::endl << std::endl;
   }


