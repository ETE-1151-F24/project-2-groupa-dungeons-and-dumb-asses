#include <iostream>
#include <ctime>            // For time() to seed random number generator
#include "mapStuff.h"       // Include the header file with your function declarations and global variables


int main() {
    srand(time(0));                                                                         //Seed random number generator to 
                                                                                            //ensure random map size each time program runs   
     
    
    generateMap();                                                                          //Generate random map size, but doesnt print yet

//-------------------------- USER NAME ENTRY CODE--------------------
    std::cout << "Please enter your name." << std::endl;                                              // initial prompt

    std::cin >> userName;                                                                        // Get user name and store in global variable [userName]
    
    std::cout << "Thank you " << userName << " for participating in this adventure!" << std::endl;    //THANKYOU message

 
//-------------------------- USER lOCATION ENTRY CODE--------------------
    std::cout << "Where would you like to be on the map?" << std::endl;

                                                                                            //Get user X, Y coordinates using input validation
    locationX = getNumberInput("Enter an x coordinate: ");                                  //Call getNumberInput with prompt for x coordinate
    locationY = getNumberInput("Enter a y coordinate: ");                                   //Call getNumberInput with prompt for y coordinate
  
                                                                
    bool validLocation = false;                                                             // Variable tracks if location valid or not   
    
    while (!validLocation) {                                                                //Loop until valid location is entered                                                             
                  
        validLocation = isValidLocation();                                                 //Check if entered coordinates within the map bounds                                            
                                                                                            //Call isValidLocation to check both coordinates valid

        if (!validLocation) {                                                               //If location invalid, show error message
                                                                          

        std::cout << "Filthy hobbitses, trixie and false!!!" << std::endl;                            //error message
        std::cout << "(apparently this location does not exist in Middle Earth)" << std::endl;        //commentary
        std::cout << "maybe try some smaller numbers" << std::endl;                                   //output statement, try again, Ask for new coordinates

        locationX = getNumberInput("Enter an x coordinate: ");                                        // Get new x coordinate
        locationY = getNumberInput("Enter a y coordinate: ");                                         // Get new y coordinate
        }
    }
    // After valid input, determine the quadrant and print the map size
    determineQuadrant();  // Once a valid location is entered, call determineQuadrant to find out which quadrant the user is in

    return 0;  // End the program
}

