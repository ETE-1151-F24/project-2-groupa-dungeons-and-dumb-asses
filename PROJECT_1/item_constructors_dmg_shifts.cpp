// item_constructors_dmg_shifts.cpp
#include "GameHeaderEli.h"


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
} // Removed the semicolon after the closing brace

//---------------------------------------Parameterized constructor for Item------------------------------------------
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
} // Removed the semicolon after the closing brace
// -------------------------------------Function to calculate damage based on combat type---------------------------

int Item::calculateDamage(int distance) {
    if (combatType == RANGED) {
        return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage); // Call ranged damage calculation
    } else if (combatType == MELEE) {
        return calculateMeleeDamage();   // Call melee damage calculation
    }
    return 0;                            // Default return [melee] if combat type is not applicable
}

//----------------------------Private function to calculate damage for ranged weapons based on distance
int Item::calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {

    int damage = 0;                       // Initialize damage to 0

    if (distance == 1) {
//If the target is right next to the user, reduce the damage range by 1
        damage = std::max((std::rand() % (maxDamage - minDamage + 1)) + minDamage - 1, 1);
                                                                                        // Reduce min and max by 1, ensure minimum is 1
    } else if (distance <= maxRange) {
                                                                                        //If the target is within regular range, 
                                                                                        //roll for damage between [minDamage] and [maxDamage]
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;               //Roll damage within normal range
    } else {
//If the target is beyond the range max
        damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;               //Start with damage within normal range
        damage -= (distance - maxRange);                                                //Reduce damage for each square beyond max range
        damage = std::max(damage, 1);                                                   //Ensure minimum damage of 1
    }

    return damage;                                                                      // Return calculated damage
}

//-------------------------------Private function to calculate damage for melee weapons (simplified logic)----------------
int Item::calculateMeleeDamage() {

    // Simple melee damage calculation between minDamage and maxDamage
    return (std::rand() % (maxDamage - minDamage + 1)) + minDamage; // Roll damage within min and max range
}