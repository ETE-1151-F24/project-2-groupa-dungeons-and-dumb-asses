// item_constructors_dmg_shifts.cpp
#include "GameHeaderEli.h"
#include <algorithm> // For std::max
#include <cstdlib>   // For std::rand
#include <random>    // For optional modern random number generation
#include "item_constructors_dmg_shifts.h"

// Default constructor for Item
Item::Item()
    : name(""),                                                     // Set item name to an empty string by default
      flavorDescription(""),                                        // Set flavor description to an empty string by default
      classification(ItemType::MAGICAL),                                      // Default classification is MAGICAL
      combatType(CombatType::MELEE),                                            // Default combat type is MELEE
      minDamage(0),                                                 // Set minimum damage to 0 by default
      maxDamage(0),                                                 // Set maximum damage to 0 by default
      rangeModifier(0),                                             // Set range modifier to 0 by default
      sneakPenalty(0),                                              // Set sneak penalty to 0 by default
      magPowModifier(0),                                            // Set magic power modifier to 0 by default
      ability(""),                                                  // Set ability description to an empty string by default
      restriction(""),                                              // Set restriction to an empty string by default
      regenerationRate(0) {                                         // Set HP regeneration rate to 0 by default
    std::fill(std::begin(statModifier), std::end(statModifier), 0); // Set all stat modifiers to 0 by default
}

// Parameterized constructor for Item
Item::Item(std::string itemName, std::string itemFlavorDescription, ItemType itemClassification,
           CombatType itemCombatType, const std::array<int, StatCount>& modifier, std::string itemAbility,
           int minDmg, int maxDmg, int rangeMod, int sneakPen, int magPowMod, std::string itemRestriction, int regenRate)
    : name(itemName), flavorDescription(itemFlavorDescription), classification(itemClassification),
      combatType(itemCombatType), ability(itemAbility), restriction(itemRestriction),
      minDamage(minDmg), maxDamage(maxDmg), rangeModifier(rangeMod), sneakPenalty(sneakPen),
      magPowModifier(magPowMod), regenerationRate(regenRate) {
    // Copy the stat modifiers from the provided array
    std::copy(modifier.begin(), modifier.end(), statModifier);
}

// Accessors and Mutators
std::string Item::getName() const { 
    return name; 
}

void Item::setName(const std::string &itemName) { 
    name = itemName; 
}

int Item::getRegenerationRate() const { 
    return regenerationRate; 
}

void Item::setRegenerationRate(int rate) { 
    regenerationRate = rate; 
}

// Helper function for rolling random numbers
int randomRoll(int min, int max) {
    static std::random_device rd; // Seed
    static std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Function to calculate damage based on combat type
int Item::calculateDamage(int distance) {
    if (combatType == RANGED) {
        return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage);        // Call ranged damage calculation
    } else if (combatType == MELEE) {
        return calculateMeleeDamage();                                                      // Call melee damage calculation
    }
    return 0;                                                                               // Default return 0 if combat type N/A
}

// Private function to calculate damage for ranged weapons based on distance
int Item::calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {
    int damage = 0;                                                                         // Initialize damage to 0

    if (distance == 1) {                                                                    // Case for adjacent enemies
         damage = std::max(randomRoll(minDamage, maxDamage) - 1, 1);  // Reduce min and max by 1, ensure minimum is 1
    } else if (distance <= maxRange) {                                                     // Within max range
        damage = randomRoll(minDamage, maxDamage);                   // Roll damage within normal range
    } else {                                                                               // Beyond max range
        damage = randomRoll(minDamage, maxDamage);                   // Start with damage within normal range
        damage -= (distance - maxRange);                                                    // Reduce damage for each square beyond max range
        damage = std::max(damage, 1);                                                       // Ensure minimum damage of 1
    }

    return damage;                                                                          // Return calculated damage
}

// Private function to calculate damage for melee weapons
int Item::calculateMeleeDamage() {
    return randomRoll(minDamage, maxDamage);                        // Roll damage within min and max range
}
