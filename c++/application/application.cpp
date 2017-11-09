#include "application.h"

Application::Application()
{
	running=false;
}


void Application::afficheMenu()
{
	cout<<endl <<endl <<"saisir 'a' pour afficher, '+' pour ajouter, 'r' pour rechercher et 'q' pour quitter"<<endl;
}

char Application::votreChoix()
{
	char leChoix;
	cin>>leChoix;

	return leChoix;
	cin.ignore(1);
}

void Application::realiseActionCorrespondantAuChoix(char leChoix)
{
	string recherche;
	switch(leChoix)
	{
	
		case 'a':
			cout<<endl<<"afficher le tableau : "<<endl;
			afficherP();
		break;
		case '+':
			cout<<endl<<"ajouter une personne : "<<endl;
			ajouterP();
		break;
		case 'r':
			cout<<endl<<"rechercher une personne : "<<endl<<endl;
			cin>>recherche;
			rechercherPerson(recherche).display();
		break;
		case'q':
			arret();
		break;
		default:
			cout<<" Cette lettre n'a aucune correspondance "<<endl <<endl;
		}

}

void Application::ajouterP()
{
	Person newPerson;
	cin.ignore();
	newPerson.input();
	vectPerson.push_back(newPerson);

}

void Application::afficherP()
{
	int nbPerson=vectPerson.size();
	cout<<"Liste des personnes : "<<endl;
		for( int nuPerson=0;nuPerson < nbPerson;nuPerson++)
		{
		 vectPerson[nuPerson].display();
	}
	cin.ignore();

}


Person Application::rechercherPerson(string chaineRecherchee)
{
	int nbPerson=vectPerson.size();
	for( int nuPerson=0;nuPerson < nbPerson;nuPerson++)
		{
		if(vectPerson[nuPerson].getFirstName() == chaineRecherchee)
			return vectPerson[nuPerson];	
		}
}

void Application::run()
{
	running=true;

	do
	{
		afficheMenu();
		realiseActionCorrespondantAuChoix(votreChoix());
	}while(running);

}

void Application::arret()
{
	running=false;
}
