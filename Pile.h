/**************************************************************************************************************************/
/****************************************** CREATED BY : ******************************************************************/
/**************************************************************************************************************************/
/*********************************** - OUFRAD Mohamed                 *****************************************************/
/*********************************** - FERGOUCH Younes                *****************************************************/
/*********************************** - RAMI mohamed                   *****************************************************/
/*********************************** - AIT OUAKRIM Abdessamad         *****************************************************/
/*********************************** - ESSADIK Lahcen                 *****************************************************/
/**************************************************************************************************************************/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/**********************************Les Structure des Pile **************************************************/

struct MaillonPile{
	int e;
	struct MaillonPile *psuivant;
};
typedef struct MaillonPile MaillonPile;

struct pile{
    MaillonPile *psommet; 	
};
typedef struct pile pile;

/*************************************Les fonction des Pile *************************************************/

pile* CreerPile(){
	pile* p=new pile;
	p->psommet=NULL;
	return p;
 }
 
bool pileVide (pile* p){
	return(p->psommet == NULL);
}

int Sommet(pile* p){
	if(!pileVide(p)) return p->psommet->e;
}
 
MaillonPile *CreerMaillonPile(int valeur){
	MaillonPile *pm=new MaillonPile;
	if(pm != NULL)
	{
		pm->e=valeur;
		pm->psuivant=NULL;
	}
	return pm;
 }

int hautPile(pile* p){
	MaillonPile *m = p->psommet;
	int h=1;
	if(pileVide(p))	
	return 0;
    while(m->psuivant != NULL)
    {
		m=m->psuivant;
		h++;
    }
	return h;
}
 
bool Empiler(pile *p,int valeur){
	MaillonPile *pm = CreerMaillonPile(valeur);
	
	if(pm == NULL)  return false;
    
	pm->psuivant=p->psommet;	
	p->psommet=pm;
	return true;
}
 
int Depiler(pile *p){
	MaillonPile *m;
	int v;
	if(!pileVide(p))
	{
		v=p->psommet->e;
		m=p->psommet;
		p->psommet=m->psuivant;
		free(m);
	}
	return v;
}
 
void AffichePile(pile *p){
	MaillonPile *m;
	if(pileVide(p)){
	cout<<"\t|    | : La pile est vide !!"<<endl;
	cout<<"\t*----*"<<endl;}
	else{
	m = p->psommet;
    while(m->psuivant != NULL)
	{
		cout<<"\t| "<<m->e<<" |"<<endl;
		cout<<"\t|----|"<<endl;
		m = m->psuivant;
	}
	cout<<"\t| "<<m->e<<" |"<<endl;
	cout<<"\t*----*"<<endl;	
	} 
}
 

