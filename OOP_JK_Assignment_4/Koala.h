//child of Herbivore
//leaf node

//~Koala()
//eat(Food* food): bool (only eats leaves)
//Koala()


#pragma once
#include "Animal.h"
#include "Herbivore.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Koala : public Herbivore
{
	public:
		//Koala(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Herbivore (animal_name, animal_age, animal_calories, animal_weight) {}

		//~Koala(){};


	 //eat() only eats leaves


		Koala(void) : name(), alive(true), age(0), calories(0), weight(0) {}
        Koala(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		name(animal_name), alive(true), age(animal_age), calories(animal_calories), weight(animal_weight), maxcalories(animal_calories) {}

    
		~Koala(){}
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