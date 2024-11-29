//Leveling.cpp
#include<iostream>
#include <cstdlib>
#include <ctime>
#include "GameHeaderEli.h"
using namespace std;





int xp;


//GENERIC FUNCTION FOR GIVING OUT XP





// --------------------------------Function to determine the player's level
int getLevel(int xp, const std::vector<int>& xpBenchmarks) {
    for (int i = xpBenchmarks.size() - 1; i >= 0; --i) {
        if (xp >= xpBenchmarks[i]) {
            return i + 1; // Levels are 1-indexed
        }
    }
    return 1; // Default to level 1 if below all benchmarks
}
// ---------------------------experience benchmarks
     // -------------------------XP Benchmarks
    std::vector<int> xpBenchmarks = {
        0, 150, 450, 1350, 3250, 7000, 11500, 17000, 24000, 32000,
        42500, 50000, 60000, 72500, 87500, 105000, 125000, 150000, 177500, 205000
    };

        // Determine and display the player's level
int level = getLevel(xp, xpBenchmarks);
std::cout << "Your level is: " << level << "\n";

// Function to award XP after a combat or puzzle
void awardXP(int& xp, int amount, const std::vector<int>& xpBenchmarks) {
    int oldLevel = getLevel(xp, xpBenchmarks); // Determine current level
    xp += amount;                             // Add the XP reward
    int newLevel = getLevel(xp, xpBenchmarks); // Recalculate level

    std::cout << "You earned " << amount << " XP!\n";
    if (newLevel > oldLevel) {
        std::cout << "Congratulations! You leveled up to Level " << newLevel << "!\n";
    } else {
        std::cout << "You are now at " << xp << " XP, Level " << newLevel << ".\n";
    }
}



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
int fight(int Stats [6], int lvl)
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
}