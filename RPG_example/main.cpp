#include <iostream>
#include "character.h"

using namespace std;

int main(){
    
    // Initialize characters
    Character player("Barbarian", 5, 3, 20, 2);     // Player Character
    Character computer("Dragon", 7, 4, 50, 1);      // Computer Character
    
    
    while(player.isAlive() && computer.isAlive()){
        // Combat
        // Who is faster?
        
        if(player.getSpeed() > computer.getSpeed()){
            // Player attacks first
            computer.takeDamage(player.getStrength());  // health = health - (attacker's str - def);
            if(computer.isAlive())
                break;
            player.takeDamage(computer.getStrength());
        } else {
            // Computer attacks first
            
        }
    }
    
    // Evaluate winner
    
    // Print conclusion
    
    return 0;
}