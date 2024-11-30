cmake_minimum_required(VERSION 3.14)
project(DungeonsAndDumbAsses)

# Enable testing
enable_testing()

# Add Google Test
add_subdirectory(googletest)

# Define the source files of your project
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/PROJECT_1/Character_develop_functs.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/Game_functions_eli.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/Health_management.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/Leveling.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/GameHeaderEli.h
    ${CMAKE_SOURCE_DIR}/PROJECT_1/Game_inventory_functions.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/gameItems.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/GameMainStuff.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/item_constructors_dmg_shifts.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/MapFunctions.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/SpellHandling.cpp
)

# Add your main project
add_executable(main_project ${SOURCE_FILES})

# Add the test executable
add_executable(run_tests ${CMAKE_SOURCE_DIR}/PROJECT_1/tests/test_file.cpp)

# Link Google Test libraries
target_link_libraries(run_tests gtest gtest_main)