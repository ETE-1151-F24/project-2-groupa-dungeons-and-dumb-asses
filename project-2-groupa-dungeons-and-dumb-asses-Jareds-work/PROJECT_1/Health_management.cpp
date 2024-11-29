#include "GameHeaderEli.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "gameItems.cpp"
void Player::applyRegeneration() {
    currentHealth += totalRegenerationRate;                     // Add total regeneration rate to current health
    currentHealth = std::min(currentHealth, maxHealth);         // Ensure health does not exceed the maximum
    std::cout << "Regenerated " << totalRegenerationRate << " HP! Current Health: " << currentHealth << "\n";
}