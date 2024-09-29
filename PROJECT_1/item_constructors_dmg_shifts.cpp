//item_constructors_dmg_shifts.cpp
#include "GameHeaderEli.h"

// Default constructor for Item
Item::Item()
    : name(""),                                         // Initialize name as an empty string
      description(""),                                  // Initialize description as an empty string
      classification(MAGICAL),                          // Default classification is MAGICAL
      combatType(MELEE),                                // Default combat type is MELEE
      minDamage(0),                                     // Default minimum damage is 0
      maxDamage(0),                                     // Default maximum damage is 0
      rangeModifier(0),                                 // Default range modifier is 0
      sneakPenalty(0),                                  // Default sneak penalty is 0
      magPowModifier(0),                                // Default magic power modifier is 0
      ability(""),                                      // Initialize ability as an empty string
      restriction(""),                                  // Initialize restriction as an empty string
      isPlaceholder(false),                             // Initialize placeholder as false
      statusMessage("") {                               // Initialize statusMessage as an empty string

    std::fill(std::begin(statModifier), std::end(statModifier), 0);        // Set all stat modifiers to 0 by default
}

// Parameterized constructor for Item
Item::Item(std::string itemName, std::string itemDescription, ItemType itemClassification,
           CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
           int minDmg, int maxDmg, int rangeMod, int sneakPen, int magPowMod, std::string itemRestriction)
    : name(itemName),                                      // Initialize item name
      description(itemDescription),                        // Initialize item description
      classification(itemClassification),                  // Set item classification (MAGICAL, CLOTHING, WEAPON)
      combatType(itemCombatType),                          // Set combat type (MELEE or RANGED)
      minDamage(minDmg),                                   // Set minimum damage for the item
      maxDamage(maxDmg),                                   // Set maximum damage for the item
      rangeModifier(rangeMod),                             // Set range modifier for ranged weapons
      sneakPenalty(sneakPen),                              // Set penalty to sneak ability
      magPowModifier(magPowMod),                           // Set magic power modifier
      ability(itemAbility),                                // Set special ability description
      restriction(itemRestriction),                        // Set any restrictions on item use
      isPlaceholder(false),                                // Initialize placeholder as false
      statusMessage("") {                                  // Initialize statusMessage as empty

    std::copy(modifier.begin(), modifier.end(), statModifier);             // Copy stat modifiers from the provided array
}

// Function to calculate damage based on combat type
int Item::calculateDamage(int distance) {
    if (combatType == RANGED) {
        return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage);     // Call ranged damage calculation
    } else if (combatType == MELEE) {
        return calculateMeleeDamage();                              // Call melee damage calculation
    }
    return 0;                                                       // Default return 0 if combat type is not applicable
}

// Private function to calculate damage for ranged weapons based on distance
int Item::calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {
    int damage = 0;                                                 // Initialize damage to 0

    if (distance == 1) {
        damage = std::max((std::rand() % (maxDamage - minDamage + 1)) + minDamage - 1, 1);  // Reduce min and max by 1, ensure minimum is 1
    } else if (distance <= maxRange) {
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;                   // Roll damage within normal range
    } else {
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;                   // Start with damage within normal range
        damage -= (distance - maxRange);                                                    // Reduce damage for each square beyond max range
        damage = std::max(damage, 1);                                                       // Ensure minimum damage of 1
    }

    return damage;                                                                          // Return calculated damage
}

// Private function to calculate damage for melee weapons
int Item::calculateMeleeDamage() {
    return (std::rand() % (maxDamage - minDamage + 1)) + minDamage;  // Roll damage within min and max range
}

// Function to mark an item as a placeholder
void Item::markAsPlaceholder() {
    isPlaceholder = true;                                           // Set isPlaceholder attribute to true
    statusMessage = "This item is currently equipped and cannot be used."; // Set status message for placeholder
    name = "Placeholder: " + name + " (equipped)";                  // Update the name to reflect placeholder status
}
