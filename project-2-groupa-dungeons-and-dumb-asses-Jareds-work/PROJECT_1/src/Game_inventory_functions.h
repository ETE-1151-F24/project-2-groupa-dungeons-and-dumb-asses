#ifndef GAME_INVENTORY_FUNCTIONS_H
#define GAME_INVENTORY_FUNCTIONS_H
#include "Character_develop_functs.h"
#include "GameHeaderEli.h" // Include necessary declarations from the main game header
#include "item_constructors_dmg_shifts.h"
// Function declarations for inventory management
void displayInventory(Player& player);                             // Display player inventory and interact with items
void displayItemDetails(const Item& item);                         // Display detailed info about an item
// bool Player::isEquipped(const Item& item) const;                   // Check if an item is equipped by the player
// void Player::updateStats(const Item& item, bool isEquipping);      // Update stats when an item is equipped or unequipped
// void Player::equipItem(Item* item);                                // Equip an item to the player
// void Player::unequipItem(Item* item);                              // Unequip an item from the player
void checkForWeapon(Player& player);                               // Check if the player has a weapon equipped

#endif // GAME_INVENTORY_FUNCTIONS_H
