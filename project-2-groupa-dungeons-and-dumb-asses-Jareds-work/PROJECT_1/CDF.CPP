#include "GameHeaderEli.h" // Include the game header file for necessary class definitions and enums

//------------------------------------------ PLAYER CLASS IMPLEMENTATION -------------------------------------------------

// Function to check if the player has a weapon equipped
bool Player::hasEquippedWeapon() const {
    for (const auto* item : equippedItems) { // Iterate through equipped items using pointers
        if (item->classification == WEAPON) { // Check if the item classification is WEAPON
            return true; // Return true if a weapon is found
        }
    }
    return false; // Return false if no weapon is found
}

//---------------------------- Constructor for Player - Takes player's name, class, and optional start level
Player::Player(std::string playerName, std::string charClass, int startLevel)
    : name(playerName), // Initialize player's name with the provided name
      characterClass(charClass), // Set player's character class
      level(startLevel), // Set player's level
      experience(0), // Initialize experience points to 0
      stats{}, // Default initialize stats to zero
      abilitiesMenu{}, // Default initialize abilities menu (empty vector)
      equippedItems{}, // Default initialize equipped items (empty vector)
      inventory{} { // Default initialize inventory (empty vector)
    // Stats are explicitly default-initialized to zero
}

//------------------------------ FUNCTION TO GET PLAYER NAME ------------------------------
std::string getPlayerName() {
    std::string playerName; // Variable to store player's name
    std::cout << "Enter your character's name: "; // Prompt the user for their character's name
    std::getline(std::cin, playerName); // Get the full name input including spaces
    return playerName; // Return the player's name to be used in the game
}

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
            std::cout << "Invalid class selection.\n"; // Handle invalid class numbers
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
              << "5. Ranger\n"; // Display available classes with numeric options

    int classChoice;

    while (true) {
        std::cout << "Please enter the number corresponding to your class: "; // Prompt user to enter the class choice
        std::cin >> classChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (classChoice >= 1 && classChoice <= 5) {
            showClassDescription(classChoice); // Display the class description based on player choice

            // Confirm class choice
            std::string confirmation;
            while (true) {
                std::cout << "Does this sound like your jam? (yes/no): ";
                std::getline(std::cin, confirmation);
                std::transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower); // Normalize input

                if (confirmation == "yes") {
                    // Assign chosen class to player's characterClass attribute
                    static const std::vector<std::string> classes{"warrior", "rogue", "mage", "cleric", "ranger"};
                    player.characterClass = classes[classChoice - 1];
                    std::cout << "Great! You are now a " << player.characterClass << ".\n"; // Confirm player choice
                    break;
                } else if (confirmation == "no") {
                    std::cout << "Let's choose a class again.\n"; // Allow user to choose again
                    break; // Exit the confirmation loop to select again
                } else {
                    std::cout << "Invalid input. Please enter 'yes' or 'no'.\n"; // Handle invalid input
                }
            }

            if (confirmation == "yes") {
                break; // Exit loop after confirming the class choice
            }
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n"; // Handle invalid input
        }
    }

    player.finalizeStats(); // Roll initial stats and finalize
}

//------------------------------------------ Function to roll stats based on character class
void Player::rollStats() {
    struct StatRange {
        int minValue;
        int maxValue;
    };

    static const std::map<std::string, std::vector<StatRange>> classStats{
        {"warrior", {{9, 20}, {4, 15}, {2, 15}, {2, 13}, {9, 20}}},
        {"rogue", {{5, 13}, {9, 20}, {9, 20}, {4, 15}, {2, 13}}},
        {"mage", {{3, 13}, {4, 13}, {9, 20}, {9, 20}, {2, 13}}},
        {"cleric", {{3, 13}, {4, 13}, {5, 15}, {9, 20}, {9, 20}}},
        {"ranger", {{5, 13}, {9, 20}, {5, 15}, {9, 20}, {2, 13}}}
    };

    auto selectedStats = classStats.at(characterClass);

    for (int i = 0; i < StatCount; ++i) {
        stats[i] = roll(selectedStats[i].minValue, selectedStats[i].maxValue);
    }
}

int Player::roll(int minValue, int maxValue) {
    return rand() % (maxValue - minValue + 1) + minValue;
}

// Function to display stats
void Player::showStats() const {
    std::cout << "\n--- Player Stats ---\n";
    static const std::vector<std::string> statNames{"Strength", "Dexterity", "Intelligence", "Wisdom", "Constitution", "Health"};
    for (int i = 0; i < StatCount; ++i) {
        std::cout << statNames[i] << ": " << stats[i] << "\n";
    }
}
