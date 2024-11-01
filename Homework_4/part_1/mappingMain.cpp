#include <iostream>
#include <ctime>                                                                            // For time() to seed random number generator
#include "mapLocation.cpp"
#include "mapStuff.h"                                                                       // Include the header file for map functions

int main() {
    srand(time(0));                                                                         //Seed random number generator to 
                                                                                            //ensure random map size each time program runs   
     
//-------------------------- MAP GENERATION FUNCTION ----------------------------    
    generateMap();                                                                          //Generate random map size, but doesnt print yet

//-------------------------- USER NAME ENTRY FUNCTION ---------------------------
   
    // If nameEntry() returns false (i.e., if the name is "Frodo"), we immediately return 0 to stop the program
if (!nameEntry()) {                                                                         //Call nameEntry() function check return value
    return 0;  // End the program if the user enters "Frodo"
    }

//-------------------------- USER lOCATION ENTRY FUNCTION -----------------------

    coordination();                                                                         // Call [coordination] function FOR valid coordinates

//-------------------------- CALCULATIONS AND RESOLUTIONS OF LOCATION -----------
    determineQuadrant(locationX, locationY);                                                //After valid input, determine the quadrant and 
    
    quadImaging();                                                                          //print the map location

    showMapSizes();                                                                         //RUNS function to reveal actual map size
  std::cout << "Thanks for playing preshuss" << std::endl << std::endl;

      
    std::cout << "\nPress any key to exit..." << std::endl;                                 // Wait for user input before closing 
    std::cin.get();                                                                         // Wait for the user to press any key
    return 0;
}

