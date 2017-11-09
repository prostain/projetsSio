#ifndef LION
	#define LION

#include "animal.h"

class Lion : public Animal
{
	protected:
		int tailleCriniere;
				
	public:
		Lion(string hisName, int hisAge, Animal* hisPere, Animal* hisMere,int hisCriniere);
		void display();
		void cri();


};
#endif
