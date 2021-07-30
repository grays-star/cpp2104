#include <iostream>
#include <string>
#include <vector>
#include "food.h"

using namespace std;
Food::Food(string n, double cal, double ft, double sgr, double prtn, int sdm){
        name = n;
        calories = cal;
        fat = ft;
        sugar = sgr;
        protein = prtn; 
        sodium = sdm;

}

string Food::getName() const {
    return name;
}

double Food::getCalories() const {
    return calories;
}

double Food::getFat() const {
    return fat;
}

double Food::getSugar() const {
    return sugar;
}

double Food::getProtein() const {
    return protein;
}

int Food::getSodium() const {
    return sodium;
}

void Food::setName(string nameToSet){
    name = nameToSet;
}

void Food::setFat(double fatToSet){
    fat = fatToSet;
}
void Food::setSugar(double sugarToSet){
    sugar = sugarToSet;
}
void Food::setProtein(double proteinToSet){
    protein = proteinToSet;
}
void Food::setSodium(int sodiumToSet){
    sodium = sodiumToSet;
}