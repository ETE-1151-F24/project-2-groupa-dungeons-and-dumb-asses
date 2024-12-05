#include <iostream>                                                // Required for input and output
#include <cstdlib>                                                 // Required for random number generation
#include <ctime>                                                   // Required for seeding random number generation
#include "GameHeaderEli.h"                                         // Include the game header file
#include "combatfighting.h"
#include "Character_develop_functs.h"

// ------------------------------- FUNCTION TO GENERATE THE MAP -------------------------------
void MapGen(int map[5][5]) {
    srand(time(0));                                                // Seed random number generator with current time
    int stairCoords[2];                                            // Coordinates for the stairs

    for (size_t row = 0; row < 5; row++) {                         // Loop through rows of the map
        for (size_t col = 0; col < 5; col++) {                     // Loop through columns of the map
            if (row == 2 && col == 2) {                            // If at the center of the map
                map[row][col] = 1;                                 // Set player's starting position
            } else {
                map[row][col] = (rand() % 100 < 25) ? 2 : 0;       // 25% chance to place an enemy (2), otherwise empty (0)
            }
        }
    }

    do {
        stairCoords[0] = rand() % 5;                               // Random row for stairs
        stairCoords[1] = rand() % 5;                               // Random column for stairs
    } while (stairCoords[0] == 2 && stairCoords[1] == 2);          // Ensure stairs are not placed at the center

    map[stairCoords[0]][stairCoords[1]] = 3;                      // Place stairs on the map

    std::cout << "\033[2J\033[1;1H";                               // Clear console for better visualization
    for (size_t row = 0; row < 5; row++) {                         // Loop through rows to display the map
        for (size_t col = 0; col < 5; col++) {                     // Loop through columns to display the map
            std::cout << map[row][col] << " ";                     // Print map element with a space for readability
        }
        std::cout << std::endl;                                    // Move to the next line after each row
    }
}

// ------------------------------- FUNCTION TO HANDLE PLAYER MOVEMENT -------------------------------
void Movement(int map[5][5], Player& player) {
    int playerX = 2, playerY = 2;               // Player starts at the center of the map
    int floor = 1;                              // Initialize the floor number

    while (true) {                              // Infinite loop for continuous movement
        std::string response;                   // Store player input for movement
        std::cout << "What would you like to do (up, down, left, right): ";
        std::cin >> response;                   // Get player response

        if (response == "right" && playerX + 1 < 5) {   // If moving right and within map bounds
            playerX++;                                  // Update player's X-coordinate
        } else if (response == "left" && playerX - 1 >= 0) {  // If moving left and within map bounds
            playerX--;                                  // Update player's X-coordinate
        } else if (response == "down" && playerY + 1 < 5) {   // If moving down and within map bounds
            playerY++;                                  // Update player's Y-coordinate
        } else if (response == "up" && playerY - 1 >= 0) {    // If moving up and within map bounds
            playerY--;                                  // Update player's Y-coordinate
        } else {
            std::cout << "Invalid move.\n";             // Display message for invalid movement
            continue;                                   // Skip to next iteration
        }

        if (map[playerY][playerX] == 2) {              // If player encounters an enemy
            fight(player, floor);                      // Pass the Player object to fight
        } else if (map[playerY][playerX] == 3) {       // If player reaches the stairs
            floor++;                                   // Increment floor number
            std::cout << "You found the stairs! Moving to floor " << floor << ".\n";
            MapGen(map);                               // Generate a new map for the next floor
        }
    }
}

