//GameMainStuff.cpp
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
//include the flashing logo intro similar to the wordsalad tosser

#include "Game_functions_eli.cpp"
#include "GameHeaderEli.h"


/*Game flow
-Welcome message
    // Call the function to display the strobing title
    printStrobingText(title, duration);

    // --------------------WELCOME MESSAGE--------------------------
    std::cout << "Welcome to 'Goblins & Glittery S***!'\n\n";
    std::cout << "Brace yourself for a ridiculous adventure where goblins are annoying, magic is overrated,\n";
    std::cout << "and you're probably going to make some terrible decisions. But hey, that’s half the fun!\n";
    std::cout << "Collect shiny crap, survive questionable life choices, and try not to die... too much.\n\n";

    // ---------------------TITLE DISPLAY---------------------------
    std::string title = "Goblins & Glittery S*** !";                         maybe initialize as a global
    int duration = 5;  // Duration for strobing effect in seconds*/


#include <iostream>
#include <string>
#include <limits>
#include <cctype>  // For std::isdigit

//------------------------------------ Function to get the player's name
std::string getPlayerName() {
    std::string PlayerName;  // Variable to store the player's name
    std::cout << "What is your name, adventurer? ... you know, the type of thing someone goes by" << std::endl;
    std::cout << "when they are on a thirst-trappy voyage for peril and riches." << std::endl;
    std::getline(std::cin, PlayerName);  // Use getline to capture the full name, including spaces
    return PlayerName;  // Return the captured name
}

//-------------------------------------- Function to check if a string is a valid number
bool isNumber(const std::string& str) {
    // Loop through each character in the string
    for (char const &c : str) {
        if (!std::isdigit(c)) return false;  // If any character is not a digit, return false
    }
    return true;  // If all characters are digits, return true
}

//------------------------------- Function to show class description and stat focus based on the player's selection
void showClassDescription(int classChoice) {
    switch (classChoice) {  // Switch statement based on the class number
        case 1:
            // Output the Warrior class description and its stat focus
            std::cout << "Warrior: A strong melee fighter, excels in physical combat with high strength and constitution.\n";
            std::cout << "Stat focus: Strength and Constitution.\n";
            break;
        case 2:
            // Output the Rogue class description and its stat focus
            std::cout << "Rogue: A dexterous thief with stealth and agility, excelling in quick strikes and critical hits.\n";
            std::cout << "Stat focus: Dexterity and Intelligence.\n";
            break;
        case 3:
            // Output the Mage class description and its stat focus
            std::cout << "Mage: A master of the arcane arts, casting powerful spells with high intelligence and wisdom.\n";
            std::cout << "Stat focus: Intelligence and Wisdom.\n";
            break;
        case 4:
            // Output the Cleric class description and its stat focus
            std::cout << "Cleric: A divine healer and protector, wielding holy magic to heal and protect allies.\n";
            std::cout << "Stat focus: Wisdom and Constitution.\n";
            break;
        case 5:
            // Output the Ranger class description and its stat focus
            std::cout << "Ranger: A skilled marksman and survivalist, excelling in ranged combat and nature-based magic.\n";
            std::cout << "Stat focus: Dexterity and Wisdom.\n";
            break;
        default:
            std::cout << "Invalid class selection.\n";  // Handle invalid class numbers
            break;
    }
}

//--------------------------- Function to confirm the player's class choice
bool confirmClassChoice() {
    std::string confirmation;                                               // Variable to store player yes/no confirmation
    while (true) {                                                          //loop until a valid input is given
        std::cout << "Does this sound like a class you want to belong to? (yes/no): ";
        std::cin >> confirmation;                                           //record the players confirmation choice

        for (auto& ch : confirmation) ch = std::tolower(ch);                //Convert input to lowercase for case-insensitive comparison

        if (confirmation == "yes") {                                        // If player confirms with "yes"
            return true;                                                    // Return true, indicating confirmation
        } else if (confirmation == "no") {                                  // If player declines with "no"
            return false;                                                   //Return false, indicating no confirmation
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'.\n";    // Error message for invalid input
        }
    }
}

//------------------------------ Function to display classes, allow selection, and handle confirmation
void displayClasses() {
    std::string playerInput;  // Variable storing playerinput for class selection


    std::cout << "What type of adventurer would you like to be?" << std::endl;      // Display message asking player to choose a class
    std::cout << "(choose a number from the list below)" << std::endl << std::endl;

    std::cout << "1. Warrior\n2. Rogue\n3. Mage\n4. Cleric\n5. Ranger\n";           // List the available classes                  
 
    std::cout << "Enter a number to select a class: ";                              //Ask player to enter number corresponding to class
    std::cin >> playerInput;                                                        //record player's input

// Check if the input is a valid number and is between 1 and 5
    if (isNumber(playerInput) && (playerInput == "1" || playerInput == "2" || playerInput == "3" || playerInput == "4" || playerInput == "5")) {
        int classChoice = std::stoi(playerInput);                                   //Convert input string to an integer using [stoi]
        showClassDescription(classChoice);                                          //Display class description after selection

        // Ask the player to confirm their class choice
        if (confirmClassChoice()) {

            std::cout << "Awesome-sauce! You have decided to be a "                 // Congratulate the player on their choice and proceed to the next step
                      << (classChoice == 1 ? "Warrior" : classChoice == 2 ? "Rogue" : classChoice == 3 ? "Mage" : classChoice == 4 ? "Cleric" : "Ranger") 
                      << ".\n";
            
            std::cout << "Now, let's talk about your base statistics...\n";         // message indicating Procession to next part (base statistics and rolling for them)
        } else {
            
            std::cout << "Okay, let's choose a different class then.\n";            //If player decline class, restart class selection process
            displayClasses();                                                       //Recursive call to restart the class selection
        }
    } 
    else {
        std::cout << "Invalid input. Please select a number from 1-5." << std::endl;  // Error message for invalid input
    }
}
//--------------------------------------------------------------------------------------------------------

// Statistics array to hold string representations of attributes
std::string statistics[] = {"Strength", "Dexterity", "Wisdom", "Intelligence", "Constitution", "Charisma"};






int main() {
   
}


/*-pick a charachter class message [playerClass]
-list char classes
"which class would you like"
        for each class, 
            show primary stat fields
            explain the class
        give option to keep that class or chose another
once class is chosen, roll for stats and give 4 additional points to spend
then display the stats for the character

playerIdentity   Class: [playerClass]   
---------STATICS---------------------------
streng           STG [ streng ]......attack +1 for every 3, lift/pull/push/throw +1 every 3, +1 range every 6
dexter           DEX [ dexter ]......speed +1 for every 3, range +1 for every 4, number of attacks +1 every 6
wisdom           WIS [ wisdom ]......magic reserve +1 for every 3,  magic duration (rounds) +1 every 6
intell           ITL [ intell ]......attack +1 every 5......magic power +1 every 3       
consti           CON [ consti ]......defense +1 every 3 points....healing +1 every 4...health +1 every 2
charis           CRM [ charis ]......healing +1 every 5....magic power +1 every 4....

---------ATTRIBUTES-----------------------
magic reserve  how much mana
magic power    magic effect multiplier
attack         dealing damage on attack
defense        how much damage is ignored from attackers
speed          who goes first in combat, how far you can move a turn
range          how far your attack or spell can reach
health         how many hitpoints you have
healing        healing effect multiplier


---------------ABILITIES---------------------
each class has 4 skills or attacks
ranged   close  special   magical  itemspecial


-----------------INVENTORY---------------------
the player has an inventory in [sakkysac] that holds 10 items
sakkysac[]:{,,,,,,,,,}

you will be allowed to get one item from the store
wand,+1 mag                                
   ring,                        +1spd+1range  
   shield,                      +3 defense-1speed   
   boots,                       +1speed+1defe  
   chestplate,                  +2 defense -2 magic  
   sword,                       +2 attack
   axe,                         +3 attack-1 speed
   staff,                       +3 magic -1 defense +1 range
   bow/quiver,                  +1 damage +3range
   teddybear(owlbear golem),    +4attack -2 health
   arcane spell scroll          +3 magic reserve, +1 magic power, -2 health


then be able to have a thing that calls up player status that shows,
name, class, statics
abilities, INVENTORY AND ATTRIBUTES
*/

}
