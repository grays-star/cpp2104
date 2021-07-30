
#include <iostream>
#include <string>

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
    int getStrength()  ;
    int takeDamage(int strength) ;
    void win();
    
};


Character::Character(string n, int st, int d, int h, int sp){
        name = n;
        strength = st;
        defense = d;
        health = h;
        speed = sp;
}

bool Character::isAlive() const {
    return health > 0;
}

int Character::getSpeed() const {
    return speed;
}

int Character::getStrength()  {
    return strength;
}

int Character::takeDamage(int strength) {
    health = health - (strength - defense);
    cout << name << " has " << health <<endl;
    return health;
}

void Character::win(){
    cout << name << " has won the battle!" << endl;
}

int main(){
    
    string nameholder;
    int choice = 0; 
    string job; 
    Character player;
    Character computer;
    
    int playstrength = 0;
    int compstrength = 0;
    
    // Initialize characters
    cout << "Welcome to the Dangerous Dungeon RPG!" << endl;
    cout << "Please enter your name: " << endl;
    cin >> nameholder; 
    
    cout << "Choose your class: "  << endl;
    cout << "1. Barbarian: "  << endl;
    cout << "\tThis class has the highest strength stat, but the lowest speed stat.\n\n";
    
    cout << "2. Knight: "  << endl;
    cout << "\tThis class has the highest health stat, but the lowest strength stat.\n\n";
    
    cout << "3. Rogue: " << endl;
    cout << "\tThis class has the highest speed stat, but the lowest defense stat.\n\n";
    
    cout << "4. Mage: "  << endl;
    cout << "\tThis class has the highest defense stat, but the lowest health stat.\n\n";  
    
    cout << "Enter 1-4: " << endl;
    
    cin >> choice; 
    
    //assign the correct stat array to the player's chosen class
    if (choice == 1){
        Character player(nameholder, 7, 2, 35, 2);
        job = "barbarian";
        playstrength = 7;
    }
    if (choice == 2){
        Character player(nameholder, 4, 1, 45, 6);
        job = "knight";
        playstrength = 4;
    }
    if (choice == 3){
        Character player(nameholder, 5, 0, 40, 8);
        job = "rogue";
        playstrength = 5;
    }
    if (choice == 4){
       Character player(nameholder, 6, 3, 30, 4);
        job = "mage";
        playstrength = 6;
    }    
    
    choice = 0;
   
    cout << "\nWelcome " << nameholder << ", bravest " << job << " in the land!" << endl;
    
    cout << "\nNow that you are prepared to battle, choose your most worthy enemy: "<< endl;
    cout <<"1. Dragon \n2. 100 Rats \n3. Troll \n4. Giant Cube of Slime"<< endl;
    
    cout << "\nEnter 1-4: " << endl;
    
    cin >> choice;    
    
    if (choice == 1){
         Character computer("Dragon", 6, 1, 45, 5);
         compstrength = 5;
    }
    if (choice == 2){
        Character computer("100 Rats", 5, 0, 40, 7);
        compstrength = 5;
    }
    if (choice == 3){
         Character computer("Troll", 7, 3, 30, 3);
         compstrength = 6;
    }
    if (choice == 1){
         Character computer("Giant Cube of Slime", 5, 2, 35, 1);
         compstrength = 7;
    }
    
    cout << "\nA bold choice! Good luck on your journey!" << endl;
    
    
    
    
    while(player.isAlive() && computer.isAlive()){
        // Combat
        // Who is faster?
        
        if(player.getSpeed() > computer.getSpeed()){
            // Player attacks first
            cout << nameholder << " attacks!\n";
            computer.takeDamage(playstrength);  // health = health - (attacker's str - def);
            if(computer.isAlive() == false){
                break;
            }
            
        } 
        else {
            // Computer attacks first
            cout << "The enemy attacks!\n";
            player.takeDamage(compstrength);  // health = health - (attacker's str - def);
            if(player.isAlive() == false){
                break;
            }
        }
    }
    
    if(player.isAlive() == true){
        player.win();
    }
    else{
        computer.win();
    }
    // Evaluate winner
    
    // Print conclusion
    
    return 0;
}