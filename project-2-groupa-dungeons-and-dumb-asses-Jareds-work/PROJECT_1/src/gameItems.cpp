// Include necessary header
#include "GameHeaderEli.h"
#include "gameItems.h"
// #include "item_constructors_dmg_shifts.h"
// #include "Character_develop_functs.h"
// // Shorthand variables  use  these for types
// constexpr ItemType           magical         = ItemType::MAGICAL;
// constexpr ItemType           weapon          = ItemType::WEAPON;
// constexpr ItemType           clothing        = ItemType::CLOTHING;
// constexpr CombatType         melee           = CombatType::MELEE;
// constexpr CombatType         ranged          = CombatType::RANGED;



//-------------------------------------------------------------------------------------------
// //---------------------------------- Helper function to add an item to the game
//-------------------------------------------------------------------------------------------
void addItem(std::vector<Item>& gameItems, 
             const std::string& itemName, 
             const std::string& itemDescription,
             ItemType classification, 
             CombatType combatType, 
             const std::array<int, 
             StatCount>& statModifiers,
             const std::string& abilityDescription, 
             int minDamage, 
             int maxDamage, 
             int rangeModifier,
             int sneakPenalty, 
             int magicPowerModifier, 
             const std::string& restriction, 
             int regenRate) {
    
    // Create a new item using the parameterized constructor of Item
    Item newItem(itemName, 
                 itemDescription, 
                 classification, 
                 combatType, 
                 statModifiers,
                 abilityDescription, 
                 minDamage, 
                 maxDamage, 
                 rangeModifier,
                 sneakPenalty, 
                 magicPowerModifier, 
                 restriction, 
                 regenRate);
    gameItems.push_back(newItem);
}


//-------------------------------------------------------------------------------------------
// // Function to initialize items in the game
//-------------------------------------------------------------------------------------------
void initializeGameItems(std::vector<Item>& gameItems) {
    gameItems.clear();  // Clear any existing items

std::array<int, StatCount> statModifiers = {0, 0, 0, 0, 0};  // Initialize with 0s or desired values




//-------------------------------------------------------------------------------------------
//     // ---------- Magical Items ----------
//-------------------------------------------------------------------------------------------
 

    addItem(gameItems, "Ring of Insight",                               // Item name
            "A mystical ring that enhances mental acuity.",            // Item description
            magical,                                                   // Classification: Magical
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 2, 2, 0},                                           // Stat modifiers: +2 Wisdom, others 0
            "+2 Wisdom, +2 intelligence, 10 percent Experience boost.",// Ability description
            0,                                                         // Minimum damage
            0,                                                         // Maximum damage
            0,                                                         // Range modifier
            0,                                                         // Sneak penalty
            0,                                                         // Magic power modifier
            "No restriction",0);                                         // Restriction

    addItem(gameItems, "Amulet of Goodness",                      // Item name
            "Such a warm jewel, it feels cozy.",                           // Item description
            magical,                                                   // Classification: Magical
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 0, 0, 2},                                           // Stat modifiers: +2 Constitution, others 0
            "+2 Constitution, heal self 6 once a day.",                // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction",0);                                         // Restriction (default value)


//-------------------------------------------------------------------------------------------
//     // ---------- Clothing Items ----------
//-------------------------------------------------------------------------------------------
    addItem(gameItems, "Bracers of Blustery Bash",                     // Item name
            "Bracers that amplify strength but increase spell cost.",  // Item description
            clothing,                                                  // Classification: Clothing
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {1, 0, 0, 0, 2},                                           // Stat modifiers: +2 Strength, others 0
            "+1 Strength, +2 constitution, +20percent chance to stun, +25percent Spell Cost Increase.",           // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction",0);                                         // Restriction (default value)

    addItem(gameItems, "Helm of the Resolute",                         // Item name
            "A helm that provides substantial defense.",               // Item description
            clothing,                                                  // Classification: Clothing
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 0, 0, 3},                                           // Stat modifiers: +3 Constitution, others 0
            "+3 Constitution, +1 RESISTANCE (magic, elemental, stun).",// Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "Warrior, Rogue, Ranger Only",0);                            // Restriction

    addItem(gameItems, "Cloak of the Wind Dancer",                     // Item name
            "A lightweight cloak that improves agility.",              // Item description
            clothing,                                                  // Classification: Clothing
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {0, 2, 0, 0, 0},                                           // Stat modifiers: +2 Dexterity, others 0
            "+2 Dexterity, +2 to Dodge.",                              // Ability description
            0,                                                         // Minimum damage (default value)
            0,                                                         // Maximum damage (default value)
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction",
            0);                                         // Restriction (default value)


//-------------------------------------------------------------------------------------------
//     // ---------- Weapon Items ----------
//-------------------------------------------------------------------------------------------
    addItem(gameItems, "Bow of the Windbreaker",                       // Item name
            "A bow that improves range and dexterity, but comes with an amusing effect.", // Item description
            weapon,                                                    // Classification: Weapon
            ranged,                                                    // Combat type: Ranged
            {0, 3, 0, 0, 0},                                           // Stat modifiers: +3 Dexterity, others 0
            "+3 Dexterity, increases range and accuracy. Arrows make farting noise when fired (-4 Sneak/Hide).", // Ability description
            2,                                                         // Minimum damage
            7,                                                         // Maximum damage
            3+(Dexterity/6),                                           // Range modifier
            -4,                                                        // Sneak penalty
            0,                                                         // Magic power modifier (default value)
            "No restriction",0);                                         // Restriction (default value)

    addItem(gameItems, "Dagger of the Quicky-strike",                    // Item name
            "A dagger with enhanced speed.",                           // Item description
            weapon,                                                    // Classification: Weapon
            melee,                                                     // Combat type: Melee
            {0, 2, 0, 0, 0},                                           // Stat modifiers: +2 Dexterity, others 0
            "+2 Dexterity, 10percent chance to attack twice a turn.", // Ability description
            2,                                                         // Minimum damage
            5,                                                         // Maximum damage
            0,                                                         // Range modifier (default value)
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier (default value)
            "No restriction",0);                                         // Restriction (default value)

    addItem(gameItems, "Staff of the Whipering Eye",                     // Item name
            "A staff that grants some range and dodging.",             // Item description
            weapon,                                                    // Classification: Weapon
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {0, 0, 1, 0, 0},                                           // Stat modifiers: 
            "+2 Intelligence, +2 Magic power, +1 Range.",              // Ability description
            1,                                                         // Minimum damage
            6,                                                         // Maximum damage
            1,                                                         // Range modifier
            0,                                                         // Sneak penalty (default value)
            2,                                                         // Magic power modifier
            "Mage, Cleric Only",0);                                      // Restriction

    addItem(gameItems, "Hammer of Emberstrike",                         // Item name
            "A hammer with the power of fire.",                         // Item description
            weapon,                                                    // Classification: Weapon
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {3, 0, -2, 0, 0},                                           // Stat modifiers: str dex int wis con
            "+3 Strength, -2 Dexterity, 10percent chance to Emberstrike, 1d6 fire damage.",   // Ability description
            2,                                                         // Minimum damage
            9,                                                         // Maximum damage
            0,                                                         // Range modifier
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier
            "no restriction....why?",0);                                  // Restriction

    addItem(gameItems, "Sword of the Slicey Way",                         // Item name
            "A very sharp sword.....its a helluva can opener",                         // Item description
            weapon,                                                    // Classification: Weapon
            melee,                                                     // Combat type (not applicable, default to MELEE)
            {2, 0, 0, 0, 0},                                           // Stat modifiers: str dex int wis con
            "+2 Strength, additional Damage to armor clad enemies (strength/6)dmg ",   // Ability description
            2,                                                         // Minimum damage
            5,                                                         // Maximum damage
            0,                                                         // Range modifier
            0,                                                         // Sneak penalty (default value)
            0,                                                         // Magic power modifier
            "none",0);                                  // Restriction
}
