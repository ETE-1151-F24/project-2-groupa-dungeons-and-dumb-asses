#pragma once  // Ensure this header file is included only once during compilation

// #ifndef GAMEHEADERELI_H
// #define GAMEHEADERELI_H

//+++++++++++++++++++++++++++++ Required standard libraries for the project ++++++++++++++++++++++++++++
#include <vector>                                                   // Required for using std::vector to store dynamic data collections
#include <array>                                                    // Required for using std::array to handle fixed-size stat arrays
#include <iostream>                                                 // Required for input and output operations (cin, cout)
#include <string>                                                   // Required for player names, commands, etc.
#include <chrono>                                                   // Required for time-based operations
#include <thread>                                                   // Required for pauses in strobing effect
#include <limits>                                                   // Required for clearing input buffer
#include <cctype>                                                   // Required for checking digit characters
#include <algorithm>                                                // Required for using std::max
#include <cstdlib>                                                  // Required for random number generation (rand())
#include <ctime>                                                    // Required for seeding random number generation (time)
#include <iomanip>
#include <random>
#include <map>

#include <nlohmann/json.hpp>

using json = nlohmann::json;



#include "Character_develop_functs.h"
#include "combatfighting.h"
#include "Game_functions_eli.h"
#include "Game_inventory_functions.h"
#include "gameItems.h"
#include "item_constructors_dmg_shifts.h"
#include "Leveling.h"
#include "MapFunctions.h"
#include "ProgressHandling.h"
#include "SpellHandling.h"


// #endif // GAMEHEADERELI_H
