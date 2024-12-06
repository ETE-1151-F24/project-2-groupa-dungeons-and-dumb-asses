#ifndef LEVELING_H
#define LEVELING_H

#include <vector>
#include <map>
#include "GameHeaderEli.h"  // Include the game header for Player class and related functionality
// #include "Character_develop_functs.h"
// Function Declarations


//+++++++++++++++++++++++++++++ Struct declarations ++++++++++++++++++++++++++++++++++++++++++++++++++++
struct HealthModifiers {
    int constitutionMod = 0; // Constitution-based health modifier
    int levelMod = 0;        // Level-based health modifier
    int temporaryMod = 0;    // Temporary health modifier (e.g., from items, spells)

    // Correctly mark calculateTotalHealth as const
    int calculateTotalHealth(int baseConstitution, int level) const {
        int health = baseConstitution * 2 + level * 6;
        health += constitutionMod + levelMod + temporaryMod;
        return health;
    }
};

// Function to display health details based on player's stats and health modifiers
void displayHealthDetails(const HealthModifiers& modifiers, int baseConstitution, int level);

// Function to determine the player's level based on their experience and XP benchmarks
int getLevel(int xp, const std::map<int, int>& xpBenchmarks);

// Function to award XP to the player after combat, puzzles, or quests
void awardXP(Player& player, int amount, const std::map<int, int>& xpBenchmarks,
             const std::vector<nlohmann::json>& availableSpells);



#endif // LEVELING_H
