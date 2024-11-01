#include <iostream>                                       // Include input/output stream
#include <string>                                         // Include string library to handle string inputs
using namespace std;                                      // Use the standard namespace

bool isEven(int number) {                                 // Declare function isEven with int argument
    return (number % 2 == 0);                             // Return true if the number is divisible by 2 (even)
}


int main() {                                              // Start of the main function
    string input;                                         // Declare string variable for user input
    int num;                                              // Declare integer variable to store the converted input
    
    cout << "Enter an integer (or 'q' to quit): ";        // Output prompt to ask for integer or 'q' to quit
    while (cin >> input && input != "q" && input !="Q") {                // Loop until the user inputs 'q'
        try {                                             // Try block to handle conversion from string to int
            num = stoi(input);                            // Convert string input to an integer
            if (isEven(num)) {                            // Call isEven function and check if num is even
                cout << num << " is an even integer." << endl; // Output message for even integer
            } else {                                      // Else case for odd number
                cout << num << " is an odd integer." << endl; // Output message for odd integer
            }
        } catch (invalid_argument&) {                     // Catch invalid input if it's not a valid integer
            cout << "Invalid input. Please enter a valid integer or 'q' to quit." << endl; // Output error message
        }
        cout << "Enter another integer (or 'q' to quit): "; // Prompt for the next input
    }
        cout << "Goodbye!" << endl;                           // Output message before program ends

    cout << "Press Enter to exit...";                     // Prompt to press Enter to exit
    cin.ignore();                                         // Clear the input buffer
    cin.get();                                            // Wait for the user to press Enter

    return 0;                                             // End of the main function, return 0
}