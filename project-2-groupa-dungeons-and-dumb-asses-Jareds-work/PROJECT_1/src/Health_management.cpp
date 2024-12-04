#include "GameHeaderEli.h"                // Include the game header file for necessary declarations
#include <vector>                         // Required for std::vector
#include <iostream>                       // Required for input/output operations
#include <algorithm>                      // Required for algorithms like std::min


//-------------------------------------------------------------------------------------------
// Function to apply regeneration to the player's health
//-------------------------------------------------------------------------------------------
void Player::applyRegeneration() {
    currentHealth += totalRegenerationRate;                     // Add total regeneration rate to current health
    currentHealth = std::min(currentHealth, maxHealth);         // Ensure health does not exceed the maximum limit
    std::cout << "Regenerated " << totalRegenerationRate << " HP! Current Health: " << currentHealth << "\n";
}

//this will trigger each round, 

 
