#include "GameHeaderEli.h"                // Include the game header file for necessary declarations
#include <vector>                         // Required for std::vector
#include <iostream>                       // Required for input/output operations
#include <algorithm>                      // Required for algorithms like std::min
#include "Character_develop_functs.h"

//-------------------------------------------------------------------------------------------
// Function to apply regeneration to the player's health
//-------------------------------------------------------------------------------------------
void Player::applyRegeneration() {
if (currentHealth < maxHealth) {
    currentHealth += totalRegenerationRate;
    currentHealth = std::min(currentHealth, maxHealth);
    std::cout << "Regenerated " << totalRegenerationRate << " HP! Current Health: " << currentHealth << "\n";
}
}

//this will trigger each round, 

 
//if the value of the regeneration is negative, then that means that something is draining you of life, like a parasitic curse or something