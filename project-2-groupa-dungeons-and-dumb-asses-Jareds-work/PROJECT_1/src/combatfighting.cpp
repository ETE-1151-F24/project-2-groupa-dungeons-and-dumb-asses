//combatfighting.cpp

#include "combatfighting.h"


// Combat Improvement with Action Choices
void fight(int stats[6], int floor) {
    int enemyHealth = 10 + (floor * 5); // Enemy health scales with floor
    while (enemyHealth > 0 && stats[0] > 0) { // While enemy and player are alive
        std::string action;
        std::cout << "Choose an action: (attack/heal/escape): ";
        std::cin >> action;

        if (action == "attack") {
            int damage = rand() % 5 + 1; // Random damage
            enemyHealth -= damage;
            std::cout << "You dealt " << damage << " damage. Enemy health: " << enemyHealth << "\n";
        } else if (action == "heal") {
            int healAmount = rand() % 3 + 2; // Heal the player slightly
            stats[0] += healAmount;
            std::cout << "You healed for " << healAmount << " health. Your health: " << stats[0] << "\n";
        } else if (action == "escape") {
            std::cout << "You attempted to escape... but failed.\n";
        }

        if (enemyHealth <= 0) {
            std::cout << "Enemy defeated!\n";
            break;
        }

        // Enemy's turn to attack
        int damage = rand() % 5 + 1;
        stats[0] -= damage; // Subtract from player health
        std::cout << "Enemy dealt " << damage << " damage. Your health: " << stats[0] << "\n";

        if (stats[0] <= 0) {
            std::cout << "You were defeated...\n";
        }
    }
}

bool checkDodge(int dodgeChance) {
    int roll = rand() % 100;  // Simulate a dice roll to determine dodge success  there will be 5 types of dodges that can occur
    //those dodges will be based on how good the roll is 
    return roll < dodgeChance;
}

void enemyAttack(Player& player, int enemyStrength) {
    int damage = enemyStrength + (rand() % 10);  // Randomized damage.....this should also include the weapon that the enemy has
    player.currentHealth -= damage;
    std::cout << "The enemy attacks you for " << damage << " damage.\n";
    std::cout << "Your health is now: " << player.currentHealth << " / " << player.maxHealth << "\n";
}

void displayCombatStats(const Player& player, const std::map<std::string, int>& enemyStats) {
    // Display player's stats
    displayHealth(player);
    std::cout << "--- Enemy Stats ---\n";
    for (const auto& stat : enemyStats) {
        std::cout << stat.first << ": " << stat.second << "\n";
    }
}

// Function to simulate the player's healing action during combat
void healPlayer(int stats[6]) {
    int healAmount = rand() % 3 + 2; // Heal player slightly
    stats[0] += healAmount;
    std::cout << "You healed for " << healAmount << " health. Your health: " << stats[0] << "\n";
}

// Function to simulate the player's attempt to escape the battle
bool tryEscape(int stats[6]) {
    int escapeChance = rand() % 100; // Random chance to escape, 0 to 99
    if (escapeChance < 50) { // 50% chance of success
        return true;
    } else {
        return false;
    }
}
