//Game_functions_eli.cpp
#include "GameHeaderEli.h"
#include <string>                       // Enables the use of the standard string class for handling text.
#include <chrono>                       // Provides facilities for [time-based operations], such as timing and sleeping.
#include <iostream>                     // for std::cin, std::cout
#include <thread>                       // Enables multithreading, allowing the program to [run tasks concurrently].

//----------------------------------------------FUNCTION FOR STROBING TITLE-------------------------------------

void printStrobingText(const std::string& text, int duration) {
    // --------------------- ANSI COLOR CODES -------------------------
    const std::string goldColor = "\033[38;5;220m";                      // Custom gold color
    const std::string resetColor = "\033[0m";                            // Reset to default
    const std::string boldEffect = "\033[1m";                            // Bold text effect

    // --------------------- TIME START POINT -------------------------
    auto startTime = std::chrono::steady_clock::now();                   // Mark current time

    // ------------------- LOOP FOR STROBING EFFECT -------------------
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

    // --------------------- RESET COLOR AT END -----------------------
    std::cout << resetColor << "\n";                                          // Reset terminal color and add a newline
}
//----------------------------------------------------------------------------------------------


//---------------------------------------------- FUNCTION FOR RUNNING MAIN GAME LOOP ---------------------------

void runGameLoop(Player& player) {
    std::string command;                                                                            // [command] variable to handle inputs

    while (true) {
        std::cout << "\nEnter a command (equip / unequip / inventory / stats / quit): ";            // Display available commands
        std::getline(std::cin, command);                                                            // Get command from the player
        command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));                                 // Trim leading whitespace to avoid errors.

        if (command == "equip") {                                                                   // If player wants to equip an item
            int itemChoice;
            std::cout << "Enter the number of the item to equip from your inventory: ";             // Prompt for item number
            std::cin >> itemChoice;

            // Input validation for equip
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.inventory.size()) {
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input.
            }

            equipItem(player, itemChoice - 1);                                                      // Equip selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer

        } else if (command == "unequip") {                                                          // If player wants to unequip an item
            int itemChoice;
            std::cout << "Enter the number of the item to unequip: ";                               // Prompt for item number
            std::cin >> itemChoice;

            // Input validation for unequip
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.equippedItems.size()) {
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear the error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input.
            }

            unequipItem(player, itemChoice - 1);                                                    // Unequip the selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer

        } else if (command == "inventory") {                                                        // If player wants to view own inventory
            if (player.inventory.empty()) {                                                         // Handle empty inventory case.
                std::cout << "Your inventory is empty.\n";
            } else {
                for (size_t i = 0; i < player.inventory.size(); ++i) {                              // Iterate over items in inventory
                    std::cout << (i + 1) << ". " << player.inventory[i].name << "\n";               // Display each item in the inventory
                }
            }

        } else if (command == "stats") {                                                            // If player wants to view own stats
            player.showStats();                                                                     // Call function to display player's stats

        } else if (command == "quit") {                                                             // If player wants to quit the game
            std::cout << "Goodbye, " << player.name << "!\n";                                       // Display farewell message
            break;                                                                                  // Exit the game loop

        } else {                                                                                    // Handle unknown commands
            std::cout << "Unknown command. Try again.\n";                                           // Show error for unknown commands
        }
    }
}
//-----------------------------------------------------------------
