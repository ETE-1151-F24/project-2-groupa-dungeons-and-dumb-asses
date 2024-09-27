//GameHeaderEli.h
#ifndef GAMEHEADERELI.H
#define GAMEHEADERELI.H


//+++++++++++++++++++++++++++ any INCLUDES needed for the file  ---------------
// #include <iostream>                     // Provides functionality for input and output operations [(cin, cout)].
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
                                                                             //allows categorizing items by type in program,

class Item {
public:
    std::string name;                             // Name of the item
    std::string description;                      // Description of the item
    std::array<int, StatCount> statModifier;       // Modifier for each statistic (e.g., strength, agility)
    std::string ability;                          // Special ability associated with the item
    ItemType type;                                // Type of the item (e.g., weapon, magical, clothing)
    
    // Constructor that is a templat of how information is gathered and kept for different items
    Item(std::string itemName, std::string itemDescription, std::array<int, StatCount> modifier, std::string itemAbility, ItemType itemType)
        : name(itemName),                            // Initialize the item name
          description(itemDescription),              // Initialize the item description
          ability(itemAbility),                      // Initialize the item ability
          type(itemType),                            // Initialize the item type
          statModifier(modifier) {}                  // Initialize the stat modifiers




//-------------------------DECLARE FUNCTION INITIALIZATIONS----------
bool confirmClassChoice();


#endif //closes the definition guard