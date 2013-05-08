//child of Herbivore
//leaf node

//~Lemur()
//eat(Food* food): bool (only eats fruit)
//Lemur()


#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include <iostream>
#include <string>
using namespace std;

class Lemur : public Herbivore
{
	public:
		//Lemur(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Herbivore (animal_name, animal_age, animal_calories, animal_weight) {}

		//~Lemur(){};


	
		//eat(), only eats fruit
		Lemur(void) : name(), alive(true), age(0), calories(0), weight(0) {}
        Lemur(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    
		~Lemur(){};
		bool eat(Food* food) 
		{
			if ( typeid(*food).name() )
				cout << "food passed successfully, its a " << typeid(*food).name() << endl; //need the * in front of food otherwise it things it's a class Food* type
			return true;
		};
	   bool hunt(list<Food*> &foodlist) 
		{
			cout << "successfully got the food list" << endl;
			return true;
		};
	
	void PrintSelf()
	{
		cout << "i am a " << age << " year old, " << weight << " kilogram " << name << " with " << calories << " calories." << endl;
	};

        protected:	
        std::string name;
		bool alive;
        int age, calories, maxcalories;
		double weight;
	

};