// Game_functions_eli.cpp
#include "GameHeaderEli.h"                           // Include header file for necessary declarations
#include <string>                                    // Enables use of the standard string class for handling text
#include <chrono>                                    // Provides facilities for time-based operations
#include <iostream>                                  // For std::cin, std::cout
#include <thread>                                    // Enables multithreading, allowing tasks to run concurrently

//---------------------------------------------- FUNCTION FOR STROBING TITLE --------------------------------------
void printStrobingText(const std::string& text, int duration) {
    const std::string goldColor = "\033[38;5;220m";                      // Custom gold color
    const std::string resetColor = "\033[0m";                            // Reset to default
    const std::string boldEffect = "\033[1m";                            // Bold text effect

    auto startTime = std::chrono::steady_clock::now();                   // Mark current time

    while (true) {
        auto currentTime = std::chrono::steady_clock::now();                 // Get current time for elapsed calculation
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count(); // Calculate elapsed time

        if (elapsedTime >= duration) {                                        // Break the loop when duration ends
            break;
        }

        std::cout << "\r";                                                    // Move cursor to the start of the line

        for (size_t i = 0; i < text.length(); ++i) {
            if (i % 2 == elapsedTime % 2) {                                   // Use elapsedTime for alternating effect
                std::cout << goldColor << boldEffect << text[i];              // Gold and bold effect for alternating characters
            } else {
                std::cout << resetColor << boldEffect << text[i];             // Reset color with bold effect for other characters
            }
        }

        std::cout.flush();                                                    // Flush output buffer to display text immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(100));          // Delay for visible strobing effect
    }

    std::cout << resetColor << "\n";                                          // Reset terminal color and add a newline
}
//---------------------------------------------------------------------------------------------------------------

//---------------------------------------------- FUNCTION FOR RUNNING MAIN GAME LOOP ----------------------------
void runGameLoop(Player& player) {
    std::string command;                                                                            // [command] variable to handle inputs

    while (true) {
        std::cout << "\nEnter a command (equip / unequip / inventory / stats / quit): ";            // Display available commands
        std::getline(std::cin, command);                                                            // Get command from the player

        // Trim leading and trailing whitespace
        command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));                                 // Trim leading whitespace
        command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1);                                 // Trim trailing whitespace

        // Convert the command to lowercase for case insensitivity
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "equip") {                                                                   // If player wants to equip an item
            int itemChoice;
            std::cout << "Enter the number of the item to equip from your inventory: ";             // Prompt for item number
            std::cin >> itemChoice;

            // Input validation for equip
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > static_cast<int>(player.inventory.size())) { // Validate input
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input
            }

            equipItem(player, itemChoice - 1);                                                      // Equip selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer to remove leftover newline character

        } else if (command == "unequip") {                                                          // If player wants to unequip an item
            int itemChoice;
            std::cout << "Enter the number of the item to unequip: ";                               // Prompt for item number
            std::cin >> itemChoice;

            // Input validation for unequip
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > static_cast<int>(player.equippedItems.size())) { // Validate input
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input
            }

            unequipItem(player, itemChoice - 1);                                                    // Unequip the selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer to remove leftover newline character

        } else if (command == "inventory") {                                                        // If player wants to view their inventory
            std::cout << "\n--- Your Inventory ---\n";

            // Display all items in inventory and equipped status
            for (size_t i = 0; i < player.inventory.size(); ++i) {
                const Item& item = player.inventory[i];
                std::string status = "In your Sakky";                                               // Default status as "in your Sakky"

                if (player.isEquipped(item)) {                                                      // Check if item is equipped
                    status = "Equipped";                                                            // Update status to "Equipped"
                }

                std::cout << (i + 1) << ". " << item.name << " - " << status << "\n";               // Display item name and status
            }

            std::string response;
            while (true) {
                std::cout << "\nWould you like to focus on an item? Enter the number or type 'no': ";  // Prompt for focusing on an item
                std::getline(std::cin, response);                                                   // Get the player's response

                if (response == "no") {                                                             // If player types "no"
                    break;                                                                          // Exit from the inventory focus loop
                }

                try {
                    int itemChoice = std::stoi(response) - 1;                                       // Convert response to item index
                    if (itemChoice < 0 || itemChoice >= static_cast<int>(player.inventory.size())) {// Validate the item choice
                        std::cout << "Invalid item number. Please try again.\n";                    // Error message for invalid choice
                        continue;                                                                   // Continue loop to retry
                    }

                    Item& selectedItem = player.inventory[itemChoice];                              // Reference to selected item
                    std::string itemResponse;

                    // Offer actions for the selected item
                    while (true) {
                        std::cout << "\nWhat would you like to do with '" << selectedItem.name << "'?\n";
                        std::cout << "1. Read Description\n";
                        if (player.isEquipped(selectedItem)) {                                      // If item is equipped
                            std::cout << "2. Unequip Item\n";                                       // Option to unequip item
                        } else {
                            std::cout << "2. Equip Item\n";                                         // Option to equip item
                        }
                        std::cout << "3. Back to Inventory\n";
                        std::getline(std::cin, itemResponse);                                       // Get player's response for item action

                        if (itemResponse == "1") {
                            displayItemDetails(selectedItem);                                       // Call function to display item details
                        } else if (itemResponse == "2") {
                            if (player.isEquipped(selectedItem)) {
                                unequipItem(player, itemChoice);                                    // Unequip the item
                            } else {
                                if (selectedItem.classification == WEAPON && player.hasEquippedWeapon()) {
                                    std::cout << "You must first unequip your current weapon before equipping a new one.\n";
                                } else {
                                    equipItem(player, itemChoice);                                  // Equip the item
                                }
                            }
                        } else if (itemResponse == "3") {
                            break;                                                                  // Exit item interaction loop and return to inventory overview
                        } else {
                            std::cout << "Invalid input. Please enter 1, 2, or 3.\n";               // Error message for invalid input
                        }
                    }
                } catch (const std::invalid_argument&) {
                    std::cout << "Invalid input. Please enter a number.\n";                         // Handle invalid non-numeric input
                }
            }

        } else if (command == "stats") {                                                            // If player wants to view their stats
            player.showStats();                                                                     // Call function to display player's stats

        } else if (command == "quit") {                                                             // If player wants to quit the game
            std::cout << "Goodbye, " << player.name << "!\n";                                       // Display farewell message
            break;                                                                                  // Exit the game loop

        } else {                                                                                    // Handle unknown commands
            std::cout << "Unknown command. Try again.\n";                                           // Show error for unknown commands
        }
    }
}
//---------------------------------------------------------------------------------------------------------------
