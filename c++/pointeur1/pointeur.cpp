#include <iostream>
using namespace std;

int main()
{
	int nb1, nb2;
	cout<<"entrer le premier nombre : ";
	cin>>nb1;
	cout<<"entrer le second nombre : ";
	cin>>nb2;
	int *lePlusGrand, *lePlusPetit;

	if(nb1>nb2)
	{
		lePlusGrand = &nb1;
		lePlusPetit = &nb2;
	}
	else
	{	
		lePlusGrand = &nb2;
		lePlusPetit = &nb1;
	}

	cout<<"le nombre le plus petit est : "<<*lePlusPetit<<endl<<" le plus grand est : "<<*lePlusGrand<<endl;
	cout<<"l'adresse de nb1 est : "<<&nb1<<endl<<" l'adresse de nb2 est : "<<&nb2<<endl;



}
