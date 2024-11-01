/* ETE_1151L Laboratory # 9
Objectives: This lab is designed to reinforce programming concepts using arrays and
passing arrays to functions. The students are also supposed to use random
function to generate random numbers.
Program 1: Write a program that simulates the roll of two dice. The program should
call rand to roll first dice, and should call rand again to roll the second
dice. The sum of two values should then be calculated. The sum should be
between 2 and 12. Your program should roll the two dice 100 times. Use
one dimensional array to tally the numbers of times each sum appears.
Print the result in tabular format as shown below:
SUM TOTAL
2 7
3 9
4 10
. .
Note: Use the following statement before you call rand function;
srand( time( NULL ) ); // #include <time.h>, #include<stdlib.h>

*/



#include <iostream>
#include <cstdlib>                                      // Include cstdlib for rand and srand
#include <ctime>                                        // Include ctime for time function
using namespace std;

int main() {
    srand(time(NULL));                                  // Seed random number generator

    const int ROLLS = 100;                              // Number of times to roll the dice
    const int MIN_SUM = 2;                              // Minimum possible sum of two dice
    const int MAX_SUM = 12;                             // Maximum possible sum of two dice
    int tally[MAX_SUM + 1] = {0};                       // Array to count each sum from 2 to 12, extra space for indexing ease
    char choice = 'y';                                        // Variable for storing user choice

    // Ask if user would like to roll the dice
    cout << "Would you like to roll some dice? (y/n): ";
    cin >> choice;

    // If user chooses 'y' or 'Y', proceed with rolling the dice
    if (choice == 'y' || choice == 'Y') {
        // Roll dice 100 times
        for (int i = 0; i < ROLLS; ++i) {
            int dice1 = rand() % 6 + 1;                 // Roll first die (1-6)
            int dice2 = rand() % 6 + 1;                 // Roll second die (1-6)
            int sum = dice1 + dice2;                    // Calculate sum of both dice
              // Use switch-case to tally each possible sum
            switch (sum) {
                case 2: tally[2]++; break;
                case 3: tally[3]++; break;
                case 4: tally[4]++; break;
                case 5: tally[5]++; break;                  // or you could us tally[sum]++;
                case 6: tally[6]++; break;
                case 7: tally[7]++; break;
                case 8: tally[8]++; break;
                case 9: tally[9]++; break;
                case 10: tally[10]++; break;
                case 11: tally[11]++; break;
                case 12: tally[12]++; break;
                default: break;  // No action needed for invalid cases
            }    
        }

        // Print results in tabular format
        cout << "DICE SUM\tTOTAL\n";
        for (int i = MIN_SUM; i <= MAX_SUM; ++i) {      // Loop through possible sums from MIN_SUM = 2 to MAX_SUM = 12
            cout << i << "\t\t" << tally[i] << endl;      // Print sum and its tally
        }
    } else {
        cout << "No dice rolling today!" << endl;
    }

    // Hold console until user presses Enter
    cout << "\nPress Enter to exit...";
    cin.ignore();                                       // Ignore leftover newline from previous input
    cin.get();                                          // Wait for user to press Enter

    return 0;
}
