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

#include<iostream>
#include<iomanip>
using namespace std;                                                                    //[std::] naming scheme to avoid typing it over and over

int main() {

float celsius;                                                                            //this is the initialization of [celsius] variable
float farenheit;                                                                          //this is the initialization of [farenheit] variable

cout << "We are going to convert Celsius temperature to Fahrenheit" << endl;            //message explaing the program
cout << "Enter a celsius temperature: ";                                                //output message prompt to enter a temperature
cin >> celsius;                                                                         //stores user input int variable[celsius]
farenheit = (celsius * (9.0/5.0)) + 32.0;                                               //calculation definition for [farenheit] variable 
    
    cout << fixed << setprecision(1);                                           //output with [setprecision] to [(2)] [fixed] decimal places
    cout << "The temperature in Fahrenheit is " << farenheit << endl;

        return 0;                                                                       //returns value of 0 if program completes correctly                   

}
