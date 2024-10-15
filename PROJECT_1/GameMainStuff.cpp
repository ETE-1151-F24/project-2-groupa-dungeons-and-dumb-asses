#include "GameHeaderEli.h"                         // Include game-specific classes and definitions
#include "Character_develop_functs.cpp"            // Include character development-related functions
#include "Game_functions_eli.cpp"                  // Include general game functions
#include "Game_inventory_functions.cpp"            // Include inventory management functions
#include "gameItems.cpp"                           // Include functions to initialize game items
#include "item_constructors_dmg_shifts.cpp"        // Include item constructor implementations

// Additional headers (commented out if not used)
// #include ""
// #include ""
// #include ""


//----------------------------- Main Function ------------------------------------------------
int main() {
    srand(static_cast<unsigned int>(time(0)));                                                                  // Seed the random number generator

    // -------------------- WELCOME MESSAGE ---------------------------
    std::string title = "Goblins & Glittery S***!";                                                             // Title of the game
    int duration = 5;                                                                                           // Duration strobing effect seconds
    printStrobingText(title, duration);                                                                         // Call function to display strobing title effect

    // Display the complete welcome message
    std::cout << "Welcome to 'Goblins & Glittery S***!'\n\n";                                                   // Game title + welcome message
    std::cout << "Brace yourself for a ridiculous adventure where goblins are annoying, magic is overrated,\n"; // Describe setting
    std::cout << "and you're probably going to make some terrible decisions. But hey, that's half the fun!\n";  // Add humor
    std::cout << "Collect shiny crap, survive questionable life choices, and try not to die... too much.\n\n";  // Set expectations

    // -------------------- PLAYER SETUP --------------------------
    Player player(getPlayerName(), "");                                 // Create player w/default class and their name
    displayClasses(player);                                             // Prompt player to choose their character class

    // -------------------- INITIALIZE GAME ITEMS --------------------------
    std::vector<Item> gameItems;                                        // Create a vector to store game items
    initializeGameItems(gameItems);                                     // Initialize all items in the game

    player.inventory = gameItems;                                       // Add initialized items to player's inventory

    // -------------------- GAME LOOP --------------------------
    runGameLoop(player);                                                // Call the game loop function

    return 0;                                                           // Exit the program
}
