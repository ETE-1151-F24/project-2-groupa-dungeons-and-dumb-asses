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
22 is not a multiple of 8
Description of the Problem #2
Write a program, which converts Celsius temperature to Fahrenheit. The user is supposed to
input Celsius temperature as a real value and your program should convert it to Fahrenheit as a
real number. Use the equation: F = 9.0/5.0 * C + 32.0 for conversion.
Sample Output<
Enter temperature in Celsius: 30.5
The temperature in Fahrenheit is 86.9
Post lab
A brief report is required due next week, containing source code, results, and about ½ page
summary (single spaced) explaining what you learned in this lab.*/


#include<iostream>
#include<limits>
using namespace std;                    //this makes it the [std::] naming scheme so i dont have to type it over and over

int main() {
cout << "We are going to see if NUMBER ONE is a multiple of NUMBER TWO." << endl;         //message explaing the program
int number1;                                                                            //initializes the integer[int] for variable[number1]
int number2;                                                                            //initializes the integer[int] for variable[number2]
cout << "Enter number one" << endl;                                                     //output statement prompt for [number1] 
cin >> number1;                                                                         //stores user entry [cin] in variable [number1]
cout << "Enter number two" << endl;                                                     //output statement prompt for [number2]
cin >> number2;                                                                         //stores user entry [cin] in variable [number2]


if (number1 % number2 != 0){                                                            //if the modulus[%] remainder result is not 0 [!= 0], 
        cout << number1 << " is not a multiple of " << number1 << endl;                   //then state NOT MULTIPLE
} else {                                                                                //OTHERWISE.....
        cout << number1 << " is a multiple of " << number2 << endl;                        //state that IS MULTIPLE
        }

    cout << "Press Enter to exit..."; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears the input buffer to ignore leftover characters
    cin.get(); // Waits for the Enter key press to exit the program
        return 0;                   //returns the value of 0 if the program completes correctly                   

}


