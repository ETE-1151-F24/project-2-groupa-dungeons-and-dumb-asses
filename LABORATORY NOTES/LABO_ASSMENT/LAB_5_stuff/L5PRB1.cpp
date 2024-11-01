#include <iostream>
#include <cmath>                         // Required for pow() and M_PI
#include <math.h>
#include <numbers>
#include <limits>
#include <string> // Enables use of the standard string class for handling text
#include <algorithm> // Required for using std::max

#define M_PI 3.14159265358979323846       // Define M_PI to 32 bit precision

int main() {
    double diameter, radius, volume;      // Declare variables for diameter, radius, and volume

    std::cout << "Enter the diameter of the sphere: ";    // Prompt for diameter
    std::cin >> diameter;                                 // Store the input value in diameter

    radius = diameter / 2;                                // Calculate the radius by dividing the diameter by 2

    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);         // Calculate the volume using the formula

    std::cout << "The volume of the sphere is: " << volume << std::endl;  // Output the result

    std::cout << "Press Enter to exit..."; // Prompt user to press Enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::cin.get();  // Wait for user to press Enter

    return 0;                                             // End the program
}
