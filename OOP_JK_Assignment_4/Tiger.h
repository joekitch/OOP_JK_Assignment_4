//child of Carnivore (leaf node)

//~Tiger()
//eat(Food* food):bool
//Tiger()

#pragma once
#include "Animal.h"
#include "Carnivore.h"
#include <iostream>
#include <string>
using namespace std;

class Tiger : public Carnivore
{
	public:
//		Tiger(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Carnivore (animal_name, animal_age, animal_calories, animal_weight) {}

		//~Tiger(){};


	
		//eat(), only eats herbivores from the Animal list. Only things of less weight than itself, and not other Tigers (unless it's calories are below 20% of max calories)

		Tiger(void) : name(), alive(true), age(0), calories(0), weight(0) {}
        Tiger(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    
		~Tiger(){};
		bool eat(Food* food) 
		{
			if ( typeid(food).name() )
				cout << "food passed successfully" << endl;
			return true;
		};
	    bool hunt() 
		{
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