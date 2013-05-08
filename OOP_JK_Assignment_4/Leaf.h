//child of Plant (leaf node)

//~Leaf()
//Leaf()

#pragma once
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class Leaf : public Plant {
	public:
		Leaf (std::string& plant_name, int energy_value):
		  Plant (plant_name, energy_value){} //constructor pased to base class

		~Leaf(){ } //destructor

		//inherits basically everything from the Plant base class, makes leae nodes in the class tree easy to write and access


		
	};