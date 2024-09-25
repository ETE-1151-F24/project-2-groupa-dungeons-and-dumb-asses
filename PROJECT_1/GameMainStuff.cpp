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



// Function to get character name
std::string getPlayerName() {
std::string PlayerName;
std::cout << "What is your name, adventurer? ... you know, the type of thing someone goes by" << std::endl;
std::cout << "when they are on a thirst-trappy voyage for peril and riches." << std::endl;
std:: getline(std::cin, PlayerName);  // Read full line for name using getline operator 
}
// Function to display available classes
void displayClasses() {
    int PlayerClass;                                                                         //initialize PlayerClass integer  
    std::cout << "What type of adventurer would you like to be"<< std::endl; 
    std::cout <<"(chose a number from the list below)" << std::endl << std::endl;
    std::cout << "1. Warrior\n2. Rogue\n3. Mage\n4. Cleric\n5. Ranger\n";                    //List of all of the options for 
    std::cout << "Enter a number to select a class, or press 'I' to get info about a specific class." << std::endl;
    std::cin >> PlayerClass;
}



std::string statistics[]{streng,dexter,wisdom,intell,consti,charis};


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
