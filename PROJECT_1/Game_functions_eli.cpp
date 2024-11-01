//Game_functions_eli.cpp
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

//------------------------------- FUNCTION FOR RUNNING MAIN GAME LOOP   this is modifiable -------------------------------------------
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
            displayInventory(player);    //@Game_inventory_functions.cpp  LINES 81-112
        } else if (command == "stats") {                                                      // Stats command
            player.showStats();          //@Character_develop_functs.cpp LINES 188-195        // Display player's stats



            //add OTHER GAME FUNCTIONS IN BETWEEN HERE AS ELSE COMPONENTS

            
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
