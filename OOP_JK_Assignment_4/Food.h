//parent of Animal
//parent of Plant

//~Food()
//Food()
#pragma once
#include <string>
#include <list>

class Food
{
public:
	Food(){};
	~Food(){};

	//virtuals of all the functions i'll be overriding in lower classes
	virtual const std::string& getName(){return std::string("none");}; 
	virtual bool eat(Food* food) {return true;};
 	virtual bool hunt() {return true;};
	//PROBLEM, error C2061: syntax error : identifier 'list' 
	virtual void PrintSelf() =0;

	//in order for these abstracts to work, ALL the functions MUST be defined SOMEWHERE in the class heirarchy. any un-used virtuals will cause errors
	//virtual const std::string& getName()=0; 
	//virtual bool eat()=0;
	//virtual bool hunt()=0;
	//virtual void PrintSelf()=0;
	
	
};