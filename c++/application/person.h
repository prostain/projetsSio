#include <iostream>
#include <string>
using namespace std;

class Person
{
	private:
		string firstName, lastName;
		int age;
	public:
		Person();
		Person(string hisName,string hisSurname, int hisAge);
		string getFirstName();
		void setFirstName(string theFirstName);

		string getLastName();
		void setLastName(string theLastName);

		int getAge();
		void setAge(int theAge);

		void display();
		void input();
};
