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

//+++++++++++++++++++++++++++++ Enum declarations for the project ++++++++++++++++++++++++++++++++++++++
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount };  // Defines character stats
enum ItemType { WEAPON, MAGICAL, CLOTHING };                                                // Defines item categories
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };                                              // Defines character types
enum CombatType { MELEE, RANGED };                                                          // Defines weapon combat types

//+++++++++++++++++++++++++++++ Struct declarations ++++++++++++++++++++++++++++++++++++++++++++++++++++
struct HealthModifiers {
    int constitutionMod = 0; // Constitution-based health modifier
    int levelMod = 0;        // Level-based health modifier
    int temporaryMod = 0;    // Temporary health modifier (e.g., from items, spells)

    // Calculate total health
    int calculateTotalHealth(int baseConstitution, int level) const {
        int baseHealth = baseConstitution * 2;  // Base health from Constitution
        int levelHealth = level * 6;           // Level-based health bonus
        return baseHealth + levelHealth + constitutionMod + levelMod + temporaryMod;
    }
};






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
    // New Attribute
    int regenerationRate = 0; // HP regeneration rate for this item

    // Default constructor
     // Default Constructor
    Item()
        : name("Unknown"), flavorDescription("No description"), ability("No ability"),
          classification(ItemType::MAGICAL), combatType(CombatType::MELEE) {
        std::fill(std::begin(statModifier), std::end(statModifier), 0);
    }                                                         // Declares the default constructor


    // Parameterized Constructor
    Item(std::string itemName,                                      // Set the item's name 
        std::string itemDescription,                               // Set the item's description 
        ItemType itemClassification,                               // Set the item's classification (e.g., WEAPON, CLOTHING) 
        CombatType itemCombatType,,                                 // Set the item's combat type (MELEE or RANGED)
        std::array<int, StatCount> modifier,                       // Set stat modifiers (e.g., strength, dexterity adjustments) 
        std::string itemAbility,                                   // Set the item's special ability description 
         int minDmg = 0,                                            // Set minimum damage (default 0 for non-weapons)
         int maxDmg = 0,                                            // Set maximum damage (default 0 for non-weapons)
         int rangeMod = 0,                                          // Set range modifier (default 0)
         int sneakPen = 0,                                          // Set sneak penalty (default 0)
         int magPowMod = 0,                                         // Set magic power modifier (default 0)
        std::string itemRestriction = "",                         // Set usage restrictions (e.g., class-specific, default none)
        int regenRate = 0)
        : name(itemName), flavorDescription(itemDescription), ability(itemAbility),
          classification(itemClassification), combatType(itemCombatType), minDamage(minDmg),
          maxDamage(maxDmg), rangeModifier(rangeMod), sneakPenalty(sneakPen), magPowModifier(magPowMod),
          restriction(itemRestriction), regenerationRate(regenRate) {
        std::copy(modifier.begin(), modifier.end(), statModifier);
    }

    // Accessors and Mutators (Example)
    std::string getName() const { return name; }
    void setName(const std::string &itemName) { name = itemName; }

    int getRegenerationRate() const { return regenerationRate; }
    void setRegenerationRate(int rate) { regenerationRate = rate; }

    int calculateDamage(int distance); // Damage calculation logic

private:
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage);
    int calculateMeleeDamage();
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
    HealthModifiers healthModifiers; // Added healthModifiers
    int totalRegenerationRate = 0; // Tracks total HP regeneration from equipped items
    int currentHealth = 8;          // Set initial health to 8
    int  maxHealth = 8; {             // Set maximum health to 8
    // Constructor
    Player(std::string playerName, std::string charClass, int startLevel = 1);

    // Function Declarations
    void rollStats();                                               // Roll stats based on the character class
    void finalizeStats();                                           // Function for rolling and finalizing stats
    void showStats() const;                                         // Display player's stats
    void showEquippedItems() const;                                 // Display equipped items
    void applyRegeneration();     // Function to apply regeneration to current health


    // Equipment management
    bool isEquipped(const Item& item) const;                        // Checks if an item is equipped
    void equipItem(Item* item);                                     // Equip an item using a pointer
    void unequipItem(Item* item);                                   // Unequip an item using a pointer
    bool hasEquippedWeapon() const;                                 // Checks if a weapon is currently equipped
    void getStats(int S[6], int a) const;

private:
    int roll(int minValue, int maxValue);                           // Function to roll a stat within a given range
};

//++++++++++++++++++++++++++++ Function prototypes ++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printStrobingText(const std::string& text, int duration);      // Function to print strobing text effect for title
bool confirmClassChoice();                                          // Function to confirm player's class choice
void initializeGameItems(std::vector<Item>& gameItems);             // Function to initialize game items
void displayClasses(Player& player);                                // Function to display available character classes and handle selection
void runGameLoop(Player& player);                                   // Function to run the main game loop
void displayItemDetails(const Item& item);                          // Function to display item details
void displayInventory(const Player& player);                       // Function to display player inventory
std::string getPlayerName();                                        // Function to get the player's name                           

#endif // GAMEHEADERELI_H

