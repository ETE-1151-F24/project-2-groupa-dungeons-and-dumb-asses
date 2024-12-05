#ifndef GAMEITEMS_H
#define GAMEITEMS_H

#include <vector>
#include <string>
#include <array>
#include "GameHeaderEli.h"
#include "Item_constructors_dmg_shifts.h"

enum ItemType { WEAPON, MAGICAL, CLOTHING }; 
enum CombatType { MELEE, RANGED };    

// Shorthand variables
constexpr ItemType magical = ItemType::MAGICAL;
constexpr ItemType weapon = ItemType::WEAPON;
constexpr ItemType clothing = ItemType::CLOTHING;
constexpr CombatType melee = CombatType::MELEE;
constexpr CombatType ranged = CombatType::RANGED;

// Function to add an item to the game
void addItem(std::vector<Item>& gameItems, const std::string& itemName, const std::string& itemDescription,
             ItemType classification, CombatType combatType, const std::array<int, StatCount>& statModifiers,
             const std::string& abilityDescription, int minDamage, int maxDamage, int rangeModifier,
             int sneakPenalty, int magicPowerModifier, const std::string& restriction, int regenRate);

// Function to initialize the game items
void initializeGameItems(std::vector<Item>& gameItems);

#endif //gameitems.h