#include "conversionStuff.h" // this includes a reference to the content of the file [conversionStuff.h]
#include<iostream>
#include<string>

using namespace std; //this makes it the std:: naming scheme so i dont have to type it over and over

void charToBinary(char c); //initializes the char to binary function and references variable [c]
void numToBinary(int n);  //initializes the number to binary function and references variable [n]
void floaterToBinary(float f);  //initializes the floater to binary function and references variable [f]


int main() {
    //this section of code might be best suited as an intro function
    string inputToConvert; // this is intitializing a string to store an input in a variable named [inputToConvert]
    cout << "Input something to convert to binary" << endl; // this the output prompt message at the beginning of the program
    cin >> inputToConvert;


//this is where i am checking to see what kind of input it is that i am working with



//if thing is character then convert char to binary
            //this code should call the function from functions.h


//if thing is integer then convert int to binary
            //this code should call the function from functions.h


// if thing is float, then convert float to binary
            //this code should call the function from functions.h

//some code should go here to return the value of the operation




    return 0;                       
}