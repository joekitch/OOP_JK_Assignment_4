//Abstract Base Classes / Multiple Inheritance / Run-Time Type Identification (RTTI)
//
//In this assignment, Food class will be need to be designed using an Abstract Base Class, and Animal and Plant classes may be Abstract Base Classes or regular, child-classes of Food.  Food is the top-most base class, and both Animal and Plant inherit from Food.  Each one of these should have all members virtual, and no member variables whatsoever.  The member functions that should be declared are included in the Class Diagram file alongside this assignment in Moodle.  The class diagram does not necessarily look the same as the actual member functions you will need in your classes.  Only the critical ones, such as eat and hunt are listed.  If you need / want to add additional functions, you may do so, but make sure they are created in the appropriate places.  For the inhertiance, it will be up to you to construct the syntax properly.
//
//Eat and Hunt /must/ have the same function signature as the ones listed in the Class Diagram. 
//
//Example: 
//bool Eat (Food *food);
//bool Hunt (list<Food*> &foodList);
//
//Do not add or change these types.  Also, you should call Eat from the Hunt function.
//
//I have included the main.cpp file I showed in class, to give you both an idea of how to iterate through the food list, as well as how to use RTTI.   You must use RTTI to determine whether a Food or Animal Object is of a specified type, i.e. no type fields  should be present /anywhere/ within your classes.  The code will determine whether a Food object is an animal or plant, and what concrete type that they are using RTTI only.
//
//The list<Food*> that you use to store all of the animals and plants should use the push_back method.  When processing the list, it should be read from front to back.  Failure to follow this order will result in deductions. 
//
//Rules for hunting and eating:
//
//Herbivore:
//1) For any herbivore, it begins hunting at the beginning of the list of food for any Food* item that it can eat by calling the eat() function on every Plant object.  In other words, you won't call the eat function if it is not a Plant Object.  However, the eat function will decide if the Plant is edible by the herbivore.  When the herbivore finds an edible Food*, it consumes it, deletes it from the list, and increases it's current energy level by the amount of calories that the food item was worth (which is included in the input file for every Plant).  
//
//Carnivore:
//A carnivore parses the list from the front to the back, just like herbivores, but obviously only attempts to eat Animal objects.  Again, his energy is increased by edible prey (Animal objects) ONLY IF THE PREY WEIGHS LESS THAN THE PREDATOR.  Also, he will not eat himself, and he will not eat animals of his own kind unless his energy level is below 20% and the prey that he finds still weighs less than him.
//
//Omniore:
//He will traverse the food list from front to back, eating any plant, and any animal that weighs less than him (if he eats another animal, all predator/prey rules from the carnivore apply).
//
//IMPORTANT:  
//
//1) All animals will be full the first day.  They will use (maxenergy)/14 per day, so they probably won't start eating for two days.  This is ok.
//2) Animals will traverse the foodlist until they find something to eat. They only eat once per day.
//3) Plants will double in calorie size at the end of each day, assuming they survived.
//
//Please try to keep your code clean and neat with no extra, unnecessary code. Useful code, however, is always permitted.
//
//Please get started on your code beforehand.  The simulation should run for around 35/36 days.
//
//Please be sure to ASK QUESTIONS in Class!!! I cannot guarantee you assistance outside of normal office hours, even through email. I will make every effort to answer your emails, but for most cases, it's best that we sit down and look at your code together. I've extended my normal office hours to Tuesday through Thursday, from 2:25-to 3:50, but I have to leave at 3:50, so please come at the beginning of the office hours.
//
//I will continue to update this assignment as questions arise, so please check back often. 








#pragma once

#include "Food.h"

#include "Animal.h"

#include "Carnivore.h"
#include "Tiger.h"

#include "Herbivore.h"
#include "Lemur.h"
#include "Koala.h"
#include "Squirrel.h"

#include "Plant.h"
#include "Fruit.h"
#include "Leaf.h"
#include "Nut.h"

#include "Omnivore.h"
#include "Raven.h"

#include <iostream>
#include <string>
#include <list>
#include <typeinfo> //for using RTTI functionality
#include <fstream>
using namespace std;


//list<Animal*> Animal_list;  //STL pointer list declared globally instead of locally

//list<Plant*> Plant_list;  //STL pointer list declared globally instead of locally

list<Food*> Food_list;

void readFile();

int main()
{
	//Animal(std::string& animal_name, int animal_age, int animal_calories, double animal_weight)
	//Animal* thing = new Animal (std::string("testAnimal"), 1, 100, 100); //NEED to have the type animal* instead of animal for some reason?
	//Plant* plant_thing = new Plant(std::string("testPlant"), 10);
	//Fruit* fruit_thing = new Fruit(std::string("testFruit"), 23);
	//Nut* Nut_thing = new Nut(std::string("testNut"), 27);
	//Leaf* Leaf_thing = new Leaf(std::string("testLeaf"), 29);
	//Herbivore* Herbivore_thing = new Herbivore (std::string("testHerbivore"), 1, 100, 100);
	//Carnivore* Carnivore_thing = new Carnivore (std::string("testCarnivore"), 1, 100, 100);
	//Omnivore* Omnivore_thing = new Omnivore (std::string("testOmnivore"), 1, 100, 100);
	//Raven* Raven_thing = new Raven(std::string("testRaven"), 1, 100, 100);
	//Squirrel* Squirrel_thing = new Squirrel(std::string("testSquirrel"), 1, 100, 100);

	//Carnivore* Carnivore_thing = new Carnivore();
	//Herbivore* Herbivore_thing = new Herbivore();
	//Omnivore* Omnivore_thing = new Omnivore();



	//thing->PrintSelf(); //use -> when dealing with pointers

	//plant_thing->PrintSelf(); //WORKS

	//plant_thing->grow();

	//plant_thing->PrintSelf(); //after growing once, the caloric value doubles

	//fruit_thing->PrintSelf(); //WORKS

	//fruit_thing->grow();

	//fruit_thing->PrintSelf(); //after growing once, the caloric value doubles

	//Carnivore_thing->eat(Herbivore_thing);

	//Raven_thing->PrintSelf();
	//PROBLEM, getting an "ambiguous access of "printself"" error. whenever i try to define PrintSelf() in Raven, it says "variable age undeclared, variable weight undeclared..." like they're not inheriting correctly?[SOLVED; by having a PrintSelf() in Raven, and within that, just calling Animal::PrintSelf(). it overloads the Animal version (which is not virtual) with the current stuff

	//Squirrel_thing->PrintSelf();
    
	//cout << "Herbivore thing is of the type " << typeid(Herbivore_thing).name() << endl;

	//if ( typeid(Herbivore_thing) == typeid(Carnivore_thing) ) //use typeid() == typeid() for comparisons between types
	//{ cout << "Herbivore thing and carnivore thing are the same type!" << endl;}
	//else{
	//	cout << "Herbivore thing and carnivore thing ARE NOT THE SAME TYPE" << endl;}

	//if (dynamic_cast<Herbivore*>(Herbivore_thing))
	//{ cout << "dynamic casting says that Herbivore_thing is an herbivore* type" << endl;}
	//else {cout << "dynamic casting failed..." << endl;}
	//what about comparing an examined type to the type you want? (you have a something, and you need to know if it's an herbivore or not)

	
	//problem here, trying to use food->getName() but it's looking in food for the getname function, when it should be in Herbivore of Animal [SOLVED, by making a virtual getName() in Food.h, and letting Animal.h fully define it, so it trickles down to all Animal's descendents.]

	
	
	readFile();

	list<Food*>::iterator it = Food_list.begin();

	(*it)->PrintSelf();
	

	cout << "iterator thing is of the type " << typeid(**it).name() << endl;
	//PROBLEM, it's only reading the type as a Food* type, not an herbivore! [SOLVED, use two stars instead of one]
	//NEW PROBLEM, it's not reading the parent class, just the immediate class type (like Lemur), and i can't do reliable string.find() on it either!
	//[SOLVED, use dynamic casting down (go from Food* to Herbivore*, if the tmp returns null it's false). see example below main]


	(*it)->eat(*it);
	
	//PROBLEM, keeps saying eat does not take one arugments [SOLVED, had to put (Food* food) in all the virtual function definitions through food to herbivore/carnivore to omnivore]
	//technically Food* food need only be in the food class' definition

	(*it)->hunt(Food_list);
	//PROBLEM, error C2061: syntax error : identifier 'list' (see Food.h)
	//error C2660: 'Food::hunt' : function does not take 1 arguments

	//if i take the virtual hunt() out of Food it says hunt() is not a member of Food






	//these return true no matter what
	//if (dynamic_cast<Herbivore*>(*it)); 
	//cout << "detected an herbivore" << endl; 

	//if (dynamic_cast<Carnivore*>(*it));
	//cout << "detected a carnivore" << endl; 
	



	

	//enable RTTI[x]
	//set up global lists (always use push_back when adding to list)[x]
	//give the plant class an extra variable (energy value) which is passed by the file reader, this determines how much energy they give to animals which eat them.[x]
	//set up the plant class with a virtual grow() function which doubles the current calorie value. have runSimulation() call this on all plants in the plant list after the death list has run. make sure it compiles[X]
	//set up the carnivore and herbivore classes with constructors that pass to animal (and instantiate some to make sure they work)[x]
	//set up omnivore class with constructors that pass to herbivore and carnivore, which pass to animal (and instantiate some examples to make sure they work)[X]
	//verify the readFile function can properly take in all the input and repeat it[x]

	//make getters and setters for all variables in the Animal class. the functions should all trickle down to the descendents Omnivore should call the animal versions of the getters and setters
	//need to pass the global plant and animal list to the animal 
	//set up the virtual Hunt (list<Food*> &foodList) in carnivore and herbivore function and make sure it compiles HUNT MODIFIES THE CALORIES OF THE ANIMAL
	//set up the global lists, and passing them to the hunt() function, doesn't need to do anything yet
	//set up the virtual Eat (Food *food) functions in carnivore and herbivore, check compile
	//set up hunt to use RTTI to examine the types of anything it's looking at when iterating, dont use type fields
	//call eat() from the hunt() function, passing a sample (one or two) plant objects into a list, sending the list to hunt
	//hunt only calls eat() on things of the right kind. Carnivores only eat() things that are Animal type and weigh less than them, and are not tigers (unless energy is below 20% then tigers are fair game). Omnivores eat either plants or animals, but only when they weigh less.
	//eat takes the iterator being examined by hunt and checks it against the "eatable items", then eats it (deletes the object) when it findd something suitable. MAIN MUST ERASE THE ITERATOR WHEN IT DOES THIS (look for hunt to return a true, which requires eat to return a true, and then delete the iterator then.
	
	//next make eat and hunt for carnivores, which traverse the passed animal list same way as the herbivore hunt uses the plant list, and can eat any herbivore in that list (use names? or class types?)

	//next make the omnivore eat and hunt, which goes through both the animal and plant list (plant list first), calling eat once on the first thing it finds (except tigers)

	//make a day() pasage function which is called from runSimulation() main after they're done eating, which reduces calories by (maxenergy)/14

	//make the lists like in the below example (plants are straight up foodlist items, where animals are passed in as Animal* types)


	

};



void readFile() //function to read in file
{
	
	ifstream FileIn;
	FileIn.open("assignment_4_input.txt"); // located in C:\Users\joseph\Documents\Visual Studio 2010\Projects\OOP_JK_Assignment1\OOP_JK_Assignment1
	if (FileIn.is_open()) 
		
			{
				while (!FileIn.eof( )) 
					{
						
					string Animal_type = "Animal";
					string Plant_type = "Plant";
					string FileIn_type = "none";
             		string FileIn_name = "none";            //define variables to be found in the text file
					int FileIn_age = 0, FileIn_calories = 0;
					double FileIn_weight = 0;

					//some loop to read in lines of text and store them as variables to be passed
					FileIn >> FileIn_type; //read in all variables per line, terminates at end of line, and is whitespace delimited

					//input samples
					//Animal        27       3    3000    Lemur    Herbivore
					//Plant   Fruits        65
					//Animal        33       5    5000    Raven     Omnivore
					//Animal        29     535  535000    Tiger    Carnivore
					//type, age, weight, calories, name, classification
					//ignoring the classification input, since RTTI will handle that jazz

						if (FileIn_type == Animal_type)
						{
							FileIn >> FileIn_age >> FileIn_weight  >> FileIn_calories  >> FileIn_name;
						    
							
							if (FileIn_name == "Lemur")
							{ 
								
								Food_list.push_back(new Lemur(FileIn_name, FileIn_age, FileIn_calories, FileIn_weight)); //instantiate new Animal object using input data
							} 
							else if (FileIn_name == "Koala")
							{ 
								
								Food_list.push_back(new Koala(FileIn_name, FileIn_age, FileIn_calories, FileIn_weight));
							}
							else if (FileIn_name == "Squirrel")
							{ 
								
								Food_list.push_back(new Squirrel(FileIn_name, FileIn_age, FileIn_calories, FileIn_weight));
							}
							else if (FileIn_name == "Tiger")
							{ 
								
								Food_list.push_back(new Tiger(FileIn_name, FileIn_age, FileIn_calories, FileIn_weight));
							}
							else if (FileIn_name == "Raven")
							{ 
								
								Food_list.push_back(new Raven(FileIn_name, FileIn_age, FileIn_calories, FileIn_weight));\
								//PROBLEM, getting error C2594: 'argument' : ambiguous conversions from 'Raven *' to 'Food *' [SOLVED, needed to make all constructors adhere to the leaf nodes instead of inheriting from Animal, and give carnivore/herbivore/omnivore blank constructors]

							}
						}
						else if (FileIn_type == Plant_type)
						{
							
							FileIn >> FileIn_name >> FileIn_calories;
							Food_list.push_back(new Plant (FileIn_name, FileIn_calories) );
						}


						//this is a nice error check, but for some reason it registers all animals as invalid on the first pass, then gets it fine the second pass?
						//else 
						//{
						//	cout << "invalid entry" << endl;
							
						//}

			   

					}
			}
			else cout << "failed to open file" << endl; //if is_open fails, or it cannot locate the file
		FileIn.close(); //no need for this anymore

		//animals and plants print their variables
		//DECIDED TO FORGO THIS FOR PROJECT 4, IT TAKES FOREVER TO PRINT OUT
		//for(list<Food*>::iterator it = Food_list.begin(); it != Food_list.end(); it++) 
		//{ //iterate through Animal_list vector of pointers 
		//	(*it)->PrintSelf(); //for each object, call PrintSelf() from Animal object
		//}
		cout << "list read and stored successfully" << endl;


} //end of readFile()



//SAMPLE MAIN FOR HOW TO ITERATE THROUGH LISTS
//int main (void)
//{
//	// Global list of Animal's and Plants
//	list <Food *> foodList;
//	
//	// The code below should be replaced with your existing code for
//	// reading in the input file, creating the objects and running
//	// the simulation.  
//	// This code is provided as an example. You will not be using the default constructors.
//	// You will need to modify your file read code to incorporate the new animals.
//	for (int i=0; i < 2; i++) {
//		foodList.push_back(new Fruit());
//		foodList.push_back(new Leaf());
//		foodList.push_back(new Nut());
//		Animal* tmp = new Raven();
//		foodList.push_back(tmp);
//		tmp = new Raven();
//		foodList.push_back(tmp);
//		tmp = new Squirrel();
//		foodList.push_back(tmp);
//		tmp = new Tiger();
//		foodList.push_back(tmp);
//	}
//	
//	// The code below should be replaced with your doSimulation routine.
//	while (foodList.size() > 1)
//	{
//		for (list<Food*>::iterator itr = foodList.begin(); itr != foodList.end(); itr++)
//		{
//			Animal* temp = dynamic_cast<Animal*>(*itr);
//			if (temp) {
//				// We have an animal
//				temp->hunt(foodList);  // If the animal finds something to eat, he'll eat it too.
//									   // i.e. hunt calls the appropriate eat from the concrete class

                //can only cast down. cast down from food* to animal* and see if its harbivore* type, if(cast) or whatever returns NULL its not
// hunt, searches through list for casted plant type. pass to eat, cast further down to what
//Herbivore* temp = dynamic_cast<Food*>(*itr)
// if (temp)
//			}
//		}
//	}
//}