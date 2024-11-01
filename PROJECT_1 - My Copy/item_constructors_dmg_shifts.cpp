// item_constructors_dmg_shifts.cpp
#include "GameHeaderEli.h"

// Default constructor for Item
Item::Item()
    : name(""),                                                     // Set item name to an empty string by default
      flavorDescription(""),                                        // Set flavor description to an empty string by default
      classification(MAGICAL),                                      // Default classification is MAGICAL
      combatType(MELEE),                                            // Default combat type is MELEE
      minDamage(0),                                                 // Set minimum damage to 0 by default
      maxDamage(0),                                                 // Set maximum damage to 0 by default
      rangeModifier(0),                                             // Set range modifier to 0 by default
      sneakPenalty(0),                                              // Set sneak penalty to 0 by default
      magPowModifier(0),                                            // Set magic power modifier to 0 by default
      ability(""),                                                  // Set ability description to an empty string by default
      restriction("") {                                             // Set restriction to an empty string by default

    std::fill(std::begin(statModifier), std::end(statModifier), 0); // Set all stat modifiers to 0 by default
}

// Parameterized constructor for Item
Item::Item(std::string itemName, std::string itemFlavorDescription, ItemType itemClassification,
           CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
           int minDmg, int maxDmg, int rangeMod, int sneakPen, int magPowMod, std::string itemRestriction)
    : name(itemName),                                               // Initialize item name with the provided value
      flavorDescription(itemFlavorDescription),                     // Initialize item flavor description
      classification(itemClassification),                           // Set item classification (MAGICAL, CLOTHING, WEAPON)
      combatType(itemCombatType),                                   // Set combat type (MELEE or RANGED)
      minDamage(minDmg),                                            // Set minimum damage for the item
      maxDamage(maxDmg),                                            // Set maximum damage for the item
      rangeModifier(rangeMod),                                      // Set range modifier for ranged weapons
      sneakPenalty(sneakPen),                                       // Set penalty to sneak ability
      magPowModifier(magPowMod),                                    // Set magic power modifier
      ability(itemAbility),                                         // Set special ability description
      restriction(itemRestriction) {                                // Set any restrictions on who can use the item

    std::copy(modifier.begin(), modifier.end(), statModifier);      // Copy stat modifiers from provided array
}

// Function to calculate damage based on combat type
int Item::calculateDamage(int distance) {
    if (combatType == RANGED) {
        return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage);  //@LINE 51      // Call ranged damage calculation
    } else if (combatType == MELEE) {
        return calculateMeleeDamage();                                                //@LINE 70      // Call melee damage calculation
    }
    return 0;                                                                               // Default return 0 if combat type N/A
}

// function to calculate damage for ranged weapons based on distance
int Item::calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {
    int damage = 0;                                                                         // Initialize damage to 0

    if (distance == 1) {
        damage = std::max((std::rand() % (maxDamage - minDamage + 1)) + minDamage - 1, 1);  // Reduce min and max by 1, ensure minimum is 1
    
    } else if (distance <= maxRange) {
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;                   // Roll damage within normal range
   
    } else {
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;                   // Start with damage within normal range
        damage -= (distance - maxRange);                                                    // Reduce damage each square beyond max range
        damage = std::max(damage, 1);                                                       // Ensure minimum damage of 1
    }

    return damage;                                                                          // Return calculated damage
}

// Private function to calculate damage for melee weapons
int Item::calculateMeleeDamage() {
    return (std::rand() % (maxDamage - minDamage + 1)) + minDamage;                         // Roll damage within min and max range
}
