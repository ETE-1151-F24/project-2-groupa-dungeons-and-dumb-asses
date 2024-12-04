#include <gtest/gtest.h>
#include "src/GameHeaderEli.h"  // Include the header file for your Player and Item definitions
#include "src/Game_inventory_functions.cpp"  // Include the source file (for the implementation)
#include "nlohmann/json.hpp"

// Mock data for tests
Player createMockPlayer() {
    Player player("Mock Player", "warrior", 1);  // Use parameterized constructor

    // Create mock items
    Item sword("Sword", "A sharp blade.", WEAPON, MELEE,
               std::array<int, StatCount>{5, 0, 0, 0, 0}, 
               "Increases strength", 5, 10);
    Item shield("Shield", "A sturdy shield.", CLOTHING, MELEE, 
                std::array<int, StatCount>{0, 0, 0, 0, 3}, 
                "Increases constitution", 0, 0);
    
    // Add items to inventory
    player.inventory.push_back(sword);
    player.inventory.push_back(shield);

    return player;
}

// Test for displayInventory
TEST(GameInventoryFunctionsTest, DisplayInventory) {
    Player player = createMockPlayer();
    
    testing::internal::CaptureStdout();  // Capture output to test it
    displayInventory(player);  // Call the function
    std::string output = testing::internal::GetCapturedStdout();  // Get captured output

    EXPECT_NE(output.find("--- Your Inventory ---"), std::string::npos);
    EXPECT_NE(output.find("Sword"), std::string::npos);
    EXPECT_NE(output.find("Shield"), std::string::npos);
}

// Test for displayItemDetails
TEST(GameInventoryFunctionsTest, DisplayItemDetails) {
    Item item("Sword", "A sharp blade.", WEAPON, MELEE,
              std::array<int, StatCount>{5, 0, 0, 0, 0}, 
              "Increases strength", 5, 10);

    testing::internal::CaptureStdout();  // Capture output
    displayItemDetails(item);  // Call the function
    std::string output = testing::internal::GetCapturedStdout();  // Get captured output

    EXPECT_NE(output.find("Item: Sword"), std::string::npos);
    EXPECT_NE(output.find("Flavor Description: A sharp blade."), std::string::npos);
    EXPECT_NE(output.find("Ability: Increases strength."), std::string::npos);
    EXPECT_NE(output.find("Damage Range: 5 - 10"), std::string::npos);
}

// Test for isEquipped
TEST(GameInventoryFunctionsTest, IsEquipped) {
    Player player = createMockPlayer();
    const Item& sword = player.inventory[0];

    player.equipItem(&player.inventory[0]);  // Equip the sword
    EXPECT_TRUE(player.isEquipped(sword));  // Sword should be equipped

    player.unequipItem(&player.inventory[0]);  // Unequip the sword
    EXPECT_FALSE(player.isEquipped(sword));  // Sword should not be equipped
}

// Test for equipItem
TEST(GameInventoryFunctionsTest, EquipItem) {
    Player player = createMockPlayer();
    Item& sword = player.inventory[0];

    EXPECT_FALSE(player.isEquipped(sword));  // Sword initially unequipped
    player.equipItem(&sword);  // Equip the sword
    EXPECT_TRUE(player.isEquipped(sword));  // Sword should be equipped
}

// Test for unequipItem
TEST(GameInventoryFunctionsTest, UnequipItem) {
    Player player = createMockPlayer();
    Item& sword = player.inventory[0];

    player.equipItem(&sword);  // Equip the sword
    EXPECT_TRUE(player.isEquipped(sword));  // Sword should be equipped

    player.unequipItem(&sword);  // Unequip the sword
    EXPECT_FALSE(player.isEquipped(sword));  // Sword should not be equipped
}

// Test for checkForWeapon
TEST(GameInventoryFunctionsTest, CheckForWeapon) {
    Player player = createMockPlayer();
    
    testing::internal::CaptureStdout();  // Capture output
    checkForWeapon(player);  // Call the function
    std::string output = testing::internal::GetCapturedStdout();  // Get captured output

    EXPECT_NE(output.find("Warning: You are without a weapon."), std::string::npos);

    player.equipItem(&player.inventory[0]);  // Equip the sword
    testing::internal::CaptureStdout();  // Capture output again
    checkForWeapon(player);  // Call the function
    output = testing::internal::GetCapturedStdout();  // Get captured output

    EXPECT_EQ(output.find("Warning: You are without a weapon."), std::string::npos);
}
