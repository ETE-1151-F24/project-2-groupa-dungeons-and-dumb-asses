//Character_develop_functs.cpp
#include <iostream>                                  // Required for input and output
#include <string>                                    // Required for using std::string
#include <array>                                     // Required for using std::array
#include <vector>                                    // Required for using std::vector
#include <cstdlib>                                   // Required for rand() function
#include <cctype>                                    // Required for std::tolower()

// [Enum] for character stats
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount };

// Player Class
class Player {
public:
    std::string name;                                   // Player's name
    std::string characterClass;                         // Character's class type (e.g., cleric, ranger, etc.)
    int level;                                          // Player's current level
    int experience;                                     // Player's accumulated experience points
    std::array<int, StatCount> stats;                   // Player's stats, stored in an array of size StatCount
    std::vector<std::string> abilitiesMenu;             // List of abilities available to the player
    std::vector<Item> equippedItems;                    // Items currently equipped by the player, affecting their abilities
    std::vector<Item> saccySak;                         // Player's inventory, renamed to saccySak, stores all items that the player has acquired

    // Constructor
    Player(std::string playerName, std::string charClass, int startLevel = 1) // Constructor takes player's name, class, and optional start level
        : name(playerName), characterClass(charClass), level(startLevel), experience(0) { // Initialize name, class, level, and experience
        // Stats will be initialized based on rolling values for each character class
    }

    // Method to roll stats based on character class
    void rollStats() {
        if (characterClass == "cleric") {               // Check if character class is cleric
            stats = {roll(9, 20), roll(9, 20), roll(2, 13), roll(2, 13), roll(2, 13)}; // Roll stats specific to cleric
        } else if (characterClass == "ranger") {        // Check if character class is ranger
            stats = {roll(2, 13), roll(9, 20), roll(9, 20), roll(2, 13), roll(2, 13)}; // Roll stats specific to ranger
        } else if (characterClass == "warrior") {       // Check if character class is warrior
            stats = {roll(9, 20), roll(2, 13), roll(2, 13), roll(2, 13), roll(9, 20)}; // Roll stats specific to warrior
        } else if (characterClass == "rogue") {         // Check if character class is rogue
            stats = {roll(2, 13), roll(9, 20), roll(9, 20), roll(2, 13), roll(2, 13)}; // Roll stats specific to rogue
        } else if (characterClass == "mage") {          // Check if character class is mage
            stats = {roll(2, 13), roll(2, 13), roll(9, 20), roll(9, 20), roll(2, 13)}; // Roll stats specific to mage
        }
        // Add additional conditions for other character classes as needed
    }

private:
    // Helper method to simulate rolling stats within a given range
    int roll(int minValue, int maxValue) {
        return rand() % (maxValue - minValue + 1) + minValue; // Random value between minValue and maxValue (inclusive)
    }
};

// Function to get the player's name
std::string getPlayerName() {
    std::string PlayerName;                                           // Variable to store the player's name
    std::cout << "What is your name, adventurer? ... you know, the type of thing someone goes by" << std::endl;
    std::cout << "when they are on a thirst-trappy voyage for peril and riches." << std::endl;
    std::getline(std::cin, PlayerName);                               // Use getline to capture the full name, including spaces
    return PlayerName;                                                // Return the captured name
}

// Function to check if a string is a valid number
bool isNumber(const std::string& str) {
    for (char const &c : str) {
        if (!std::isdigit(c)) return false;                           // If any character is not a digit, return false
    }
    return true;                                                      // If all characters are digits, return true
}

// Function to show class description and stat focus based on the player's selection
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
            std::cout << "Invalid class selection.\n";                 // Handle invalid class numbers
            break;
    }
}

// Function to confirm the player's class choice
bool confirmClassChoice() {
    std::string confirmation;                                         // Variable to store player yes/no confirmation
    while (true) {                                                    // Loop until a valid input is given
        std::cout << "Does this sound like a class you want to belong to? (yes/no): ";
        std::cin >> confirmation;                                     // Record the player's confirmation choice
        for (auto& ch : confirmation) ch = std::tolower(ch);          // Convert input to lowercase for case-insensitive comparison

        if (confirmation == "yes") {                                  // If player confirms with "yes"
            return true;                                              // Return true, indicating confirmation
        } else if (confirmation == "no") {                            // If player declines with "no"
            return false;                                             // Return false, indicating no confirmation
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n"; // Error message for invalid input
        }
    }
}

// Function to display classes, allow selection, and handle confirmation
void displayClasses(Player& player) {
    std::string playerInput;                                          // Variable storing player input for class selection

    std::cout << "What type of adventurer would you like to be?" << std::endl; // Display message asking player to choose a class
    std::cout << "(choose a number from the list below)" << std::endl << std::endl;

    std::cout << "1. Warrior\n2. Rogue\n3. Mage\n4. Cleric\n5. Ranger\n"; // List the available classes                  

    std::cout << "Enter a number to select a class: ";                 // Ask player to enter number corresponding to class
    std::cin >> playerInput;                                          // Record player's input

    if (isNumber(playerInput) && (playerInput == "1" || playerInput == "2" || playerInput == "3" || playerInput == "4" || playerInput == "5")) {
        int classChoice = std::stoi(playerInput);                     // Convert input string to an integer using stoi
        showClassDescription(classChoice);                            // Display class description after selection

        if (confirmClassChoice()) {
            player.characterClass = (classChoice == 1 ? "warrior" : classChoice == 2 ? "rogue" : classChoice == 3 ? "mage" : classChoice == 4 ? "cleric" : "ranger");
            std::cout << "Awesome-sauce! You have decided to be a " << player.characterClass << ".\n"; // Congratulate the player on their choice
            std::cout << "Now, let's talk about your base statistics...\n"; // Message indicating procession to next part (base statistics and rolling for them)
            player.rollStats();                                       // Roll stats based on the selected class
        } else {
            std::cout << "Okay, let's choose a different class then.\n"; // If player declines class, restart class selection process
            displayClasses(player);                                   // Recursive call to restart the class selection
        }
    } else {
        std::cout << "Invalid input. Please select a number from 1-5." << std::endl; // Error message for invalid input
    }
}


// Function to roll stats based on character class using consolidated stat ranges
void Player::rollStats() {
    srand(static_cast<unsigned int>(time(0)));             // Seed for random number generation

    // Define stat ranges for each class
    struct StatRange {
        int minValue;
        int maxValue;
    };

    // Stat ranges for each class
    StatRange warriorStats[StatCount] = {{9, 20}, {2, 13}, {2, 13}, {2, 13}, {9, 20}};
    StatRange rogueStats[StatCount]   = {{2, 13}, {9, 20}, {9, 20}, {2, 13}, {2, 13}};
    StatRange mageStats[StatCount]    = {{2, 13}, {2, 13}, {9, 20}, {9, 20}, {2, 13}};
    StatRange clericStats[StatCount]  = {{2, 13}, {2, 13}, {2, 13}, {9, 20}, {9, 20}};
    StatRange rangerStats[StatCount]  = {{2, 13}, {9, 20}, {2, 13}, {9, 20}, {2, 13}};

    StatRange* selectedStats = nullptr;                    // Pointer to the selected stat range array

    // Use a switch statement to assign the appropriate stat range
    if (characterClass == "warrior") {                     // If character class is warrior
        selectedStats = warriorStats;                      // Assign warrior stat ranges
    } else if (characterClass == "rogue") {                // If character class is rogue
        selectedStats = rogueStats;                        // Assign rogue stat ranges
    } else if (characterClass == "mage") {                 // If character class is mage
        selectedStats = mageStats;                         // Assign mage stat ranges
    } else if (characterClass == "cleric") {               // If character class is cleric
        selectedStats = clericStats;                       // Assign cleric stat ranges
    } else if (characterClass == "ranger") {               // If character class is ranger
        selectedStats = rangerStats;                       // Assign ranger stat ranges
    } else {                                               // If character class is unknown
        std::cerr << "Error: Unknown character class." << std::endl;  // Print error message
        return;                                            // Exit the function if invalid class
    }

    // Roll stats using the selected stat range
    for (int i = 0; i < StatCount; ++i) {                  // Loop through each stat
        stats[i] = roll(selectedStats[i].minValue, selectedStats[i].maxValue);  // Roll stat within defined range
    }
}



// Function to display player's stats
void Player::showStats() const {
    std::cout << "\n--- Player Stats ---\n";             // Display header for player stats
    std::cout << "Strength: " << stats[Strength] << "\n";  // Display strength stat
    std::cout << "Dexterity: " << stats[Dexterity] << "\n"; // Display dexterity stat
    std::cout << "Intelligence: " << stats[Intelligence] << "\n"; // Display intelligence stat
    std::cout << "Wisdom: " << stats[Wisdom] << "\n";       // Display wisdom stat
    std::cout << "Constitution: " << stats[Constitution] << "\n"; // Display constitution stat
}

// Function to display equipped items
void Player::showEquippedItems() const {
    std::cout << "\n--- Equipped Items ---\n";            // Display header for equipped items
    if (equippedItems.empty()) {                            // Check if no items are equipped
        std::cout << "No items equipped.\n";               // Print message indicating no items equipped
    } else {
        for (const auto& item : equippedItems) {            // Loop through equipped items
            std::cout << item.name << ": " << item.description << "\n"; // Display item name and description
        }
    }
}

