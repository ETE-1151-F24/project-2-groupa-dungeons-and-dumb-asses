//DONT EVER TY TO COMPILE THIS...IT IS JUST FOR VISUAL REFERENCE
// cout << "" << endl;       this is the syntax for an output statement with text

// ANYTIME DEALING WITH PI YOU SHOULD CHOOSE TO DECLARE AS A DOUBLE

//-------------------------------------THIS IS YOUR STARTING JUMP OFF POINT FOR CODING------------------------------
#include<iostream>
using namespace std;                //this makes it the [std::] naming scheme so i dont have to type it over and over

int main() {

        return 0;                   //returns the value of 0 if the program completes correctly                   
}

//--------------------------------putting stuff in and out via prompt------------------------------------------------------------------------------
#include<iostream>
using namespace std;                //this makes it the [std::] naming scheme so i dont have to type it over and over
int x;                              // initializes a variable called [x] for later use

int main() {
    cout << "enter two values";  	//this is a prompt statement and goes before cin
	cin>>x>>y;		                //tells the computer to hold for input for [x] and [y] put a space between 
                                    //each and can only have one stream operator at a time

                                    //To make a comment you use //  or for a multiline comment you use 

z = x + y;                          //all operations are stored on the right side of the variable and [=]
                                    // (make sure to add spaces between things to increase legibility)
cout << ” Result is = ” << z;       //references the variable [z] address    ["Result is"] statement is optional


                // !!!!!!! pay close attention to the quote marks...[”] Result is = [”] curly quote create and unrecognized error token
                // !!!!!!! the correct quotes to use are ["] Result is = ["]  **** notice they are straight quotes

                return 0;                   //returns the value of 0 if the program completes correctly                   
}
//---------------------------------------------IF STATEMENTS-------------------------------------------------
if (/*boolean/comparison*/){
    /*perform this command*/;
} else{
    /*perform this command instead*/
}

//--------------------------------------------SETTING FIXED PRECISION FLOATS-----------------------------
int main() {
    float num = 3.14159265;

    // Set the precision to 3 decimal places
    cout << fixed << setprecision(3);            //output with [setprecision] to [(2)] [fixed] decimal places
    cout << "Number with 3 decimal places: " << num << endl;

    // Set the precision to 5 decimal places
    cout << fixed << setprecision(5);
    cout << "Number with 5 decimal places: " << num << endl;
//------------------------------------------------