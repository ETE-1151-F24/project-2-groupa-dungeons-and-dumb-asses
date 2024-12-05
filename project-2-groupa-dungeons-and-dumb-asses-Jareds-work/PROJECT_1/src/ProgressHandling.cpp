//ProgressHandling.cpp
/*this is where im going to store multiple vectors that has 1 or 0 values based to reflect yes or no for 
missions completed 
puzzles solved
visited already
waypoints activated
items in specific locations
items in perosnal inventory
items available in shops
count of specific enemies defeated
bosses defeated
    */
#include "GameHeaderEli.h"
#include "ProgressHandling.h"
#include "ProgressHandling.h"
#include <iostream>
#include <fstream>
#include <filesystem> // For file operations

namespace fs = std::filesystem;

// Constructor to initialize progress and save slots
ProgressManager::ProgressManager(size_t missionCount, size_t puzzleCount, size_t locationCount,
                                 size_t waypointCount, size_t inventorySize, size_t shopItemCount,
                                 size_t enemyTypeCount, size_t bossCount)
    : missionsCompleted(missionCount, 0), puzzlesSolved(puzzleCount, 0),
      locationsVisited(locationCount, 0), waypointsActivated(waypointCount, 0),
      inventoryItems(inventorySize, 0), shopItemsAvailable(shopItemCount, 0),
      enemiesDefeated(enemyTypeCount, 0), bossesDefeated(bossCount, 0),
      characterClass("Unknown"), stats{0, 0, 0, 0, 0}, level(1),
      experience(0), currentHealth(10), maxHealth(10) {}

// Save progress to a specific slot
void ProgressManager::saveProgress(const std::string& slotName) {
    if (saveSlots.find(slotName) == saveSlots.end()) {
        saveSlots[slotName] = slotName + ".json"; // Default file path for the save slot
    }

    json saveData;
    saveData["missionsCompleted"] = missionsCompleted;
    saveData["puzzlesSolved"] = puzzlesSolved;
    saveData["locationsVisited"] = locationsVisited;
    saveData["waypointsActivated"] = waypointsActivated;
    saveData["inventoryItems"] = inventoryItems;
    saveData["shopItemsAvailable"] = shopItemsAvailable;
    saveData["enemiesDefeated"] = enemiesDefeated;
    saveData["bossesDefeated"] = bossesDefeated;

    saveData["characterClass"] = characterClass;
    saveData["stats"] = stats;
    saveData["level"] = level;
    saveData["experience"] = experience;
    saveData["currentHealth"] = currentHealth;
    saveData["maxHealth"] = maxHealth;

    std::ofstream outFile(saveSlots[slotName]);
    if (outFile.is_open()) {
        outFile << saveData.dump(4);
        outFile.close();
        std::cout << "Game progress saved to slot: " << slotName << ".\n";
    } else {
        std::cerr << "Error: Unable to save progress.\n";
    }
}

// Load progress from a specific slot
void ProgressManager::loadProgress(const std::string& slotName) {
    if (saveSlots.find(slotName) == saveSlots.end()) {
        std::cerr << "Error: Save slot not found.\n";
        return;
    }

    std::ifstream inFile(saveSlots[slotName]);
    if (inFile.is_open()) {
        json saveData;
        inFile >> saveData;
        inFile.close();

        missionsCompleted = saveData["missionsCompleted"].get<std::vector<int>>();
        puzzlesSolved = saveData["puzzlesSolved"].get<std::vector<int>>();
        locationsVisited = saveData["locationsVisited"].get<std::vector<int>>();
        waypointsActivated = saveData["waypointsActivated"].get<std::vector<int>>();
        inventoryItems = saveData["inventoryItems"].get<std::vector<int>>();
        shopItemsAvailable = saveData["shopItemsAvailable"].get<std::vector<int>>();
        enemiesDefeated = saveData["enemiesDefeated"].get<std::vector<int>>();
        bossesDefeated = saveData["bossesDefeated"].get<std::vector<int>>();

        characterClass = saveData["characterClass"].get<std::string>();
        stats = saveData["stats"].get<std::array<int, 5>>();
        level = saveData["level"].get<int>();
        experience = saveData["experience"].get<int>();
        currentHealth = saveData["currentHealth"].get<int>();
        maxHealth = saveData["maxHealth"].get<int>();

        std::cout << "Game progress loaded from slot: " << slotName << ".\n";
    } else {
        std::cerr << "Error: Unable to load save slot.\n";
    }
}

// Display available save slots
void ProgressManager::displayAvailableSaves() const {
    std::cout << "--- Available Save Slots ---\n";
    for (const auto& slot : saveSlots) {
        std::cout << "Slot: " << slot.first << " (File: " << slot.second << ")\n";
    }
}

// Delete a specific save slot
void ProgressManager::deleteSave(const std::string& slotName) {
    if (saveSlots.find(slotName) != saveSlots.end()) {
        fs::remove(saveSlots[slotName]); // Delete the file
        saveSlots.erase(slotName);       // Remove the slot from the map
        std::cout << "Save slot \"" << slotName << "\" deleted.\n";
    } else {
        std::cerr << "Error: Save slot not found.\n";
    }
}

// Debugging method
void ProgressManager::displayProgressSummary() const {
    std::cout << "--- Progress Summary ---\n";
    std::cout << "Missions Completed: " << std::count(missionsCompleted.begin(), missionsCompleted.end(), 1) << "\n";
    // Add similar lines for other progress categories
}
