//child of Carnivore and Herbivore
//parent of Raven

//~Omnivore()
//hunt(list<Food*>&foodList):bool

//class X : public A, private B, public C { /* ... */ };


#pragma once
#include "Animal.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;


class Omnivore : public Carnivore, public Herbivore
{
	public:
		//using Animal::Animal;
		//Omnivore(string& animal_name, int animal_age, int animal_calories, double animal_weight) : Herbivore (animal_name, animal_age, animal_calories, animal_weight), Carnivore (animal_name, animal_age, animal_calories, animal_weight) {}

//PROBLEM, how to pass a constructor to multiple parent classes? [SOLVED; use Omnivore(int arguments) : Herbivore(arguments), Omnivore(Arguments) {} ]

		Omnivore() : Herbivore(), Carnivore(){}
		virtual ~Omnivore(){}
		virtual bool eat(Food* food) {return true;};
	
	virtual bool hunt(list<Food*> &foodlist) {return true;};
    void PrintSelf()
	{
		Animal::PrintSelf();
	};
	//problem, usage of PrintSelf() in Raven or Omnivore ambiguous? [SOLVED; need to use the PrintSelf() of an upper function, in this case Animal]


	//override hunt for omnivore entirely to avoid ambiguity
	//dont call carnivore's or herbivore's hunt or eat

		  

};

