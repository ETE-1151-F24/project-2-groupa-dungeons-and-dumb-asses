// SpellHandling.cpp

#include <nlohmann/json.hpp>                                                             // Include JSON library
#include <fstream> // Add this line to include ifstream                                                                   // Include file stream
#include <vector>                                                                        // Include vector for dynamic arrays
#include <iostream>                                                                      // Include iostream for console I/O
#include "GameHeaderEli.h"                                                               // Include game-specific header
#include <stdexcept>        // For std::runtime_error

// Display the list of spells based on the player's level
void displaySpellList(int playerLevel, const std::vector<nlohmann::json>& availableSpells) {
    if (playerLevel <= 0 || playerLevel > static_cast<int>(availableSpells.size())) {
        std::cout << "No spells available for this level.\n";
        return;
    }

    const auto& levelSpells = availableSpells[playerLevel - 1]["spells"];
    std::cout << "Available spells for your level:\n";

    for (size_t i = 0; i < levelSpells.size(); ++i) {
        const auto& spell = levelSpells[i];
        std::cout << (i + 1) << ". " << spell["name"] << " - " << spell["description"] << "\n";
    }
}

// Function to load spells from a JSON file
std::vector<nlohmann::json> loadSpells(const std::string& filename) {                    // Function to load spells
    std::ifstream file(filename);                                                       // Open file stream
    if (!file.is_open()) {                                                              // Check if file failed to open
        std::cerr << "Error: Could not open the spells file: " << filename << "\n";     // Log error
        throw std::runtime_error("Spells file missing!");                               // Throw runtime error
    }

    nlohmann::json spellData;                                                           // JSON object to store spells
    try {
        file >> spellData;                                                              // Parse JSON from file
    } catch (const nlohmann::json::parse_error& e) {                                    // Handle parsing errors
        std::cerr << "Error: Failed to parse JSON. Details: " << e.what() << "\n";      // Log parsing error
        throw;                                                                          // Re-throw exception for handling at a higher level
    }

    if (!spellData.is_array()) {                                                        // Ensure the parsed JSON is an array
        std::cerr << "Error: The JSON file does not contain a valid spell array.\n";    // Log format error
        throw std::runtime_error("Invalid JSON format for spells.");                    // Throw runtime error for invalid format
    }

    return spellData.get<std::vector<nlohmann::json>>();                                // Convert JSON array to vector and return
}

// Display all learned spells
void Player::displaySpells() const {                                                     // Function to display player's spells
    std::cout << "\n--- Learned Spells ---\n";                                           // Print title
    if (learnedSpells.empty()) {                                                         // Check if no spells learned
        std::cout << "You have not learned any spells yet.\n";                           // Inform player of empty spell list
        return;                                                                          // Exit function
    }
    for (const auto& spell : learnedSpells) {                                            // Loop through learned spells
        std::cout << "- " << spell << "\n";                                              // Print each spell
    }
}

// Learn a new spell
void Player::learnSpell(const std::string& spellName) {                                  // Function to learn a new spell
    if (std::find(learnedSpells.begin(), learnedSpells.end(), spellName) !=              // Check if spell is already learned
        learnedSpells.end()) {
        std::cout << "You already know the spell: " << spellName << "\n";                // Inform player they already know the spell
        return;                                                                          // Exit function
    }
    learnedSpells.push_back(spellName);                                                  // Add spell to learned spells
    std::cout << "You have learned the spell: " << spellName << "\n";                    // Confirm spell learned
}

// Choose a starting spell
void chooseStartingSpell(Player& player, const std::vector<nlohmann::json>& availableSpells) {
    std::cout << "Choose a starting spell:\n";  // Prompt player to choose
    displaySpellList(player.level, availableSpells);  // Display available spells based on level

    int choice;  // Player's choice
    while (true) {  // Loop until valid input
        std::cout << "Enter the number of your choice: ";  // Prompt for input
        std::cin >> choice;  // Read input

         // Ensure the input is valid and corresponds to available spells
        int playerLevel = player.level;  // Ensure the level is correctly referenced
        if (std::cin.fail() || choice <= 0 || choice > availableSpells[playerLevel - 1]["spells"].size()) {

            std::cin.clear();  // Clear input error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please try again.\n";  // Inform user of error
            continue;  // Retry loop
        }

        const auto& chosenSpell = availableSpells[player.level - 1]["spells"][choice - 1];  // Get chosen spell
        if (player.level >= chosenSpell["level"]) {  // Check if player's level is enough for the spell
            player.learnSpell(chosenSpell["name"]);  // Learn the chosen spell
            std::cout << "You have learned the " << chosenSpell["name"] << " spell!\n";  // Confirm learning
            break;  // Exit loop
        } else {
            std::cout << "You do not meet the level requirement for that spell.\n";  // Inform player of level issue
        }
    }
}
// Grant new spells upon leveling up
void grantSpellsOnLevelUp(Player& player, const std::vector<nlohmann::json>& availableSpells) {
    std::cout << "Congratulations! You have leveled up to Level " << player.level        // Announce level up
              << "!\n";

    int spellsToLearn = 1 + player.level / 5;                                            // Calculate spells to learn
    std::cout << "You can learn " << spellsToLearn << " new spell(s) at this level.\n";  // Inform player of spell allowance

    std::vector<nlohmann::json> eligibleSpells;                                          // Store eligible spells
    for (const auto& spell : availableSpells) {                                          // Loop through all spells
        if (spell["level_required"] <= player.level &&                                   // Check level requirement
            std::find(player.learnedSpells.begin(), player.learnedSpells.end(), spell["name"].get<std::string>()) 
            == player.learnedSpells.end()) {                                             // Check if spell is already learned
            eligibleSpells.push_back(spell);                                             // Add eligible spell
        }
    }

    if (eligibleSpells.empty()) {                                                        // Check if no eligible spells
        std::cout << "No new spells are available for your level.\n";                    // Inform player of no options
        return;                                                                          // Exit function
    }

    while (spellsToLearn > 0) {                                                          // Allow player to learn spells
        displaySpellList(player.level, eligibleSpells);                                                // Display eligible spells

        int choice;                                                                      // Player's choice
        std::cout << "Choose a spell to learn by entering its number (or 0 to skip): ";  // Prompt for input
        std::cin >> choice;

        if (std::cin.fail() || choice < 0 || choice >                                    // Validate input
            static_cast<int>(eligibleSpells.size())) {
            std::cin.clear();                                                            // Clear input error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');          // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 0 and "           // Prompt valid range
                      << eligibleSpells.size() << ".\n";
            continue;                                                                    // Retry loop
        }

        if (choice == 0) {                                                               // Check for skip choice
            std::cout << "You chose to skip learning a spell.\n";                        // Confirm skip
            break;                                                                       // Exit loop
        }

        const std::string& selectedSpell = eligibleSpells[choice - 1]["name"].get<std::string>(); // Get spell name
        player.learnSpell(selectedSpell);                                               // Learn spell
        std::cout << "You have learned the spell: " << selectedSpell << "!\n";           // Confirm learning

        eligibleSpells.erase(eligibleSpells.begin() + (choice - 1));                     // Remove learned spell
        --spellsToLearn;                                                                 // Decrement spells to learn

        if (eligibleSpells.empty()) {                                                    // Check if no eligible spells
            std::cout << "No more eligible spells are available to learn.\n";            // Inform player
            break;                                                                       // Exit loop
        }
        if (spellsToLearn > 0) {                                                         // Check if more spells to learn
            std::cout << "You can learn " << spellsToLearn                               // Inform remaining spells
                      << " more spell(s).\n";
        }
    }
}
