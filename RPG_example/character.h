#ifndef CHARACTER_H
#define CHARACTER_H

#include <string.h>

using namespace std;

class Character{
    private:
    string name;
    int strength;
    int defense;
    int health;
    int speed;
    
    public:
    Character(string n, int st, int d, int h, int sp);
    
    bool isAlive() const;
    int getSpeed() const;
    int getStrength();
    int takeDamage(int strength);
    
};

#endif