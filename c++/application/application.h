#include <iostream>
#include "person.h"
#include <vector>
class Application
{
	private:
		vector <Person> vectPerson;
		char votreChoix();
		void afficheMenu();
		bool running;
		
		void realiseActionCorrespondantAuChoix(char leChoix);
		void afficherResultatRecherche();
		void ajouterP();
		void afficherP();
		Person rechercherPerson(string chaineRecherchee);
	public:
		Application();
		void run();
		void arret();
};
