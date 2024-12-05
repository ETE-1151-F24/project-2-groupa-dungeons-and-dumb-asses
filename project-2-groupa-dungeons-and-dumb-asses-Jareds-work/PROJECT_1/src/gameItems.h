#ifndef GAMEITEMS_H
#define GAMEITEMS_H

#include <vector>
#include <string>
#include <array>
#include "GameHeaderEli.h"
#include "Item_constructors_dmg_shifts.h"

// Function to add an item to the game
void addItem(std::vector<Item>& gameItems, const std::string& itemName, const std::string& itemDescription,
             ItemType classification, CombatType combatType, const std::array<int, StatCount>& statModifiers,
             const std::string& abilityDescription, int minDamage, int maxDamage, int rangeModifier,
             int sneakPenalty, int magicPowerModifier, const std::string& restriction, int regenRate);

// Function to initialize the game items
void initializeGameItems(std::vector<Item>& gameItems);

#endif //gameitems.h