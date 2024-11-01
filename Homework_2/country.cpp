#include<iostream>
using namespace std; //this makes it the [std::] naming scheme so i dont have to type it over and over


/*Write a C++ program that asks which country the user lives in, lets the user type in the country and  and prints out a message
Example run :
    1. Program prints : Where do you live?
    2. User types : USA
    3. Program prints : I've heard great things about USA. I'd like to go sometime.*/
string x;    // initializes a [string] variable called [x] for later use

int main() {
                          

    cout << "Where do you live?" << endl;  	//this is a prompt statement and goes before cin
	getline(cin, x);	//[cin] tells the computer to hold for input for [x] and [getline] allows for capturing strings with spaces


                    // !!!!!!! pay close attention to the quote marks ELI...[”] Result is = [”] curly quotes create and UNRECOGNIZED TOKEN ERROR
                // !!!!!!! the correct quotes to use are ["] Result is = ["]  **** notice they are straight quotes


    cout << "Ive heard great things about "<< x << " I'd like to go sometime... and conquer it...MUAHAHAHAHAHA!";

return 0;
}