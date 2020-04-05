#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "Pile.h"
#include "File.h"

using namespace std;

int main(int argc, char** argv) {

	/****************************** La partie des listes ******************************/

	cout<<endl<<"------------- Exemple sur les fonction des listes chaines : -------------"<<endl<<endl;
	list* l = CreerList();
	AfficheList(l);
	cout<<endl;
	inserQueue(l,19);
	AfficheList(l);
	inserTete(l,17);
	AfficheList(l);
	inserMaillonList(l,20,1);		inserMaillonList(l,55,2);		inserMaillonList(l,66,3);		inserMaillonList(l,33,4);
	inserMaillonList(l,77,5);    // insertion des �lements
	AfficheList(l);
	cout<<endl;
	cout<<"la longeur de la list est : "<<LongList(l)<<" elements."<<endl<<endl;
	cout<<"la position de 33 est :  "<<rangElement(l,33)<<endl;
	cout<<"la position de 77 est :  "<<rangElement(l,77)<<endl;

	/****************************** La partie des files ******************************/

	cout<<endl<<"----------------- Exemple sur les fonction des files : -----------------"<<endl<<endl;
	File *f = CreerFile();
	AfficheFile(f);
	cout<<endl;
	Emfiler(f,18);		Emfiler(f,11);		Emfiler(f,33);		Emfiler(f,77);		Emfiler(f,88); // insertion des �lements

	AfficheFile(f);		cout<<endl;

	cout<<"En defile l'element "<<Tete(f)<<" de la file :"<<endl<<endl;		Defiler(f);

	AfficheFile(f);		cout<<endl;

	cout<<"En emfile l'element 15 dans la file :"<<endl<<endl;	 Emfiler(f,15);

	AfficheFile(f);		cout<<endl;

	cout<<"la longeur de la file est : "<<longFile(f)<<" elements"<<endl;

	/****************************** La partie des piles ******************************/

	cout<<endl<<"------------------ Exemple sur les fonction des piles : ------------------"<<endl<<endl;
	pile *p = CreerPile();
	AffichePile(p);
	cout<<endl;
	Empiler(p,11);		Empiler(p,22);		Empiler(p,33);		Empiler(p,44);		Empiler(p,55);  // insertion des �lements

	AffichePile(p);		cout<<endl;

	cout<<"En depile l'element "<<Sommet(p)<<" de la pile :"<<endl<<endl;		Depiler(p);

	AffichePile(p);		cout<<endl;

	cout<<"En empile l'element 99 dans la pile :"<<endl<<endl;	 Empiler(p,99);

	AffichePile(p);		cout<<endl;

	cout<<"La hauteur de la pile est : "<<hautPile(p)<<" elements"<<endl<<endl;

	cout<<"En depile l'element "<<Sommet(p)<<" de la pile :"<<endl<<endl;		Depiler(p);

	AffichePile(p);		cout<<endl;
  system(“pause”);





	return 0;
}
