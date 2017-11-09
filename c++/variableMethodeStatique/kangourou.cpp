#include "kangourou.h"


int Kangourou::nbKangourou=0;

Kangourou::Kangourou(string hisName, int hisAge, Animal* hisPere, Animal* hisMere)
:Animal(hisName, hisAge, hisPere, hisMere)
{
	nbKangourou++;
}
void Kangourou::crier()
{
cout<<"le kangourou siffle "<<endl;
}

void Kangourou::display()
{
	cout<<"je suis un Kangourou"<<endl;
	Animal::display();
}

void Kangourou::displayNbKangourou()
{
	cout<<" le nombre de Kangourou est de "<<nbKangourou<<"Kangouroux"<<endl;
}

Kangourou::~Kangourou()
{
	nbKangourou--;

}


