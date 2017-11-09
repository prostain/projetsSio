#include "person.h"


Person::Person()
{
	firstName="duppond";
	age=53;
	lastName="patrick";
}
Person::Person(string hisName,string hisSurname, int hisAge)
{
	firstName=hisName;
	age=hisAge;
	lastName=hisSurname;
}
string Person::getFirstName()
{
	return firstName;
}
void Person::setFirstName( string theFirstName)
{
	firstName= theFirstName;
}

string Person::getLastName()
{
	return lastName;
}
void Person::setLastName( string theLastName)
{
	lastName= theLastName;
}

int Person::getAge()
{
	return age;
}
void Person::setAge( int theAge)
{
	age= theAge;
}

void Person::display()
{
	cout<< "firstName : " << firstName<< endl;
	cout<< "lastName : " << lastName<< endl;
	cout<< "age : " << age<< endl <<endl;  
}
void Person::input()
{
	cout<< "firstName : ";
	getline(cin,firstName);
	cout<< "lastName : ";
	getline(cin,lastName);
	cout<< "age : " <<endl;
	cin>>age;

}

