#include "lion.h"


int tailleCriniere=27;
Lion::Lion(string hisName, int hisAge, Animal* hisPere, Animal* hisMere,int hisCriniere)
:Animal( hisName, hisAge, hisPere, hisMere)
{
tailleCriniere=hisCriniere;
}
void Lion::crier()
{
cout<<"le lion rugi  "<<endl;
}


void Lion::display()
{
	cout<<"je suis un lion"<<endl;
	Animal::display();
	cout<<"la taille de ma crinière est de "<<tailleCriniere<<"cm"<<endl;
}
