#ifndef MAP_STUFF_H // Include guard to prevent multiple definitions
#define MAP_STUFF_H

#include <string> // Required for string data type

// Global variables for map size and user coordinates
 int mapSizeX, mapSizeY; // Declared as external so they can be used in other files
 double locationX, locationY;
 std::string userName, horizontal, vertical, quad;


// Function declarations for map-related operations
void generateMap();                                         // Function to generate random map size
bool isValidLocation(double locationX, double locationY);   // Function to check if the entered location is within the map boundaries
void determineQuadrant(double x, double y);                 // Function to determine which quadrant the user is located in
void quadImaging();                                         // function for displaying quadrant location
double getNumberInput(std::string prompt);                  // Function to get valid numeric input from the user
void printStatement(std::string quad);                      // Function to print quadrant information

#endif // End of include guard