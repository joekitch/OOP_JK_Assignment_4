//Child of Animal
//Parent of Tiger, Omnivore

//~Carnivore()
//hunt(list<Food*&foodList):bool (only eats Herbivore types)

#pragma once
#include "Animal.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Carnivore : public virtual Animal
	{
	public:
		//Carnivore(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		  // Animal (animal_name, animal_age, animal_calories, animal_weight) {} //constructor pased to base class
		Carnivore(){}
		virtual ~Carnivore(){}
		virtual bool eat() {return true;};
	
	virtual bool hunt(list<Food*> &foodlist) {return true;};

    bool eat(Food* food) 
	{ 
//		cout << name << " ate a " << food->getName()  << endl; 
	    return true; 

		//needs to check if the target is an animal, isn't a tiger, and weighs more than its prey
	};

	//void PrintSelf()
	//{
	//	cout << "i am a " << age << " year old, " << weight << " kilogram " << name << " with " << calories << " calories." << endl;
	//};



	//const std::string& getName()  //because there is a virtual getName in Food.h, and it's fully defined in Animal, everything "down the line" will have this generic function
    //{
    //            return name;
    //};
	//virtual bool eat(Food*) { return true; };
	//virtual bool hunt(list<Food*>&foodList) { return true; }; //pass an animal list to this (checks target weight, and type. dont eat tigers unless calories >= 20% maxcalories)
		
};