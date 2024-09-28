//gameItems.cpp
#include "GameHeaderEli.h"             // Include necessary headers containing class definitions and enums


// Function to initialize items in the game
void initializeGameItems(std::vector<Item>& gameItems) {

    //-----------------------FORMAT FOR CREATING NEW GAME ITEMS-------------------
    /* // NAME OF ITEM - ITEM CLASSIFICATION
    Item [ITEM CODENAME]("ACTUAL ITEM NAME",                             // Item name
                       "THIS IS WHAT DESCRIBES THE ITEM",                // Item description
                       CLASSIFICATION OF ITEM (WEAPON, WEARABLE, MAGIC), // Classification: (WEAPON, WEARABLE, MAGIC)
                       COMBAT TYPE IF WEAPON (RANGED, MELEE),            // Combat type (not applicable, default to MELEE)
                       {STR, DEX, INTEL, WISD, CONSTI},                  // Stat modifiers: + VALUE TO STAT IN INDEX POSITION
                       "+2 Wisdom, 10 PERCENT Experience boost.");       // Ability description EXAMPLE
    gameItems.push_back(ITEM CODENAME);                                  // Add [ACTUAL ITEM NAME] to game items list
    */
    //----------------------------------------------------------------------------

    //---------------------------------------------ITEM GLOSSARY---------------------------

    // Ring of Insight - Magical Item
    Item ringOfInsight("Ring of Insight",                             // Item name
                       "A mystical ring that enhances mental acuity.", // Item description
                       MAGICAL,                                       // Classification: Magical
                       MELEE,                                         // Combat type (not applicable, default to MELEE)
                       {0, 0, 0, 2, 0},                               // Stat modifiers: +2 Wisdom, others 0
                       "+2 Wisdom, 5 percent Experience boost.");     // Ability description
    gameItems.push_back(ringOfInsight);                               // Add ring of insight to game items list

    // Amulet of Minor Healing - Magical Item
    Item amuletMinorHealing("Amulet of Minor Healing",                // Item name
                            "Heals 6 health chips per day.",          // Item description
                            MAGICAL,                                  // Classification: Magical
                            MELEE,                                    // Combat type (not applicable, default to MELEE)
                            {0, 0, 0, 0, 2},                          // Stat modifiers: +2 Constitution, others 0
                            "+2 Constitution, passive healing effect."); // Ability description
    gameItems.push_back(amuletMinorHealing);                          // Add amulet of minor healing to game items list

    // Bracers of Thunderstrike - Clothing Item
    Item bracersThunderstrike("Bracers of Thunderstrike",             // Item name
                              "Bracers that amplify strength but increase spell cost.", // Item description
                              CLOTHING,                               // Classification: Clothing
                              MELEE,                                  // Combat type (not applicable, default to MELEE)
                              {2, 0, 0, 0, 0},                        // Stat modifiers: +2 Strength, others 0
                              "+2 Strength, +25 percent Spell Cost Increase."); // Ability description
    gameItems.push_back(bracersThunderstrike);                        // Add bracers of thunderstrike to game items list

    // Helm of the Resolute - Clothing Item
    Item helmResolute("Helm of the Resolute",                         // Item name
                      "A helm that provides substantial defense.",    // Item description
                      CLOTHING,                                       // Classification: Clothing
                      MELEE,                                          // Combat type (not applicable, default to MELEE)
                      {0, 0, 0, 0, 3},                                // Stat modifiers: +3 Constitution, others 0
                      "+3 Constitution, +4 RESISTANCE (MAG, CLEAR, STUN).", // Ability description
                      0,                                              // Minimum damage
                      0,                                              // Maximum damage
                      0,                                              // Range modifier
                      0,                                              // Sneak penalty
                      "Warrior, Rogue, Ranger Only");                 // Restriction
    gameItems.push_back(helmResolute);                                // Add helm of the resolute to game items list

    // Cloak of the Wind Aspect - Clothing Item
    Item cloakWindAspect("Cloak of the Wind Aspect",                  // Item name
                         "A lightweight cloak that improves agility.", // Item description
                         CLOTHING,                                    // Classification: Clothing
                         MELEE,                                       // Combat type (not applicable, default to MELEE)
                         {0, 2, 0, 0, 0},                             // Stat modifiers: +2 Dexterity, others 0
                         "+2 Dexterity, +1 to Dodge chance.");        // Ability description
    gameItems.push_back(cloakWindAspect);                             // Add cloak of the wind aspect to game items list

    // Bow of the Windbreaker - Ranged Weapon Item
    Item bowWindbreaker("Bow of the Windbreaker",                     // Item name
                        "A bow that improves range and dexterity, but comes with an amusing effect.", // Item description
                        WEAPON,                                       // Classification: Weapon
                        RANGED,                                       // Combat type: Ranged
                        {0, 3, 0, 0, 0},                              // Stat modifiers: +3 Dexterity, others 0
                        "+3 Dexterity, increases range and accuracy. Arrows make farting noise when fired (-4 Sneak/Hide).",
                        2,                                            // Minimum damage
                        7,                                            // Maximum damage
                        3,                                            // Range modifier for ranged weapons
                        -4);                                          // Sneak penalty when using the bow
    gameItems.push_back(bowWindbreaker);                              // Add bow of the windbreaker to game items list

    // Dagger of the Quickstrike - Melee Weapon Item
    Item daggerQuickstrike("Dagger of the Quickstrike",              // Item name
                           "A dagger with enhanced speed.",          // Item description
                           WEAPON,                                   // Classification: Weapon
                           MELEE,                                    // Combat type: Melee
                           {0, 2, 0, 0, 0},                          // Stat modifiers: +2 Dexterity, others 0
                           "+2 Dexterity, 5% chance to attack twice in a turn.",
                           2,                                        // Minimum damage
                           6);                                       // Maximum damage
    gameItems.push_back(daggerQuickstrike);                          // Add dagger of the quickstrike to game items list

    // Add additional items similarly...
}
