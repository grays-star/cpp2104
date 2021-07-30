#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"

using namespace std;

/**
 * Function to clear the terminal by inserting many new line characters.
 */
void clearTerminal();

/**
 * Function to populate the deck with cards.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
void buildDeck(vector<Card*>& deck);

/**
 * Function to shuffle the deck.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
 void shuffleDeck(vector<Card*>&);

/**
 * Function to draw a card from the deck to either the hand or discard pile.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param target A vector representing the structure that the card being drawn 
 * from the deck is being drawn to. This can be either a hand or the discard
 * pile
 */
void drawCards(vector<Card*>& deck, vector<Card*>& target, int);

/**
 * Function to draw 7 cards to each player's hand at the beginning of the game.
 * 
 * @param deck A vector reference of Card pointers representing the deck.
 * @param hands A vector of vector of Card pointers representing each player 
 * and their hands. The indicies of the first vector represents a player, and 
 * the indicies of the vector at that index is each individual card within the
 * player's hand.
 */
void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);

/** 
 * Renders the cards in he hand vector passed.
 * 
 * @param hand A vector containing Card pointers
 */
void renderHand(vector<Card*> hand);

/**
 * Renders the top card of the passed discard vector.
 * 
 * @param hand A vector containing Card pointers
 */
void renderDiscard(vector<Card*>);

/**
 * Passed references to the deck, hand, and discard vectors and a reference to 
 * the game state. This function will resolve the turn for the current player
 * (whose index is stored in the game state). TakeTurn will query the user for
 * input, draw cards if the previous card was a draw 2 card, or skip the current
 * players turn (see numCardsToPlay in GameState).
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param hand A vector reference of Card pointers representing a single player's hand
 * @param discard A vector reference of Card pointers representing the discard pile
 * @param gameState A reference of the game state object
 */
void takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState);

int main(){
    srand(time(0));
    int NUM_PLAYERS;
    
    //lets the user input how many players there will be in the game
    cout << "Enter the number of players: " << endl; 
    cin >> NUM_PLAYERS;
    
    GameState gameState(NUM_PLAYERS);
    
    vector<Card*> deck;
    vector<Card*> discard;
    
    vector<vector<Card*>> hands(NUM_PLAYERS);
    
    buildDeck(deck);
    shuffleDeck(deck);
    populateHands(deck, hands);
    drawCards(deck, discard, 1);
    
    while(hands.size() > 0){
        takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
    }
    
    return 0;
}

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

void buildDeck(vector<Card*> &deck){
    // Create Number and Action Cards
    for(int c = RED; c < NUM_COLORS; c++){
        int n = 0;
        Card* temp = new NumberCard((Color)c, n);
        deck.push_back(temp);
        deck.push_back(temp);
      
        for (int z = 0; z < 2; z++){
            for(int n = 1; n < 10; n++){
                Card* temp = new NumberCard((Color)c, n);
                deck.push_back(temp);
                deck.push_back(temp);
            }
            for(int a = DRAW2; a < NUM_ACTIONS; a++){
                Card* temp = new actionCard((Color)c, (Action)a);
                deck.push_back(temp);
                deck.push_back(temp);
            }
        }
    }
    
    // Create Changing Cards
    for(int ch = WILD; ch < NUM_CHANGES; ch++){
        for(int n = 0; n < 4; n++){
            Card* temp = new changingCard((Changes)ch);
            deck.push_back(temp);
            deck.push_back(temp);
        }
    }    
}

void shuffleDeck(vector<Card*> &deck){
    for(int i = 0; i < 1000; i++){
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        Card* temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}

void drawCards(vector<Card*> &deck, vector<Card*> &target, vector<Card*> discard, int numToDraw){
    for(int i = 0; i < numToDraw; i++){
        if(deck.size() > 0){
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
        } else {
            int n = discard.size();
            //refill the deck with cards from the discard pile, leaving the last one
            cout << "Deck out of cards, replacing deck with discard pile." << endl;
            for(int i=0; i<n-1; i++){
                deck.push_back(discard.back());
                discard.pop_back();
            }
        }
    }
}

void populateHands(vector<Card*> &deck, vector<vector<Card*>> &hands){
    for(int i = 0; i < hands.size(); i++){
        drawCards(deck, hands.at(i), 7);
    }
}

void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
        cout << discard.at(discard.size() - 1)->render(i) << endl;
    }
}

void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState){
    clearTerminal();
    renderDiscard(discard);
    cout << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
    
    
    drawCards(deck, hand, gameState.numCardsToDraw);
    gameState.numCardsToDraw = 0; // reset cards to draw back to 0
    
    renderHand(hand);
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
    //for(int j = 0; j < gameState.numCardsToPlay; j++){
    if(!gameState.skipTurn){
        // Collect user input
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
        }
        cout << i << ": Draw a Card" << endl;
        int input;
        cin >> input;
        
        
        // Evaluate user input
        if(input < i){
            // Play card at index input
            if(hand.at(input)->play(discard.at(discard.size()-1), gameState)){
                //if an action card is played
                int a = getAction(hand.at(input)); 
                if(a == DRAW2){
                    gameState.numCardsToDraw = 2;   //draws 2 and skips turn
                    gameState.skipTurn = TRUE;
                }
                if(a == REVERSE){
                    if(gameState.nextTurn == LEFT){     //reverses player order
                        gameState.nextTurn = RIGHT;
                    }
                    else{
                        gameState.nextTurn = LEFT;
                    }
                }
                if(a == SKIP){
                    gameState.skipTurn = TRUE;  //skips next player
                }
                
                //if a changing card is played
                int ch = getChanges(hand.at(input));
                if(ch == WILD){     //lets the user pick a color
                    cout << "Choose a color: "<< endl;
                    cout << "\t 0: RED" << endl;
                    cout << "\t 1: BLUE" << endl;
                    cout << "\t 3: GREEN" << endl;
                    cout << "\t 4: YELLOW" << endl;
                    
                    int c;
                    cin >> c >> endl;
                    
                   // hand.at(input) = changingCard((Color) c);
                    Card* temp = new changingCard((Color) c);
                    temp = hand.at(input);
                }
                if(ch == DRAW4){    //lets the user pick a color, next player is forced to draw 4 and skip turn
                    cout << "Choose a color: "<< endl;
                    cout << "\t 0: RED" << endl;
                    cout << "\t 1: BLUE" << endl;
                    cout << "\t 3: GREEN" << endl;
                    cout << "\t 4: YELLOW" << endl;
                    
                    int c;
                    cin >> c;
                    
                   // hand.at(input) = changingCard((Color) c);
                    
                    Card* temp = new changingCard(Color c);
                    temp = hand.at(input);
                    
                    gameState.numCardsToDraw = 4;
                    gameState.skipTurn = true;
                    
                }
                
                Card* temp;
                temp = hand.at(input);
                discard.push_back(temp);
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"
                
                
                
            } else {
                cout << "Improper choice" << endl;
                takeTurn(deck, hand, discard, gameState);
                return;
            }
        }else if(input == i){
            drawCards(deck, hand, 1);
        }
    }else{
        gameState.skipTurn = false;
    }
    
    // update variables for next turn
    gameState.nextTurn();
} 