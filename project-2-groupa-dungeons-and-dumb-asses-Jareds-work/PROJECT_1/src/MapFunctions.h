#ifndef MAPFUNCTIONS_H
#define MAPFUNCTIONS_H

#include <iostream>           // Required for input and output operations
#include "GameHeaderEli.h"    // Include the game header for shared classes and functions
#include "combatfighting.h"   // Include combat-related functionality

// ------------------------------ FUNCTION DECLARATIONS ------------------------------

// Function to generate a 5x5 map for the game
// - Places the player at the center
// - Randomly places enemies (25% chance) and a stair location
// Parameters:
// - map: 5x5 array representing the game map
void MapGen(int map[5][5]);

// Function to handle player movement on the map
// - Updates the player's position based on input
// - Triggers combat or floor progression when applicable
// Parameters:
// - map: 5x5 array representing the game map
// - player: Player object for tracking player stats and progress
void Movement(int map[5][5], Player& player);

#endif // MAPFUNCTIONS_H
