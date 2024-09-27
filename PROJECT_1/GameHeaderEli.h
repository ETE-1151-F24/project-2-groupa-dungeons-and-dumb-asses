//GameHeaderEli.h
#ifndef GAMEHEADERELI.H
#define GAMEHEADERELI.H


//+++++++++++++++++++++++++++ any INCLUDES needed for the file  ---------------
#include <vector>  // Required for using std::vector
#include <string>  // Required for using std::string
#include <array>   // Required for using std::array
#include <iostream>                     // Provides functionality for input and output operations [(cin, cout)].

// #include <iomanip>                      // Allows for formatting and [alignment] of output, such as setting precision. [setw]
// #include <string>                       // Enables the use of the standard [string] class for handling text.
// #include <cstring>                      // Provides C-style string manipulation functions like [strcpy], [strlen], etc.
// #include <thread>                       // Enables multithreading, allowing the program to [run tasks concurrently].
// #include <chrono>                       // Provides facilities for [time-based operations], such as timing and sleeping.
// #include <limits>                       // Allows access to numeric limits, such as [maximum or minimum] values of data types.
// #include <bits/stdc++.h>                // A GCC-specific header that includes nearly [all standard library] headers in one file.
// #include <cstdlib>                      // Provides functions for [random number generation, memory management], and other utilities.
// #include <ctime>                        // Provides functions to get the current time and to [seed the random number generator].
// #include <algorithm>                    // Provides functions for algorithmic operations like [sorting, searching, and transforming].

//-------------------------DECLARE GLOBAL VARIABLES----------
// Enum for character stats
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount }; //defines a set of named integer constants, 
                                                                                           //making code more readable. In this case, 
                                                                                           //StatisticType assigns specific names 
                                                                                           //(e.g., Strength, Dexterity) to integer values
                                                                                           // representing character stats

enum ItemType { WEAPON, MAGICAL, CLOTHING };                                 //defines three named constants: WEAPON, MAGICAL, and CLOTHING. 

int statModifier;
                                                                             //allows categorizing items by type in program,


class Item {
public:
    std::string name;                             // Name of the item
    std::string description;                      // Description of the item
    std::array<int, StatCount> statModifier;       // Modifier for each statistic (e.g., strength, agility)
    std::string ability;                          // Special ability associated with the item
    ItemType type;                                // Type of the item (e.g., weapon, magical, clothing)
    int minDamage; // Minimum damage value for weapons
    int maxDamage; // Maximum damage value for weapons             //min and max damage values

    // Constructor that is a template of how information is gathered and kept for different items
     Item(std::string itemName, std::string itemDescription, std::array<int, StatCount> modifier, 
         std::string itemAbility, ItemType itemType, int minDmg = 0, int maxDmg = 0)
        : name(itemName),                             // Initialize the item name
          description(itemDescription),                // Initialize the item description
          ability(itemAbility),                        // Initialize the item ability
          type(itemType),                              // Initialize the item type
          statModifier(modifier),                      // Initialize the stat modifiers
          minDamage(minDmg),                           // Initialize the minimum damage value
          maxDamage(maxDmg) {}                         // Initialize the maximum damage value

}


//------------------------CLASS FOR PLAYER DEVELOPMENT----------------------------
// Player Class
// Player Class
class Player {
public:
    std::string name;                                   // Player's name
    std::string characterClass;                         // Character's class type (e.g., cleric, ranger, etc.)
    int level;                                          // Player's current level
    int experience;                                     // Player's accumulated experience points
    std::array<int, StatCount> stats;                   // Player's stats, stored in an array of size StatCount
    std::vector<std::string> abilitiesMenu;             // List of abilities available to the player
    std::vector<Item> equippedItems;                    // Items currently equipped by the player, affecting their abilities
    std::vector<Item> saccySak;                         // Player's inventory, renamed to saccySak, stores all items that the player has acquired

    // Constructor
    Player(std::string playerName, std::string charClass, int startLevel = 1) // Constructor takes player's name, class, and optional start level
        : name(playerName), characterClass(charClass), level(startLevel), experience(0) { // Initialize name, class, level, and experience
        // Initialize stats (these can be set based on class selection and stat rolling)
        //stats = {10, 10, 10, 10, 10};                   // Example initial stats set to 10 for each stat
    }
    
    // Add other functions here as needed, such as for leveling up, gaining experience, etc.
};



//-------------------------DECLARE FUNCTION INITIALIZATIONS----------
bool confirmClassChoice();

    // Function to equip an item
    bool equipItem(Item &item);

    // Function to unequip an item
    void unequipItem(int index);

    // Function to display player's stats
    void showStats() const;

    // Function to display equipped items
    void showEquippedItems() const;
#endif //closes the definition guard