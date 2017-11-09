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
		virtual void crier();

	public:
		Animal();
		void display();
		void displayNbAnimaux();
		void input();
		Animal(string hisName, int hisAge, Animal* hisPere, Animal* hisMere);

		static int nbAnimaux;
		~Animal();


};

#endif
