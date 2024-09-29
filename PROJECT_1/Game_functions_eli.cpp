#include "GameHeaderEli.h"                           // Include header file for necessary declarations
#include <string>                                    // Enables use of the standard string class for handling text
#include <chrono>                                    // Provides facilities for time-based operations
#include <iostream>                                  // For std::cin, std::cout
#include <thread>                                    // Enables multithreading, allowing tasks to run concurrently
#include <iomanip>                                   // Required for using setw, left, and right manipulators

//------------------------------------------- FUNCTION FOR STROBING TITLE --------------------------------------------
void printStrobingText(const std::string& text, int duration) {
    const std::string goldColor = "\033[38;5;220m";                                           // Custom gold color
    const std::string resetColor = "\033[0m";                                                 // Reset to default
    const std::string boldEffect = "\033[1m";                                                 // Bold text effect

    auto startTime = std::chrono::steady_clock::now();                                        // Mark current time

    while (true) {
        auto currentTime = std::chrono::steady_clock::now();                                  // Get current time for elapsed calculation
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count(); // Calculate elapsed time

        if (elapsedTime >= duration) {                                                        // Break the loop when duration ends
            break;
        }

        std::cout << "\r";                                                                    // Move cursor to the start of the line

        for (size_t i = 0; i < text.length(); ++i) {
            if (i % 2 == elapsedTime % 2) {                                                   // Use elapsedTime for alternating effect
                std::cout << goldColor << boldEffect << text[i];                              // Gold & bold effect for alternating characters
            } else {
                std::cout << resetColor << boldEffect << text[i];                             // Reset color w/bold effect for other characters
            }
        }

        std::cout.flush();                                                                    // Flush output buffer to display text immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(100));                          // Delay for visible strobing effect
    }

    std::cout << resetColor << "\n";                                                          // Reset terminal color and add a newline
}
//---------------------------------------------------------------------------------------------------------------

//------------------------------- FUNCTION FOR RUNNING MAIN GAME LOOP -------------------------------------------
void runGameLoop(Player& player) {
    std::string command;

    while (true) {
        std::cout << "\nEnter a command (inventory / stats / quit): ";                        // Prompt user for command
        std::getline(std::cin, command);                                                      // Get user's command input

        // Trim whitespace and convert to lowercase
        command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));                           // Remove leading whitespace
        command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1);                           // Remove trailing whitespace
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);           // Convert command to lowercase

        if (command == "inventory") {                                                         // Inventory command
            while (true) {
                // Display inventory items
                std::cout << "\n--- Your Inventory ---\n";                                    // Print inventory header

                const int nameWidth = 35; // Set a fixed width for item names

                for (size_t i = 0; i < player.inventory.size(); ++i) {
                    const Item& item = player.inventory[i];                                   // Get item reference
                    std::string status = player.isEquipped(item) ? "(equipped)" : "In your Sakky"; // Determine item status

                    // Use setw, left, and right to align the output correctly
                    std::cout << std::setw(3) << (i + 1) << ". "                              // Index of the item, right aligned
                              << std::left << std::setw(nameWidth) << item.name               // Left-align item name with fixed width
                              << std::right << status << "\n";                                // Right-align item status
                }

                std::string response;
                std::cout << "\nWould you like to focus on an item? Enter the number or type 'no': "; // Ask if user wants to focus on an item
                std::getline(std::cin, response);                                             // Get user's response

                if (response == "no") {                                                       // If user doesn't want to focus on an item
                    break;                                                                    // Exit inventory loop
                }

                int itemChoice;
                try {
                    itemChoice = std::stoi(response) - 1;                                     // Convert response to an index
                } catch (std::exception& e) {
                    std::cout << "Invalid input. Please enter a valid number.\n";             // Handle invalid input
                    continue;                                                                 // Restart loop
                }

                if (itemChoice < 0 || itemChoice >= static_cast<int>(player.inventory.size())) {
                    std::cout << "Invalid item number. Please try again.\n";                  // Handle out of bounds item choice
                    continue;                                                                 // Restart loop
                }

                Item& selectedItem = player.inventory[itemChoice];                            // Get selected item reference

                std::string itemResponse;
                while (true) {
                    std::cout << "\nWhat would you like to do with '" << selectedItem.name << "'?\n"; // Prompt actions for the selected item
                    std::cout << "1. Read Description\n";                                  
                    if (player.isEquipped(selectedItem)) {                                    // If item is equipped
                        std::cout << "2. Unequip Item\n";                                     // Provide unequip option
                    } else {                                                                  // If item is not equipped
                        std::cout << "2. Equip Item\n";                                       // Provide equip option
                    }
                    std::cout << "3. Back to Inventory\n";                                    // Provide option to go back to inventory
                    std::getline(std::cin, itemResponse);                                     // Get user's choice

                    if (itemResponse == "1") {                                                // If user chooses to read description
                        displayItemDetails(selectedItem);                                     // Display item details
                    } else if (itemResponse == "2") {                                         // If user chooses to equip/unequip item
                        if (player.isEquipped(selectedItem)) {                                // If item is equipped
                            player.unequipItem(&selectedItem);                                // Unequip item
                        } else {                                                              // If item is not equipped
                            player.equipItem(&selectedItem);                                  // Equip item
                        }
                    } else if (itemResponse == "3") {                                         // If user chooses to go back to inventory
                        break;                                                                // Break inner loop to redisplay inventory
                    } else {
                        std::cout << "Invalid input. Please enter 1, 2, or 3.\n";             // Handle invalid input
                    }
                }
            }
        } else if (command == "stats") {                                                      // Stats command
            player.showStats();                                                               // Display player's stats
        } else if (command == "quit") {                                                       // Quit command
            std::cout << "Goodbye, " << player.name << "!\n";                                 // Display goodbye message
            std::cout << "Press Enter to exit...";                                            // Prompt user to press Enter
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');               // Wait for user input (Enter)
            break;                                                                            // Exit the game loop                                                                       
        } else {
            std::cout << "Unknown command. Try again.\n";                                     // Handle unknown command
        }
    }
}
