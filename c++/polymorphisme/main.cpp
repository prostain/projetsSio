#include "kangourou.h"
#include "lion.h"
#include <vector>
int main()
{
	//Animal bambli("bambi",0,NULL,NULL);
	vector <Animal*> vectMesAnimaux;
	vectMesAnimaux.push_back(new Kangourou("pumba",0,NULL,NULL));
	vectMesAnimaux.push_back(new Kangourou("tot",0,NULL,NULL));
	vectMesAnimaux.push_back(new Lion("mouphaça",0,NULL,NULL,20));

	
	unsigned int nbAnimaux=Animal::nbAnimaux;

	for (unsigned int noAnim=0; noAnim<nbAnimaux;noAnim++)
	{
		vectMesAnimaux[noAnim]->display();
		vectMesAnimaux[noAnim]->crier();


	}


}
