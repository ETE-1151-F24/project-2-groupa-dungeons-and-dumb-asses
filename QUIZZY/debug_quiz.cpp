// Post a picture of your running the following code in debug mode.

// Identify the issue using debugger:

#include <iostream>

class Character {
    protected:
        int health;
    
    public:
        int getHealth() {return health;}
};

class Wizard : public Character {
    public:
        int health;
        void setHealth(int newHealth) {health = newHealth;}
};

int main() {
    Wizard gandalf;
    gandalf.setHealth(100);
    std::cout << "Wizard's health: " << gandalf.getHealth() << std::endl;

    return 0;
}
