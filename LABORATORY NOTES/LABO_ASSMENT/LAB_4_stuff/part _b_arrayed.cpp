#include <iostream>
#include <string>

int main() {
    // Predefined array of employee names
    std::string employeeNames[] = {"John", "Alice", "Bob", "Eve"};
    
    // Predefined array of hours worked by each employee
    int hoursWorked[] = {38, 45, 40, 50};
    
    // Predefined array of hourly rates for each employee
    double hourlyRates[] = {15.00, 20.00, 12.50, 25.00};
    
    // Number of employees (size of the array)
    int numEmployees = 4;

    // Iterate through the array of employees using a for loop
    for (int i = 0; i < numEmployees; i++) {
        double grossPay;
        
        // Calculate gross pay
        if (hoursWorked[i] <= 40) {
            // If hours worked is less than or equal to 40, use regular rate
            grossPay = hoursWorked[i] * hourlyRates[i];
        } else {
            // If hours worked is more than 40, apply overtime pay
            grossPay = (40 * hourlyRates[i]) + ((hoursWorked[i] - 40) * 1.5 * hourlyRates[i]);
        }
        
        // Output the name, hours worked, hourly rate, and calculated gross pay for each employee
        std::cout << "Employee Name: " << employeeNames[i] << std::endl;
        std::cout << "Hours Worked: " << hoursWorked[i] << std::endl;
        std::cout << "Hourly Rate: $" << hourlyRates[i] << std::endl;
        std::cout << "Gross Pay: $" << grossPay << std::endl;
        std::cout << "-----------------------------" << std::endl;  // Divider between employees
    }

    // Wait for the user to press Enter to prevent the console from closing immediately
    std::cout << "Press Enter to exit...";
    std::cin.get();  // Wait for Enter press to exit the program
    std::cin.get();  // Ensures the window doesn't close immediately

    return 0;
}

