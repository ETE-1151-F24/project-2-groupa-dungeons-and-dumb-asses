/*ETE 1151 Lab Laboratory #2
Lab Objectives
This lab was designed to reinforce programming concepts. In this lab, you will practice:
• Using cout to output text and values.
• Using cin to input data from the user.
• Using if statements to make decisions based on the truth or falsity of a condition.
• Using the modulus operator (%) to determine the remainder of an integer division operation.
• Using real numbers and formatting outputs.
• Adapting a program to solve a similar problem.


Description of the Problem #1
Write a program that reads in two integers and determines and prints whether the first is a
multiple of the second. [Hint: Use the modulus operator.]
Sample Output
Enter two integers: 22 8
22 is not a multiple of 8*/

#include <iostream>
#include <limits>
using namespace std;

int main(){
    int num1, num2;
    char choice;
    do {

        cout << "Enter your first number: ";        // Prompt for the first and second numbers
        cin >> num1;
        cout << "Enter your second number: ";
        cin >> num2;

        
        if (num2 == 0) {                            // Check if the second number is zero
            cout << "The second number cannot be zero. Please re-enter both numbers.\n" << endl;
            continue;                               // Go back to the beginning of the loop
        }

        // Ask if user wants to check for multiples
        cout << "Check if the first number is a multiple of the second? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            if (num1 % num2 != 0) {
                cout << num1 << " is not a multiple of " << num2 << endl;
            } else {
                cout << num1 << " is a multiple of " << num2 << endl;
            }
        }

    } while (choice != 'n' && choice != 'N');

    // Hold the console until Enter is pressed
    cout << "Press Enter to exit." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    cin.get(); // Wait for Enter

    return 0;
}








/*Description of the Problem #2
Write a program, which converts Celsius temperature to Fahrenheit. The user is supposed to
input Celsius temperature as a real value and your program should convert it to Fahrenheit as a
real number. Use the equation: F = 9.0/5.0 * C + 32.0 for conversion.
Sample Output<
Enter temperature in Celsius: 30.5
The temperature in Fahrenheit is 86.9
Post lab
A brief report is required due next week, containing source code, results, and about ½ page
summary (single spaced) explaining what you learned in this lab.*/
