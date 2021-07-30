#include "card.h"

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

Action Card::getAction() const{
    return action;
}

void Card::setAction(Action a){
    action = a;
}

Changes Card::getChanges() const{
    return changes;
}

void Card::setChanges(Changes ch){
    changes = ch;
}
NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

actionCard::actionCard(Color c, Action a){
    setColor(c);
    setAction(a);
}

changingCard::changingCard(Changes ch, Color c){
    setChanges(ch);
    setColor(c);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1:
            switch(action){
            case DRAW2:
                return "|   DRAW 2  |";
                break;
            case REVERSE:
                return "|  REVERSE  |";
                break;
            case SKIP:
                return "|    SKIP   |";
                break;
            default:
                return "|           |";
                break;
            }
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: 
            switch(changes){
            case WILD:
                return "|    WILD   |";
                break;
            case DRAW4:
                return "|   DRAW 4  |";
                break;
            default:
                return "|           |";
                break;
            }
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}

bool actionCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || action == discard->getAction()){
        return true;
    } else {
        return false;
    }
}

bool changingCard::play(Card* discard, GameState &gameState) {
        return true;
    //always true because they can be played on top of any card
}