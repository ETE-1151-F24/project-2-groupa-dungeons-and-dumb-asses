#include <iostream>
#include <cmath>  // For sqrt()
#include <limits> // For numeric_limits

int main() {
    double a, b, c, discriminant, realPart, imagPart, root1, root2;
    char choice = 'y';  // Initialize choice to 'y' to enter the loop
    
    while (choice == 'y' || choice == 'Y') {
        // Input coefficient a
        std::cout << "Enter coefficient [a] (non-zero): ";
        while (!(std::cin >> a) || a == 0) {
            std::cout << "Invalid input. Coefficient 'a' must be a non-zero real number. Try again: ";
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        }
        
        // Input coefficient b
        std::cout << "Enter coefficient [b]: ";
        while (!(std::cin >> b)) {
            std::cout << "Invalid input. Coefficient 'b' must be a real number. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        // Input coefficient c
        std::cout << "Enter coefficient [c]: ";
        while (!(std::cin >> c)) {
            std::cout << "Invalid input. Coefficient 'c' must be a real number. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        // Calculate the discriminant
        discriminant = b * b - 4 * a * c;
        
        // Nested if-else statements to handle different cases
        if (discriminant > 0) {
            // Two real and different roots
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << std::endl << "Roots are " << root1 << " and " << root2 << std::endl;
        } 
        else if (discriminant == 0) {
            // Two real and equal roots
            root1 = -b / (2 * a);
            std::cout << std::endl << "Roots are equal: " << root1 << std::endl;
        } 
        else {
            // Complex conjugate roots
            realPart = -b / (2 * a);
            imagPart = sqrt(-discriminant) / (2 * a);
            std::cout << std::endl << "Complex roots are " << realPart << " + j" << imagPart
                      << " and " << realPart << " - j" << imagPart << std::endl;
        }
        
        // Ask the user if they want to continue
        std::cout << std::endl 
    << "Do you want to solve another equation? (y/n): "<< std::endl << std::endl;
        std::cin >> choice;
    }
    
    return 0;
}


