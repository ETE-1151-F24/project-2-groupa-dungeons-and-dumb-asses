#include "GameHeaderEli.h"
#include <iostream>


//-------------------------------Function to display item descriptions
void displayItemDetails(const Item& item) {
    std::cout << "Item: " << item.name << "\nDescription: " << item.description << "\nAbility: " << item.ability << "\n"; // Display item details

    bool hasModifiers = false;                     // Flag to check if there are any non-zero modifiers
    for (int i = 0; i < StatCount; ++i) {          // Loop through all stat modifiers
        if (item.statModifier[i] != 0) {           // Check if any modifier is non-zero
            hasModifiers = true;                   // Set flag to true if a non-zero modifier is found
            break;                                 // Exit loop since we only need to know if any modifier exists
        }
    }

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

        // Display damage range if applicable
        if (type == WEAPON) {
            std::cout << "Damage Range: " << damageRange.first << " - " << damageRange.second << "\n";
        }
    }