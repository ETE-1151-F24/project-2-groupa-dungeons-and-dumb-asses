#include <iostream>
#include <cmath> // for sqrt()
using namespace std;

// Function to find and print roots of a quadratic equation
void findRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The roots are real and distinct: " << root1 << " and " << root2 << endl;
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "The roots are real and equal: " << root << endl;
    }
    else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "The roots are complex: " << realPart << " + " << imaginaryPart << "i and "
             << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// Function to calculate factorial for exponential calculation
double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to approximate e^x
double calculateExponential(int numTerms, double x) {
    double result = 1.0; // Start with 1.0 (the first term in the series)
    
    for (int i = 1; i < numTerms; ++i) {
        result += (pow(x, i) / factorial(i));
    }
    
    return result;
}

int main() {
    int choice;                                              // Variable to store the user's menu choice

    while (true) {                                           // Sentinel loop to keep the program running until the user exits
        cout << "Hello! What would you like to do today?"     // Prompt the user with a greeting message
             << endl;                                        
        cout << "1. Solve a quadratic equation" << endl;     // Menu option 1: Solve a quadratic equation
        cout << "2. Approximate e^x" << endl;                // Menu option 2: Approximate e^x
        cout << "3. Exit" << endl;                           // Menu option 3: Exit the program
        cout << "Enter your choice: ";                       // Prompt the user for their menu choice
        cin >> choice;                                       // Read the user's choice from input

        if (choice == 1) {                                   // If user chooses option 1
            // Quadratic equation solver
            double a, b, c;                                  // Variables to store coefficients of the quadratic equation
            cout << "Enter coefficients a, b, and c: "<<endl;      // Prompt user to enter the coefficients
            cin >> a >> b >> c;                              // Read the coefficients from input
            findRoots(a, b, c);                              // Call the findRoots function to solve the equation
            
            cout << endl;                                    // Add a blank line after the result to create spacing
        }
        else if (choice == 2) {                              // If user chooses option 2
            // Exponential approximation
            int numTerms;                                    // Variable to store the number of terms for the approximation
            double x;                                        // Variable to store the value of x
            cout << "Enter number of terms: ";               // Prompt user to enter the number of terms
            cin >> numTerms;                                 // Read the number of terms from input
            cout << "Enter value of x: ";                    // Prompt user to enter the value of x
            cin >> x;                                        // Read the value of x from input
            double result = calculateExponential(numTerms, x);// Call the calculateExponential function
            cout << "The approximation of e^" << x           // Output the result of the approximation
                 << " is: " << result << endl;               // Output the result of e^x

            cout << endl;                                    // Add a blank line after the result to create spacing
        }
        else if (choice == 3) {                              // If user chooses option 3
            // Exit the program
            cout << "Goodbye!" << endl;                      // Output a goodbye message
            break;                                           // Exit the loop, ending the program
        }
        else {                                               // If the user enters an invalid choice
            cout << "Invalid choice, please try again."      // Output an error message
                 << endl;                                    // Move to a new line
        }

        cout << "Would you like to perform another operation?" << endl;  // Prompt for another operation
        cout << endl;                                        // Add a blank line for additional spacing between iterations
    }

    return 0;                                                // Return 0 to indicate successful program termination
}