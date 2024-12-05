#ifndef ITEM_CONSTRUCTORS_DMG_SHIFTS_H
#define ITEM_CONSTRUCTORS_DMG_SHIFTS_H
//Item_constructors_dmg_shifts.h
#include <string>                                                     // For std::string
#include <array>                                                      // For std::array
#include <random>                                                     // For random number generation

// Define StatCount for the number of stats
#define StatCount 5

// Enum for item types (Weapon, Magical, Clothing)
enum ItemType { WEAPON, MAGICAL, CLOTHING };

// Enum for combat types (Melee, Ranged)
enum CombatType { MELEE, RANGED };

// Item class declaration
class Item {
public:
    // Attributes
    std::string name;                                                // Name of the item
    std::string flavorDescription;                                     // Flavor description of the item
    ItemType classification;                                           // Item classification (e.g., WEAPON, MAGICAL)
    CombatType combatType;                                             // Combat type (MELEE or RANGED)
    int statModifier[StatCount];                                       // Stat modifiers for the item
    int minDamage;                                                    // Minimum damage for weapons
    int maxDamage;                                                    // Maximum damage for weapons
    int rangeModifier;                                                // Range modifier for ranged weapons
    int sneakPenalty;                                                 // Penalty to sneak when using the item
    int magPowModifier;                                               // Magic power modifier
    std::string ability;                                               // Special ability description
    std::string restriction;                                           // Restriction on who can use the item
    int regenerationRate;                                              // HP regeneration rate for the item

    // Constructors
    Item();                                                            // Default constructor
    Item(std::string itemName, std::string itemFlavorDescription, ItemType itemClassification,
         CombatType itemCombatType, const std::array<int, StatCount>& modifier, std::string itemAbility,
         int minDmg, int maxDmg, int rangeMod, int sneakPen, int magPowMod, std::string itemRestriction, int regenRate); // Parameterized constructor

    // Accessors and Mutators
    std::string getName() const;                                        // Get the item's name
    void setName(const std::string &itemName);                          // Set the item's name
    int getRegenerationRate() const;                                    // Get the regeneration rate
    void setRegenerationRate(int rate);                                 // Set the regeneration rate

    // Damage calculation logic
    int calculateDamage(int distance);                                  // Calculate damage based on combat type

private:
    // Private helper functions for damage calculation
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage); // Calculate ranged damage
    int calculateMeleeDamage();                                          // Calculate melee damage
};

// Helper function to perform random roll for damage calculation
int randomRoll(int min, int max);

#endif // ITEM_CONSTRUCTORS_DMG_SHIFTS_H
