#ifndef COMBATFIGHTING_H
#define COMBATFIGHTING_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include "GameHeaderEli.h" // To include Player and HealthModifiers
#include "Character_develop_functs.h"

// Function to simulate a fight between the player and an enemy
int fight(Player& player, int enemyLevel); // Declaring the fight function, which handles the player's fight logic


// Function to display the player's health
void displayHealth(const Player& player); // Displays health information for the player during combat

// Function to check if the player dodged the attack
bool checkDodge(int dodgeChance);  // Check if the player successfully dodged the enemy's attack

// Function to simulate the enemy's attack
void enemyAttack(Player& player, int enemyStrength); // Simulate the enemy's attack on the player

// Function to display combat stats, including the enemy's health and attack damage
void displayCombatStats(const Player& player, const std::map<std::string, int>& enemyStats);  // Display combat stats for both player and enemy

// Function to simulate the player's healing action
void healPlayer(int stats[6]); // Function to heal the player slightly during combat

// Function to simulate the player's attempt to escape
bool tryEscape(int stats[6]); // Function to attempt an escape from the battle


//calculating damgage is in the item constructors and damage shift files


#endif // COMBATFIGHTING_H
