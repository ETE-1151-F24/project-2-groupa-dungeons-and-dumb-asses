#ifndef LEVELING_H
#define LEVELING_H

#include <vector>
#include <map>
#include "GameHeaderEli.h"  // Include the game header for Player class and related functionality
#include "Character_develop_functs.h"
// Function Declarations

// Function to display health details based on player's stats and health modifiers
void displayHealthDetails(const HealthModifiers& modifiers, int baseConstitution, int level);

// Function to determine the player's level based on their experience and XP benchmarks
int getLevel(int xp, const std::map<int, int>& xpBenchmarks);

// Function to award XP to the player after combat, puzzles, or quests
void awardXP(Player& player, int amount, const std::map<int, int>& xpBenchmarks,
             const std::vector<nlohmann::json>& availableSpells);



#endif // LEVELING_H
