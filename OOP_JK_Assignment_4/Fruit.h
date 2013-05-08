//child of Plant (leaf node)

//~Fruit()
//Fruit()


#pragma once
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class Fruit : public Plant {
	public:
		Fruit (std::string& plant_name, int energy_value):
		  Plant (plant_name, energy_value){} //constructor pased to base class

		~Fruit(){ } //destructor

		//inherits basically everything from the Plant base class, makes leae nodes in the class tree easy to write and access


		
	};

