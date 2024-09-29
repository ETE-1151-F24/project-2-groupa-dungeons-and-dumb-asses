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

//------------------------------- FUNCTION FOR RUNNING MAIN GAME LOOP --------------------------------
void runGameLoop(Player& player) {
    std::string command;

    while (true) {
        std::cout << "\nEnter a command (equip / unequip / inventory / stats / quit): ";
        std::getline(std::cin, command);

        // Trim whitespace and convert to lowercase
        command.erase(0, command.find_first_not_of(" \t\n\r\f\v"));
        command.erase(command.find_last_not_of(" \t\n\r\f\v") + 1);
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "equip") {
            int itemChoice;
            std::cout << "Enter the number of the item to equip from your inventory: ";
            std::cin >> itemChoice;

            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.inventory.size()) {
                std::cout << "Invalid item number. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            equipItem(player, itemChoice - 1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (command == "unequip") {
            int itemChoice;
            std::cout << "Enter the number of the item to unequip: ";
            std::cin >> itemChoice;

            if (std::cin.fail() || itemChoice <= 0 || itemChoice > player.equippedItems.size()) {
                std::cout << "Invalid item number. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            unequipItem(player, itemChoice - 1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (command == "inventory") {
            while (true) {
                // Display inventory items
                std::cout << "\n--- Your Inventory ---\n";
                for (size_t i = 0; i < player.inventory.size(); ++i) {
                    const Item& item = player.inventory[i];
                    std::string status = item.isPlaceholder ? "Placeholder (equipped)" : "In your Sakky";
                    std::cout << (i + 1) << ". " << item.name << " - " << status << "\n";
                }

                std::string response;
                std::cout << "\nWould you like to focus on an item? Enter the number or type 'no': ";
                std::getline(std::cin, response);

                if (response == "no") {
                    break;
                }

                int itemChoice;
                try {
                    itemChoice = std::stoi(response) - 1;
                } catch (std::exception& e) {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                    continue;
                }

                if (itemChoice < 0 || itemChoice >= static_cast<int>(player.inventory.size())) {
                    std::cout << "Invalid item number. Please try again.\n";
                    continue;
                }

                Item& selectedItem = player.inventory[itemChoice];
                if (selectedItem.isPlaceholder) {
                    std::cout << "This is a placeholder for an equipped item. Please unequip it first if you want to modify it.\n";
                    continue;
                }

                std::string itemResponse;
                while (true) {
                    std::cout << "\nWhat would you like to do with '" << selectedItem.name << "'?\n";
                    std::cout << "1. Read Description\n";
                    if (player.isEquipped(selectedItem)) {
                        std::cout << "2. Unequip Item\n";
                    } else {
                        std::cout << "2. Equip Item\n";
                    }
                    std::cout << "3. Back to Inventory\n";
                    std::getline(std::cin, itemResponse);

                    if (itemResponse == "1") {
                        displayItemDetails(selectedItem);
                    } else if (itemResponse == "2") {
                        if (player.isEquipped(selectedItem)) {
                            unequipItem(player, itemChoice);
                        } else {
                            equipItem(player, itemChoice);
                        }
                    } else if (itemResponse == "3") {
                        // Redisplay inventory items before going back to the previous question
                        break; // This breaks the inner loop, and the outer loop redisplays the inventory.
                    } else {
                        std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
                    }
                }
            }
        } else if (command == "stats") {
            player.showStats();
        } else if (command == "quit") {
            std::cout << "Goodbye, " << player.name << "!\n";
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
}
