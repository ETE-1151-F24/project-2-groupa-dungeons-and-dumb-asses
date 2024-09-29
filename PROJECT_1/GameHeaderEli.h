#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H

//+++++++++++++++++++++++++++ any INCLUDES needed for the file ---------------
#include <vector>                                      // Required for dynamic data storage
#include <array>                                       // Required for fixed-size stat arrays
#include <iostream>                                    // For input/output operations
#include <string>                                      // For handling text (e.g., names, descriptions)
#include <chrono>                                      // Provides time-based operations
#include <thread>                                      // Enables multithreading for strobing effects
#include <limits>                                      // For clearing input buffer
#include <cctype>                                      // For checking digit characters
#include <algorithm>                                   // Required for std::max
#include <cstdlib>                                     // Required for random number generation (rand())
#include <ctime>                                       // Required for seeding random number generation

//-------------------------DECLARE GLOBAL VARIABLES----------
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount };  // Defines character stats
enum ItemType { WEAPON, MAGICAL, CLOTHING };                      // Defines item types
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };                    // Character types: main player, NPC, enemy
enum CombatType { MELEE, RANGED };                                // Combat type for weapons

//------------------------------------------ Class Declaration for Game Items ------------------------------------------
class Item {
public:
    // Attributes
    std::string name;                                    // Name of the item
    std::string description;                             // Flavor description of the item
    std::string ability;                                 // Special ability of the item
    std::string statusMessage;                           // Holds placeholder-specific status message
    ItemType classification;                             // Classification of the item (MAGICAL, CLOTHING, WEAPON)
    CombatType combatType;                               // Combat type for weapons (MELEE or RANGED)
    int statModifier[StatCount];                         // Stat modifiers for the item (Strength, Dexterity, etc.)
    int minDamage = 0;                                   // Minimum damage for weapons
    int maxDamage = 0;                                   // Maximum damage for weapons
    int rangeModifier = 0;                               // Range modifier for ranged weapons
    int sneakPenalty = 0;                                // Penalty to sneak ability
    int magPowModifier = 0;                              // Magic power modifier
    std::string restriction;                             // Restriction on who can use the item
    bool isPlaceholder;                                  // Determines if the item is a placeholder

    // Default constructor
    Item();                                              // Declares default constructor

    // Parameterized constructor
    Item(std::string itemName, std::string itemDescription, ItemType itemClassification,
         CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
         int minDmg = 0, int maxDmg = 0, int rangeMod = 0, int sneakPen = 0, int magPowMod = 0, std::string itemRestriction = "");

    void markAsPlaceholder();                            // Function to mark an item as a placeholder

    // Function to calculate damage based on combat type
    int calculateDamage(int distance);                   // Calculates damage based on combat type and distance

private:
    // Helper functions to calculate damage
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage);  // Calculates ranged damage
    int calculateMeleeDamage();                          // Calculates melee damage
};

//-----------------------------------------Declaring Class for character development----------------------------------------------------
class Player {
public:
    std::string name;                                     // Player's name
    std::string characterClass;                           // Player's character class type (e.g., cleric, ranger)
    int level;                                            // Player's level
    int experience;                                       // Accumulated experience points
    std::array<int, StatCount> stats;                     // Stats stored as a fixed-size array
    std::vector<std::string> abilitiesMenu;               // List of abilities available to the player
    std::vector<Item> equippedItems;                      // Items currently equipped by the player
    std::vector<Item> inventory;                          // Player's inventory

    Player(std::string playerName, std::string charClass, int startLevel = 1); // Constructor to initialize a player

    // Stat methods
    void rollStats();                                     // Roll stats based on the character class
    void finalizeStats();                                 // Roll stats and finalize them
    void showStats() const;                               // Display player's stats
    void showEquippedItems() const;                       // Display currently equipped items

    // Methods for equipment management
    bool isEquipped(const Item& item) const;              // Checks if an item is equipped
    void equipItem(Item& item);                           // Equip an item
    void unequipItem(Item& item);                         // Unequip an item
    bool hasEquippedWeapon() const;                       // Checks if a weapon is equipped

private:
    int roll(int minValue, int maxValue);                 // Rolls a value between a minimum and maximum value
};

//-------------------------DECLARE FUNCTION PROTOTYPES----------
void initializeGameItems(std::vector<Item>& gameItems);                   // Function to initialize game items
void printStrobingText(const std::string& text, int duration);            // Print strobing text effect for title
bool confirmClassChoice();                                                // Confirm the player's class choice
bool equipItem(Player& player, int itemIndex);                            // Equip an item from player's inventory
bool unequipItem(Player& player, int itemIndex);                          // Unequip an item from equipped items
void displayClasses(Player& player);                                      // Display available character classes
std::string getPlayerName();                                              // Get player's name
void runGameLoop(Player& player);                                         // Main game loop
void displayItemDetails(const Item& item);                                // Display item details

#endif // GAMEHEADERELI_H
