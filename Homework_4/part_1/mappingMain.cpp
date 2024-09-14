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
   nameEntry();

//-------------------------- USER lOCATION ENTRY FUNCTION -----------------------

    coordination();                                                                         // Call [coordination] function FOR valid coordinates

//-------------------------- CALCULATIONS AND RESOLUTIONS OF LOCATION -----------
    determineQuadrant(locationX, locationY);                                                //After valid input, determine the quadrant and 
    
    quadImaging();                                                                          //print the map location

    showMapSizes();                                                                         //RUNS function to reveal actual map size
  
    return 0;
}

