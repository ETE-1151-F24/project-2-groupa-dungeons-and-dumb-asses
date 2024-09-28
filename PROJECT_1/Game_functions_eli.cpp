//Game_functions_eli.cpp
#include "GameHeaderEli.h"
#include <string>                       // Enables the use of the standard string class for handling text.
#include <chrono>                       // Provides facilities for [time-based operations], such as timing and sleeping.
#include <iostream>                     // for std::cin, std::cout
#include <thread>                       // Enables multithreading, allowing the program to [run tasks concurrently].                 
//----------------------------------------------FUNCTION FOR STROBING TITLE-------------------------------------
  
 void printStrobingText(const std::string& text, int duration) { 
    // ---------------------ANSI COLOR CODES-------------------------
    // Array of ANSI escape codes representing gold color and bold effect.
    const std::string goldColor = "\033[38;5;220m";                                 // Custom gold color
    const std::string resetColor = "\033[0m";                                       // Reset to default
    const std::string boldEffect = "\033[1m";                                       // Bold text effect

    // ---------------------TIME START POINT-------------------------
    auto startTime = std::chrono::steady_clock::now();                              // Mark current time

    // -------------------LOOP FOR STROBING EFFECT-------------------
    while (true) {
                                                                                    // Calculate elapsed time
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

        if (elapsedTime >= duration) {                                              // Break the loop when duration ends
            break;
        }

        // ------------------STROBING CHARACTERS----------------------
         for (size_t i = 0; i < text.length(); ++i) {
            std::cout << "\r";                                                      // Move cursor to the start of the line

            for (size_t j = 0; j < text.length(); ++j) {
                if (j % 2 == i % 2) {
                    std::cout << goldColor << boldEffect << text[j];                // Gold and bold effect for alternating characters
                } else {
                    std::cout << resetColor << boldEffect << text[j];               // Reset color with bold effect for other characters
                }
            }

            std::cout.flush();                                                      // Flush output buffer to display text immediately
            std::this_thread::sleep_for(std::chrono::milliseconds(100));            // Delay for visible strobing effect
        }
    }

    // ---------------------RESET COLOR AT END-----------------------
    std::cout << resetColor << "\n";  // Reset terminal color and add a newline
//----------------------------------------------------------------------------------------------


//----------------------------------------------Function for running the main game loop
void runGameLoop(Player& player) {
    std::string command;                                                                    // Command variable to handle player inputs
    while (true) {
        std::cout << "\nEnter a command (equip / unequip / inventory / stats / quit): ";    // Display available commands
        std::getline(std::cin, command);                                                    // Get command from the player

        if (command == "equip") {                                                           // If player wants to equip an item
            int itemChoice;                                                                 // Variable to hold player's item choice
            std::cout << "Enter the number of the item to equip from your inventory: ";     // Prompt for item number
            std::cin >> itemChoice;                                                         // Record player's item selection
            equipItem(player, itemChoice - 1);                                              // Call function to equip the item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // Clear the input buffer
        } else if (command == "unequip") {                                                  // If player wants to unequip an item
            int itemChoice;                                                                 // Variable to hold player's item choice
            std::cout << "Enter the number of the item to unequip: ";                       // Prompt for item number
            std::cin >> itemChoice;                                                         // Record player's item selection
            unequipItem(player, itemChoice - 1);                                            // Call function to unequip the item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // Clear the input buffer
        } else if (command == "inventory") {                                                // If player wants to view their inventory
            for (size_t i = 0; i < player.inventory.size(); ++i) {                          // Iterate over items in inventory
                std::cout << (i + 1) << ". " << player.inventory[i].name << "\n";           // Display each item in the inventory
            }
        } else if (command == "stats") {                                                    // If player wants to view their stats
            player.showStats();                                                             // Call function to display player's stats
        } else if (command == "quit") {                                                     // If player wants to quit the game
            std::cout << "Goodbye, " << player.name << "!\n";                               // Display farewell message
            break;                                                                          // Exit the game loop
        } else {                                                                            // Handle unknown commands
            std::cout << "Unknown command. Try again.\n";                                   // Display error message for unknown commands
        }
    }
}