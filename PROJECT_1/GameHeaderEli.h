#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H

//+++++++++++++++++++++++++++++ Required standard libraries for the project ++++++++++++++++++++++++++++
#include <vector>                                                   // Required for using std::vector to store dynamic data collections
#include <array>                                                    // Required for using std::array to handle fixed-size stat arrays
#include <iostream>                                                 // Required for input and output operations (cin, cout)
#include <string>                                                   // Required for player names, commands, etc.
#include <chrono>                                                   // Required for time-based operations
#include <thread>                                                   // Required for pauses in strobing effect
#include <limits>                                                   // Required for clearing input buffer
#include <cctype>                                                   // Required for checking digit characters
#include <algorithm>                                                // Required for using std::max
#include <cstdlib>                                                  // Required for random number generation (rand())
#include <ctime>                                                    // Required for seeding random number generation (time)
#include <iomanip>

//+++++++++++++++++++++++++++++ Enum declarations for the project ++++++++++++++++++++++++++++++++++++++
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount };  // Defines character stats
enum ItemType { WEAPON, MAGICAL, CLOTHING };                                                // Defines item categories
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };                                              // Defines character types
enum CombatType { MELEE, RANGED };                                                          // Defines weapon combat types

//+++++++++++++++++++++++++++++ Class declarations ++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Note on constructors:
// A constructor helps set up an object with its initial values when it's created,
// making sure everything is ready to use right from the start.

//-------------------------------- Class for Game Items ----------------------------------------
class Item {
public:
    // Attributes
    std::string name;                                               // Name of the item
    std::string flavorDescription;                                  // Flavor description of the item
    std::string ability;                                            // Special ability description
    ItemType classification;                                        // Classification of the item (MAGICAL, CLOTHING, WEAPON)
    CombatType combatType;                                          // Combat type for weapons (MELEE or RANGED)
    int statModifier[StatCount];                                    // Stat modifiers for the item
    int minDamage = 0;                                              // Minimum damage for weapons
    int maxDamage = 0;                                              // Maximum damage for weapons
    int rangeModifier = 0;                                          // Range modifier for ranged weapons
    int sneakPenalty = 0;                                           // Penalty to sneak when using the item
    int magPowModifier = 0;                                         // Magic power modifier
    std::string restriction;                                        // Restriction on who can use the item

    // Default constructor
    Item();                                                         // Declares the default constructor

    // Parameterized constructor to initialize an Item object
    Item(std::string itemName,                                      // Set the item's name
         std::string itemDescription,                               // Set the item's description
         ItemType itemClassification,                               // Set the item's classification (e.g., WEAPON, CLOTHING)
         CombatType itemCombatType,                                 // Set the item's combat type (MELEE or RANGED)
         std::array<int, StatCount> modifier,                       // Set stat modifiers (e.g., strength, dexterity adjustments)
         std::string itemAbility,                                   // Set the item's special ability description
         int minDmg = 0,                                            // Set minimum damage (default 0 for non-weapons)
         int maxDmg = 0,                                            // Set maximum damage (default 0 for non-weapons)
         int rangeMod = 0,                                          // Set range modifier (default 0)
         int sneakPen = 0,                                          // Set sneak penalty (default 0)
         int magPowMod = 0,                                         // Set magic power modifier (default 0)
         std::string itemRestriction = "");                         // Set usage restrictions (e.g., class-specific, default none)

    // Function Declarations
    int calculateDamage(int distance);                              // calculate damage based on combat type

private:
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage);  // ranged damage calculation
    int calculateMeleeDamage();                                                           // melee damage calculation
};

//-------------------------------- Class for Player Development --------------------------------
class Player {
public:
    // Attributes
    std::string name;                                               // Player's name
    std::string characterClass;                                     // Player's class type (e.g., cleric, ranger)
    int level;                                                      // Player's current level
    int experience;                                                 // Player's accumulated experience points
    std::array<int, StatCount> stats;                               // Player's stats stored in an array
    std::vector<std::string> abilitiesMenu;                         // List of abilities available to the player
    std::vector<Item*> equippedItems;                               // Pointers to items currently equipped by the player
    std::vector<Item> inventory;                                    // Player's inventory

    // Constructor
    Player(std::string playerName, std::string charClass, int startLevel = 1);

    // Function Declarations
    void rollStats();                                               // Roll stats based on the character class @ Character_develop_functs.cpp--LINE 133
    void finalizeStats();                                           // rolling and finalizing stats
    void showStats() const;                                         // Display player's stats
    void showEquippedItems() const;                                 // Display equipped items

    // Equipment management
    bool isEquipped(const Item& item) const;                        // Checks if an item is equipped
    void equipItem(Item* item);                                     // Equip an item using a pointer
    void unequipItem(Item* item);                                   // Unequip an item using a pointer
    bool hasEquippedWeapon() const;                                 // Checks if a weapon is currently equipped

private:
    int roll(int minValue, int maxValue);                           // roll a stat within a given range                 @ Character_develop_functs.cpp-  -LINE 181
};

//++++++++++++++++++++++++++++ Function prototypes ++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printStrobingText(const std::string& text, int duration);      // print strobing text effect for title             @ Game_functions_eli.cpp --     --LINE 10
void initializeGameItems(std::vector<Item>& gameItems);             // initialize game items                            @ gameItems.cpp --              --LINE 19
void displayClasses(Player& player);                                // display character classes and handle selection   @ Character_develop_functs.cpp -- LINE 71
void runGameLoop(Player& player);                                   // run the main game loop                           @ Game_functions_eli.cpp--      --LINE 44
void displayItemDetails(const Item& item);                          // display item details                             @ Game_inventory_functions.cpp----LINE 81
void displayInventory(const Player& player);                        // display player inventory                         @ Game_inventory_functions.cpp----LINE 5
std::string getPlayerName();                                        // get the player's name                            @ Character_develop_functs.cpp -- LINE 31
                        

#endif // GAMEHEADERELI_H
  