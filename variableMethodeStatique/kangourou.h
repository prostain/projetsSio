#ifndef KANGOUROU
	#define KANGOUROU

#include "animal.h"

class Kangourou : public Animal
{
			
	public:
		static int nbKangourou;
		Kangourou(string hisName, int hisAge, Animal* hisPere, Animal* hisMere);
		void display();
		void crier();
		void displayNbKangourou();
		~Kangourou();


};
#endif
