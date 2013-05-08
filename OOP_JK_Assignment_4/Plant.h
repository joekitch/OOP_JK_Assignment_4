//Child of Food
//parent of Leaf, Nut, Fruit

//~Plant()
//Plant()

#pragma once
#include "Food.h"
#include <iostream>
#include <string>
using namespace std;

class Plant : public Food
	{
	public:
		Plant (void) : name(), energy(0) {}
		Plant (std::string& plant_name, int energy_value) :
		name(plant_name), energy(energy_value) {} //constructor

		virtual ~Plant(void){ } //destructor

		std::string name;  //variables for the class
		int energy;
		//I am a 10 year old, 25.5 kilogram Animal with 1000 calories. // sample output
		virtual void PrintSelf() //easy way to print out the class' contents externally
		{ 
			cout << "this is some " << name << " with a caloric value of " << energy << endl;
			
		};


		virtual void grow()
		{
			energy*=2;
		}

		virtual int& getEnergy()
		{
			return energy;
		}

		virtual std::string& getName()
		{
			return name;
		}


		
	};
