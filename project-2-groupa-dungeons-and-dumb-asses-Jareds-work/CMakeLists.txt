cmake_minimum_required(VERSION 3.14)
project(DungeonsAndDumbAsses)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Define the source files of your main project
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/Character_develop_functs.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/Game_functions_eli.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/Health_management.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/Leveling.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/Game_inventory_functions.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/gameItems.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/GameMainStuff.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/item_constructors_dmg_shifts.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/MapFunctions.cpp
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src/SpellHandling.cpp
)

# Add your main project executable
add_executable(main_project ${SOURCE_FILES})

# Add Google Test
add_subdirectory(PROJECT_1/googletest)

# Add include directories for the project and Google Test
include_directories(
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src  # Include project source directory for headers
    ${CMAKE_SOURCE_DIR}/PROJECT_1/googletest/googletest/include  # Include GoogleTest headers
    ${CMAKE_SOURCE_DIR}/PROJECT_1/include
)

# Define test source files
set(TEST_FILES
    ${CMAKE_SOURCE_DIR}/PROJECT_1/tests/Game_inventory_functions_test.cpp
)

# Add the test executable (only once)
add_executable(run_tests ${TEST_FILES})

# Link Google Test libraries to the test executable
target_link_libraries(run_tests PRIVATE gtest gtest_main)

# Add include directories for the test executable
target_include_directories(run_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/PROJECT_1/src  # Include project source directory for headers
    ${CMAKE_SOURCE_DIR}/PROJECT_1/googletest/googletest/include  # Include GoogleTest headers
)

# Add the tests to CTest
add_test(NAME GameInventoryFunctionsTest COMMAND run_tests)
