//Child of Food
//Parent of Carnivore, Herbivore

//~Animal()
//eat(Food*):bool (virtual function, no food type specified, only pointer)
//hunt(list<Food*>&foodList):bool
#pragma once
#include "Food.h"
#include "Animal.h"
#include "Plant.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Animal : public Food
{
public:
	Animal(void) : name(), alive(true), age(0), calories(0), weight(0) { }
        Animal(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    ~Animal(){};

	virtual bool eat(Food* food) {return true;};
	
	virtual bool hunt(list<Food*> &foodlist) {return true;};
	

	void PrintSelf()
	{
		cout << "i am a " << age << " year old, " << weight << " kilogram " << name << " with " << calories << " calories." << endl;
	};



	//const std::string& getName()
    //{
    //            return name;
    //};

protected:	
        std::string name;
		bool alive;
        int age, calories, maxcalories;
		double weight;
};