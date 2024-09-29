// Game_inventory_functions.cpp
#include "GameHeaderEli.h"                            // Include header file for necessary declarations
#include <iostream>                                   // For std::cin, std::cout

//------------------------------- FUNCTION TO DISPLAY PLAYER INVENTORY -------------------------------------------
void displayInventory(const Player& player) {
    std::cout << "\n--- Your Inventory ---\n";

    for (size_t i = 0; i < player.inventory.size(); ++i) {
        const Item& item = player.inventory[i];                                // Access current item in inventory
        std::string status = player.isEquipped(item) ? "(equipped)"            // Set status to "(equipped)" if item is equipped
                                                     : "In your Sakky";        // Otherwise, set status to "In your Sakky"
        std::cout << (i + 1) << ". " << item.name << " - " << status << "\n";  // Display item and its status
    }
}

//------------------------------- FUNCTION TO DISPLAY ITEM DESCRIPTIONS -------------------------------------------
void displayItemDetails(const Item& item) {
    std::cout << "Item: " << item.name << "\nFlavor Description: " << item.flavorDescription // Print item details
              << "\nAbility: " << item.ability << "\n";                                     // Display ability of item

    bool hasModifiers = false;                                                              //Flag to check for any non-zero modifiers
    for (int i = 0; i < StatCount; ++i) {                                                   // Loop through all stat mods
        if (item.statModifier[i] != 0) {                                                    // Check if any modifier is non-zero
            hasModifiers = true;                                                            // Set flag true if non-zero modifier found
            break;                                                                          //Exit loop: only need know if any modifier exists
        }
    }

    if (hasModifiers) {                                                                     // If there are stat mods, display them
        std::cout << "Stat Modifiers: \n";
        if (item.statModifier[Strength] != 0)                                               // Check if strength mod is non-zero
            std::cout << "Strength: " << item.statModifier[Strength] << "\n";               // Display strength mod
        if (item.statModifier[Dexterity] != 0)                                              // Check if dexterity modi is non-zero
            std::cout << "Dexterity: " << item.statModifier[Dexterity] << "\n";             // Display dexterity mod
        if (item.statModifier[Intelligence] != 0)                                           // Check if intelligence mod is non-zero
            std::cout << "Intelligence: " << item.statModifier[Intelligence] << "\n";       // Display intelligence mod
        if (item.statModifier[Wisdom] != 0)                                                 // Check if wisdom mod is non-zero
            std::cout << "Wisdom: " << item.statModifier[Wisdom] << "\n";                   // Display wisdom mod
        if (item.statModifier[Constitution] != 0)                                           // Check if constitution mod is non-zero
            std::cout << "Constitution: " << item.statModifier[Constitution] << "\n";       // Display constitution mod
    } else {                                                                                // If no stat mods exist
        std::cout << "This item does not affect any stats.\n";                              // Display message indicating no mods
    }

    if (item.classification == WEAPON) {                                                    // If item is weapon, show damage range
        std::cout << "Damage Range: " << item.minDamage << " - " << item.maxDamage << "\n"; // Show damage for weapons
    }
}

//------------------------------- FUNCTION TO CHECK IF ITEM IS EQUIPPED -------------------------------------------
bool Player::isEquipped(const Item& item) const {
    for (const auto* equippedItem : equippedItems) {                                        // Iterate through equipped items using pointers
        if (equippedItem == &item) {                                                        // Compare pointers directly
            return true;                                                                    // Return true if item is equipped
        }
    }
    return false;                                                                           // Return false if item is not equipped
}

//------------------------------- FUNCTION TO EQUIP AN ITEM -----------------------------------------------
bool equipItem(Player& player, int itemIndex) {
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.inventory.size())) {          // Validate item index
        std::cout << "Invalid item selection.\n";
        return false;
    }

    Item* itemToEquip = &player.inventory[itemIndex];                                       // Step 1: Get the item to equip

    if (player.isEquipped(*itemToEquip)) {                                                  // Step 2: Check if the item is already equipped
        std::cout << itemToEquip->name << " is already equipped.\n";
        return false;
    }

    player.equippedItems.push_back(itemToEquip);                                            // Step 3: Add the item to equipped items
    std::cout << "Equipped " << itemToEquip->name << "!\n";

    for (int i = 0; i < StatCount; ++i) {                                                   // Step 4: Update player stats based on item mods
        player.stats[i] += itemToEquip->statModifier[i];
    }

    return true;                                                                            // Return true indicating successful equip
}

//------------------------------- FUNCTION TO UNEQUIP AN ITEM ---------------------------------------------
bool unequipItem(Player& player, int itemIndex) {
    if (itemIndex < 0 || itemIndex >= static_cast<int>(player.equippedItems.size())) {      // Validate item index
        std::cout << "Invalid item selection.\n";
        return false;
    }

    Item* itemToUnequip = player.equippedItems[itemIndex];                                  // Step 1: Get the item to unequip

    player.equippedItems.erase(player.equippedItems.begin() + itemIndex);                   // Step 2: Remove the item from equipped items

    std::cout << "Unequipped " << itemToUnequip->name << "!\n";                             // Display message that item was unequipped

    for (int i = 0; i < StatCount; ++i) {                                                   // Step 3: Update player stats by removing item mods
        player.stats[i] -= itemToUnequip->statModifier[i];
    }

    return true;                                                                            // Return true indicating successful unequip
}

//------------------------------- FUNCTION TO CHECK FOR WEAPON -------------------------------------------
void checkForWeapon(Player& player) {
    bool hasWeapon = false;                                                                 // Flag to check if player has a weapon equipped

    for (const auto* item : player.equippedItems) {                                         // Loop through equipped items using pointers
        if (item->classification == WEAPON) {                                               // If an item is classified as a weapon
            hasWeapon = true;                                                               // Set flag to true if a weapon is found
            break;                                                                          // Exit loop as soon as a weapon is found
        }
    }

    if (!hasWeapon) {                                                                       // If no weapon equipped, prompt the player
        std::cout << "Warning: You are without a weapon. This might not end well in combat!\n";           
        std::cout << "If you wanna punch and kick your way out, be my guest, but you've been warned.\n";

        char weapResponse;                                                                  // Variable to store user response
        while (true) {
            std::cout << "Do you want to proceed without a weapon? (y/n): ";              
            std::cin >> weapResponse;

            if (weapResponse == 'y' || weapResponse == 'Y') {                               // If player is okay without a weapon
                std::cout << "Alright, but be careful out there!\n";                        // Warning confirmation
                break;                                                                      // Exit loop to continue gameplay
            } else if (weapResponse == 'n' || weapResponse == 'N') {                        // If player wants to equip a weapon
                std::cout << "Let's head back to the inventory to equip a weapon.\n";
                
                int itemChoice;                                                             // Variable to store user's item choice
                
                
                while (true) {                                                              // Prompt user: select weapon from inventory
                    std::cout << "Enter the number of the item to equip from your inventory: ";
                    std::cin >> itemChoice;

                    if (std::cin.fail() || itemChoice <= 0 || itemChoice > static_cast<int>(player.inventory.size())) { // Validate input
                        std::cout << "Invalid item selection. Please enter a valid item number.\n";
                        std::cin.clear();                                                   // Clear the error state of std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    } else {
                        equipItem(player, itemChoice - 1);                                  // Call [equipItem] with chosen item
                        break;                                                              // Exit loop after equipping
                    }
                }
                break;                                                                      // Break loop after attempting to equip a weapon
            } else {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";                   // Handle invalid input
            }
        }
    }
}
