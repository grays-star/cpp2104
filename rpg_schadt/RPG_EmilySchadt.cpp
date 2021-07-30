//Emily Schadt ECGR 2104
#include <iostream>
#include <string>


using namespace std;

//create character class
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
    void win();
    void attacks();
    int getHealth() const;
    
};

//define functions 
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
    cout << name << " has " << health << " remaining health!" <<endl;
    return health;
}
void Character::attacks(){
    cout << name << " attacks!" << endl;
}

void Character::win(){
    cout << name << " has won the battle!" << endl;
}

int Character::getHealth() const{
    return health;
}


int main(){
    
    //variables to hold user input
    int choice = 0;
    string run;
    string key;
     
    //declare player and computer characters with preset stats
    Character player("Knight", 4, 1, 45, 6);
    Character computer("Troll", 7, 3, 30, 3);
    
    int playstrength = 4;
    int compstrength = 7;
    
    //welcome message
    cout << "Welcome to the Spooky Dungeon RPG!" << endl;
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
        Character player1("Barbarian", 7, 2, 35, 2);
        playstrength = 7;
        player = player1;
    }
    else if (choice == 2){
        Character player2("Knight", 4, 1, 45, 6);
        playstrength = 4;
        player = player2;
    }
   else if (choice == 3){
        Character player3("Rogue", 5, 0, 40, 8);
        playstrength = 5;
        player = player3;
    }
   else if (choice == 4){
       Character player4("Mage", 6, 3, 30, 4);
        playstrength = 6;
        player = player4;
    } 
    
    cout << "\nNow that you are prepared to battle, choose your most worthy enemy: "<< endl;
    cout <<"1. Dragon \n2. 100 Rats \n3. Troll \n4. Giant Cube of Slime"<< endl;
    
    cout << "\nEnter 1-4: " << endl;
    
    cin >> choice;    
    
    //assign correct stat array to chosen enemy
    if (choice == 1){
         Character computer1("Dragon", 6, 1, 45, 5);
         compstrength = 5;
         computer = computer1;
    }
    else if (choice == 2){
        Character computer2("100 Rats", 5, 0, 40, 7);
        compstrength = 5;
        computer = computer2;
    }
   else if (choice == 3){
         Character computer3("Troll", 7, 3, 30, 3);
         compstrength = 6;
         computer = computer3;
    }
    else if (choice == 4){
         Character computer4("Giant Cube of Slime", 5, 2, 35, 1);
         compstrength = 7;
         computer = computer4;
    }
    
    cout << "\nA bold choice! Good luck on your journey!" << endl;
    
    //while loop to hold combat
    while(player.isAlive() && computer.isAlive()){
    
        //determine which player goes first based on speed
        if(player.getSpeed() > computer.getSpeed()){
            // Player attacks first
            cout << "\033[1;36m";   //change output color
            cout << "Hit any key to attack!" << endl;
            cin >> key;
            player.attacks();
            computer.takeDamage(playstrength);  
            //if the computer dies the loop breaks
            if(computer.isAlive() == false){
                break;
            }
            cout << "\033[1;33m";   //change output color
            computer.attacks();
            player.takeDamage(compstrength);  
            //if the player dies the loop breaks
            if(player.isAlive() == false){
                break;
            }
        } 
        else {
            // Computer attacks first
            cout << "\033[1;33m";
            computer.attacks();
            player.takeDamage(compstrength);  
            if(player.isAlive() == false){
                break;
            }
            cout << "\033[1;36m";
            cout << "Hit any key to attack!" << endl;
            cin >> key;
            player.attacks();
            computer.takeDamage(playstrength);  // health = health - (attacker's str - def);
            if(computer.isAlive() == false){
                break;
            }
        }
        //if the player's health is too low, offer an option to run away
        if(player.getHealth() < 6){
            cout << "\033[1;36m";
            cout << "You may not win this one, brave warrior..."<< endl;
            cout << "Should you choose to, you may run away and never return." << endl;
            cout << "Type 'run' to run away, type 'stay' to continue battling." << endl;
            cin >> run;
            if (run == "run"){
                break;
            }
            else{
                cout << "An honorable choice, but perhaps not a wise one." << endl;
            }
            
        }
    }
    cout << "\033[1;31m";
    if(run == "run"){
        cout << "You narrowly escaped. You kept your life, but not your honor." << endl;
    }
    else if(player.isAlive() == true){
        player.win();
    }
    else{
        computer.win();
    }
   
    
    return 0;
}
    
    