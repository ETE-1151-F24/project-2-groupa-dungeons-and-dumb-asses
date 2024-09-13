#include <iostream>
#include <ctime>            // For time() to seed random number generator
#include "mapStuff.h"       // Include the header file with your function declarations and global variables

using namespace std;

int main() {
 std::cout << rand() % 100 << " "; // Output a random number between 0 and 99, followed by a space
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


//THEN GO TO SPECIFIED [COORDINATE FUNCTION] FOR ENTERING THE VALUES I WILL NEED SOME FORM OF A [WHILE] LOOP


/*choice of output results*/
      //variable [outcome] =
                  //success; then display message "you have chosen wisely"
                  //failure; while the [outcome] is failure, 

                  //if a value entered for either of the numbers is too big, put a message that says, maybe try a smaller location with either x or y








  return 0;
}

