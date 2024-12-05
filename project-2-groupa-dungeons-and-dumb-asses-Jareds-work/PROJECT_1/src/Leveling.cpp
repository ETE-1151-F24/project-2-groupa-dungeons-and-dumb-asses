//Leveling.cpp
#include<iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include "SpellHandling.h"
#include "Leveling.h"
using namespace std;
 //-------------------------------------------------------------------------------------------
 //  this is the function for displaying the health of the character
 //-------------------------------------------------------------------------------------------

 void displayHealthDetails(const HealthModifiers& modifiers, int baseConstitution, int level) {
    int totalHealth = modifiers.calculateTotalHealth(baseConstitution, level);
    std::cout << "--- Health Details ---\n";
    std::cout << "Base Constitution: " << baseConstitution << " -> " << baseConstitution * 2 << " HP\n";
    std::cout << "Level: " << level << " -> " << level * 6 << " HP\n";
    std::cout << "Permanent Modifiers: " << modifiers.constitutionMod + modifiers.levelMod << " HP\n";
    std::cout << "Temporary Modifiers: " << modifiers.temporaryMod << " HP\n";
    std::cout << "Total Health: " << totalHealth << " HP\n";
}





// ---------------------------experience benchmarks
     // -------------------------vector that stores the XP Benchmarks
    // Map for storing XP benchmarks with levels as keys these are static and will not change
    std::map<int, int> xpBenchmarks = {
        {1, 0},       {2, 150},    {3, 450},    {4, 1350},   {5, 3250},
        {6, 7000},    {7, 11500},  {8, 17000},  {9, 24000},  {10, 32000},
        {11, 42500},  {12, 50000}, {13, 60000}, {14, 72500}, {15, 87500},
        {16, 105000}, {17, 125000},{18, 150000},{19, 177500},{20, 205000}
    };



//-------------------------------------------------------------------------------------------
// Function to determine the player's level using a map
//-------------------------------------------------------------------------------------------

int getLevel(int xp, const std::map<int, int>& xpBenchmarks) {
    int level = 1;
    for (const auto& [lvl, threshold] : xpBenchmarks) {
        if (xp >= threshold) {  //the threshold is established in the map for the xpbenchmarks
            level = lvl;
        } else {
            break; // Stop checking once XP is less than the threshold
        }
    }
    return level;
}




//-------------------------------------------------------------------------------------------
// Function to award XP after combat, puzzles, or quests
//-------------------------------------------------------------------------------------------
void awardXP(Player& player, int amount, const std::map<int, int>& xpBenchmarks,
             const std::vector<nlohmann::json>& availableSpells) {
    int oldLevel = getLevel(player.experience, xpBenchmarks);                   // Determine current level
    player.experience += amount;                                                // Add XP to player's total
    int newLevel = getLevel(player.experience, xpBenchmarks);                   // Recalculate level

    std::cout << "You earned " << amount << " XP!\n";

    if (newLevel > oldLevel) {
        std::cout << "Congratulations! You leveled up to Level " << newLevel << "!\n";
        player.level = newLevel;                                                // Update the player's level
        player.healthModifiers.levelMod = newLevel * 6;                         // Update health based on level

        // Grant new spells upon leveling up
        grantSpellsOnLevelUp(player, availableSpells);

        // Pass healthModifiers directly
        displayHealthDetails(player.healthModifiers, player.stats[Constitution], player.level);  // Display updated health
    } else {
        std::cout << "You are now at " << player.experience << " XP, Level " << newLevel << ".\n";
    }
}

//-------------------------------------------------------------------------------------------
// Function to display health details
//-------------------------------------------------------------------------------------------






/*void lvl (int l [2], int stats [6])
{
    int a = 6;
    while (l[2] >= l[1]*10)
    {
        l[1] +=1;
        l[2] -=l[1]*10;
        std::cout<< " Where would you like to put your stat point\n 1:Strength:" << stats[0] << "\n2:Dexterity: "<< stats[1]<<"\n3:Intelligence:" << stats[2] << "\n4:Wisdom: "<< stats[3]<<"\n5:Constitution:" <<stats[4];
        std::cin >> a;
        a +=1;
        while (a < 1 || a > 5)
        {
            std::cout<< "Enter another value [1-5]:";
            std::cin >> a;
            a +=1;
        }
        
        stats[a] +=1;
        stats[5] = stats[4]*(1+l[1]/10);
        
    }
}*/
/*int fight(int Stats [6], int lvl)
{
    const int MaxHP =Stats[6];
    int z;
    int c = rand() %20;
    int eHP= rand()%lvl * 10;
    int eStr= rand()%lvl * 10;

    std::cout << "Enemy has " << eHP << " Stats[6], and " << eStr << " Str\n";

    
    while (eHP>0){
        std::cout << "What would you like to do: \n 1:Attack" << " 2:Magic\n";
        std::cin >> z;
        if ( z == 1)
        {
            c = rand() %20;
            if (c<=(5))
            {
                Stats[6] = Stats[6]-1;
                std::cout << "You fell and took 1 damage, your health is " << Stats[6] << std::endl;
            } else if(c >= 17 )
            {
                eHP = eHP - Stats[0]*2;
                std::cout << "WOW YOU HIT A CRIT AND DID " << Stats[0]*2 << " DAMAGE. Enemy has " << eHP << " health\n";
            }else
            {
                eHP = eHP - Stats[0];
                std::cout << "You Attacked and did " << Stats[0] << " damage. Enemy has " << eHP << " health\n";
            }

        } else if( z ==2)
        {
            std::cout << "What would you like to do: \n 1:Heal[1 MP] 2:Dino Nuggets[4 MP]\n";
            std::cin >> z;
            if (z == 1 && Stats[1] >1)
            {
                Stats[1] = Stats[1] -1;
                std::cout << "You used 1 MP to Heal\n";
                if (MaxHP < (Stats[6] + 5))
                {
                    Stats[6] = MaxHP;
                    std::cout << "You healed to max Stats[6], you now have " << Stats[6] << "Stats[6]\n";
                }else 
                {
                    Stats[6] = Stats[6] +5;
                    std::cout << "You healed 5 Stats[6], you now have " << Stats[6] << "Stats[6]\n";
                    std::cout << "you have " << Stats[1] <<" MP left\n";
                }
                
            }else if (z == 2 && Stats[1] > 4)
            {
                Stats[1] = Stats[1] -4;
                eHP = eHP - (3*Stats[0]);
                std::cout << "You used 4 MP to use Dino Nuggets and dealt " << 3*Stats[0] <<" damage. Enemy has " << eHP << "health\n";
                std::cout << "you have " << Stats[1] <<" MP left\n";
            } else 
            {
                std::cout << "You tried to use magic but couldn't. You looked stupid, the enemy laughed at you.\n";
            }
            
        }
        if (eHP > 0)
        {
            std::cout << "Now its the enemy's turn \n";
            c = rand() %20;
            if (c<=(2))
            {
                std::cout << "You dodged the enemy's attack\n";
            }else
            {
                Stats[6] = Stats[6] - eStr;
                std::cout << "The enemy hit you for " << eStr << " damage, you have " << Stats[6] << "Stats[6] left\n";
                if ( Stats[6] <=0 )
                {
                std::cout << "*sighs*...I expected better of you... would you like to try again [1:Yes 2:No]: ";
                std::cin >> z;
                if (z == 1)
                {
                    eHP = 0;
                }else
                {
                    std::cout << "Of course you give up, you always give up goodbye...";
                    Stats[6] = Stats[6] -1;
                    eHP =0;
                }
                
                }
            }
        }
    }
    return Stats[6];
}*/