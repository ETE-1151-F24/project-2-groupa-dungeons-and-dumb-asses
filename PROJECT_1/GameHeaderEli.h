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
class Player {
public:
    std::string name;                                   // Player's name
    std::array<int, StatCount> stats;                   // Player's stats, stored in an array of fixed size (StatCount)
    std::vector<Item> inventory;                        // Player's inventory, a collection of items that the player has acquired
    std::vector<Item> equippedItems;                    // Items that the player currently has equipped, affecting their stats or abilities

    // Constructor
    Player(std::string playerName) : name(playerName) { // Initialize player with a name
        // Initialize stats (these can be set based on class selection and stat rolling)
        stats = {10, 10, 10, 10, 10};                   // Example initial stats set to 10 for each stat
    }
}



//-------------------------DECLARE FUNCTION INITIALIZATIONS----------
bool confirmClassChoice();


#endif //closes the definition guard