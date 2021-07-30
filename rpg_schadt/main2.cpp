#include <iostream>
#include <string>
#include <vector> 

using namespace std;


    class Character{
    private:
        string name;
        int strength;
        int defense;
        int health;
        int speed;
    public:
    vector <Character> characterInfo;
    Character(string n);
    
    bool isAlive() const;
    int getSpeed() const;
    int getStrength();
    int takeDamage(int strength);
    
};
Character::Character(string n){
    name = n;
}

Character::characterInfo(){
    strength = characterInfo.at(0);
    defense = characterInfo.at(1);
    health = characterInfo.at(2);
    speed = characterInfo.at(3);
    
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

void Character::win(){
    cout << name << " has won the battle!" << endl;
}

int main(){
    int choice = 0; 
    string job; 
   
    cout << "Welcome to the Dangerous Dungeon RPG!" << endl;
   
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
    
    if (choice == 1){
        characterInfo player( 7, 2, 35, 2);
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