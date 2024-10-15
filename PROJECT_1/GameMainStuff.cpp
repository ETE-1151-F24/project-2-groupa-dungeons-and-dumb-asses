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

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    J:The only major nitpick that I have is that the program is lowkey hard to follow, only becuase I feel like 
    im playing a scavenger hunt looking for each function, so I feel like when a fuction is used, there should should be a comment to the exact location
    aka for the function on line '40: runGameLoop(player);' with in the comment add its location 
    (ex. Located in Game_functions_eli.cpp on line 43) that way the program is easier to follow and is not a search for every function that is used
    cause my adhd monkey brain may follow the code, but lose track of what I was trying to do whilst going through all the functions,
    I feel that it will create better organization throughout the program and would be easier for others who are seeing it for the first time
    to be able to not only understand the program but follow the path it is taking in a more effecient manner.
    
    
     test
    ajbfg
    fna
*/