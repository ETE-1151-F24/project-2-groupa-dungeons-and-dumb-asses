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
#include <random>
#include <map>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Define the number of stats
#define StatCount 5  // Ensure StatCount is defined

//++++++++++++++++++++++++++++ Function prototypes ++++++++++++++++++++++++++++++++++++++++++++++++++++++
//extern void runGameLoop(Player& player);                                   // Function to run the main game loop
//extern void printStrobingText(const std::string& text, int duration);      // Function to print strobing text effect for title

extern bool confirmClassChoice();                                          // Function to confirm player's class choice
//extern void initializeGameItems(std::vector<Item>& gameItems);             // Function to initialize game items
extern void displayClasses(const Player& player);                                // Function to display available character classes and handle selection

//extern void displayItemDetails(const Item& item);                          // Function to display item details
//extern void displayInventory(const Player& player);                       // Function to display player inventory
extern std::string getPlayerName();                                        // Function to get the player's name                           
//extern void grantSpellsOnLevelUp(Player& player, const std::vector<nlohmann::json>& availableSpells);
//extern void awardXP(Player& player, int amount, const std::map<int, int>& xpBenchmarks,const std::vector<nlohmann::json>& availableSpells);
//extern void fight(int stats[6], int floor);                                // Declaration of fight function
extern void MapGen(int map[5][5]);                                         // Map Generation function
extern void Movement(int map[5][5], int stats[6]);                        // Player movement function
extern std::vector<nlohmann::json> loadSpells(const std::string& filename); // Function to load spells from a file
//extern void chooseStartingSpell(Player& player, const std::vector<nlohmann::json>& availableSpells);
// Function to choose starting spell for the player

//+++++++++++++++++++++++++++++ Enum declarations for the project ++++++++++++++++++++++++++++++++++++++
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, };  // 5 stats

enum ItemType { WEAPON, MAGICAL, CLOTHING };                                                // Defines item categories
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };                                              // Defines character types
enum CombatType { MELEE, RANGED };     
//+++++++++++++++++++++++++++++ Struct declarations ++++++++++++++++++++++++++++++++++++++++++++++++++++
struct HealthModifiers {
    int constitutionMod = 0; // Constitution-based health modifier
    int levelMod = 0;        // Level-based health modifier
    int temporaryMod = 0;    // Temporary health modifier (e.g., from items, spells)

    // Correctly mark calculateTotalHealth as const
    int calculateTotalHealth(int baseConstitution, int level) const {
        int health = baseConstitution * 2 + level * 6;
        health += constitutionMod + levelMod + temporaryMod;
        return health;
    }
};

//+++++++++++++++++++++++++++++ Class declarations ++++++++++++++++++++++++++++++++++++++++++++++++++++

// //-------------------------------- Class for Game Items ----------------------------------------
// class Item {
// public:
//     // Attributes
//     std::string name;                                               // Name of the item
//     std::string flavorDescription;                                  // Flavor description of the item
//     std::string ability;                                            // Special ability description
//     ItemType classification;                                        // Classification of the item (MAGICAL, CLOTHING, WEAPON)
//     CombatType combatType;                                          // Combat type for weapons (MELEE or RANGED)
//     int statModifier[StatCount];                                    // Stat modifiers for the item
//     int minDamage = 0;                                              // Minimum damage for weapons
//     int maxDamage = 0;                                              // Maximum damage for weapons
//     int rangeModifier = 0;                                          // Range modifier for ranged weapons
//     int sneakPenalty = 0;                                           // Penalty to sneak when using the item
//     int magPowModifier = 0;                                         // Magic power modifier
//     std::string restriction;                                        // Restriction on who can use the item
//     int regenerationRate = 0;                                       // HP regeneration rate for this item

//     // Constructor
//     Item();                                                         // Default constructor
//     Item(std::string itemName, std::string itemFlavorDescription, ItemType itemClassification,
//          CombatType itemCombatType, const std::array<int, StatCount>& modifier, std::string itemAbility,
//          int minDmg, int maxDmg, int rangeMod, int sneakPen, int magPowMod, std::string itemRestriction, int regenRate); // Parameterized constructor


//     // Accessors and Mutators
//     std::string getName() const;                                      // Get the item's name
//     void setName(const std::string &itemName);                        // Set the item's name
//     int getRegenerationRate() const;                                  // Get the regeneration rate
//     void setRegenerationRate(int rate);                               // Set the regeneration rate

//     // Damage calculation logic
//     int calculateDamage(int distance);
//     int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage);
//     int calculateMeleeDamage();
// };

// //-------------------------------- Class for Player Development --------------------------------
// class Player {
// public:
//     // Attributes
//     std::string name;                                               // Player's name
//     std::string characterClass;                                     // Player's class type (e.g., cleric, ranger)
//     int level;                                                      // Player's current level
//     int experience;                                                 // Player's accumulated experience points
//     std::array<int, StatCount> stats;                               // Player's stats stored in an array
//     std::vector<std::string> abilitiesMenu;                         // List of abilities available to the player
//     std::vector<Item*> equippedItems;                               // Pointers to items currently equipped by the player
//     std::vector<Item> inventory;                                    // Player's inventory
//     HealthModifiers healthModifiers;                                // Added healthModifiers
//     int totalRegenerationRate = 0;                                  // Tracks total HP regeneration from equipped items
//     int currentHealth = 8;                                          // Set initial health to 8
//     int  maxHealth = 8;                                             // Set maximum health to 8
//     std::vector<std::string> learnedSpells;                         // Spells the player has learned
//     std::vector<nlohmann::json> spells;                             // Known spells for the player

//     // Constructor
//     Player(std::string playerName, std::string charClass, int startLevel = 1);

//     // Function Declarations
//     void rollStats();                                               // Roll stats based on the character class
//     void finalizeStats();                                           // Function for rolling and finalizing stats
//     void showStats() const;                                         // Display player's stats
//     void showEquippedItems() const;                                 // Display equipped items
//     void applyRegeneration();                                       // Function to apply regeneration to current health

//     // Equipment management
//     bool isEquipped(const Item& item) const;                        // Checks if an item is equipped
//     void equipItem(Item* item);                                     // Equip an item using a pointer
//     void unequipItem(Item* item);                                   // Unequip an item using a pointer
//     bool hasEquippedWeapon() const;                                 // Checks if a weapon is currently equipped
//     void getStats(int S[6], int a) const;
//     void updateStats(const Item& item, bool isEquipping);           // Helper to update the stats of the player
//     // New methods for spell handling
//     void displaySpells() const;                                     // Display learned spells
//     void learnSpell(const std::string& spellName);                  // Learn a new spell

// private:
//     int roll(int minValue, int maxValue);                           // Function to roll a stat within a given range
// };

#endif // GAMEHEADERELI_H
