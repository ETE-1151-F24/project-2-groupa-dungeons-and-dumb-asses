// GameHeaderEli.h
#ifndef GAMEHEADERELI_H
#define GAMEHEADERELI_H

//+++++++++++++++++++++++++++ any INCLUDES needed for the file ---------------
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <ctime>

//-------------------------DECLARE GLOBAL VARIABLES----------
enum StatisticType { Strength, Dexterity, Intelligence, Wisdom, Constitution, StatCount };
enum ItemType { WEAPON, MAGICAL, CLOTHING };
enum CharacterType { CHOSEN_ONE, NPC, ENEMY };
enum CombatType { MELEE, RANGED };

//------------------------------------------ Class Declaration for Game Items ------------------------------------------
class Item {
public:
    // Attributes
    std::string name;
    std::string description;
    std::string ability;
    ItemType classification;
    CombatType combatType;
    int statModifier[StatCount];
    int minDamage = 0;
    int maxDamage = 0;
    int rangeModifier = 0;
    int sneakPenalty = 0;
    int magPowModifier = 0;
    std::string restriction;
    bool isPlaceholder; // New attribute to determine if the item is a placeholder

    // Default constructor
    Item();

    // Parameterized constructor
    Item(std::string itemName, std::string itemDescription, ItemType itemClassification,
         CombatType itemCombatType, std::array<int, StatCount> modifier, std::string itemAbility,
         int minDmg = 0, int maxDmg = 0, int rangeMod = 0, int sneakPen = 0, int magPowMod = 0, std::string itemRestriction = "");

    // Function to mark an item as a placeholder
    void markAsPlaceholder();

    // Function to calculate damage based on combat type
    int calculateDamage(int distance);

private:
    // Helper functions to calculate damage
    int calculateRangedDamage(int distance, int maxRange, int minDamage, int maxDamage);
    int calculateMeleeDamage();
};

//-----------------------------------------Declaring Class for character development----------------------------------------------------
class Player {
public:
    std::string name;
    std::string characterClass;
    int level;
    int experience;
    std::array<int, StatCount> stats;
    std::vector<std::string> abilitiesMenu;
    std::vector<Item> equippedItems;
    std::vector<Item> inventory;

    Player(std::string playerName, std::string charClass, int startLevel = 1);

    // Stat methods
    void rollStats();
    void finalizeStats();
    void showStats() const;
    void showEquippedItems() const;

    // Methods for equipment management
    bool isEquipped(const Item& item) const;
    void equipItem(Item& item);
    void unequipItem(Item& item);
    bool hasEquippedWeapon() const;

private:
    int roll(int minValue, int maxValue);
};

//-------------------------DECLARE FUNCTION PROTOTYPES----------
void initializeGameItems(std::vector<Item>& gameItems);
void printStrobingText(const std::string& text, int duration);
bool confirmClassChoice();
bool equipItem(Player& player, int itemIndex);
bool unequipItem(Player& player, int itemIndex);
void displayClasses(Player& player);
std::string getPlayerName();
void runGameLoop(Player& player);
void displayItemDetails(const Item& item);

#endif // GAMEHEADERELI_H
