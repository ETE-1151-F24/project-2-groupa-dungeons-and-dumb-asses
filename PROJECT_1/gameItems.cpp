//gameItems.cpp
#include "GameHeaderEli.h"             // Include necessary headers containing class definitions and enums



//----------------------------------Helper function to add an item to the game
void addItem(std::vector<Item>& gameItems, const std::string& itemName, const std::string& itemDescription,
             ItemType classification, CombatType combatType, const std::array<int, StatCount>& statModifiers,
             const std::string& abilityDescription, int minDamage, int maxDamage, int rangeModifier,
             int sneakPenalty, int magicPowerModifier, const std::string& restriction) {
    
    Item newItem(itemName, itemDescription, classification, combatType, statModifiers,
                 abilityDescription, minDamage, maxDamage, rangeModifier,
                 sneakPenalty, magicPowerModifier, restriction);
    gameItems.push_back(newItem);
}


// Function to initialize items in the game
void initializeGameItems(std::vector<Item>& gameItems) {
    gameItems.clear();  // Clear any existing items

    //---------------------------------------------ITEM GLOSSARY---------------------------
    
 /*   // Add a new item to the game
    addItem(gameItems, "ACTUAL ITEM NAME",                             // Item name
            "THIS IS WHAT DESCRIBES THE ITEM",                         // Item description
            ITEM_TYPE,                                                 // Classification: WEAPON, CLOTHING, MAGIC, etc.
            COMBAT_TYPE,                                               // Combat type: RANGED, MELEE (not applicable for non-weapons, default to MELEE)
            {STR, DEX, INTEL, WISD, CONSTI},                           // Stat modifiers: Strength, Dexterity, Intelligence, Wisdom, Constitution
            "Ability description goes here, e.g., +3 Constitution, +4 RESISTANCE (MAG, CLEAR, STUN).", // Ability description
            MIN_DAMAGE,                                                // Minimum damage (default value is 0)
            MAX_DAMAGE,                                                // Maximum damage (default value is 0)
            RANGE_MODIFIER,                                            // Range modifier (default value is 0)
            SNEAK_PENALTY,                                             // Sneak penalty (default value is 0)
            MAGIC_POWER_MODIFIER,                                      // Magic power modifier (default value is 0)
            "Restrictions to class go here, e.g., Mage, Cleric Only"); // Restriction (default value is "No restriction")
*/


    // ---------- Magical Items ----------
    addItem(gameItems, "Ring of Insight",                               // Item name
            "A mystical ring that enhances mental acuity.",            // Item description
            MAGICAL,                                                   // Classification: Magical
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 2, 2, 0},                                           // Stat modifiers: +2 Wisdom, others 0
            "+2 Wisdom, +2 intelligence, 10 percent Experience boost.",// Ability description
            0,                                                         // Minimum damage
            0,                                                         // Maximum damage
            0,                                                         // Range modifier
            0,                                                         // Sneak penalty
            0,                                                         // Magic power modifier
            "No restriction");                                         // Restriction

    addItem(gameItems, "Amulet of Minor Healing",                      // Item name
            "Heals 6 health chips per day.",                           // Item description
            MAGICAL,                                                   // Classification: Magical
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 0, 0, 2},                                           // Stat modifiers: +2 Constitution, others 0
            "+2 Constitution, heal self 6 once a day.",                // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction");                                         // Restriction (default value)

    // ---------- Clothing Items ----------
    addItem(gameItems, "Bracers of Thunderstrike",                     // Item name
            "Bracers that amplify strength but increase spell cost.",  // Item description
            CLOTHING,                                                  // Classification: Clothing
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {1, 0, 0, 0, 2},                                           // Stat modifiers: +2 Strength, others 0
            "+1 Strength, +2 constitution, +20 percent chance to stun, +25 percent Spell Cost Increase.",           // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction");                                         // Restriction (default value)

    addItem(gameItems, "Helm of the Resolute",                         // Item name
            "A helm that provides substantial defense.",               // Item description
            CLOTHING,                                                  // Classification: Clothing
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 0, 0, 3},                                           // Stat modifiers: +3 Constitution, others 0
            "+3 Constitution, +1 RESISTANCE (magic, elemental, stun).",// Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "Warrior, Rogue, Ranger Only");                            // Restriction

    addItem(gameItems, "Cloak of the Wind Dancer",                     // Item name
            "A lightweight cloak that improves agility.",              // Item description
            CLOTHING,                                                  // Classification: Clothing
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {0, 2, 0, 0, 0},                                           // Stat modifiers: +2 Dexterity, others 0
            "+2 Dexterity, +1 to Dodge chance.",                       // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction");                                         // Restriction (default value)

    // ---------- Weapon Items ----------
    addItem(gameItems, "Bow of the Windbreaker",                       // Item name
            "A bow that improves range and dexterity, but comes with an amusing effect.", // Item description
            WEAPON,                                                    // Classification: Weapon
            RANGED,                                                    // Combat type: Ranged
            {0, 3, 0, 0, 0},                                           // Stat modifiers: +3 Dexterity, others 0
            "+3 Dexterity, increases range and accuracy. Arrows make farting noise when fired (-4 Sneak/Hide).", // Ability description
            2,                                                         // Minimum damage
            7,                                                         // Maximum damage
            3,                                                         // Range modifier
            -4,                                                        // Sneak penalty
            0,                                                         // Magic power modifier (default value)
            "No restriction");                                         // Restriction (default value)

    addItem(gameItems, "Dagger of the Quickstrike",                    // Item name
            "A dagger with enhanced speed.",                           // Item description
            WEAPON,                                                    // Classification: Weapon
            MELEE,                                                     // Combat type: Melee
            {0, 2, 0, 0, 0},                                           // Stat modifiers: +2 Dexterity, others 0
            "+2 Dexterity, 5% chance to attack twice in a turn.",      // Ability description
            2,                                                         // Minimum damage
            6,                                                         // Maximum damage
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction");                                         // Restriction (default value)

    addItem(gameItems, "Staff of the Mystic Mist",                     // Item name
            "A staff that grants some range and dodging.",             // Item description
            WEAPON,                                                    // Classification: Weapon
            MELEE,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 1, 0, 0},                                           // Stat modifiers: +1 Intelligence, others 0
            "+2 Intelligence, +2 Magic power, +1 Range.",              // Ability description
            1,                                                         // Minimum damage
            6,                                                         // Maximum damage
            1,                                                         // Range modifier
            0,                                                         // Sneak penalty (default value)
            2,                                                         // Magic power modifier
            "Mage, Cleric Only");                                      // Restriction

 /*   // Add a new item to the game
    addItem(gameItems, "ACTUAL ITEM NAME",                             // Item name
            "THIS IS WHAT DESCRIBES THE ITEM",                         // Item description
            ITEM_TYPE,                                                 // Classification: WEAPON, CLOTHING, MAGIC, etc.
            COMBAT_TYPE,                                               // Combat type: RANGED, MELEE (not applicable for non-weapons, default to MELEE)
            {STR, DEX, INTEL, WISD, CONSTI},                           // Stat modifiers: Strength, Dexterity, Intelligence, Wisdom, Constitution
            "Ability description goes here, e.g., +3 Constitution, +4 RESISTANCE (MAG, CLEAR, STUN).", // Ability description
            MIN_DAMAGE,                                                // Minimum damage (default value is 0)
            MAX_DAMAGE,                                                // Maximum damage (default value is 0)
            RANGE_MODIFIER,                                            // Range modifier (default value is 0)
            SNEAK_PENALTY,                                             // Sneak penalty (default value is 0)
            MAGIC_POWER_MODIFIER,                                      // Magic power modifier (default value is 0)
            "Restrictions to class go here, e.g., Mage, Cleric Only"); // Restriction (default value is "No restriction")
*/

    // Additional items can be added in the same format as needed...
}

 /*
    Example for adding new items:

 /*   // Add a new item to the game
    addItem(gameItems, "ACTUAL ITEM NAME",                             // Item name
            "THIS IS WHAT DESCRIBES THE ITEM",                         // Item description
            ITEM_TYPE,                                                 // Classification: WEAPON, CLOTHING, MAGIC, etc.
            COMBAT_TYPE,                                               // Combat type: RANGED, MELEE (not applicable for non-weapons, default to MELEE)
            {STR, DEX, INTEL, WISD, CONSTI},                           // Stat modifiers: Strength, Dexterity, Intelligence, Wisdom, Constitution
            "Ability description goes here, e.g., +3 Constitution, +4 RESISTANCE (MAG, CLEAR, STUN).", // Ability description
            MIN_DAMAGE,                                                // Minimum damage (default value is 0)
            MAX_DAMAGE,                                                // Maximum damage (default value is 0)
            RANGE_MODIFIER,                                            // Range modifier (default value is 0)
            SNEAK_PENALTY,                                             // Sneak penalty (default value is 0)
            MAGIC_POWER_MODIFIER,                                      // Magic power modifier (default value is 0)
            "Restrictions to class go here, e.g., Mage, Cleric Only"); // Restriction (default value is "No restriction")
*/
    // Example usage:
    // addItem(gameItems, "Sword of Valor", "A powerful sword infused with magic.", WEAPON, MELEE, {3, 0, 0, 0, 1}, "+3 Strength, +1 Constitution", 5, 10, 0, 0, 0, "Warrior Only");
*/





