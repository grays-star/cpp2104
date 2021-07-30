//Emily Schadt ECGR 2104
#include <iostream>
#include <string>
#include <vector>
#include "food.h"

/*
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
*/
int main(){
    
    int selection;
    double total_calories;
    double total_fat;
    double total_sugar;
    double total_protein;
    int total_sodium;
    int i;
    string nameToSet;
    double fatToSet;
    double sugarToSet;
    double proteinToSet;
    int sodiumToSet;
    
    Food cheerio("Cheerios", 140, 2.5, 2, 5, 190);
    Food bacon("Bacon", 343, 11, 0, 3, 137);
    Food turkey_sub("Turkey Sub", 399, 3.1, 0, 31.2, 1217);
    Food PBJ("Peanut Butter and Jelly Sandwich", 327.4, 14.2, 12.1, 10.3, 390);
    Food steak("Steak", 679, 48, 0, 62, 146);
    Food spaghetti("Spaghetti", 221, 1.3, 0.8, 8, 1);
    Food chips("Chips", 152, 10, 0.1, 2, 2);
    Food celery("Celery", 6, 0, 1, 0, 32);
    Food salad("Salad", 20, 0.2, 1.8, 1.2, 31);
    Food cheese("Cheese", 113, 9, 0.1, 7, 174);

    Food total("all", 0, 0, 0, 0, 0);
    
    vector<Food> vec;
    vec.push_back(cheerio);
    vec.push_back(bacon);
    vec.push_back(turkey_sub);
    vec.push_back(PBJ);
    vec.push_back(steak);
    vec.push_back(spaghetti);
    vec.push_back(chips);
    vec.push_back(celery);
    vec.push_back(salad);
    vec.push_back(cheese);
    
   
    do{
        cout << "\nWhat have you eaten today?" << endl;
        
        
        for (i = 0; i < vec.size(); i++){
            cout << i + 1<< ". " << vec.at(i).getName() << endl;
        }
        
        cout << (i + 1) << ". Enter a new selection" << endl;
        cout << (i + 2) << ". End Selection for the Day" << endl;
                
        
        cin >> selection; 
        
        if(selection == 1){
            
            
            total_calories+= cheerio.getCalories();
            total_fat+= cheerio.getFat();
            total_sugar+= cheerio.getSugar();
            total_protein+= cheerio.getProtein();
            total_sodium+= cheerio.getSodium();
        }
        if(selection == 2){
            
            total_calories+= bacon.getCalories();
            total_fat+= bacon.getFat();
            total_sugar+= bacon.getSugar();
            total_protein+= bacon.getProtein();
            total_sodium+= bacon.getSodium();

        }
        if(selection == 3){
           
            total_calories+= turkey_sub.getCalories();
            total_fat+= turkey_sub.getFat();
            total_sugar+= turkey_sub.getSugar();
            total_protein+= turkey_sub.getProtein();
            total_sodium+= turkey_sub.getSodium();

        }
        if(selection == 4){
           
            total_calories+= PBJ.getCalories();
            total_fat+= PBJ.getFat();
            total_sugar+= PBJ.getSugar();
            total_protein+= PBJ.getProtein();
            total_sodium+= PBJ.getSodium();
        }
        if(selection == 5){
            
            total_calories+= steak.getCalories();
            total_fat+= steak.getFat();
            total_sugar+= steak.getSugar();
            total_protein+= steak.getProtein();
            total_sodium+= steak.getSodium();
        }
        if(selection == 6){
            
            total_calories+= spaghetti.getCalories();
            total_fat+= spaghetti.getFat();
            total_sugar+= spaghetti.getSugar();
            total_protein+= spaghetti.getProtein();
            total_sodium+= spaghetti.getSodium();
        }
        if(selection == 7){
           
            total_calories+= chips.getCalories();
            total_fat+= chips.getFat();
            total_sugar+= chips.getSugar();
            total_protein+= chips.getProtein();
            total_sodium+= chips.getSodium();
        }
        if(selection == 8){
            
            total_calories+= celery.getCalories();
            total_fat+= celery.getFat();
            total_sugar+= celery.getSugar();
            total_protein+= celery.getProtein();
            total_sodium+= celery.getSodium();
        }
        if(selection == 9){
            
            total_calories+= salad.getCalories();
            total_fat+= salad.getFat();
            total_sugar+= salad.getSugar();
            total_protein+= salad.getProtein();
            total_sodium+= salad.getSodium();
        }
        if(selection == 10){
            
            total_calories+= cheese.getCalories();
            total_fat+= cheese.getFat();
            total_sugar+= cheese.getSugar();
            total_protein+= cheese.getProtein();
            total_sodium+= cheese.getSodium();
        }
        
        if(selection == (i + 1)){
            Food newfood("void", 0, 0, 0, 0, 0);
            cout << "\nEnter the name of the new selection: " << endl;
            cin >> nameToSet;
            newfood.setName(nameToSet);
            cout << "\nEnter the fat content in grams: " << endl;
            cin >> fatToSet;
            newfood.setFat(fatToSet);
            cout << "\nEnter the sugar content in grams: " << endl;
            cin >> sugarToSet;
            newfood.setSugar(sugarToSet);
            cout << "\nEnter the protein content in grams: " << endl; 
            cin >> proteinToSet;
            newfood.setProtein(proteinToSet);
            cout << "\nEnter the sodium content in milligrams: " << endl;
            cin >> sodiumToSet;
            newfood.setSodium(sodiumToSet);
            vec.push_back(newfood);
            total_calories+= newfood.getCalories();
            total_fat+= newfood.getFat();
            total_sugar+= newfood.getSugar();
            total_protein+= newfood.getProtein();
            total_sodium+= newfood.getSodium();
        }
        if((selection > 10)&&(selection < i + 1)){
            
            total_calories+= vec.at(selection - 1).getCalories();
            total_fat+= vec.at(selection - 1).getFat();
            total_sugar+= vec.at(selection- 1).getSugar();
            total_protein+= vec.at(selection - 1).getProtein();
            total_sodium+= vec.at(selection - 1).getSodium();
        }
        

        
        
    }while (selection != (i + 2));
    
    if (total_calories > 2000){
        cout << "Today you exceeded the recommended daily ammount of calories." << endl;
        
    }
    if(total_fat > 70){
        cout << "Today you exceeded the recommended daily grams of fat." << endl;
    }
    if(total_sugar > 30){
        cout << "Today you exceeded the recommended daily grams of sugar." << endl;
    }
    if(total_protein > 50){
        cout << "Today you exceeded the recommended daily grams of protein." << endl;
    }
    if(total_sodium > 2300){
        cout << "Today you exceeded the recommended daily milligrams of sodium." << endl;
    }
    return 0;
}
