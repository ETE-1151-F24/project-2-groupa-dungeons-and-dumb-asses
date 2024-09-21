#include <iostream>
#include <thread> // For sleep_for
#include <chrono> // For timing

void printStrobingText(const std::string& text) {
    const std::string colors[] = {
        "\033[31m", // Red
        "\033[32m", // Green
        "\033[33m", // Yellow
        "\033[34m", // Blue
        "\033[35m", // Magenta
        "\033[36m", // Cyan
        "\033[37m"  // White
    };
    
    const int colorCount = sizeof(colors) / sizeof(colors[0]);
    int currentColor = 0;
    
    while (true) {
        for (size_t i = 0; i < text.length(); ++i) {
            std::cout << "\r"; // Move cursor back to the start of the line

            for (size_t j = 0; j < text.length(); ++j) {
                if (j == i) {
                    // Apply strobing color to current character
                    std::cout << colors[currentColor % colorCount] << text[j];
                } else {
                    std::cout << "\033[0m" << text[j]; // Reset color for other characters
                }
            }

            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay for effect

            ++currentColor;
        }
    }
}

int main() {
    std::string text = "WORDSALAD TOSSER";
    std::cout << "\033[2J\033[H"; // Clear screen
    printStrobingText(text);

    return 0;
}