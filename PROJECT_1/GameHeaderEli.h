// GameHeaderEli.h
#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H

//+++++++++++++++++++++++++++ any INCLUDES needed for the file  ---------------
#include <vector>                                      // Required for using std::vector to store dynamic data collections
#include <string>                                      // Required for using std::string to handle text data
#include <array>                                       // Required for using std::array to handle fixed-size stat arrays
#include <iostream>                                    // Required for input and output operations (cin, cout)

//-------------------------DECLARE GLOBAL VARIABLES----------
// Enum for character stats
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount }; // Defines a set of named constants to represent character stats

// Enum for item types
enum ItemType { WEAPON, MAGICAL, CLOTHING };           // Defines item types to categorize items in the game

// Enum for character type
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };         // Character types: main player, NPC, enemy

// Enumeration for different combat types for weapons
enum CombatType { MELEE, RANGED };

//------------------------------------------Declaring Class for game items---------------------------------------------------------
class Item {
public:
    std::string name;                                    // Name of the item
    std::string description;                             // Description of the item
    std::string ability;                                 // Special ability description
    ItemClassification classification;                   // Classification of the item (MAGICAL, CLOTHING, WEAPON)
    CombatType combatType;                               // Combat type for weapons (MELEE or RANGED)
    int statModifier[StatCount] = {0};                   // Stat modifiers for the item
    int minDamage = 0;                                   // Minimum damage for weapons
    int maxDamage = 0;                                   // Maximum damage for weapons
    int rangeModifier = 0;                               // Range modifier for ranged weapons
    int sneakPenalty = 0;                                // Penalty to sneak when using the item
    std::string restriction;                             // Any restriction on who can use the item

    // Default constructor
    Item() : name(""),                                   // Set item name to empty string by default
             description(""),                            // Set description to empty string by default
             ability(""),                                // Set ability to empty string by default
             classification(MAGICAL),                    // Default classification is MAGICAL
             combatType(MELEE),                          // Default combat type is MELEE
             minDamage(0),                               // Set minimum damage to 0 by default
             maxDamage(0),                               // Set maximum damage to 0 by default
             rangeModifier(0),                           // Set range modifier to 0 by default
             sneakPenalty(0),                            // Set sneak penalty to 0 by default
             restriction("") {                           // Set restriction to empty string by default
        // Initialize all stat modifiers to 0
        for (int i = 0; i < StatCount; ++i) {
            statModifier[i] = 0;                         // Set each stat modifier to 0 by default
        }
    }

// Constructor template for items
Item(std::string itemName, std::string itemDescription, ItemType itemClassification, // Item name, description, and classification
     CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility, // Combat type, stat modifiers, and ability
     int minDmg = 0, int maxDmg = 0, int rangeMod = 0, int sneakPen = 0, std::string itemRestriction = "") // Optional parameters
    : name(itemName),                                      // Initialize item name
      description(itemDescription),                        // Initialize item description
      classification(itemClassification),                  // Set item classification (MAGICAL, CLOTHING, WEAPON)
      combatType(itemCombatType),                          // Set combat type (MELEE or RANGED)
      ability(itemAbility),                                // Set special ability description
      minDamage(minDmg),                                   // Set minimum damage for the item
      maxDamage(maxDmg),                                   // Set maximum damage for the item
      rangeModifier(rangeMod),                             // Set range modifier for ranged weapons
      sneakPenalty(sneakPen),                              // Set penalty to sneak ability
      restriction(itemRestriction) {                       // Set any restrictions on who can use the item

    // Initialize stat modifiers from the provided array
    for (int i = 0; i < StatCount; ++i) {
        statModifier[i] = modifier[i];                     // Set each stat modifier (e.g., Strength, Dexterity, etc.) from the input array
    }
}

    // Function to calculate damage based on combat type
    int calculateDamage(int distance) {
        if (combatType == RANGED) {
            return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage); // Call ranged damage calculation
        } else if (combatType == MELEE) {
            return calculateMeleeDamage();            // Call melee damage calculation
        }
        return 0;                                      // Default return if combat type is not applicable
    }

private:
    // Function to calculate damage for ranged weapons based on distance
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {
        // Seed the random generator (only needed once in the game initialization)
        static bool seeded = false;                     // Static variable to track if the generator has been seeded
        if (!seeded) {
            std::srand(std::time(0));                   // Seed the random number generator with the current time
            seeded = true;                              // Mark that the generator has been seeded
        }

        int damage = 0;                                 // Initialize damage to 0

        if (distance == 1) {
            // If the target is right next to the user, reduce the damage range by 1
            damage = std::max((std::rand() % (maxDamage - minDamage + 1)) + minDamage - 1, 1); // Reduce min and max by 1, ensure minimum is 1
        } else if (distance <= maxRange) {
            // If the target is within regular range, roll for damage between minDamage and maxDamage
            damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage; // Roll damage within normal range
        } else {
            // If the target is beyond the range max
            damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage; // Start with damage within normal range
            damage -= (distance - maxRange); // Reduce damage for each square beyond max range
            damage = std::max(damage, 1);    // Ensure minimum damage of 1
        }

        return damage;                       // Return calculated damage
    }

    // Function to calculate damage for melee weapons (simplified logic)
    int calculateMeleeDamage() {
        // Seed the random generator (only needed once in the game initialization)
        static bool seeded = false;                     // Static variable to track if the generator has been seeded
        if (!seeded) {
            std::srand(std::time(0));                   // Seed the random number generator with the current time
            seeded = true;                              // Mark that the generator has been seeded
        }

        // Simple melee damage calculation between minDamage and maxDamage
        return (std::rand() % (maxDamage - minDamage + 1)) + minDamage; // Roll damage within min and max range
    }
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

//-------------------------DECLARE FUNCTION PROTOTYPES----------
void initializeGameItems(std::vector<Item>& gameItems);  // Function to initialize game items
void printStrobingText(const std::string& text, int duration); // Function to print strobing text effect for title
bool confirmClassChoice();                                // Function to confirm player's class choice
bool equipItem(Player& player, int itemIndex);            // Function to equip an item from player's inventory
bool unequipItem(Player& player, int itemIndex);          // Function to unequip an item from player's equipped items
void displayClasses(Player& player);                      // Function to display available character classes and handle selection
std::string getPlayerName();                              // Function to get the player's name
void runGameLoop(Player& player);                         // Function to run the main game loop

#endif // GAMEHEADERELI_H