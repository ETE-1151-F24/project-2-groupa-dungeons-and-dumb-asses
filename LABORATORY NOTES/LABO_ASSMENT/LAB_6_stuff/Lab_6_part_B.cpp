
#include <iostream>                                                     // Include input/output stream
#include <string>                                                       // Include string library to handle string inputs
using namespace std;                                                    // Use the standard namespace

string reverseDigits(string number) {                                   // Declare function reverseDigits with string argument
    string reversed = "";                                               // Declare and initialize reversed as an empty string
    for (int i = number.length() - 1; i >= 0; --i) {                    // Loop from the last character to the first
        reversed += number[i];                                          // Append each character to the reversed string
    }
    return reversed;                                                    // Return the reversed string
}



int main() {                                                            // Start of the main function
    string input;                                                       // Declare string variable for user input

    cout << "Enter a number between 1 and 9999 (or 'q' to quit): ";     // Output prompt to ask for number or 'q'
    while (cin >> input && input != "q" && input != "Q") {              // Loop until the user inputs 'q'
        try {                                                           // Try block to handle string to int conversion
            int num = stoi(input);                                      // Convert string input to integer to validate range
            if (num > 0 && num <= 9999) {                               // Check if the number is within the valid range
                string reversed = reverseDigits(input);                 // Get the reversed string
                try {                                                   // Nested try block to check if reversed string is a valid integer
                    int reversedNum = stoi(reversed);                   // Attempt to convert the reversed string to an integer
                    cout << "The number with its digits reversed is: " 
                         << reversedNum << endl;                        // Output the reversed integer
                } catch (invalid_argument&) {                           // Catch any invalid reversed number
                    cout << "Error: The reversed number is not a valid integer." << endl;  // Output error if reversed string can't be converted
                }
            } else {                                                    // Else case for invalid range input
                cout << "Invalid input. Please enter a number between 1 and 9999." << endl; // Error message
            }
        } catch (invalid_argument&) {                                   // Catch invalid input if it's not a valid integer
            cout << "Invalid input. Please enter a valid number or 'q' to quit." << endl;   // Output error message
        }
        
        cout << "Would you like to reverse another number? (Enter number or 'q' to quit): "; // Ask to continue or quit
    }
    
    cout << "Goodbye!" << endl;                                         // Output message before program ends

    cout << "Press Enter to exit...";                                   // Prompt to press Enter to exit
    cin.ignore();                                                       // Clear the input buffer
    cin.get();                                                          // Wait for the user to press Enter

    return 0;                                                           // End of the main function, return 0
}





