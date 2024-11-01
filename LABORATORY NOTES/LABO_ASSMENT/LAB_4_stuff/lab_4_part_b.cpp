#include <iostream>
#include <string>
#include <limits>  // For std::numeric_limits

int main() {
    // Number of employees (size of the array)
    int numEmployees;

    // Ask user how many employees they want to input data for
    std::cout << "Enter the number of employees: ";
    std::cin >> numEmployees;

    // Declare arrays to store employee data, size based on user input
    std::string employeeNames[numEmployees];
    int hoursWorked[numEmployees];
    double hourlyRates[numEmployees];

    // Loop to input employee data
    for (int i = 0; i < numEmployees; i++) {
        std::cout << "Enter the name of employee #" << (i + 1) << ": ";
        std::cin.ignore();  // Clear the input buffer before taking string input
        std::getline(std::cin, employeeNames[i]);  // Get the employee's name

        // Error handling for hours worked input
        while (true) {
            std::cout << "Enter hours worked by " << employeeNames[i] << ": ";
            std::cin >> hoursWorked[i];

            // Check if the input is valid (positive integer)
            if (std::cin.fail() || hoursWorked[i] < 0) {
                std::cout << "Invalid input. Please enter a valid number of hours (0 or more)." << std::endl;
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            } else {
                break;  // Input is valid, break out of the loop
            }
        }

        // Error handling for hourly rate input
        while (true) {
            std::cout << "Enter hourly rate for " << employeeNames[i] << ": ";
            std::cin >> hourlyRates[i];

            // Check if the input is valid (positive double)
            if (std::cin.fail() || hourlyRates[i] <= 0) {
                std::cout << "Invalid input. Please enter a valid hourly rate (greater than 0)." << std::endl;
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            } else {
                break;  // Input is valid, break out of the loop
            }
        }

        std::cout << "-----------------------------" << std::endl;  // Divider between inputs
    }

    // Heading for the payout section
    std::cout << std::endl << "+++++++++++++++++++++++++++" << std::endl;
    std::cout << "HERE ARE THE TOTAL PAYOUTS" << std::endl;
    std::cout << "+++++++++++++++++++++++++++" << std::endl << std::endl;

    // Iterate through the array of employees and print their details
    for (int i = 0; i < numEmployees; i++) {
        double grossPay;

        // Calculate gross pay
        if (hoursWorked[i] <= 40) {
            grossPay = hoursWorked[i] * hourlyRates[i];  // Regular pay
        } else {
            grossPay = (40 * hourlyRates[i]) + ((hoursWorked[i] - 40) * 1.5 * hourlyRates[i]);  // Overtime pay
        }

        // Output the name, hours worked, hourly rate, and gross pay for each employee
        std::cout << "Employee Name: " << employeeNames[i] << std::endl;
        std::cout << "Hours Worked: " << hoursWorked[i] << std::endl;
        std::cout << "Hourly Rate: $" << hourlyRates[i] << std::endl;
        std::cout << "Gross Pay: $" << grossPay << std::endl;
        std::cout << "-----------------------------" << std::endl;  // Divider between employees
    }

    // Wait for the user to press Enter to prevent the console from closing immediately
    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    std::cin.get();  // Wait for Enter press to exit the program

    return 0;
}
