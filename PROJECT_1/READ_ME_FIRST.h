#ifndef READ_ME_FIRST_H
#define READ_ME_FIRST_H

/* 
 * Overview of Project Files for Goblins & Glittery S***!
 * ======================================================
 * 
 * This document provides a detailed overview of the various source files used in the project,
 * explaining their roles and functionalities within the game. Each source file contains specific
 * functions and classes that, when combined, form the entire game experience.
 * 
 * The main executable for this project is `gameMainStuff.exe`. Please note that this executable 
 * must be compiled on the appropriate system to ensure compatibility and proper execution.
 * Below is a description of each file in the project:
 * 
 * 1. **game_mainstuff.cpp**
 *    - **Purpose**: This file is responsible for setting up the main structure of the game.
 *    - **Details**: It defines the flow of the game by calling the necessary functions in the correct order.
 *      It acts as the entry point for initiating gameplay by linking together various aspects of the game logic.
 * 
 * 2. **game_functions_eli.cpp**
 *    - **Purpose**: This file contains auxiliary functions that handle the dynamic user experience.
 *    - **Details**: It includes the function responsible for the strobing title screen effect, 
 *      as well as the function to manage the main game loop. The game loop keeps the menu interactions 
 *      and the game flow consistent, allowing the user to continue interacting with the game until they decide to quit.
 * 
 * 3. **character_develop_functs.cpp**
 *    - **Purpose**: This file handles character creation, development, and related mechanics.
 *    - **Details**: It manages the character's dice roll-based stat allocation, displays class descriptions, 
 *      and constructs the player character based on user choices. The constructors are used to build and initialize 
 *      the player's class attributes and stats, ensuring each player character is properly set up for gameplay.
 * 
 * 4. **game_inventory_functions.cpp**
 *    - **Purpose**: This file manages the inventory system of the game.
 *    - **Details**: It contains the functions responsible for interactions with the player's inventory. These interactions include 
 *      equipping and unequipping items, displaying details about each item, and showing whether items are equipped 
 *      or stored in the player's inventory. It provides the core functionality of item management for the game.
 * 
 * 5. **game_items.cpp**
 *    - **Purpose**: This file defines the items that can be used in the game.
 *    - **Details**: It includes the class definitions and constructors for game items, allowing for the creation of new items 
 *      and customization of their properties. This file is key for expanding the game's content, as new items can be 
 *      easily added by using the provided structures and constructors.
 * 
 * 6. **GameHeaderEli.h**
 *    - **Purpose**: This header file provides the essential declarations used throughout the game.
 *    - **Details**: It contains the preliminary setup for the game, including the player class, item class, and their constructors. 
 *      It also defines several global variables, enumerations, and function prototypes that will be used in the game logic. 
 *      Additionally, it ensures that all necessary libraries are included and ready to use before the game begins.
 * 
 * Note:
 * -----
 * Each of the source files plays an important role in creating a cohesive and immersive gaming experience. 
 * Ensure that each source file is compiled correctly and linked together to produce a functional executable. 
 * Follow the flow from character creation, title display, to inventory management to understand the lifecycle of game interaction.
 * 
 * Enjoy building and enhancing 'Goblins & Glittery S***!'!
 */

#endif // READ_ME_FIRST_H
