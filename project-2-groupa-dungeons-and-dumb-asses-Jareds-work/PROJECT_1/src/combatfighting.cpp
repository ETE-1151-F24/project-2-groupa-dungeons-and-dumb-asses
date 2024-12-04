//combatfighting.cpp

#include "GameHeaderEli.h"

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
