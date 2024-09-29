
// Game_inventory_functions.cpp
#include "GameHeaderEli.h"
#include <iostream>

//-------------------------------- FUNCTION TO DISPLAY ITEM DESCRIPTIONS -----------------------------------
void displayItemDetails(const Item& item) {
    std::cout << "Item: " << item.name << "\nDescription: " << item.description << "\nAbility: " << item.ability << "\n"; // Display item details

    bool hasModifiers = false;                     // Flag to check if there are any non-zero modifiers
    for (int i = 0; i < StatCount; ++i) {          // Loop through all stat modifiers
        if (item.statModifier[i] != 0) {           // Check if any modifier is non-zero
            hasModifiers = true;                   // Set flag to true if a non-zero modifier is found
            break;                                 // Exit loop since we only need to know if any modifier exists
        }
    }
// ----------------------------------------Display modifiers if they exist
    if (hasModifiers) {                                                                     // If there are stat modifiers, display them
        std::cout << "Stat Modifiers: \n";
        if (item.statModifier[Strength] != 0)                                               // Check if strength modifier is non-zero
            std::cout << "Strength: " << item.statModifier[Strength] << "\n";               // Display strength modifier
        if (item.statModifier[Dexterity] != 0)                                              // Check if dexterity modifier is non-zero
            std::cout << "Dexterity: " << item.statModifier[Dexterity] << "\n";             // Display dexterity modifier
        if (item.statModifier[Intelligence] != 0)                                           // Check if intelligence modifier is non-zero
            std::cout << "Intelligence: " << item.statModifier[Intelligence] << "\n";       // Display intelligence modifier
        if (item.statModifier[Wisdom] != 0)                                                 // Check if wisdom modifier is non-zero
            std::cout << "Wisdom: " << item.statModifier[Wisdom] << "\n";                   // Display wisdom modifier
        if (item.statModifier[Constitution] != 0)                                           // Check if constitution modifier is non-zero
            std::cout << "Constitution: " << item.statModifier[Constitution] << "\n";       // Display constitution modifier
    } else {                                                                                // If no stat modifiers exist
        std::cout << "This item does not affect any stats.\n";                              // Display message indicating no modifiers
    }
// ---------------------------If the item is a weapon, show its damage range
    if (item.classification == WEAPON) {                                                    // Display damage range if applicable
        std::cout << "Damage Range: " << item.minDamage << " - " << item.maxDamage << "\n"; // Show damage for weapons
    }
}

//-------------------------------- FUNCTION TO CHECK IF ITEM IS EQUIPPED -----------------------------------
bool Player::isEquipped(const Item& item) const {                                           // Member function to check if item is equipped
    for (const auto& equippedItem : equippedItems) {                                        // Iterate through equipped items
        if (equippedItem.name == item.name) {                                               // Compare by item name
            return true;                                                                    // if Item is equipped
        }
    }
    return false;                                                                           // rtrn false if Item is not equipped
}
//------------------------------- FUNCTION TO EQUIP AN ITEM -----------------------------------------------
// Function to equip an item from inventory
bool equipItem(Player& player, int itemIndex) {

    // Step 1: Validate item index
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.inventory.size())) { // Check if item index is within inventory bounds
        std::cout << "Invalid item selection.\n";           // Display error for invalid index
        return false;                                       // Return false indicating the equip process failed
    }

    // Step 2: Get the item to equip
    Item itemToEquip = player.inventory[itemIndex];         // Retrieve the item from the player's inventory using the index provided

    // Step 3: Check if the item is already equipped
    if (player.isEquipped(itemToEquip)) {                   // Use Player's `isEquipped` method to verify if the item is already equipped
        std::cout << itemToEquip.name << " is already equipped.\n"; // Notify the player if the item is already equipped
        return false;                                       // Return false to indicate no action taken
    }

    // Step 4: Remove the item from the inventory
    player.inventory.erase(player.inventory.begin() + itemIndex); // Remove the item from inventory using the vector's `erase` method

    // Step 5: Add the item to equipped items
    player.equippedItems.push_back(itemToEquip);            // Add the item to the `equippedItems` vector
    std::cout << "Equipped " << itemToEquip.name << "!\n";  // Inform the player that the item was successfully equipped

    // Step 6: Update player stats based on item modifiers
    for (int i = 0; i < StatCount; ++i) {                   // Iterate through all stats (Strength, Dexterity, etc.)
        player.stats[i] += itemToEquip.statModifier[i];     // Add the stat modifier from the item to the player's stats
    }

    return true;                                            // Return true to indicate success
}

//-------------------------------- FUNCTION TO UNEQUIP AN ITEM --------------------------------------------
// Function to unequip an item from equipped items
bool unequipItem(Player& player, int itemIndex) {
    
    // Step 1: Validate item index
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.equippedItems.size())) { // Check if item index is valid
        std::cout << "Invalid item selection.\n";         // Display error for invalid index
        return false;                                     // Return false indicating the unequip process failed
    }

    // Step 2: Get the item to unequip
    Item itemToUnequip = player.equippedItems[itemIndex]; // Retrieve the item from the equipped items

    // Step 3: Remove the item from equipped items
    player.equippedItems.erase(player.equippedItems.begin() + itemIndex); // Remove item from `equippedItems` using vector's `erase` method

    // Step 4: Add the item back to inventory
    player.inventory.push_back(itemToUnequip);            // Return the item to the player's inventory
    std::cout << "Unequipped " << itemToUnequip.name << "!\n"; // Inform the player that the item was successfully unequipped

    // Step 5: Update player stats by removing item modifiers
    for (int i = 0; i < StatCount; ++i) {                 // Iterate through all stats (Strength, Dexterity, etc.)
        player.stats[i] -= itemToUnequip.statModifier[i]; // Subtract the stat modifier from the player's stats
    }

    return true;                                          // Return true to indicate success
}

//------------------------------- FUNCTION TO CHECK FOR WEAPON -------------------------------------------
void checkForWeapon(Player& player) {
    bool hasWeapon = false;                               // Flag to check if the player has a weapon equipped

    for (const auto& item : player.equippedItems) {       // Loop through equipped items
        if (item.classification == WEAPON) {              // If an item is a weapon
            hasWeapon = true;                             // Set flag to true
            break;                                        // Exit loop as soon as a weapon is found
        }
    }

    if (!hasWeapon) {                                                                                               // If no weapon equipped
        std::cout << "Warning: You are without a weapon. This might not end well in combat!\n";                     // Warning message
        std::cout << "If you wanna punch and kick your way out, be my guest, but you've been warned." << std::endl;

        char weapResponse;                                                                              // Variable to store user response
        while (true) {
            std::cout << "Do you want to proceed without a weapon? (y/n): ";                            // Ask player for confirmation
            std::cin >> weapResponse;                                                                   // Get response

            if (weapResponse == 'y' || weapResponse == 'Y') {                                           // If player is okay with no weapon
                std::cout << "Alright, but be careful out there!\n";                                    // Warning confirmation
                break;                                                                                  // Break loop, continue main menu
            } else if (weapResponse == 'n' || weapResponse == 'N') {                                    // If player wants to equip a weapon
                std::cout << "Let's head back to the inventory to equip a weapon.\n";
                int itemChoice;                                                                         // Variable to store user item choice
                std::cout << "Enter the number of the item to equip from your inventory: ";             // Prompt user to choose an item
                std::cin >> itemChoice;
                equipItem(player, itemChoice - 1);                                                      // Call [equipItem] with chosen item
                break;                                                                                  // Break loop after equipping
            } else {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";                               // Handle invalid input
            }
        }
    }
}
