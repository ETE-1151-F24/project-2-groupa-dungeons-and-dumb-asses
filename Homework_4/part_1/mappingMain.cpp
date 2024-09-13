#include <iostream>
#include <ctime>            // For time() to seed random number generator
#include "mapStuff.h"       // Include the header file with your function declarations and global variables

using namespace std;

int main() {
    srand(time(0));                                                                         //Seed random number generator to 
                                                                                            //ensure random map size each time program runs   
     
    
    generateMap();                                                                          //Generate random map size, but doesnt print yet

//-------------------------- USER NAME ENTRY CODE--------------------
    cout << "Please enter your name." << endl;                                              // initial prompt

    cin >> userName;                                                                        // Get user name and store in global variable [userName]
    
    cout << "Thank you " << userName << " for participating in this adventure!" << endl;    //THANKYOU message

 
//-------------------------- USER lOCATION ENTRY CODE--------------------
    cout << "Where would you like to be on the map?" << endl;

                                                                                            //Get user X, Y coordinates using input validation
    locationX = getNumberInput("Enter an x coordinate: ");                                  //Call getNumberInput with prompt for x coordinate
    locationY = getNumberInput("Enter a y coordinate: ");                                   //Call getNumberInput with prompt for y coordinate
  
                                                                
    bool validLocation = false;                                                             // Variable tracks if location valid or not   
    
    while (!validLocation) {                                                                //Loop until valid location is entered                                                             
                  
        validLocation = isValidLocation();                                                  //Check if entered coordinates within the map bounds                                            
                                                                                            //Call isValidLocation to check both coordinates valid

        if (!validLocation) {                                                               //If location invalid, show error message
                                                                          

        cout << "Filthy hobbitses, trixie and false!!!" << endl;                            //error message
        cout << "(apparently this location does not exist in Middle Earth)" << endl;        //commentary
        cout << "maybe try some smaller numbers" << endl;                                   //output statement, try again, Ask for new coordinates

        locationX = getNumberInput("Enter an x coordinate: ");  // Get new x coordinate
        locationY = getNumberInput("Enter a y coordinate: ");   // Get new y coordinate
        }
    }



 
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








  return 0;
}

