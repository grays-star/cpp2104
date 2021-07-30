#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case TOWN:
            return new Town;
            break;
        case CAVE:
            return new Cave;
            break;
        case CIRCUS:
            return new Circus;
            break;
        case SPIDERS:
            return new Spiders;
            break;
        case STORE:
            return new Store;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}

string Town::getShortDescription(){
    return "town";
}

string Town::getLongDescription(){
    return "You arrive at a town full of strange people.";
}

string Town::visit(Player& p){
    string description = "You look for someone to talk to but everyone avoids you.";
    
    int chance = rand() % 100;
    
    if(chance > 50){
        description = "You found a friendly old woman who gave you a pie.";
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    
    if(chance < 10 && chance > 5){
        description = "You look so run down the local doctor treats you for free.";
        p.setHealth(p.getHealth() + 2);
    }
    
    if(chance < 5){
        description = "You are mistaken for the local scoundrel and attacked by a mob.";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Cave::getShortDescription(){
    return "cave";
}

string Cave::getLongDescription(){
    return "You arrive in a glistening cave full of crystals.";
}

string Cave::visit(Player& p){
    string description = "You find a beautiful crystal pond and drink from it.";
    
    p.setThirst(p.getThirst() + 1);

    return description;
}

string Circus::getShortDescription(){
    return "circus";
}

string Circus::getLongDescription(){
    return "You arrive at a small circus full of menacing clowns.";
}

string Circus::visit(Player& p){
        string description = "The clowns are angry at you for laughing at them and beat you up.";
        p.setHealth(p.getHealth() - 2);

    return description;
}


string Spiders::getShortDescription(){
    return "spider nest";
}

string Spiders::getLongDescription(){
    return "You arrive at a dark nest full of giant fuzzy spiders.";
}

string Spiders::visit(Player& p){
    string description = "The spiders wrap you up tightly in their web. You get a full night's rest.";
    p.setHealth(Player::DEFAULT_HEALTH);
    return description;
}

string Store::getShortDescription(){
    return "grocery store";
}

string Store::getLongDescription(){
    return "You arrive at a small grocery store full of affordable goods.";
}

string Store::visit(Player& p){
    string description = "You buy lots of food and eat until you're full.";
    p.setHunger(Player::DEFAULT_HUNGER);
    return description;
}