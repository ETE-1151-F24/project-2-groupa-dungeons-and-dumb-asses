/*Program 2: Arrange an array in descending order using a function. Follow these steps:
1. Declare an array of ten elements
2. Print the array
3. Pass the array to a function
4. Have the function arrange the array in descending order
5. Print the rearranged array inside the function
6. Print the array in the main program
You will notice that that the main array is also rearranged.*/


#include <iostream>
using namespace std;

void sortDescending(int array_of_mine[], int size_of_my_array) {              // Function to sort array in descending order
    for (int i = 0; i < size_of_my_array - 1; ++i) {                          // Outer loop to control passes
        for (int j = 0; j < size_of_my_array - i - 1; ++j) {                  // Inner loop to compare adjacent elements
            if (array_of_mine[j] < array_of_mine[j + 1]) {                    // If current element is less than the next
                
                int temp = array_of_mine[j];                     // a temporary integer will hold the j element value
                
                array_of_mine[j] = array_of_mine[j + 1];        //the j element is now set equal to the j+1 element value
                
                array_of_mine[j + 1] = temp;                    //the j+1 element is now set to the temp value
            }
        }
    }

    cout << "\nArray inside function (descending order): ";
    for (int i = 0; i < size_of_my_array; ++i) {                   // Print the sorted array within the function
        cout << array_of_mine[i] << " ";
    }
    cout << endl;
}

int main() {
char choice;

        // Ask if user would like to re arrange some stuff
    cout << "Would you like to rearrange an array? (y/n): ";
    cin >> choice;
if (choice=='y'||choice=='Y'){
    const int size_of_my_array = 10;
    int array_of_mine[size_of_my_array] = {12, 7, 19, 3, 15, 8, 10, 5, 13, 6}; // Declare and initialize array with 10 elements

    // Print the array before sorting
    cout << "Original array: ";
    for (int i = 0; i < size_of_my_array; ++i) {
        cout << array_of_mine[i] << " ";
    }
    cout << endl;

    // Sort array in descending order
    sortDescending(array_of_mine, size_of_my_array);                          // Pass array to function for sorting

    // Print the array in main after sorting
    cout << "Array in main (after sorting): ";
    for (int i = 0; i < size_of_my_array; ++i) {
        cout << array_of_mine[i] << " ";
    }

      } else if (choice == 'n' || choice == 'N'){
        cout << "No rearranging today!" << endl;
    }

    // Hold console until user presses Enter
    cout << "\nPress Enter to exit...";
    cin.ignore();                                       // Ignore leftover newline from previous input
    cin.get();                                          // Wait for user to press Enter

    cout << endl;

    return 0;
}
