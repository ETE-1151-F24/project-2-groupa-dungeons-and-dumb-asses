#include <iostream>                                     // Include the iostream library for input/output
#include <algorithm>                                    // Include the algorithm library for sorting
using namespace std;                                    // Use the standard namespace to avoid prefixing 'std::'

//-----------------------------------DECLARING VARIABLES----------------------------------------

void printArray(int grades[], int SIZE) {               // Function to print the array in the entered order
    cout << "\n----Grades in entered order----\n";      // Output message with a separator
    for (int i = 0; i < SIZE; ++i) {                    // Loop through array
        cout << grades[i] << " ";                       // Print each grade
    }
    cout << endl;                                       // New line at the end
}

void printArrayReverse(int grades[], int SIZE) {        // Function to print the array in reverse order
    cout << "\n----Grades in reverse order----\n";      // Output message with a separator
    for (int i = SIZE - 1; i >= 0; --i) {               // Loop from last to first element
        cout << grades[i] << " ";                       // Print each grade in reverse order
    }
    cout << endl;                                       // New line at the end
}

double calculateAverage(int grades[], int SIZE) {       // Function to calculate and return the average of the grades
    int sum = 0;                                        // Initialize sum
    for (int i = 0; i < SIZE; ++i) {                    // Loop through array
        sum += grades[i];                               // Add each grade to sum
    }
    return static_cast<double>(sum) / SIZE;             // Return the average as a double
}

int findMax(int grades[], int SIZE) {                   // Function to find the maximum grade using a 'for' loop
    int maxGrade = grades[0];                           // Initialize maxGrade to the first element in the array
    for (int i = 1; i < SIZE; ++i) {                    // Start loop from the second element (index 1)
        if (grades[i] > maxGrade) {                     // If current grade is greater than maxGrade
            maxGrade = grades[i];                       // Update maxGrade
        }
    }
    return maxGrade;                                    // Return the maximum grade found
}

int findMin(int grades[], int SIZE) {                   // Function to find the minimum grade using a 'for' loop
    int minGrade = grades[0];                           // Initialize minGrade to the first element in the array
    for (int i = 1; i < SIZE; ++i) {                    // Start loop from the second element (index 1)
        if (grades[i] < minGrade) {                     // If current grade is less than minGrade
            minGrade = grades[i];                       // Update minGrade
        }
    }
    return minGrade;                                    // Return the minimum grade found
}

void sortArray(int grades[], int SIZE) {                // Function to sort the array in ascending order
    sort(grades, grades + SIZE);                        // Use sort from <algorithm>
    cout << "\n----Grades in ascending order----\n";    // Output message with a separator
    for (int i = 0; i < SIZE; ++i) {                    // Loop through sorted array
        cout << grades[i] << " ";                       // Print each sorted grade
    }
    cout << endl;                                       // New line at the end
}

//---------------------------------MAIN FUNCTION WITH MENU--------------------------------------

int main() {
    const int SIZE = 10;                                // Declare a constant for array size
    int grades[SIZE];                                   // Declare the array
    int choice;                                         // Variable to store the user's menu choice

    // Input grades from the user
    cout << "Enter 10 grades: " << endl;                // Prompt the user for input
    for (int i = 0; i < SIZE; ++i) {                    // Loop to input 10 grades
        cout << "Grade " << (i + 1) << ": ";            // Display the current grade number
        cin >> grades[i];                               // Read grade input
    }

    // Menu loop
    do {
        // Display menu options
        cout << "\nWhat would you like to do?\n";
        cout << "1: Print the array in the entered order\n";
        cout << "2: Print the array in reverse order\n";
        cout << "3: Calculate and print the average\n";
        cout << "4: Find the maximum grade\n";
        cout << "5: Find the minimum grade\n";
        cout << "6: Sort the array in ascending order\n";
        cout << "7: Exit the program\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;                                  // Get user's choice

        switch (choice) {                               // Switch statement to handle user choice
            case 1:                                     // Option 1: Print the array in entered order
                printArray(grades, SIZE);               // Call the printArray function
                break;
            case 2:                                     // Option 2: Print the array in reverse order
                printArrayReverse(grades, SIZE);        // Call the printArrayReverse function
                break;
            case 3:                                     // Option 3: Calculate and print the average
                cout << "\n----Average of grades----\n" << calculateAverage(grades, SIZE) << endl;
                break;
            case 4:                                     // Option 4: Find the maximum grade
                cout << "\n----Maximum grade----\n" << findMax(grades, SIZE) << endl;
                break;
            case 5:                                     // Option 5: Find the minimum grade
                cout << "\n----Minimum grade----\n" << findMin(grades, SIZE) << endl;
                break;
            case 6:                                     // Option 6: Sort the array in ascending order
                sortArray(grades, SIZE);                // Call the sortArray function
                break;
            case 7:                                     // Option 7: Exit the program
                cout << "Exiting the program.\n";       // Output exit message
                break;
            default:                                    // Handle invalid input
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);                              // Continue the loop until the user chooses to exit

    return 0;                                           // End of program
}

//---------------------------------KEY CONCEPT BREAKDOWN----------------------------------------
// 1. [Switch Statement] - The switch-case structure allows for handling multiple menu options.
// 2. [Looping Menu] - A do-while loop ensures the program keeps asking the user what they want to do until they choose to exit.
// 3. [Function Usage] - We've modularized the tasks (printing, calculating, etc.) into functions, making the code easier to manage and extend.
// 4. [For Loop for Max/Min] - Traditional for loop is used instead of max_element and min_element for clarity and learning purposes.
