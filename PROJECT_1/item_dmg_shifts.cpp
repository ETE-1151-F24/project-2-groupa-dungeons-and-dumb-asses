// //item_dmg_shifts.cpp

// #include "GameHeaderEli.h"                     // Include game-specific headers containing class definitions and enums
// #include <algorithm>                           // Required for std::max
// #include <cstdlib>                             // Required for random number generation (rand())
// #include <ctime>                               // Required for seeding random number generation (time)

// // Function to calculate damage based on combat type
// int Item::calculateDamage(int distance) {
//     if (combatType == RANGED) {
//         return calculateRangedDamage(distance, rangeModifier, minDamage, maxDamage); // Call ranged damage calculation
//     } else if (combatType == MELEE) {
//         return calculateMeleeDamage();   // Call melee damage calculation
//     }
//     return 0;                            // Default return [melee] if combat type is not applicable
// }

// // Private function to calculate damage for ranged weapons based on distance
// int Item::calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage) {
//     int damage = 0;                       // Initialize damage to 0

//     if (distance == 1) {
//         // If the target is right next to the user, reduce the damage range by 1
//         damage = std::max((std::rand() % (maxDamage - minDamage + 1)) + minDamage - 1, 1);
//                                                                                         // Reduce min and max by 1, ensure minimum is 1
//     } else if (distance <= maxRange) {
//                                                                                         // If the target is within regular range, 
//                                                                                         // roll for damage between [minDamage] and [maxDamage]
//         damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;               // Roll damage within normal range
//     } else {
//         // If the target is beyond the range max
//         damage = (std::rand() % (maxDamage - minDamage + 1)) + minDamage;               // Start with damage within normal range
//         damage -= (distance - maxRange);                                                // Reduce damage for each square beyond max range
//         damage = std::max(damage, 1);                                                   // Ensure minimum damage of 1
//     }

//     return damage;                                                                      // Return calculated damage
// }

// // Private function to calculate damage for melee weapons (simplified logic)
// int Item::calculateMeleeDamage() {
//     // Simple melee damage calculation between minDamage and maxDamage
//     return (std::rand() % (maxDamage - minDamage + 1)) + minDamage; // Roll damage within min and max range
// }
