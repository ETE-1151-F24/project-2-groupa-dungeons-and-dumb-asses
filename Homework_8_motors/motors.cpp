/*Hope you enjoy this one I put a lot of thought Into it.

See attached file. main-2.cppDownload main-2.cpp

In the attached code you will find a class called MotorStatus. 
You may only modify the turnOff function and main function. 
You may add new functions to the code if you so desire as long as it increase complexity and does not make the end game easier.  
The goal of this HW is to understand how bitwiseOperators work and to find bugs in code.

How the code should work. 
OH NO.... your motors are overheating but you are not sure which one!!! 
Hurry turn off a motor!!!! OH NO another motor is now overheating 

The turnOff function should turn off the guessed motor (if it is over heating) 
and return true if the correct motor/s are turned off. (not working)
If the motor is not overheating it leave it in is original state on/off, respectively.(not working)
If the user guesses wrong the overheating motor will get so hot another motor will overheat. (working - 
updateOverheating())
)
 

Currently the function turnOff is not correctly turning off the motors that the user is telling it to turn off.

Debug the code and fix turnOff to correctly shut down the correct motors according to the user input. 

 

sample output

Motor State (ON/OFF): 11111010 
Overheating Motors: 00101000 
Turn Count: 1 

Motor State (ON/OFF): 11111010 
Overheating Motors: 10101000 
Turn Count: 2*/


#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>
class MotorStatus {
private:
uint8_t motorState;                                                     // Each bit represents the status of a motor (on/off)
uint8_t overheatingMotors;                                              // Motors that are overheating
int turnCount;
// Function to randomly initialize motors (on/off) and overheat one motor
void initialize() {
    srand(time(0)); 
    motorState = rand() % 256;                                              // Randomly turn motors on/off
    updateOverheating();                                                    // Randomly overheat one motor
    turnCount = 0;
    displayStatus();
}
// Incrementally overheat motors with each turn, ensuring the motor is ON and not already overheating
void updateOverheating() {
    int newMotor;
    do {
        newMotor = rand() % 8;                                                  // Randomly select a motor
    } while (((1 << newMotor) & motorState) == 0 ||                             // Ensure the motor is ON
        ((1 << newMotor) & overheatingMotors) != 0);                            // Ensure the motor is not already overheating
        overheatingMotors |= (1 << newMotor);                                   // Set the selected motor to overheat
        turnCount++;
}
void displayStatus() {
    std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) <<
    std::endl;
    std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << std::endl;
    std::cout << "Turn Count: " << turnCount << std::endl;
}
public:
MotorStatus() {
initialize();
}
                                                                    // Simulate a guess attempt
bool turnOff(uint8_t guess) {
                                                                    // turn off the motors that are associated with the guess
    motorState ^= (overheatingMotors & guess);
    if (guess == motorState) {/*code to turn of correct motor*/
    }
                                                                    // Motors not overheating and were turned off are restored to ON
    updateOverheating();                                                // Each incorect guess makes another motor overheat
    displayStatus();
    return false;
}
                        // Display current motor status (for debugging purposes)
};
int main() {
    MotorStatus motorStatus;
    uint8_t guess = 0b00000001; // Start with all motors off
//----------------------- Loop until all motors are turned off
    while (!motorStatus.turnOff(guess)) {
// The student can use bitwise AND/OR/XOR here to adjust the guess based on the feedback
}
}