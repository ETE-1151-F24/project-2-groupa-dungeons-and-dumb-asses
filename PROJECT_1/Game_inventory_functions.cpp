
// Game_inventory_functions.cpp
#include "GameHeaderEli.h"
#include <iostream>

//------------------------------- FUNCTION TO DISPLAY PLAYER INVENTORY -------------------------------------------
void displayInventory(const Player& player) {
    std::cout << "\n--- Your Inventory ---\n";

    for (size_t i = 0; i < player.inventory.size(); ++i) {
        const Item& item = player.inventory[i];
        std::string status = item.isPlaceholder ? "(equipped)" : "In your Sakky";
        std::cout << (i + 1) << ". " << item.name << " - " << status << "\n";
    }
}



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
//-------------------------------- FUNCTION TO EQUIP AN ITEM -----------------------------------------------
bool equipItem(Player& player, int itemIndex) {
    // Step 1: Validate item index
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.inventory.size())) {
        std::cout << "Invalid item selection.\n";
        return false;
    }

    // Step 2: Get the item to equip
    Item& itemToEquip = player.inventory[itemIndex];

    // Step 3: Check if the item is already equipped
    if (player.isEquipped(itemToEquip)) {
        std::cout << itemToEquip.name << " is already equipped.\n";
        return false;
    }

    // Step 4: Mark the item in the inventory as a placeholder
    itemToEquip.isPlaceholder = true;

    // Step 5: Add the item to equipped items
    player.equippedItems.push_back(itemToEquip);
    std::cout << "Equipped " << itemToEquip.name << "!\n";

    // Step 6: Update player stats based on item modifiers
    for (int i = 0; i < StatCount; ++i) {
        player.stats[i] += itemToEquip.statModifier[i];
    }

    return true;
}


//-------------------------------- FUNCTION TO UNEQUIP AN ITEM --------------------------------------------
bool unequipItem(Player& player, int itemIndex) {
    // Step 1: Validate item index
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.equippedItems.size())) {
        std::cout << "Invalid item selection.\n";
        return false;
    }

    // Step 2: Get the item to unequip
    Item itemToUnequip = player.equippedItems[itemIndex];

    // Step 3: Remove the item from equipped items
    player.equippedItems.erase(player.equippedItems.begin() + itemIndex);

    // Step 4: Find the placeholder in the inventory and replace it
    for (auto& item : player.inventory) {
        if (item.name == itemToUnequip.name && item.isPlaceholder) {
            item.isPlaceholder = false;  // Mark it as no longer a placeholder
            break;
        }
    }
    std::cout << "Unequipped " << itemToUnequip.name << "!\n";

    // Step 5: Update player stats by removing item modifiers
    for (int i = 0; i < StatCount; ++i) {
        player.stats[i] -= itemToUnequip.statModifier[i];
    }

    return true;
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
