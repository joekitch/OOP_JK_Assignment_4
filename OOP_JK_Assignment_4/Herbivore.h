//Child of Animal
//Parent of Lemur, Koala, Squirrel, Omnivore

//~Herbivore()
//hunt(list<Food*&foodList):bool (only eats plant types)
#pragma once
#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;

class Herbivore : public virtual Animal
	{
	public:
		//Herbivore(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		  // Animal (animal_name, animal_age, animal_calories, animal_weight) {} //constructor pased to base class
		Herbivore() {};
		~Herbivore(){};
		virtual bool eat(Food* food) {return true;};
	
	virtual bool hunt(list<Food*> &foodlist) {return true;};

	//void PrintSelf()
	//{
	//	cout << "i am a " << age << " year old, " << weight << " kilogram " << name << " with " << calories << " calories." << endl;
	//};

	//const std::string& getName()
    //{
    //            return name;
    //};
	//virtual bool hunt(list<Food*>&foodList) { return true; };  //pass a plant list to this. child classes check if it's a certain type that they can eat 
		 
};


		
        