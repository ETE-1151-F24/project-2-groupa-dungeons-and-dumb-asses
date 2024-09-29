// Character_develop_functs.cpp
#include "GameHeaderEli.h"                  // Include the game header file for necessary class definitions and enums

//------------------------------------------ PLAYER CLASS IMPLEMENTATION -------------------------------------------------

// Function to check if the player has a weapon equipped
bool Player::hasEquippedWeapon() const {
    for (const auto* item : equippedItems) {                                    // Iterate through equipped items using pointers
        if (item->classification == WEAPON) {                                   // Check if the item classification is WEAPON
            return true;                                                        // Return true if a weapon is found
        }
    }
    return false;                                          // Return false if no weapon is found
}

//----------------------------------Constructor for Player - Takes player's name, class, and optional start level
Player::Player(std::string playerName, std::string charClass, int startLevel)
    : name(playerName),                                                         // Initialize player's name with the provided name
      characterClass(charClass),                                                // Set player's character class (e.g., cleric, ranger, etc.)
      level(startLevel),                                                        // Set player's level
      experience(0),                                                            // Initialize experience points to 0
      stats{},                                                                  // Default initialize stats to zero
      abilitiesMenu{},                                                          // Default initialize abilities menu (empty vector)
      equippedItems{},                                                          // Default initialize equipped items (empty vector)
      inventory{}                                                               // Default initialize inventory (empty vector)
{
    // stats array default-initialized.... values set to zero.
}

//------------------------------------------Function to roll stats based on character class
void Player::rollStats() {
    // Implementation for rolling stats based on class
    // Example: Rolling each stat based on the player's character class
//-----------------------------------------------------------------------------


// Define stat ranges for each class
    struct StatRange {
        int minValue;                                      // Minimum value for the stat
        int maxValue;                                      // Maximum value for the stat
    };

// Stat ranges for each class           {  STR      DEX     INTEL   WISDOM   CONSTI}
    StatRange warriorStats[StatCount]  = {{9, 20}, {4, 15}, {2, 15}, {2, 13}, {9, 20}}; // Warrior stat ranges
    StatRange rogueStats[StatCount]    = {{5, 13}, {9, 20}, {9, 20}, {4, 15}, {2, 13}}; // Rogue stat ranges
    StatRange mageStats[StatCount]     = {{3, 13}, {4, 13}, {9, 20}, {9, 20}, {2, 13}}; // Mage stat ranges
    StatRange clericStats[StatCount]   = {{3, 13}, {4, 13}, {5, 15}, {9, 20}, {9, 20}}; // Cleric stat ranges
    StatRange rangerStats[StatCount]   = {{5, 13}, {9, 20}, {5, 15}, {9, 20}, {2, 13}}; // Ranger stat ranges
//  StatRange GENERICStats[StatCount]  = {{5, 13}, {9, 20}, {5, 15}, {9, 20}, {2, 13}}; // GENERIC stat ranges
        

    StatRange* selectedStats = nullptr;                                                 //Pointer to the selected stat range array

// Use if-else statements to assign the appropriate stat range based on character class
    if (characterClass == "warrior") {                                                  // If character class is warrior
        selectedStats = warriorStats;                                                   // Assign warrior stat ranges
    } else if (characterClass == "rogue") {                                             // If character class is rogue
        selectedStats = rogueStats;                                                     // Assign rogue stat ranges
    } else if (characterClass == "mage") {                                              // If character class is mage
        selectedStats = mageStats;                                                      // Assign mage stat ranges
    } else if (characterClass == "cleric") {                                            // If character class is cleric
        selectedStats = clericStats;                                                    // Assign cleric stat ranges
    } else if (characterClass == "ranger") {                                            // If character class is ranger
        selectedStats = rangerStats;                                                    // Assign ranger stat ranges
    } else {                                                                            // If character class is unknown
        std::cerr << "Error: Unknown character class '" << characterClass << "'." << std::endl; // Print error message
        return;                                                                         //Exit the function if an invalid class is given
    }

    for (int i = 0; i < StatCount; ++i) {                                               // Roll stats using selected stat range
        stats[i] = roll(selectedStats[i].minValue, selectedStats[i].maxValue);          // Roll stat within the defined range
    }
}

//--------------------------Function to simulate rolling stats within a given range using rand()---------------------
int Player::roll(int minValue, int maxValue) {
    return rand() % (maxValue - minValue + 1) + minValue;  // Random value between minValue and maxValue (inclusive)
}


// ----------------------------------------- Function to display player's stats -----------------------------------------
void Player::showStats() const {
    std::cout << "\n--- Player Stats ---\n";               // Display header for player stats
    std::cout << "Strength: " << stats[Strength] << "\n";  // Display strength stat
    std::cout << "Dexterity: " << stats[Dexterity] << "\n";// Display dexterity stat
    std::cout << "Intelligence: " << stats[Intelligence] << "\n"; // Display intelligence stat
    std::cout << "Wisdom: " << stats[Wisdom] << "\n";      // Display wisdom stat
    std::cout << "Constitution: " << stats[Constitution] << "\n"; // Display constitution stat
}


// ------------------------------------------ Function to display equipped items ----------------------------------------
void Player::showEquippedItems() const {
    std::cout << "\n--- Equipped Items ---\n";             // Display header for equipped items
    if (equippedItems.empty()) {                           // Check if no items are equipped
        std::cout << "No items equipped.\n";               // Print message indicating no items equipped
    } else {
        for (const auto* item : equippedItems) {           // Loop through equipped items using pointers
            std::cout << item->name << ": " << item->flavorDescription << "\n"; // Display item name and flavor description
        }
    }
}


// --------------------------Function to handle rolling stats and allowing player to decide whether to keep or re-roll
void Player::finalizeStats() {
    std::string response;                                                   // Store player's response for confirming or re-rolling stats

    // First roll
    rollStats();                                                                                // Roll stats for the first time
    showStats();                                                                                // Display the rolled stats

// Ask player if they are satisfied with the rolled stats
    while (true) {
        std::cout << "Do you like these stats? (yes/no): ";                                     // Prompt player to confirm if they like the stats
        std::cin >> response;                                                                   // Get player's response
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                     // Clear input buffer
        std::transform(response.begin(), response.end(), response.begin(), ::tolower);          // Convert response to lowercase

        if (response == "yes") {                                                                // If player likes the stats
            std::cout << "Great! We will keep these stats.\n";                                  // Confirm that the stats will be kept
            break;                                                                              // Exit the loop as stats are finalized
        } else if (response == "no") {                                                          // If player does not like the stats
            std::cout << "Alright, we'll give it one more roll.\n";                             // Inform player that a second roll will be given

            // Second roll (final roll)
            rollStats();                                                                        // Roll stats for the final time
            showStats();                                                                        // Display the newly rolled stats

            std::cout << "These are your final stats. Looks like we're going to keep these!\n"; // Final confirmation
            break;                                                                              // Exit the loop after the final roll
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";                        // Handle invalid input by displaying an error message
        }
    }
}
