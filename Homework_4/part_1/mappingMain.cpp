#include <iostream>
#include <ctime>            // For time() to seed random number generator
#include "mapStuff.h"       // Include the header file with your function declarations and global variables

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator to ensure random map size each time the program runs   
     
    
    generateMap(); // Generate a random map size, but doesnt print anything yet

//-------------------------- USER NAME ENTRY CODE--------------------
    cout << "Please enter your name." << endl;                                              // initial prompt

    cin >> userName;                                                                        // Get user name and store in global variable [userName]
    
    cout << "Thank you " << userName << " for participating in this adventure!" << endl;    //THANKYOU message

 
//-------------------------- USER lOCATION ENTRY CODE--------------------
    cout << "Where would you like to be on the map?" << endl;

 // Get the user's X and Y coordinates using input validation
    locationX = getNumberInput("Enter an x coordinate: ");                                  //Call getNumberInput with prompt for x coordinate
    locationY = getNumberInput("Enter a y coordinate: ");                                   //Call getNumberInput with prompt for y coordinate
  
  // Loop until a valid location is entered
    bool validLocation = false;                                                             // Variable tracks if location valid or not   
    while (!validLocation) {
                // Check if the entered coordinates are within the map's bounds
    validLocation = isValidLocation();  // Call isValidLocation to check if both coordinates are valid
            // If the location is invalid, show an error message
    if (!validLocation) {

        

 
 //std::cout << rand() % 100 << " "; // Output a random number between 0 and 99, followed by a space
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




  return 0;
}

