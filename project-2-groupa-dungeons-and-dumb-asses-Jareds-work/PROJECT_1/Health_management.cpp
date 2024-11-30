#include "GameHeaderEli.h"                // Include the game header file for necessary declarations
#include <vector>                         // Required for std::vector
#include <iostream>                       // Required for input/output operations
#include <algorithm>                      // Required for algorithms like std::min
#include "gameItems.cpp"                  // Include definitions for game items

//-------------------------------------------------------------------------------------------
// Function to apply regeneration to the player's health
//-------------------------------------------------------------------------------------------
void Player::applyRegeneration() {
    currentHealth += totalRegenerationRate;                     // Add total regeneration rate to current health
    currentHealth = std::min(currentHealth, maxHealth);         // Ensure health does not exceed the maximum limit
    std::cout << "Regenerated " << totalRegenerationRate << " HP! Current Health: " << currentHealth << "\n";
}

//this will trigger each round, time frame, or day, depending on its condition

 
 //-------------------------------------------------------------------------------------------
 //  this is the function for displaying the health of the character
 //-------------------------------------------------------------------------------------------

 void displayHealthDetails(const HealthModifiers& modifiers, int baseConstitution, int level) {
    int totalHealth = modifiers.calculateTotalHealth(baseConstitution, level);
    std::cout << "--- Health Details ---\n";
    std::cout << "Base Constitution: " << baseConstitution << " -> " << baseConstitution * 2 << " HP\n";
    std::cout << "Level: " << level << " -> " << level * 6 << " HP\n";
    std::cout << "Permanent Modifiers: " << modifiers.constitutionMod + modifiers.levelMod << " HP\n";
    std::cout << "Temporary Modifiers: " << modifiers.temporaryMod << " HP\n";
    std::cout << "Total Health: " << totalHealth << " HP\n";
}

