//GameMainStuff.cpp
#include "GameHeaderEli.h"                         // Include game-specific classes and definitions
#include "Character_develop_functs.cpp"
#include "Game_functions_eli.cpp"
#include "Game_inventory_functions.cpp"
#include "gameItems.cpp"
#include "item_constructors_dmg_shifts.cpp"
// #include ""
// #include ""
// #include ""


// #include <iostream>                                // Include input-output stream for console interactions
// #include <string>                                  // Include string class for player names, commands, etc.
// #include <chrono>                                  // Include chrono for time-based operations
// #include <thread>                                  // Include thread for pauses in strobing effect
// #include <limits>                                  // Include limits for clearing input buffer
// #include <cctype>                                  // Include cctype for checking digit characters
// #include <algorithm>                               // Required for std::max to ensure minimum damage of 1
// #include <cstdlib>                                 // Required for random number generation (rand())
// #include <ctime>                                   // Required for seeding random number generation (time)

int main() {

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    
    /*[new code goes in these]*/
    // --------------------WELCOME MESSAGE--------------------------
    std::string title = "Goblins & Glittery S***!";                          // Title of the game
    int duration = 5;                                                        // Duration for the strobing effect in seconds
    printStrobingText(title, duration);                                      // Call the function to display the strobing title effect

    // Display the complete welcome message
    std::cout << "Welcome to 'Goblins & Glittery S***!'\n\n";                // Game title and welcome message
    std::cout << "Brace yourself for a ridiculous adventure where goblins are annoying, magic is overrated,\n";  // Describe adventure setting
    std::cout << "and you're probably going to make some terrible decisions. But hey, that's half the fun!\n";   // Add a humorous note
    std::cout << "Collect shiny crap, survive questionable life choices, and try not to die... too much.\n\n";   // Set player expectations for gameplay

    // --------------------PLAYER SETUP--------------------------
    Player player(getPlayerName(), "");                                      // Create a player with default class and their name
    displayClasses(player);                                                 // Prompt player to choose their character class
   
    // --------------------INITIALIZE GAME ITEMS--------------------------
    std::vector<Item> gameItems;                                            // Create a vector to store game items
    initializeGameItems(gameItems);                                         // Initialize all items in the game

    player.inventory = gameItems; // Add initialized items to player's inventory for demo

    // --------------------GAME LOOP--------------------------
    runGameLoop(player);                                                    // Call the game loop function

    return 0;    
}




