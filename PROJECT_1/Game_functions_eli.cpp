//Game_functions_eli.cpp

//----------------------------------------------FUNCTION FOR STROBING TITLE-------------------------------------
    // ---------------------ANSI COLOR CODES-------------------------
    // Array of ANSI escape codes representing gold color and bold effect.
    const std::string goldColor = "\033[38;5;220m";  // Custom gold color
    const std::string resetColor = "\033[0m";        // Reset to default
    const std::string boldEffect = "\033[1m";        // Bold text effect

    // ---------------------TIME START POINT-------------------------
    auto startTime = std::chrono::steady_clock::now();  // Mark current time

    // -------------------LOOP FOR STROBING EFFECT-------------------
    while (true) {
        // Calculate elapsed time
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

        if (elapsedTime >= duration) {  // Break the loop when duration ends
            break;
        }

        // ------------------STROBING CHARACTERS----------------------
        for (size_t i = 0; i < text.length(); ++i) {
            std::cout << "\r";  // Move cursor to the start of the line

            // Print each letter with alternate gold and default color strobing
            for (size_t j = 0; j < text.length(); ++j) {
                if (j % 2 == i % 2) {
                    std::cout << goldColor << boldEffect << text[j];  // Gold and bold effect
                } else {
                    std::cout << resetColor << boldEffect << text[j];  // Reset color with bold
                }
            }

            std::cout.flush();  // Flush output buffer to display text immediately
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Delay for visible strobing effect
        }
    }

    // ---------------------RESET COLOR AT END-----------------------
    std::cout << resetColor << "\n";  // Reset terminal color and add a newline
}
//_________________________________________________________________________________________________________
Player_class:
