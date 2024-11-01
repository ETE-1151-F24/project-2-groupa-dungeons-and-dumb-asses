// Game_inventory_functions.cpp
#include "GameHeaderEli.h"                            // Include header file for necessary declarations

//------------------------------- FUNCTION TO DISPLAY PLAYER INVENTORY -------------------------------------------
void displayInventory(Player& player) {
    std::cout << "\n--- Your Inventory ---\n";

    const int totalWidth = 60;   // Total width for the entire display line

    for (size_t i = 0; i < player.inventory.size(); ++i) {
        const Item& item = player.inventory[i];                                 // Access current item in inventory
        std::string status = player.isEquipped(item) ? "(equipped)"             //@ this file LINES 115-122  // Set status to "(equipped)" if item is equipped
                                                     : "In your Sakky";         // Otherwise, set status to "In your Sakky"
        
        // Calculate remaining space for alignment
        int itemNumberWidth = 4; // Width for item numbering (e.g., "1. ")
        int statusWidth = static_cast<int>(status.length()); // Width of the status text
        int nameWidth = totalWidth - itemNumberWidth - statusWidth; // Width available for item name

        // Output the formatted line
        std::cout << std::left << std::setw(itemNumberWidth) << (i + 1) << ". "   // Display item number left-aligned
                  << std::setw(nameWidth) << std::left << item.name               // Display item name left-aligned with calculated width
                  << std::setw(statusWidth) << std::right << status << "\n";      // Display status right-aligned
    }

    while (true) {
        std::string response;
        std::cout << "\nWould you like to focus on an item? Enter the number or type 'no': "; // Ask if user wants to focus on an item
        std::getline(std::cin, response);                                                     // Get user's response

        if (response == "no") {                                                               // If user doesn't want to focus on an item
            break;                                                                            // Exit inventory loop
        }

        int itemChoice;
        try {
            itemChoice = std::stoi(response) - 1;                                             // Convert response to an index int
        } catch (std::exception& e) {
            std::cout << "Invalid input. Please enter a valid number.\n";                     // Handle invalid input
            continue;                                                                         // Restart loop
        }

        if (itemChoice < 0 || itemChoice >= static_cast<int>(player.inventory.size())) {
            std::cout << "Invalid item number. Please try again.\n";                          // Handle out of bounds item choice
            continue;                                                                         // Restart loop
        }

        Item& selectedItem = player.inventory[itemChoice];                                    // Get selected item reference

        std::string itemResponse;
        while (true) {
            std::cout << "\nWhat would you like to do with '" << selectedItem.name << "'?\n"; // Prompt actions for the selected item
            std::cout << "1. Read Description\n";                                  
            if (player.isEquipped(selectedItem)) {                                        //@ this file LINES 115-122    // If item is equipped
                std::cout << "2. Unequip Item\n";                                             // Provide unequip option
            } else {                                                                          // If item is not equipped
                std::cout << "2. Equip Item\n";                                               // Provide equip option
            }
            std::cout << "3. Back to Inventory\n";                                            // Provide option to go back to inventory
            std::getline(std::cin, itemResponse);                                             // Get user's choice

            if (itemResponse == "1") {                                                        // If user chooses to read description
                displayItemDetails(selectedItem);                                       //@ this file LINES 81-112      // Display item details
            } else if (itemResponse == "2") {                                                 // If user chooses to equip/unequip item
                if (player.isEquipped(selectedItem)) {                                  //@ this file LINES 115-122      // If item is equipped
                    player.unequipItem(&selectedItem);                                  //@ this file LINES 153-165      // Unequip item
                } else {                                                                      // If item is not equipped
                    player.equipItem(&selectedItem);                                    //@ this file LINES 126-148      // Equip item
                }
            } else if (itemResponse == "3") {                                                 // If user chooses to go back to inventory
                break;                                                                        // Break inner loop to redisplay inventory
            } else {
                std::cout << "Invalid input. Please enter 1, 2, or 3.\n";                     // Handle invalid input
            }
        }
    }
}


//------------------------------- FUNCTION TO DISPLAY ITEM DESCRIPTIONS -------------------------------------------
void displayItemDetails(const Item& item) {
    std::cout << "Item: " << item.name << "\nFlavor Description: " << item.flavorDescription // Print item details
              << "\nAbility: " << item.ability << "\n";                                      // Display ability of item

    bool hasModifiers = false;                                                               // Flag to check if there are any non-zero modifiers
    for (int i = 0; i < StatCount; ++i) {                                                    // Loop through all stat modifiers
        if (item.statModifier[i] != 0) {                                                     // Check if any modifier is non-zero
            hasModifiers = true;                                                             // Set flag to true if a non-zero modifier is found
            break;                                                                           // Exit loop since we only need to know if any modifier exists
        }
    }

    if (hasModifiers) {                                                                      // If there are stat modifiers, display them
        std::cout << "Stat Modifiers: \n";
        if (item.statModifier[Strength] != 0)                                                // Check if strength modifier is non-zero
            std::cout << "Strength: " << item.statModifier[Strength] << "\n";                // Display strength modifier
        if (item.statModifier[Dexterity] != 0)                                               // Check if dexterity modifier is non-zero
            std::cout << "Dexterity: " << item.statModifier[Dexterity] << "\n";              // Display dexterity modifier
        if (item.statModifier[Intelligence] != 0)                                            // Check if intelligence modifier is non-zero
            std::cout << "Intelligence: " << item.statModifier[Intelligence] << "\n";        // Display intelligence modifier
        if (item.statModifier[Wisdom] != 0)                                                  // Check if wisdom modifier is non-zero
            std::cout << "Wisdom: " << item.statModifier[Wisdom] << "\n";                    // Display wisdom modifier
        if (item.statModifier[Constitution] != 0)                                            // Check if constitution modifier is non-zero
            std::cout << "Constitution: " << item.statModifier[Constitution] << "\n";        // Display constitution modifier
    } else {                                                                                 // If no stat modifiers exist
        std::cout << "This item does not affect any stats.\n";                               // Display message indicating no modifiers
    }

    if (item.classification == WEAPON) {                                                     // If the item is a weapon, show its damage range
        std::cout << "Damage Range: " << item.minDamage << " - " << item.maxDamage << "\n";  // Show damage for weapons
    }
}

//------------------------------- FUNCTION TO CHECK IF ITEM IS EQUIPPED -------------------------------------------
bool Player::isEquipped(const Item& item) const {
    for (const auto* equippedItem : equippedItems) {                                         // Iterate through equipped items using pointers
        if (equippedItem == &item) {                                                         // Compare pointers directly
            return true;                                                                     // Return true if item is equipped
        }
    }
    return false;                                                                            // Return false if item is not equipped
}

//------------------------------- FUNCTION TO EQUIP AN ITEM -----------------------------------------------

void Player::equipItem(Item* item) {
    if (item->classification == WEAPON) {                                                   // Check if the item to equip is a weapon
        for (auto* equippedItem : equippedItems) {                                          // Iterate through currently equipped items
            if (equippedItem->classification == WEAPON) {                                   // If a weapon is already equipped
                std::cout << "You already have a weapon equipped: " << equippedItem->name << ".\n"; // Display current weapon
                std::cout << "Please unequip it before equipping another weapon.\n";        // Prompt to unequip before equipping a new weapon
                return;                                                                     // Exit the function if another weapon is equipped
            }
        }
    }

    if (isEquipped(*item)) {                                                                // Check if the item is already equipped
        std::cout << item->name << " is already equipped.\n";                               // Inform the user that the item is already equipped
        return;                                                                             // Exit the function if item is already equipped
    }

    equippedItems.push_back(item);                                                          // Add the item to equipped items
    std::cout << "Equipped " << item->name << "!\n";                                        // Display message indicating the item is equipped

    for (int i = 0; i < StatCount; ++i) {                                                   // Iterate over each player stat to update
        stats[i] += item->statModifier[i];                                                  // Add the stat modifiers of the equipped item to the player's stats
    }
}


//------------------------------- FUNCTION TO UNEQUIP AN ITEM ---------------------------------------------

void Player::unequipItem(Item* item) {
    auto it = std::find(equippedItems.begin(), equippedItems.end(), item);                  // Find item in equipped items
    if (it != equippedItems.end()) {                                                        // If item is found
        equippedItems.erase(it);                                                            // Remove item from equipped items
        std::cout << "Unequipped " << item->name << "!\n";

        for (int i = 0; i < StatCount; ++i) {                                               // Update player stats by removing item modifiers
            stats[i] -= item->statModifier[i];
        }
    } else {
        std::cout << item->name << " is not equipped.\n";
    }
}

//------------------------------- FUNCTION TO CHECK FOR WEAPON -------------------------------------------
void checkForWeapon(Player& player) {
 if (!player.hasEquippedWeapon()) {                //@Character_develop_functs.cpp LINES 7-14  // Use hasEquippedWeapon to check if player has a weapon   
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
                
                while (true) {                                                              // Prompt user to select a weapon from inventory
                    std::cout << "Enter the number of the item to equip from your inventory: ";
                    std::cin >> itemChoice;

                    if (std::cin.fail() || itemChoice <= 0 || itemChoice > static_cast<int>(player.inventory.size())) { // Validate input
                        std::cout << "Invalid item selection. Please enter a valid item number.\n";
                        std::cin.clear();                                                   // Clear the error state of std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    } else {
                        player.equipItem(&player.inventory[itemChoice - 1]);          //@ this file LINES 126-148       // Call equipItem with chosen item
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
