#ifndef SPELLHANDLING_H
#define SPELLHANDLING_H

#include <vector>
#include <nlohmann/json.hpp>
#include "GameHeaderEli.h"  // Include the game-specific header for the Player class and other game-specific functionality

// Function Declarations

// Display the list of spells based on the player's level
void displaySpellList(int playerLevel, const std::vector<nlohmann::json>& availableSpells);

// Function to load spells from a JSON file
std::vector<nlohmann::json> loadSpells(const std::string& filename);

// Function to choose a starting spell for the player
void chooseStartingSpell(Player& player, const std::vector<nlohmann::json>& availableSpells);

// Function to grant new spells upon leveling up
void grantSpellsOnLevelUp(Player& player, const std::vector<nlohmann::json>& availableSpells);

#endif // SPELLHANDLING_H
