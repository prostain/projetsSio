#include "animal.h"


int Animal::nbAnimaux=0;

Animal::Animal(string hisName, int hisAge, Animal* hisPere, Animal* hisMere)
{
	name=hisName;
	age=hisAge;
	pere=hisPere;
	mere=hisMere;
	
	nbAnimaux++;
	Animal::display();
}

void Animal::display()
{
	cout<< "Name : " << name<< endl;
	cout<< "age : " << age<<endl; 
	cout<<"père : "<<pere<<endl;
	cout<<"mère : "<<mere<<endl;
	displayNbAnimaux();


}
void Animal::displayNbAnimaux()
{
	cout<<"Le nombre d'animeaux : "<<nbAnimaux<<endl;
}

Animal::~Animal()
{
	nbAnimaux--;
}
