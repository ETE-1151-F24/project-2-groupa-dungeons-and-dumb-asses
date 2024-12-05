#ifndef CHARACTER_DEVELOP_FUNCTS_H
#define CHARACTER_DEVELOP_FUNCTS_H
#include "Game_inventory_functions.h"
#include "GameHeaderEli.h"  // Include the necessary base classes and libraries
//Character_develop_functs.h
// Define the Player class and its methods

void displayClasses(const Player& player);                                // Function to display available character classes and handle selection



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
    HealthModifiers healthModifiers;                                // Health modifiers for the player
    int totalRegenerationRate = 0;                                  // Total HP regeneration from equipped items
    int currentHealth = 8;                                          // Current health of the player
    int maxHealth = 8;                                              // Maximum health of the player
    std::vector<std::string> learnedSpells;                         // Spells the player has learned
    std::vector<nlohmann::json> spells;                             // Known spells for the player

    // Constructor
    Player(std::string playerName, std::string charClass, int startLevel = 1);

    // Function Declarations
    void rollStats();                                               // Roll stats based on the character class
    void finalizeStats();                                           // Finalize the stats after the roll
    void showStats() const;                                         // Display player's stats
    void showEquippedItems() const;                                 // Display equipped items
    void applyRegeneration();                                       // Apply regeneration based on equipped items

    // Equipment management
    bool isEquipped(const Item& item) const;                        // Check if an item is equipped
    void equipItem(Item* item);                                     // Equip an item using a pointer
    void unequipItem(Item* item);                                   // Unequip an item using a pointer
    bool hasEquippedWeapon() const;                                 // Check if a weapon is equipped
    void getStats(int S[6], int a) const;                           // Get the player's stats
    void updateStats(const Item& item, bool isEquipping);           // Update player stats based on equipped items

    // Spell management
    void displaySpells() const;                                     // Display learned spells
    void learnSpell(const std::string& spellName);                  // Learn a new spell

private:
    int roll(int minValue, int maxValue);                           // Roll a stat within a range
};

#endif // CHARACTER_DEVELOP_FUNCTS_H
