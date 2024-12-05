//combatfighting.cpp

#include "combatfighting.h"

//-------------------------------------------------------------------------------------------
// Combat Improvement with Action Choices
//-------------------------------------------------------------------------------------------
void fight(Player& player, int enemyLevel) {
    int enemyHealth = 10 + (enemyLevel * 5); // Enemy health scales with level
    while (enemyHealth > 0 && player.currentHealth > 0) { // While enemy and player are alive
        std::string action;
        std::cout << "Choose an action: (attack/heal/escape): ";
        std::cin >> action;

        if (action == "attack") {
            int damage = rand() % 5 + 1; // Random damage
            enemyHealth -= damage;
            std::cout << "You dealt " << damage << " damage. Enemy health: " << enemyHealth << "\n";
        } else if (action == "heal") {
            healPlayer(player); // Use Player's healing function
        } else if (action == "escape") {
            if (tryEscape(player)) {
                std::cout << "You successfully escaped!\n";
                return; // Exit the fight
            } else {
                std::cout << "You attempted to escape... but failed.\n";
            }
        }

        if (enemyHealth <= 0) {
            std::cout << "Enemy defeated!\n";
            break;
        }

        // Enemy's turn to attack
        enemyAttack(player, enemyLevel * 2); // Scale enemy strength with level
        if (player.currentHealth <= 0) {
            std::cout << "You were defeated...\n";
        }
    }
}


//-------------------------------------------------------------------------------------------
// ---------------function to dodge an attack
//-------------------------------------------------------------------------------------------
 
bool checkDodge(int dodgeChance) {
    int roll = rand() % 100;  // Simulate a dice roll to determine dodge success  there will be 5 types of dodges that can occur
    //those dodges will be based on how good the roll is 
    return roll < dodgeChance;
}

//-------------------------------------------------------------------------------------------
//---------------------------function to perform the enemy attack
//-------------------------------------------------------------------------------------------
 
void enemyAttack(Player& player, int enemyStrength) {
    int damage = enemyStrength + (rand() % 10);  // Randomized damage.....this should also include the weapon that the enemy has
    player.currentHealth -= damage;
    std::cout << "The enemy attacks you for " << damage << " damage.\n";
    std::cout << "Your health is now: " << player.currentHealth << " / " << player.maxHealth << "\n";
}


//-------------------------------------------------------------------------------------------
//----------------------------function to display the combat related stats
//-------------------------------------------------------------------------------------------
 
void displayCombatStats(const Player& player, const std::map<std::string, int>& enemyStats) {
    // Display player's stats
    displayHealth(player);
    std::cout << "--- Enemy Stats ---\n";
    for (const auto& stat : enemyStats) {
        std::cout << stat.first << ": " << stat.second << "\n";
    }
}

//-------------------------------------------------------------------------------------------
//----------------// Function to simulate the player's healing action during combat----------------------- 
//-------------------------------------------------------------------------------------------
void healPlayer(Player& player) {
    int healAmount = rand() % 3 + 2; // Heal player slightly
    player.currentHealth = std::min(player.currentHealth + healAmount, player.maxHealth);
    std::cout << "You healed for " << healAmount << " health. Your health: " << player.currentHealth << "\n";
}


//-------------------------------------------------------------------------------------------
//---------------// Function to simulate the player's attempt to escape the battle------------------------ 
//-------------------------------------------------------------------------------------------
bool tryEscape(const Player& player) {
    int escapeChance = rand() % 100; // Random chance to escape, 0 to 99
    return escapeChance < 50; // 50% chance of success
}
