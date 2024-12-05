//ProgressHandling.h
#ifndef PROGRESSHANDLING_H
#define PROGRESSHANDLING_H

#include <vector>
#include <string>
#include <map>
#include <nlohmann/json.hpp> // JSON library for save/load functionality

using json = nlohmann::json;

class ProgressManager {
public:
    // Progress tracking
    std::vector<int> missionsCompleted;
    std::vector<int> puzzlesSolved;
    std::vector<int> locationsVisited;
    std::vector<int> waypointsActivated;
    std::vector<int> inventoryItems;
    std::vector<int> shopItemsAvailable;
    std::vector<int> enemiesDefeated;
    std::vector<int> bossesDefeated;

    // Character details
    std::string characterClass;
    std::array<int, 5> stats;
    int level;
    int experience;
    int currentHealth;
    int maxHealth;

    // Save slots
    std::map<std::string, std::string> saveSlots; // Map of slot names to file paths

    // Constructor
    ProgressManager(size_t missionCount, size_t puzzleCount, size_t locationCount,
                    size_t waypointCount, size_t inventorySize, size_t shopItemCount,
                    size_t enemyTypeCount, size_t bossCount);

    // Save and load progress
    void saveProgress(const std::string& slotName);     // Save to a specific slot
    void loadProgress(const std::string& slotName);     // Load from a specific slot
    void displayAvailableSaves() const;                // Display all available save slots
    void deleteSave(const std::string& slotName);      // Delete a specific save slot

    // Debugging
    void displayProgressSummary() const;
};

#endif // PROGRESSHANDLING_H
