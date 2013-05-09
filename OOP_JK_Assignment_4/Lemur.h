//child of Herbivore
//leaf node

//~Lemur()
//eat(Food* food): bool (only eats fruit)
//Lemur()


#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include "Plant.h"
#include "Fruit.h"
#include "Leaf.h"
#include "Nut.h"
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
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

    
		~Lemur(){}
		 


		bool eat(Food* food)
		{
			
			//Fruit* temp = dynamic_cast<Fruit*>(food);
			Plant *food2 = static_cast<Plant*>(food);
			if (Fruit* temp = dynamic_cast<Fruit*>(food2))
			{
				//PROBLEM, it sees every plant as a fruit in this case. so the temp is always NULL when it encounters a fruit?
				cout << "it's a fruit" << endl;
				return true;
			}
			else
			{
				//cout << "not a fruit" << endl;
				return false;
			}
		
			
		}

		//eat works like this (for lemur)
		//take in Food* object
		//attempt to cast down to a Fruit* object
		//if temp is null, return false.
		//if temp is not null, output "ate fruit" or whatever
		//get the fruit's calories (put a getCalories in Plant or something)
		//add the fruit's calories to this animal's calories with {calories += energy} or something
		//delete the object by using delete *food
		//return true

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

	string& getName(){
		return name;
	};
       
        std::string name;
		bool alive;
        int age, calories, maxcalories;
		double weight;
	

};