//child of Plant (leaf node)

//~Nut()
//Nut()

#pragma once
#include <iostream>
#include <string>
#include "Plant.h"
using namespace std;

class Nut : public Plant {
	public:
		Nut (std::string& plant_name, int energy_value):
		  Plant (plant_name, energy_value){} //constructor pased to base class

		~Nut(){ } //destructor

		//inherits basically everything from the Plant base class, makes leae nodes in the class tree easy to write and access


		
	};