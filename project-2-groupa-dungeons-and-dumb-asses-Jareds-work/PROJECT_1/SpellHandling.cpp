// SpellHandling.cpp
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include "GameHeaderEli.h"

// Load spells from JSON file
std::vector<nlohmann::json> loadSpells(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open spells file: " + filename);
    }
    nlohmann::json spellData;
    file >> spellData;
    return spellData;
}

// Display all learned spells
void Player::displaySpells() const {
    std::cout << "\n--- Learned Spells ---\n";
    if (learnedSpells.empty()) {
        std::cout << "You have not learned any spells yet.\n";
        return;
    }
    for (const auto& spell : learnedSpells) {
        std::cout << "- " << spell << "\n";
    }
}

// Learn a new spell
void Player::learnSpell(const std::string& spellName) {
    if (std::find(learnedSpells.begin(), learnedSpells.end(), spellName) != learnedSpells.end()) {
        std::cout << "You already know the spell: " << spellName << "\n";
        return;
    }
    learnedSpells.push_back(spellName);
    std::cout << "You have learned the spell: " << spellName << "\n";
}

// Choose a starting spell
void chooseStartingSpell(Player& player, const std::vector<nlohmann::json>& availableSpells) {
    std::cout << "Choose a starting spell:\n";
    for (size_t i = 0; i < availableSpells.size(); ++i) {
        const auto& spell = availableSpells[i];
        std::cout << i + 1 << ". " << spell["name"] << ": " << spell["description"] << " (Level " << spell["level_required"] << ")\n";
    }

    int choice;
    while (true) {
        std::cout << "Enter the number of your choice: ";
        std::cin >> choice;
        if (choice > 0 && choice <= static_cast<int>(availableSpells.size())) {
            const auto& chosenSpell = availableSpells[choice - 1];
            if (player.level >= chosenSpell["level_required"]) {
                player.learnSpell(chosenSpell["name"]);
                break;
            } else {
                std::cout << "You do not meet the level requirement for that spell.\n";
            }
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Grant new spells upon leveling up
// Grant new spells upon leveling up
void grantSpellsOnLevelUp(Player& player, const std::vector<nlohmann::json>& availableSpells) {
    std::cout << "Congratulations! You have leveled up to Level " << player.level << "!\n";

    // Determine the number of spells the player can learn (e.g., 1 spell + 1 per 5 levels)
    int spellsToLearn = 1 + player.level / 5;
    std::cout << "You can learn " << spellsToLearn << " new spell(s) at this level.\n";

    // Filter eligible spells
    std::vector<nlohmann::json> eligibleSpells;
    for (const auto& spell : availableSpells) {
        if (spell["level_required"] <= player.level &&
            std::find(player.learnedSpells.begin(), player.learnedSpells.end(), spell["name"]) == player.learnedSpells.end()) {
            eligibleSpells.push_back(spell);
        }
    }

    if (eligibleSpells.empty()) {
        std::cout << "No new spells are available for your level.\n";
        return;
    }

    // Display eligible spells
    for (size_t i = 0; i < eligibleSpells.size(); ++i) {
        std::cout << i + 1 << ". " << eligibleSpells[i]["name"] << ": " << eligibleSpells[i]["description"] << "\n";
    }

    // Allow the player to choose spells
    while (spellsToLearn > 0) {
        int choice;
        std::cout << "Choose a spell to learn by entering its number (or 0 to skip): ";
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail() || choice < 0 || choice > static_cast<int>(eligibleSpells.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 0 and " << eligibleSpells.size() << ".\n";
            continue;
        }

        // Skip learning a spell
        if (choice == 0) {
            std::cout << "You chose to skip learning a spell.\n";
            break;
        }

        // Learn the chosen spell
        const std::string& selectedSpell = eligibleSpells[choice - 1]["name"];
        player.learnSpell(selectedSpell);
        std::cout << "You have learned the spell: " << selectedSpell << "!\n";

        // Remove the learned spell from the eligible list
        eligibleSpells.erase(eligibleSpells.begin() + (choice - 1));
        --spellsToLearn;

        // If no eligible spells remain
        if (eligibleSpells.empty()) {
            std::cout << "No more eligible spells are available to learn.\n";
            break;
        }

        // Display remaining eligible spells
        if (spellsToLearn > 0) {
            std::cout << "You can learn " << spellsToLearn << " more spell(s).\n";
            for (size_t i = 0; i < eligibleSpells.size(); ++i) {
                std::cout << i + 1 << ". " << eligibleSpells[i]["name"] << ": " << eligibleSpells[i]["description"] << "\n";
            }
        }
    }
}
