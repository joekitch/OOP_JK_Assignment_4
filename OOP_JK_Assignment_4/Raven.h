//child of Omnivore (leaf node)

//~Raven()
//eat(Food*, food): bool
//Raven()


#pragma once
#include "Animal.h"
#include "Omnivore.h"
#include <iostream>
#include <string>
using namespace std;

class Raven : public Omnivore
{
	public:
		//using Animal::Animal;
		//Raven(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Omnivore (animal_name, animal_age, animal_calories, animal_weight) {}

		//~Raven(){};
		


		//eat() looks through both animal and plant lists, eats any plant, and any animal smaller than itself (including ravens!)

		Raven(void) : name(), alive(true), age(0), calories(0), weight(0) {}
        Raven(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    
		~Raven(){};
		bool eat(Food* food) 
		{
			if ( typeid(*food).name() )
				cout << "food passed successfully, its a " << typeid(*food).name() << endl; //need the * in front of food otherwise it things it's a class Food* type
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