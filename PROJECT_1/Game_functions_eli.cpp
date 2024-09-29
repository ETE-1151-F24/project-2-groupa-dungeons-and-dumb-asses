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

        // ----------------------------------- TRIM AND PROCESS COMMAND INPUT ---------------------------------
        command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));                                 // Trim leading whitespace
        command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1);                                 // Trim trailing whitespace
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);                 // Convert the command to lowercase for case insensitivity
        std::cout << "DEBUG: Command entered: '" << command << "'\n";                               // Debug output to verify command input

        // ----------------------------------- COMMAND HANDLING -----------------------------------------------
        if (command == "equip") {                                                                   // If player wants to equip an item
            int itemChoice;                                                                         // Variable to store item choice
            std::cout << "Enter the number of the item to equip from your inventory: ";             // Prompt for item number
            std::cin >> itemChoice;

            // ------------------------------- INPUT VALIDATION FOR EQUIP ------------------------------------
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.inventory.size()) {       // Validate input for correct range and type
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input
            }

            // ------------------------------- EQUIP ITEM ----------------------------------------------------
            equipItem(player, itemChoice - 1);                                                      // Equip selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer to remove leftover newline character
            std::cout << "You have equipped: " << player.inventory[itemChoice - 1].name << "\n";    // Display confirmation of equipped item

        } else if (command == "unequip") {                                                          // If player wants to unequip an item
            int itemChoice;                                                                         // Variable to store item choice
            std::cout << "Enter the number of the item to unequip: ";                               // Prompt for item number
            std::cin >> itemChoice;

            // ------------------------------- INPUT VALIDATION FOR UNEQUIP -------------------------------
            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.equippedItems.size()) {   // Validate input for correct range and type
                std::cout << "Invalid item number. Please try again.\n";                            // Invalid input message
                std::cin.clear();                                                                   // Clear the error flag on cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                 // Discard invalid input
                continue;                                                                           // Prevent further processing after invalid input
            }

            // ------------------------------- UNEQUIP ITEM -------------------------------------------------
            unequipItem(player, itemChoice - 1);                                                    // Unequip the selected item (adjust for zero-based index)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear the input buffer to remove leftover newline character
            std::cout << "You have unequipped: " << player.equippedItems[itemChoice - 1].name << "\n"; // Display confirmation of unequipped item

        } else if (command == "inventory") {                                                        // If player wants to view their inventory
            // ---------------------------------- DISPLAY INVENTORY -----------------------------------------
            if (player.inventory.empty()) {                                                         // Handle empty inventory case
                std::cout << "Your inventory is empty.\n";
            } else {
                for (size_t i = 0; i < player.inventory.size(); ++i) {                              // Iterate over items in inventory
                    std::cout << (i + 1) << ". " << player.inventory[i].name;                       // Display each item in the inventory
                    if (player.isEquipped(player.inventory[i])) {                                   // Check if item is equipped
                        std::cout << " (Equipped)";
                    }
                    std::cout << "\n";
                }
            }

        } else if (command == "stats") {                                                            // If player wants to view their stats
            // ---------------------------------- DISPLAY PLAYER STATS --------------------------------------
            player.showStats();                                                                     // Call function to display player's stats

        } else if (command == "quit") {                                                             // If player wants to quit the game
            // ---------------------------------- QUIT GAME -------------------------------------------------
            std::cout << "Goodbye, " << player.name << "!\n";                                       // Display farewell message
            break;                                                                                  // Exit the game loop

        } else {                                                                                    // Handle unknown commands
            // ---------------------------------- UNKNOWN COMMAND ------------------------------------------
            std::cout << "Unknown command. Try again.\n";                                           // Show error for unknown commands
        }
    }
}
//-----------------------------------------------------------------



//--------------------------clarification of the ****whitespace cleaning syntax-----------------------
/* 
-------------------------------------------------------------------------------------------
Explanation of Whitespace Characters Used for Trimming (`" \t\n\r\f\v"`):
-------------------------------------------------------------------------------------------
The string `" \t\n\r\f\v"` contains various **whitespace characters** that may need to be trimmed
from user input. Each of these characters has a specific purpose related to formatting:

1. **Space (`' '`)**:
   - A regular space character, used for separating words or padding.

2. **Horizontal Tab (`\t`)**:
   - Represents a **tab** character, commonly used to align text in columns.

3. **Newline (`\n`)**:
   - Represents a **newline** character, moving the cursor to the **next line**.
   - This is used to end a line of text and start a new one.

4. **Carriage Return (`\r`)**:
   - Represents a **carriage return**, moving the cursor to the **beginning of the current line**.
   - Often used with `\n` (`\r\n`) for line endings in Windows environments.

5. **Form Feed (`\f`)**:
   - Represents a **form feed** character, used to advance the printer to the **next page**.
   - It is mostly a legacy character and rarely used in modern applications.

6. **Vertical Tab (`\v`)**:
   - Represents a **vertical tab**, moving the cursor **down to the next tab stop** vertically.
   - Similar to form feed, it is not common in modern software.

These characters are used in the trimming functions:
- `command.erase(0, command.find_first_not_of(" \t\n\r\f\v"))`:
  - Removes all **leading whitespace** characters from the string `command`.

- `command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1)`:
  - Removes all **trailing whitespace** characters from the string `command`.

This ensures that any input given by the user is clean and free from unintended spaces or control 
characters that might cause issues during processing, especially for commands entered in the game.
-------------------------------------------------------------------------------------------
*/
