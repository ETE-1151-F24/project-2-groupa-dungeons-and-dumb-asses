// GameHeaderEli.h
#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H

//+++++++++++++++++++++++++++ any INCLUDES needed for the file  ---------------
#include <vector>                                      // Required for using std::vector to store dynamic data collections
#include <array>                                       // Required for using std::array to handle fixed-size stat arrays
#include <iostream>                                    // Required for input and output operations (cin, cout)
#include <string>                                  // Include string class for player names, commands, etc.
#include <chrono>                                  // Include chrono for time-based operations
#include <thread>                                  // Include thread for pauses in strobing effect
#include <limits>                                  // Include limits for clearing input buffer
#include <cctype>                                  // Include cctype for checking digit characters
#include <algorithm>                               // Required for std::max to ensure minimum damage of 1
#include <cstdlib>                                 // Required for random number generation (rand())
#include <ctime>                                   // Required for seeding random number generation (time)

//-------------------------DECLARE GLOBAL VARIABLES----------
// Enum for character stats
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount }; // Defines a set of named constants to represent character stats

// Enum for item types
enum ItemType { WEAPON, MAGICAL, CLOTHING };           // Defines item types to categorize items in the game

// Enum for character type
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };         // Character types: main player, NPC, enemy

// Enumeration for different combat types for weapons
enum CombatType { MELEE, RANGED };

//------------------------------------------ Class Declaration for Game Items ------------------------------------------
class Item {
public:
    // Attributes
    std::string name;                                   // Name of the item
    std::string description;                            // Description of the item
    std::string ability;                                // Special ability description
    ItemType classification;                            // Classification of the item (MAGICAL, CLOTHING, WEAPON)
    CombatType combatType;                              // Combat type for weapons (MELEE or RANGED)
    int statModifier[StatCount];                        // Stat modifiers for the item (Strength, Dexterity, Intelligence, Wisdom, Constitution)
    int minDamage = 0;                                  // Minimum damage for weapons
    int maxDamage = 0;                                  // Maximum damage for weapons
    int rangeModifier = 0;                              // Range modifier for ranged weapons
    int sneakPenalty = 0;                               // Penalty to sneak when using the item
    int magPowModifier = 0;                             // Magic power modifier
    std::string restriction;                            // Any restriction on who can use the item

    // Default constructor
    Item();                                             // Declares the default constructor

    // Parameterized constructor declaration
    Item(std::string itemName, std::string itemDescription, ItemType itemClassification,
         CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
         int minDmg = 0, int maxDmg = 0, int rangeMod = 0, int sneakPen = 0, int magPowMod = 0, std::string itemRestriction = "");

    // Other member functions (if needed) can go here
    // Function to calculate damage based on combat type
    int calculateDamage(int distance);                  // Declares function to calculate item damage

private:
    // Helper functions to calculate damage
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage); // Calculates damage for ranged weapons
    int calculateMeleeDamage();                         // Calculates damage for melee weapons
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
    std::vector<Item> inventory;                       // Player's inventory renamed to "inventory" for clarity

    Player(std::string playerName, std::string charClass, int startLevel = 1);


// Stat methods
    void rollStats();                                  // Roll stats based on the character class
    void finalizeStats();                              // Method for rolling and finalizing stats
    void showStats() const;                            // Display player's stats
    void showEquippedItems() const;                    // Display equipped items 

// Methods for equipment management
    bool isEquipped(const Item& item) const;               // Checks if an item is equipped
    void equipItem(Item& item);                            // Equip an item
    void unequipItem(Item& item);                          // Unequip an item
    bool hasEquippedWeapon() const;                        // Checks if a weapon is currently equipped




private:

    int roll(int minValue, int maxValue);              // Method to roll a stat between a given range


};

//-------------------------DECLARE FUNCTION PROTOTYPES----------
void initializeGameItems(std::vector<Item>& gameItems);         // Function to initialize game items
void printStrobingText(const std::string& text, int duration);  // Function to print strobing text effect for title
bool confirmClassChoice();                                      // Function to confirm player's class choice
bool equipItem(Player& player, int itemIndex);                  // Function to equip an item from player's inventory
bool unequipItem(Player& player, int itemIndex);                // Function to unequip an item from player's equipped items
void displayClasses(Player& player);                            // Function to display available character classes and handle selection
std::string getPlayerName();                                    // Function to get the player's name
void runGameLoop(Player& player);                               // Function to run the main game loop
void displayItemDetails(const Item& item);                      // Declare the function to display item details

#endif // GAMEHEADERELI_H