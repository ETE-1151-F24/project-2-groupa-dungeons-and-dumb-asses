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
    return false;                                                               // Return false if no weapon is found
}

//---------------------------- Constructor for Player - Takes player's name, class, and optional start level
Player::Player(std::string playerName, std::string charClass, int startLevel)
    : name(playerName),                                                         // Initialize player's name with the provided name
      characterClass(charClass),                                                // Set player's character class (e.g., cleric, ranger, etc.)
      level(startLevel),                  // Set player's level
      experience(0),                      // Initialize experience points to 0
      stats{},                            // Default initialize stats to zero
      abilitiesMenu{},                    // Default initialize abilities menu (empty vector)
      equippedItems{},                    // Default initialize equipped items (empty vector)
      inventory{}                         // Default initialize inventory (empty vector)
{
    // The stats array is explicitly default-initialized, meaning all values are set to zero.
}

//------------------------------ FUNCTION TO GET PLAYER NAME ------------------------------
std::string getPlayerName() {
    std::string playerName;                                                                     // Variable to store player's name
    std::cout << "Enter your character's name: ";                                               // Prompt the user for their character's name
    std::getline(std::cin, playerName);                                                         // Get the full name input including spaces

    return playerName;                                                                          // Return the player's name to be used in the game
}
//----------------------------------------------------------------------------------------------

// ------------------------------Function to show class description and stat focus based on the player's selection
void showClassDescription(int classChoice) {
    switch (classChoice) {
        case 1:
            std::cout << "Warrior: A strong melee fighter, excels in physical combat with high strength and constitution.\n";
            std::cout << "Stat focus: Strength and Constitution.\n";
            break;
        case 2:
            std::cout << "Rogue: A dexterous thief with stealth and agility, excelling in quick strikes and critical hits.\n";
            std::cout << "Stat focus: Dexterity and Intelligence.\n";
            break;
        case 3:
            std::cout << "Mage: A master of the arcane arts, casting powerful spells with high intelligence and wisdom.\n";
            std::cout << "Stat focus: Intelligence and Wisdom.\n";
            break;
        case 4:
            std::cout << "Cleric: A divine healer and protector, wielding holy magic to heal and protect allies and auras to damage enemies.\n";
            std::cout << "Stat focus: Wisdom and Constitution.\n";
            break;
        case 5:
            std::cout << "Ranger: A skilled marksman and survivalist, excelling in ranged combat and nature-based magic.\n";
            std::cout << "Stat focus: Dexterity and Wisdom.\n";
            break;
        default:
            std::cout << "Invalid class selection.\n";  // Handle invalid class numbers
            break;
    }
}


//--------------------------------- FUNCTION TO DISPLAY CLASSES ----------------------------
void displayClasses(Player& player) {
    std::cout << "\nAvailable Classes:\n"
              << "1. Warrior\n"
              << "2. Rogue\n"
              << "3. Mage\n"
              << "4. Cleric\n"
              << "5. Ranger\n";  // Display available classes with numeric options

    int classChoice;

    while (true) {
        std::cout << "Please enter the number corresponding to your class: ";  // Prompt user to enter the class choice
        std::cin >> classChoice;

        // Check for invalid input (non-numeric input)
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;  // Restart the loop to ask for input again
        }

        // Ignore any extra input after a valid number
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (classChoice >= 1 && classChoice <= 5) {
            showClassDescription(classChoice);  // Character_develop_functs.cpp (this file) LINES 41-67    //Display the class description based on player choice

            // Confirm class choice
            std::string confirmation;
            while (true) {
                std::cout << "Does this kinda sound like your jam? (yes/no): ";
                std::getline(std::cin, confirmation);
                std::transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower);  // Normalize input

                if (confirmation == "yes") {
                    // Assign chosen class to player's characterClass attribute
                    switch (classChoice) {
                        case 1: player.characterClass = "warrior"; break;
                        case 2: player.characterClass = "rogue"; break;
                        case 3: player.characterClass = "mage"; break;
                        case 4: player.characterClass = "cleric"; break;
                        case 5: player.characterClass = "ranger"; break;
                    }
                    std::cout << "Great! You are now a " << player.characterClass << ".\n";  // Confirm player choice
                    break;
                } else if (confirmation == "no") {
                    std::cout << "Let's choose a class again.\n";  // Allow user to choose again
                    break;  // Exit the confirmation loop to select again
                } else {
                    std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";  // Handle invalid input
                }
            }

            if (confirmation == "yes") {
                break;  // Exit loop after confirming the class choice
            }
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";  // Handle invalid input
        }
    }

    // Roll initial stats and finalize
    player.finalizeStats();  // Call function to roll and finalize stats
}
//------------------------------------------------------------------------------------------



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
int Player::roll(int minValue, int maxValue) {              //
    return rand() % (maxValue - minValue + 1) + minValue;  // Random value between minValue and maxValue (inclusive)
}




// ----------------------------------------- Function to display player's stats -----------------------------------------
void Player::showStats() const {
    std::cout << "\n--- Player Stats ---\n";               // Display header for player stats
    std::cout << "Strength: " << stats[Strength] << "\n";  // Display strength stat from the stats array
    std::cout << "Dexterity: " << stats[Dexterity] << "\n";// Display dexterity stat from the stats array
    std::cout << "Intelligence: " << stats[Intelligence] << "\n"; // Display intelligence stat from the stats array
    std::cout << "Wisdom: " << stats[Wisdom] << "\n";      // Display wisdom stat from the stats array
    std::cout << "Constitution: " << stats[Constitution] << "\n"; // Display constitution stat from the stats array
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
    rollStats();                       // Roll stats for the first time       //@character_develop_functs (this file) LINES 132-175            
    showStats();                       // Display the rolled stats            //@character_develop_functs (this file) LINES 188-195

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
            rollStats();   //@character_develop_functs (this file) LINES 132-175                // Roll stats for the final time
            showStats();   //@character_develop_functs (this file) LINES 188-195                // Display the newly rolled stats

            std::cout << "These are your final stats. Looks like we're going to keep these!\n"; // Final confirmation
            break;                                                                              // Exit the loop after the final roll
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";                        // Handle invalid input by displaying an error message
        }
    }
}