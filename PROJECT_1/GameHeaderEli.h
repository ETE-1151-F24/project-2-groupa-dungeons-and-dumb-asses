//GameHeaderEli.h
#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H


//+++++++++++++++++++++++++++ any INCLUDES needed for the file  ---------------
#include <vector>                                      // Required for using std::vector to store dynamic data collections
#include <string>                                      // Required for using std::string to handle text data
#include <array>                                       // Required for using std::array to handle fixed-size stat arrays
#include <iostream>                                    // Required for input and output operations (cin, cout)

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
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount }; // Defines a set of named constants to represent character stats

// Enum for item types
enum ItemType { WEAPON, MAGICAL, CLOTHING };           // Defines item types to categorize items in the game

// Enum for character type
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };         // Character types: main player, NPC, enemy


//------------------------------------------Declaring Class for game items---------------------------------------------------------
class Item {
public:
    std::string name;                                  // Name of the item
    std::string description;                           // Description of the item
    std::array<int, StatCount> statModifier;           // Modifier for each statistic (e.g., strength, agility)
    std::string ability;                               // Special ability associated with the item
    ItemType type;                                     // Type of the item (e.g., weapon, magical, clothing)
    int minDamage;                                     // Minimum damage value for weapons
    int maxDamage;                                     // Maximum damage value for weapons

    // Constructor template for items
    Item(std::string itemName, std::string itemDescription, std::array<int, StatCount> modifier, 
         std::string itemAbility, ItemType itemType, int minDmg = 0, int maxDmg = 0)    // Constructor takes the item properties
        : name(itemName), description(itemDescription), statModifier(modifier),          // Initialize item name, description, and stat modifiers
          ability(itemAbility), type(itemType), minDamage(minDmg), maxDamage(maxDmg) {}  // Initialize ability, item type, and damage values
};
//-----------------------------------------Declaring Class for character development----------------------------------------------------
class Player {
public:
    std::string name;                                  // Player's name
    std::string characterClass;                        // Player's class type (e.g., cleric, ranger, etc.)
    int level;                                         // Player's current level
    int experience;                                    // Player's accumulated experience points
    std::array<int, StatCount> stats;                  // Player's stats stored in an array of fixed size
    std::vector<std::string> abilitiesMenu;            // List of abilities available to the player
    std::vector<Item> equippedItems;                   // Items currently equipped by the player, affecting their abilities
    std::vector<Item> saccySak;                        // Player's inventory renamed to "saccySak" to personalize their inventory

    // Constructor template for how the character is built, could be used to define a character other than the main player
    Player(std::string playerName, std::string charClass, int startLevel = 1) // Constructor takes player's name, class, and optional start level
        : name(playerName), characterClass(charClass), level(startLevel), experience(0) {} // Initialize player properties

    // Method to roll stats based on character class
    void rollStats();                                  // Method to roll stats, unique for each character class

    // Function to display player's stats
    void showStats() const;                            // Display all the player's stats in the game

    // Function to display equipped items
    void showEquippedItems() const;                    // Show items that are currently equipped by the player
};

#endif // GAMEHEADERELI_H

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