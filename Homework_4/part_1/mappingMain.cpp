#include <iostream>
#include <ctime>            // For time() to seed random number generator
#include "mapLocation.cpp"
#include "mapStuff.h"                   // Include the header file for map functions

int main() {
    srand(time(0));                                                                         //Seed random number generator to 
                                                                                            //ensure random map size each time program runs   
     
    
    generateMap();                                                                          //Generate random map size, but doesnt print yet

//-------------------------- USER NAME ENTRY CODE--------------------
    std::cout << "Please enter your name." << std::endl << std::endl;                       // initial prompt
    
    std::getline(std::cin, userName);                                                       // Use std::getline to allow names with spaces
    
    std::cout << std::endl  <<  "Thank you [" << userName << "] for participating in this adventure!" << std::endl;    //THANKYOU message

 
//-------------------------- USER lOCATION ENTRY FUNCTION--------------------

    coordination();                                                              // Call [coordination] function to get valid coordinates

    
    // After valid input, determine the quadrant and print the map size
    // Determine and display quadrant info
    determineQuadrant(locationX, locationY);
    quadImaging();

        // Calculate halfX and halfY here
    float halfX = mapSizeX / 2.0f;
    float halfY = mapSizeY / 2.0f;

    std::cout << "The map is ("<< mapSizeX << " by "<< mapSizeY << ") B T dubs"<< std::endl;
    std::cout << "Each quadrant is ("<< halfX << " by "<< halfY << ")" << std::endl;
    return 0;
}

