//Game_functions_eli.h


#ifndef GAME_FUNCTIONS_ELI_H
#define GAME_FUNCTIONS_ELI_H

#include <string>
#include <array>
#include <vector>
#include "GameHeaderEli.h"  // Make sure this header file includes all necessary definitions
#include "Game_inventory_functions.h"
// Function prototypes

// Function to print strobing text effect for the title
void printStrobingText(const std::string& text, int duration);

// Function to run the main game loop
void runGameLoop(Player& player);

// // Other helper function prototypes if necessary
// // For example, for handling inventory and stats
// void displayItemDetails(const Item& item);  // If not already declared elsewhere

// // Map generation and movement functions (presuming these are defined elsewhere)
// void MapGen(int map[5][5]); 
// void Movement(int map[5][5], int stats[6]);

#endif // GAME_FUNCTIONS_ELI_H