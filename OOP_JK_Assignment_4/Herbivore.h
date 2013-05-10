//Child of Animal
//Parent of Lemur, Koala, Squirrel, Omnivore

//~Herbivore()
//hunt(list<Food*&foodList):bool (only eats plant types)
#pragma once
#include "Animal.h"
//#include "Lemur.h"
#include "Plant.h"
#include "Fruit.h"
#include "Leaf.h"
#include "Nut.h"
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
using namespace std;

class Herbivore : public virtual Animal
	{
	public:
		//Herbivore(string& animal_name, int animal_age, int animal_calories, double animal_weight) : 
		  // Animal (animal_name, animal_age, animal_calories, animal_weight) {} //constructor pased to base class
		Herbivore() {}
		virtual ~Herbivore(){}
		virtual bool eat(Food* food) {cout << "herbivore.h eat() called" << endl; return true;};
	    //virtual bool eat(Food* food) = 0;


		
	    bool hunt(list<Food*> &foodlist) //herbivore version of hunt()
		{
			//cout << "successfully got the food list in hunt(), this is from HERBIVORE.H" << endl;
			int fruitcounter=0;
			int plantcounter=0;
			string name;
			//if (foodlist.size() > 1){
			for (list<Food*>::iterator it = foodlist.begin(); it != foodlist.end(); it++)
			{
				
				//cout << "plant list iterate in herbivore.h" << endl;
                //Plant* temp = dynamic_cast<Plant*>(*it);
                if (Plant* temp = dynamic_cast<Plant*>(*it))
				{
					//cout << "this is a " << cout << typeid(temp).name() << endl;
				    plantcounter++;

					eat(it);

					//if ( eat(*it) )
				    //fruitcounter++;
					//return true;
				}
				
			}
			cout << "there are " << fruitcounter << " fruits and " << plantcounter << " plants in the list." << endl;
			return false;
		};

			


			//Lemur* temp = dynamic_cast<Lemur*>(*it);
			//cout << " from hunt() of herbivore, iterator thing is of the type " << typeid(**it).name() << endl; //WORKS, can get foodlist items

			/*for( list<Food*>::iterator it = foodlist.begin(); it != foodlist.end(); it++ )
			{
				if (foodlist.size() > 1)
				{
					Plant* temp = dynamic_cast<Plant*>(*it);
					if(temp)
					{
					cout << "iterator thing is a Plant " << endl;
					 (*it)->eat(temp); //will either eat the item if it can, or simply fail and go through the next iteration
					}

					else cout << "iterator is not a plant " << endl;
				}
			}
			*/

			//take in foodlist 
			//make foodlist iterator
			//for each foodlist item, cast to Plant*.
			//if temp is null, just let the iterator loop ride to th next one, skip everything below
			//if temp is not null, call eat(*it), this will pass the plant object down to Lemur in the first case
			//DO NOT PASS TEMP to eat(), no need to, and it needs a Food* type anyway
		




			//eat(*it);
			//hunt should examine the food list using an iterator, and using the same dynamic_cast technique as in main, check if anything is a plant
			//if it's a plant, call the iterator herbivore's appropriate eat() function to see if they can eat that specific plant
			//PROBLEM, do i need to dynamic_cast down to lemur, squirrel, or koala? like three else if statements?
			//if i do, it's just three else_if statements within this herbivore hunt() function, in order to figure out what type it is, then call Lemur::eat() or something
			//Lemur::eat();

			//wait, i can't just call the Lemur::eat(*it) from herbivore can i? it doesn't know what a lemur is
			//and even then, which lemur should it be calling it from? the one that called hunt() from main?
			//do i need to pass the temp from main into hunt() for this to work?
			//assignment says "HUNT CALLS THE APPROPRIATE EAT FROM THE CONCRETE CLASS", and a concrete class is any class that inherts from an abstract base function, and overrides it (so anything below animal, basically)
			//however, lemur::eat() does not work, neither does Lemur.eat() or Lemur->eat()
			//also says "lemur, undeclared identifier"

			
		
		
	

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


		
        