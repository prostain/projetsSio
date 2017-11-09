#include "person.h"
#include <vector>
#include <iostream>
using namespace std; 

vector <Person> vectPerson;
char votreChoix;
void ajoutP();
void afficheP();

int main()
{
	
	bool quit=false;
	do
	{
		cout<<"saisir : 'a' pour afficher, '+' pour ajouter, 'r' pour rechercher et 'q' pour quitter"<<endl;
		cin>>votreChoix;
		switch(votreChoix)
		{
			case 'a':
				cout<<"afficher le tableau : "<<endl;
			break;
			case '+':
				cout<<"ahouter une personne : "<<endl;
			break;
			case 'r':
				cout<<"rechercher une personne : "<<endl;
			break;
			case'q':
				quit=true;
			break;
			default:
				cout<<" Cette lettre n'a aucune correspondance ";
		}
	
	}
	while(!quit);
}
	char votreChoix()
	{
		char choix
		cin>>choix
		return choix;
	}

	void afficheP()
	{
		cout<<"Liste des personnes : "<<endl;
		for( int i=0;i < vectPerson.size();i++)
		{
		 if(vectPerson[i].display() = chaineRecherchee
			return i;	
		}
		return -1;
				
	}


