//DONT EVER TY TO COMPILE THIS...IT IS JUST FOR VISUAL REFERENCE



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