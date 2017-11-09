#ifndef ANIMAL
	#define ANIMAL

#include <iostream>
#include <string>
using namespace std;

class Animal
{

	protected:
		string name;
		int age;
		Animal* pere;
		Animal* mere;
	public:
		Animal();
		void display();
		void displayNbAnimaux();
		void input();
		Animal(string hisName, int hisAge, Animal* hisPere, Animal* hisMere);
		virtual void crier()=0;
		static int nbAnimaux;
		~Animal();


};

#endif
