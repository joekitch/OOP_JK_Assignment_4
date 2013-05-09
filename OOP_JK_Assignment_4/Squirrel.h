//child of Herbivore
//leaf node

//~Squirrel()
//eat(Food* food): bool (only eats nuts)
//Squirrel()


#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Squirrel : public Herbivore
{
	public:
		//Squirrel(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Herbivore (animal_name, animal_age, animal_calories, animal_weight) {}

		//~Squirrel(){};

		//eat() only eats nuts

		Squirrel(void) : name(), alive(true), age(0), calories(0), weight(0) {}
        Squirrel(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    
		~Squirrel(){}


		  
		bool eat(Food* food)
		{
			cout << "squirrel.h eat() called" << endl;
			return true;
		}

		/*
		static bool eat(Food* food)
		{
			string Fruits = "Fruits";
			if (food.getName() == Fruits)
			{
				cout << "Animal: " << name << " ate a Plant of type: " << (food)->getName() << ". " << .size() << " Plants remain." << endl;
				calories += food.energy;
				delete food
				return true;
			}
			else 
				return false;
		}
		*/
	
	void PrintSelf()
	{
		cout << "i am a " << age << " year old, " << weight << " kilogram " << name << " with " << calories << " calories." << endl;
	};

        
        std::string name;
		bool alive;
        int age, calories, maxcalories;
		double weight;
	


	

};