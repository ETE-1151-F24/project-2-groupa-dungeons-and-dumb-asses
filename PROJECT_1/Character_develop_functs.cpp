// Character_develop_functs.cpp
#include "GameHeaderEli.h"                  // Include the game header file for necessary class definitions and enums


//------------------------------------------ PLAYER CLASS IMPLEMENTATION -------------------------------------------------

// Method to check if the player has a weapon equipped
bool Player::hasEquippedWeapon() const {
    for (const auto& item : equippedItems) {                // Iterate through all equipped items
        if (item.classification == WEAPON) {                // Check if the item classification is WEAPON
            return true;                                    // Return true if a weapon is found
        }
    }
    return false;                                           // Return false if no weapon is found
}

// Constructor for Player - Takes player's name, class, and optional start level
Player::Player(std::string playerName, std::string charClass, int startLevel)
    : name(playerName),                    // Initialize player's name with the provided name
      characterClass(charClass),           // Set player's character class (e.g., cleric, ranger, etc.)
      level(startLevel),                   // Set player's level
      experience(0),                       // Initialize experience points to 0
      stats{},                             // Default initialize stats to zero
      abilitiesMenu{},                     // Default initialize abilities menu (empty vector)
      equippedItems{},                     // Default initialize equipped items (empty vector)
      inventory{}                          // Default initialize inventory (empty vector)
{
    // The stats array is explicitly default-initialized, meaning all values are set to zero.
}

// Method to roll stats based on character class
void Player::rollStats() {
    // Implementation for rolling stats based on class
    // Example: Rolling each stat based on the player's character class
       // Define stat ranges for each class
    struct StatRange {
        int minValue;                                      // Minimum value for the stat
        int maxValue;                                      // Maximum value for the stat
    };

    // Stat ranges for each class
    StatRange warriorStats[StatCount] = {{9, 20}, {2, 13}, {2, 13}, {2, 13}, {9, 20}}; // Warrior stat ranges
    StatRange rogueStats[StatCount]   = {{2, 13}, {9, 20}, {9, 20}, {2, 13}, {2, 13}}; // Rogue stat ranges
    StatRange mageStats[StatCount]    = {{2, 13}, {2, 13}, {9, 20}, {9, 20}, {2, 13}}; // Mage stat ranges
    StatRange clericStats[StatCount]  = {{2, 13}, {2, 13}, {2, 13}, {9, 20}, {9, 20}}; // Cleric stat ranges
    StatRange rangerStats[StatCount]  = {{2, 13}, {9, 20}, {2, 13}, {9, 20}, {2, 13}}; // Ranger stat ranges

    StatRange* selectedStats = nullptr;                   // Pointer to the selected stat range array

    // Use if-else statements to assign the appropriate stat range based on character class
    if (characterClass == "warrior") {                                          // If character class is warrior
        selectedStats = warriorStats;                                               // Assign warrior stat ranges
    } else if (characterClass == "rogue") {                                     // If character class is rogue
        selectedStats = rogueStats;                                                 // Assign rogue stat ranges
    } else if (characterClass == "mage") {                                      // If character class is mage
        selectedStats = mageStats;                                                  // Assign mage stat ranges
    } else if (characterClass == "cleric") {                                    // If character class is cleric
        selectedStats = clericStats;                                                // Assign cleric stat ranges
    } else if (characterClass == "ranger") {                                    // If character class is ranger
        selectedStats = rangerStats;                                                // Assign ranger stat ranges
    } else {                                                                    // If character class is unknown
        std::cerr << "Error: Unknown character class '" << characterClass << "'." << std::endl;
                    // Print error message
        return;                                                                 // Exit the function if an invalid class is given
    }

    // Roll stats using the selected stat range
    for (int i = 0; i < StatCount; ++i) {
        stats[i] = roll(selectedStats[i].minValue, selectedStats[i].maxValue); // Roll stat within the defined range
    }
}

// Helper method to simulate rolling stats within a given range using rand()
int Player::roll(int minValue, int maxValue) {
    return rand() % (maxValue - minValue + 1) + minValue; // Random value between minValue and maxValue (inclusive)
}

// -----------------------------------------Function to display player's stats
void Player::showStats() const {
    std::cout << "\n--- Player Stats ---\n";                                            // Display header for player stats
    std::cout << "Strength: " << stats[Strength] << "\n";                               // Display strength stat
    std::cout << "Dexterity: " << stats[Dexterity] << "\n";                             // Display dexterity stat
    std::cout << "Intelligence: " << stats[Intelligence] << "\n";                       // Display intelligence stat
    std::cout << "Wisdom: " << stats[Wisdom] << "\n";                                   // Display wisdom stat
    std::cout << "Constitution: " << stats[Constitution] << "\n";                       // Display constitution stat
}

// ------------------------------------------Function to display equipped items
void Player::showEquippedItems() const {
    std::cout << "\n--- Equipped Items ---\n";                                          // Display header for equipped items
    if (equippedItems.empty()) {                                                        // Check if no items are equipped
        std::cout << "No items equipped.\n";                                            // Print message indicating no items equipped
    } else {
        for (const auto& item : equippedItems) {                                        // Loop through equipped items
            std::cout << item.name << ": " << item.description << "\n";                 // Display item name and description
        }
    }
}


// Method to handle rolling stats and allowing player to decide whether to keep or re-roll
void Player::finalizeStats() {
    std::string response;                                                             // Store player's response for confirming or re-rolling stats

    // First roll
    rollStats();                                                                      // Roll stats for the first time
    showStats();                                                                      // Display the rolled stats

    // Ask player if they are satisfied with the rolled stats
    while (true) {
        std::cout << "Do you like these stats? (yes/no): ";                           // Prompt player to confirm if they like the stats
        std::cin >> response;                                                         // Get player's response
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');           // Clear input buffer to avoid any leftover newline issues
        std::transform(response.begin(), response.end(), response.begin(), ::tolower); // Convert response to lowercase for consistent comparison

        if (response == "yes") {                                                      // If player likes the stats
            std::cout << "Great! We will keep these stats.\n";                        // Confirm that the stats will be kept
            break;                                                                    // Exit the loop as stats are finalized
        } else if (response == "no") {                                                // If player does not like the stats
            std::cout << "Alright, we'll give it one more roll.\n";                   // Inform player that a second roll will be given

            // Second roll (final roll)
            rollStats();                                                              // Roll stats for the final time
            showStats();                                                              // Display the newly rolled stats

            std::cout << "These are your final stats. Looks like we're going to keep these!\n"; // Inform player that these are the final stats
            break;                                                                    // Exit the loop after the final roll
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";              // Handle invalid input by displaying an error message
        }
    }
}


//----------------------------------------------------------------------------------------------------


//------------------------------------------- PLAYER NAME AND CLASS SELECTION -------------------------------------------

// Function to get the player's name
std::string getPlayerName() {
    std::string playerName;                                                                     // Variable to store the player's name
    std::cout << "What is your name, adventurer?" << std::endl; 
    std::cout <<"... you know, the type of thing someone goes by" << std::endl;
    std::cout << "when they are on a thirst-trappy voyage for peril and riches." << std::endl;
    while (playerName.empty()) {                                                                //while loop not allowing blank names
        std::cout << "Name cannot be empty. Please enter your name: "; 
        std::getline(std::cin, playerName); };                                                  //getline capture full name, include spaces
    return playerName;                                                                          // Return the captured name
}

// ---------------------------------------Function to check if a string is a valid number
bool isNumber(const std::string& str) {
        for (auto c : str) {                              //Use auto to improve readability and make code 
                                                          //easier to refactor if data type changes.

        if (!std::isdigit(c)) return false;               // If any character is not a digit, return false
    }
    return true;                                          // If all characters are digits, return true
}

// -----------------------------Function to show class description and stat focus based on the player's selection
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
            std::cout << "Cleric: A divine healer and protector, wielding holy magic to heal and protect allies.\n";
            std::cout << "Stat focus: Wisdom and Constitution.\n";
            break;
        case 5:
            std::cout << "Ranger: A skilled marksman and survivalist, excelling in ranged combat and nature-based magic.\n";
            std::cout << "Stat focus: Dexterity and Wisdom.\n";
            break;
        default:
            std::cout << "Invalid class selection.\n";    // Handle invalid class numbers
            break;
    }
}


// -----------------------------------------------Function to confirm the player's class choice
bool confirmClassChoice() {
    std::string confirmation;                                                                       // Variable to store player yes/no confirmation
    while (true) {                                                                                  // Loop until a valid input is given
        std::cout << "Does this sound like a class you want to belong to? (yes/no): ";
        std::cin >> confirmation;                                                                   // Record the player's confirmation choice
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                         // Clear the input buffer to prevent leftover newlines
        std::transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower);  // Convert string to lowercase

        if (confirmation == "yes") {                                                                // If player confirms with "yes"
            return true;                                                                            // Return true, indicating confirmation
        } else if (confirmation == "no") {                                                          // If player declines with "no"
            return false;                                                                           // Return false, indicating no confirmation
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";                            // Error message for invalid input
        }
    }
}
// ---------------------------------Function to display available classes, allow selection, and handle confirmation
void displayClasses(Player& player) {
    std::string playerInput; // Variable storing player input for class selection

    std::cout << "What type of adventurer would you like to be?" << std::endl;
    std::cout << "(choose a number from the list below)" << std::endl << std::endl;

    std::cout << "1. Warrior\n2. Rogue\n3. Mage\n4. Cleric\n5. Ranger\n";                       // List the available classes

    std::cout << "Enter a number to select a class: ";                                          // Ask player to enter a number corresponding to the class
    std::cin >> playerInput;                                                                    // Record player's input

    if (isNumber(playerInput) && (playerInput >= "1" && playerInput <= "5")) {                  // Make sure numeric input is in the correct range
        int classChoice = std::stoi(playerInput);                                               // Convert input string to an integer using stoi
        showClassDescription(classChoice);                                                      // Display class description after selection

        if (confirmClassChoice()) {
            player.characterClass = (classChoice == 1 ? "warrior" : classChoice == 2 ? "rogue" :
                                     classChoice == 3 ? "mage" : classChoice == 4 ? "cleric" : "ranger");
            std::cout << "Awesome! You have decided to be a " << player.characterClass << ".\n";
            std::cout << "Now, let's talk about your base statistics...\n";

// Call finalizeStats to roll stats, allow player to review, and finalize them
            player.finalizeStats();
        } else {
            std::cout << "Okay, let's choose a different class then.\n";
            displayClasses(player); // Recursive call to restart the class selection
        }
    } else {
        std::cout << "Invalid input. Please select a number from 1-5." << std::endl; // Error message for invalid input
        displayClasses(player); // Recursive call to retry the class selection
    }
}






