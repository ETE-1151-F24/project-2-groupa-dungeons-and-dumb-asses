#include "GameHeaderEli.h"                     // Include game-specific headers containing class definitions and enums
#include <algorithm>                           // Required for std::fill and std::copy
#include <cstdlib>                             // Required for random number generation (rand())
#include <ctime>                               // Required for seeding random number generation (time)

// Default constructor for Item
Item::Item() 
    : name(""),                                // Set item name to an empty string by default
      description(""),                         // Set description to an empty string by default
      ability(""),                             // Set ability to an empty string by default
      classification(MAGICAL),                 // Default classification is MAGICAL
      combatType(MELEE),                       // Default combat type is MELEE
      minDamage(0),                            // Set minimum damage to 0 by default
      maxDamage(0),                            // Set maximum damage to 0 by default
      rangeModifier(0),                        // Set range modifier to 0 by default
      sneakPenalty(0),                         // Set sneak penalty to 0 by default
      restriction("") {                        // Set restriction to an empty string by default

    std::fill(std::begin(statModifier), std::end(statModifier), 0); // Set all stat modifiers to 0
}

// Parameterized constructor for Item
Item::Item(std::string itemName, std::string itemDescription, ItemType itemClassification,
           CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
           int minDmg, int maxDmg, int rangeMod, int sneakPen, std::string itemRestriction)
    : name(itemName),                                // Initialize item name with the provided value
      description(itemDescription),                  // Initialize item description
      classification(itemClassification),            // Set item classification (MAGICAL, CLOTHING, WEAPON)
      combatType(itemCombatType),                    // Set combat type (MELEE or RANGED)
      ability(itemAbility),                          // Set special ability description
      minDamage(minDmg),                             // Set minimum damage for the item
      maxDamage(maxDmg),                             // Set maximum damage for the item
      rangeModifier(rangeMod),                       // Set range modifier for ranged weapons
      sneakPenalty(sneakPen),                        // Set penalty to sneak ability
      restriction(itemRestriction) {                 // Set any restrictions on who can use the item

    std::copy(modifier.begin(), modifier.end(), statModifier);  // Copy stat modifiers from provided array
}
