#ifndef FOOD_H
#define FOOD_H

#include <string.h>

using namespace std;

class Food{
    private:
    string name;
    double calories;
    double fat;
    double sugar;
    double protein;
    int sodium;
    
    public:
    Food(string n, double cal, double ft, double sgr, double prtn, int sdm);
    string getName() const;
    double getCalories() const;
    double getFat() const;
    double getSugar() const;
    double getProtein() const;
    int getSodium() const;
    void setName(string nameToSet);
    void setCal(double calToSet);
    void setFat(double fatToSet);
    void setSugar(double sugarToSet);
    void setProtein(double proteinToSet);
    void setSodium(int sodiumToSet);
    
    
    
};
#endif